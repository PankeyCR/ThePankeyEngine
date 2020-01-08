#ifndef LinearNet_h
#define LinearNet_h

#include "Net.h"
#include "NetSet.h"

class LinearNet : public Net{
	public:
		virtual void fit(NetSet *set);
		virtual void setInput(NetSet *set);
		virtual NetSet *getOutput();
	private:
};

#endif