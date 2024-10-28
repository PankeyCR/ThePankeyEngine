
#ifndef TR_InvokeCommandMap_Testing_hpp
	#define TR_InvokeCommandMap_Testing_hpp
	
	#include "pankey.hpp"

	#include "TestResult.hpp"
	#include "TestRunner.hpp"

	#include "InvokeCommandMap.hpp"

	namespace pankey{

		class TestCommandMap : Command<TestResult&>{
			void execute(TestResult& a_result){
				a_result.assertTrue("executing method", true);
			}
		};

		class TestCommandMap_2 : Command<TestResult&>{
			void execute(TestResult& a_result){
				a_result.assertEqual("executing method", 1,1);
			}
		};

		class TestCommandMapWithError : Command<TestResult&>{
			void execute(TestResult& a_result){
				a_result.assertTrue("executing method with error", false);
			}
		};
		
		TestResult TR_InvokeCommandMap_Testing_1(){
			TestResult result;

			CommandMap<Note> i_map;

			result.assertTrue("list has to be empty", i_map.isEmpty());
			
			return result;
		}
		
		TestResult TR_InvokeCommandMap_Testing_2(){
			TestResult result;

			CommandMap<Note,float> i_map;

			result.assertTrue("list has to be empty", i_map.isEmpty());
			
			return result;
		}
		/*
		TestResult TR_InvokeCommandMap_Testing_3(){
			TestResult result;

			CommandMap<Note,TestResult&> i_map;

			command<TestResult&> i_obj = TestCommandMap();

			i_map.add("", i_obj);

			invoke<TestResult&>(i_map, 0, result);
			
			return result;
		}
		
		TestResult TR_InvokeCommandMap_Testing_4(){
			TestResult result;

			CommandMap<Note,TestResult&> i_map;

			command<TestResult&> i_obj = TestCommandMap();
			command<TestResult&> i_obj_2 = TestCommandMap_2();

			i_map.add(i_obj);
			i_map.add(i_obj_2);

			invokeAll<TestResult&>(i_map, result);
			
			return result;
		}

		class TestCommandMapReturn : CommandReturn<bool,bool>{
			bool execute(bool a_bool){
				return a_bool;
			}
		};

		class TestCommandMapReturn_2 : CommandReturn<bool,bool,TestResult&>{
			bool execute(bool a_bool, TestResult& a_result){
				a_result.assertTrue("bool parameter has to be true", a_bool);
				return a_bool;
			}
		};

		class TestCommandMapReturn_3 : CommandReturn<bool,bool,TestResult&>{
			bool execute(bool a_bool, TestResult& a_result){
				a_result.assertEqual("bool parameter has to be true", a_bool, true);
				return a_bool;
			}
		};

		TestResult TR_InvokeCommandMap_Testing_5(){
			TestResult result;

			CommandReturnMap<Note,bool,bool> i_map;

			commandReturn<bool,bool> i_obj = TestCommandMapReturn();

			i_map.add(i_obj);

			result.assertTrue("command has to return true", invoke(i_map, 0, true));
			
			return result;
		}
		
		TestResult TR_InvokeCommandMap_Testing_6(){
			TestResult result;

			CommandReturnMap<Note,bool,bool,TestResult&> i_map;

			commandReturn<bool,bool,TestResult&> i_obj = TestCommandMapReturn_2();
			commandReturn<bool,bool,TestResult&> i_obj_2 = TestCommandMapReturn_3();

			i_map.add(i_obj);
			i_map.add(i_obj_2);

			invokeAll<bool,bool,TestResult&>(i_map, true, result);
			
			return result;
		}
*/
		void TR_InvokeCommandMap_Testing(TestRunner& a_test_runner){
			createEngineManager();

			a_test_runner.map.add("CommandMap Constructor with no arguments", TR_InvokeCommandMap_Testing_1);
			a_test_runner.map.add("CommandMap Constructor with 1 float arguments", TR_InvokeCommandMap_Testing_2);
			// a_test_runner.map.add("CommandMap invoke with TestResult& argument", TR_InvokeCommandMap_Testing_3);
			// a_test_runner.map.add("CommandMap invokeAll with TestResult& argument", TR_InvokeCommandMap_Testing_4);
			// a_test_runner.map.add("CommandMap invoke class with TestResult& argument", TR_InvokeCommandMap_Testing_5);
			// a_test_runner.map.add("CommandMap invokeAll class with TestResult& argument", TR_InvokeCommandMap_Testing_6);
		}

	}

#endif
