
#include "ame_Enviroment.hpp"

#if defined(DISABLE_MonkeyTransporter)
	#define MonkeyTransporter_hpp
#endif

#ifndef MonkeyTransporter_hpp
#define MonkeyTransporter_hpp
#define MonkeyTransporter_AVAILABLE

#ifndef ame_Enviroment_Defined

#endif

#ifdef ame_Windows

#endif

#ifdef ame_ArduinoIDE
	#include "Arduino.h"
#endif

#include "ElementId.hpp"
#include "MonkeyExporter.hpp"
#include "MonkeyImporter.hpp"

namespace ame{

class MonkeyTransporter{
    public:
		MonkeyTransporter(){}
		virtual ~MonkeyTransporter(){}
    	virtual void write(ElementId id, MonkeyExporter* exporter){}
    	virtual void read(ElementId id, MonkeyImporter* importer){}
	protected:	
};

}

#endif