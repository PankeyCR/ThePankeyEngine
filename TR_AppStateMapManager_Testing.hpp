
#ifndef TR_AppStateMapManager_Testing_hpp
	#define TR_AppStateMapManager_Testing_hpp
	
	#include "pankey.hpp"

	#include "TestResult.hpp"
	#include "TestRunner.hpp"

	#include "AppState.hpp"
	#include "AppStateMapManager.hpp"

	namespace pankey{
		
		class AppMapExample{};
		
		class AppStateMapExample : public AppState<AppMapExample,TestResult&,float>{
			public:
				virtual void initializeState(AppMapExample& a_app){}
				virtual bool hasInitialize(){return false;}
				virtual void onEnable(){}
				virtual void onDisable(){}
				virtual void updateState(AppMapExample& a_app, TestResult& a_result, float a_values){
					a_result.assertTrue("executing class method", true);
				}
		};
		
		class AppStateMapExampleWithError : public AppState<AppMapExample,TestResult&,float>{
			public:
				virtual void initializeState(AppMapExample& app){}
				virtual bool hasInitialize(){return false;}
				virtual void onEnable(){}
				virtual void onDisable(){}
				virtual void updateState(AppMapExample& a_app, TestResult& a_result,float a_values){
					a_result.assertTrue("executing class method with error", false);
				}
		};
	
		TestResult TR_AppStateMapManager_Testing_1(){
			TestResult i_result;

			AppStateMapManager<AppMapExample,TestResult&,float> i_manager;
			AppMapExample i_example;

			i_manager.update(i_example, i_result, 0.1f);
			
			return i_result;
		}
		/*
		TestResult TR_AppStateMapManager_Testing_2(){
			TestResult i_result;

			AppStateMapManager<AppMapExample,TestResult&,float> i_manager;
			AppMapExample i_example;

			app_state<AppMapExample,TestResult&,float> i_state = AppStateMapExample();

			i_manager.add(i_state);
			
			i_manager.update(i_example, i_result, 0.1f);
			
			i_result.assertNoteEqual("manager should have 1 appstates", i_manager.getAppStateMapSize(), 1);
			
			return i_result;
		}
		
		TestResult TR_AppStateMapManager_Testing_3(){
			TestResult i_result;

			AppStateMapManager<AppMapExample,TestResult&,float> i_manager;
			AppMapExample i_example;

			app_state<AppMapExample,TestResult&,float> i_state = AppStateMapExample();

			i_manager.add(i_state);

			app_state<AppMapExample,TestResult&,float> i_state_un = i_manager.getUnInitializedAppStateMap(0);
			
			i_manager.update(i_example, i_result, 0.1f);

			app_state<AppMapExample,TestResult&,float> i_state_in = i_manager.getInitializedAppStateMap(0);
			
			i_result.assertEqual("states should be the same", i_state_un, i_state_in);
			
			return i_result;
		}
		
		TestResult TR_AppStateMapManager_Testing_4(){
			TestResult i_result;

			AppStateMapManager<AppMapExample,TestResult&,float> i_manager;
			AppMapExample i_example;

			app_state<AppMapExample,TestResult&,float> i_state = AppStateMapExample();

			i_manager.add(i_state);

			i_result.assertEqual("manager shouldnt have any methods", i_manager.getUnInitializedAppStateMapSize(), 1);
			i_result.assertEqual("manager shouldnt have any methods", i_manager.getInitializedAppStateMapSize(), 0);
			i_result.assertEqual("manager shouldnt have any methods", i_manager.getAppStateMapSize(), 0);
			
			i_manager.update(i_example, i_result, 0.1f);

			i_result.assertEqual("manager shouldnt have any methods", i_manager.getUnInitializedAppStateMapSize(), 0);
			i_result.assertEqual("manager shouldnt have any methods", i_manager.getInitializedAppStateMapSize(), 1);
			i_result.assertEqual("manager shouldnt have any methods", i_manager.getAppStateMapSize(), 1);
			
			return i_result;
		}
		
		TestResult TR_AppStateMapManager_Testing_5(){
			TestResult i_result;

			AppStateMapManager<AppMapExample,TestResult&,float> i_manager;
			AppMapExample i_example;

			app_state<AppMapExample,TestResult&,float> i_state = AppStateMapExample();

			i_manager.add(i_state);

			app_state<AppMapExample,TestResult&,float> i_state_un = i_manager.removeUnInitializedAppStateMap(0);

			i_result.assertEqual("manager shouldnt have any methods", i_manager.getUnInitializedAppStateMapSize(), 0);
			
			i_manager.update(i_example, i_result, 0.1f);
			
			return i_result;
		}
		
		TestResult TR_AppStateMapManager_Testing_6(){
			TestResult i_result;

			AppStateMapManager<AppMapExample,TestResult&,float> i_manager;
			AppMapExample i_example;

			app_state<AppMapExample,TestResult&,float> i_state = AppStateMapExample();

			i_manager.add(i_state);
			
			i_manager.update(i_example, i_result, 0.1f);

			app_state<AppMapExample,TestResult&,float> i_state_un = i_manager.removeInitializedAppStateMap(0);

			i_result.assertEqual("manager shouldnt have any methods", i_manager.getInitializedAppStateMapSize(), 0);
			
			return i_result;
		}
		
		TestResult TR_AppStateMapManager_Testing_7(){
			TestResult i_result;

			AppStateMapManager<AppMapExample,TestResult&,float> i_manager;
			AppMapExample i_example;

			app_state<AppMapExample,TestResult&,float> i_state = AppStateMapExample();

			i_manager.add(i_state);

			i_manager.removeAllAppStateMap();

			i_result.assertEqual("manager shouldnt have any methods", i_manager.getAppStateMapSize(), 0);
			
			i_manager.update(i_example, i_result, 0.1f);
			
			return i_result;
		}
		
		TestResult TR_AppStateMapManager_Testing_8(){
			TestResult i_result;

			AppStateMapManager<AppMapExample,TestResult&,float> i_manager;
			AppMapExample i_example;

			app_state<AppMapExample,TestResult&,float> i_state = AppStateMapExample();

			i_manager.add(i_state);
			
			i_manager.update(i_example, i_result, 0.1f);

			i_manager.removeAllAppStateMap();

			i_result.assertEqual("manager shouldnt have any methods", i_manager.getAppStateMapSize(), 0);
			
			return i_result;
		}
		
		TestResult TR_AppStateMapManager_Testing_9(){
			TestResult i_result;

			AppStateMapManager<AppMapExample,TestResult&,float> i_manager;

			i_manager.add(AppStateMapExample());
			
			return i_result;
		}
*/
		void TR_AppStateMapManager_Testing(TestRunner& a_test_runner){
			createEngineManager();

			// a_test_runner.map.add("AppStateMapManager add and update", TR_AppStateMapManager_Testing_1);
			// a_test_runner.map.add("AppStateMapManager add", TR_AppStateMapManager_Testing_2);
			// a_test_runner.map.add("AppStateMapManager getUnInitializedAppState and getInitializedAppState", TR_AppStateMapManager_Testing_3);
			// a_test_runner.map.add("AppStateMapManager getUnInitializedAppStateMapSize, getInitializedAppStateMapSize and getAppStateMapSize", TR_AppStateMapManager_Testing_4);
			// a_test_runner.map.add("AppStateMapManager removeUnInitializedAppStateMap", TR_AppStateMapManager_Testing_5);
			// a_test_runner.map.add("AppStateMapManager removeInitializedAppState", TR_AppStateMapManager_Testing_6);
			// a_test_runner.map.add("AppStateMapManager removeAllAppStates after update", TR_AppStateMapManager_Testing_7);
			// a_test_runner.map.add("AppStateMapManager removeAllAppStates after update", TR_AppStateMapManager_Testing_8);
			// a_test_runner.map.add("AppStateMapManager add", TR_AppStateMapManager_Testing_9);

			// a_test_runner.map.add("AppStateMapManager getUnInitializedAppState and getInitializedAppState by id", TR_AppStateMapManager_Testing_7);
			// a_test_runner.map.add("AppStateMapManager getAppStateById", TR_AppStateMapManager_Testing_8);
			// a_test_runner.map.add("AppStateMapManager removeUnInitializedAppStateMapById", TR_AppStateMapManager_Testing_12);
			// a_test_runner.map.add("AppStateMapManager removeInitializedAppStateById", TR_AppStateMapManager_Testing_13);
			// a_test_runner.map.add("AppStateMapManager removeAppStateById before update", TR_AppStateMapManager_Testing_14);
			// a_test_runner.map.add("AppStateMapManager removeAppStateById after update", TR_AppStateMapManager_Testing_15);
			
		}		

	}

