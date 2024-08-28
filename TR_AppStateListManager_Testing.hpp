
#ifndef TR_AppStateListManager_Testing_hpp
	#define TR_AppStateListManager_Testing_hpp
	
	#include "pankey_Enviroment.hpp"
	#include "pankey_Enviroment_config.hpp"

	#include "TestResult.hpp"
	#include "TestRunner.hpp"

	#include "AppState.hpp"
	#include "AppStateListManager.hpp"

	namespace pankey{
		
		class AppListExample{};
		
		class AppStateListExample : public AppState<AppListExample,TestResult&,float>{
			public:
				virtual void initializeState(AppListExample& a_app){}
				virtual bool hasInitialize(){return false;}
				virtual void onEnable(){}
				virtual void onDisable(){}
				virtual void updateState(AppListExample& a_app, TestResult& a_result, float a_values){
					a_result.assertTrue("executing class method", true);
				}
		};
		
		class AppStateListExampleWithError : public AppState<AppListExample,TestResult&,float>{
			public:
				virtual void initializeState(AppListExample& app){}
				virtual bool hasInitialize(){return false;}
				virtual void onEnable(){}
				virtual void onDisable(){}
				virtual void updateState(AppListExample& a_app, TestResult& a_result,float a_values){
					a_result.assertTrue("executing class method with error", false);
				}
		};
	
		TestResult TR_AppStateListManager_Testing_1(){
			TestResult i_result;

			AppStateListManager<AppListExample,TestResult&,float> i_manager;
			AppListExample i_example;

			i_manager.update(i_example, i_result, 0.1f);
			
			return i_result;
		}
		
		TestResult TR_AppStateListManager_Testing_2(){
			TestResult i_result;

			AppStateListManager<AppListExample,TestResult&,float> i_manager;
			AppListExample i_example;

			app_state<AppListExample,TestResult&,float> i_state = AppStateListExample();

			i_manager.add(i_state);
			
			i_manager.update(i_example, i_result, 0.1f);
			
			i_result.assertNoteEqual("manager should have 1 appstates", i_manager.getAppStateListSize(), 1);
			
			return i_result;
		}
		
		TestResult TR_AppStateListManager_Testing_3(){
			TestResult i_result;

			AppStateListManager<AppListExample,TestResult&,float> i_manager;
			AppListExample i_example;

			app_state<AppListExample,TestResult&,float> i_state = AppStateListExample();

			i_manager.add(i_state);

			app_state<AppListExample,TestResult&,float> i_state_un = i_manager.getUnInitializedAppStateList(0);
			
			i_manager.update(i_example, i_result, 0.1f);

			app_state<AppListExample,TestResult&,float> i_state_in = i_manager.getInitializedAppStateList(0);
			
			i_result.assertEqual("states should be the same", i_state_un, i_state_in);
			
			return i_result;
		}
		
		TestResult TR_AppStateListManager_Testing_4(){
			TestResult i_result;

			AppStateListManager<AppListExample,TestResult&,float> i_manager;
			AppListExample i_example;

			app_state<AppListExample,TestResult&,float> i_state = AppStateListExample();

			i_manager.add(i_state);

			i_result.assertEqual("manager shouldnt have any methods", i_manager.getUnInitializedAppStateListSize(), 1);
			i_result.assertEqual("manager shouldnt have any methods", i_manager.getInitializedAppStateListSize(), 0);
			i_result.assertEqual("manager shouldnt have any methods", i_manager.getAppStateListSize(), 0);
			
			i_manager.update(i_example, i_result, 0.1f);

			i_result.assertEqual("manager shouldnt have any methods", i_manager.getUnInitializedAppStateListSize(), 0);
			i_result.assertEqual("manager shouldnt have any methods", i_manager.getInitializedAppStateListSize(), 1);
			i_result.assertEqual("manager shouldnt have any methods", i_manager.getAppStateListSize(), 1);
			
			return i_result;
		}
		
		TestResult TR_AppStateListManager_Testing_5(){
			TestResult i_result;

			AppStateListManager<AppListExample,TestResult&,float> i_manager;
			AppListExample i_example;

			app_state<AppListExample,TestResult&,float> i_state = AppStateListExample();

			i_manager.add(i_state);

			app_state<AppListExample,TestResult&,float> i_state_un = i_manager.removeUnInitializedAppStateList(0);

			i_result.assertEqual("manager shouldnt have any methods", i_manager.getUnInitializedAppStateListSize(), 0);
			
			i_manager.update(i_example, i_result, 0.1f);
			
			return i_result;
		}
		
		TestResult TR_AppStateListManager_Testing_6(){
			TestResult i_result;

			AppStateListManager<AppListExample,TestResult&,float> i_manager;
			AppListExample i_example;

			app_state<AppListExample,TestResult&,float> i_state = AppStateListExample();

			i_manager.add(i_state);
			
			i_manager.update(i_example, i_result, 0.1f);

			app_state<AppListExample,TestResult&,float> i_state_un = i_manager.removeInitializedAppStateList(0);

			i_result.assertEqual("manager shouldnt have any methods", i_manager.getInitializedAppStateListSize(), 0);
			
			return i_result;
		}
		
		TestResult TR_AppStateListManager_Testing_7(){
			TestResult i_result;

			AppStateListManager<AppListExample,TestResult&,float> i_manager;
			AppListExample i_example;

			app_state<AppListExample,TestResult&,float> i_state = AppStateListExample();

			i_manager.add(i_state);

			i_manager.removeAllAppStateList();

			i_result.assertEqual("manager shouldnt have any methods", i_manager.getAppStateListSize(), 0);
			
			i_manager.update(i_example, i_result, 0.1f);
			
			return i_result;
		}
		
		TestResult TR_AppStateListManager_Testing_8(){
			TestResult i_result;

			AppStateListManager<AppListExample,TestResult&,float> i_manager;
			AppListExample i_example;

			app_state<AppListExample,TestResult&,float> i_state = AppStateListExample();

			i_manager.add(i_state);
			
			i_manager.update(i_example, i_result, 0.1f);

			i_manager.removeAllAppStateList();

			i_result.assertEqual("manager shouldnt have any methods", i_manager.getAppStateListSize(), 0);
			
			return i_result;
		}
		
		TestResult TR_AppStateListManager_Testing_9(){
			TestResult i_result;

			AppStateListManager<AppListExample,TestResult&,float> i_manager;

			i_manager.add(AppStateListExample());
			
			return i_result;
		}

		void TR_AppStateListManager_Testing(TestRunner& a_test_runner){
			createEngineManager();

			a_test_runner.map.add("AppStateListManager add and update", TR_AppStateListManager_Testing_1);
			a_test_runner.map.add("AppStateListManager add", TR_AppStateListManager_Testing_2);
			a_test_runner.map.add("AppStateListManager getUnInitializedAppState and getInitializedAppState", TR_AppStateListManager_Testing_3);
			a_test_runner.map.add("AppStateListManager getUnInitializedAppStateListSize, getInitializedAppStateListSize and getAppStateListSize", TR_AppStateListManager_Testing_4);
			a_test_runner.map.add("AppStateListManager removeUnInitializedAppStateList", TR_AppStateListManager_Testing_5);
			a_test_runner.map.add("AppStateListManager removeInitializedAppState", TR_AppStateListManager_Testing_6);
			a_test_runner.map.add("AppStateListManager removeAllAppStates after update", TR_AppStateListManager_Testing_7);
			a_test_runner.map.add("AppStateListManager removeAllAppStates after update", TR_AppStateListManager_Testing_8);
			a_test_runner.map.add("AppStateListManager add", TR_AppStateListManager_Testing_9);

			// a_test_runner.map.add("AppStateListManager getUnInitializedAppState and getInitializedAppState by id", TR_AppStateListManager_Testing_7);
			// a_test_runner.map.add("AppStateListManager getAppStateById", TR_AppStateListManager_Testing_8);
			// a_test_runner.map.add("AppStateListManager removeUnInitializedAppStateListById", TR_AppStateListManager_Testing_12);
			// a_test_runner.map.add("AppStateListManager removeInitializedAppStateById", TR_AppStateListManager_Testing_13);
			// a_test_runner.map.add("AppStateListManager removeAppStateById before update", TR_AppStateListManager_Testing_14);
			// a_test_runner.map.add("AppStateListManager removeAppStateById after update", TR_AppStateListManager_Testing_15);
			
		}		

	}

