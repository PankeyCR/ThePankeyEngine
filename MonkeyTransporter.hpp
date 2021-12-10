
#ifndef MonkeyTransporter_hpp
#define MonkeyTransporter_hpp

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
