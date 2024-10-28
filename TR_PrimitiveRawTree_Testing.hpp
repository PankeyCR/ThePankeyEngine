
#ifndef TR_PrimitiveRawTree_Testing_hpp
	#define TR_PrimitiveRawTree_Testing_hpp
	
	#include "pankey.hpp"

	#include "TestResult.hpp"
	#include "TestRunner.hpp"

	#include "PrimitiveRawTree.hpp"

	namespace pankey{
		
		TestResult TR_PrimitiveRawTree_Testing_1(){
			TestResult result;

			PrimitiveRawTree<int> i_tree;

			result.assertTrue("list has to be empty", i_tree.isEmpty());
			
			return result;
		}

		void TR_PrimitiveRawTree_Testing(TestRunner& a_test_runner){
			a_test_runner.map.add("Constructor", TR_PrimitiveRawTree_Testing_1);
		}		

	}

#endif
