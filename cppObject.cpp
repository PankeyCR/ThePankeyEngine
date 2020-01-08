

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
	cppObject *cppObject::clone(){
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
