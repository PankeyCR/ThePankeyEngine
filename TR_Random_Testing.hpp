
#ifndef TR_Random_Testing_hpp
#define TR_Random_Testing_hpp

#include "TestResult.hpp"

#include "AbsoluteRandom.hpp"
#include "RealRandom.hpp"
#include "NoRepiteRandom.hpp"
#include "MemoryRam.hpp"

namespace higgs{
	
	int tipesOfRandoms(){
		return 3;
	}
	
	Random* getRandom(int x){
		if(x == 0){
			return new RealRandom();
		}
		if(x == 1){
			return new AbsoluteRandom();
		}
		if(x == 2){
			return new NoRepiteRandom();
		}
		return nullptr;
	}
	
	Note getRandomName(int x){
		if(x == 0){
			return Note("RealRandom");
		}
		if(x == 1){
			return Note("AbsoluteRandom");
		}
		if(x == 2){
			return Note("NoRepiteRandom");
		}
		return "";
	}
	
	TestResult TR_Random_Testing(){
		TestResult result;
		
		for(int x = 0; x < tipesOfRandoms(); x++){
			Note a_name = getRandomName(x);
			Random* rnd = getRandom(x);
			rnd->setSeed(845);
			rnd->setMax(10);
			rnd->setMin(0);
			
			for(int x = 0; x < 100; x++){
				float rand = rnd->getRandom();
				if(rand < 0){
					result.catchError(1, a_name + Note(" Random is getting smaller than the max limmit"));
				}
				if(rand > 10){
					result.catchError(2, a_name + Note(" Random is getting bigger than the max limmit"));
				}
			}
			
			delete rnd;
		}
		
		return result;
	}
}

#endif
