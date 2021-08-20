
#ifndef ScriptState_cpp
#define ScriptState_cpp

#include "ScriptState.h"

	
	ame::ScriptState::ScriptState(){
	}
	
	ame::ScriptState::~ScriptState(){
		if(this->scripts != nullptr){
			delete this->scripts;
			this->scripts = nullptr;
		}
		if(this->loopScripts != nullptr){
			delete this->loopScripts;
			this->loopScripts = nullptr;
		}
	}
	
	ame::cppObjectClass* ame::ScriptState::getClass(){
		return ame::Class<ame::ScriptState>::classType;
	}
	
	String ame::ScriptState::toString(){
		return "ScriptState";
	}
	
	void ame::ScriptState::initialize(ame::Application *app){
	}
	
	void ame::ScriptState::update(){
	}
	
	void ame::ScriptState::addScript(ame::Script* script){
		
	}
	void ame::ScriptState::addLoopScript(ame::Script* script){
		
	}
	
	void ame::ScriptState::runScript(const String& c){
		
	}
	void ame::ScriptState::runScript(const char* c){
		
	}
	
#endif 