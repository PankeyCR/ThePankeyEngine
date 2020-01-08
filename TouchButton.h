
#ifndef TouchButton_h
#define TouchButton_h

#include "Vector2f.h"
#include "Vector3f.h"
#include "ScreenButton.h"
#include "GameObject.h"
#include "TouchScreen_2_4tft.h"

class TouchButton : public ScreenButton , public GameObject{
    private:
	
    public:
		
		Vector3f position;
		Vector2f size;
		Vector2f cursor;
		uint16_t pressure;
		bool pressed=false;
		bool clicked=false;
		bool released=false;
		int color;
		
		TouchButton();
        virtual void setParent(GameObject *obj);
        virtual TouchScreen_2_4tft getTouchScreen();
		bool isPressed();     
		bool isReleased();     
		bool isClick();   
		virtual Vector2f getCursor();
		virtual uint16_t getPressure();
		virtual void setLocalTranslation(Vector3f Position);
		virtual Vector3f getLocalTranslation();
		virtual void setSize(Vector2f Size);
		virtual Vector2f getSize();
		virtual void setColor(Vector2f Size);
		virtual Vector2f getColor();
        virtual void onDelete();
		virtual String getClassName();
		virtual String toString();
		SDClass getSD();
        virtual void update();
};
#endif 

