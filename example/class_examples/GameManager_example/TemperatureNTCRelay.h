

#ifndef TemperatureNTCRelay_h
#define TemperatureNTCRelay_h

#include "GameOn.h"

class TemperatureNTCRelay : public GameOn{
    public:
    float MaxTemperature = 0;
    int pin = 0;
		TemperatureNTCRelay(int p, float max){
      pinMode(p, OUTPUT);
      this->pin = p;
      this->MaxTemperature = max;
		}
		virtual ~TemperatureNTCRelay(){}
		
};


#endif 
