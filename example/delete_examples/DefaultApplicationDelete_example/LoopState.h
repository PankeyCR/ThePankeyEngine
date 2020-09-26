
#ifndef LoopState_h
#define LoopState_h

#include "AppState.h"

class LoopState : public AppState{
public:
Application *App;

LoopState(Stream *port){
	serial = port;
}

~LoopState(){}

void initialize(Application *app){
}

void update(float tpc){
	serial->println(getClassName());
}

String getClassName(){
	return "LoopState";
}

private:
Stream *serial=NULL;
};

#endif 
