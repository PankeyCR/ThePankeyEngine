
#include "ame_Enviroment.hpp"

#ifndef TestRunnerState_hpp
#define TestRunnerState_hpp
#define TestRunnerState_AVAILABLE

#ifndef ame_Enviroment_Defined

#endif

#ifdef ame_Windows

#endif

#ifdef ame_ArduinoIDE
	#include "Arduino.h"
#endif

#include "Note.hpp"
#include "AppState.hpp"
#include "Class.hpp"
#include "TestResult.hpp"
#include "StaticMethodReturnMap.hpp"
#include "System.hpp"

namespace ame{

class TestRunnerState : public AppState{
    public:
		using TestMethod = TestResult (*)();
		
		TestRunnerState(){}
		virtual ~TestRunnerState(){}
		
		virtual cppObjectClass* getClass(){return Class<AppState>::classType;}
		virtual bool instanceof(cppObjectClass* cls){
			return cls == Class<TestRunnerState>::classType || cppObject::instanceof(cls);
		}
		
		virtual void addUnitTest(Note a_note, TestMethod a_method){
			testMap.add(a_note, a_method);
		}
		
		virtual void runTest(){m_running = true;}
		
		virtual void initialize(Application *app){}
		
		virtual void update(float tpc){
			if(!m_running){
				return;
			}
			bool t_res = true;
			for(int x = 0; x < testMap.getPosition(); x++){
				Note f_note = *testMap.getKeyByPosition(x);
				TestResult f_result = testMap.invokeByPosition(x, TestResult());
				if(!f_result.hasError()){
					continue;
				}
				t_res = false;
				System::println(Note("Testing ") + f_note);
				System::println(f_result.getNoteResult());
			}
			if(t_res){
				System::println("Testing has been a complete success");
			}
			m_running = false;
		}
	protected:
		StaticMethodReturnMap<Note,TestResult> testMap;
		bool m_running = false;
};

}

#endif
