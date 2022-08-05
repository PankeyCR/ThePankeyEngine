
#include "ame_Enviroment.hpp"

#if defined(DISABLE_GameState)
	#define GameState_hpp
#endif

#ifndef GameState_hpp
#define GameState_hpp
#define GameState_AVAILABLE

#ifndef ame_Enviroment_Defined

#endif

#ifdef ame_Windows

#endif

#ifdef ame_ArduinoIDE
	#include "Arduino.h"
#endif

namespace ame{

template<class T>
class GameState{
public:
T version;
T pre_version;

GameState(){
}
GameState(T t){
	version = t;
	pre_version = t;
}
virtual ~GameState(){}

bool update(){
	if(version != pre_version){
		pre_version = version ;
		return true;
	}
	return false;
}
bool update(T v){
	return version != v;
}
bool isState(T v){
	return version == v;
}
void setState(T v){
	version = v;
}

virtual void operator =(T v){
	version = v;
}
virtual bool operator ==(T v){
	return version == v;
}
virtual bool operator !=(T v){
	return version != v;
}
	protected:
};

}

#endif