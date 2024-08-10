
#ifndef SetState_hpp
#define SetState_hpp

#include "Note.hpp"
#include "AppState.hpp"
#include "Class.hpp"

namespace higgs{

class SetState : public AppState{
    public:
		SetState(){}
		virtual ~SetState(){}
		
		virtual bool instanceof(cppObjectClass* cls){
			return cls == Class<SetState>::classType || cls == Class<AppState>::classType;
		}
		
		virtual void initialize(Application *app){}
		virtual void onEnable(){}
		virtual void onDisable(){}
		
		virtual void update(float tpc){}
	protected:
	
};

}

#endif
