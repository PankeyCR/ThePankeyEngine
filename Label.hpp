
#include "ame_Enviroment.hpp"

#if defined(DISABLE_Label)
	#define Label_hpp
#endif

#ifndef Label_h
#define Label_h
#define Label_AVAILABLE

#ifndef ame_Enviroment_Defined

#endif

#ifdef ame_Windows

#endif

#ifdef ame_ArduinoIDE
	#include "Arduino.h"
#endif

#include "cppObject.hpp"
#include "Panel.hpp"

namespace ame{

class Label : public Panel{	
    public:
		Label(){
		}
		Label(const Note& s){
		}
		virtual ~Label(){
		}
		virtual void operator=(const Label& b){}
		virtual bool operator==(Label b){return this->getClass()==b.getClass();}
		virtual bool operator!=(Label b){return this->getClass()!=b.getClass();}
		
		virtual bool instanceof(cppObjectClass* cls){
			return cls == Class<Label>::classType || Panel::instanceof(cls);
		}
		virtual cppObjectClass* getClass(){return Class<Label>::classType;}
		virtual Note toNote(){return "Label";}
		virtual bool equal(cppObject *b){
			if(b == this){
				return true;
			}
			return false;
		}
		
		virtual Label* clone(){return nullptr;}
		
	protected:
};

}

#endif