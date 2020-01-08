#ifndef NetNeuron_h
#define NetNeuron_h

#include "List.h"
#include "DataSet.h"
#include "Neuron.h"
#include "Funtion.h"

template<class... arr>
class NetNeuron : public Neuron<float>{
	public:
		NetNeuron();
		virtual ~NetNeuron();
		virtual void setWeight(int index, float weightValue);
		virtual float getWeight(int id);
		
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
		
		virtual Neuron<float> *setFuntion(Funtion<arr...> *a);
		virtual Funtion<arr...> *getFuntion();
    
	protected:
		List<Neuron<float>> *neuronList = nullptr;
		List<float> *weightList = nullptr;
		Funtion<arr...> *funtion = nullptr;
};

#endif