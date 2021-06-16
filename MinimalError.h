
#ifndef MinimalError_h
#define MinimalError_h

#include "FunctionConfiguration.h"
#include "ModifiableFunction.h"
#include "XtremeFunction1.h"
#include "AbsoluteRandom.h"
#include "DataSet.h"
#include "ArrayFunction.h"
#include "Stream.h"

#ifdef MinimalErrorLogApp
	#include "Logger.h"
	#define MinimalErrorLog(name,method,type,mns) Log(name,method,type,mns)
#else
	#define MinimalErrorLog(name,method,type,mns)
#endif

template<class T,class... args>
class MinimalError : public FunctionProtocol<T,args...>{
	public:
		MinimalError(){}
		virtual ~MinimalError(){}
		
		virtual Function<T,args...>* createFunction(FunctionMetric<T,args...>* metric){
			MinimalErrorLog("MinimalError", "createFunction", "println","");
			// fx = new ArrayFunction<10,30,10,10,10,T,args...>();
			fx = new XtremeFunction1<T,args...>();
			return fx;
		}
		virtual void initializeFuntion(FunctionMetric<T,args...>* metric){
			
		}
		virtual void fit(FunctionMetric<T,args...>* metric, args... a){
			MinimalErrorLog("MinimalError", "fit", "print","");
			for(long x = 0; x < metric->getEpochs(); x++){
				yield();
				MinimalErrorLog("MinimalError", "fit", "println", String("epochcount ")+String(x));
				float maxErrT1 = 0;
				float rf = this->fx->f(a...);
				float errt1 = (rf - metric->getOutput());
				if(errt1 < 0){
					errt1*=-1.00f;
				}
				MinimalErrorLog("MinimalError", "fit", "println",String("initial error: ")+String(errt1));
				if(errt1 > metric->getError()){
					maxErrT1 = errt1;
					MinimalErrorLog("MinimalError", "fit", "println","to much error");
				}
				bool learn = false;
				float maxErrT2 = 0;
				MinimalErrorLog("MinimalError", "fit", "println","funtion start ");
				MinimalErrorLog("MinimalError", "fit", "println",String("getIterationSize ")+String(fx->getIterationSize()));
				for(int fxI = 0; fxI < fx->getIterationSize(); fxI++){
					yield();
					float fv = this->fx->getLValue(fxI);
					float randd = metric->getRandom();
					MinimalErrorLog("MinimalError", "fit", "println", String("modifiable variable: ")+String(fv));
					MinimalErrorLog("MinimalError", "fit", "println", String("modifiable variable position: ")+String(fxI));
					MinimalErrorLog("MinimalError", "fit", "println", String("last function result: ")+String(rf));
					MinimalErrorLog("MinimalError", "fit", "println", String("random ")+String(randd));
					this->fx->set(fxI, randd);
					float rf = this->fx->f(a...);
					MinimalErrorLog("MinimalError", "fit", "println", String("new function result: ")+String(rf));
					float errt2 = (rf - metric->getOutput());
					if(errt2 < 0){
						errt2*=-1.00f;
					}
					if(errt2 > maxErrT2){
						maxErrT2 = errt2;
						MinimalErrorLog("MinimalError", "fit", "println", "errt2 > maxErrT2");
						MinimalErrorLog("MinimalError", "fit", "println", String("maxErrT1 ")+String(maxErrT1));
						MinimalErrorLog("MinimalError", "fit", "println", String("maxErrT2 ")+String(maxErrT2));
					}
					learn = true;
					if(maxErrT2 > maxErrT1){
						learn = false;
						MinimalErrorLog("MinimalError", "fit", "println", String("unlearning from error ")+String(errt2));
					}
					if(!learn){
						this->fx->set(fxI, fv);
						maxErrT2 = 0;
						MinimalErrorLog("MinimalError", "fit", "println", String("unlearned ")+String(randd));
						MinimalErrorLog("MinimalError", "fit", "println", String("restore ")+String(fv));
					}
					if(learn){
						maxErrT1 = maxErrT2;
						maxErrT2 = 0;
						learn = false;
						MinimalErrorLog("MinimalError", "fit", "println",String("learn//////////////////////////////////////  ")+String(maxErrT1));
						if(metric->getError() > maxErrT1){
							MinimalErrorLog("MinimalError", "fit", "println","metric->getError() > maxErrT1");
							MinimalErrorLog("MinimalError", "fit", "println",String("metric->getError ")+String(metric->getError()));
							MinimalErrorLog("MinimalError", "fit", "println",String("maxErrT1 ")+String(maxErrT1));
							break;
						}
						continue;
					}
					if(metric->getError() > maxErrT1){
						MinimalErrorLog("MinimalError", "fit", "println","metric->getError() > maxErrT1");
						MinimalErrorLog("MinimalError", "fit", "println",String("metric->getError ")+String(metric->getError()));
						MinimalErrorLog("MinimalError", "fit", "println",String("maxErrT1 ")+String(maxErrT1));
						break;
					}
					
				}
				if(metric->getError() > maxErrT1){
					MinimalErrorLog("MinimalError", "fit", "println","metric->getError() > maxErrT1");
					MinimalErrorLog("MinimalError", "fit", "println",String("metric->getError ")+String(metric->getError()));
					MinimalErrorLog("MinimalError", "fit", "println",String("maxErrT1 ")+String(maxErrT1));
					break;
				}
			}
		}
		
	protected:
		ModifiableFunction<T,args...>* fx = nullptr;
};

#endif 
