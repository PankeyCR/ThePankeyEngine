
#ifndef SystemListener_hpp
#define SystemListener_hpp

#include "SerialListener.hpp"
#include "ElementId.hpp"
#include "AppState.hpp"
#include "SerialMessageState.hpp"
#include "MonkeyExporter.hpp"
#include "MonkeyImporter.hpp"
#include "TextExporter.hpp"
#include "TextImporter.hpp"
#include "MemoryRam.hpp"

#ifdef SystemListenerLogApp
	#include "Logger.hpp"
	#define SystemListenerLog(name,method,type,mns) Log(name,method,type,mns)
#else
	#define SystemListenerLog(name,method,type,mns)
#endif

namespace ame{

class SystemListener : public SerialListener{
    public:
		SystemListener(){
			SystemListenerLog("SystemListener", "Constructor",  "println", "");
		}
		
		SystemListener(Application* a){
			SystemListenerLog("SystemListener", "Constructor",  "println", "");
			app = a;
		}
		
		virtual ~SystemListener(){
			SystemListenerLog("SystemListener", "Destructor",  "println", "");
		}
		
		virtual bool instanceof(cppObjectClass* cls){
			return cls == Class<SystemListener>::classType;
		}
		
		virtual cppObjectClass* getClass(){return Class<SystemListener>::classType;}
		
		virtual void execute(Message* message){
			SystemListenerLog("SystemListener", "execute",  "println", "start execute");
			SystemListenerLog("SystemListener", "execute",  "println", message->text());
			
			String txt = message->text();
			
			if(txt == "printRam"){
				Serial.println(String("ram ") + String(getRamSize()));
			}
			
			if(app == nullptr){
				SystemListenerLog("SystemListener", "execute",  "println", "app == nullptr");
				return;
			}
			
			TextImporter importer = message->text();
			
			SerialMessageState* serialState = (SerialMessageState*)app->getStateManager()->get(Class<SerialMessageState>::classType);
			if(serialState != nullptr){
				SystemListenerLog("SystemListener", "execute",  "println", "serialState == nullptr");
				TextExporter exporter;
				
				if(txt == "sendRam"){
					exporter.write("MemoryRam", getRamSize());
					serialState->send(exporter.getText());
				}
				
				bool printRam = importer.read(ElementId("print.ram"), false);
				bool printPort = importer.read(ElementId("print.port"), false);
				
				if(printRam){
					SystemListenerLog("SystemListener", "execute",  "println", "!printRam");
					if(printPort){
						SystemListenerLog("SystemListener", "execute",  "println", "printPort");
						exporter.write("MemoryRam", getRamSize());
						serialState->send(message->id(), exporter.getText());
					}else{
						SystemListenerLog("SystemListener", "execute",  "println", "!printPort");
						exporter.write("MemoryRam", getRamSize());
						serialState->send(exporter.getText());
					}
				}
				
				String myName = importer.read(ElementId("MyNameIs"), String());
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
						exporter.write(ElementId(String("PortName.") + String(x)), port->getName());
					}
				
					if(printPort){
						serialState->send(message->id(), exporter.getText());
					}else{
						serialState->send(exporter.getText());
					}
				}
			}
			
		}
	protected:
		Application* app = nullptr;
};

}

#endif 

