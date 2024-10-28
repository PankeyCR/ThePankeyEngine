
#ifndef TR_Function_Testing_hpp
	#define TR_Function_Testing_hpp
	
	#include "pankey.hpp"

	#include "TestResult.hpp"
	#include "TestRunner.hpp"

	#include "Function.hpp"
	#include "FreeFunction.hpp"

	namespace pankey{

		float FunctionTesting(float a_fx){
			return a_fx;
		}

		float FunctionTesting_2(float a_fx){
			return a_fx;
		}
	
		TestResult TR_Function_Testing_1(){
			TestResult i_result;

			Fx i_fx;
			
			return i_result;
		}
	
		TestResult TR_Function_Testing_2(){
			TestResult i_result;

			Fx i_fx = FreeFun(FunctionTesting);

			i_result.assertNoteEqual("function return should be 15.5f", i_fx.run(15.5f), 15.5f);
			i_result.assertTrue("function should be FunctionTesting", i_fx == FreeFun(FunctionTesting));
			i_result.assertTrue("function shouldnt be FunctionTesting_2", i_fx != FreeFun(FunctionTesting_2));
			
			return i_result;
		}
	
		TestResult TR_Function_Testing_3(){
			TestResult i_result;

			Fx i_fx;
			i_fx = FreeFun(FunctionTesting);

			i_result.assertNoteEqual("function return should be 15.5f", i_fx.run(15.5f), 15.5f);
			i_result.assertTrue("function should be FunctionTesting", i_fx == FreeFun(FunctionTesting));
			i_result.assertTrue("function shouldnt be FunctionTesting_2", i_fx != FreeFun(FunctionTesting_2));
			
			return i_result;
		}

		void TR_Function_Testing(TestRunner& a_test_runner){
			a_test_runner.map.add("Function Constructor", TR_Function_Testing_1);
			a_test_runner.map.add("Function Constructor Free Function", TR_Function_Testing_2);
			a_test_runner.map.add("Function operator= Free Function", TR_Function_Testing_3);
		}

	}

#endif
