

#ifndef GameOn_cpp
#define GameOn_cpp

#include "GameOn.h"

	GameOn::GameOn(){
		
	}
	
	GameOn::~GameOn(){
		
	}
	
	void GameOn::setParent(GameObject *parent){
		this->parent = parent;
	}
	
	GameObject *GameOn::getParent(){
		return this->parent;
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
		
	//Note GameOn::getNote(){
		
	//}
	
	void GameOn::update(float tpf){
		
	}
	
	// GameOn GameOn::operator =(const Note& note){
		
	// }
	
	// GameOn GameOn::operator =(const GameOn& note){
		
	// }
	
	// bool GameOn::operator ==((const GameOn& note){
		// return false;
	// }
	
	// bool GameOn::operator !=((const GameOn& note){
		// return false;
	// }
	

#endif 
