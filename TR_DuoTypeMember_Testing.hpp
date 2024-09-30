
#ifndef TR_DuoTypeMember_Testing_hpp
	#define TR_DuoTypeMember_Testing_hpp
	
	#include "pankey.hpp"

	#include "TestResult.hpp"
	#include "TestRunner.hpp"

	#include "DuoTypeMember.hpp"
	#include "Variable.hpp"

	namespace pankey{

		TestResult TR_DuoTypeMember_Testing_1(){
			TestResult result;

			duo_type<int,int> i_duo;

			result.assertNotNull("manager shouldnt be null", i_duo.getManager());

			result.assertTrue("holder has to be null", i_duo.isHolderNull());
			result.assertTrue("holder has to be null", i_duo.isDuoTypeHolderNull());

			result.assertTrue("pointer has to be null", i_duo.isMemoryNull());
			result.assertTrue("pointer has to be null", i_duo.isDuoTypeMemoryNull());

			result.assertTrue("pointers has to be null", i_duo.isNull());
			return result;
		}
		
		TestResult TR_DuoTypeMember_Testing_2(){
			TestResult i_result;

			var i_var_0 = 15;
			var i_var_1 = 20;

			duo_type<int,int> i_duo;

			i_duo.copyMember(i_var_0);
			i_duo.copyDuoTypeMember(i_var_1);

			i_result.assertTrue("holder shouldnt be null", !i_duo.isHolderNull());
			i_result.assertTrue("holder shouldnt be null", !i_duo.isDuoTypeHolderNull());

			i_result.assertTrue("holder shouldnt be null", !i_duo.isMemoryNull());
			i_result.assertTrue("holder shouldnt be null", !i_duo.isDuoTypeMemoryNull());

			i_result.assertTrue("pointer shouldnt be null", !i_duo.isNull());

			return i_result;
		}
		
		TestResult TR_DuoTypeMember_Testing_3(){
			TestResult i_result;

			var i_var_0 = 15.4f;
			var i_var_1 = 20.4f;

			duo_type<int,int> i_duo;

			i_duo.copyMember(i_var_0);
			i_duo.copyDuoTypeMember(i_var_1);

			i_result.assertTrue("holder shouldnt be null", i_duo.isHolderNull());
			i_result.assertTrue("holder shouldnt be null", i_duo.isDuoTypeHolderNull());

			i_result.assertTrue("holder shouldnt be null", i_duo.isMemoryNull());
			i_result.assertTrue("holder shouldnt be null", i_duo.isDuoTypeMemoryNull());

			i_result.assertTrue("pointer shouldnt be null", i_duo.isNull());
			return i_result;
		}
		
		TestResult TR_DuoTypeMember_Testing_4(){
			TestResult result;

			var i_var_0 = 15;
			var i_var_1 = 20;

			duo_type<int,int> i_duo;

			i_duo.copyMember(i_var_0);
			i_duo.copyDuoTypeMember(i_var_1);

			var i_var_00 = i_duo.getMember();
			var i_var_11 = i_duo.getDuoTypeMember();

			result.assertNoteEqual("value should be: 15", i_var_00.getValue<int>(), 15);
			result.assertNoteEqual("value should be: 20", i_var_11.getValue<int>(), 20);

			return result;
		}
		
		TestResult TR_DuoTypeMember_Testing_5(){
			TestResult i_result;

			var i_var_0 = 15;
			var i_var_1 = 20;

			duo_type<int,int> i_duo = duo_type<int,int>(i_var_0, i_var_1);

			var i_var_00 = i_duo.getMember();
			var i_var_11 = i_duo.getDuoTypeMember();

			i_result.assertNoteEqual("value should be: 15", i_var_00.getValue<int>(), 15);
			i_result.assertNoteEqual("value should be: 20", i_var_11.getValue<int>(), 20);

			return i_result;
		}
		
		void TR_DuoTypeMember_Testing(TestRunner& a_test_runner){
			createEngineManager();

			a_test_runner.map.add("duo_type Constructor", TR_DuoTypeMember_Testing_1);
			a_test_runner.map.add("duo_type copyMember, copyDuoMember", TR_DuoTypeMember_Testing_2);
			a_test_runner.map.add("duo_type copyMember, copyDuoMember, for non type", TR_DuoTypeMember_Testing_3);
			a_test_runner.map.add("duo_type getMember, getDuoMember", TR_DuoTypeMember_Testing_4);
			a_test_runner.map.add("duo_type Constructor with both Members", TR_DuoTypeMember_Testing_5);
		}		

	}

#endif
