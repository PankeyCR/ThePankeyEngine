
#ifndef DefaultRenderManager_hpp
#define DefaultRenderManager_hpp
#define DefaultRenderManager_AVAILABLE

#include "ViewPort.hpp"
#include "Texture.hpp"
#include "ColorRGBA.hpp"
#include "Transform.hpp"
#include "PrimitiveList.hpp"
#include "PrimitiveMap.hpp"

namespace ame{

class DefaultRenderManager : public cppObject{	
    public:
		DefaultRenderManager(){}
		virtual ~DefaultRenderManager(){}
		
		virtual bool instanceof(cppObjectClass* cls){
			return cls == Class<DefaultRenderManager>::classType || cppObject::instanceof(cls);
		}
		virtual cppObjectClass* getClass(){return Class<DefaultRenderManager>::classType;}
		virtual Note toNote(){return "DefaultRenderManager";}
		
		virtual void initialize(Application *app){}
		
		virtual void update(float tpc){
			m_time += tpc;
			if(m_time < m_time_limit){
				return;
			}
			m_time = 0.0f;
			
			proyectViewPorts();
			
			combineViewPorts();
			
			// for(int x = 0; x < m_max_x_size; x++){
				// for(int y = 0; y < m_max_y_size; y++){
					// printPixel(x, y, ColorRGBA::Black);
				// }
			// }
			for(int x = 0; x < m_max_x_size; x++){
				for(int y = 0; y < m_max_y_size; y++){
					printPixel(x, y, m_screenTexture.getColor(x, y));
				}
			}
		}
		
		virtual void proyectViewPorts(){}
		
		virtual void combineViewPorts(){}
		
		virtual void printPixel(int x, int y, const ColorRGBA& a_color){}
		
		virtual Texture& getTexture(){return m_screenTexture;}
		
		virtual void setTexture(Texture a_texture){}
		
	protected:
		Texture m_screenTexture;
		int m_max_x_size = 0;
		int m_max_y_size = 0;
		
		PrimitiveMap<Note,ViewPort> m_viewports;
		float m_time = 0.0f;
		float m_time_limit = 0.01f;
};

}

#endif