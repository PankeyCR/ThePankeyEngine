
#include "ame_Enviroment.hpp"

#if defined(DISABLE_Ultrasonic)
	#define Ultrasonic_hpp
#endif

#ifndef Ultrasonic_hpp
#define Ultrasonic_hpp
#define Ultrasonic_AVAILABLE

#ifndef ame_Enviroment_Defined

#endif

#ifdef ame_Windows

#endif

#ifdef ame_ArduinoIDE
	#include "Arduino.h"
#endif

namespace ame{

class Ultrasonic {
    public:
		Ultrasonic(){}
		Ultrasonic(int t, int r){
			setTriggerPin(t);
			setReadPin(r);
		}
		Ultrasonic(int triggerP, int readP, float max, float min, float scaleV){
			setTriggerPin(triggerP);
			setReadPin(readP);
			m_maxLimit = max;
			m_minLimit = min;
			m_scale = scaleV;
		}
		virtual ~Ultrasonic(){}
		
		virtual void initialize(Application *app){}
		
		virtual void setTriggerPin(int p){
			pinMode(p, OUTPUT);
			t_pin = p;
		}
		virtual int triggerPin(){return t_pin;}
		
		virtual void setReadPin(int p){
			pinMode(p, INPUT);
			r_pin = p;
		}
		virtual int readPin(){return r_pin;}
		
		virtual void setScale(float p){
			m_scale = p;
		}
		virtual float scale(){return m_scale;}
		
		virtual bool isTriggering(){return m_triggering;}
		
		virtual void startTrigger(){
			m_triggering = true;
			digitalWrite(t_pin, HIGH);
		}
		virtual void stopTrigger(){
			m_triggering = false;
			digitalWrite(t_pin, LOW);
		}
		
		//distance
		virtual int rawRead(){
			return analogRead(r_pin);
		}
		
		//distance
		virtual float read(){
			m_read = analogRead(r_pin) * m_scale;
			// Serial.println(analogRead(r_pin));
			if(m_read > m_maxLimit || m_read < m_minLimit){
				return -1.0f;
			}
			return m_read;
		}
		
		virtual void setMaxLimit(float l){m_maxLimit = l;}
		virtual void setMinLimit(float l){m_minLimit = l;}
		
		virtual float getMaxLimit(){return m_maxLimit;}
		virtual float getMinLimit(){return m_minLimit;}
		
		virtual bool isEnable(){return m_enable;}
		virtual void enable(){m_enable = true;}
		virtual void disable(){m_enable = false;}
		
		virtual void operator=(Ultrasonic b){}
		virtual bool operator==(Ultrasonic b){return true;}
		virtual bool operator!=(Ultrasonic b){return true;}
		
    protected: 
		bool m_enable = false;
		float m_read = -1.0f;
		bool m_triggering = false;
		int r_pin = 0;
		int t_pin = 0;
		float m_maxLimit = 500.0f;
		float m_minLimit = 30.0f;
		float m_scale = 0.4761f;
};

}

#endif