#endif

	/*	
		TestResult TR_AppStateListManager_Testing_7(){
			TestResult i_result;

			AppStateListManager<AppListExample,TestResult&,float> i_manager;
			AppListExample i_example;

			app_state<AppListExample,TestResult&,float> i_state = AppStateListExample();

			i_manager.add(i_state);

			app_state<AppListExample,TestResult&,float> i_state_un = i_manager.getUnInitializedAppStateById("test");
			
			i_manager.update(i_example, i_result, 0.1f);

			app_state<AppListExample,TestResult&,float> i_state_in = i_manager.getInitializedAppStateById("test");
			
			i_result.assertEqual("states should be the same", i_state_un, i_state_in);
			
			return i_result;
		}
		TestResult TR_AppStateListManager_Testing_8(){
			TestResult i_result;

			AppStateListManager<AppListExample,TestResult&,float> i_manager;
			AppListExample i_example;

			app_state<AppListExample,TestResult&,float> i_state = AppStateListExample();
			i_state->setId("test");

			i_manager.add(i_state);

			app_state<AppListExample,TestResult&,float> i_state_un = i_manager.getAppStateById("test");
			
			i_manager.update(i_example, i_result, 0.1f);

			app_state<AppListExample,TestResult&,float> i_state_in = i_manager.getAppStateById("test");
			
			i_result.assertEqual("states should be the same", i_state_un, i_state_in);
			
			return i_result;
		}
		
		TestResult TR_AppStateListManager_Testing_12(){
			TestResult i_result;

			AppStateListManager<AppListExample,TestResult&,float> i_manager;
			AppListExample i_example;

			app_state<AppListExample,TestResult&,float> i_state = AppStateListExample();
			i_state->setId("test");

			i_manager.add(i_state);

			app_state<AppListExample,TestResult&,float> i_state_un = i_manager.removeUnInitializedAppStateListById("test");

			i_result.assertEqual("manager shouldnt have any methods", i_manager.getUnInitializedAppStateListSize(), 0);
			
			i_manager.update(i_example, i_result, 0.1f);
			
			return i_result;
		}
		
		TestResult TR_AppStateListManager_Testing_13(){
			TestResult i_result;

			AppStateListManager<AppListExample,TestResult&,float> i_manager;
			AppListExample i_example;

			app_state<AppListExample,TestResult&,float> i_state = AppStateListExample();
			i_state->setId("test");

			i_manager.add(i_state);
			
			i_manager.update(i_example, i_result, 0.1f);

			app_state<AppListExample,TestResult&,float> i_state_in = i_manager.removeInitializedAppStateById("test");

			i_result.assertEqual("manager shouldnt have any methods", i_manager.getInitializedAppStateListSize(), 0);
			
			return i_result;
		}
		
		TestResult TR_AppStateListManager_Testing_14(){
			TestResult i_result;

			AppStateListManager<AppListExample,TestResult&,float> i_manager;
			AppListExample i_example;

			app_state<AppListExample,TestResult&,float> i_state = AppStateListExample();
			i_state->setId("test");

			i_manager.add(i_state);

			app_state<AppListExample,TestResult&,float> i_state_un = i_manager.removeAppStateById("test");

			i_result.assertEqual("manager shouldnt have any methods", i_manager.getAppStateListSize(), 0);
			
			i_manager.update(i_example, i_result, 0.1f);
			
			return i_result;
		}
		
		TestResult TR_AppStateListManager_Testing_15(){
			TestResult i_result;

			AppStateListManager<AppListExample,TestResult&,float> i_manager;
			AppListExample i_example;

			app_state<AppListExample,TestResult&,float> i_state = AppStateListExample();
			i_state->setId("test");

			i_manager.add(i_state);
			
			i_manager.update(i_example, i_result, 0.1f);

			app_state<AppListExample,TestResult&,float> i_state_un = i_manager.removeAppStateById("test");

			i_result.assertEqual("manager shouldnt have any methods", i_manager.getAppStateListSize(), 0);
			
			return i_result;
		}


		*/