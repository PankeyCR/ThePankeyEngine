
#include "ame_Level.hpp"

#if defined(ame_untilLevel_7)

#ifndef GameState_hpp
#define GameState_hpp

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

#endif 
