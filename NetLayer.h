

#ifndef NetLayer_h
#define NetLayer_h

#include "List.h"
#include "NetNeuron.h"
#include "cppObject.h"

class NetLayer : public cppObject{
	public:
		NetLayer();
		virtual void inputs(int in);
		virtual void outputs(int out);
		virtual int inputs();
		virtual int outputs();
		
		virtual void addInputNetNeuron(NetNeuron<float> *neuron);
		virtual NetNeuron<float> *getInputNetNeuron(int index);
		virtual List<NetNeuron<float>> *getInputNetNeurons();
		
		virtual void addOutputNetNeuron(NetNeuron<float> *neuron);
		virtual NetNeuron<float> *getOutputNetNeuron(int index);
		virtual List<NetNeuron<float>> *getOutputNetNeurons();
		
		virtual void initialize();
		virtual void compute();
		
		//cppObject part
		virtual String getClassName();
		virtual String toString();
		virtual bool equal(cppObject *b);
		virtual NetLayer *clone();
		
		virtual NetLayer operator=(NetLayer& b);
		virtual bool operator==(NetLayer& b);
		virtual bool operator!=(NetLayer& b);
    
	protected:
		int inp = 0;
		int outp = 0;
};

#endif