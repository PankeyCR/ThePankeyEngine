
#ifndef Ultrasonic_h
#define Ultrasonic_h

#include "Arduino.h"

class Ultrasonic {
    public:
    Ultrasonic();
    Ultrasonic setPins(int TrigPin, int EchoPin);
    float getDistance();
    float getSafeDistance(int safe);
    private:    
    float distance;
    float trigPin;
    float echoPin;    
};
#endif 
