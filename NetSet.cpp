

#ifndef NetSet_cpp
#define NetSet_cpp

#include "NetSet.h"

	NetSet::NetSet(){
		
	}
		
	NetSet::~NetSet(){
		if(this->pointLimit != nullptr){
			delete this->pointLimit;
			this->pointLimit = nullptr;
		}
		if(this->vectorLimit != nullptr){
			delete this->vectorLimit;
			this->vectorLimit = nullptr;
		}
		if(this->vectorMap != nullptr){
			delete this->vectorMap;
			this->vectorMap = nullptr;
		}
	}
	
	DataSet<float>* NetSet::dimention(int dimentionPos){
		if(dimentionPos >= this->dimentionLimit){
			return this;
		}
		this->dimentionMap = dimentionPos;
		return this;
	}
	
	DataSet<float>* NetSet::vector(int vectorPos, int pointPos){
		if(this->vectorMap == nullptr){
			return this;
		}
		if(this->vectorMap->contain(vectorPos)){
			this->vectorMap->set(vectorPos , pointPos);
		}else{
			this->vectorMap->add(vectorPos , pointPos);
		}		
		return this;
	}
	
	DataSet<float>* NetSet::set(float t){
		
		return this;
	}
	
	DataSet<float>* NetSet::remove(){
		
		return this;
	}	
	
	float NetSet::getValue(){
		
	}
	
	float *NetSet::getPointer(){
		
	}
	
	int NetSet::dimentionSize(){
		return this->dimentionLimit;
	}
	
	int NetSet::vectorSize(int dimentionPos){
		if(this->vectorLimit == nullptr){
			return -1;
		}
		return *this->vectorLimit->getByPos(dimentionPos);
	}
	
	void NetSet::setIteration(int iter){
		this->iterateCount = iter;
		if(iter == 0){
			this->dimentionMap = 0;
		}
		if(iter == this->fullSize-1){
			this->dimentionMap = this->dimentionLimit-1;
		}
	}
	
	int NetSet::getIterationSize(){
		this->fullSize = this->dimentionLimit;
		return this->fullSize;
	}
	
	void NetSet::last(){
		this->iterateCount--;
		// if(this->pointLimit == nullptr || this->vectorLimit == nullptr){
			// return;
		// }
		// this->pointMap--;
		// if(this->pointMap < 0){
			// this->pointMap = *this->pointLimit->get(this->vectorMap) - 1;
			// this->vectorMap--;
			// if(this->vectorMap < 0){
				// this->vectorMap = *this->vectorLimit->get(this->dimentionMap) - 1;
				// this->dimentionMap--;
			// }
		// }
		// this->dimention(this->dimentionMap)->vector(this->vectorMap , this->pointMap);
	}
	
	void NetSet::next(){
		// this->iterateCount++;
		// if(this->pointLimit == nullptr || this->vectorLimit == nullptr){
			// return;
		// }
		// this->pointMap++;
		//this->vector(this->vectorMap , this->pointMap);
		// if(this->pointMap >= *this->pointLimit->get(this->vectorMap)){
			// this->pointMap = 0;
			//this->vector(this->vectorMap , this->pointMap);
			//this->dimention(this->dimentionMap)->vector(this->vectorMap , this->pointMap);
			// this->vectorMap++;
			//this->vector(this->vectorMap , this->pointMap);
			// if(this->vectorMap >= *this->vectorLimit->get(this->dimentionMap)){
				// this->vectorMap = 0;
				//this->vector(this->vectorMap , this->pointMap);
				//this->dimention(this->dimentionMap)->vector(this->vectorMap , this->pointMap);
				// this->dimentionMap++;
				// this->dimentionPosition = this->dimentionMap;
			// }
		// }
		// this->dimention(this->dimentionMap);
		// this->dimention(this->dimentionMap)->vector(this->vectorMap , this->pointMap);
	}
	
	int NetSet::dimention(){
		return this->dimentionMap;
	}
	
	int NetSet::vector(int dimentionPos){
		if(this->vectorMap == nullptr){
			return -1;
		}
		if(this->vectorMap->get(dimentionPos) == nullptr){
			return -1;
		}		
		return *this->vectorMap->get(dimentionPos);
	}
	
	String NetSet::getClassName(){
		return "NetSet";
	}
	
	String NetSet::toString(){
		return "NetSet";
	}

	DataSet<float>* NetSet::clone(){
		return this;
	}
		
		
		

#endif 
