
#ifndef TR_Set_Testing_hpp
	#define TR_Set_Testing_hpp
	
	#include "pankey.hpp"

	#include "TestResult.hpp"
	#include "TestRunner.hpp"

	#include "Set.hpp"

	namespace pankey{
		
		TestResult TR_Set_Testing_1(){
			TestResult i_result;

			Set i_set;

			i_result.assertTrue("Set should be empty", i_set.isEmpty());

			return i_result;
		}
		
		TestResult TR_Set_Testing_2(){
			TestResult i_result;

			set i_set;

			set i_member;

			i_set->add(i_member);

			i_result.assertTrue("Set should contain member set", i_set->belongs(i_member));

			return i_result;
		}

		void TR_Set_Testing(TestRunner& a_test_runner){
			createEngineManager();

			a_test_runner.map.add("Set Constructor", TR_Set_Testing_1);
			a_test_runner.map.add("Set add belongs", TR_Set_Testing_2);
		}
	}

#endif
