#ifndef Net_h
#define Net_h

#include "NetSet.h"

class Net {
	public:
		virtual void fit(NetSet *set);
		virtual void fit();
		virtual void setInput(NetSet *set);
		virtual NetSet *getOutput();
	private:
};

#endif