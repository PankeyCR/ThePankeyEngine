
#ifndef LoopState_hpp
#define LoopState_hpp

#include "AppState.hpp"

using namespace ame;

class LoopState : public AppState{
	public:
		Application *App;
		LoopState(Stream *port){
			serial = port;
		}
		void initialize(Application *app){
			App = app;
		}
		void update(float tpc){
		  serial->println(tpc);
		}
   
    bool instanceof(cppObjectClass* cls){
      return cls == Class<LoopState>::classType || AppState::instanceof(cls);
    }
   
    cppObjectClass* getClass(){
		  return Class<LoopState>::classType;
		}
		
	private:
		Stream *serial = nullptr;
};

#endif 