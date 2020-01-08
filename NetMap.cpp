#ifndef NetMap_cpp
#define NetMap_cpp

#include "NetMap.h"

	NetMap::NetMap(){
		value = new float*[size];
		for(int x=0; x < size; x++){
			value[x] = new float();
			*value[x] = 1;
		}
	}
	
	NetMap::NetMap(int netsize){
		value = new float*[netsize];
		for(int x=0; x < netsize; x++){
			value[x] = new float();
			*value[x] = 1;
		}
		size = netsize;
	}
	
	NetMap::~NetMap(){
		for(int x=0; x < size; x++){
			value[x] = new float();
		}
		delete value;	
	}
	
	void NetMap::setPos(int p){
		
	}
	
	int NetMap::getPos(){
		return size;
	}
	
	int NetMap::getSize(){
		return size;
	}
	
	void NetMap::add(int *key, float *value){
		*this->value[*key] = *value;
	}
	
	void NetMap::add(int key, float value){
		*this->value[key] = value;
	}
	
	void NetMap::add(int key, float *value){
		*this->value[key] = *value;
	}
	
	void NetMap::set(int *key, float *value){
		*this->value[*key] = *value;
	}
	
	void NetMap::set(int key, float value){
		*this->value[key] = value;
	}
	
	void NetMap::set(int key, float *value){
		*this->value[key] = *value;
	}
	
	bool NetMap::contain(int *key){
		if(*key < size){
			return true;
		}
		return false;
	}
	
	bool NetMap::contain(int key){
		if(key < size){
			return true;
		}
		return false;
	}
	
	float *NetMap::get(int *key){
		if(*key < size){
			return value[*key];
		}
		return NULL;
	}
	
	float *NetMap::get(int key){
		if(key < size){
			return value[key];
		}
		return NULL;
	}
	
	float *NetMap::getByPos(int key){
		if(key < size){
			return value[key];
		}
		return NULL;
	}
	
	int *NetMap::getKeyByPos(int key){
		// if(key < size){
			// return key;
		// }
		return NULL;
	}
	
	int *NetMap::getKey(float *value){
		// for(int xgetKey = 0; xgetKey < size; xgetKey+){
			// if(*value[xgetKey] < *value){
				// return xgetKey;
			// }
		// }
		return NULL;
	}
	
	int *NetMap::getKey(float value){
		// for(int xgetKey = 0; xgetKey < size; xgetKey+){
			// if(*value[xgetKey] < value){
				// return xgetKey;
			// }
		// }
		return NULL;
	}
	
	void NetMap::reset(){
		for(int x=0; x < size; x++){
			*value[x] = 1;
		}
	}
	
	void NetMap::resetDelete(){
		for(int x=0; x < size; x++){
			*value[x] = 1;
		}
	}
	
	float *NetMap::remove(int *key){
		if(*key < size){
			*value[*key] = 1;
			return value[*key];
		}
	}
	
	float *NetMap::remove(int key){
		if(key < size){
			*value[key] = 1;
			return value[key];
		}
		return NULL;
	}
	
	float *NetMap::removeByPos(int p){
		if(p < size){
			*value[p] = 1;
			return value[p];
		}
		return NULL;
	}
	
	void NetMap::removeDelete(int *key){
		if(*key < size){
			*value[*key] = 1;
		}
	}
	
	void NetMap::removeDelete(int key){
		if(key < size){
			*value[key] = 1;
		}
	}
	
	void NetMap::removeDeleteByPos(int p){
		if(p < size){
			*value[p] = 1;
		}
	}
	
	float NetMap::getValue(){
		return *this->getByPos(this->getIteration());
	}
	
	float *NetMap::getPointer(){
		return this->getByPos(this->getIteration());
	}
	
	int NetMap::getKey(){
		return getIteration();
	}
	
	int *NetMap::getKeyPointer(){
		return NULL;
	}
	
	void NetMap::onDelete(){
		for(int x=0; x < size; x++){
			delete value[x];
		}
		delete *value;
		delete this;
	}
		
	int NetMap::getIterationSize(){
		return this->size;
	}
	
	String NetMap::getClassName(){
		return "NetMap";
	}
	
	String NetMap::toString(){
		return "NetMap";
	}
	
	NetMap *NetMap::clone(){
		return new NetMap(size);
	}

	
#endif