

#ifndef CodeRoute_h
#define CodeRoute_h

#include "Arduino.h"

class CodeRoute{
    public:
		CodeRoute();
		virtual ~CodeRoute();
		
		bool block(int v);
		bool update(int v);
	protected:
		int bVersion = -1;
		
		int uVersion = -1;
};

#endif 
