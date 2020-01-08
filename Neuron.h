#ifndef Neuron_h
#define Neuron_h

#include "List.h"
#include "DataSet.h"
#include "cppObject.h"

template<class dataset>
class Neuron : public cppObject{
	public:
		Neuron();
		virtual ~Neuron();
		virtual void setWeight(int index, float weightValue);
		virtual float getWeight(int index);
		
		virtual Neuron<dataset> *connect(Neuron<dataset> *neuron);
		virtual Neuron<dataset> *getNeuron(int index);
		virtual Neuron<dataset> *removeNeuron(int index);
		virtual List<Neuron<dataset>> *getNeurons();
		
		virtual bool initialize();
		virtual DataSet<dataset> *compute(DataSet<dataset> *data);
		
		//cppObject part
		virtual String getClassName();
		virtual String toString();
		virtual bool equal(cppObject *b);
		virtual Neuron<dataset> *clone();
		
		virtual Neuron<dataset> operator=(Neuron<dataset> b);
		virtual bool operator==(Neuron<dataset> b);
		virtual bool operator!=(Neuron<dataset> b);
    
	protected:
	
};

#endif