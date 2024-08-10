
#ifndef TR_UpdateFunctionMapManager_Testing_hpp
	#define TR_UpdateFunctionMapManager_Testing_hpp
	
	#include "higgs_Enviroment.hpp"
	#include "higgs_Enviroment_config.hpp"

	#include "TestResult.hpp"
	#include "TestRunner.hpp"

	#include "UpdateFunctionMapManager.hpp"

	namespace higgs{

		void UpdateFunctionMapManagerTest(TestResult& a_result, float a_tpc){
			a_result.assertTrue("executing method", true);
		}

		void UpdateFunctionMapManagerTestWithError(TestResult& a_result, float a_tpc){
			a_result.assertTrue("executing method", false);
		}
		
		TestResult TR_UpdateFunctionMapManager_Testing_1(){
			TestResult i_result;

			UpdateFunctionMapManager<Note,TestResult&,float> i_manager;

			i_manager.add("key", UpdateFunctionMapManagerTest);
			i_manager.update(i_result, 0.1f);
			
			return i_result;
		}
		
		TestResult TR_UpdateFunctionMapManager_Testing_2(){
			TestResult i_result;

			UpdateFunctionMapManager<Note,TestResult&,float> i_manager;

			i_manager.add("function", UpdateFunctionMapManagerTest);
			i_manager.add("error_function", UpdateFunctionMapManagerTestWithError);
			i_manager.removeUpdateFunctionMap("error_function");
			i_manager.update(i_result, 0.1f);
			
			return i_result;
		}
		
		TestResult TR_UpdateFunctionMapManager_Testing_3(){
			TestResult i_result;

			UpdateFunctionMapManager<Note,TestResult&,float> i_manager;

			i_manager.add("function", UpdateFunctionMapManagerTest);
			i_manager.add("error_function", UpdateFunctionMapManagerTestWithError);
			i_manager.removeUpdateFunctionMap(1);
			i_manager.update(i_result, 0.1f);
			
			return i_result;
		}
		
		TestResult TR_UpdateFunctionMapManager_Testing_4(){
			TestResult i_result;

			UpdateFunctionMapManager<Note,TestResult&,float> i_manager;

			i_manager.add("function", UpdateFunctionMapManagerTest);
			i_manager.add("error_function", UpdateFunctionMapManagerTestWithError);

			i_manager.removeAllUpdateFunctionMap();

			i_manager.update(i_result, 0.1f);

			i_result.assertEqual("manager shouldnt have any methods", i_manager.getUpdateFunctionMapSize(), 0);
			
			return i_result;
		}
		
		TestResult TR_UpdateFunctionMapManager_Testing_5(){
			TestResult i_result;

			UpdateFunctionMapManager<Note,TestResult&,float> i_manager;

			i_manager.add("function", UpdateFunctionMapManagerTest);
			i_manager.add("error_function", UpdateFunctionMapManagerTestWithError);

			i_manager.removeAll();

			i_manager.update(i_result, 0.1f);

			i_result.assertEqual("manager shouldnt have any methods", i_manager.getUpdateFunctionMapSize(), 0);
			
			return i_result;
		}
		
		TestResult TR_UpdateFunctionMapManager_Testing_6(){
			TestResult i_result;

			UpdateFunctionMapManager<Note,TestResult&,float> i_manager;

			auto lambda = [](TestResult& a_result, float a_tpc){
				a_result.assertTrue("executing method", true);
			};

			i_manager.add("method", lambda);

			i_manager.update(i_result, 0.1f);
			
			return i_result;
		}

		void TR_UpdateFunctionMapManager_Testing(TestRunner& a_test_runner){
			a_test_runner.map.add("UpdateFunctionMapManager add and update", TR_UpdateFunctionMapManager_Testing_1);
			a_test_runner.map.add("UpdateFunctionMapManager removeUpdate by lvalue", TR_UpdateFunctionMapManager_Testing_2);
			a_test_runner.map.add("UpdateFunctionMapManager removeUpdate by index", TR_UpdateFunctionMapManager_Testing_3);
			a_test_runner.map.add("UpdateFunctionMapManager removeAllUpdateFunctionMap", TR_UpdateFunctionMapManager_Testing_4);
			a_test_runner.map.add("UpdateFunctionMapManager removeAll", TR_UpdateFunctionMapManager_Testing_5);
			a_test_runner.map.add("UpdateFunctionMapManager lambda", TR_UpdateFunctionMapManager_Testing_6);
		}		

	}

#endif
