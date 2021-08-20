
#ifndef FunctionMetric_h
#define FunctionMetric_h

#include "Random.h"
#include "AbsoluteRandom.h"
#include "Function.h"
#include "LinkedList.h"
#include "cppObject.h"

#ifdef FunctionMetricLogApp
	#include "Logger.h"
	#define FunctionMetricLog(name,method,type,mns) Log(name,method,type,mns)
#else
	#define FunctionMetricLog(name,method,type,mns)
#endif

namespace ame{

template<class type,class... args>
class FunctionMetric : public cppObject{
	public:
		FunctionMetric(){}
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
		virtual void operator=(FunctionMetric b){
			
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