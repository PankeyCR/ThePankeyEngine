
#ifndef TR_InvokeMethod_Testing_hpp
	#define TR_InvokeMethod_Testing_hpp
	
	#include "pankey.hpp"

	#include "TestResult.hpp"
	#include "TestRunner.hpp"

	#include "InvokeMethod.hpp"

	namespace pankey{

		void InvokeMethodTest(TestResult& a_result){
			a_result.assertTrue("executing method", true);
		}

		bool InvokeMethodReturnTest(TestResult& a_result){
			a_result.assertTrue("executing method", true);
			return true;
		}
		
		TestResult TR_InvokeMethod_Testing_1(){
			TestResult i_result;

			InvokeMethod<TestResult&> i_method = InvokeMethodTest;

			invoke<TestResult&>(i_method, i_result);
			
			return i_result;
		}
		
		TestResult TR_InvokeMethod_Testing_2(){
			TestResult i_result;

			invoke<TestResult&>(InvokeMethodTest, i_result);
			
			return i_result;
		}
		
		TestResult TR_InvokeMethod_Testing_3(){
			TestResult i_result;

			InvokeMethod<TestResult&>* i_method = new InvokeMethod<TestResult&>(InvokeMethodTest);

			invoke<TestResult&>(i_method, i_result);

			delete i_method;
			
			return i_result;
		}
		
		TestResult TR_InvokeMethod_Testing_4(){
			TestResult i_result;

			invoke<TestResult&>(&InvokeMethodTest, i_result);
			
			return i_result;
		}
		
		TestResult TR_InvokeMethod_Testing_5(){
			TestResult i_result;

			InvokeMethodReturn<bool,TestResult&> i_method = InvokeMethodReturnTest;

			bool i_invokeResult = invoke<bool,TestResult&>(i_method, i_result);

			i_result.assertTrue("invoke method should return true", i_invokeResult);
			
			return i_result;
		}
		
		TestResult TR_InvokeMethod_Testing_6(){
			TestResult i_result;

			bool i_invokeResult = invoke<bool,TestResult&>(InvokeMethodReturnTest, i_result);

			i_result.assertTrue("invoke method should return true", i_invokeResult);
			
			return i_result;
		}
		
		TestResult TR_InvokeMethod_Testing_7(){
			TestResult i_result;

			InvokeMethodReturn<bool,TestResult&>* i_method = new InvokeMethodReturn<bool,TestResult&>(InvokeMethodReturnTest);

			bool i_invokeResult = invoke<bool,TestResult&>(i_method, i_result);

			i_result.assertTrue("invoke method should return true", i_invokeResult);

			delete i_method;
			
			return i_result;
		}
		
		TestResult TR_InvokeMethod_Testing_8(){
			TestResult i_result;

			bool i_invokeResult = invoke<bool,TestResult&>(&InvokeMethodReturnTest, i_result);

			i_result.assertTrue("invoke method should return true", i_invokeResult);
			
			return i_result;
		}

		class InvokeMethodExample{
			public:
			void run(TestResult& a_result){
				a_result.assertTrue("executing method", true);
			}
			bool won(TestResult& a_result){
				a_result.assertTrue("executing method", true);
				return true;
			}
		};
		
		TestResult TR_InvokeMethod_Testing_9(){
			TestResult i_result;

			InvokeClassMethod<InvokeMethodExample,TestResult&> i_method = &InvokeMethodExample::run;

			InvokeMethodExample i_example;

			invoke<InvokeMethodExample,TestResult&>(i_example, i_method, i_result);
			
			return i_result;
		}
		
		TestResult TR_InvokeMethod_Testing_10(){
			TestResult i_result;

			InvokeMethodExample i_example;

			invoke<InvokeMethodExample,TestResult&>(i_example, &InvokeMethodExample::run, i_result);
			
			return i_result;
		}
		
		TestResult TR_InvokeMethod_Testing_11(){
			TestResult i_result;

			InvokeClassMethodReturn<InvokeMethodExample,bool,TestResult&> i_method = &InvokeMethodExample::won;

			InvokeMethodExample i_example;

			bool i_invokeResult = invoke<InvokeMethodExample,bool,TestResult&>(i_example, i_method, i_result);

			i_result.assertTrue("invoke method should return true", i_invokeResult);
			
			return i_result;
		}
		
		TestResult TR_InvokeMethod_Testing_12(){
			TestResult i_result;

			InvokeMethodExample i_example;

			bool i_invokeResult = invoke<InvokeMethodExample,bool,TestResult&>(i_example, &InvokeMethodExample::won, i_result);

			i_result.assertTrue("invoke method should return true", i_invokeResult);
			
			return i_result;
		}
		
		TestResult TR_InvokeMethod_Testing_13(){
			TestResult i_result;

			InvokeMethod<TestResult&> i_method = [](TestResult& a_result){
				a_result.assertTrue("executing method", true);
			};

			invoke<TestResult&>(i_method, i_result);
			
			return i_result;
		}

		void TR_InvokeMethod_Testing(TestRunner& a_test_runner){
			createEngineManager();

			a_test_runner.map.add("Invoke method with instance of the method", TR_InvokeMethod_Testing_1);
			a_test_runner.map.add("Invoke method with no instance of the method", TR_InvokeMethod_Testing_2);
			a_test_runner.map.add("Invoke method as a pointer variable", TR_InvokeMethod_Testing_3);
			a_test_runner.map.add("Invoke method as a lvalue", TR_InvokeMethod_Testing_4);
			a_test_runner.map.add("Invoke method as a lvalue instance, returning a value", TR_InvokeMethod_Testing_5);
			a_test_runner.map.add("Invoke method as a lvalue, returning a value", TR_InvokeMethod_Testing_6);
			a_test_runner.map.add("Invoke method as a pointer instance, returning a value", TR_InvokeMethod_Testing_7);
			a_test_runner.map.add("Invoke method as a lvalue, returning a value", TR_InvokeMethod_Testing_8);
			a_test_runner.map.add("Invoke class method as a lvalue instance", TR_InvokeMethod_Testing_9);
			a_test_runner.map.add("Invoke class method as a lvalue", TR_InvokeMethod_Testing_10);
			a_test_runner.map.add("Invoke class method as a lvalue instance, returning a value", TR_InvokeMethod_Testing_11);
			a_test_runner.map.add("Invoke class method as a lvalue, returning a value", TR_InvokeMethod_Testing_12);
			a_test_runner.map.add("Invoke lambda", TR_InvokeMethod_Testing_13);
		}

	}

#endif
