
#ifndef MinimalError_h
#define MinimalError_h

#include "FunctionConfiguration.h"
#include "ModifiableFunction.h"
#include "XtremeFunction1.h"
#include "AbsoluteRandom.h"
#include "DataSet.h"
#include "Stream.h"
#include "Logger.h"

class MinimalError : public FunctionConfiguration<float,float>{
	public:
		MinimalError();
		virtual ~MinimalError();
		
		virtual MinimalError* random(float max,float min,float st);
		virtual MinimalError* minimalerror(float st);
		virtual MinimalError* input(int st);
		virtual MinimalError* output(int st);
		virtual MinimalError* function(ModifiableFunction<float,float>* fn);
		virtual MinimalError* epochs(long epochs);
		virtual MinimalError* dataset(DataSet<float>* data);
		
		virtual Function<float,float>* build();
		
		virtual float error();
		
	protected:
		int inputD=0;
		int outputD=0;
		long epochcount=100;
		float rnd=521;
		float rndmax=2;
		float rndmin=0;
		float Error=0;
		float MError=0;
		DataSet<float>* data;
		ModifiableFunction<float,float>* fx = nullptr;
};

#endif 
