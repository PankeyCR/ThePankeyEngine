
#ifndef TouchScreen_2_4tft_h
#define TouchScreen_2_4tft_h
/*
#include "GameObject.h"
#include "ScreenButton.h"
#include "Arduino.h"

#include <SPFD5408_Adafruit_GFX.h>    // Core graphics library
#include <SPFD5408_Adafruit_TFTLCD.h> // Hardware-specific library
#include <SPFD5408_TouchScreen.h>
#include <SD.h>

//Colores 
#define BLACK   0x0000
#define BLUE    0x001F
#define RED     0xF800
#define GREEN   0x07E0
#define CYAN    0x07FF
#define MAGENTA 0xF81F
#define YELLOW  0xFFE0
#define WHITE   0xFFFF

#define FUSE   0xF071
//------------------------------


class TouchScreen_2_4tft : public GameObject, public ScreenButton{
    private:
	
    public:
		Adafruit_TFTLCD *screen;
		TouchScreen *screenTouch;
		Vector2f cursor;
		uint16_t pressure;
		bool pressed=false;
		bool clicked=false;
		bool released=false;
		
		TouchScreen_2_4tft();
		~TouchScreen_2_4tft();
        virtual void update();
        virtual void onDelete();
		virtual String getClassName();
		SDClass getSD();
		bool isPressed();     
		bool isReleased();     
		bool isClick();      
		Vector2f getCursor();
		uint16_t getPressure();
};
*/
#endif 
