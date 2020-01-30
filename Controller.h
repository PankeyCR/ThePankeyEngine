

#ifndef Controller_h
#define Controller_h

#include "Arduino.h"
#include "cppObject.h"
#include "Map.h"
#include "List.h"
#include "Controlling.h"

template<class InputSource,class ControlSource, class OutputSource>
class Controller : public cppObject{
	public:
		Controller();
		virtual ~Controller();
		
		virtual Controller<InputSource,ControlSource,OutputSource>* setup(Controlling ctl);
		
		virtual Controller<InputSource,ControlSource,OutputSource>* input(InputSource* in);
		virtual Controller<InputSource,ControlSource,OutputSource>* control(ControlSource* ct);
		virtual Controller<InputSource,ControlSource,OutputSource>* output(OutputSource* ot);
		
		// virtual Controller<InputSource,ControlSource,OutputSource>* input(InputSource in);
		// virtual Controller<InputSource,ControlSource,OutputSource>* control(ControlSource ct);
		// virtual Controller<InputSource,ControlSource,OutputSource>* output(OutputSource ot);
		
		virtual InputSource* input();
		virtual ControlSource* control();
		virtual OutputSource* output();
		//virtual OutputSource outputValue();
		
		virtual void update(float tpf);
		
		//cppObject part
		virtual String getClassName();
		virtual String toString();
		virtual Controller<InputSource,ControlSource,OutputSource>* clone();
		
		virtual void operator=(const Controller& b);
		virtual bool operator==(const Controller& b);
		virtual bool operator!=(const Controller& b);
		
	protected:
		InputSource* inputm = nullptr;
		ControlSource* controlm = nullptr;
		OutputSource* outputm = nullptr;
		Controlling controlling = Controlling::Default;
		
};

#endif 
