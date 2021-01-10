

#ifndef NTCRelay_h
#define NTCRelay_h

#include "GameOn.h"

class NTCRelay : public GameOn{
	public:
		float temperature = 0;
		float MaxTemperature = 0;
		int temperaturepin = 0;
		int relaypin = 0;

		NTCRelay(int tp, int rp, float max){
			pinMode(p, OUTPUT);
			this->temperaturepin = tp;
			this->relaypin = rp;
			this->MaxTemperature = max;
		}
		virtual ~NTCRelay(){}

		virtual String getClassName(){
			return "NTCRelay";
		}
		bool instanceof(String name){
			return name == "NTCRelay" || GameOn::instanceof(name);
		}
		
};


#endif 
