#ifndef NetVList_cpp
#define NetVList_cpp

#include "NetVList.h"

	template<>
	NetVList<5>::NetVList(){
		for(int x=0; x < 5; x++){
			value[x] = 1;
		}
	}
		
	template<>
	NetVList<5>::~NetVList(){
		
	}
	
	template<>
	void NetVList<5>::setPos(int p){
		this->pos = p;
	}
	
	template<>
	int NetVList<5>::getPos(){
		return this->pos;
	}
	
	template<>
	int NetVList<5>::getSize(){
		return 5;
	}
	
	template<>
	void NetVList<5>::add(List<float> *list){
		iterate(list){
			this->value[this->pos] = list->getValue();
			this->pos++;
		}
	}
	
	template<>
	void NetVList<5>::add(float *value){
		this->value[this->pos] = *value;
		this->pos++;
	}
	
	template<>
	void NetVList<5>::add(float value){
		this->value[this->pos] = value;
		this->pos++;
	}
	
	template<>
	void NetVList<5>::set(int key, float *value){
		this->value[key] = *value;
	}
	
	template<>
	void NetVList<5>::set(int key, float value){
		this->value[key] = value;
	}
	
	template<>
	float *NetVList<5>::get(float *key){
		for(int x=0; x < this->pos; x++){
			if(*key == this->value[x]){
				return &this->value[x];
			}
		}
		return NULL;
	}
	
	template<>
	float *NetVList<5>::get(float key){
		for(int x=0; x < this->pos; x++){
			if(key == this->value[x]){
				return &this->value[x];
			}
		}
		return NULL;
	}
	
	template<>
	float *NetVList<5>::getByPos(int key){
		if(key < 5){
			return &value[key];
		}
		return NULL;
	}
	
	template<>
	bool NetVList<5>::contain(float *key){
		for(int x=0; x < this->pos; x++){
			if(*key == this->value[x]){
				return true;
			}
		}
		return false;
	}
	
	template<>
	bool NetVList<5>::contain(float key){
		for(int x=0; x < this->pos; x++){
			if(key == this->value[x]){
				return true;
			}
		}
		return false;
	}
	
	template<>
	void NetVList<5>::reset(){
		for(int x=0; x < 5; x++){
			value[x] = 1;
		}
	}
	
	template<>
	void NetVList<5>::resetDelete(){
		for(int x=0; x < 5; x++){
			value[x] = 1;
		}
	}
	
	template<>
	float *NetVList<5>::remove(float *key){
		for(int x=0; x < this->pos; x++){
			if(*key == this->value[x]){
				this->value[x] = 1;
				return &this->value[x];
			}
		}
		return NULL;
	}
	
	template<>
	float *NetVList<5>::remove(float key){
		for(int x=0; x < this->pos; x++){
			if(key == this->value[x]){
				this->value[x] = 1;
				return &this->value[x];
			}
		}
		return NULL;
	}
	
	template<>
	float *NetVList<5>::removeByPos(int p){
		if(p < 5){
			value[p] = 1;
			return &value[p];
		}
		return NULL;
	}
	
	template<>
	void NetVList<5>::removeDelete(float *key){
		for(int x=0; x < this->pos; x++){
			if(*key == this->value[x]){
				this->value[x] = 1;
			}
		}
		return NULL;
	}
	
	template<>
	void NetVList<5>::removeDelete(float key){
		for(int x=0; x < this->pos; x++){
			if(key == this->value[x]){
				this->value[x] = 1;
			}
		}
		return NULL;
	}
	
	template<>
	void NetVList<5>::removeDeleteByPos(int p){
		if(p < 5){
			value[p] = 1;
		}
		return NULL;
	}
	
	template<>
	float NetVList<5>::getValue(){
		return *this->getByPos(this->getIteration());
	}
	
	template<>
	float *NetVList<5>::getPointer(){
		return this->getByPos(this->getIteration());
	}
		
	template<>
	int NetVList<5>::getIterationSize(){
		return 5;
	}
	
	template<>
	String NetVList<5>::getClassName(){
		return "NetVList";
	}
	
	template<>
	String NetVList<5>::toString(){
		return "NetVList";
	}
	
	template<>
	NetVList<5> *NetVList<5>::clone(){
		return new NetVList<5>();
	}
	
	//////////////////////////////////////////////////////////////////

	
#endif