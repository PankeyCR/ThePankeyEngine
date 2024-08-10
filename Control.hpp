
#include "higgs_Enviroment.hpp"

#if defined(DISABLE_Control)
	#define Control_hpp
#endif

#ifndef Control_hpp
#define Control_hpp
#define Control_AVAILABLE

#ifndef higgs_Enviroment_Defined

#endif

#ifdef higgs_Windows

#endif

#ifdef higgs_ArduinoIDE
	#include "Arduino.h"
#endif

#include "cppObject.hpp"

//class RenderManager;

namespace higgs{

class Control : public cppObject{	
    public:
		Control(){
		}
		virtual ~Control(){
		}
		virtual void operator=(const Control& b){}
		virtual bool operator==(Control b){return this->getClass()==b.getClass();}
		virtual bool operator!=(Control b){return this->getClass()!=b.getClass();}
		
		virtual bool instanceof(cppObjectClass* cls){
			return cls == Class<Control>::classType || cppObject::instanceof(cls);
		}
		virtual cppObjectClass* getClass(){return Class<Control>::classType;}
		virtual Note toNote(){return "Control";}
		virtual bool equal(cppObject *b){
			if(b == this){
				return true;
			}
			return false;
		}
		
		virtual Control* clone(){return nullptr;}
		
		virtual void update(float tpc){
			
		}
		// #if defined(RenderManager_AVAILABLE)
		// virtual void RenderUpdate(RenderManager* manager){
			
		// }
		// #endif
	protected:
};

}

#endif