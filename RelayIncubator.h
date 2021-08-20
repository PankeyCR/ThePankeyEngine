

#ifndef RelayIncubator_h
#define RelayIncubator_h

#include "Logger.h"
#include "Arduino.h"
#include "Average.h"
#include "MetricScale.h"
#include "Application.h"
#include "AppState.h"
#include "TimeControl.h"
#include "TemperatureNTC.h"
#include "FixPulseGenerator.h"

namespace ame{
	
class RelayIncubator : public AppState{
    public:
		RelayIncubator();
		virtual ~RelayIncubator();
		
		virtual void setMaxTemperature(float t);
		virtual void setTemeraturePin(int pin);
		virtual void setRelayPin(int pin);
		virtual void setFanPin(int pin);
		
		virtual void initialize(Application *app);
		virtual void update();
		
		cppObjectClass* getClass();
		String toString();
		
	protected:
		MetricScale* scale;
		TemperatureNTC* temperature;
		FixPulseGenerator* fanPulse;
		FixPulseGenerator* relayPulse;
		int tpin = 0;
		float maxT = 38;
		Average<float>* average;
};

}

#endif 
