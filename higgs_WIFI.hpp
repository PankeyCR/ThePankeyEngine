
#ifndef higgs_WIFI_hpp
	#define higgs_WIFI_hpp

	#include "Note.hpp"
	#include "NoteHelper.hpp"
	#include "PrimitiveRawList.hpp"

	#ifndef higgs_Enviroment_Defined

	#endif

	#ifdef higgs_Windows

	#endif

	#ifdef higgs_ArduinoIDE
		#include "Arduino.h"
	#endif

	#if defined(ARDUINO_ARCH_ESP8266)
		#include "WiFi.h"
	#elif defined(ARDUINO_ARCH_ESP32)
		#include "WiFi.h"
		#include <esp_wifi.h>
	#endif

	#ifdef higgs_WIFI_LogApp
		#include "higgs_Logger.hpp"
		#define higgs_WIFILog(location,method,type,mns) higgs_Log(nullptr,location,"higgs_WIFI",method,type,mns)
	#else
		#define higgs_WIFILog(location,method,type,mns)
	#endif

	namespace higgs{
		
		//void initializeWIFI(Note a_ip, Note a_gateway, Note a_subnet, Note a_dns, uint8_t* a_mac, const char* name, const char* pasword);

		#ifdef higgs_ArduinoIDE

			void initializeWIFI(Note a_mac, Note a_ip, Note a_gateway, Note a_subnet, Note a_dns, Note a_name, Note a_pasword){
				higgs_WIFILog(higgs_Log_StartMethod, "initializeWIFI",  "println", "");

				higgs_WIFILog(higgs_Log_Statement, "initializeWIFI",  "println", "mac");
				higgs_WIFILog(higgs_Log_Statement, "initializeWIFI",  "println", a_mac);
				higgs_WIFILog(higgs_Log_Statement, "initializeWIFI",  "println", "ip");
				higgs_WIFILog(higgs_Log_Statement, "initializeWIFI",  "println", a_ip);
				higgs_WIFILog(higgs_Log_Statement, "initializeWIFI",  "println", "gateway");
				higgs_WIFILog(higgs_Log_Statement, "initializeWIFI",  "println", a_gateway);
				higgs_WIFILog(higgs_Log_Statement, "initializeWIFI",  "println", "subnet");
				higgs_WIFILog(higgs_Log_Statement, "initializeWIFI",  "println", a_subnet);
				higgs_WIFILog(higgs_Log_Statement, "initializeWIFI",  "println", "dns");
				higgs_WIFILog(higgs_Log_Statement, "initializeWIFI",  "println", a_dns);
				higgs_WIFILog(higgs_Log_Statement, "initializeWIFI",  "println", "name");
				higgs_WIFILog(higgs_Log_Statement, "initializeWIFI",  "println", a_name);
				higgs_WIFILog(higgs_Log_Statement, "initializeWIFI",  "println", "pasword");
				higgs_WIFILog(higgs_Log_Statement, "initializeWIFI",  "println", a_pasword);

				Array<uint8_t> i_mac = toMAC(a_mac);
				IPAddress i_ip = toIPAddress(a_ip);
				IPAddress i_gateway = toIPAddress(a_gateway);
				IPAddress i_subnet = toIPAddress(a_subnet);
				IPAddress i_dns = toIPAddress(a_dns);

				higgs_WIFILog(higgs_Log_Statement, "initializeWIFI",  "println", "ip");
				higgs_WIFILog(higgs_Log_Statement, "initializeWIFI",  "println", i_ip);
				higgs_WIFILog(higgs_Log_Statement, "initializeWIFI",  "println", "gateway");
				higgs_WIFILog(higgs_Log_Statement, "initializeWIFI",  "println", i_gateway);
				higgs_WIFILog(higgs_Log_Statement, "initializeWIFI",  "println", "subnet");
				higgs_WIFILog(higgs_Log_Statement, "initializeWIFI",  "println", i_subnet);
				higgs_WIFILog(higgs_Log_Statement, "initializeWIFI",  "println", "dns");
				higgs_WIFILog(higgs_Log_Statement, "initializeWIFI",  "println", i_dns);
				
				WiFi.mode(WIFI_STA);
				WiFi.setSleep(false);
				
				esp_wifi_set_mac(WIFI_IF_STA, i_mac.pointer());

				if(!WiFi.config(i_ip, i_gateway, i_subnet, i_dns)) {
					higgs_WIFILog(higgs_Log_Statement, "initializeWIFI",  "println", "STA Failed to configure");
				}

				WiFi.begin(a_name.pointer(), a_pasword.pointer());

				if(WiFi.status() == WL_CONNECTED) {
					higgs_WIFILog(higgs_Log_Statement, "initializeWIFI",  "println", "connected");
				}else{
					higgs_WIFILog(higgs_Log_Statement, "initializeWIFI",  "println", "fail to connect");
				}

				higgs_WIFILog(higgs_Log_EndMethod, "initializeWIFI",  "println", "");
			}

			void configWIFI(Note a_mac, Note a_ip, Note a_gateway, Note a_subnet, Note a_dns){
				higgs_WIFILog(higgs_Log_StartMethod, "configWIFI",  "println", "");

				higgs_WIFILog(higgs_Log_Statement, "configWIFI",  "println", "mac");
				higgs_WIFILog(higgs_Log_Statement, "configWIFI",  "println", a_mac);
				higgs_WIFILog(higgs_Log_Statement, "configWIFI",  "println", "ip");
				higgs_WIFILog(higgs_Log_Statement, "configWIFI",  "println", a_ip);
				higgs_WIFILog(higgs_Log_Statement, "configWIFI",  "println", "gateway");
				higgs_WIFILog(higgs_Log_Statement, "configWIFI",  "println", a_gateway);
				higgs_WIFILog(higgs_Log_Statement, "configWIFI",  "println", "subnet");
				higgs_WIFILog(higgs_Log_Statement, "configWIFI",  "println", a_subnet);
				higgs_WIFILog(higgs_Log_Statement, "configWIFI",  "println", "dns");
				higgs_WIFILog(higgs_Log_Statement, "configWIFI",  "println", a_dns);

				Array<uint8_t> i_mac = toMAC(a_mac);
				IPAddress i_ip = toIPAddress(a_ip);
				IPAddress i_gateway = toIPAddress(a_gateway);
				IPAddress i_subnet = toIPAddress(a_subnet);
				IPAddress i_dns = toIPAddress(a_dns);

				higgs_WIFILog(higgs_Log_Statement, "configWIFI",  "println", "ip");
				higgs_WIFILog(higgs_Log_Statement, "configWIFI",  "println", i_ip);
				higgs_WIFILog(higgs_Log_Statement, "configWIFI",  "println", "gateway");
				higgs_WIFILog(higgs_Log_Statement, "configWIFI",  "println", i_gateway);
				higgs_WIFILog(higgs_Log_Statement, "configWIFI",  "println", "subnet");
				higgs_WIFILog(higgs_Log_Statement, "configWIFI",  "println", i_subnet);
				higgs_WIFILog(higgs_Log_Statement, "configWIFI",  "println", "dns");
				higgs_WIFILog(higgs_Log_Statement, "configWIFI",  "println", i_dns);
				
				WiFi.mode(WIFI_STA);
				WiFi.setSleep(false);
				
				esp_wifi_set_mac(WIFI_IF_STA, i_mac.pointer());

				if(!WiFi.config(i_ip, i_gateway, i_subnet, i_dns)) {
					higgs_WIFILog(higgs_Log_Statement, "configWIFI",  "println", "STA Failed to configure");
				}

				higgs_WIFILog(higgs_Log_EndMethod, "configWIFI",  "println", "");
			}

			void configWIFI(Note a_mac){
				higgs_WIFILog(higgs_Log_StartMethod, "configWIFI",  "println", "");

				higgs_WIFILog(higgs_Log_Statement, "configWIFI",  "println", "mac");
				higgs_WIFILog(higgs_Log_Statement, "configWIFI",  "println", a_mac);

				Array<uint8_t> i_mac = toMAC(a_mac);
				
				WiFi.mode(WIFI_STA);
				WiFi.setSleep(false);
				
				esp_wifi_set_mac(WIFI_IF_STA, i_mac.pointer());

				higgs_WIFILog(higgs_Log_EndMethod, "configWIFI",  "println", "");
			}

			void configWIFI(Note a_ip, Note a_gateway, Note a_subnet, Note a_dns){
				higgs_WIFILog(higgs_Log_StartMethod, "configWIFI",  "println", "");

				higgs_WIFILog(higgs_Log_Statement, "configWIFI",  "println", "ip");
				higgs_WIFILog(higgs_Log_Statement, "configWIFI",  "println", a_ip);
				higgs_WIFILog(higgs_Log_Statement, "configWIFI",  "println", "gateway");
				higgs_WIFILog(higgs_Log_Statement, "configWIFI",  "println", a_gateway);
				higgs_WIFILog(higgs_Log_Statement, "configWIFI",  "println", "subnet");
				higgs_WIFILog(higgs_Log_Statement, "configWIFI",  "println", a_subnet);
				higgs_WIFILog(higgs_Log_Statement, "configWIFI",  "println", "dns");
				higgs_WIFILog(higgs_Log_Statement, "configWIFI",  "println", a_dns);

				IPAddress i_ip = toIPAddress(a_ip);
				IPAddress i_gateway = toIPAddress(a_gateway);
				IPAddress i_subnet = toIPAddress(a_subnet);
				IPAddress i_dns = toIPAddress(a_dns);

				higgs_WIFILog(higgs_Log_Statement, "configWIFI",  "println", "ip");
				higgs_WIFILog(higgs_Log_Statement, "configWIFI",  "println", i_ip);
				higgs_WIFILog(higgs_Log_Statement, "configWIFI",  "println", "gateway");
				higgs_WIFILog(higgs_Log_Statement, "configWIFI",  "println", i_gateway);
				higgs_WIFILog(higgs_Log_Statement, "configWIFI",  "println", "subnet");
				higgs_WIFILog(higgs_Log_Statement, "configWIFI",  "println", i_subnet);
				higgs_WIFILog(higgs_Log_Statement, "configWIFI",  "println", "dns");
				higgs_WIFILog(higgs_Log_Statement, "configWIFI",  "println", i_dns);

				if(!WiFi.config(i_ip, i_gateway, i_subnet, i_dns)) {
					higgs_WIFILog(higgs_Log_Statement, "configWIFI",  "println", "STA Failed to configure");
				}

				higgs_WIFILog(higgs_Log_EndMethod, "configWIFI",  "println", "");
			}

			void connectWIFI(Note  name, Note pasword){
				higgs_WIFILog(higgs_Log_StartMethod, "connectWIFI",  "println", "");

				higgs_WIFILog(higgs_Log_Statement, "connectWIFI",  "println", "name");
				higgs_WIFILog(higgs_Log_Statement, "connectWIFI",  "println", name);
				higgs_WIFILog(higgs_Log_Statement, "connectWIFI",  "println", "pasword");
				higgs_WIFILog(higgs_Log_Statement, "connectWIFI",  "println", pasword);
				 
				WiFi.begin(name.pointer(), pasword.pointer());

				if(WiFi.status() == WL_CONNECTED) {
					higgs_WIFILog(higgs_Log_Statement, "connectWIFI",  "println", "connected");
				}else{
					higgs_WIFILog(higgs_Log_Statement, "connectWIFI",  "println", "fail to connect");
				}

				higgs_WIFILog(higgs_Log_EndMethod, "connectWIFI",  "println", "");
			}

			void disconnectWIFI(){
				higgs_WIFILog(higgs_Log_StartMethod, "connectWIFI",  "println", "");
				 
				WiFi.disconnect();

				if(WiFi.status() != WL_CONNECTED) {
					higgs_WIFILog(higgs_Log_Statement, "connectWIFI",  "println", "disconnected");
				}else{
					higgs_WIFILog(higgs_Log_Statement, "connectWIFI",  "println", "fail to disconnect");
				}

				higgs_WIFILog(higgs_Log_EndMethod, "connectWIFI",  "println", "");
			}

			void haltUntilWIFIConnection(){
				higgs_WIFILog(higgs_Log_StartMethod, "haltUntilWIFIConnection",  "println", "");
				while (WiFi.status() != WL_CONNECTED) {
					higgs_WIFILog(higgs_Log_StartMethod, "haltUntilWIFIConnection",  "println", ".");
					delay(1000);
				}
				higgs_WIFILog(higgs_Log_EndMethod, "haltUntilWIFIConnection",  "println", "");
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
