
#include "ame_Enviroment.hpp"

#if defined(DISABLE_MinimalError)
	#define MinimalError_hpp
#endif

#ifndef MinimalError_hpp
#define MinimalError_hpp
#define MinimalError_AVAILABLE

#ifndef ame_Enviroment_Defined

#endif

#ifdef ame_Windows

#endif

#ifdef ame_ArduinoIDE
	#include "Arduino.h"
	#include "Stream.h"
#endif

#include "FunctionConfiguration.hpp"
#include "ModifiableFunction.hpp"
#include "XtremeFunction1.hpp"
#include "AbsoluteRandom.hpp"
#include "DataSet.hpp"
#include "ArrayFunction.hpp"

#ifdef MinimalErrorLogApp
	#include "Logger.h"
	#define MinimalErrorLog(name,method,type,mns) Log(name,method,type,mns)
#else
	#define MinimalErrorLog(name,method,type,mns)
#endif

namespace ame{

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
				MinimalErrorLog("MinimalError", "fit", "println", Note("epochcount ")+Note(x));
				float maxErrT1 = 0;
				float rf = this->fx->f(a...);
				float errt1 = (rf - metric->getOutput());
				if(errt1 < 0){
					errt1*=-1.00f;
				}
				MinimalErrorLog("MinimalError", "fit", "println",Note("initial error: ")+Note(errt1));
				if(errt1 > metric->getError()){
					maxErrT1 = errt1;
					MinimalErrorLog("MinimalError", "fit", "println","to much error");
				}
				bool learn = false;
				float maxErrT2 = 0;
				MinimalErrorLog("MinimalError", "fit", "println","funtion start ");
				MinimalErrorLog("MinimalError", "fit", "println",Note("getIterationSize ")+Note(fx->getIterationSize()));
				for(int fxI = 0; fxI < fx->getIterationSize(); fxI++){
					yield();
					float fv = this->fx->getLValue(fxI);
					float randd = metric->getRandom();
					MinimalErrorLog("MinimalError", "fit", "println", Note("modifiable variable: ")+Note(fv));
					MinimalErrorLog("MinimalError", "fit", "println", Note("modifiable variable position: ")+Note(fxI));
					MinimalErrorLog("MinimalError", "fit", "println", Note("last function result: ")+Note(rf));
					MinimalErrorLog("MinimalError", "fit", "println", Note("random ")+Note(randd));
					this->fx->set(fxI, randd);
					float rf = this->fx->f(a...);
					MinimalErrorLog("MinimalError", "fit", "println", Note("new function result: ")+Note(rf));
					float errt2 = (rf - metric->getOutput());
					if(errt2 < 0){
						errt2*=-1.00f;
					}
					if(errt2 > maxErrT2){
						maxErrT2 = errt2;
						MinimalErrorLog("MinimalError", "fit", "println", "errt2 > maxErrT2");
						MinimalErrorLog("MinimalError", "fit", "println", Note("maxErrT1 ")+Note(maxErrT1));
						MinimalErrorLog("MinimalError", "fit", "println", Note("maxErrT2 ")+Note(maxErrT2));
					}
					learn = true;
					if(maxErrT2 > maxErrT1){
						learn = false;
						MinimalErrorLog("MinimalError", "fit", "println", Note("unlearning from error ")+Note(errt2));
					}
					if(!learn){
						this->fx->set(fxI, fv);
						maxErrT2 = 0;
						MinimalErrorLog("MinimalError", "fit", "println", Note("unlearned ")+Note(randd));
						MinimalErrorLog("MinimalError", "fit", "println", Note("restore ")+Note(fv));
					}
					if(learn){
						maxErrT1 = maxErrT2;
						maxErrT2 = 0;
						learn = false;
						MinimalErrorLog("MinimalError", "fit", "println",Note("learn//////////////////////////////////////  ")+Note(maxErrT1));
						if(metric->getError() > maxErrT1){
							MinimalErrorLog("MinimalError", "fit", "println","metric->getError() > maxErrT1");
							MinimalErrorLog("MinimalError", "fit", "println",Note("metric->getError ")+Note(metric->getError()));
							MinimalErrorLog("MinimalError", "fit", "println",Note("maxErrT1 ")+Note(maxErrT1));
							break;
						}
						continue;
					}
					if(metric->getError() > maxErrT1){
						MinimalErrorLog("MinimalError", "fit", "println","metric->getError() > maxErrT1");
						MinimalErrorLog("MinimalError", "fit", "println",Note("metric->getError ")+Note(metric->getError()));
						MinimalErrorLog("MinimalError", "fit", "println",Note("maxErrT1 ")+Note(maxErrT1));
						break;
					}
					
				}
				if(metric->getError() > maxErrT1){
					MinimalErrorLog("MinimalError", "fit", "println","metric->getError() > maxErrT1");
					MinimalErrorLog("MinimalError", "fit", "println",Note("metric->getError ")+Note(metric->getError()));
					MinimalErrorLog("MinimalError", "fit", "println",Note("maxErrT1 ")+Note(maxErrT1));
					break;
				}
			}
		}
		
	protected:
		ModifiableFunction<T,args...>* fx = nullptr;
};

}

#endif