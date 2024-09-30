
#ifndef pankey_Stream_hpp
    #define pankey_Stream_hpp

	#include "pankey_Enviroment.hpp"
	#include "pankey_Enviroment_config.hpp"

    #include "pankey_String.hpp"

    #ifdef pankey_Windows
        #include <string.h>
        #include "pankey_Print.hpp"
    #endif

    #ifdef pankey_ArduinoIDE
        #include "Print.h"
    #endif

    namespace pankey{

        class Stream : public Print{
            public:
                Stream() {}
                virtual ~Stream() {}
                
                virtual int available() = 0;
                virtual int read() = 0;
                virtual int peek() = 0;
        };

    }

#endif
