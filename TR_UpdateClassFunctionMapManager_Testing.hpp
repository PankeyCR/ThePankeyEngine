
#ifndef TR_UpdateClassFunctionMapManager_Testing_hpp
	#define TR_UpdateClassFunctionMapManager_Testing_hpp
	
	#include "higgs_Enviroment.hpp"
	#include "higgs_Enviroment_config.hpp"

	#include "TestResult.hpp"
	#include "TestRunner.hpp"

	#include "UpdateClassFunctionMapManager.hpp"

	namespace higgs{
		
		class UpdateClassFunctionMapExample{
			public:
			void UpdateClassFunctionMapManagerTest(TestResult& a_result, float a_tpc){
				a_result.assertTrue("executing class method", true);
			}

			void UpdateClassFunctionMapManagerTestWithError(TestResult& a_result, float a_tpc){
				a_result.assertTrue("executing class method with error", false);
			}
		};
	
		TestResult TR_UpdateClassFunctionMapManager_Testing_1(){
			TestResult i_result;

			UpdateClassFunctionMapManager<UpdateClassFunctionMapExample,Note,TestResult&,float> i_manager;
			UpdateClassFunctionMapExample i_example;

			i_manager.add("class_function", &UpdateClassFunctionMapExample::UpdateClassFunctionMapManagerTest);

			i_manager.update(i_example, i_result, 0.1f);
			
			return i_result;
		}
		
		TestResult TR_UpdateClassFunctionMapManager_Testing_2(){
			TestResult i_result;

			UpdateClassFunctionMapManager<UpdateClassFunctionMapExample,Note,TestResult&,float> i_manager;
			UpdateClassFunctionMapExample i_example;

			i_manager.add("class_function", &UpdateClassFunctionMapExample::UpdateClassFunctionMapManagerTest);
			i_manager.add("class_error_function", &UpdateClassFunctionMapExample::UpdateClassFunctionMapManagerTestWithError);

			i_manager.removeUpdateClassFunctionMap("class_error_function");

			i_manager.update(i_example, i_result, 0.1f);
			
			return i_result;
		}
		
		TestResult TR_UpdateClassFunctionMapManager_Testing_3(){
			TestResult i_result;

			UpdateClassFunctionMapManager<UpdateClassFunctionMapExample,Note,TestResult&,float> i_manager;
			UpdateClassFunctionMapExample i_example;

			i_manager.add("class_function", &UpdateClassFunctionMapExample::UpdateClassFunctionMapManagerTest);
			i_manager.add("class_error_function", &UpdateClassFunctionMapExample::UpdateClassFunctionMapManagerTestWithError);

			i_manager.removeUpdateClassFunctionMap(1);
			
			i_manager.update(i_example, i_result, 0.1f);
			
			return i_result;
		}
		
		TestResult TR_UpdateClassFunctionMapManager_Testing_4(){
			TestResult i_result;

			UpdateClassFunctionMapManager<UpdateClassFunctionMapExample,Note,TestResult&,float> i_manager;
			UpdateClassFunctionMapExample i_example;

			i_manager.add("class_function", &UpdateClassFunctionMapExample::UpdateClassFunctionMapManagerTest);
			i_manager.add("class_error_function", &UpdateClassFunctionMapExample::UpdateClassFunctionMapManagerTestWithError);

			i_manager.removeAll();
			
			i_manager.update(i_example, i_result, 0.1f);
			
			i_result.assertEqual("manager shouldnt have any methods", i_manager.getUpdateClassFunctionMapSize(), 0);
			i_result.assertEqual("manager shouldnt have any methods", i_manager.getUpdateClassFunctionMapSize(), 0);
			
			return i_result;
		}

		void TR_UpdateClassFunctionMapManager_Testing(TestRunner& a_test_runner){
			a_test_runner.map.add("UpdateClassFunctionMapManager add and update", TR_UpdateClassFunctionMapManager_Testing_1);
			a_test_runner.map.add("UpdateClassFunctionMapManager removeUpdate by lvalue", TR_UpdateClassFunctionMapManager_Testing_2);
			a_test_runner.map.add("UpdateClassFunctionMapManager removeUpdate by index", TR_UpdateClassFunctionMapManager_Testing_3);
			a_test_runner.map.add("UpdateClassFunctionMapManager removeAll", TR_UpdateClassFunctionMapManager_Testing_4);
		}		

	}

#endif
