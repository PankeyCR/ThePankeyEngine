
#ifndef AppState_cpp
#define AppState_cpp

#include "AppState.h"

	void ame::AppState::initialize(ame::Application *app){
		
	}
	
	void ame::AppState::onEnable(){
		
	}
	
	void ame::AppState::onDisable(){
		
	}
	
	String ame::AppState::getId(){
		if(this->id == nullptr){
			return "";
		}
		return *this->id;
	}
	
	void ame::AppState::update(float tpc){
		
	}
	
	bool ame::AppState::instanceof(ame::cppObjectClass* cls){
		return cls == ame::Class<AppState>::classType || ame::cppObject::instanceof(cls);
	}
	
	void ame::AppState::operator=(AppState b) {
		this->id = b.id;
	}
	
	bool ame::AppState::operator==(ame::AppState b) {
			return this->getClass() == b.getClass();
	}
	
	bool ame::AppState::operator!=(ame::AppState b) {
			return this->getClass() != b.getClass();
	}
	
#endif 