#ifndef PNeuron_h
#define PNeuron_h

#include "GameOn.h"
#include "List.h"
#include "PList.h"
#include "DataSet.h"
#include "Neuron.h"
#include "FNeuron.h"

template<int size = 10>
class PNeuron : public FNeuron<float,float,float>{
	public:
		PNeuron(){
			this->childs = new PList<GameOn,size>();
		}
		PNeuron(String i){
			this->setId(i);
			this->childs = new PList<GameOn,size>();
		}
		PNeuron(String i, int in, int out){
			this->setId(i);
			this->diminput = in;
			this->dimoutput = out;
			this->childs = new PList<GameOn,size>();
		}
		virtual ~PNeuron(){
			if(this->childs != nullptr){
				delete this->childs;
				this->childs = nullptr;
			}
		}
		
		virtual DataSet<float> *compute(DataSet<float> *data){
			if(this->function == nullptr){
				return data;
			}
			if(this->getFuntionSetup() == FunctionSetup::ZeroStart){
				iterate(data->iterateDimention(diminput)){
					this->function->set(data->getIteration(), data->getValue());
				}
			}
			if(this->getFuntionSetup() == FunctionSetup::UnityStart){
				iterate(data->iterateDimention(diminput)){
					this->function->set(data->getIteration()+1, data->getValue());
				}
			}
			
			if(this->logic() == Logic::LogicGate1x1){
				if(this->computability() == Computability::Computable){
					iterate(data->iterateDimention(dimoutput)){
						if(this->getFuntionSetup() == FunctionSetup::ZeroStart){
							data->set(this->function->f(data->getIteration()));
						}
						if(this->getFuntionSetup() == FunctionSetup::UnityStart){
							data->set(this->function->f(data->getIteration()+1));
						}
					}
				}
			}
			data->setIteration(0);
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
			dn->setFunction(this->getFunction());
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