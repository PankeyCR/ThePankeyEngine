

#ifndef LinearNetConfiguration_h
#define LinearNetConfiguration_h

#include "NetConfiguration.h"
#include "NetLayer.h"
#include "LinearNet.h"
#include "ArrayList.h"

class LinearNetConfiguration : public NetConfiguration {
	public:
		LinearNetConfiguration();
		virtual void addLayer(NetLayer *layer);
		virtual NetLayer *getLayer(int layer);
		virtual int getSize();
		virtual LinearNet* build();
    
	private:
		ArrayList<NetLayer,20> list;
};

#endif 
