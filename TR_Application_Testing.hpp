
#ifndef TR_Application_Testing_hpp
	#define TR_Application_Testing_hpp
	
	#include "higgs_Enviroment.hpp"
	#include "higgs_Enviroment_config.hpp"

	#include "TestResult.hpp"
	#include "TestRunner.hpp"

	#include "Application.hpp"

	namespace higgs{
	
		TestResult TR_Application_Testing_1(){
			TestResult i_result;

			Application i_app;
			
			return i_result;
		}
	
		TestResult TR_Application_Testing_2(){
			TestResult i_result;

			Application i_app;

			LoopManager<Application>& i_manager = i_app.getStateManager();
			
			return i_result;
		}
	
		TestResult TR_Application_Testing_3(){
			TestResult i_result;

			Application i_app;

			AppManager& i_manager = i_app.getStateManager();
			
			return i_result;
		}
	
		TestResult TR_Application_Testing_4(){
			TestResult i_result;

			Application i_app;

			auto& i_manager = i_app.getStateManager();
			
			return i_result;
		}
	
		TestResult TR_Application_Testing_5(){
			TestResult i_result;

			Application i_app;

			AppSettings& i_settings = i_app.getSettings();
			
			return i_result;
		}
	
		TestResult TR_Application_Testing_6(){
			TestResult i_result;

			Application i_app;

			auto& i_settings = i_app.getSettings();
			
			return i_result;
		}
		void TR_Application_Testing(TestRunner& a_test_runner){
			createEngineManager();

			a_test_runner.map.add("Application Constructor", TR_Application_Testing_1);
			a_test_runner.map.add("Application getStateManager", TR_Application_Testing_2);
			a_test_runner.map.add("Application AppManager", TR_Application_Testing_3);
			a_test_runner.map.add("Application auto getStateManager", TR_Application_Testing_4);
			a_test_runner.map.add("Application AppSettings getSettings", TR_Application_Testing_5);
			a_test_runner.map.add("Application auto getSettings", TR_Application_Testing_6);
		}

	}

#endif
