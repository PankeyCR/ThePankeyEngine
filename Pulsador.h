
#ifndef Pulsador_h
#define Pulsador_h

#include "Arduino.h"

namespace ame{

class Pulsador {
    private:
		int pinPulsador=0;
		bool pressed=false;
		bool released=false;
		bool clicked=false;
	
    public:
		Pulsador(int pin);
		~Pulsador();
		void update();
		bool isPressed();
		bool isReleased();
		bool isClick();
};

}

#endif 
