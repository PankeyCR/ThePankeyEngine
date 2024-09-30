
#ifndef TR_InvokeList_Testing_hpp
	#define TR_InvokeList_Testing_hpp
	
	#include "pankey.hpp"

	#include "TestResult.hpp"
	#include "TestRunner.hpp"

	#include "InvokeList.hpp"

	namespace pankey{

		class TestListInvoker{
			public:
			void run(TestResult& a_result){
				a_result.assertTrue("executing method", true);
			}
			bool won(TestResult& a_result){
				a_result.assertTrue("executing method", true);
				return true;
			}
		};
		
		TestResult TR_InvokeList_Testing_1(){
			TestResult i_result;

			InvokerList<TestListInvoker> i_list;

			i_result.assertTrue("list has to be empty", i_list.isEmpty());
			
			return i_result;
		}
		
		TestResult TR_InvokeList_Testing_2(){
			TestResult i_result;

			invoking<TestListInvoker> i_class = TestListInvoker();

			invoke<TestListInvoker,TestResult&>(i_class, &TestListInvoker::run, i_result);
			
			return i_result;
		}
		
		TestResult TR_InvokeList_Testing_3(){
			TestResult i_result;

			InvokerList<TestListInvoker> i_list;

			invoking<TestListInvoker> i_class = TestListInvoker();

			i_list.add(i_class);

			invoke<TestListInvoker,TestResult&>(i_list, 0, &TestListInvoker::run, i_result);
			
			return i_result;
		}
		
		TestResult TR_InvokeList_Testing_4(){
			TestResult i_result;

			InvokerList<TestListInvoker> i_list;

			invoking<TestListInvoker> i_class_1 = TestListInvoker();
			invoking<TestListInvoker> i_class_2 = TestListInvoker();
			invoking<TestListInvoker> i_class_3 = TestListInvoker();

			i_list.add(i_class_1);
			i_list.add(i_class_2);
			i_list.add(i_class_3);

			invokeAll<TestListInvoker,TestResult&>(i_list, &TestListInvoker::run, i_result);
			
			return i_result;
		}

		void TR_InvokeList_Testing(TestRunner& a_test_runner){
			createEngineManager();

			a_test_runner.map.add("List Constructor with no arguments", TR_InvokeList_Testing_1);
			a_test_runner.map.add("invoking class method", TR_InvokeList_Testing_2);
			a_test_runner.map.add("List invoking class method", TR_InvokeList_Testing_3);
			a_test_runner.map.add("List invoking all class method", TR_InvokeList_Testing_4);
		}

	}

#endif
