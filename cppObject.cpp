

#ifndef cppObject_cpp
#define cppObject_cpp

#include "cppObject.h"

	ame::cppObject::cppObject(){
		
	}
	ame::cppObject::~cppObject(){
		
	}
	void ame::cppObject::onDelete(){
		
	}
	ame::cppObjectClass* ame::cppObject::getClass(){
		return ame::Class<cppObject>::classType;
	}
	String ame::cppObject::toString(){
		return "cppObject";
	}
	bool ame::cppObject::equal(ame::cppObject *b){
		if(b == this){
			return true;
		}
		if(b->getClass() == this->getClass()){
			return true;
		}
		return false;
	}
	bool ame::cppObject::instanceof(ame::cppObjectClass* cls){
		return cls == this->getClass() || cls == ame::Class<cppObject>::classType;
	}
	ame::cppObject* ame::cppObject::clone(void){
		return this->clone(true);
	}
	ame::cppObject* ame::cppObject::clone(bool owningMemory){
		return this;
	}

	void ame::cppObject::invoke(String methodName){
		
	}

	void ame::cppObject::operator=(ame::cppObject b){
		
	}

	bool ame::cppObject::operator==(ame::cppObject b){
		return this->getClass() == b.getClass();
	}

	bool ame::cppObject::operator!=(ame::cppObject b){
		return this->getClass() != b.getClass();
	}


#endif 
