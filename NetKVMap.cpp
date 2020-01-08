#ifndef NetKVMap_cpp
#define NetKVMap_cpp

#include "NetKVMap.h"

	template<>
	NetKVMap<5>::NetKVMap(){
		for(int x=0; x < 5; x++){
			value[x] = 1;
		}
	}
		
	template<>
	NetKVMap<5>::~NetKVMap(){
		
	}
	
	template<>
	void NetKVMap<5>::setPos(int p){
	}
	
	template<>
	int NetKVMap<5>::getPos(){
		return 5;
	}
	
	template<>
	int NetKVMap<5>::getSize(){
		return 5;
	}
	
	template<>
	void NetKVMap<5>::add(int *key, float *value){
		this->value[*key] = *value;
	}
	
	template<>
	void NetKVMap<5>::add(int key, float value){
		this->value[key] = value;
	}
	
	template<>
	void NetKVMap<5>::add(int key, float *value){
		this->value[key] = *value;
	}
	
	template<>
	void NetKVMap<5>::set(int *key, float *value){
		this->value[*key] = *value;
	}
	
	template<>
	void NetKVMap<5>::set(int key, float value){
		this->value[key] = value;
	}
	
	template<>
	void NetKVMap<5>::set(int key, float *value){
		this->value[key] = *value;
	}
	
	template<>
	bool NetKVMap<5>::contain(int *key){
		if(*key < 5){
			return true;
		}
		return false;
	}
	
	template<>
	bool NetKVMap<5>::contain(int key){
		if(key < 5){
			return true;
		}
		return false;
	}
	
	template<>
	float *NetKVMap<5>::get(int *key){
		if(*key < 5){
			return &value[*key];
		}
		return NULL;
	}
	
	template<>
	float *NetKVMap<5>::get(int key){
		if(key < 5){
			return &value[key];
		}
		return NULL;
	}
	
	template<>
	float *NetKVMap<5>::getByPos(int key){
		if(key < 5){
			return &value[key];
		}
		return NULL;
	}
	
	template<>
	int *NetKVMap<5>::getKeyByPos(int key){
		// if(key < 10){
			// return key;
		// }
		return NULL;
	}
	
	template<>
	int *NetKVMap<5>::getKey(float *value){
		// for(int xgetKey = 0; xgetKey < size; xgetKey+){
			// if(*value[xgetKey] < *value){
				// return xgetKey;
			// }
		// }
		return NULL;
	}
	
	template<>
	int *NetKVMap<5>::getKey(float value){
		// for(int xgetKey = 0; xgetKey < size; xgetKey+){
			// if(*value[xgetKey] < value){
				// return xgetKey;
			// }
		// }
		return NULL;
	}
	
	template<>
	void NetKVMap<5>::reset(){
		for(int x=0; x < 5; x++){
			value[x] = 1;
		}
	}
	
	template<>
	void NetKVMap<5>::resetDelete(){
		for(int x=0; x < 5; x++){
			value[x] = 1;
		}
	}
	
	template<>
	float *NetKVMap<5>::remove(int *key){
		if(*key < 5){
			value[*key] = 1;
			return &value[*key];
		}
	}
	
	template<>
	float *NetKVMap<5>::remove(int key){
		if(key < 5){
			value[key] = 1;
			return &value[key];
		}
		return NULL;
	}
	
	template<>
	float *NetKVMap<5>::removeByPos(int p){
		if(p < 5){
			value[p] = 1;
			return &value[p];
		}
		return NULL;
	}
	
	template<>
	void NetKVMap<5>::removeDelete(int *key){
		if(*key < 5){
			value[*key] = 1;
		}
		return NULL;
	}
	
	template<>
	void NetKVMap<5>::removeDelete(int key){
		if(key < 5){
			value[key] = 1;
		}
		return NULL;
	}
	
	template<>
	void NetKVMap<5>::removeDeleteByPos(int p){
		if(p < 5){
			value[p] = 1;
		}
		return NULL;
	}
	
	template<>
	float NetKVMap<5>::getValue(){
		return *this->getByPos(this->getIteration());
	}
	
	template<>
	float *NetKVMap<5>::getPointer(){
		return this->getByPos(this->getIteration());
	}
	
	template<>
	int NetKVMap<5>::getKey(){
		return this->getIteration();
	}
	
	template<>
	int *NetKVMap<5>::getKeyPointer(){
		return NULL;
	}
		
	template<>
	int NetKVMap<5>::getIterationSize(){
		return 5;
	}
	
	template<>
	String NetKVMap<5>::getClassName(){
		return "NetKVMap";
	}
	
	template<>
	String NetKVMap<5>::toString(){
		return "NetKVMap";
	}
	
	template<>
	NetKVMap<5> *NetKVMap<5>::clone(){
		return new NetKVMap<5>();
	}
	
	////////////////////////////////////////////////////////

	template<>
	NetKVMap<10>::NetKVMap(){
		for(int x=0; x < 10; x++){
			value[x] = 1;
		}
	}
		
	template<>
	NetKVMap<10>::~NetKVMap(){
		
	}
	
	template<>
	void NetKVMap<10>::setPos(int p){
	}
	
	template<>
	int NetKVMap<10>::getPos(){
		return 10;
	}
	
	template<>
	int NetKVMap<10>::getSize(){
		return 10;
	}
	
	template<>
	void NetKVMap<10>::add(int *key, float *value){
		this->value[*key] = *value;
	}
	
	template<>
	void NetKVMap<10>::add(int key, float value){
		this->value[key] = value;
	}
	
	template<>
	void NetKVMap<10>::add(int key, float *value){
		this->value[key] = *value;
	}
	
	template<>
	void NetKVMap<10>::set(int *key, float *value){
		this->value[*key] = *value;
	}
	
	template<>
	void NetKVMap<10>::set(int key, float value){
		this->value[key] = value;
	}
	
	template<>
	void NetKVMap<10>::set(int key, float *value){
		this->value[key] = *value;
	}
	
	template<>
	bool NetKVMap<10>::contain(int *key){
		if(*key < 10){
			return true;
		}
		return false;
	}
	
	template<>
	bool NetKVMap<10>::contain(int key){
		if(key < 10){
			return true;
		}
		return false;
	}
	
	template<>
	float *NetKVMap<10>::get(int *key){
		if(*key < 10){
			return &value[*key];
		}
		return NULL;
	}
	
	template<>
	float *NetKVMap<10>::get(int key){
		if(key < 10){
			return &value[key];
		}
		return NULL;
	}
	
	template<>
	float *NetKVMap<10>::getByPos(int key){
		if(key < 10){
			return &value[key];
		}
		return NULL;
	}
	
	template<>
	int *NetKVMap<10>::getKeyByPos(int key){
		// if(key < 10){
			// return key;
		// }
		return NULL;
	}
	
	template<>
	int *NetKVMap<10>::getKey(float *value){
		// for(int xgetKey = 0; xgetKey < size; xgetKey+){
			// if(*value[xgetKey] < *value){
				// return xgetKey;
			// }
		// }
		return NULL;
	}
	
	template<>
	int *NetKVMap<10>::getKey(float value){
		// for(int xgetKey = 0; xgetKey < size; xgetKey+){
			// if(*value[xgetKey] < value){
				// return xgetKey;
			// }
		// }
		return NULL;
	}
	
	template<>
	void NetKVMap<10>::reset(){
		for(int x=0; x < 10; x++){
			value[x] = 1;
		}
	}
	
	template<>
	void NetKVMap<10>::resetDelete(){
		for(int x=0; x < 10; x++){
			value[x] = 1;
		}
	}
	
	template<>
	float *NetKVMap<10>::remove(int *key){
		if(*key < 10){
			value[*key] = 1;
			return &value[*key];
		}
	}
	
	template<>
	float *NetKVMap<10>::remove(int key){
		if(key < 10){
			value[key] = 1;
			return &value[key];
		}
		return NULL;
	}
	
	template<>
	float *NetKVMap<10>::removeByPos(int p){
		if(p < 10){
			value[p] = 1;
			return &value[p];
		}
		return NULL;
	}
	
	template<>
	void NetKVMap<10>::removeDelete(int *key){
		if(*key < 10){
			value[*key] = 1;
		}
		return NULL;
	}
	
	template<>
	void NetKVMap<10>::removeDelete(int key){
		if(key < 10){
			value[key] = 1;
		}
		return NULL;
	}
	
	template<>
	void NetKVMap<10>::removeDeleteByPos(int p){
		if(p < 10){
			value[p] = 1;
		}
		return NULL;
	}
	
	template<>
	float NetKVMap<10>::getValue(){
		return *this->getByPos(this->getIteration());
	}
	
	template<>
	float *NetKVMap<10>::getPointer(){
		return this->getByPos(this->getIteration());
	}
	
	template<>
	int NetKVMap<10>::getKey(){
		return this->getIteration();
	}
	
	template<>
	int *NetKVMap<10>::getKeyPointer(){
		return NULL;
	}
		
	template<>
	int NetKVMap<10>::getIterationSize(){
		return 10;
	}
	
	template<>
	String NetKVMap<10>::getClassName(){
		return "NetKVMap";
	}
	
	template<>
	String NetKVMap<10>::toString(){
		return "NetKVMap";
	}
	
	template<>
	NetKVMap<10> *NetKVMap<10>::clone(){
		return new NetKVMap<10>();
	}
	
	////////////////////////////////////////////////////////
	
	template<>
	NetKVMap<20>::NetKVMap(){
		for(int x=0; x < 10; x++){
			value[x] = 1;
		}
	}
		
	template<>
	NetKVMap<20>::~NetKVMap(){
		
	}
	
	template<>
	void NetKVMap<20>::setPos(int p){
	}
	
	template<>
	int NetKVMap<20>::getPos(){
		return 20;
	}
	
	template<>
	int NetKVMap<20>::getSize(){
		return 20;
	}
	
	template<>
	void NetKVMap<20>::add(int *key, float *value){
		this->value[*key] = *value;
	}
	
	template<>
	void NetKVMap<20>::add(int key, float value){
		this->value[key] = value;
	}
	
	template<>
	void NetKVMap<20>::add(int key, float *value){
		this->value[key] = *value;
	}
	
	template<>
	void NetKVMap<20>::set(int *key, float *value){
		this->value[*key] = *value;
	}
	
	template<>
	void NetKVMap<20>::set(int key, float value){
		this->value[key] = value;
	}
	
	template<>
	void NetKVMap<20>::set(int key, float *value){
		this->value[key] = *value;
	}
	
	template<>
	bool NetKVMap<20>::contain(int *key){
		if(*key < 20){
			return true;
		}
		return false;
	}
	
	template<>
	bool NetKVMap<20>::contain(int key){
		if(key < 20){
			return true;
		}
		return false;
	}
	
	template<>
	float *NetKVMap<20>::get(int *key){
		if(*key < 20){
			return &value[*key];
		}
		return NULL;
	}
	
	template<>
	float *NetKVMap<20>::get(int key){
		if(key < 20){
			return &value[key];
		}
		return NULL;
	}
	
	template<>
	float *NetKVMap<20>::getByPos(int key){
		if(key < 20){
			return &value[key];
		}
		return NULL;
	}
	
	template<>
	int *NetKVMap<20>::getKeyByPos(int key){
		// if(key < 10){
			// return key;
		// }
		return NULL;
	}
	
	template<>
	int *NetKVMap<20>::getKey(float *value){
		// for(int xgetKey = 0; xgetKey < size; xgetKey+){
			// if(*value[xgetKey] < *value){
				// return xgetKey;
			// }
		// }
		return NULL;
	}
	
	template<>
	int *NetKVMap<20>::getKey(float value){
		// for(int xgetKey = 0; xgetKey < size; xgetKey+){
			// if(*value[xgetKey] < value){
				// return xgetKey;
			// }
		// }
		return NULL;
	}
	
	template<>
	void NetKVMap<20>::reset(){
		for(int x=0; x < 20; x++){
			value[x] = 1;
		}
	}
	
	template<>
	void NetKVMap<20>::resetDelete(){
		for(int x=0; x < 20; x++){
			value[x] = 1;
		}
	}
	
	template<>
	float *NetKVMap<20>::remove(int *key){
		if(*key < 20){
			value[*key] = 1;
			return &value[*key];
		}
	}
	
	template<>
	float *NetKVMap<20>::remove(int key){
		if(key < 20){
			value[key] = 1;
			return &value[key];
		}
		return NULL;
	}
	
	template<>
	float *NetKVMap<20>::removeByPos(int p){
		if(p < 20){
			value[p] = 1;
			return &value[p];
		}
		return NULL;
	}
	
	template<>
	void NetKVMap<20>::removeDelete(int *key){
		if(*key < 20){
			value[*key] = 1;
		}
		return NULL;
	}
	
	template<>
	void NetKVMap<20>::removeDelete(int key){
		if(key < 20){
			value[key] = 1;
		}
		return NULL;
	}
	
	template<>
	void NetKVMap<20>::removeDeleteByPos(int p){
		if(p < 20){
			value[p] = 1;
		}
		return NULL;
	}
	
	template<>
	float NetKVMap<20>::getValue(){
		return *this->getByPos(this->getIteration());
	}
	
	template<>
	float *NetKVMap<20>::getPointer(){
		return this->getByPos(this->getIteration());
	}
	
	template<>
	int NetKVMap<20>::getKey(){
		return this->getIteration();
	}
	
	template<>
	int *NetKVMap<20>::getKeyPointer(){
		return NULL;
	}
		
	template<>
	int NetKVMap<20>::getIterationSize(){
		return 20;
	}
	
	template<>
	String NetKVMap<20>::getClassName(){
		return "NetKVMap";
	}
	
	template<>
	String NetKVMap<20>::toString(){
		return "NetKVMap";
	}
	
	template<>
	NetKVMap<20> *NetKVMap<20>::clone(){
		return new NetKVMap<20>();
	}

	
#endif