
#ifndef Label_h
#define Label_h

#include "cppObject.h"
#include "Panel.h"

class Label : public Panel{	
    public:
		Label(){
		}
		Label(const String& s){
		}
		virtual ~Label(){
		}
		virtual void operator=(const Label& b){}
		virtual bool operator==(Label b){return this->getClassName()==b.getClassName();}
		virtual bool operator!=(Label b){return this->getClassName()!=b.getClassName();}
		
		virtual bool instanceof(String name){return name == "Label" || Panel::instanceof(name);}
		virtual String getClassName(){return "Label";}
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
#endif 
