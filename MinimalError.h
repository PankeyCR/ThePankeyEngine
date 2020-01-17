
#ifndef MinimalError_h
#define MinimalError_h

#include "FuntionConfiguration.h"
#include "Funtion.h"
#include "XtremeFuntion1.h"
#include "AbsoluteRandom.h"
#include "DataSet.h"
#include "Stream.h"

class MinimalError : public FuntionConfiguration<float,float>{
	public:
		MinimalError();
		MinimalError(Stream* serial);
		virtual ~MinimalError();
		
		virtual MinimalError* input(int st);
		virtual MinimalError* output(int st);
		virtual MinimalError* funtion(Funtion<float,float>* fn);
		virtual MinimalError* epochs(long epochs);
		virtual MinimalError* dataset(DataSet<float>* data);
		
		virtual Funtion<float,float>* build();
		
		virtual float error();
		
	protected:
		Stream* port = nullptr;
		int inputD=0;
		int outputD=0;
		long epochcount=100;
		float Error=0;
		DataSet<float>* data;
		Funtion<float,float>* fx = nullptr;
};

#endif 
