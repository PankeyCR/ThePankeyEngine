
#ifndef ScriptState_cpp
#define ScriptState_cpp

#include "ScriptState.h"

	
	ScriptState::ScriptState(){
	}
	
	ScriptState::~ScriptState(){
		if(this->scripts != nullptr){
			delete this->scripts;
			this->scripts = nullptr;
		}
		if(this->loopScripts != nullptr){
			delete this->loopScripts;
			this->loopScripts = nullptr;
		}
	}
	
	String ScriptState::getClassName(){
		return "ScriptState";
	}
	
	String ScriptState::toString(){
		return "ScriptState";
	}
	
	void ScriptState::initialize(Application *app){
	}
	
	void ScriptState::update(){
	}
	
	void ScriptState::addScript(Script* script){
		
	}
	void ScriptState::addLoopScript(Script* script){
		
	}
	
	void ScriptState::runScript(const String& c){
		
	}
	void ScriptState::runScript(const char* c){
		
	}
	
#endif 