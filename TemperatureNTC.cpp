
#ifndef TemperatureNTC_cpp
#define TemperatureNTC_cpp

#include "TemperatureNTC.h"

	
	TemperatureNTC::TemperatureNTC(){
	}
	
	TemperatureNTC::~TemperatureNTC(){
	}
	
	void TemperatureNTC::initialize(){
		//Global parameters calculation
		beta=(log(RT1/RT2))/((1/T1)-(1/T2));
		Rinf=R0*exp(-beta/T0);
	}
	
	float TemperatureNTC::getTemperature(int pin){
		float valor= analogRead(pin);  
		Vout = (valor/1023)*5; 
		Rout = (Raux*Vout/(Vin-Vout));

		TempK=(beta/log(Rout/Rinf));
		TempC=TempK-273.15;
		return TempC;
	}
	
	float TemperatureNTC::getResistance(int pin){
		float valor= analogRead(pin);  
		Vout = (valor/1023)*5; 
		Rout = (Raux*Vout/(Vin-Vout));
		return Rout;
	}
	
#endif 