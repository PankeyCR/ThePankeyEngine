
#ifndef TR_LoopManager_Testing_hpp
	#define TR_LoopManager_Testing_hpp

	#include "pankey.hpp"

	#include "TestResult.hpp"
	#include "TestRunner.hpp"

	#include "LoopManager.hpp"
	#include "BaseAppState.hpp"

	namespace pankey{

		TestResult g_loop_result;

		class LoopExample{
			public:
			void loop(){
				g_loop_result.assertTrue("executing method", true);
			}

			void tpc_loop(float a_tpc){
				g_loop_result.assertTrue("executing method", true);
			}
		};

		void LoopMethod(){
			g_loop_result.assertTrue("executing method", true);
		}
		void TPCLoopMethod(float a_tpc){
			g_loop_result.assertTrue("executing tpc method", true);
		}
		void LoopExampleMethod(LoopExample& a_example){
			g_loop_result.assertTrue("executing loopexample method", true);
		}
		void TPCLoopExampleMethod(LoopExample& a_example, float a_tpc){
			g_loop_result.assertTrue("executing loopexample tpc method", true);
		}

		class LoopExampleAppState : public BaseAppState<LoopExample,float>{
			public:
			virtual void initializeState(LoopExample& app){
				g_loop_result.assertTrue("executing appstate init method", true);
			}
			virtual void updateState(LoopExample& app, float a_tpc){
				g_loop_result.assertTrue("executing appstate update method", true);
			}
		};

		class LoopExampleState : public State<float>{
			public:
			virtual void initializeState(){
				g_loop_result.assertTrue("executing appstate init method", true);
			}
			virtual void updateState(float a_tpc){
				g_loop_result.assertTrue("executing appstate update method", true);
			}
		};

		TestResult TR_LoopManager_Testing_1(){
			g_loop_result.clear();

			LoopManager<LoopExample> i_manager;
			LoopExample i_example;

			i_manager.functions_list.add(LoopMethod);

			i_manager.update(i_example, 0.1f);

			TestResult i_result = g_loop_result;
			g_loop_result.clear();

			return i_result;
		}

		TestResult TR_LoopManager_Testing_2(){
			g_loop_result.clear();

			LoopManager<LoopExample> i_manager;
			LoopExample i_example;

			i_manager.timed_functions_list.add(TPCLoopMethod);

			i_manager.update(i_example, 0.1f);

			TestResult i_result = g_loop_result;
			g_loop_result.clear();

			return i_result;
		}

		TestResult TR_LoopManager_Testing_3(){
			g_loop_result.clear();

			LoopManager<LoopExample> i_manager;
			LoopExample i_example;

			i_manager.app_functions_list.add(LoopExampleMethod);

			i_manager.update(i_example, 0.1f);

			TestResult i_result = g_loop_result;
			g_loop_result.clear();

			return i_result;
		}

		TestResult TR_LoopManager_Testing_4(){
			g_loop_result.clear();

			LoopManager<LoopExample> i_manager;
			LoopExample i_example;

			i_manager.app_timed_functions_list.add(TPCLoopExampleMethod);

			i_manager.update(i_example, 0.1f);

			TestResult i_result = g_loop_result;
			g_loop_result.clear();

			return i_result;
		}

		TestResult TR_LoopManager_Testing_5(){
			g_loop_result.clear();

			LoopManager<LoopExample> i_manager;
			LoopExample i_example;

			i_manager.class_functions_list.add(&LoopExample::loop);

			i_manager.update(i_example, 0.1f);

			TestResult i_result = g_loop_result;
			g_loop_result.clear();

			return i_result;
		}

		TestResult TR_LoopManager_Testing_6(){
			g_loop_result.clear();

			LoopManager<LoopExample> i_manager;
			LoopExample i_example;

			i_manager.class_timed_functions_list.add(&LoopExample::tpc_loop);

			i_manager.update(i_example, 0.1f);

			TestResult i_result = g_loop_result;
			g_loop_result.clear();

			return i_result;
		}

		TestResult TR_LoopManager_Testing_7(){
			g_loop_result.clear();

			LoopManager<LoopExample> i_manager;
			LoopExample i_example;

			i_manager.app_state_functions_list.add(LoopExampleAppState());

			i_manager.update(i_example, 0.1f);

			TestResult i_result = g_loop_result;
			g_loop_result.clear();

			return i_result;
		}

		TestResult TR_LoopManager_Testing_8(){
			g_loop_result.clear();

			LoopManager<LoopExample> i_manager;
			LoopExample i_example;

			i_manager.functions_map.add("method", LoopMethod);

			i_manager.update(i_example, 0.1f);

			TestResult i_result = g_loop_result;
			g_loop_result.clear();

			return i_result;
		}

		TestResult TR_LoopManager_Testing_9(){
			g_loop_result.clear();

			LoopManager<LoopExample> i_manager;
			LoopExample i_example;

			i_manager.timed_functions_map.add("method", TPCLoopMethod);

			i_manager.update(i_example, 0.1f);

			TestResult i_result = g_loop_result;
			g_loop_result.clear();

			return i_result;
		}

		TestResult TR_LoopManager_Testing_10(){
			g_loop_result.clear();

			LoopManager<LoopExample> i_manager;
			LoopExample i_example;

			i_manager.app_functions_map.add("method", LoopExampleMethod);

			i_manager.update(i_example, 0.1f);

			TestResult i_result = g_loop_result;
			g_loop_result.clear();

			return i_result;
		}

		TestResult TR_LoopManager_Testing_11(){
			g_loop_result.clear();

			LoopManager<LoopExample> i_manager;
			LoopExample i_example;

			i_manager.app_timed_functions_map.add("method", TPCLoopExampleMethod);

			i_manager.update(i_example, 0.1f);

			TestResult i_result = g_loop_result;
			g_loop_result.clear();

			return i_result;
		}

		TestResult TR_LoopManager_Testing_12(){
			g_loop_result.clear();

			LoopManager<LoopExample> i_manager;
			LoopExample i_example;

			i_manager.class_functions_map.add("method", &LoopExample::loop);

			i_manager.update(i_example, 0.1f);

			TestResult i_result = g_loop_result;
			g_loop_result.clear();

			return i_result;
		}

		TestResult TR_LoopManager_Testing_13(){
			g_loop_result.clear();

			LoopManager<LoopExample> i_manager;
			LoopExample i_example;

			i_manager.class_timed_functions_map.add("method", &LoopExample::tpc_loop);

			i_manager.update(i_example, 0.1f);

			TestResult i_result = g_loop_result;
			g_loop_result.clear();

			return i_result;
		}

		// TestResult TR_LoopManager_Testing_14(){
		// 	g_loop_result.clear();

		// 	LoopManager<LoopExample> i_manager;
		// 	LoopExample i_example;

		// 	i_manager.app_state_functions_map.add("method", LoopExampleAppState());

		// 	i_manager.update(i_example, 0.1f);

		// 	TestResult i_result = g_loop_result;
		// 	g_loop_result.clear();

		// 	return i_result;
		// }

		TestResult TR_LoopManager_Testing_15(){
			g_loop_result.clear();

			LoopManager<LoopExample> i_manager;
			LoopExample i_example;

			i_manager.state_functions_list.add(LoopExampleState());

			i_manager.update(i_example, 0.1f);

			TestResult i_result = g_loop_result;
			g_loop_result.clear();

			return i_result;
		}

		void TR_LoopManager_Testing(TestRunner& a_test_runner){
			createEngineManager();

			a_test_runner.map.add("TR_LoopManager_Testing add (single method) and update", TR_LoopManager_Testing_1);
			a_test_runner.map.add("TR_LoopManager_Testing add (tpc method) and update", TR_LoopManager_Testing_2);
			a_test_runner.map.add("TR_LoopManager_Testing add (loop example method) and update", TR_LoopManager_Testing_3);
			a_test_runner.map.add("TR_LoopManager_Testing add (loop example, float method) and update", TR_LoopManager_Testing_4);
			a_test_runner.map.add("TR_LoopManager_Testing add (class single method) and update", TR_LoopManager_Testing_5);
			a_test_runner.map.add("TR_LoopManager_Testing add (class tpc method) and update", TR_LoopManager_Testing_6);
			a_test_runner.map.add("TR_LoopManager_Testing add (appstate) and update", TR_LoopManager_Testing_7);

			a_test_runner.map.add("TR_LoopManager_Testing add (single method) and update", TR_LoopManager_Testing_8);
			a_test_runner.map.add("TR_LoopManager_Testing add (tpc method) and update", TR_LoopManager_Testing_9);
			a_test_runner.map.add("TR_LoopManager_Testing add (loop example method) and update", TR_LoopManager_Testing_10);
			a_test_runner.map.add("TR_LoopManager_Testing add (loop example, float method) and update", TR_LoopManager_Testing_11);
			a_test_runner.map.add("TR_LoopManager_Testing add (class single method) and update", TR_LoopManager_Testing_12);
			a_test_runner.map.add("TR_LoopManager_Testing add (class tpc method) and update", TR_LoopManager_Testing_13);
			// a_test_runner.map.add("TR_LoopManager_Testing add (appstate) and update", TR_LoopManager_Testing_14);
			
			a_test_runner.map.add("TR_LoopManager_Testing add (class tpc method) and update", TR_LoopManager_Testing_15);
		}

	}

#endif
