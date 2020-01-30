

#ifndef MinimalError_cpp
#define MinimalError_cpp

#include "MinimalError.h"

	
	MinimalError::MinimalError(){
	}
	
	MinimalError::MinimalError(Stream* serial){
		this->port = serial;
	}
	
	MinimalError::~MinimalError(){
		
	}
	
	MinimalError* MinimalError::random(float max,float min,float st){
		this->rnd = st;
		this->rndmax = max;
		this->rndmin = min;
        return this;
	}
	
	MinimalError* MinimalError::minimalerror(float st){
		this->MError = st;
        return this;
	}
	
	MinimalError* MinimalError::input(int st){
		this->inputD = st;
        return this;
	}
	
	MinimalError* MinimalError::output(int st){
		this->outputD = st;
        return this;
	}
	
	MinimalError* MinimalError::epochs(long epochs){
		this->epochcount = epochs;
        return this;
	}
	
	MinimalError* MinimalError::dataset(DataSet<float>* data){
		this->data = data;
        return this;
	}
	
	MinimalError* MinimalError::funtion(Funtion<float,float>* fn){
		this->fx = fn;
        return this;
	}
	
	float MinimalError::error(){
        return this->Error;
	}
	
	Funtion<float,float>* MinimalError::build(){
		if(this->fx == nullptr){
			this->fx = new XtremeFuntion1();
		}
		iterate(this->data->iterateDimention(this->inputD)){
			this->fx->set(this->data->getIteration(), this->data->getValue());
		}
		AbsoluteRandom random;
		random.setSeed(this->rnd);
		random.setMax(this->rndmax);
		random.setMin(this->rndmin);
		
		for(long x=0; x<this->epochcount;x++){
			Log("print","epochcount ");
			Log("println", String(x));
			
			float fun1 = 0;
			float maxErrT1 = 0;
			int maxErrT1Pos = 0;
			iterate(this->data->iterateDimention(this->outputD)){
				int pos= this->data->getIteration();
				float rf = this->fx->f(pos);
				float errt1 = abs(rf - this->data->getValue());
				Log("println","iterate 1 dimention output");
				Log("print","pos ");Log("println", String(pos));
				Log("print","data getValue ");Log("println", String(this->data->getValue()));
				Log("print","funtion responce ");Log("println", String(rf));
				Log("print","error ");Log("println", String(errt1));
				if(errt1 > maxErrT1){
					fun1 = rf;
					maxErrT1 = errt1;
					maxErrT1Pos = pos;
					this->Error = errt1;
					Log("print","maxErrT1 ");Log("println", String(errt1));
					Log("print","maxErrT1Pos ");Log("println", String(pos));
				}
			}
			
			bool learn = false;
			float maxErrT2 = 0;
			Log("println","funtion start ");
			iterate(this->fx){
				if(this->fx->isModifiable()){
					Log("print","funtion iteration ");Log("println", String(this->fx->getIteration()));
					float fv = this->fx->getValue();
					float randd = random.getRandom();
					Log("print","random ");Log("println", String(randd));
					this->fx->set(randd);
					iterate(this->data->iterateDimention(this->outputD)){
						int pos=this->data->getIteration();
						float rf = this->fx->f(pos);
						float errt2 = abs(rf - this->data->getValue());
						Log("println","iterate 2 dimention output");
						Log("print","pos ");Log("println", String(pos));
						Log("print","data getValue ");Log("println", String(this->data->getValue()));
						Log("print","funtion responce ");Log("println", String(rf));
						Log("print","error ");Log("println", String(errt2));
						if(errt2 > maxErrT2){
							maxErrT2 = errt2;
							Log("print","maxErrT1 ");Log("println", String(maxErrT1));
							Log("print","maxErrT2 ");Log("println", String(maxErrT2));
						}
						learn = true;
						if(maxErrT2 > maxErrT1){
							learn = false;
							Log("print","unlearning from error ");Log("println", String(errt2));
							break;
						}
					}
					if(!learn){
						this->fx->set(fv);
						maxErrT2 = 0;
						Log("println","unlearned ");
					}
				}
				if(learn){
					this->Error = maxErrT2;
					maxErrT1 = maxErrT2;
					maxErrT2 = 0;
					learn = false;
					Log("print","learn////////////////////////////////////// ");
					Log("println",String(this->Error));
					if(this->MError > this->Error){
						break;
					}
					continue;
				}
				if(this->MError > this->Error){
					break;
				}
			}
			if(this->MError > this->Error){
				break;
			}
		}
		
		
		return this->fx;
	}
		
		
		
#endif 
