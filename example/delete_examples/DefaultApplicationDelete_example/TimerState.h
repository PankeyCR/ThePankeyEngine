
#ifndef TimerState_h
#define TimerState_h

#include "AppState.h"

class TimerState : public AppState, TimeElapsed{
public:

TimerState(Stream *port){
	serial = port;
}
~TimerState(){}

void initialize(Application *app){
}

void Play(TimeControl *t){
	serial->println(t->getTime());
}

private:
Stream *serial=NULL;
};

#endif 
