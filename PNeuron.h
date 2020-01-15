#ifndef PNeuron_h
#define PNeuron_h

#include "List.h"
#include "PList.h"
#include "ArrayList.h"
#include "DataSet.h"
#include "Neuron.h"
#include "NetNeuron.h"

template<int size = 10>
class PNeuron : public NetNeuron<float>{
	public:
		PNeuron(){
			this->weightList = new ArrayList<float,size>();
			this->neuronList = new PList<Neuron<float>,size>();
		}
		virtual ~PNeuron(){
			if(this->weightList != nullptr){
				delete this->weightList;
				this->weightList = nullptr;
			}		
			if(this->neuronList != nullptr){
				delete this->neuronList;
				this->neuronList = nullptr;
			}
		}
		
		virtual bool initialize(){
			return true;
		}
		virtual DataSet<float> *compute(DataSet<float> *data){
			if(this->funtion == nullptr){
				return data;
			}
			if(data->getClassName() == "DuoArray1"){
				iterate(data->iterateDimention(0)){
					this->funtion->set(data->getIteration(), data->getValue());
				}
				iterate(data->iterateDimention(1)){
					data->set(this->funtion->f(data->vector(1)));
				}
				return data;
			}
			
			iterate(data){
				float value =this->funtion->f(data->getValue());
				data->set(value);
				iterate(this->neuronList){
					DataSet<float> *ndata = this->neuronList->getPointer()->compute(data);
					if(ndata == nullptr){
						return ndata;
					}
				}
			}
			return data;
		}
		
		//cppObject part
		virtual String getClassName(){
			return "PNeuron";
		}
		virtual String toString(){
			return "PNeuron";
		}
		virtual PNeuron<size> *clone(){
			PNeuron<size> *dn = new PNeuron<size>();
			dn->setFuntion(this->getFuntion());
			return dn;
		}
		virtual void onDelete(){
			if(this->neuronList != nullptr){
				this->neuronList->onDelete();
			}
		}
    
	protected:
	
};

#endif