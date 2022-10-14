

#ifndef NTC_h
#define NTC_h

#include "GameOn.h"

class NTC : public GameOn{
	public:
		float temperature = 0;
		int pin = 0;
		
		NTC(int p){
			pinMode(p, INPUT);
			this->pin = p;
		}
		virtual ~NTC(){}

		virtual String getClassName(){
			return "NTC";
		}
		bool instanceof(String name){
			return name == "NTC" || GameOn::instanceof(name);
		}
};


#endif 
