
#include "ame_Enviroment.hpp"

#if defined(DISABLE_FunctionMetric)
	#define FunctionMetric_hpp
#endif

#ifndef FunctionMetric_hpp
#define FunctionMetric_hpp
#define FunctionMetric_AVAILABLE

#ifndef ame_Enviroment_Defined

#endif

#ifdef ame_Windows

#endif

#ifdef ame_ArduinoIDE
	#include "Arduino.h"
#endif

#include "Random.hpp"
#include "AbsoluteRandom.hpp"
#include "Function.hpp"
#include "LinkedList.hpp"
#include "cppObject.hpp"

#ifdef FunctionMetricLogApp
	#include "Logger.hpp"
	#define FunctionMetricLog(name,method,type,mns) Log(name,method,type,mns)
#else
	#define FunctionMetricLog(name,method,type,mns)
#endif

namespace ame{

template<class type,class... args>
class FunctionMetric : public cppObject{
	public:
		FunctionMetric(){}
		FunctionMetric(const FunctionMetric& metric){
			this->m_random = metric.m_random;
			this->m_inputs = metric.m_inputs;
			this->m_output = metric.m_output;
			this->m_epochs = metric.m_epochs;
			this->m_error = metric.m_error;
		}
		virtual ~FunctionMetric(){} 
		
		void random(Random* r){
			if(m_random == nullptr){
				m_random = r;
				return;
			}
			if(m_random != r){
				delete m_random;
				m_random = r;
			}
		}
		
		void random(float max,float min,float s){
			if(m_random == nullptr){
				m_random = new AbsoluteRandom(s);
			}else{
				delete m_random;
				m_random = new AbsoluteRandom(s);
			}
			m_random->setMax(max);
			m_random->setMin(min);
			m_random->setSeed(s);
		}
		virtual void minimalerror(type e){
			m_error = e;
		}
		
		void input(args... i){
			m_inputs.resetDelete();
			m_inputs.addPack(i...);
		}
		void output(type o){
			m_output = o;
		}
		void epochs(long e){
			m_epochs = e;
		}
		
		float getRandom(){
			if(m_random == nullptr){
				return -1.0f;
			}
			return m_random->getRandom();
		}
		int getInputSize(){
			return m_inputs.getPosition();
		}
		type getInput(){
			if(m_inputs.getByPosition(0) == nullptr){
				return -1;
			}
			return m_inputs.getByPosition(0);
		}
		type getInput(int x){
			if(m_inputs.getByPosition(x) == nullptr){
				return -1;
			}
			return *m_inputs.getByPosition(x);
		}
		type getOutput(){
			return m_output;
		}
		long getEpochs(){
			return m_epochs;
		}
		type getError(){
			return m_error;
		}
		virtual bool instanceof(cppObjectClass* cls){
			return cls == Class<FunctionMetric>::classType || cppObject::instanceof(cls);
		}
		virtual void operator=(const FunctionMetric& metric){
			this->m_random = metric.m_random;
			this->m_inputs = metric.m_inputs;
			this->m_output = metric.m_output;
			this->m_epochs = metric.m_epochs;
			this->m_error = metric.m_error;
		}
		virtual bool operator==(FunctionMetric b){
			return false;
		}
		virtual bool operator!=(FunctionMetric b){
			return false;
		}
		
	protected:
		Random* m_random = nullptr;
		LinkedList<type> m_inputs;
		type m_output;
		long m_epochs = 100;
		type m_error;
};

}

#endif