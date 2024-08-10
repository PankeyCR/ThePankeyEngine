
#ifndef RenderManager_hpp
	#define RenderManager_hpp

	#include "cppObject.hpp"
	#include "ColorRGBA.hpp"
	#include "Class.hpp"

	namespace higgs{
		
		template<class BC, class O, class H, class A>
		class RenderManager : public O {
			public:
				using CLASS_TYPE = BC*;
				RenderManager(){}
				virtual ~RenderManager(){}
				
				virtual CLASS_TYPE getClass(){return Class<BC>::getClass<BC,RenderManager>();}

				virtual bool instanceof(CLASS_TYPE cls){
					return cls == Class<BC>::getClass<BC,RenderManager>();
				}
				
				virtual void initialize(Application<BC,O,H,A>& app){}
				
				virtual void update(float tpc){}
				
				virtual void proyectViewPorts(){}
				
				virtual void combineViewPorts(){}
				
				virtual void printPixel(int x, int y, const ColorRGBA& a_color){}
				
			protected:
		};

	}

#endif