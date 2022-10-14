
#ifndef RenderManager_hpp
#define RenderManager_hpp
#define RenderManager_AVAILABLE

#include "cppObject.hpp"
#include "ColorRGBA.hpp"
#include "Class.hpp"

namespace ame{

class RenderManager : public cppObject{	
    public:
		RenderManager(){}
		virtual ~RenderManager(){}
		
		virtual bool instanceof(cppObjectClass* cls){
			return cls == Class<RenderManager>::classType || cppObject::instanceof(cls);
		}
		virtual cppObjectClass* getClass(){return Class<RenderManager>::classType;}
		
		virtual void initialize(Application *app){}
		
		virtual void update(float tpc){}
		
		virtual void proyectViewPorts(){}
		
		virtual void combineViewPorts(){}
		
		virtual void printPixel(int x, int y, const ColorRGBA& a_color){}
		
	protected:
};

}

#endif