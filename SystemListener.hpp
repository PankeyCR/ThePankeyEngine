
#include "ame_Enviroment.hpp"

#if defined(DISABLE_SystemListener)
	#define SystemListener_hpp
#endif

#ifndef SystemListener_hpp
#define SystemListener_hpp
#define SystemListener_AVAILABLE

#ifndef ame_Enviroment_Defined

#endif

#ifdef ame_Windows

#endif

#ifdef ame_ArduinoIDE
	#include "Arduino.h"
#endif

#include "SerialListener.hpp"
#include "ElementId.hpp"
#include "AppState.hpp"
#include "SerialState.hpp"
#include "MonkeyExporter.hpp"
#include "MonkeyImporter.hpp"
#include "TextExporter.hpp"
#include "TextImporter.hpp"
#include "ame_WIFI.hpp"
#include "MemoryRam.h"

#ifdef SystemListener_LogApp
	#include "ame_Logger_config.hpp"
	#include "ame_Logger.hpp"
	#include "MemoryRam.h"
	
	#define SystemListenerLog(location,method,type,mns) ame_Log(this,location,"SystemListener",method,type,mns)
	#define const_SystemListenerLog(location,method,type,mns) 
	#define StaticSystemListenerLog(pointer,location,method,type,mns) ame_Log(pointer,location,"SystemListener",method,type,mns)
#else
	#ifdef SystemListener_LogDebugApp
		#include "ame_Logger_config.hpp"
		#include "ame_Logger.hpp"
		#include "MemoryRam.h"
		
		#define SystemListenerLog(location,method,type,mns) ame_LogDebug(this,location,"SystemListener",method,type)
		#define const_SystemListenerLog(location,method,type,mns) 
		#define StaticSystemListenerLog(pointer,location,method,type,mns) ame_LogDebug(pointer,location,"SystemListener",method,type)
	#else
		#define SystemListenerLog(location,method,type,mns) 
		#define const_SystemListenerLog(location,method,type,mns) 
		#define StaticSystemListenerLog(pointer,location,method,type,mns) 
	#endif
#endif

namespace ame{

class SystemListener : public SerialListener{
    public:
		SystemListener(){
			SystemListenerLog(ame_Log_Statement, "Constructor",  "println", "");
		}
		
		virtual ~SystemListener(){
			SystemListenerLog(ame_Log_Statement, "Destructor",  "println", "");
		}
		
		virtual bool instanceof(cppObjectClass* cls){
			return cls == Class<SystemListener>::classType;
		}
		
		virtual cppObjectClass* getClass(){return Class<SystemListener>::classType;}
		
		virtual void execute(Message* message){
			SystemListenerLog(ame_Log_Statement, "execute",  "println", "start execute");
			SystemListenerLog(ame_Log_Statement, "execute",  "println", message->text());
			
			Note txt = message->text();
			
			if(txt == "printRam"){
				Serial.println(Note("ram ") + Note(getRamSize()));
			}
			
			TextImporter importer = message->text();
			
			SystemListenerLog(ame_Log_Statement, "execute",  "println", "serialState == nullptr");
			TextExporter exporter;
			
			if(txt == "sendRam"){
				exporter.write("MemoryRam", getRamSize());
				serialState->send(exporter.getText());
			}
			
			bool printRam = importer.read(ElementId("print.ram"), false);
			bool printPort = importer.read(ElementId("print.port"), false);
			
			if(printRam){
				SystemListenerLog(ame_Log_Statement, "execute",  "println", "!printRam");
				if(printPort){
					SystemListenerLog(ame_Log_Statement, "execute",  "println", "printPort");
					exporter.write("MemoryRam", getRamSize());
					serialState->send(message->id(), exporter.getText());
				}else{
					SystemListenerLog(ame_Log_Statement, "execute",  "println", "!printPort");
					exporter.write("MemoryRam", getRamSize());
					serialState->send(exporter.getText());
				}
			}
			
			Note myName = importer.read(ElementId("MyNameIs"), Note());
			if(myName != ""){
				SerialPort* port = serialState->getSerialPort(message->id());
				if(port != nullptr){
					port->setName(myName);
				}
			}
			
			bool printPorts = importer.read(ElementId("print.ports"), false);
			if(printPorts){
				List<SerialPort>* ports = serialState->getSerialPorts();
				for(int x = 0; x < ports->getPosition(); x++){
					SerialPort* port = ports->getByPosition(x);
					exporter.write(ElementId(Note("PortName.") + Note(x)), port->getName());
				}
			
				if(printPort){
					serialState->send(message->id(), exporter.getText());
				}else{
					serialState->send(exporter.getText());
				}
			}
			
			bool request_connection = importer.read(ElementId("System.request.connection.status"), false);
			Note port_name = importer.read(ElementId("System.port.name"), "");
			
			if(request_connection){
				exporter.write("System.status.connection", true);
				if(port_name == ""){
					serialState->send(exporter.getText());
				}else{
					serialState->send(port_name, exporter.getText());
				}
			}
			
			if(importer.read(ElementId("System.status.connection"), false)){
				exporter.write("System.result.connection", true);
				if(port_name == ""){
					serialState->send(exporter.getText());
				}else{
					serialState->send(port_name, exporter.getText());
				}
			}
		
			if(importer.read("System.request.hasLAN", false)){
				exporter.write("System.response.hasLAN", hasLAN());
				if(port_name == ""){
					serialState->send(exporter.getText());
				}else{
					serialState->send(port_name, exporter.getText());
				}
			}
		}
	protected:
	
};

}

#endif