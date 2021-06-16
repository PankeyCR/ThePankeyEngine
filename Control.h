
#ifndef Control_h
#define Control_h

#include "cppObject.h"
#include "RenderManager.h"

class Control : public cppObject{	
    public:
		Control(){
		}
		virtual ~Control(){
		}
		virtual void operator=(const Control& b){}
		virtual bool operator==(Control b){return this->getClassName()==b.getClassName();}
		virtual bool operator!=(Control b){return this->getClassName()!=b.getClassName();}
		
		virtual bool instanceof(String name){return name == "Control" || name == "cppObject";}
		virtual String getClassName(){return "Control";}
		virtual String toString(){return "Control";}
		virtual bool equal(cppObject *b){
			if(b == this){
				return true;
			}
			return false;
		}
		
		virtual Control* clone(){return nullptr;}
		
		virtual void update(float tpc){
			
		}
		virtual void RenderUpdate(RenderManager* manager){
			
		}
	protected:
};
#endif 
