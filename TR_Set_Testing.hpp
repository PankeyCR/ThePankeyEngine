
#ifndef TR_Set_Testing_hpp
#define TR_Set_Testing_hpp

#include "TestResult.hpp"

#include "Set.hpp"
#include "MemoryRam.hpp"

namespace ame{
	
	TestResult TR_Set_Testing(){
		TestResult result;
		
		Set one;
		Set two;
		Set three;
		Set four;
		Set five;
		
		if(!one.similar(two)){
			result.catchError(0, Note("At thid point, one and two are similar because there is nothing inside, yet"));
		}
		
		// one.addPointer(&five);
		// one.addPointer(&two);
		
		// two.addPointer(&one);
		// two.addPointer(&three);
		
		// three.addPointer(&two);
		// three.addPointer(&four);
		
		// four.addPointer(&three);
		// four.addPointer(&five);
		
		// five.addPointer(&four);
		// five.addPointer(&one);
		
		
		return result;
	}
}

#endif
