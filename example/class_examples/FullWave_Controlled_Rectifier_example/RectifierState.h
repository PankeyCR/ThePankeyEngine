

#ifndef RectifierState_h
#define RectifierState_h

#include "Arduino.h"
#include "AppState.h"
#include "TimeRecorder.h"
#include "Rectifier.h"

class RectifierState : public AppState, TimeElapsed{
 public:
    typedef void (RectifierState::*Disparo)();
  
    RectifierState(){
    }
    ~RectifierState(){
    }
    
    RectifierState* setAngle(int a){
      angle = a;
      return this;
    }
    
    RectifierState* setOutputPin1(int pin){
      out1 = pin;
      return this;
    }
    
    RectifierState* setOutputPin2(int pin){
      out2 = pin;
      return this;
    }
    
    RectifierState* setOutputPin3(int pin){
      out3 = pin;
      return this;
    }
    
    RectifierState* setRectifier(Rectifier r){
      rectifier = r;
      return this;
    }
   
    void Disparo_1(){
      disparo1 = angle * dt_da;
    }
   
    void Disparo_2(){
      disparo1 = (30 + angle) * dt_da;
      disparo2 = (150 + angle) * dt_da;
      disparo3 = (270 + angle) * dt_da;
    }
   
    void Disparo_PinMode_1(){
      pinMode(out1, OUTPUT);
    }
   
    void Disparo_PinMode_2(){
      pinMode(out1, OUTPUT);
      pinMode(out2, OUTPUT);
      pinMode(out3, OUTPUT);
    }
   
    void Disparo_Timer_1(){
      if(tiempoOnda >= disparo1 ){
        digitalWrite(out1,HIGH);
      }else{
        digitalWrite(out1,LOW);
      }
    }
   
    void Disparo_Timer_2(){
      if(tiempoOnda >= disparo1 ){
        digitalWrite(out1,HIGH);
      }else{
        digitalWrite(out1,LOW);
      }
      if(tiempoOnda >= disparo2 ){
        digitalWrite(out2,HIGH);
      }else{
        digitalWrite(out2,LOW);
      }
      if(tiempoOnda >= disparo3 ){
        digitalWrite(out3,HIGH);
      }else{
        digitalWrite(out3,LOW);
      }
    }
   
    String getClassName(){
      return "RectifierState";
    }
   
    void initialize(Application *app){
      m_app = app;
      
      if(this->rectifier == Rectifier::Single_Phase){
        d_start = &RectifierState::Disparo_1;
        d_pinmode = &RectifierState::Disparo_PinMode_1;
        d_timer = &RectifierState::Disparo_Timer_1;
      }
      if(this->rectifier == Rectifier::Three_Phase){
        d_start = &RectifierState::Disparo_2;
        d_pinmode = &RectifierState::Disparo_PinMode_2;
        d_timer = &RectifierState::Disparo_Timer_2;
      }
      (this->*d_pinmode)();
    }
    
    void onEnable(){
      m_app->getTimeControl()->add(this);
    }
    
    void onDisable(){
      m_app->getTimeControl()->remove(this);
    }
    
    void start(){
      x1 = x0;
      x0 = m_app->getTimeControl()->getTime();
      tiempoOnda = 0;
      dt_da = (x0 - x1)/360;
      (this->*d_start)();
    }
    
    void Play(TimeControl *t){
      (this->*d_timer)();
      tiempoOnda++;
    }
    
  private:
    Application* m_app;
    int dt_da = 1;
    long tiempoOnda = 0;
    long x0 = 0;
    long x1 = 0;
    int angle = 0;
    int disparo1 = 0;
    int disparo2 = 120;
    int disparo3 = 240;
    int out1 = 8;
    int out2 = 9;
    int out3 = 10;
    Disparo d_start = &RectifierState::Disparo_1;
    Disparo d_pinmode = &RectifierState::Disparo_PinMode_1;
    Disparo d_timer = &RectifierState::Disparo_Timer_1;
    Rectifier rectifier = Rectifier::Single_Phase;
};

#endif 
