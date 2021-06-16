
#ifndef RenderManager_h
#define RenderManager_h

#include "cppObject.h"
#include "Transform.h"
#include "PrimitiveList.h"
#include "Application.h"

class RenderManager : public cppObject{	
    public:
		RenderManager(){}
		virtual ~RenderManager(){}
		
		virtual bool instanceof(String name){return name == "RenderManager" || name == "cppObject";}
		virtual String getClassName(){return "RenderManager";}
		virtual String toString(){return "RenderManager";}
		
		virtual void initialize(Application *app){}
		
	protected:
};
#endif 
