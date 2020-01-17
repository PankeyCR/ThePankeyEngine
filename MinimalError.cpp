

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
			this->fx->set(this->data->vector(this->inputD), this->data->getValue());
		}
		AbsoluteRandom random;
		
		for(long x=0; x<this->epochcount;x++){
			if(this->port != nullptr){
				this->port->println(x);
			}
			int maxErrT1 = 0;
			int maxErrT1Pos = 0;
			iterate(this->data->iterateDimention(this->outputD)){
				int pos=this->data->vector(this->outputD);
				float rf = this->fx->f(pos);
				float errt1 = abs(rf - this->data->getValue());
				if(errt1 > maxErrT1){
					maxErrT1 = errt1;
					maxErrT1Pos = pos;
				}
			}
			
			iterate(this->fx){
				if(this->fx->isModifiable()){
					int maxErrT2 = 0;
					bool learn = false;
					float fv = this->fx->getValue();
					this->fx->set(random.getRandom());
					iterate(this->data->iterateDimention(this->outputD)){
						int pos=this->data->vector(this->outputD);
						float rf = this->fx->f(pos);
						float errt2 = abs(rf - this->data->getValue());
						if(errt2 > maxErrT2){
							maxErrT2 = errt2;
							this->Error = errt2;
							if(this->port != nullptr){
								this->port->println(this->Error);
							}
						}
						learn = true;
						if(maxErrT2 > maxErrT1){
							maxErrT2 = errt2;
							learn = false;
							break;
						}
					}
					if(!learn){
						this->fx->set(fv);
					}
				}
			}
		}
		
		
		return this->fx;
	}
		
		
		
#endif 
