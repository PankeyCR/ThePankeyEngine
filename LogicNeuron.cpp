#ifndef LogicNeuron_cpp
#define LogicNeuron_cpp

#include "LogicNeuron.h"

	LogicNeuron::LogicNeuron(){
		this->functionList = new PrimitiveList<MFNEntry<float,float>>();
	}

	LogicNeuron::~LogicNeuron(){
		if(this->functionList != nullptr){
			delete this->functionList;
			this->functionList = nullptr;
		}
	}

	DataSet<float>* LogicNeuron::compute(DataSet<float> *data){
		Log("println", "start compute LogicNeuron");
		iterate(this->functionList){
			Log("println", "start iterate functionList");
			int in = this->functionList->getPointer()->input();
			int out = this->functionList->getPointer()->output();
			Function<float,float>* func = this->functionList->getPointer()->function();
			Log("print", "in");Log("println", String(in) );
			Log("print", "out");Log("println", String(out) );
			if(this->functionsetup() == FunctionSetup::ZeroStart){
				Log("println", "ZeroStart");
				iterate(data->iterateDimention(in)){
					func->set(data->getIteration(), data->getValue());
				}
			}
			if(this->functionsetup() == FunctionSetup::UnityStart){
				Log("println", "UnityStart");
				iterate(data->iterateDimention(in)){
					func->set(data->getIteration()+1, data->getValue());
				}
			}
			if(this->logic() == Logic::LogicGate1x1){
				Log("println", "LogicGate1x1");
				if(this->computability() == Computability::Computable){
					bool r = true;
					iterate(data->iterateDimention(out)){
						float o = this->output(data->getIteration(),0);
						float fout = func->f(data->getIteration());
						Log("print", "out");Log("expected output ", String(o) );
						Log("print", "out");Log("funtion output ", String(fout) );
						Log("print", "out");Log("bigger ", String(o + this->error()) );
						Log("print", "out");Log("smaller ", String(o - this->error()) );
						if(this->functionsetup() == FunctionSetup::ZeroStart){
							if(fout > o + this->error() &&
								fout < o - this->error()){
								Log("println", "not ");
								r = false;
								break;
							}
						}
						if(this->functionsetup() == FunctionSetup::UnityStart){
							if(func->f(data->getIteration()+1) > o + this->error() &&
								func->f(data->getIteration()+1) < o - this->error()){
								r = false;
								break;
							}
						}
					}
					if(r){
						if(this->functionsetup() == FunctionSetup::ZeroStart){
							data->set(func->f(data->getIteration()));
						}
						if(this->functionsetup() == FunctionSetup::UnityStart){
							data->set(func->f(data->getIteration()+1));
						}
					}
				}
			}
		}
		
		
		data->setIteration(0);
		return data;
	}
	
#endif