#ifndef MFNeuron_cpp
#define MFNeuron_cpp

#include "MFNeuron.h"

	template<class dataset,class funtion_return, class... arr>
	MFNeuron<dataset,funtion_return,arr...>::MFNeuron(){
		
	}

	template<class dataset,class funtion_return, class... arr>
	MFNeuron<dataset,funtion_return,arr...>::~MFNeuron(){
		
	}

	template<class dataset,class funtion_return, class... arr>
	DataSet<dataset> *MFNeuron<dataset,funtion_return,arr...>::compute(DataSet<dataset> *data){
		iterate(this){
			iterate(this->getPointer()){
				// iterate(this->getPointer()){
					
				// }
			}
		}
		return data;
	}
	
	template class MFNeuron<long,float,float>;
	template class MFNeuron<char,float,float>;
	template class MFNeuron<float,float,float>;
	template class MFNeuron<double,float,float>;
	template class MFNeuron<String,String,String>;

#endif