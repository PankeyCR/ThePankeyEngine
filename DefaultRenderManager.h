
#ifndef DefaultRenderManager_h
#define DefaultRenderManager_h

#include "cppObject.h"
#include "Transform.h"
#include "PrimitiveList.h"

namespace ame{

class DefaultRenderManager : public RenderManager {	
    public:
		DefaultRenderManager(){}
		virtual ~DefaultRenderManager(){}
		
		virtual bool instanceof(cppObjectClass* cls){
			return cls == Class<DefaultRenderManager>::classType || RenderManager::instanceof(cls);
		}
		virtual cppObjectClass* getClass(){return Class<DefaultRenderManager>::classType;}
		virtual String toString(){return "DefaultRenderManager";}
		
		virtual void initialize(Application *app){
			
		}
	protected:
};

}

#endif 
