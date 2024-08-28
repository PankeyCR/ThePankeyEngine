
#ifndef Control_hpp
	#define Control_hpp

	#include "cppObject.hpp"

	//class RenderManager;

	namespace pankey{

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
			protected:
		};

	}

#endif