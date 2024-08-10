
#ifndef Neuron_hpp
	#define Neuron_hpp

	namespace higgs{

		class Neuron{
			public:
			
			Neuron(){}
			virtual ~Neuron(){}
			
			float weight = 1;
			float data = 1;
		};

	}

#endif