#ifndef VNeuron_h
#define VNeuron_h

#include "List.h"
#include "PrimitiveList.h"
#include "DataSet.h"
#include "Neuron.h"

template<int size = 10>
class VNeuron : public Neuron<float,float,float>{
	public:
		VNeuron(){
			this->childs = new PrimitiveList<GameOn>();
		}
		VNeuron(String i){
			this->setId(i);
			this->childs = new PrimitiveList<GameOn>();
		}
		VNeuron(String i, int in, int out){
			this->setId(i);
			this->diminput = in;
			this->dimoutput = out;
			this->childs = new PrimitiveList<GameOn>();
		}
		virtual ~VNeuron(){
			if(this->childs != nullptr){
				delete this->childs;
				this->childs = nullptr;
			}
		}
		
		virtual DataSet<float> *compute(DataSet<float> *data){
			if(this->funtion == nullptr){
				return data;
			}
			iterate(data->iterateDimention(diminput)){
				this->funtion->set(data->getIteration(), data->getValue());
			}
			iterate(data->iterateDimention(dimoutput)){
				data->set(this->funtion->f(data->getIteration()));
			}
			return data;
		}
		
		//cppObject part
		virtual String getClassName(){
			return "VNeuron";
		}
		virtual String toString(){
			return "VNeuron";
		}
		virtual VNeuron<size> *clone(){
			VNeuron<size> *dn = new VNeuron<size>();
			dn->setFuntion(this->getFuntion());
			return dn;
		}
		virtual void onDelete(){
			if(this->childs != nullptr){
				this->childs->onDelete();
			}
		}
		virtual int input(){
			return diminput;
		}
		virtual int output(){
			return dimoutput;
		}
		virtual void input(int dm){
			diminput= dm;
		}
		virtual void output(int dm){
			dimoutput= dm;
		}
    
	protected:
		int diminput=0;
		int dimoutput=1;
};

#endif