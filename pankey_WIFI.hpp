
#ifndef pankey_WIFI_hpp
	#define pankey_WIFI_hpp

	#include "Note.hpp"
	#include "NoteHelper.hpp"
	#include "PrimitiveRawList.hpp"

	#ifndef pankey_Enviroment_Defined

	#endif

	#ifdef pankey_Windows

	#endif

	#ifdef pankey_ArduinoIDE
		#include "Arduino.h"
	#endif

	#if defined(ARDUINO_ARCH_ESP8266)
		#include "WiFi.h"
	#elif defined(ARDUINO_ARCH_ESP32)
		#include "WiFi.h"
		#include <esp_wifi.h>
	#endif

	#ifdef pankey_WIFI_LogApp
		#include "pankey_Logger.hpp"
		#define pankey_WIFILog(location,method,type,mns) pankey_Log(nullptr,location,"pankey_WIFI",method,type,mns)
	#else
		#define pankey_WIFILog(location,method,type,mns)
	#endif

	namespace pankey{
		
		//void initializeWIFI(Note a_ip, Note a_gateway, Note a_subnet, Note a_dns, uint8_t* a_mac, const char* name, const char* pasword);

		#ifdef pankey_ArduinoIDE

			void initializeWIFI(Note a_mac, Note a_ip, Note a_gateway, Note a_subnet, Note a_dns, Note a_name, Note a_pasword){
				pankey_WIFILog(pankey_Log_StartMethod, "initializeWIFI",  "println", "");

				pankey_WIFILog(pankey_Log_Statement, "initializeWIFI",  "println", "mac");
				pankey_WIFILog(pankey_Log_Statement, "initializeWIFI",  "println", a_mac);
				pankey_WIFILog(pankey_Log_Statement, "initializeWIFI",  "println", "ip");
				pankey_WIFILog(pankey_Log_Statement, "initializeWIFI",  "println", a_ip);
				pankey_WIFILog(pankey_Log_Statement, "initializeWIFI",  "println", "gateway");
				pankey_WIFILog(pankey_Log_Statement, "initializeWIFI",  "println", a_gateway);
				pankey_WIFILog(pankey_Log_Statement, "initializeWIFI",  "println", "subnet");
				pankey_WIFILog(pankey_Log_Statement, "initializeWIFI",  "println", a_subnet);
				pankey_WIFILog(pankey_Log_Statement, "initializeWIFI",  "println", "dns");
				pankey_WIFILog(pankey_Log_Statement, "initializeWIFI",  "println", a_dns);
				pankey_WIFILog(pankey_Log_Statement, "initializeWIFI",  "println", "name");
				pankey_WIFILog(pankey_Log_Statement, "initializeWIFI",  "println", a_name);
				pankey_WIFILog(pankey_Log_Statement, "initializeWIFI",  "println", "pasword");
				pankey_WIFILog(pankey_Log_Statement, "initializeWIFI",  "println", a_pasword);

				Array<uint8_t> i_mac = toMAC(a_mac);
				IPAddress i_ip = toIPAddress(a_ip);
				IPAddress i_gateway = toIPAddress(a_gateway);
				IPAddress i_subnet = toIPAddress(a_subnet);
				IPAddress i_dns = toIPAddress(a_dns);

				pankey_WIFILog(pankey_Log_Statement, "initializeWIFI",  "println", "ip");
				pankey_WIFILog(pankey_Log_Statement, "initializeWIFI",  "println", i_ip);
				pankey_WIFILog(pankey_Log_Statement, "initializeWIFI",  "println", "gateway");
				pankey_WIFILog(pankey_Log_Statement, "initializeWIFI",  "println", i_gateway);
				pankey_WIFILog(pankey_Log_Statement, "initializeWIFI",  "println", "subnet");
				pankey_WIFILog(pankey_Log_Statement, "initializeWIFI",  "println", i_subnet);
				pankey_WIFILog(pankey_Log_Statement, "initializeWIFI",  "println", "dns");
				pankey_WIFILog(pankey_Log_Statement, "initializeWIFI",  "println", i_dns);
				
				WiFi.mode(WIFI_STA);
				WiFi.setSleep(false);
				
				esp_wifi_set_mac(WIFI_IF_STA, i_mac.pointer());

				if(!WiFi.config(i_ip, i_gateway, i_subnet, i_dns)) {
					pankey_WIFILog(pankey_Log_Statement, "initializeWIFI",  "println", "STA Failed to configure");
				}

				WiFi.begin(a_name.pointer(), a_pasword.pointer());

				if(WiFi.status() == WL_CONNECTED) {
					pankey_WIFILog(pankey_Log_Statement, "initializeWIFI",  "println", "connected");
				}else{
					pankey_WIFILog(pankey_Log_Statement, "initializeWIFI",  "println", "fail to connect");
				}

				pankey_WIFILog(pankey_Log_EndMethod, "initializeWIFI",  "println", "");
			}

			void configWIFI(Note a_mac, Note a_ip, Note a_gateway, Note a_subnet, Note a_dns){
				pankey_WIFILog(pankey_Log_StartMethod, "configWIFI",  "println", "");

				pankey_WIFILog(pankey_Log_Statement, "configWIFI",  "println", "mac");
				pankey_WIFILog(pankey_Log_Statement, "configWIFI",  "println", a_mac);
				pankey_WIFILog(pankey_Log_Statement, "configWIFI",  "println", "ip");
				pankey_WIFILog(pankey_Log_Statement, "configWIFI",  "println", a_ip);
				pankey_WIFILog(pankey_Log_Statement, "configWIFI",  "println", "gateway");
				pankey_WIFILog(pankey_Log_Statement, "configWIFI",  "println", a_gateway);
				pankey_WIFILog(pankey_Log_Statement, "configWIFI",  "println", "subnet");
				pankey_WIFILog(pankey_Log_Statement, "configWIFI",  "println", a_subnet);
				pankey_WIFILog(pankey_Log_Statement, "configWIFI",  "println", "dns");
				pankey_WIFILog(pankey_Log_Statement, "configWIFI",  "println", a_dns);

				Array<uint8_t> i_mac = toMAC(a_mac);
				IPAddress i_ip = toIPAddress(a_ip);
				IPAddress i_gateway = toIPAddress(a_gateway);
				IPAddress i_subnet = toIPAddress(a_subnet);
				IPAddress i_dns = toIPAddress(a_dns);

				pankey_WIFILog(pankey_Log_Statement, "configWIFI",  "println", "ip");
				pankey_WIFILog(pankey_Log_Statement, "configWIFI",  "println", i_ip);
				pankey_WIFILog(pankey_Log_Statement, "configWIFI",  "println", "gateway");
				pankey_WIFILog(pankey_Log_Statement, "configWIFI",  "println", i_gateway);
				pankey_WIFILog(pankey_Log_Statement, "configWIFI",  "println", "subnet");
				pankey_WIFILog(pankey_Log_Statement, "configWIFI",  "println", i_subnet);
				pankey_WIFILog(pankey_Log_Statement, "configWIFI",  "println", "dns");
				pankey_WIFILog(pankey_Log_Statement, "configWIFI",  "println", i_dns);
				
				WiFi.mode(WIFI_STA);
				WiFi.setSleep(false);
				
				esp_wifi_set_mac(WIFI_IF_STA, i_mac.pointer());

				if(!WiFi.config(i_ip, i_gateway, i_subnet, i_dns)) {
					pankey_WIFILog(pankey_Log_Statement, "configWIFI",  "println", "STA Failed to configure");
				}

				pankey_WIFILog(pankey_Log_EndMethod, "configWIFI",  "println", "");
			}

			void configWIFI(Note a_mac){
				pankey_WIFILog(pankey_Log_StartMethod, "configWIFI",  "println", "");

				pankey_WIFILog(pankey_Log_Statement, "configWIFI",  "println", "mac");
				pankey_WIFILog(pankey_Log_Statement, "configWIFI",  "println", a_mac);

				Array<uint8_t> i_mac = toMAC(a_mac);
				
				WiFi.mode(WIFI_STA);
				WiFi.setSleep(false);
				
				esp_wifi_set_mac(WIFI_IF_STA, i_mac.pointer());

				pankey_WIFILog(pankey_Log_EndMethod, "configWIFI",  "println", "");
			}

			void configWIFI(Note a_ip, Note a_gateway, Note a_subnet, Note a_dns){
				pankey_WIFILog(pankey_Log_StartMethod, "configWIFI",  "println", "");

				pankey_WIFILog(pankey_Log_Statement, "configWIFI",  "println", "ip");
				pankey_WIFILog(pankey_Log_Statement, "configWIFI",  "println", a_ip);
				pankey_WIFILog(pankey_Log_Statement, "configWIFI",  "println", "gateway");
				pankey_WIFILog(pankey_Log_Statement, "configWIFI",  "println", a_gateway);
				pankey_WIFILog(pankey_Log_Statement, "configWIFI",  "println", "subnet");
				pankey_WIFILog(pankey_Log_Statement, "configWIFI",  "println", a_subnet);
				pankey_WIFILog(pankey_Log_Statement, "configWIFI",  "println", "dns");
				pankey_WIFILog(pankey_Log_Statement, "configWIFI",  "println", a_dns);

				IPAddress i_ip = toIPAddress(a_ip);
				IPAddress i_gateway = toIPAddress(a_gateway);
				IPAddress i_subnet = toIPAddress(a_subnet);
				IPAddress i_dns = toIPAddress(a_dns);

				pankey_WIFILog(pankey_Log_Statement, "configWIFI",  "println", "ip");
				pankey_WIFILog(pankey_Log_Statement, "configWIFI",  "println", i_ip);
				pankey_WIFILog(pankey_Log_Statement, "configWIFI",  "println", "gateway");
				pankey_WIFILog(pankey_Log_Statement, "configWIFI",  "println", i_gateway);
				pankey_WIFILog(pankey_Log_Statement, "configWIFI",  "println", "subnet");
				pankey_WIFILog(pankey_Log_Statement, "configWIFI",  "println", i_subnet);
				pankey_WIFILog(pankey_Log_Statement, "configWIFI",  "println", "dns");
				pankey_WIFILog(pankey_Log_Statement, "configWIFI",  "println", i_dns);

				if(!WiFi.config(i_ip, i_gateway, i_subnet, i_dns)) {
					pankey_WIFILog(pankey_Log_Statement, "configWIFI",  "println", "STA Failed to configure");
				}

				pankey_WIFILog(pankey_Log_EndMethod, "configWIFI",  "println", "");
			}

			void connectWIFI(Note  name, Note pasword){
				pankey_WIFILog(pankey_Log_StartMethod, "connectWIFI",  "println", "");

				pankey_WIFILog(pankey_Log_Statement, "connectWIFI",  "println", "name");
				pankey_WIFILog(pankey_Log_Statement, "connectWIFI",  "println", name);
				pankey_WIFILog(pankey_Log_Statement, "connectWIFI",  "println", "pasword");
				pankey_WIFILog(pankey_Log_Statement, "connectWIFI",  "println", pasword);
				 
				WiFi.begin(name.pointer(), pasword.pointer());

				if(WiFi.status() == WL_CONNECTED) {
					pankey_WIFILog(pankey_Log_Statement, "connectWIFI",  "println", "connected");
				}else{
					pankey_WIFILog(pankey_Log_Statement, "connectWIFI",  "println", "fail to connect");
				}

				pankey_WIFILog(pankey_Log_EndMethod, "connectWIFI",  "println", "");
			}

			void disconnectWIFI(){
				pankey_WIFILog(pankey_Log_StartMethod, "connectWIFI",  "println", "");
				 
				WiFi.disconnect();

				if(WiFi.status() != WL_CONNECTED) {
					pankey_WIFILog(pankey_Log_Statement, "connectWIFI",  "println", "disconnected");
				}else{
					pankey_WIFILog(pankey_Log_Statement, "connectWIFI",  "println", "fail to disconnect");
				}

				pankey_WIFILog(pankey_Log_EndMethod, "connectWIFI",  "println", "");
			}

			void haltUntilWIFIConnection(){
				pankey_WIFILog(pankey_Log_StartMethod, "haltUntilWIFIConnection",  "println", "");
				while (WiFi.status() != WL_CONNECTED) {
					pankey_WIFILog(pankey_Log_StartMethod, "haltUntilWIFIConnection",  "println", ".");
					delay(1000);
				}
				pankey_WIFILog(pankey_Log_EndMethod, "haltUntilWIFIConnection",  "println", "");
			}

			bool hasLAN(){
				return WiFi.status() == WL_CONNECTED;
			}

			void printWIFI(Stream* port){
				if(port == nullptr){
					return;
				}
				if(WiFi.status() == WL_CONNECTED){
					port->println("WIFI connected");
				}else{
					port->println("WIFI disconnected");
				}
				port->print("WIFI ip: ");
				port->println(WiFi.localIP());
			}

			void WIFICommands(const PrimitiveRawList<Note>& a_commands){

			}

		#endif

	}

#endif
