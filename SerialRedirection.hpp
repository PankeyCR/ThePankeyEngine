
#include "ame_Enviroment.hpp"

#if defined(DISABLE_SerialRedirection)
	#define SerialRedirection_hpp
#endif

#ifndef SerialRedirection_hpp
#define SerialRedirection_hpp
#define SerialRedirection_AVAILABLE

#ifndef ame_Enviroment_Defined

#endif

#ifdef ame_Windows

#endif

#ifdef ame_ArduinoIDE
	#include "Arduino.h"
#endif

#include "SerialListener.hpp"
#include "ObjectDataBaseConfig.hpp"
#include "ElementId.hpp"
#include "AppState.hpp"
#include "DefaultMonkeyFile.hpp"
#include "SerialMessageState.hpp"
#include "MonkeyExporter.hpp"
#include "MonkeyImporter.hpp"
#include "TextExporter.hpp"
#include "TextImporter.hpp"
#include "SerialListener.hpp"
#include "PrimitiveList.hpp"
#include "AlwaysConnected.hpp"
#include "MemoryRam.h"

#ifdef SerialRedirectionLogApp
	#include "Logger.hpp"
	#define SerialRedirectionLog(name,method,type,mns) Log(name,method,type,mns)
#else
	#define SerialRedirectionLog(name,method,type,mns)
#endif

namespace ame{

class SerialRedirection : public SerialListener{
    public:
		SerialRedirection(){
			SerialRedirectionLog("SerialRedirection", "Constructor",  "println", "");
		}
		
		virtual ~SerialRedirection(){
			SerialRedirectionLog("SerialRedirection", "Destructor",  "println", "");
		}
		
		virtual bool instanceof(cppObjectClass* cls){
			return cls == Class<SerialRedirection>::classType || SerialListener::instanceof(cls);
		}
		
		virtual cppObjectClass* getClass(){return Class<SerialRedirection>::classType;}
		
		virtual void execute(Message* message){
			Note name = message->name();
			for(int x = 0; x < redirectionNames.getPosition(); x++){
				Note o_port = *redirectionNames.getKeyByPosition(x);
				if(o_port == name){
					Note r_port = *redirectionNames.getByPosition(x);
					serialState->send(r_port, message->text());
				}
			}
		}
		
		virtual void redirect(Note o_port, Note r_port){
			redirectionNames.add(o_port, r_port);
		}
		
	protected:
		PrimitiveMap<Note,Note> redirectionNames;
};

}

#endif