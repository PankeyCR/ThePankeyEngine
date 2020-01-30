

#ifndef GameOn_cpp
#define GameOn_cpp

#include "GameOn.h"

	GameOn::GameOn(){
		
	}
	
	GameOn::~GameOn(){
		
	}
	
	void GameOn::setParent(GameOn *parent){
		this->parent = parent;
	}
	
	GameOn *GameOn::getParent(){
		return this->parent;
	}
	
	void GameOn::setId(String id){
		this->idm = id;
	}
	
	String GameOn::getId(){
		return this->idm;
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
	
	void GameOn::update(float tpf){
		
	}
	
	String GameOn::getClassName(){
		return "GameOn";
	}
	
	String GameOn::toString(){
		return "GameOn";
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
