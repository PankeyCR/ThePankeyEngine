
#ifndef TestRunnerState_hpp
#define TestRunnerState_hpp
#define TestRunnerState_AVAILABLE

#include "Note.hpp"
#include "Application.hpp"

#ifdef ame_Windows

#endif

#ifdef ame_ArduinoIDE
	#include "Arduino.h"
#endif

#include "Class.hpp"
#include "TestResult.hpp"
#include "PrimitiveMethodReturnMap.hpp"
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
				Note f_note = testMap.getKey(x);
				TestResult f_result = testMap.invokeByPosition(x, TestResult());
				// testMap.invokeByPosition(x, TestResult());
				// TestResult f_result = TestResult();
				if(!f_result.hasError()){
					continue;
				}
				t_res = false;
				System::console.println(Note("Testing ") + f_note);
				System::console.println(f_result.getNoteResult());
			}
			if(t_res){
				System::console.println("Testing has been a complete success");
			}
			m_running = false;
		}
	protected:
		PrimitiveMethodReturnMap<Note,TestResult> testMap;
		bool m_running = false;
};

}

#endif
