
#ifndef TestRunnerState_hpp
	#define TestRunnerState_hpp

	#include "pankey.hpp"

	#include "PrimitiveRawMap.hpp"
	#include "InvokeRawMap.hpp"

	#include "TestResult.hpp"
	
	#include "Note.hpp"

	namespace pankey{

		class TestRunner{
			public:
				using TestMethod = TestResult (*)();
				PrimitiveRawMap<Note,TestMethod> map;
				
				TestRunner(){}
				virtual ~TestRunner(){}
				
				virtual void runTest(){m_running = true;}

				virtual void omitInfo(bool a_omit){
					m_omit_info = a_omit;
				}
				
				virtual void run(){
					if(!m_running){
						return;
					}
					System::console.println();
					System::console.println("Starting Testing...");
					System::console.println();

					bool t_res = true;
					for(int x = 0; x < map.getPosition(); x++){
						System::recycle();

						long f_ram = getRamSize();
						Note* f_note = map.getKeyByPosition(x);
						TestMethod* f_method = map.getValueByPosition(x);
						TestResult f_result = invoke(f_method);
						
						System::recycle();

						//f_result.assertNoteEqual(401, Note("Memory Leak of: ") + Note(f_ram - getRamSize()), f_ram, getRamSize());

						if(!m_omit_info){
							if(f_result.hasInfo()){
								if(f_note != nullptr){
									System::console.println(Note("Info of : ") + *f_note);
								}else{
									System::console.println("Info of : ");
								}
								System::console.println(f_result.getInfo());
								System::console.println();
							}
						}

						if(!f_result.hasError()){
							continue;
						}
						t_res = false;

						if(f_note != nullptr){
							System::console.println(Note("Testing - ") + *f_note);
						}
						System::console.println(f_result.getNoteResult());
						System::console.println();
					}
					if(t_res){
						System::console.println("Testing has been a complete success");
					}

					System::console.println("Ram Size: ");
					System::console.println(getRamSize());
					System::console.println();
					System::console.println("Ending Testing...");
					m_running = false;
				}

			protected:
				bool m_running = false;
				bool m_omit_info = false;
		};

	}

#endif
