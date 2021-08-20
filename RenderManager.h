
#ifndef RenderManager_h
#define RenderManager_h

#include "cppObject.h"
#include "Transform.h"
#include "PrimitiveList.h"
#include "Application.h"

namespace ame{

class RenderManager : public cppObject{	
    public:
		RenderManager(){}
		virtual ~RenderManager(){}
		
		virtual bool instanceof(cppObjectClass* cls){
			return cls == Class<RenderManager>::classType || cppObject::instanceof(cls);
		}
		virtual cppObjectClass* getClass(){return Class<RenderManager>::classType;}
		virtual String toString(){return "RenderManager";}
		
		virtual void initialize(Application *app){}
		
	protected:
};

}

#endif 
