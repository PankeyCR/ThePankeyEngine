
#ifndef DefaultPortProtocol_hpp
	#define DefaultPortProtocol_hpp

	#include "pankey_Enviroment.hpp"

	#ifndef pankey_Enviroment_Defined

	#endif

	#ifdef pankey_Windows

	#endif

	#ifdef pankey_ArduinoIDE
		#include "Arduino.h"
	#endif

	#include "PortProtocol.hpp"
	#include "SerialPort.hpp"
	#include "Note.hpp"

	#ifdef DefaultPortProtocol_LogApp
		#include "pankey_Logger_config.hpp"
		#define DefaultPortProtocolLog(location,method,type,mns) pankey_Log((void*)this,location,"DefaultPortProtocol",method,type,mns)
	#else
		#define DefaultPortProtocolLog(location,method,type,mns)
	#endif

	namespace pankey{

		class DefaultPortProtocol : public PortProtocol{	
			public:
				DefaultPortProtocol(){
					DefaultPortProtocolLog(pankey_Log_StartMethod, "Constructor",  "println", "");
					DefaultPortProtocolLog(pankey_Log_EndMethod, "Constructor",  "println", "");
				}
				virtual ~DefaultPortProtocol(){
					DefaultPortProtocolLog(pankey_Log_StartMethod, "Destructor",  "println", "");
					DefaultPortProtocolLog(pankey_Log_EndMethod, "Destructor",  "println", "");
				}
				
				virtual void InstantBroadcastMessage(obj<SerialPort> a_port, Note a_message){
					DefaultPortProtocolLog(pankey_Log_StartMethod, "InstantBroadcastMessage",  "println", "");
					DefaultPortProtocolLog(pankey_Log_Statement, "InstantBroadcastMessage",  "println", (a_port.isNull()) ? a_port->getName() : "port is null");
					DefaultPortProtocolLog(pankey_Log_Statement, "InstantBroadcastMessage",  "println", a_message);
					a_port->print(a_message+'\n');
					DefaultPortProtocolLog(pankey_Log_EndMethod, "InstantBroadcastMessage",  "println", "");
				}
				
				virtual void InstantPrivateMessage(obj<SerialPort> a_port, Note a_message){
					DefaultPortProtocolLog(pankey_Log_StartMethod, "InstantPrivateMessage",  "println", (a_port.isNull()) ? a_port->getName() : "port is null");
					DefaultPortProtocolLog(pankey_Log_Statement, "InstantPrivateMessage",  "println", a_message);
					a_port->print(a_message+'\n');
					DefaultPortProtocolLog(pankey_Log_EndMethod, "InstantPrivateMessage",  "println", "");
				}
				
				virtual void BroadcastMessage(obj<SerialPort> a_port, Note a_message){
					DefaultPortProtocolLog(pankey_Log_StartMethod, "BroadcastMessage",  "println", (a_port.isNull()) ? a_port->getName() : "port is null");
					DefaultPortProtocolLog(pankey_Log_Statement, "BroadcastMessage",  "println", a_message);
					a_port->print(a_message+'\n');
					DefaultPortProtocolLog(pankey_Log_EndMethod, "BroadcastMessage",  "println", "");
				}
				
				virtual void PrivateMessage(obj<SerialPort> a_port, Note a_message){
					DefaultPortProtocolLog(pankey_Log_StartMethod, "PrivateMessage",  "println", (a_port.isNull()) ? a_port->getName() : "port is null");
					DefaultPortProtocolLog(pankey_Log_Statement, "PrivateMessage",  "println", a_message);
					a_port->print(a_message+'\n');
					DefaultPortProtocolLog(pankey_Log_EndMethod, "PrivateMessage",  "println", "");
				}
				
				virtual bool GlobalConect(obj<SerialPort> a_port){
					DefaultPortProtocolLog(pankey_Log_StartMethod, "GlobalConect",  "println", "");
					DefaultPortProtocolLog(pankey_Log_EndMethod, "GlobalConect",  "println", "");
					return false;
				}
				virtual bool Conect(obj<SerialPort> a_port){
					DefaultPortProtocolLog(pankey_Log_StartMethod, "Conect",  "println", "");
					DefaultPortProtocolLog(pankey_Log_EndMethod, "Conect",  "println", "");
					return true;
				}
				virtual bool UpdateConect(obj<SerialPort> a_port){
					DefaultPortProtocolLog(pankey_Log_StartMethod, "UpdateConect",  "println", "");
					DefaultPortProtocolLog(pankey_Log_EndMethod, "UpdateConect",  "println", "");
					return true;
				}
				
				virtual bool GlobalDisconect(obj<SerialPort> a_port){
					DefaultPortProtocolLog(pankey_Log_StartMethod, "GlobalDisconect",  "println", "");
					a_port->flush();
					a_port->stop();
					DefaultPortProtocolLog(pankey_Log_EndMethod, "GlobalDisconect",  "println", "");
					return true;
				}
				virtual bool Disconect(obj<SerialPort> a_port){
					DefaultPortProtocolLog(pankey_Log_StartMethod, "Disconect",  "println", "");
					a_port->flush();
					a_port->stop();
					DefaultPortProtocolLog(pankey_Log_EndMethod, "Disconect",  "println", "");
					return true;
				}
				virtual bool UpdateDisconect(obj<SerialPort> a_port){
					DefaultPortProtocolLog(pankey_Log_StartMethod, "UpdateDisconect",  "println", "");
					a_port->flush();
					a_port->stop();
					DefaultPortProtocolLog(pankey_Log_EndMethod, "UpdateDisconect",  "println", "");
					return true;
				}
				
				Note Read(obj<SerialPort> a_port){
					char i_char = a_port->read();
					if((i_char == '\n') && messageText.length() != 0){
						DefaultPortProtocolLog(pankey_Log_Statement, "Read",  "println", "adding Message to serialState");
						DefaultPortProtocolLog(pankey_Log_Statement, "Read",  "println", Note("messageText: ") + messageText);
						Note i_delivery = messageText;
						messageText = "";
						return i_delivery;
					}
					if(i_char != '\r' && i_char != '\n'){
						DefaultPortProtocolLog(pankey_Log_Statement, "Read",  "println", Note("adding char to messageText: ") + Note(i_char));
						messageText.addLocalValue(i_char);
					
					}
					return Note();
				}
				
			protected:
				Note messageText = "";
		};

	}

#endif