
#include "ame_Enviroment.hpp"

#if defined(DISABLE_ame_WIFI)
	#define ame_WIFI_hpp
#endif

#ifndef ame_WIFI_hpp
#define ame_WIFI_hpp
#define ame_WIFI_AVAILABLE

#ifndef ame_Enviroment_Defined

#endif

#ifdef ame_Windows

#endif

#ifdef ame_ArduinoIDE
	#include "Arduino.h"
#endif

#ifdef ame_WIFILogApp
	#include "Logger.hpp"
	#define ame_WIFILog(name,method,type,mns) Log(name,method,type,mns)
#else
	#define ame_WIFILog(name,method,type,mns)
#endif

namespace ame{

#ifdef ame_ArduinoIDE
void initializeWIFI(Note a_ip, Note a_gateway, Note a_subnet, Note a_dns, Note name, Note pasword){
	ame_WIFILog("ame_WIFI", "initializeWIFI",  "println", "");
	// IPAddress
	IPAddress ip = toIPAddress(a_ip);
	IPAddress gateway = toIPAddress(a_gateway);
	IPAddress subnet = toIPAddress(a_subnet);
	IPAddress dns = toIPAddress(a_subnet);
	
	WiFi.mode(WIFI_STA);
	WiFi.setSleep(false);
	if(!WiFi.config(ip,gateway,subnet,dns)) {
		ame_WIFILog("ame_WIFI", "initializeWIFI",  "println", "STA Failed to configure");
	}
	WiFi.begin(name.c_str(), pasword.c_str());
	if(WiFi.status() == WL_CONNECTED) {
		ame_WIFILog("ame_WIFI", "initializeWIFI",  "println", "connected");
		delay(1000);
	}
	ame_WIFILog("ame_WIFI", "initializeWIFI",  "println", "");
	// Serial.println(WiFi.localIP());
}

void haltUntilWIFIConnection(){
	while (WiFi.status() != WL_CONNECTED) {
		ame_WIFILog("ame_WIFI", "haltUntilConnection",  "println", ".");
		delay(1000);
	}
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
#endif

}

#endif
