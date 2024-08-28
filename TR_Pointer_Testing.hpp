
#ifndef TR_Pointer_Testing_hpp
	#define TR_Pointer_Testing_hpp
	
	#include "pankey_Enviroment.hpp"
	#include "pankey_Enviroment_config.hpp"

	#include "TestResult.hpp"
	#include "TestRunner.hpp"

	#include "Pointer.hpp"
	#include "Variable.hpp"

	namespace pankey{
		
		TestResult TR_Pointer_Testing_1(){
			TestResult result;

			pointer<int> i_pointer;

			result.assertTrue("allocator shouldnt be null", !i_pointer.isManagerNull());
			result.assertTrue("holder has to be null", i_pointer.isHolderNull());
			result.assertTrue("pointer has to be null", i_pointer.isNull());

			return result;
		}
		
		TestResult TR_Pointer_Testing_2(){
			TestResult result;
			
			pointer<int> i_pointer;

			i_pointer.create();

			result.assertTrue("allocator shouldnt be null", !i_pointer.isManagerNull());
			result.assertTrue("holder shouldnt be null", !i_pointer.isHolderNull());
			result.assertTrue("pointer shouldnt be null", !i_pointer.isNull());

			return result;
		}
		
		TestResult TR_Pointer_Testing_3(){
			TestResult result;
			
			pointer<int> i_pointer;

			i_pointer.create();

			result.assertTrue("pointer shouldnt be null", !i_pointer.isNull());

			if(i_pointer.isNull()){
				result.catchError(100, "Fail test");
				return result;
			}

			int* i_value = i_pointer.get();

			result.assertTrue("pointer value shouldnt be null", i_value != nullptr);

			if(i_value == nullptr){
				result.catchError(101, "Fail test");
				return result;
			}

			*i_value = 5;

			result.assertEqual("pointer value should be 5", *i_value, 5);
			
			pointer<int> i_pointer_2 = i_pointer;

			result.assertTrue("pointer 2 shouldnt be null", !i_pointer_2.isNull());

			if(i_pointer_2.isNull()){
				result.catchError(102, "Fail test");
				return result;
			}

			int* value_2 = i_pointer_2.get();

			result.assertTrue("pointer 2 value shouldnt be null", value_2 != nullptr);

			if(value_2 == nullptr){
				result.catchError(103, "Fail test");
				return result;
			}

			result.assertEqual("pointer 2 value should be 5", *value_2, 5);

			return result;
		}
		
		TestResult TR_Pointer_Testing_4(){
			TestResult result;
			
			pointer<int> i_pointer;

			i_pointer.create();

			result.assertTrue("pointer shouldnt be null", !i_pointer.isNull());

			if(i_pointer.isNull()){
				result.catchError(100, "Fail test");
				return result;
			}

			int* i_value = i_pointer.get();

			result.assertTrue("pointer value shouldnt be null", i_value != nullptr);

			if(i_value == nullptr){
				result.catchError(101, "Fail test");
				return result;
			}

			*i_value = 5;

			result.assertEqual("pointer value should be 5", *i_value, 5);
			
			var i_holder = i_pointer;

			pointer<int> i_pointer_2 = i_holder;

			result.assertTrue("pointer 2 shouldnt be null", !i_pointer_2.isNull());

			if(i_pointer_2.isNull()){
				result.catchError(102, "Fail test");
				return result;
			}

			int* value_2 = i_pointer_2.get();

			result.assertTrue("pointer 2 value shouldnt be null", value_2 != nullptr);

			if(value_2 == nullptr){
				result.catchError(103, "Fail test");
				return result;
			}

			result.assertEqual("pointer 2 value should be 5", *value_2, 5);

			return result;
		}

		void TR_Pointer_Testing(TestRunner& a_test_runner){
			createEngineManager();

			a_test_runner.map.add("Pointer Simple Constructor", TR_Pointer_Testing_1);
			a_test_runner.map.add("Pointer create", TR_Pointer_Testing_2);
			a_test_runner.map.add("Pointer copy Constructor", TR_Pointer_Testing_3);
			a_test_runner.map.add("Pointer Memory Holder Constructor", TR_Pointer_Testing_4);
		}		

	}

#endif
