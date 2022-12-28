
#ifndef ActionComponent_hpp
#define ActionComponent_hpp
#define ActionComponent_AVAILABLE

#include "GameOn.hpp"

namespace ame{

class ActionComponent : public GameOn{
    public:
		virtual ~ActionComponent(){}
	
		virtual cppObjectClass* getClassName(){
			return Class<ActionComponent>::getClass();
		}
		
		virtual bool instanceof(cppObjectClass* cls){
			return cls == Class<ActionComponent>::getClass() || GameOn::instanceof(cls);
		}
	
		virtual void Action(){}
};

}

#endif