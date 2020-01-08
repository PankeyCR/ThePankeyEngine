

#ifndef NetConfiguration_h
#define NetConfiguration_h

#include "GameBuilder.h"
#include "NetLayer.h"
#include "Net.h"

class NetConfiguration : public GameBuilder<Net> {
	public:
		virtual void addLayer(NetLayer *layer);
		virtual NetLayer *getLayer(int layer);
		virtual int getSize();
    
	private:
};

#endif 
