
#ifndef TR_UpdateFunctionListManager_Testing_hpp
	#define TR_UpdateFunctionListManager_Testing_hpp
	
	#include "pankey_Enviroment.hpp"
	#include "pankey_Enviroment_config.hpp"

	#include "TestResult.hpp"
	#include "TestRunner.hpp"

	#include "UpdateFunctionListManager.hpp"

	namespace pankey{

		void UpdateFunctionListManagerTest(TestResult& a_result, float a_tpc){
			a_result.assertTrue("executing method", true);
		}

		void UpdateFunctionListManagerTestWithError(TestResult& a_result, float a_tpc){
			a_result.assertTrue("executing method", false);
		}
		
		TestResult TR_UpdateFunctionListManager_Testing_1(){
			TestResult i_result;

			UpdateFunctionListManager<TestResult&,float> i_manager;

			i_manager.add(UpdateFunctionListManagerTest);
			i_manager.update(i_result, 0.1f);
			
			return i_result;
		}
		
		TestResult TR_UpdateFunctionListManager_Testing_2(){
			TestResult i_result;

			UpdateFunctionListManager<TestResult&,float> i_manager;

			i_manager.add(UpdateFunctionListManagerTest);
			i_manager.add(UpdateFunctionListManagerTestWithError);
			i_manager.removeUpdateFunctionList(UpdateFunctionListManagerTestWithError);
			i_manager.update(i_result, 0.1f);
			
			return i_result;
		}
		
		TestResult TR_UpdateFunctionListManager_Testing_3(){
			TestResult i_result;

			UpdateFunctionListManager<TestResult&,float> i_manager;

			i_manager.add(UpdateFunctionListManagerTest);
			i_manager.add(UpdateFunctionListManagerTestWithError);
			i_manager.removeUpdateFunctionList(1);
			i_manager.update(i_result, 0.1f);
			
			return i_result;
		}
		
		TestResult TR_UpdateFunctionListManager_Testing_4(){
			TestResult i_result;

			UpdateFunctionListManager<TestResult&,float> i_manager;

			i_manager.add(UpdateFunctionListManagerTest);
			i_manager.add(UpdateFunctionListManagerTestWithError);

			i_manager.removeAllUpdateFunctionList();

			i_manager.update(i_result, 0.1f);

			i_result.assertEqual("manager shouldnt have any methods", i_manager.getUpdateFunctionListSize(), 0);
			
			return i_result;
		}
		
		TestResult TR_UpdateFunctionListManager_Testing_5(){
			TestResult i_result;

			UpdateFunctionListManager<TestResult&,float> i_manager;

			i_manager.add(UpdateFunctionListManagerTest);
			i_manager.add(UpdateFunctionListManagerTestWithError);

			i_manager.removeAll();

			i_manager.update(i_result, 0.1f);

			i_result.assertEqual("manager shouldnt have any methods", i_manager.getUpdateFunctionListSize(), 0);
			
			return i_result;
		}
		
		TestResult TR_UpdateFunctionListManager_Testing_6(){
			TestResult i_result;

			UpdateFunctionListManager<TestResult&,float> i_manager;

			auto lambda = [](TestResult& a_result, float a_tpc){
				a_result.assertTrue("executing method", true);
			};

			i_manager.add(lambda);

			i_manager.update(i_result, 0.1f);
			
			return i_result;
		}

		void TR_UpdateFunctionListManager_Testing(TestRunner& a_test_runner){
			a_test_runner.map.add("UpdateFunctionListManager add and update", TR_UpdateFunctionListManager_Testing_1);
			a_test_runner.map.add("UpdateFunctionListManager removeUpdate by lvalue", TR_UpdateFunctionListManager_Testing_2);
			a_test_runner.map.add("UpdateFunctionListManager removeUpdate by index", TR_UpdateFunctionListManager_Testing_3);
			a_test_runner.map.add("UpdateFunctionListManager removeAllUpdateFunctionList", TR_UpdateFunctionListManager_Testing_4);
			a_test_runner.map.add("UpdateFunctionListManager removeAll", TR_UpdateFunctionListManager_Testing_5);
			// a_test_runner.map.add("UpdateFunctionListManager lambda", TR_UpdateFunctionListManager_Testing_6);
		}		

	}

#endif
