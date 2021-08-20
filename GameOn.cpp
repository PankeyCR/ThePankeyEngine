

#ifndef GameOn_cpp
#define GameOn_cpp

#include "GameOn.h"

	ame::GameOn::GameOn(){
		
	}
	
	ame::GameOn::~GameOn(){
		parent = nullptr;
	}
	
	void ame::GameOn::setParent(ame::GameOn *parent){
		this->parent = parent;
	}
	
	ame::GameOn *ame::GameOn::getParent(){
		return this->parent;
	}
	
	void ame::GameOn::setId(int id){
		if(this->parent != nullptr){
			this->parent->setId(id);
		}
	}
	
	int ame::GameOn::getId(){
		if(this->parent != nullptr){
			return this->parent->getId();
		}
		return -1;
	}
		
	bool ame::GameOn::isEnable(){
		return this->enabler;
	}
		
	void ame::GameOn::enable(){
		this->enabler = true;
	}
	
	void ame::GameOn::disable(){
		this->enabler = false;
	}
	
	void ame::GameOn::update(float tpc){
		
	}
	
	ame::cppObjectClass* ame::GameOn::getClass(){
		return ame::Class<ame::GameOn>::classType;
	}
	
	String ame::GameOn::toString(){
		return "GameOn";
	}
	
	bool ame::GameOn::instanceof(ame::cppObjectClass* cls){
		return cls == ame::Class<ame::GameOn>::classType || ame::cppObject::instanceof(cls);
	}
	
	ame::GameOn ame::GameOn::operator =(const ame::GameOn& note){
		
	}
	
	bool ame::GameOn::operator ==(const ame::GameOn& note){
		return false;
	}
	
	bool ame::GameOn::operator !=(const ame::GameOn& note){
		return false;
	}
	

#endif 
