
#ifndef TemperatureNTC_cpp
#define TemperatureNTC_cpp

#include "TemperatureNTC.h"

	
	ame::TemperatureNTC::TemperatureNTC(){
	}
	
	ame::TemperatureNTC::~TemperatureNTC(){
	}
	
	void ame::TemperatureNTC::initialize(){
		//Global parameters calculation
		beta=(log(RT1/RT2))/((1/T1)-(1/T2));
		Rinf=R0*exp(-beta/T0);
	}
	
	float ame::TemperatureNTC::getTemperature(int pin){
		float valor= analogRead(pin);  
		Vout = (valor/1023)*5; 
		Rout = (Raux*Vout/(Vin-Vout));

		TempK=(beta/log(Rout/Rinf));
		TempC=TempK-273.15;
		return TempC;
	}
	
	float ame::TemperatureNTC::getResistance(int pin){
		float valor= analogRead(pin);  
		Vout = (valor/1023)*5; 
		Rout = (Raux*Vout/(Vin-Vout));
		return Rout;
	}
	
	float ame::TemperatureNTC::getVolt(int pin){
		float valor= analogRead(pin);  
		float v = (valor/1023)*5; 
		return v;
	}
	
#endif 