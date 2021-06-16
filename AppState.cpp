
#ifndef AppState_cpp
#define AppState_cpp

#include "AppState.h"

	void AppState::initialize(Application *app){
		
	}
	
	void AppState::onEnable(){
		
	}
	
	void AppState::onDisable(){
		
	}
	
	String AppState::getId(){
		if(this->id == nullptr){
			return "";
		}
		return *this->id;
	}
	
	void AppState::update(float tpc){
		
	}
	
	bool AppState::instanceof(cppObjectClass* cls){
		return cls == Class<AppState>::classType || cppObject::instanceof(cls);
	}
	
	void AppState::operator=(AppState b) {
		this->id = b.id;
	}
	
	bool AppState::operator==(AppState b) {
			return this->getClass() == b.getClass();
	}
	
	bool AppState::operator!=(AppState b) {
			return this->getClass() != b.getClass();
	}
	
#endif 