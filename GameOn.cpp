

#ifndef GameOn_cpp
#define GameOn_cpp

#include "GameOn.h"

	GameOn::GameOn(){
		
	}
	
	GameOn::~GameOn(){
		parent = nullptr;
	}
	
	void GameOn::setParent(GameOn *parent){
		this->parent = parent;
	}
	
	GameOn *GameOn::getParent(){
		return this->parent;
	}
	
	void GameOn::setId(int id){
		if(this->parent != nullptr){
			this->parent->setId(id);
		}
	}
	
	int GameOn::getId(){
		if(this->parent != nullptr){
			return this->parent->getId();
		}
		return -1;
	}
		
	bool GameOn::isEnable(){
		return this->enabler;
	}
		
	void GameOn::enable(){
		this->enabler = true;
	}
	
	void GameOn::disable(){
		this->enabler = false;
	}
	
	void GameOn::update(float tpc){
		
	}
	
	cppObjectClass* GameOn::getClass(){
		return Class<GameOn>::classType;
	}
	
	String GameOn::toString(){
		return "GameOn";
	}
	
	bool GameOn::instanceof(cppObjectClass* cls){
		return cls == Class<GameOn>::classType || cppObject::instanceof(cls);
	}
	
	GameOn GameOn::operator =(const GameOn& note){
		
	}
	
	bool GameOn::operator ==(const GameOn& note){
		return false;
	}
	
	bool GameOn::operator !=(const GameOn& note){
		return false;
	}
	

#endif 
