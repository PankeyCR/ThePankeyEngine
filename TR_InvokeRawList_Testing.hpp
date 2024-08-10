
#ifndef TR_InvokeRawList_Testing_hpp
	#define TR_InvokeRawList_Testing_hpp
	
	#include "higgs_Enviroment.hpp"
	#include "higgs_Enviroment_config.hpp"

	#include "TestResult.hpp"
	#include "TestRunner.hpp"

	#include "PrimitiveRawPointerList.hpp"
	#include "InvokeRawList.hpp"

	namespace higgs{

		void TestMethod(TestResult& a_result){
			a_result.assertTrue("executing method", true);
		}

		void TestMethod_2(TestResult& a_result){
			a_result.assertEqual("executing method 2", 1, 1);
		}

		int TestMethod_3(TestResult& a_result){
			a_result.assertEqual("executing method 3", 1, 1);
			return 1;
		}

		int TestMethod_4(TestResult& a_result){
			a_result.assertEqual("executing method 3", 1, 1);
			return 2;
		}
		
		TestResult TR_InvokeRawList_Testing_1(){
			TestResult result;

			MethodList<> i_list;

			result.assertTrue("list has to be empty", i_list.isEmpty());
			
			return result;
		}
		
		TestResult TR_InvokeRawList_Testing_2(){
			TestResult result;

			MethodList<float> i_list;

			result.assertTrue("list has to be empty", i_list.isEmpty());
			
			return result;
		}
		
		TestResult TR_InvokeRawList_Testing_3(){
			TestResult result;

			MethodList<TestResult&> i_list;

			i_list.add(TestMethod);

			invoke<TestResult&>(i_list, 0, result);
			
			return result;
		}
		
		TestResult TR_InvokeRawList_Testing_4(){
			TestResult result;

			MethodList<TestResult&> i_list;

			i_list.add(TestMethod);
			i_list.add(TestMethod_2);

			invokeAll<TestResult&>(i_list, result);
			
			return result;
		}

		class InvokeExample{
			public:
			void TestMethod(TestResult& a_result){
				a_result.assertTrue("executing method", true);
			}
			void TestMethod_2(TestResult& a_result){
				a_result.assertTrue("executing method", true);
			}
			int TestMethod_3(TestResult& a_result){
				a_result.assertTrue("executing method", true);
				return 1;
			}
			int TestMethod_4(TestResult& a_result){
				a_result.assertTrue("executing method", true);
				return 2;
			}
		};
		
		TestResult TR_InvokeRawList_Testing_5(){
			TestResult result;

			ClassMethodList<InvokeExample,TestResult&> i_list;

			i_list.add(&InvokeExample::TestMethod);
			i_list.add(&InvokeExample::TestMethod_2);

			InvokeExample example;

			invoke<InvokeExample,TestResult&>(i_list, example, 0, result);
			
			return result;
		}
		
		TestResult TR_InvokeRawList_Testing_6(){
			TestResult result;

			ClassMethodList<InvokeExample,TestResult&> i_list;

			i_list.add(&InvokeExample::TestMethod);
			i_list.add(&InvokeExample::TestMethod_2);

			InvokeExample example;

			invokeAll<InvokeExample,TestResult&>(i_list, example, result);
			
			return result;
		}
		
		TestResult TR_InvokeRawList_Testing_7(){
			TestResult result;

			MethodReturnList<int,TestResult&> i_list;

			i_list.add(TestMethod_3);
			i_list.add(TestMethod_4);

			InvokeExample example;

			int i_num = invoke<int,TestResult&>(i_list, 0, result);

			result.assertEqual("i_num should be 1", i_num, 1);
			
			return result;
		}
		
		TestResult TR_InvokeRawList_Testing_8(){
			TestResult result;

			ClassMethodReturnList<InvokeExample,int,TestResult&> i_list;

			i_list.add(&InvokeExample::TestMethod_3);
			i_list.add(&InvokeExample::TestMethod_4);

			InvokeExample example;

			int i_num = invoke<InvokeExample,int,TestResult&>(i_list, example, 0, result);

			result.assertEqual("i_num should be 1", i_num, 1);
			
			return result;
		}
		
		TestResult TR_InvokeRawList_Testing_9(){
			TestResult result;

			InvokeMethod<TestResult&>* i_method = new InvokeMethod<TestResult&>(TestMethod);

			invoke<TestResult&>(i_method, result);
			
			delete i_method;
			
			return result;
		}

		void TR_InvokeRawList_Testing(TestRunner& a_test_runner){
			a_test_runner.map.add("MethodList Constructor with no arguments", TR_InvokeRawList_Testing_1);
			a_test_runner.map.add("MethodList Constructor with 1 float arguments", TR_InvokeRawList_Testing_2);
			a_test_runner.map.add("MethodList invoke with TestResult& argument", TR_InvokeRawList_Testing_3);
			a_test_runner.map.add("MethodList invokeAll with TestResult& argument", TR_InvokeRawList_Testing_4);
			a_test_runner.map.add("MethodList invoke class with TestResult& argument", TR_InvokeRawList_Testing_5);
			a_test_runner.map.add("MethodList invokeAll class with TestResult& argument", TR_InvokeRawList_Testing_6);
			a_test_runner.map.add("MethodList invoke return with TestResult& argument", TR_InvokeRawList_Testing_7);
			a_test_runner.map.add("MethodList invoke class return with TestResult& argument", TR_InvokeRawList_Testing_8);
			a_test_runner.map.add("MethodList invoke method", TR_InvokeRawList_Testing_9);
		}		

	}

#endif
