
#ifndef TimerState_hpp
#define TimerState_hpp

#include "AppState.hpp"

using namespace ame;

class TimerState : public AppState, public TimeElapsed{
	public:
		TimerState(){}
	
		TimerState(Stream *port){
			serial = port;
		}
   
		void initialize(Application *app){
			app->getTimeControl()->add(this);
		}
    
		void update(float tpc){
			if(!m_update){
				return;
			}
			serial->println("TimerState");
			serial->println(m_time);
			m_update = false;
		}
   
		void Play(TimeControl *t){
			m_time = t->getTime();
			m_update = true;
		}
   
		bool instanceof(cppObjectClass* cls){
			return cls == Class<TimerState>::classType || AppState::instanceof(cls);
		}
	   
		cppObjectClass* getClass(){
			return Class<TimerState>::classType;
		}
		
	private:
		Stream *serial = nullptr;
		float m_time = 0;
		volatile bool m_update = true;
};

#endif 