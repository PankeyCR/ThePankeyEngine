

#ifndef MinimalError_cpp
#define MinimalError_cpp

#include "MinimalError.h"

	
	MinimalError::MinimalError(){
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
	
	MinimalError* MinimalError::function(ModifiableFunction<float,float>* fn){
		this->fx = fn;
        return this;
	}
	
	float MinimalError::error(){
        return this->Error;
	}
	
	Function<float,float>* MinimalError::build(){
		if(this->fx == nullptr){
			this->fx = new XtremeFunction1();
			Log("MinimalError", "build", "println","XtremeFunction1 used for MinimalError build as default");
		}
		if(this->functionsetup() == FunctionSetup::ZeroStart){
			Log("MinimalError", "build", "println","FunctionSetup ZeroStart");
			for(Iterator i : this->data->iterateSpace(this->inputD)){
				this->fx->setConstante(this->data->getIteration(), this->data->getValue());
			}
		}
		if(this->functionsetup() == FunctionSetup::UnityStart){
			Log("MinimalError", "build", "println","FunctionSetup UnityStart");
			for(Iterator i : this->data->iterateSpace(this->inputD)){
				this->fx->setConstante(this->data->getIteration()+1, this->data->getValue());
			}
		}
		AbsoluteRandom random;
		random.setSeed(this->rnd);
		random.setMax(this->rndmax);
		random.setMin(this->rndmin);
		Log("MinimalError", "build", "print","setSeed");Log("MinimalError", "build", "println",String(this->rnd));
		Log("MinimalError", "build", "print","setMax");Log("MinimalError", "build", "println",String(this->rndmax));
		Log("MinimalError", "build", "print","setMin");Log("MinimalError", "build", "println",String(this->rndmin));
		
		for(long x=0; x<this->epochcount;x++){
			yield();
			Log("MinimalError", "build", "print","epochcount ");
			Log("MinimalError", "build", "println", String(x));
			
			float fun1 = 0;
			float maxErrT1 = 0;
			int maxErrT1Pos = 0;
			for(Iterator i : this->data->iterateSpace(this->outputD)){
				int pos= this->data->getIteration();
				float rf = this->fx->f(pos);
				float errt1 = (rf - this->data->getValue());
				if(errt1 < 0){
					errt1*=-1.00f;
				}
				Log("MinimalError", "build", "println","iterate dimention "+String(this->outputD)+" output");
				Log("MinimalError", "build", "print","pos ");Log("MinimalError", "build", "println", String(pos));
				Log("MinimalError", "build", "print","data getValue ");Log("MinimalError", "build", "println", String(this->data->getValue()));
				Log("MinimalError", "build", "print","funtion responce ");Log("MinimalError", "build", "println", String(rf));
				Log("MinimalError", "build", "print","error ");Log("MinimalError", "build", "println", String(errt1));
				if(errt1 > maxErrT1){
					fun1 = rf;
					maxErrT1 = errt1;
					maxErrT1Pos = pos;
					this->Error = errt1;
					Log("MinimalError", "build", "print","maxErrT1 ");Log("MinimalError", "build", "println", String(errt1));
					Log("MinimalError", "build", "print","maxErrT1Pos ");Log("MinimalError", "build", "println", String(pos));
				}
			}
			
			bool learn = false;
			float maxErrT2 = 0;
			Log("MinimalError", "build", "println","funtion start ");
			for(Iterator i : *this->fx){
				yield();
				Log("MinimalError", "build", "print","funtion iteration ");Log("MinimalError", "build", "println", String(this->fx->getIteration()));
				float fv = this->fx->getLValue(i);
				float randd = random.getRandom();
				Log("MinimalError", "build", "print","random ");Log("MinimalError", "build", "println", String(randd));
				this->fx->set(i, randd);
				for(Iterator i : this->data->iterateSpace(this->outputD)){
					int pos=0;
					if(this->functionsetup() == FunctionSetup::ZeroStart){
						pos = i.getIteration();
					}
					if(this->functionsetup() == FunctionSetup::UnityStart){
						pos = i.getIteration()+1;
					}
					float rf = this->fx->f(pos);
					float errt2 = (rf - this->data->getValue());
					if(errt2 < 0){
						errt2*=-1.00f;
					}
					Log("MinimalError", "build", "println","iterate 2 dimention output");
					Log("MinimalError", "build", "print","pos ");Log("MinimalError", "build", "println", String(pos));
					Log("MinimalError", "build", "print","data getValue ");Log("MinimalError", "build", "println", String(this->data->getValue()));
					Log("MinimalError", "build", "print","funtion responce ");Log("MinimalError", "build", "println", String(rf));
					Log("MinimalError", "build", "print","error ");Log("MinimalError", "build", "println", String(errt2));
					if(errt2 > maxErrT2){
						maxErrT2 = errt2;
						Log("MinimalError", "build", "print","maxErrT1 ");Log("MinimalError", "build", "println", String(maxErrT1));
						Log("MinimalError", "build", "print","maxErrT2 ");Log("MinimalError", "build", "println", String(maxErrT2));
					}
					learn = true;
					if(maxErrT2 > maxErrT1){
						learn = false;
						Log("MinimalError", "build", "print","unlearning from error ");Log("MinimalError", "build", "println", String(errt2));
						break;
					}
				}
				if(!learn){
					this->fx->set(i, fv);
					maxErrT2 = 0;
					Log("MinimalError", "build", "println","unlearned ");
				}
				if(learn){
					this->Error = maxErrT2;
					maxErrT1 = maxErrT2;
					maxErrT2 = 0;
					learn = false;
					Log("MinimalError", "build", "print","learn////////////////////////////////////// ");
					Log("MinimalError", "build", "println",String(this->Error));
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
