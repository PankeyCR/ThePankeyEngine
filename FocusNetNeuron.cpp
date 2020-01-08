#ifndef FocusNetNeuron_cpp
#define FocusNetNeuron_cpp

#include "FocusNetNeuron.h"

	FocusNetNeuron::FocusNetNeuron(){
	}
	
	FocusNetNeuron::~FocusNetNeuron(){
	}
	
	NetNeuron<float> *FocusNetNeuron::getActualNeuron(){
		return actualNeuron;
	}
	
	NetNeuron<float> *FocusNetNeuron::getFocusNeuron(){
		return focusNeuron;
	}
	
	NetNeuron<float> *FocusNetNeuron::getLastNeuron(){
		return lastNeuron;
	}
	
	NetNeuron<float> *FocusNetNeuron::getNextNeuron(){
		return nextNeuron;
	}
	
	NetNeuron<float> *FocusNetNeuron::getStarNeuron(){
		return starNeuron;
	}
	
	NetNeuron<float> *FocusNetNeuron::getNovaNeuron(){
		return novaNeuron;
	}
	
	NetNeuron<float> *FocusNetNeuron::getBlackHoleNeuron(){
		return bhNeuron;
	}
#endif