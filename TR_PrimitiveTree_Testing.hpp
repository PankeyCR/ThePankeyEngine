
#ifndef TR_PrimitiveTree_Testing_hpp
	#define TR_PrimitiveTree_Testing_hpp
	
	#include "pankey_Enviroment.hpp"
	#include "pankey_Enviroment_config.hpp"

	#include "TestResult.hpp"
	#include "TestRunner.hpp"

	#include "PrimitiveTree.hpp"

	namespace pankey{
		
		TestResult TR_PrimitiveTree_Testing_1(){
			TestResult result;

			PrimitiveTree<int> i_tree;

			result.assertTrue("list has to be empty", i_tree.isEmpty());
			
			return result;
		}

		void TR_PrimitiveTree_Testing(TestRunner& a_test_runner){
			a_test_runner.map.add("Constructor", TR_PrimitiveTree_Testing_1);
		}		

	}

#endif
