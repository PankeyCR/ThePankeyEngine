
#ifndef TR_ByteArray_Testing_hpp
	#define TR_ByteArray_Testing_hpp

	#include "TestResult.hpp"

	#include "ByteArray.hpp"

	namespace higgs{
		
		TestResult TR_ByteArray_Testing_1(){
			TestResult result;
			
			ByteArray i_array;
			
			return result;
		}
			
		void TR_ByteArray_Testing(TestRunner& a_test_runner){
			a_test_runner.map.add("ByteArray", TR_ByteArray_Testing_1);
		}
	}

#endif
