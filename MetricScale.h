

#ifndef MetricScale_h
#define MetricScale_h

#include "MetricPrefix.h"

class MetricScale {
	public:
		MetricScale();
		~MetricScale();
		
		void setScaleTransform(MetricPrefix in, MetricPrefix out);
		float getValue(float in);
		
	protected:
		long metricscaleSetup(MetricPrefix prefix);
		long input = 1;
		long output = 1;
		long scale = 1;
		float scaleInverse = 1;
};

#endif 
