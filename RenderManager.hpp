
#include "ame_Enviroment.hpp"

#if defined(DISABLE_RenderManager)
	#define RenderManager_hpp
#endif

#ifndef RenderManager_hpp
#define RenderManager_hpp
#define RenderManager_AVAILABLE

#ifndef ame_Enviroment_Defined

#endif

#ifdef ame_Windows

#endif

#ifdef ame_ArduinoIDE
	#include "Arduino.h"
#endif

#include "cppObject.hpp"
#include "Texture.hpp"
#include "ColorRGBA.hpp"
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
		virtual Note toNote(){return "RenderManager";}
		
		virtual void initialize(Application *app){}
		
		virtual void update(float tpc){
			for(int x = 0; x < m_max_x_size; x++){
				for(int y = 0; y < m_max_y_size; y++){
					printPixel(x, y, ColorRGBA::Black);
				}
			}
			for(int x = 0; x < m_max_x_size; x++){
				for(int y = 0; y < m_max_y_size; y++){
					printPixel(x, y, m_screenTexture.getPixelColor(x, y));
				}
			}
		}
		
		virtual void printPixel(int x, int y, const ColorRGBA& a_color){}
		
		virtual Texture& getTexture(){return m_screenTexture;}
		
		virtual void setTexture(Texture a_texture){}
		
	protected:
		Texture m_screenTexture;
		int m_max_x_size = 0;
		int m_max_y_size = 0;
};

}

#endif