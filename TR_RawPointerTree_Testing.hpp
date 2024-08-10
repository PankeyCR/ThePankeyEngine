
#ifndef TR_RawPointerTree_Testing_hpp
	#define TR_RawPointerTree_Testing_hpp
	
	#include "higgs_Enviroment.hpp"
	#include "higgs_Enviroment_config.hpp"

	#include "higgs_Memory_Manager_config.hpp"

	#include "TestResult.hpp"
	#include "TestRunnerState.hpp"

	#include "Pointer.hpp"
	#include "ExternReferenceCountAllocator.hpp"
	#include "ExternVoidReferenceCountAllocator.hpp"

	namespace higgs{

		TestResult TR_RawPointerTree_Testing_0(){
			TestResult result;
			
			// RPTree<int> tree;

			return result;
		}

		void TR_RawPointerTree_Testing(TestRunnerState& a_test_runner){
			createAllocator<higgs_CREATE_ENGINE_MANAGER_ALLOCATOR(void,ExternVoidReferenceCountAllocator<void>)>();

			a_test_runner.addUnitTest("RPTree", TR_RawPointerTree_Testing_0);
		}		

	}

#endif
