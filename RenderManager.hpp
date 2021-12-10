
#ifndef RenderManager_hpp
#define RenderManager_hpp

#include "cppObject.hpp"
#include "Transform.hpp"
#include "PrimitiveList.hpp"
#include "Application.hpp"

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
