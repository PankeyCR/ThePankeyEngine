

#ifndef Controller_h
#define Controller_h

#include "Arduino.h"
#include "GameOn.h"
#include "Map.h"
#include "List.h"

template<class Input,class Control, class Output>
class Controller : public GameOn{
	public:
		Controller(){
		}
		virtual ~Controller(){
		}
		
		virtual Controller<Input,Control,Output>* input(Input* in){
			this->input_m = in;
			return this;
		}
		virtual Controller<Input,Control,Output>* control(Control* ct){
			this->control_m = ct;
			return this;
		}
		virtual Controller<Input,Control,Output>* output(Output* ot){
			this->output_m = ot;
			return this;
		}
		
		virtual Input* input(){
			return this->input_m;
		}
		virtual Control* control(){
			return this->control_m;
		}
		virtual Output* output(){
			return this->output_m;
		}
		
		
		//cppObject part
		virtual String getClassName(){
			return "Controller";
		}
		virtual String toString(){
			return "Controller";
		}
		virtual Controller<Input,Control,Output>* clone(){
			return nullptr;
		}
		
	protected:
		Input* input_m = nullptr;
		Control* control_m = nullptr;
		Output* output_m = nullptr;
};

#endif 
