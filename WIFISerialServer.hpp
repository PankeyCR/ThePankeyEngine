
#ifndef WIFISerialServer_hpp
	#define WIFISerialServer_hpp

	#include "SerialServer.hpp"
	#include "WIFISerialPort.hpp"

	#if pankey_Enviroment == pankey_Windows_Enviroment

	#endif

	#if pankey_IDE == pankey_Arduino_IDE
		#include "Arduino.h"
		#include "IPAddress.h"
	#endif

	#if pankey_Generic_Hardware == pankey_Generic_Esp8266_Hardware
		#include "WiFi.h"
	#endif

	#if pankey_Generic_Hardware == pankey_Generic_Esp32_Hardware
		#include "WiFi.h"
	#endif

	#ifdef WIFISerialServer_LogApp
		#include "pankey_Logger_config.hpp"
		#define WIFISerialServerLog(location,method,type,mns) pankey_Log((void*)this,location,"WIFISerialServer",method,type,mns)
	#else
		#define WIFISerialServerLog(location,method,type,mns)
	#endif
	
	namespace pankey{

	class WIFISerialServer : public SerialServer{	
		public:
			WIFISerialServer():server(80){
				WIFISerialServerLog(pankey_Log_StartMethod, "Contructor",  "println", "server(80)");
				WIFISerialServerLog(pankey_Log_EndMethod, "Contructor",  "println", "");
			}
			WIFISerialServer(int port):server(port){
				WIFISerialServerLog(pankey_Log_StartMethod, "Contructor",  "println", "server(port)");
				WIFISerialServerLog(pankey_Log_EndMethod, "Contructor",  "println", "");
			}
			WIFISerialServer(const WIFISerialServer& a_wifi_server){
				WIFISerialServerLog(pankey_Log_StartMethod, "Contructor",  "println", "server(port)");
				server = a_wifi_server.server;
				m_name = a_wifi_server.m_name;
				m_port = a_wifi_server.m_port;
				WIFISerialServerLog(pankey_Log_EndMethod, "Contructor",  "println", "");
			}
			
			virtual ~WIFISerialServer(){
				WIFISerialServerLog(pankey_Log_StartMethod, "Destructor",  "println", "");
				server.stop();
				WIFISerialServerLog(pankey_Log_EndMethod, "Destructor",  "println", "");
			}

			virtual void begin(){
				WIFISerialServerLog(pankey_Log_StartMethod, "Destructor",  "println", "");
				server.begin();
				WIFISerialServerLog(pankey_Log_EndMethod, "Destructor",  "println", "");
			}
			
			virtual void stop(){
				WIFISerialServerLog(pankey_Log_StartMethod, "Destructor",  "println", "");
				server.stop();
				WIFISerialServerLog(pankey_Log_EndMethod, "Destructor",  "println", "");
			}
			
			virtual obj<SerialPort> accept(){
				WIFISerialServerLog(pankey_Log_StartMethod, "accept",  "println", "");
				#if pankey_Generic_Hardware == pankey_Generic_Esp32_Hardware
					WIFISerialServerLog(pankey_Log_Statement, "accept",  "println", "pankey_GENERIC_ESP32");
					WiFiClient client = server.accept();   // Listen for incoming clients
					if(client){
						obj<SerialPort> i_port = WIFISerialPort(client,"ethernet");
						WIFISerialServerLog(pankey_Log_EndMethod, "accept",  "println", "if(client)");
						return i_port;
					}
				#endif 
				#if pankey_Generic_Hardware == pankey_Generic_Esp8266_Hardware
					WIFISerialServerLog(pankey_Log_Statement, "accept",  "println", "pankey_GENERIC_ESP8266");
					WiFiClient client = server.available();
					if(client){
						obj<SerialPort> i_port = WIFISerialPort(client,"ethernet");
						WIFISerialServerLog(pankey_Log_EndMethod, "accept",  "println", "if(client)");
						return i_port;
					}
				#endif 
				WIFISerialServerLog(pankey_Log_EndMethod, "accept",  "println", "return nullptr");
				return nullptr;
			} 
			
			virtual obj<SerialPort> available(){
				WIFISerialServerLog(pankey_Log_StartMethod, "available",  "println", "");
				WiFiClient client = server.available();   // Listen for incoming clients
				if(client){
					obj<SerialPort> i_port = WIFISerialPort(client,"ethernet");
					WIFISerialServerLog(pankey_Log_EndMethod, "available",  "println", "if(client)");
					return i_port;
				}
				WIFISerialServerLog(pankey_Log_EndMethod, "accept",  "println", "return nullptr");
				return nullptr;
			}
			
			virtual WiFiServer getServer(){
				return server;
			}
			
			virtual void operator=(const WIFISerialServer& a_wifi_server){
				WIFISerialServerLog(pankey_Log_StartMethod, "operator=",  "println", "server(port)");
				server = a_wifi_server.server;
				m_name = a_wifi_server.m_name;
				m_port = a_wifi_server.m_port;
				WIFISerialServerLog(pankey_Log_EndMethod, "operator=",  "println", "");
			}

		protected:
			WiFiServer server;
	};

	}

#endif