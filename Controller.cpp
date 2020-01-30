

#ifndef Controller_cpp
#define Controller_cpp

#include "Controller.h"

	template<class InputSource,class ControlSource, class OutputSource>
	Controller<InputSource,ControlSource,OutputSource>::Controller(){
		
	}
	template<class InputSource,class ControlSource, class OutputSource>
	Controller<InputSource,ControlSource,OutputSource>::~Controller(){
		
	}
	
	template<class InputSource,class ControlSource, class OutputSource>
	Controller<InputSource,ControlSource,OutputSource>* Controller<InputSource,ControlSource,OutputSource>::setup(Controlling ctl){
		this->controlling = ctl;
		return this;
	}
	
	template<class InputSource,class ControlSource, class OutputSource>
	Controller<InputSource,ControlSource,OutputSource>* Controller<InputSource,ControlSource,OutputSource>::input(InputSource* in){
		this->inputm = in;
		return this;
	}
	
	template<class InputSource,class ControlSource, class OutputSource>
	Controller<InputSource,ControlSource,OutputSource>* Controller<InputSource,ControlSource,OutputSource>::control(ControlSource* ct){
		this->controlm = ct;
		return this;
	}
	
	template<class InputSource,class ControlSource, class OutputSource>
	Controller<InputSource,ControlSource,OutputSource>* Controller<InputSource,ControlSource,OutputSource>::output(OutputSource* ot){
		this->outputm = ot;
		return this;
	}
	
	// template<class InputSource,class ControlSource, class OutputSource>
	// Controller<InputSource,ControlSource,OutputSource>* Controller<InputSource,ControlSource,OutputSource>::input(InputSource in){
		
		// return this;
	// }
	
	// template<class InputSource,class ControlSource, class OutputSource>
	// Controller<InputSource,ControlSource,OutputSource>* Controller<InputSource,ControlSource,OutputSource>::control(ControlSource ct){
		
		// return this;
	// }
	
	// template<class InputSource,class ControlSource, class OutputSource>
	// Controller<InputSource,ControlSource,OutputSource>* Controller<InputSource,ControlSource,OutputSource>::output(OutputSource ot){
		
		// return this;
	// }
	
	template<class InputSource,class ControlSource, class OutputSource>
	InputSource* Controller<InputSource,ControlSource,OutputSource>::input(){
		return this->inputm;
	}
	
	template<class InputSource,class ControlSource, class OutputSource>
	ControlSource* Controller<InputSource,ControlSource,OutputSource>::control(){
		return this->controlm;
	}
	
	template<class InputSource,class ControlSource, class OutputSource>
	OutputSource* Controller<InputSource,ControlSource,OutputSource>::output(){
		return this->outputm;
	}
	
	// template<class InputSource,class ControlSource, class OutputSource>
	// OutputSource Controller<InputSource,ControlSource,OutputSource>::outputValue(){
		// return *this->outputm;
	// }
	
	template<class InputSource,class ControlSource, class OutputSource>
	void Controller<InputSource,ControlSource,OutputSource>::update(float tpf){
		
	}
	
	template<class InputSource,class ControlSource, class OutputSource>
	String Controller<InputSource,ControlSource,OutputSource>::getClassName(){
		return "Controller";
	}
	
	template<class InputSource,class ControlSource, class OutputSource>
	String Controller<InputSource,ControlSource,OutputSource>::toString(){
		return "Controller";
	}
	
	template<class InputSource,class ControlSource, class OutputSource>
	Controller<InputSource,ControlSource,OutputSource>* Controller<InputSource,ControlSource,OutputSource>::clone(){
		return this;
	}
	
	template<class InputSource,class ControlSource, class OutputSource>
	void Controller<InputSource,ControlSource,OutputSource>::operator=(const Controller& b){
		this->inputm = b.inputm;
		this->controlm = b.controlm;
		this->outputm = b.outputm;
	}
	
	template<class InputSource,class ControlSource, class OutputSource>
	bool Controller<InputSource,ControlSource,OutputSource>::operator==(const Controller& b){
		return this->inputm == b.inputm && this->controlm == b.controlm && this->outputm == b.outputm;
	}
	
	template<class InputSource,class ControlSource, class OutputSource>
	bool Controller<InputSource,ControlSource,OutputSource>::operator!=(const Controller& b){
		return this->inputm !=	b.inputm && this->controlm != b.controlm && this->outputm != b.outputm;
	}

	//////////////////////////////////////////////////////////////////
	
	template class Controller<float,float,float>;
	template class Controller<float,List<float>,float>;
	template class Controller<float,Map<String,float>,float>;
#endif 
