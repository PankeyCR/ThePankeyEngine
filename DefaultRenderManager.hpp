
#include "ame_Level.hpp"

#if defined(ame_untilLevel_7)

#ifndef DefaultRenderManager_hpp
#define DefaultRenderManager_hpp

#include "cppObject.hpp"
#include "Transform.hpp"
#include "PrimitiveList.hpp"

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

#endif 
