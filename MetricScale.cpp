
#ifndef MetricScale_cpp
#define MetricScale_cpp

#include "MetricScale.h"

	
	ame::MetricScale::MetricScale(){
	}
	
	ame::MetricScale::~MetricScale(){
	}
	
	long ame::MetricScale::metricscaleSetup(ame::MetricPrefix prefix){
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
	
	float ame::MetricScale::getValue(float in){
		if(this->input > this->output){
			return in*this->scaleInverse;
		}
		if(this->input < this->output){
			return in*this->scale;
		}
		return in;
	}
	
	void ame::MetricScale::setScaleTransform(ame::MetricPrefix in, ame::MetricPrefix out){
		this->input = metricscaleSetup(in);
		this->output = metricscaleSetup(out);
		if(this->input > this->output){
			this->scaleInverse = (float)(((float)this->output)/((float)this->input));
		}
		if(this->input < this->output){
			this->scale = this->output/this->input;
		}
	}
	
#endif 