
#ifndef Pulsador_cpp
#define Pulsador_cpp

#include "Pulsador.h"

	ame::Pulsador::Pulsador(int pin){
		this->pinPulsador=pin;
		pinMode(pin,OUTPUT);
	}
	
	ame::Pulsador::~Pulsador(){
		
	}
	
	void ame::Pulsador::update(){
		int valor = digitalRead(this->pinPulsador);
		
        if(valor == 1){
          if(!this->clicked && !this->pressed){
            this->clicked = true;
          }
          if(this->clicked && this->pressed){
            this->clicked = false;
          }
          this->pressed=true;
          this->released=false;
        }
        if(valor ==0){
          if(!this->released && this->pressed){
            this->released = true;
          }
          if(this->released && !this->pressed){
            this->released = false;
          }
          this->clicked = false;
          this->pressed=false;
        }
	}
	
	bool ame::Pulsador::isPressed(){
		return this->pressed;	
	}
	
	bool ame::Pulsador::isReleased(){
		return this->released;	
	}
	
	bool ame::Pulsador::isClick(){
		return this->clicked;	
	}

#endif 
