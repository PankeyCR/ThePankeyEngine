
#ifndef Panel_h
#define Panel_h

#include "cppObject.h"
#include "Node.h"

class Panel : public Node{	
    public:
		Panel(){
		}
		virtual ~Panel(){
		}
		virtual void operator=(const Panel& b){}
		virtual bool operator==(Panel b){return this->getClassName()==b.getClassName();}
		virtual bool operator!=(Panel b){return this->getClassName()!=b.getClassName();}
		
		virtual bool instanceof(String name){return name == "Panel" || Node::instanceof(name);}
		virtual String getClassName(){return "Panel";}
		virtual String toString(){return "Panel";}
		
		virtual Panel* clone(){return nullptr;}
		
		virtual void RenderUpdate(RenderManager* manager){
			for(int x = 0; x < controls.getPosition(); x++){
				Control* control = controls.getByPosition(x);
				control->RenderUpdate(manager);
			}
			
		}
	protected:
};
#endif 
