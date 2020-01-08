#ifndef NetList_cpp
#define NetList_cpp

#include "NetList.h"

	NetList::NetList(){
		value = new float*[size];
		for(int x=0; x < size; x++){
			value[x] = new float();
			*value[x] = 1;
		}
	}
	
	NetList::NetList(int netsize){
		value = new float*[netsize];
		for(int x=0; x < netsize; x++){
			value[x] = new float();
			*value[x] = 1;
		}
		size = netsize;
	}
	
	NetList::~NetList(){
		for(int x=0; x < size; x++){
			value[x] = new float();
		}
		delete value;	
	}
	
	void NetList::setPos(int p){
		this->pos = p;
	}
	
	int NetList::getPos(){
		return this->pos;
	}
	
	int NetList::getSize(){
		return this->size;
	}
	
	void NetList::add(List<float> *list){
		iterate(list){
			//*this->value[list->getIteration()] = list->getValue();
			this->add(list->getValue());
		}
	}
	
	void NetList::add(float *value){
		if(this->pos >= this->size){
			return;			
		}
		*this->value[this->pos] = *value;
		this->pos++;
	}
	
	void NetList::add(float value){
		if(this->pos >= this->size){
			return;			
		}
		*this->value[this->pos] = value;
		this->pos++;
	}
	
	void NetList::set(int position,float *value){
		if(position >= this->size){
			return;			
		}
		*this->value[position] = *value;
	}
	
	void NetList::set(int position,float value){
		if(position >= this->size){
			return;			
		}
		*this->value[position] = value;
	}
	
	bool NetList::contain(float *key){
		iterate(this){
			if(*key == this->getValue()){
				return true;
			}
		}
		return false;
	}
	
	bool NetList::contain(float key){
		iterate(this){
			if(key == this->getValue()){
				return true;
			}
		}
		return false;
	}
	
	float *NetList::get(float *key){
		iterate(this){
			if(*key == this->getValue()){
				return this->getPointer();
			}
		}
		return NULL;
	}
	
	float *NetList::get(float key){
		iterate(this){
			if(key == this->getValue()){
				return this->getPointer();
			}
		}
		return NULL;
	}
	
	float *NetList::getByPos(int key){
		if(key < this->size){
			return this->value[key];
		}
		return NULL;
	}
	
	void NetList::reset(){
		for(int x=0; x < this->size; x++){
			*this->value[x] = 1;
		}
	}
	
	void NetList::resetDelete(){
		for(int x=0; x < this->size; x++){
			*this->value[x] = 1;
		}
	}
	
	float *NetList::remove(float *key){
		iterate(this){
			if(*key == this->getValue()){
				*this->value[this->getIteration()] = 1;
				return this->value[this->getIteration()];
			}
		}
		return NULL;
	}
	
	float *NetList::remove(float key){
		iterate(this){
			if(key == this->getValue()){
				*this->value[this->getIteration()] = 1;
				return this->value[this->getIteration()];
			}
		}
		return NULL;
	}
	
	float *NetList::removeByPos(int p){
		if(p < size){
			*value[p] = 1;
			return value[p];
		}
		return NULL;
	}
	
	void NetList::removeDelete(float *key){
		iterate(this){
			if(*key == this->getValue()){
				*this->value[this->getIteration()] = 1;
			}
		}
	}
	
	void NetList::removeDelete(float key){
		iterate(this){
			if(key == this->getValue()){
				*this->value[this->getIteration()] = 1;
			}
		}
	}
	
	void NetList::removeDeleteByPos(int p){
		if(p < size){
			*value[p] = 1;
		}
	}
	
	float NetList::getValue(){
		return *this->getByPos(this->getIteration());
	}
	
	float *NetList::getPointer(){
		return this->getByPos(this->getIteration());
	}
	
	int NetList::getKey(){
		return getIteration();
	}
	
	int *NetList::getKeyPointer(){
		return NULL;
	}
	
	void NetList::onDelete(){
		for(int x=0; x < size; x++){
			delete value[x];
		}
		delete *value;
		delete this;
	}
		
	int NetList::getIterationSize(){
		return this->size;
	}
	
	String NetList::getClassName(){
		return "NetList";
	}
	
	String NetList::toString(){
		return "NetList";
	}
	
	NetList *NetList::clone(){
		return new NetList(size);
	}

	
#endif