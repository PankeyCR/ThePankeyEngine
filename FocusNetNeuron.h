#ifndef FocusNetNeuron_h
#define FocusNetNeuron_h

#include "NetNeuron.h"

class FocusNetNeuron{
	public:
		FocusNetNeuron();
		~FocusNetNeuron();
		virtual NetNeuron<float> *getActualNeuron();
		virtual NetNeuron<float> *getFocusNeuron();
		virtual NetNeuron<float> *getLastNeuron();
		virtual NetNeuron<float> *getNextNeuron();
		virtual NetNeuron<float> *getStarNeuron();	
		virtual NetNeuron<float> *getNovaNeuron();
		virtual NetNeuron<float> *getBlackHoleNeuron();			
	private:
		NetNeuron<float> *actualNeuron = NULL;
		NetNeuron<float> *focusNeuron = NULL;
		NetNeuron<float> *lastNeuron = NULL;
		NetNeuron<float> *nextNeuron = NULL;
		NetNeuron<float> *starNeuron = NULL;
		NetNeuron<float> *novaNeuron = NULL;
		NetNeuron<float> *bhNeuron = NULL;
};

#endif