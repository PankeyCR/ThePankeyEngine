
#ifndef DefaultRenderManager_h
#define DefaultRenderManager_h

#include "cppObject.h"
#include "Transform.h"
#include "PrimitiveList.h"

class DefaultRenderManager : public RenderManager {	
    public:
		DefaultRenderManager(){}
		virtual ~DefaultRenderManager(){}
		
		virtual bool instanceof(String name){return name == "DefaultRenderManager" || RenderManager::instanceof(name);}
		virtual String getClassName(){return "DefaultRenderManager";}
		virtual String toString(){return "DefaultRenderManager";}
		
		virtual void initialize(Application *app){
			
		}
	protected:
};
#endif 
