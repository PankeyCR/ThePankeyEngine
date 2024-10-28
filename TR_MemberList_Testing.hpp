
#ifndef TR_MemberList_Testing_hpp
	#define TR_MemberList_Testing_hpp
	
	#include "pankey.hpp"

	#include "TestResult.hpp"
	#include "TestRunner.hpp"

	#include "Variable.hpp"
	#include "Value.hpp"
	#include "TypeList.hpp"

	namespace pankey{
		
		TestResult TR_MemberList_Testing_1(){
			TestResult result;

			List i_list;
			
			result.assertTrue("storage has to be null", i_list.isEmpty());
			return result;
		}
		
		TestResult TR_MemberList_Testing_2(){
			TestResult result;

			List i_list;
			
			result.assertTrue("storage has to be null", i_list.isEmpty());

			var i_var_0 = 0;
			var i_var_1 = 1;
			var i_var_2 = 2;
			var i_var_3 = 3;
			var i_var_4 = 4;
			var i_var_5 = 5;
			var i_var_6 = 6;
			var i_var_7 = 7;
			var i_var_8 = 8;
			var i_var_9 = 9;

			i_list.add(i_var_0);
			i_list.add(i_var_1);
			i_list.add(i_var_2);
			i_list.add(i_var_3);
			i_list.add(i_var_4);
			i_list.add(i_var_5);
			i_list.add(i_var_6);
			i_list.add(i_var_7);
			i_list.add(i_var_8);
			i_list.add(i_var_9);
			
			result.assertNoteEqual("value should be the same", i_var_0.getValue<int>(), 0);
			result.assertNoteEqual("value should be the same", i_var_1.getValue<int>(), 1);

			for(int x = 0; x < i_list.length(); x++){
				var i_var = i_list.get(x);
				result.assertNoteEqual("storage value should be the same as the index", i_var.getValue<int>(), x);
			}
			return result;
		}

		void TR_MemberList_Testing(TestRunner& a_test_runner){
			createEngineManager();

			a_test_runner.map.add("List Constructor", TR_MemberList_Testing_1);
			a_test_runner.map.add("List adding variables", TR_MemberList_Testing_2);
			a_test_runner.map.add("List adding values", TR_MemberList_Testing_2);
		}	

	}

#endif
