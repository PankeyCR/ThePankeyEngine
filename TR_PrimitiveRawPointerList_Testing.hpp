
#ifndef TR_PrimitiveRawPointerList_Testing_hpp
#define TR_PrimitiveRawPointerList_Testing_hpp

#include "TestResult.hpp"

#include "PrimitiveRawPointerList.hpp"
#include "MemoryRam.hpp"

namespace ame{
	
	TestResult TR_PrimitiveRawPointerList_Testing(){
		TestResult result;
		
		PrimitiveRawPointerList<int> list;
		
		if(list.isEmpty()){
			result.catchError(0, "");
		}
		
		return result;
	}
}

#endif
