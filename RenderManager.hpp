
#ifndef CONFIGURATION_RenderManager_hpp
#define CONFIGURATION_RenderManager_hpp

	#include "ame_Enviroment.hpp"

	#if defined(DISABLE_RenderManager)
		#define RenderManager_hpp

		#define IMPLEMENTATION_RenderManager
		#define IMPLEMENTING_RenderManager
	#else
		#if defined(DISABLE_IMPLEMENTATION_RenderManager)
			#define IMPLEMENTATION_RenderManager
			#define IMPLEMENTING_RenderManager
		#endif
	#endif

#endif

#ifndef RenderManager_hpp
#define RenderManager_hpp
#define RenderManager_AVAILABLE

#ifndef DISABLE_IMPLEMENTATION_RenderManager
	#define IMPLEMENTATION_RenderManager IMPLEMENTATION(public RenderManager)
	#define IMPLEMENTING_RenderManager IMPLEMENTING(public RenderManager)
#endif

#include "cppObject.hpp"
#include "ColorRGBA.hpp"
#include "Class.hpp"

namespace ame{

/*
*	Class Configuration:
*	DISABLE_Application
*	DISABLE_cppObject
*	DISABLE_cppObjectClass
*	DISABLE_AbstractClass
*	DISABLE_IMPLEMENTATION_cppObject
*/
class RenderManager IMPLEMENTATION_cppObject {
    public:
		RenderManager(){}
		virtual ~RenderManager(){}
		
		#if defined(cppObject_AVAILABLE) && defined(cppObjectClass_AVAILABLE) && defined(Class_AVAILABLE)
		virtual cppObjectClass* getClass(){return Class<RenderManager>::getClass();}

		virtual bool instanceof(cppObjectClass* cls){
			return cls == Class<RenderManager>::getClass() || cppObject::instanceof(cls);
		}
		#endif
		
		#if defined(Application_AVAILABLE)
		virtual void initialize(Application *app){}
		#endif
		
		virtual void update(float tpc){}
		
		virtual void proyectViewPorts(){}
		
		virtual void combineViewPorts(){}
		
		virtual void printPixel(int x, int y, const ColorRGBA& a_color){}
		
	protected:
};

}

#endif