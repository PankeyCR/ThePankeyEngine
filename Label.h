
#ifndef Label_h
#define Label_h

#include "cppObject.h"
#include "Panel.h"

namespace ame{

class Label : public Panel{	
    public:
		Label(){
		}
		Label(const String& s){
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
		virtual String toString(){return "Label";}
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