#endif

	/*	
		TestResult TR_AppStateMapManager_Testing_7(){
			TestResult i_result;

			AppStateMapManager<AppMapExample,TestResult&,float> i_manager;
			AppMapExample i_example;

			app_state<AppMapExample,TestResult&,float> i_state = AppStateMapExample();

			i_manager.add(i_state);

			app_state<AppMapExample,TestResult&,float> i_state_un = i_manager.getUnInitializedAppStateById("test");
			
			i_manager.update(i_example, i_result, 0.1f);

			app_state<AppMapExample,TestResult&,float> i_state_in = i_manager.getInitializedAppStateById("test");
			
			i_result.assertEqual("states should be the same", i_state_un, i_state_in);
			
			return i_result;
		}
		TestResult TR_AppStateMapManager_Testing_8(){
			TestResult i_result;

			AppStateMapManager<AppMapExample,TestResult&,float> i_manager;
			AppMapExample i_example;

			app_state<AppMapExample,TestResult&,float> i_state = AppStateMapExample();
			i_state->setId("test");

			i_manager.add(i_state);

			app_state<AppMapExample,TestResult&,float> i_state_un = i_manager.getAppStateById("test");
			
			i_manager.update(i_example, i_result, 0.1f);

			app_state<AppMapExample,TestResult&,float> i_state_in = i_manager.getAppStateById("test");
			
			i_result.assertEqual("states should be the same", i_state_un, i_state_in);
			
			return i_result;
		}
		
		TestResult TR_AppStateMapManager_Testing_12(){
			TestResult i_result;

			AppStateMapManager<AppMapExample,TestResult&,float> i_manager;
			AppMapExample i_example;

			app_state<AppMapExample,TestResult&,float> i_state = AppStateMapExample();
			i_state->setId("test");

			i_manager.add(i_state);

			app_state<AppMapExample,TestResult&,float> i_state_un = i_manager.removeUnInitializedAppStateMapById("test");

			i_result.assertEqual("manager shouldnt have any methods", i_manager.getUnInitializedAppStateMapSize(), 0);
			
			i_manager.update(i_example, i_result, 0.1f);
			
			return i_result;
		}
		
		TestResult TR_AppStateMapManager_Testing_13(){
			TestResult i_result;

			AppStateMapManager<AppMapExample,TestResult&,float> i_manager;
			AppMapExample i_example;

			app_state<AppMapExample,TestResult&,float> i_state = AppStateMapExample();
			i_state->setId("test");

			i_manager.add(i_state);
			
			i_manager.update(i_example, i_result, 0.1f);

			app_state<AppMapExample,TestResult&,float> i_state_in = i_manager.removeInitializedAppStateById("test");

			i_result.assertEqual("manager shouldnt have any methods", i_manager.getInitializedAppStateMapSize(), 0);
			
			return i_result;
		}
		
		TestResult TR_AppStateMapManager_Testing_14(){
			TestResult i_result;

			AppStateMapManager<AppMapExample,TestResult&,float> i_manager;
			AppMapExample i_example;

			app_state<AppMapExample,TestResult&,float> i_state = AppStateMapExample();
			i_state->setId("test");

			i_manager.add(i_state);

			app_state<AppMapExample,TestResult&,float> i_state_un = i_manager.removeAppStateById("test");

			i_result.assertEqual("manager shouldnt have any methods", i_manager.getAppStateMapSize(), 0);
			
			i_manager.update(i_example, i_result, 0.1f);
			
			return i_result;
		}
		
		TestResult TR_AppStateMapManager_Testing_15(){
			TestResult i_result;

			AppStateMapManager<AppMapExample,TestResult&,float> i_manager;
			AppMapExample i_example;

			app_state<AppMapExample,TestResult&,float> i_state = AppStateMapExample();
			i_state->setId("test");

			i_manager.add(i_state);
			
			i_manager.update(i_example, i_result, 0.1f);

			app_state<AppMapExample,TestResult&,float> i_state_un = i_manager.removeAppStateById("test");

			i_result.assertEqual("manager shouldnt have any methods", i_manager.getAppStateMapSize(), 0);
			
			return i_result;
		}


		*/