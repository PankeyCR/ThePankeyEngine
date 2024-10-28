
#ifndef TR_Variable_Testing_hpp
	#define TR_Variable_Testing_hpp
	
	#include "pankey.hpp"

	#include "TestResult.hpp"
	#include "TestRunner.hpp"

	#include "Variable.hpp"

	#include "CharArray.hpp"

	namespace pankey{

		TestResult TR_Variable_Testing_1(){
			TestResult result;

			var i_var;

			result.assertNotNull("allocator shouldnt be null", i_var.getManager());
			result.assertTrue("holder has to be null", i_var.isHolderNull());
			result.assertTrue("pointer has to be null", i_var.isNull());
			return result;
		}
		
		TestResult TR_Variable_Testing_2(){
			TestResult result;

			var i_var;
			
			if(i_var.getManager() == nullptr){
				result.catchError(100, "Fail test");
			}

			i_var.create<int>();

			result.assertNotNull("allocator shouldnt be null", i_var.getManager());
			result.assertTrue("holder shouldnt be null", !i_var.isHolderNull());
			result.assertTrue("pointer shouldnt be null", !i_var.isNull());
			return result;
		}
		
		TestResult TR_Variable_Testing_3(){
			TestResult result;

			var i_var = 15;

			result.assertNotNull("allocator shouldnt be null", i_var.getManager());
			result.assertTrue("holder shouldnt be null", !i_var.isHolderNull());
			result.assertTrue("pointer shouldnt be null", !i_var.isNull());
			result.assertEqual("value should be 15", i_var.getValue<int>(), 15);

			return result;
		}
		
		TestResult TR_Variable_Testing_4(){
			TestResult result;

			var i_var = 15;
			var i_var_2 = i_var;

			result.assertNotNull("allocator shouldnt be null", i_var_2.getManager());
			result.assertTrue("holder shouldnt be null", !i_var.isHolderNull());
			result.assertTrue("pointer shouldnt be null", !i_var_2.isNull());
			result.assertEqual("value should be 15", i_var_2.getValue<int>(), 15);

			return result;
		}
		
		TestResult TR_Variable_Testing_5(){
			TestResult result;

			pointer<int> i_var;
			i_var.create();
			int* i = (int*)i_var.getRawPointer();
			*i = 15;
			var i_var_2 = i_var;

			result.assertNotNull("allocator shouldnt be null", i_var_2.getManager());
			result.assertTrue("holder shouldnt be null", !i_var.isHolderNull());
			result.assertTrue("pointer shouldnt be null", !i_var_2.isNull());
			result.assertEqual("value should be 15", i_var_2.getValue<int>(), 15);

			return result;
		}
		
		TestResult TR_Variable_Testing_6(){
			TestResult result;

			val<int> i_var = 15;
			var i_var_2 = i_var;

			result.assertNotNull("allocator shouldnt be null", i_var_2.getManager());
			result.assertTrue("holder shouldnt be null", !i_var.isHolderNull());
			result.assertTrue("pointer shouldnt be null", !i_var_2.isNull());
			result.assertEqual("value should be 15", i_var_2.getValue<int>(), 15);

			return result;
		}
		
		TestResult TR_Variable_Testing_7(){
			TestResult result;

			var i_var = 15;
			data i_data = i_var;
			var i_var_2 = i_data;

			result.assertNotNull("allocator shouldnt be null", i_var_2.getManager());
			result.assertTrue("holder shouldnt be null", !i_var.isHolderNull());
			result.assertTrue("pointer shouldnt be null", !i_var_2.isNull());
			result.assertEqual("value should be 15", i_var_2.getValue<int>(), 15);

			return result;
		}
		
		TestResult TR_Variable_Testing_8(){
			TestResult result;

			var i_var = CharArray("var note");

			result.assertNotNull("allocator shouldnt be null", i_var.getManager());
			result.assertTrue("holder shouldnt be null", !i_var.isHolderNull());
			result.assertTrue("pointer shouldnt be null", !i_var.isNull());
			result.assertEqual("value should be the same", i_var.getValue<CharArray>(), CharArray("var note"));

			return result;
		}
		
		TestResult TR_Variable_Testing_9(){
			TestResult result;

			var i_var;
			i_var.create<CharArray>();
			i_var.create<CharArray>();

			result.assertNotNull("allocator shouldnt be null", i_var.getManager());
			result.assertTrue("holder shouldnt be null", !i_var.isHolderNull());
			result.assertTrue("pointer shouldnt be null", !i_var.isNull());

			return result;
		}

		void TR_Variable_Testing(TestRunner& a_test_runner){
			createEngineManager();

			a_test_runner.map.add("var Constructor", TR_Variable_Testing_1);
			a_test_runner.map.add("var create", TR_Variable_Testing_2);
			a_test_runner.map.add("var value constructor", TR_Variable_Testing_3);
			a_test_runner.map.add("var copy constructor", TR_Variable_Testing_4);
			a_test_runner.map.add("pointer to var", TR_Variable_Testing_5);
			a_test_runner.map.add("val to var", TR_Variable_Testing_6);
			a_test_runner.map.add("memoryholder to var", TR_Variable_Testing_7);
			a_test_runner.map.add("var as a CharArray", TR_Variable_Testing_8);
			a_test_runner.map.add("var with 2 create and posible memory leak", TR_Variable_Testing_9);
		}		

	}

#endif
