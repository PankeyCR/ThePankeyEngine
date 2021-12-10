
#include "ame_Level.hpp"

#if defined(ame_untilLevel_7)

#ifndef Controller_hpp
#define Controller_hpp

#include "Arduino.h"
#include "GameOn.hpp"
#include "Map.hpp"
#include "List.hpp"

namespace ame{

template<class Input,class Control, class Output>
class Controller : public GameOn{
	public:
		Controller(){}
		Controller(Input* in, Control* ct, Output* ot){
			this->input_m = in;
			this->control_m = ct;
			this->output_m = ot;
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
		virtual bool instanceof(cppObjectClass* cls){
			return cls == Controller>::classType || GameOn::instanceof(cls);
		}
		
		//cppObject part
		virtual cppObjectClass* getClass(){
			return Class<Controller>::classType;
		}
		virtual String toString(){
			return "Controller";
		}
		virtual Controller<Input,Control,Output>* clone(){
			return new Controller(this->input_m, this->control_m, this->output_m);
		}
		
	protected:
		Input* input_m = nullptr;
		Control* control_m = nullptr;
		Output* output_m = nullptr;
};

#endif 

#endif 
