#ifndef NetNeuron_cpp
#define NetNeuron_cpp

#include "NetNeuron.h"

	template<class... arr>
	NetNeuron<arr...>::NetNeuron(){
		
	}
	
	template<class... arr>
	NetNeuron<arr...>::~NetNeuron(){
		// if(this->weightList != nullptr){
			// delete this->weightList;
			// this->weightList = nullptr;
		// }		
		// if(this->neuronList != nullptr){
			// delete this->neuronList;
			// this->neuronList = nullptr;
		// }
	}
	
	template<class... arr>
	void NetNeuron<arr...>::setWeight(int index, float set){
		if(this->weightList == nullptr){
			return;
		}
		if(this->weightList->getPos() < index){
			//this->weightList->add(set);
		}else{
			this->weightList->set(index, set);
		}
	}
	
	template<class... arr>
	float NetNeuron<arr...>::getWeight(int id){
		if(this->weightList == nullptr){
			return 0;
		}
		if(this->weightList->getByPos(id) == nullptr){
			return 0;
		}else{
			return *this->weightList->getByPos(id);
		}
	}

	template<class... arr>
	Neuron<float> *NetNeuron<arr...>::connect(Neuron<float> *neuron){
		if(this->neuronList == nullptr || this->weightList == nullptr){
			return nullptr;
		}
		this->neuronList->add(neuron);
		this->weightList->add(1.0f);
		return neuron;
	}

	template<class... arr>
	Neuron<float> *NetNeuron<arr...>::getNeuron(int index ){
		if(this->neuronList == nullptr){
			return nullptr;
		}
		return this->neuronList->getByPos(index);
	}

	template<class... arr>
	Neuron<float> *NetNeuron<arr...>::removeNeuron(int index ){
		if(this->neuronList == nullptr){
			return nullptr;
		}
		Neuron<float> *n = this->neuronList->getByPos(index);
		this->neuronList->removeByPos(index);
		return n;
	}

	template<class... arr>
	List<Neuron<float>> *NetNeuron<arr...>::getNeurons(){
		return this->neuronList;
	}

	template<class... arr>
	bool NetNeuron<arr...>::initialize(){
		
	}

	template<class... arr>
	DataSet<float> *NetNeuron<arr...>::compute(DataSet<float> *data){
		
	}
	
	template<class... arr>
	String NetNeuron<arr...>::getClassName(){
		return "NetNeuron";
	}
	
	template<class... arr>
	String NetNeuron<arr...>::toString(){
		return "NetNeuron";
	}
	
	template<class... arr>
	bool NetNeuron<arr...>::equal(cppObject *b){
		if(b == this){
			return true;
		}
		if(b->getClassName() == this->getClassName()){
			return true;
		}
		return false;
	}
	
	template<class... arr>
	Neuron<float> *NetNeuron<arr...>::clone(){
		return this;
	}
	
	template<class... arr>
	Neuron<float> *NetNeuron<arr...>::setFuntion(Funtion<float,arr...> *a){
		this->funtion = a;
		return this;
	}
	
	template<class... arr>
	Funtion<float,arr...> *NetNeuron<arr...>::getFuntion(){
		return this->funtion;
	}
	
	
	template class NetNeuron<long>;
	template class NetNeuron<char>;
	template class NetNeuron<double>;
	
	template class NetNeuron<float>;
	template class NetNeuron<float,float>;
	template class NetNeuron<float,float,float>;
	template class NetNeuron<float,float,float,float>;
	
	

#endif