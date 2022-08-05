
#include "ame_Enviroment.hpp"

#if defined(DISABLE_DataBaseConfig)
	#define DataBaseConfig_hpp
#endif

#ifndef DataBaseConfig_hpp
#define DataBaseConfig_hpp
#define DataBaseConfig_AVAILABLE

#ifndef ame_Enviroment_Defined

#endif

#ifdef ame_Windows

#endif

#ifdef ame_ArduinoIDE
	#include "Arduino.h"
#endif

#include "MonkeyFile.hpp"
#include "SerialMessageState.hpp"
#include "MonkeyExporter.hpp"
#include "MonkeyImporter.hpp"

#ifdef DataBaseConfigLogApp
	#include "Logger.hpp"
	#define DataBaseConfigLog(name,method,type,mns) Log(name,method,type,mns)
#else
	#define DataBaseConfigLog(name,method,type,mns)
#endif

namespace ame{

class DataBaseConfig{
    public:
		virtual ~DataBaseConfig(){}
		virtual void initialize(MonkeyExporter* exporter, MonkeyImporter* importer, MonkeyFile* file, SerialMessageState* serialState){}
		virtual void put(MonkeyExporter* exporter, MonkeyImporter* importer, MonkeyFile* file, SerialMessageState* serialState){}
		virtual void get(MonkeyExporter* exporter, MonkeyImporter* importer, MonkeyFile* file, SerialMessageState* serialState){}
		virtual void erase(MonkeyExporter* exporter, MonkeyImporter* importer, MonkeyFile* file, SerialMessageState* serialState){}
		virtual void copy(MonkeyExporter* exporter, MonkeyImporter* importer, MonkeyFile* file, SerialMessageState* serialState){}
		virtual void cut(MonkeyExporter* exporter, MonkeyImporter* importer, MonkeyFile* file, SerialMessageState* serialState){}
		virtual void update(float tpc){}
		virtual void setFileSize(int s){}
		
		virtual void operator=(DataBaseConfig db){}
		virtual bool operator==(DataBaseConfig db){return false;}
		virtual bool operator!=(DataBaseConfig db){return false;}
};

}

#endif