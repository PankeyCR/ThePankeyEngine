
#include "ame_Enviroment.hpp"

#if defined(DISABLE_Panel)
	#define Panel_hpp
#endif

#ifndef Panel_hpp
#define Panel_hpp
#define Panel_AVAILABLE

#ifndef ame_Enviroment_Defined

#endif

#ifdef ame_Windows

#endif

#ifdef ame_ArduinoIDE
	#include "Arduino.h"
#endif

#include "cppObject.hpp"
#include "Node.hpp"

namespace ame{

class Panel : public Node{	
    public:
		Panel(){
		}
		virtual ~Panel(){
		}
		virtual void operator=(const Panel& b){}
		virtual bool operator==(Panel b){return this->getClassName()==b.getClassName();}
		virtual bool operator!=(Panel b){return this->getClassName()!=b.getClassName();}
		
		virtual bool instanceof(cppObjectClass* cls){
			return cls == Class<Panel>::classType || Node::instanceof(cls);
		}
		virtual cppObjectClass* getClass(){return Class<Panel>::classType;}
		virtual Note toNote(){return "Panel";}
		
		virtual Panel* clone(){return nullptr;}
		
		virtual void RenderUpdate(RenderManager* manager){
			for(int x = 0; x < controls.getPosition(); x++){
				Control* control = controls.getByPosition(x);
				control->RenderUpdate(manager);
			}
			
		}
	protected:
};

}

#endif