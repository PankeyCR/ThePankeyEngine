#ifndef DefaultNeuron_h
#define DefaultNeuron_h

#include "List.h"
#include "PrimitiveList.h"
#include "DataSet.h"
#include "NetNeuron.h"

class DefaultNeuron : public NetNeuron<float>{
	public:
		DefaultNeuron();
		virtual ~DefaultNeuron();
		
		virtual bool initialize();
		virtual DataSet<float> *compute(DataSet<float> *data);
		
		//cppObject part
		virtual String getClassName();
		virtual String toString();
		virtual DefaultNeuron *clone();
    
	protected:
	
};

#endif