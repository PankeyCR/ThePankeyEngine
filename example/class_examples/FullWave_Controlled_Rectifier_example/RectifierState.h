

#ifndef RectifierState_h
#define RectifierState_h

#include "Arduino.h"
#include "AppState.h"
#include "TimeRecorder.h"

class RectifierState : public AppState, TimeElapsed{
 public:
  
    RectifierState(Stream* port){
      serial = port;
    }
    
    void setAngle(int a){
      angle = a;
    }
    
    void setInputPin(int pin){
      input = pin;
    }
    
    void setOutputPin1(int pin){
      out1 = pin;
    }
    
    void setOutputPin2(int pin){
      out2 = pin;
    }
    
    void setOutputPin3(int pin){
      out3 = pin;
    }
   
    void initialize(Application *app){
      app->getTimeControl()->setScale(TimeScale::MilliSecond);
      app->getTimeControl()->initialize(1);//time is scaled for the timer
      app->getTimeControl()->startInterrupt();
      app->getTimeControl()->attachInterrupt();
      serial->println("init start");
      app->getTimeControl()->add(this);

      pinMode(input, INPUT);
      pinMode(out1, OUTPUT);
      pinMode(out2, OUTPUT);
      pinMode(out3, OUTPUT);
    }
   
    String getClassName(){
      return "RectifierState";
    }
    
    void Play(TimeControl *t){
      if(digitalRead(input)){
        if(cruceInicio){
          x0 = t->time;
          cruceInicio = false;
        }else{
          x1 = t->time;
          cruceInicio = true;
          tiempoOnda = 2*(x1 - x0);
          waveTime = 0;
        }
      }
      disparo = (30 + angle) * (tiempoOnda/360);
      if(waveTime >= disparo ){
        digitalWrite(6,HIGH);
      }else{
        digitalWrite(6,LOW);
      }
      waveTime += 1;
    }
    
  private:
    Stream *serial=NULL;
    long tiempoOnda = 0;
    long x0 = 0;
    long x1 = 0;
    int disparo = 0;
    int angle = 0;
    bool cruceInicio = true;
    int waveTime;
    int input = 5;
    int out1 = 7;
    int out2 = 8;
    int out3 = 9;
};

#endif 
