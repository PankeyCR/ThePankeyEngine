
#ifndef TR_RawPointerList_Testing_hpp
	#define TR_RawPointerList_Testing_hpp

	#include "TestResult.hpp"
	#include "TestRunner.hpp"

	#include "PrimitiveList.hpp"

	namespace higgs{
		
		TestResult TR_PrimitiveList_Testing_1(){
			TestResult i_result;

			PrimitiveList<int> i_list;

			i_result.assertTrue("list should be empty", i_list.isEmpty());

			return i_result;
		}

		void TR_PrimitiveList_Testing(TestRunner& a_test_runner){
			a_test_runner.map.add("Simple Constructor", TR_PrimitiveList_Testing_1);
		}

	}

#endif
