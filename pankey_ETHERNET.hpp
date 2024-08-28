
#ifndef pankey_ETHERNET_hpp
#define pankey_ETHERNET_hpp
#define pankey_ETHERNET_AVAILABLE 

#include "pankey_Enviroment.hpp"

#ifndef pankey_Enviroment_Defined

#endif

#ifdef pankey_Windows

#endif

#ifdef pankey_ArduinoIDE
	#include "Arduino.h"
#endif

#include "NoteHelper.hpp"

#ifdef pankey_ETHERNET_LogApp
	#include "pankey_Logger_config.hpp"
	#include "pankey_Logger.hpp"
	
	#define pankey_ETHERNETLog(location,method,type,mns) pankey_Log(nullptr,location,"pankey_ETHERNET",method,type,mns)
#else
	#ifdef pankey_ETHERNET_LogDebugApp
		#include "pankey_Logger_config.hpp"
		#include "pankey_Logger.hpp"
		
		#define pankey_ETHERNETLog(location,method,type,mns) pankey_LogDebug(nullptr,location,"pankey_ETHERNET",method,type)
	#else
		#define pankey_ETHERNETLog(location,method,type,mns) 
	#endif
#endif

namespace ame{

#ifdef pankey_ArduinoIDE
void initializeETHERNET(IPAddress a_ip, IPAddress a_gateway, IPAddress a_subnet, int CS_pin, byte* mac){
	pankey_ETHERNETLog(pankey_Log_StartMethod, "initializeETHERNET",  "println", "IPAddress");
	pankey_ETHERNETLog(pankey_Log_StartMethod, "initializeETHERNET",  "println", "a_ip");
	pankey_ETHERNETLog(pankey_Log_StartMethod, "initializeETHERNET",  "println", a_ip);
	pankey_ETHERNETLog(pankey_Log_StartMethod, "initializeETHERNET",  "println", "a_gateway");
	pankey_ETHERNETLog(pankey_Log_StartMethod, "initializeETHERNET",  "println", a_gateway);
	pankey_ETHERNETLog(pankey_Log_StartMethod, "initializeETHERNET",  "println", "a_subnet");
	pankey_ETHERNETLog(pankey_Log_StartMethod, "initializeETHERNET",  "println", a_subnet);
	
	Ethernet.init(CS_pin);
	Ethernet.begin(mac, a_ip, a_gateway, a_subnet);
	
	pankey_ETHERNETLog(pankey_Log_StartMethod, "initializeETHERNET",  "println", "connected");
}

void initializeETHERNET(Note a_ip, Note a_gateway, Note a_subnet, int CS_pin, byte* mac){
	pankey_ETHERNETLog(pankey_Log_StartMethod, "initializeETHERNET",  "println", "Note");

	pankey_ETHERNETLog(pankey_Log_StartMethod, "initializeETHERNET",  "println", "a_ip");
	pankey_ETHERNETLog(pankey_Log_StartMethod, "initializeETHERNET",  "println", a_ip);
	pankey_ETHERNETLog(pankey_Log_StartMethod, "initializeETHERNET",  "println", "a_gateway");
	pankey_ETHERNETLog(pankey_Log_StartMethod, "initializeETHERNET",  "println", a_gateway);
	pankey_ETHERNETLog(pankey_Log_StartMethod, "initializeETHERNET",  "println", "a_subnet");
	pankey_ETHERNETLog(pankey_Log_StartMethod, "initializeETHERNET",  "println", a_subnet);
	
	initializeETHERNET(toIPAddress(a_ip), toIPAddress(a_gateway), toIPAddress(a_subnet), CS_pin, mac);
	pankey_ETHERNETLog(pankey_Log_StartMethod, "initializeETHERNET",  "println", "");
}

// void initializeETHERNET(Note a_ip, Note a_gateway, Note a_subnet, int CS_pin, ByteArray mac){
	// initializeETHERNET(a_ip.toIPAddress(), a_gateway.toIPAddress(), a_subnet.toIPAddress(), CS_pin, mac.pointer());
// }

void haltUntilEthernetConnection(){
	pankey_ETHERNETLog(pankey_Log_StartMethod, "haltUntilEthernetConnection",  "println", "");
	while (Ethernet.linkStatus() != LinkON) {
		pankey_ETHERNETLog(pankey_Log_StartMethod, "haltUntilEthernetConnection",  "println", ".");
		delay(1000);
	}
	pankey_ETHERNETLog(pankey_Log_EndMethod, "haltUntilEthernetConnection",  "println", "");
}


bool hasLAN(){
	return Ethernet.linkStatus() == LinkON;
}
#endif

}

#endif
