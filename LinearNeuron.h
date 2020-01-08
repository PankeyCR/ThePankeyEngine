#ifndef LinearNeuron_h
#define LinearNeuron_h

#include "List.h"
#include "PList.h"
#include "DataSet.h"
#include "Neuron.h"

class LinearNeuron : public Neuron<float>{
	public:
		LinearNeuron();
		virtual ~LinearNeuron();
		virtual Neuron<float> *connect(Neuron<float> *neuron);
		virtual Neuron<float> *getNeuron(int id);
		virtual Neuron<float> *removeNeuron(int id);
		virtual List<Neuron<float>> *getNeurons();
		
		virtual bool initialize();
		virtual DataSet<float> *compute(DataSet<float> *data);
		
		//cppObject part
		virtual String getClassName();
		virtual String toString();
		virtual bool equal(cppObject *b);
		virtual Neuron<float> *clone();
    
	private:
	
	protected:
		PList<Neuron<float>,2> Netmap;
};

#endif