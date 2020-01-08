
#ifndef ScreenText_h
#define ScreenText_h

#include "Vector2f.h"
#include "Vector3f.h"
#include "GameObject.h"
#include "TouchScreen_2_4tft.h"

class ScreenText : public GameObject{
    private:
	
    public:
		
		Vector3f position;
		float size;
		int color;
		
		ScreenText();
        virtual void setParent(GameObject *obj);
        virtual TouchScreen_2_4tft getTouchScreen();
		virtual void setLocalTranslation(Vector3f Position);
		virtual Vector3f getLocalTranslation();
		virtual void setSize(float Size);
		virtual float getSize();
		virtual void setColor(Vector2f Size);
		virtual Vector2f getColor();
        virtual void onDelete();
		virtual String getClassName();
		virtual String toString();
};
#endif 
