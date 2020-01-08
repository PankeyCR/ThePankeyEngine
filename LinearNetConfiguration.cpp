
#ifndef LinearNetConfiguration_cpp
#define LinearNetConfiguration_cpp

#include "LinearNetConfiguration.h"

	LinearNetConfiguration::LinearNetConfiguration(){
		
	}
	
	void LinearNetConfiguration::addLayer(NetLayer *layer){
		list.add(layer);
	}
	
	NetLayer *LinearNetConfiguration::getLayer(int layer){
		if(list.getByPos(layer) == NULL){
			return NULL;
		}
		return list.getByPos(layer);
	}
	
	int LinearNetConfiguration::getSize(){
		return list.getSize();
	}
	
	LinearNet* LinearNetConfiguration::build(){
		LinearNet* net = new LinearNet();
		
		return net;
	}
	
#endif 
