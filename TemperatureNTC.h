

#ifndef TemperatureNTC_h
#define TemperatureNTC_h

#include "Arduino.h"

class TemperatureNTC{
    public:
		TemperatureNTC();
		virtual ~TemperatureNTC();
		
		void initialize();
		float getTemperature(int pin);
		float getResistance(int pin);
	protected:
		float Vin=5.0;     // [V]        Supply voltage in the Voltage-Divider
		float Raux=10000;  // [ohm]      Secondary resistor in the Voltage-Divider
		float R0=10000;    // [ohm]      NTC nominal value at 25ºC
		float T0=293.15;   // [K] (25ºC)

		float Vout=0.0;    // [V]        Voltage given by the Voltage-Divider
		float Rout=0.0;    // [ohm]      Current NTC resistance

		float T1=273;      // [K]        Temperature at first testing point
		float T2=373;      // [K]        Temperature at second testing point
		float RT1=19750;   // [ohms]     Resistance at 273K (0ºC)
		float RT2=2150;    // [ohms]     Resistance at 373K (100ºC)

		float beta=0.0;    // [K]        Beta parameter
		float Rinf=0.0;    // [ohm]      Rinf parameter
		float TempK=0.0;   // [K]        Temperature output in Kelvin
		float TempC=0.0;   // [ºC]       Temperature output in Celsius
		
		
		// float Vin=5.0;     // [V]        Supply voltage in the Voltage-Divider
		// float Raux=10000;  // [ohm]      Secondary resistor in the Voltage-Divider
		// float R0=10000;    // [ohm]      NTC nominal value at 25ºC
		// float T0=293.15;   // [K] (25ºC)

		// float Vout=0.0;    // [V]        Voltage given by the Voltage-Divider
		// float Rout=0.0;    // [ohm]      Current NTC resistance

		// float T1=273;      // [K]        Temperature at first testing point
		// float T2=373;      // [K]        Temperature at second testing point
		// float RT1=19750;   // [ohms]     Resistance at 273K (0ºC)
		// float RT2=2150;    // [ohms]     Resistance at 373K (100ºC)

		// float beta=0.0;    // [K]        Beta parameter
		// float Rinf=0.0;    // [ohm]      Rinf parameter
		// float TempK=0.0;   // [K]        Temperature output in Kelvin
		// float TempC=0.0;   // [ºC]       Temperature output in Celsius
};

#endif 
