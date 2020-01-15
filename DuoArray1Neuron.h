#ifndef DuoArray1Neuron_h
#define DuoArray1Neuron_h

#include "List.h"
#include "PList.h"
#include "ArrayList.h"
#include "Neuron.h"
#include "PNeuron.h"

template<int size = 10>
class DuoArray1Neuron : public PNeuron<size>{
	public:
		DuoArray1Neuron(){
			this->weightList = new ArrayList<float,size>();
			this->neuronList = new PList<Neuron<float>,size>();
		}
		virtual ~DuoArray1Neuron(){
		}
		
		virtual String getClassName(){
			return "DuoArray1Neuron";
		}
		virtual String toString(){
			return "DuoArray1Neuron";
		}
		virtual DuoArray1Neuron<size> *clone(){
			DuoArray1Neuron<size> *dn = new DuoArray1Neuron<size>();
			dn->setFuntion(this->getFuntion());
			return dn;
		}
		virtual DataSet<float> *compute(DataSet<float> *data){
			if(this->funtion == nullptr){
				return data;
			}
			iterate(data->iterateDimention(0)){
				this->funtion->set(data->getIteration(), data->getValue());
			}
			iterate(data->iterateDimention(1)){
				data->set(this->funtion->f(data->vector(1)));
			}
			return data;
		}
    
	protected:
	
};

#endif