
#include "ame_Level.hpp"

#if defined(ame_untilLevel_1)

#ifndef AppState_hpp
#define AppState_hpp

#include "Arduino.h"
#include "cppObject.hpp"

namespace ame{

class Application;

class AppState : public cppObject{
    public:
		virtual ~AppState(){}
		virtual void initialize(Application *app){}
		virtual void onEnable(){}
		virtual void onDisable(){}
		virtual void setId(String i){
			id = i;
		}
		virtual String getId(){
			return id;
		}
		virtual void update(float tpc){}
		virtual bool instanceof(cppObjectClass* cls){
			return cls == ame::Class<AppState>::classType || ame::cppObject::instanceof(cls);
		}
		virtual void operator=(AppState b){}
		virtual bool operator==(AppState b){
				return this->getClass() == b.getClass();
		}
		virtual bool operator!=(AppState b){
				return this->getClass() != b.getClass();
		}
	protected:
		String id = "";
};

}

#endif 

#endif 
