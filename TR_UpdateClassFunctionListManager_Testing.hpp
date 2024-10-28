
#ifndef TR_UpdateClassFunctionListManager_Testing_hpp
	#define TR_UpdateClassFunctionListManager_Testing_hpp
	
	#include "pankey.hpp"

	#include "TestResult.hpp"
	#include "TestRunner.hpp"

	#include "UpdateClassFunctionListManager.hpp"

	namespace pankey{
		
		class UpdateClassFunctionListExample{
			public:
			void UpdateClassFunctionListManagerTest(TestResult& a_result, float a_tpc){
				a_result.assertTrue("executing class method", true);
			}

			void UpdateClassFunctionListManagerTestWithError(TestResult& a_result, float a_tpc){
				a_result.assertTrue("executing class method with error", false);
			}
		};
	
		TestResult TR_UpdateClassFunctionListManager_Testing_1(){
			TestResult i_result;

			UpdateClassFunctionListManager<UpdateClassFunctionListExample,TestResult&,float> i_manager;
			UpdateClassFunctionListExample i_example;

			i_manager.add(&UpdateClassFunctionListExample::UpdateClassFunctionListManagerTest);

			i_manager.update(i_example, i_result, 0.1f);
			
			return i_result;
		}
		
		TestResult TR_UpdateClassFunctionListManager_Testing_2(){
			TestResult i_result;

			UpdateClassFunctionListManager<UpdateClassFunctionListExample,TestResult&,float> i_manager;
			UpdateClassFunctionListExample i_example;

			i_manager.add(&UpdateClassFunctionListExample::UpdateClassFunctionListManagerTest);
			i_manager.add(&UpdateClassFunctionListExample::UpdateClassFunctionListManagerTestWithError);

			i_manager.removeUpdateClassFunctionList(&UpdateClassFunctionListExample::UpdateClassFunctionListManagerTestWithError);

			i_manager.update(i_example, i_result, 0.1f);
			
			return i_result;
		}
		
		TestResult TR_UpdateClassFunctionListManager_Testing_3(){
			TestResult i_result;

			UpdateClassFunctionListManager<UpdateClassFunctionListExample,TestResult&,float> i_manager;
			UpdateClassFunctionListExample i_example;

			i_manager.add(&UpdateClassFunctionListExample::UpdateClassFunctionListManagerTest);
			i_manager.add(&UpdateClassFunctionListExample::UpdateClassFunctionListManagerTestWithError);

			i_manager.removeUpdateClassFunctionList(1);
			i_manager.removeUpdateClassFunctionList(1);
			
			i_manager.update(i_example, i_result, 0.1f);
			
			return i_result;
		}
		
		TestResult TR_UpdateClassFunctionListManager_Testing_4(){
			TestResult i_result;

			UpdateClassFunctionListManager<UpdateClassFunctionListExample,TestResult&,float> i_manager;
			UpdateClassFunctionListExample i_example;

			i_manager.add(&UpdateClassFunctionListExample::UpdateClassFunctionListManagerTest);
			i_manager.add(&UpdateClassFunctionListExample::UpdateClassFunctionListManagerTestWithError);

			i_manager.removeAll();
			
			i_manager.update(i_example, i_result, 0.1f);
			
			i_result.assertEqual("manager shouldnt have any methods", i_manager.getUpdateClassFunctionListSize(), 0);
			i_result.assertEqual("manager shouldnt have any methods", i_manager.getUpdateClassFunctionListSize(), 0);
			
			return i_result;
		}

		void TR_UpdateClassFunctionListManager_Testing(TestRunner& a_test_runner){
			a_test_runner.map.add("UpdateClassFunctionListManager add and update", TR_UpdateClassFunctionListManager_Testing_1);
			a_test_runner.map.add("UpdateClassFunctionListManager removeUpdate by lvalue", TR_UpdateClassFunctionListManager_Testing_2);
			a_test_runner.map.add("UpdateClassFunctionListManager removeUpdate by index", TR_UpdateClassFunctionListManager_Testing_3);
			a_test_runner.map.add("UpdateClassFunctionListManager removeAll", TR_UpdateClassFunctionListManager_Testing_4);
		}		

	}

#endif
