
#ifndef TR_InvokeCommandList_Testing_hpp
	#define TR_InvokeCommandList_Testing_hpp
	
	#include "pankey.hpp"

	#include "TestResult.hpp"
	#include "TestRunner.hpp"

	#include "InvokeCommandList.hpp"

	namespace pankey{

		class TestCommandList : Command<TestResult&>{
			void execute(TestResult& a_result){
				a_result.assertTrue("executing method", true);
			}
		};

		class TestCommandList_2 : Command<TestResult&>{
			void execute(TestResult& a_result){
				a_result.assertEqual("executing method", 1,1);
			}
		};

		class TestCommandListWithError : Command<TestResult&>{
			void execute(TestResult& a_result){
				a_result.assertTrue("executing method with error", false);
			}
		};
		
		TestResult TR_InvokeCommandList_Testing_1(){
			TestResult result;

			CommandList<> i_list;

			result.assertTrue("list has to be empty", i_list.isEmpty());
			
			return result;
		}
		
		TestResult TR_InvokeCommandList_Testing_2(){
			TestResult result;

			CommandList<float> i_list;

			result.assertTrue("list has to be empty", i_list.isEmpty());
			
			return result;
		}
		
		TestResult TR_InvokeCommandList_Testing_3(){
			TestResult result;

			CommandList<TestResult&> i_list;

			command<TestResult&> i_obj = TestCommandList();

			i_list.add(i_obj);

			invoke<TestResult&>(i_list, 0, result);
			
			return result;
		}
		
		TestResult TR_InvokeCommandList_Testing_4(){
			TestResult result;

			CommandList<TestResult&> i_list;

			command<TestResult&> i_obj = TestCommandList();
			command<TestResult&> i_obj_2 = TestCommandList_2();

			i_list.add(i_obj);
			i_list.add(i_obj_2);

			invokeAll<TestResult&>(i_list, result);
			
			return result;
		}

		class TestCommandListReturn : CommandReturn<bool,bool>{
			bool execute(bool a_bool){
				return a_bool;
			}
		};

		class TestCommandListReturn_2 : CommandReturn<bool,bool,TestResult&>{
			bool execute(bool a_bool, TestResult& a_result){
				a_result.assertTrue("bool parameter has to be true", a_bool);
				return a_bool;
			}
		};

		class TestCommandListReturn_3 : CommandReturn<bool,bool,TestResult&>{
			bool execute(bool a_bool, TestResult& a_result){
				a_result.assertEqual("bool parameter has to be true", a_bool, true);
				return a_bool;
			}
		};

		TestResult TR_InvokeCommandList_Testing_5(){
			TestResult result;

			CommandReturnList<bool,bool> i_list;

			commandReturn<bool,bool> i_obj = TestCommandListReturn();

			i_list.add(i_obj);

			result.assertTrue("command has to return true", invoke(i_list, 0, true));
			
			return result;
		}
		
		TestResult TR_InvokeCommandList_Testing_6(){
			TestResult result;

			CommandReturnList<bool,bool,TestResult&> i_list;

			commandReturn<bool,bool,TestResult&> i_obj = TestCommandListReturn_2();
			commandReturn<bool,bool,TestResult&> i_obj_2 = TestCommandListReturn_3();

			i_list.add(i_obj);
			i_list.add(i_obj_2);

			invokeAll<bool,bool,TestResult&>(i_list, true, result);
			
			return result;
		}

		void TR_InvokeCommandList_Testing(TestRunner& a_test_runner){
			createEngineManager();

			a_test_runner.map.add("CommandList Constructor with no arguments", TR_InvokeCommandList_Testing_1);
			a_test_runner.map.add("CommandList Constructor with 1 float arguments", TR_InvokeCommandList_Testing_2);
			a_test_runner.map.add("CommandList invoke with TestResult& argument", TR_InvokeCommandList_Testing_3);
			a_test_runner.map.add("CommandList invokeAll with TestResult& argument", TR_InvokeCommandList_Testing_4);
			a_test_runner.map.add("CommandList invoke class with TestResult& argument", TR_InvokeCommandList_Testing_5);
			a_test_runner.map.add("CommandList invokeAll class with TestResult& argument", TR_InvokeCommandList_Testing_6);
		}

	}

#endif
