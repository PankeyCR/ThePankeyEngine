

#ifndef cppObject_cpp
#define cppObject_cpp

#include "cppObject.h"

	cppObject::cppObject(){
		
	}
	cppObject::~cppObject(){
		
	}
	void cppObject::onDelete(){
		
	}
	String cppObject::getClassName(){
		return "cppObject";
	}
	String cppObject::toString(){
		return "cppObject";
	}
	bool cppObject::equal(cppObject *b){
		if(b == this){
			return true;
		}
		if(b->getClassName() == this->getClassName()){
			return true;
		}
		return false;
	}
	bool cppObject::instanceof(String s){
		if(s == this->getClassName()){
			return true;
		}
		return s == "cppObject";
	}
	cppObject *cppObject::clone(void){
		return this->clone(true);
	}
	cppObject *cppObject::clone(bool owningMemory){
		return this;
	}

	void cppObject::operator=(cppObject b){
		
	}

	bool cppObject::operator==(cppObject b){
		return this->getClassName() == b.getClassName();
	}

	bool cppObject::operator!=(cppObject b){
		return this->getClassName() != b.getClassName();
	}


#endif 
