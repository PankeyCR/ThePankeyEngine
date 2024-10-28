
#ifndef WIFIConnection_hpp
	#define WIFIConnection_hpp
	
	#include "pankey.hpp"

	#include "Note.hpp"
	#include "NoteHelper.hpp"
	#include "PrimitiveRawList.hpp"

	#if pankey_Enviroment == pankey_Windows_Enviroment

	#endif

	#if pankey_IDE == pankey_Arduino_IDE
		#include "Arduino.h"
	#endif

	#if pankey_Generic_Hardware == pankey_Generic_Esp8266_Hardware
		#include "WiFi.h"
	#endif

	#if pankey_Generic_Hardware == pankey_Generic_Esp32_Hardware
		#include "WiFi.h"
		#include <esp_wifi.h>
	#endif

	#ifdef WIFIConnection_LogApp
		#include "pankey_Logger.hpp"
		#define WIFIConnectionLog(location,method,type,mns) pankey_Log(nullptr,location,"WIFIConnection",method,type,mns)
	#else
		#define WIFIConnectionLog(location,method,type,mns)
	#endif

	namespace pankey{
		
		//void initializeWIFI(Note a_ip, Note a_gateway, Note a_subnet, Note a_dns, uint8_t* a_mac, const char* name, const char* pasword);

		#if pankey_IDE == pankey_Arduino_IDE

			void initializeWIFI(Note a_mac, Note a_ip, Note a_gateway, Note a_subnet, Note a_dns, Note a_name, Note a_pasword){
				WIFIConnectionLog(pankey_Log_StartMethod, "initializeWIFI",  "println", "");

				WIFIConnectionLog(pankey_Log_Statement, "initializeWIFI",  "println", "mac");
				WIFIConnectionLog(pankey_Log_Statement, "initializeWIFI",  "println", a_mac);
				WIFIConnectionLog(pankey_Log_Statement, "initializeWIFI",  "println", "ip");
				WIFIConnectionLog(pankey_Log_Statement, "initializeWIFI",  "println", a_ip);
				WIFIConnectionLog(pankey_Log_Statement, "initializeWIFI",  "println", "gateway");
				WIFIConnectionLog(pankey_Log_Statement, "initializeWIFI",  "println", a_gateway);
				WIFIConnectionLog(pankey_Log_Statement, "initializeWIFI",  "println", "subnet");
				WIFIConnectionLog(pankey_Log_Statement, "initializeWIFI",  "println", a_subnet);
				WIFIConnectionLog(pankey_Log_Statement, "initializeWIFI",  "println", "dns");
				WIFIConnectionLog(pankey_Log_Statement, "initializeWIFI",  "println", a_dns);
				WIFIConnectionLog(pankey_Log_Statement, "initializeWIFI",  "println", "name");
				WIFIConnectionLog(pankey_Log_Statement, "initializeWIFI",  "println", a_name);
				WIFIConnectionLog(pankey_Log_Statement, "initializeWIFI",  "println", "pasword");
				WIFIConnectionLog(pankey_Log_Statement, "initializeWIFI",  "println", a_pasword);

				Array<uint8_t> i_mac = toMAC(a_mac);
				IPAddress i_ip = toIPAddress(a_ip);
				IPAddress i_gateway = toIPAddress(a_gateway);
				IPAddress i_subnet = toIPAddress(a_subnet);
				IPAddress i_dns = toIPAddress(a_dns);

				WIFIConnectionLog(pankey_Log_Statement, "initializeWIFI",  "println", "ip");
				WIFIConnectionLog(pankey_Log_Statement, "initializeWIFI",  "println", i_ip);
				WIFIConnectionLog(pankey_Log_Statement, "initializeWIFI",  "println", "gateway");
				WIFIConnectionLog(pankey_Log_Statement, "initializeWIFI",  "println", i_gateway);
				WIFIConnectionLog(pankey_Log_Statement, "initializeWIFI",  "println", "subnet");
				WIFIConnectionLog(pankey_Log_Statement, "initializeWIFI",  "println", i_subnet);
				WIFIConnectionLog(pankey_Log_Statement, "initializeWIFI",  "println", "dns");
				WIFIConnectionLog(pankey_Log_Statement, "initializeWIFI",  "println", i_dns);
				
				WiFi.mode(WIFI_STA);
				WiFi.setSleep(false);
				
				esp_wifi_set_mac(WIFI_IF_STA, i_mac.pointer());

				if(!WiFi.config(i_ip, i_gateway, i_subnet, i_dns)) {
					WIFIConnectionLog(pankey_Log_Statement, "initializeWIFI",  "println", "STA Failed to configure");
				}

				WiFi.begin(a_name.pointer(), a_pasword.pointer());

				if(WiFi.status() == WL_CONNECTED) {
					WIFIConnectionLog(pankey_Log_Statement, "initializeWIFI",  "println", "connected");
				}else{
					WIFIConnectionLog(pankey_Log_Statement, "initializeWIFI",  "println", "fail to connect");
				}

				WIFIConnectionLog(pankey_Log_EndMethod, "initializeWIFI",  "println", "");
			}

			void configWIFI(Note a_mac, Note a_ip, Note a_gateway, Note a_subnet, Note a_dns){
				WIFIConnectionLog(pankey_Log_StartMethod, "configWIFI",  "println", "");

				WIFIConnectionLog(pankey_Log_Statement, "configWIFI",  "println", "mac");
				WIFIConnectionLog(pankey_Log_Statement, "configWIFI",  "println", a_mac);
				WIFIConnectionLog(pankey_Log_Statement, "configWIFI",  "println", "ip");
				WIFIConnectionLog(pankey_Log_Statement, "configWIFI",  "println", a_ip);
				WIFIConnectionLog(pankey_Log_Statement, "configWIFI",  "println", "gateway");
				WIFIConnectionLog(pankey_Log_Statement, "configWIFI",  "println", a_gateway);
				WIFIConnectionLog(pankey_Log_Statement, "configWIFI",  "println", "subnet");
				WIFIConnectionLog(pankey_Log_Statement, "configWIFI",  "println", a_subnet);
				WIFIConnectionLog(pankey_Log_Statement, "configWIFI",  "println", "dns");
				WIFIConnectionLog(pankey_Log_Statement, "configWIFI",  "println", a_dns);

				Array<uint8_t> i_mac = toMAC(a_mac);
				IPAddress i_ip = toIPAddress(a_ip);
				IPAddress i_gateway = toIPAddress(a_gateway);
				IPAddress i_subnet = toIPAddress(a_subnet);
				IPAddress i_dns = toIPAddress(a_dns);

				WIFIConnectionLog(pankey_Log_Statement, "configWIFI",  "println", "ip");
				WIFIConnectionLog(pankey_Log_Statement, "configWIFI",  "println", i_ip);
				WIFIConnectionLog(pankey_Log_Statement, "configWIFI",  "println", "gateway");
				WIFIConnectionLog(pankey_Log_Statement, "configWIFI",  "println", i_gateway);
				WIFIConnectionLog(pankey_Log_Statement, "configWIFI",  "println", "subnet");
				WIFIConnectionLog(pankey_Log_Statement, "configWIFI",  "println", i_subnet);
				WIFIConnectionLog(pankey_Log_Statement, "configWIFI",  "println", "dns");
				WIFIConnectionLog(pankey_Log_Statement, "configWIFI",  "println", i_dns);
				
				WiFi.mode(WIFI_STA);
				WiFi.setSleep(false);
				
				esp_wifi_set_mac(WIFI_IF_STA, i_mac.pointer());

				if(!WiFi.config(i_ip, i_gateway, i_subnet, i_dns)) {
					WIFIConnectionLog(pankey_Log_Statement, "configWIFI",  "println", "STA Failed to configure");
				}

				WIFIConnectionLog(pankey_Log_EndMethod, "configWIFI",  "println", "");
			}

			void configWIFI(Note a_mac){
				WIFIConnectionLog(pankey_Log_StartMethod, "configWIFI",  "println", "");

				WIFIConnectionLog(pankey_Log_Statement, "configWIFI",  "println", "mac");
				WIFIConnectionLog(pankey_Log_Statement, "configWIFI",  "println", a_mac);

				Array<uint8_t> i_mac = toMAC(a_mac);
				
				WiFi.mode(WIFI_STA);
				WiFi.setSleep(false);
				
				esp_wifi_set_mac(WIFI_IF_STA, i_mac.pointer());

				WIFIConnectionLog(pankey_Log_EndMethod, "configWIFI",  "println", "");
			}

			void configWIFI(Note a_ip, Note a_gateway, Note a_subnet, Note a_dns){
				WIFIConnectionLog(pankey_Log_StartMethod, "configWIFI",  "println", "");

				WIFIConnectionLog(pankey_Log_Statement, "configWIFI",  "println", "ip");
				WIFIConnectionLog(pankey_Log_Statement, "configWIFI",  "println", a_ip);
				WIFIConnectionLog(pankey_Log_Statement, "configWIFI",  "println", "gateway");
				WIFIConnectionLog(pankey_Log_Statement, "configWIFI",  "println", a_gateway);
				WIFIConnectionLog(pankey_Log_Statement, "configWIFI",  "println", "subnet");
				WIFIConnectionLog(pankey_Log_Statement, "configWIFI",  "println", a_subnet);
				WIFIConnectionLog(pankey_Log_Statement, "configWIFI",  "println", "dns");
				WIFIConnectionLog(pankey_Log_Statement, "configWIFI",  "println", a_dns);

				IPAddress i_ip = toIPAddress(a_ip);
				IPAddress i_gateway = toIPAddress(a_gateway);
				IPAddress i_subnet = toIPAddress(a_subnet);
				IPAddress i_dns = toIPAddress(a_dns);

				WIFIConnectionLog(pankey_Log_Statement, "configWIFI",  "println", "ip");
				WIFIConnectionLog(pankey_Log_Statement, "configWIFI",  "println", i_ip);
				WIFIConnectionLog(pankey_Log_Statement, "configWIFI",  "println", "gateway");
				WIFIConnectionLog(pankey_Log_Statement, "configWIFI",  "println", i_gateway);
				WIFIConnectionLog(pankey_Log_Statement, "configWIFI",  "println", "subnet");
				WIFIConnectionLog(pankey_Log_Statement, "configWIFI",  "println", i_subnet);
				WIFIConnectionLog(pankey_Log_Statement, "configWIFI",  "println", "dns");
				WIFIConnectionLog(pankey_Log_Statement, "configWIFI",  "println", i_dns);

				if(!WiFi.config(i_ip, i_gateway, i_subnet, i_dns)) {
					WIFIConnectionLog(pankey_Log_Statement, "configWIFI",  "println", "STA Failed to configure");
				}

				WIFIConnectionLog(pankey_Log_EndMethod, "configWIFI",  "println", "");
			}

			void connectWIFI(Note  name, Note pasword){
				WIFIConnectionLog(pankey_Log_StartMethod, "connectWIFI",  "println", "");

				WIFIConnectionLog(pankey_Log_Statement, "connectWIFI",  "println", "name");
				WIFIConnectionLog(pankey_Log_Statement, "connectWIFI",  "println", name);
				WIFIConnectionLog(pankey_Log_Statement, "connectWIFI",  "println", "pasword");
				WIFIConnectionLog(pankey_Log_Statement, "connectWIFI",  "println", pasword);
				 
				WiFi.begin(name.pointer(), pasword.pointer());

				if(WiFi.status() == WL_CONNECTED) {
					WIFIConnectionLog(pankey_Log_Statement, "connectWIFI",  "println", "connected");
				}else{
					WIFIConnectionLog(pankey_Log_Statement, "connectWIFI",  "println", "fail to connect");
				}

				WIFIConnectionLog(pankey_Log_EndMethod, "connectWIFI",  "println", "");
			}

			void disconnectWIFI(){
				WIFIConnectionLog(pankey_Log_StartMethod, "connectWIFI",  "println", "");
				 
				WiFi.disconnect();

				if(WiFi.status() != WL_CONNECTED) {
					WIFIConnectionLog(pankey_Log_Statement, "connectWIFI",  "println", "disconnected");
				}else{
					WIFIConnectionLog(pankey_Log_Statement, "connectWIFI",  "println", "fail to disconnect");
				}

				WIFIConnectionLog(pankey_Log_EndMethod, "connectWIFI",  "println", "");
			}

			void haltUntilWIFIConnection(){
				WIFIConnectionLog(pankey_Log_StartMethod, "haltUntilWIFIConnection",  "println", "");
				while (WiFi.status() != WL_CONNECTED) {
					WIFIConnectionLog(pankey_Log_StartMethod, "haltUntilWIFIConnection",  "println", ".");
					System::sleep(1000);
				}
				WIFIConnectionLog(pankey_Log_EndMethod, "haltUntilWIFIConnection",  "println", "");
			}

			void haltUntilWIFIConnection(float a_time){
				WIFIConnectionLog(pankey_Log_StartMethod, "haltUntilWIFIConnection",  "println", "");
				long i_time_limit = 1000 * a_time;
				long i_start_time = millis();
				while ((millis() - i_start_time) < i_time_limit) {
					WIFIConnectionLog(pankey_Log_StartMethod, "haltUntilWIFIConnection",  "println", ".");
					Watchdog::feed();
					if(WiFi.status() == WL_CONNECTED){
						return;
					}
				}
				WIFIConnectionLog(pankey_Log_EndMethod, "haltUntilWIFIConnection",  "println", "");
			}

			void haltUntilWIFIDisconnection(){
				WIFIConnectionLog(pankey_Log_StartMethod, "haltUntilWIFIDisconnection",  "println", "");
				while (WiFi.status() == WL_CONNECTED) {
					WIFIConnectionLog(pankey_Log_StartMethod, "haltUntilWIFIDisconnection",  "println", ".");
					System::sleep(1000);
				}
				WIFIConnectionLog(pankey_Log_EndMethod, "haltUntilWIFIDisconnection",  "println", "");
			}

			void haltUntilWIFIDisconnection(float a_time){
				WIFIConnectionLog(pankey_Log_StartMethod, "haltUntilWIFIDisconnection",  "println", "");
				long i_time_limit = 1000 * a_time;
				long i_start_time = millis();
				while ((millis() - i_start_time) < i_time_limit) {
					WIFIConnectionLog(pankey_Log_StartMethod, "haltUntilWIFIConnection",  "println", ".");
					Watchdog::feed();
					if(WiFi.status() != WL_CONNECTED){
						return;
					}
				}
				WIFIConnectionLog(pankey_Log_EndMethod, "haltUntilWIFIDisconnection",  "println", "");
			}

			bool hasWifiLAN(){
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
