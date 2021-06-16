

#ifndef cppObject_cpp
#define cppObject_cpp

#include "cppObject.h"

	cppObject::cppObject(){
		
	}
	cppObject::~cppObject(){
		
	}
	void cppObject::onDelete(){
		
	}
	cppObjectClass* cppObject::getClass(){
		return Class<cppObject>::classType;
	}
	String cppObject::toString(){
		return "cppObject";
	}
	bool cppObject::equal(cppObject *b){
		if(b == this){
			return true;
		}
		if(b->getClass() == this->getClass()){
			return true;
		}
		return false;
	}
	bool cppObject::instanceof(cppObjectClass* cls){
		return cls == this->getClass();
	}
	cppObject* cppObject::clone(void){
		return this->clone(true);
	}
	cppObject* cppObject::clone(bool owningMemory){
		return this;
	}

	void cppObject::operator=(cppObject b){
		
	}

	bool cppObject::operator==(cppObject b){
		return this->getClass() == b.getClass();
	}

	bool cppObject::operator!=(cppObject b){
		return this->getClass() != b.getClass();
	}


#endif 
