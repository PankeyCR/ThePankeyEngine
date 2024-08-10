
#ifndef TR_GlobalEvents_Testing_hpp
	#define TR_GlobalEvents_Testing_hpp
	
	#include "higgs_Enviroment.hpp"
	#include "higgs_Enviroment_config.hpp"

	#include "TestResult.hpp"
	#include "TestRunner.hpp"

	#include "GlobalEvents.hpp"

	namespace higgs{
	
		void GlobalEventMethod(TestResult& a_result, float a_tpc){
			a_result.assertTrue("executing method", true);
		}
	
		TestResult TR_GlobalEvents_Testing_1(){
			TestResult i_result;

			GlobalEvents<Note,TestResult&,float>::removeAll();

			GlobalEvents<Note,TestResult&,float>::put("assert", GlobalEventMethod);

			GlobalEvents<Note,TestResult&,float>::run("assert", i_result, 15.5f);

			GlobalEvents<Note,TestResult&,float>::removeAll();
			
			return i_result;
		}
	
		static void GlobalEventMethod2(TestResult& a_result, float a_tpc){
			a_result.assertTrue("executing method", false);
			System::console.println("executingsdfasdf");
		}
	
		TestResult TR_GlobalEvents_Testing_2(){
			TestResult i_result;

			GlobalEvents<Note,TestResult&,float>::removeAll();

			GlobalEvents<Note,TestResult&,float>::put("assert", GlobalEventMethod2);

			GlobalEvents<Note,TestResult&,float>::change("assert", GlobalEventMethod);

			GlobalEvents<Note,TestResult&,float>::run("assert", i_result, 15.5f);

			GlobalEvents<Note,TestResult&,float>::removeAll();
			
			return i_result;
		}

		void TR_GlobalEvents_Testing(TestRunner& a_test_runner){
			createEngineManager();

			a_test_runner.map.add("Application Constructor", TR_GlobalEvents_Testing_1);
			a_test_runner.map.add("Application getStateManager", TR_GlobalEvents_Testing_2);
		}

	}

#endif
