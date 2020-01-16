#ifndef DuoArray1Neuron_h
#define DuoArray1Neuron_h

#include "List.h"
#include "PList.h"
#include "ArrayList.h"
#include "Neuron.h"
#include "NetNeuron.h"

template<int size = 10>
class DuoArray1Neuron : public NetNeuron<float>{
	public:
		DuoArray1Neuron(){
			this->weightList = new ArrayList<float,size>();
			this->neuronList = new PList<Neuron<float>,size>();
		}
		virtual ~DuoArray1Neuron(){
			if(this->weightList != nullptr){
				delete this->weightList;
				this->weightList = nullptr;
			}		
			if(this->neuronList != nullptr){
				delete this->neuronList;
				this->neuronList = nullptr;
			}
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
		
		virtual bool initialize(){
			return true;
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
		virtual void onDelete(){
			if(this->neuronList != nullptr){
				this->neuronList->onDelete();
			}
		}
    
	protected:
	
};

#endif