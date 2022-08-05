
#include "ame_Enviroment.hpp"

#if defined(DISABLE_MetricScale)
	#define MetricScale_hpp
#endif

#ifndef MetricScale_hpp
#define MetricScale_hpp
#define MetricScale_AVAILABLE

#ifndef ame_Enviroment_Defined

#endif

#ifdef ame_Windows

#endif

#ifdef ame_ArduinoIDE
	#include "Arduino.h"
#endif

#include "MetricPrefix.hpp"

namespace ame{

class MetricScale {
	public:
		MetricScale(){}
		~MetricScale(){}
		
		void setScaleTransform(MetricPrefix in, MetricPrefix out){
			this->input = metricscaleSetup(in);
			this->output = metricscaleSetup(out);
			if(this->input > this->output){
				this->scaleInverse = (float)(((float)this->output)/((float)this->input));
			}
			if(this->input < this->output){
				this->scale = this->output/this->input;
			}
		}
		
		float getValue(float in){
			if(this->input > this->output){
				return in*this->scaleInverse;
			}
			if(this->input < this->output){
				return in*this->scale;
			}
			return in;
		}
	
		
	protected:
		long metricscaleSetup(MetricPrefix prefix){
			long scaler = 1;
			if(prefix == MetricPrefix::micro){
				scaler = 1l;
			}
			if(prefix == MetricPrefix::milli){
				scaler = 1000l;
			}
			if(prefix == MetricPrefix::centi){
				scaler = 10000l;
			}
			if(prefix == MetricPrefix::deci){
				scaler = 100000l;
			}
			if(prefix == MetricPrefix::none){
				scaler = 1000000l;
			}
			if(prefix == MetricPrefix::deka){
				scaler = 10000000l;
			}
			if(prefix == MetricPrefix::hecto){
				scaler = 100000000l;
			}
			if(prefix == MetricPrefix::kilo){
				scaler = 1000000000l;
			}
			return scaler;
		}
		long input = 1;
		long output = 1;
		long scale = 1;
		float scaleInverse = 1;
};

}

#endif