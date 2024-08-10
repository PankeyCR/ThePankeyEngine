
#ifndef higgs_Stream_hpp
#define higgs_Stream_hpp

//#include "higgs_Streamable.hpp"
#include "higgs_String.hpp"

#ifdef higgs_Windows
	#include <string.h>
	#include "higgs_Print.hpp"
#endif

#ifdef higgs_ArduinoIDE
	#include "Print.h"
#endif

class Stream : public Print{
    public:
        Stream() {}
        virtual ~Stream() {}
		
        virtual int available() = 0;
        virtual int read() = 0;
        virtual int peek() = 0;
};

#endif
