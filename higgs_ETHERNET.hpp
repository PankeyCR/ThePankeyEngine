
#ifndef higgs_ETHERNET_hpp
#define higgs_ETHERNET_hpp
#define higgs_ETHERNET_AVAILABLE 

#include "higgs_Enviroment.hpp"

#ifndef higgs_Enviroment_Defined

#endif

#ifdef higgs_Windows

#endif

#ifdef higgs_ArduinoIDE
	#include "Arduino.h"
#endif

#include "NoteHelper.hpp"

#ifdef higgs_ETHERNET_LogApp
	#include "higgs_Logger_config.hpp"
	#include "higgs_Logger.hpp"
	
	#define higgs_ETHERNETLog(location,method,type,mns) higgs_Log(nullptr,location,"higgs_ETHERNET",method,type,mns)
#else
	#ifdef higgs_ETHERNET_LogDebugApp
		#include "higgs_Logger_config.hpp"
		#include "higgs_Logger.hpp"
		
		#define higgs_ETHERNETLog(location,method,type,mns) higgs_LogDebug(nullptr,location,"higgs_ETHERNET",method,type)
	#else
		#define higgs_ETHERNETLog(location,method,type,mns) 
	#endif
#endif

namespace ame{

#ifdef higgs_ArduinoIDE
void initializeETHERNET(IPAddress a_ip, IPAddress a_gateway, IPAddress a_subnet, int CS_pin, byte* mac){
	higgs_ETHERNETLog(higgs_Log_StartMethod, "initializeETHERNET",  "println", "IPAddress");
	higgs_ETHERNETLog(higgs_Log_StartMethod, "initializeETHERNET",  "println", "a_ip");
	higgs_ETHERNETLog(higgs_Log_StartMethod, "initializeETHERNET",  "println", a_ip);
	higgs_ETHERNETLog(higgs_Log_StartMethod, "initializeETHERNET",  "println", "a_gateway");
	higgs_ETHERNETLog(higgs_Log_StartMethod, "initializeETHERNET",  "println", a_gateway);
	higgs_ETHERNETLog(higgs_Log_StartMethod, "initializeETHERNET",  "println", "a_subnet");
	higgs_ETHERNETLog(higgs_Log_StartMethod, "initializeETHERNET",  "println", a_subnet);
	
	Ethernet.init(CS_pin);
	Ethernet.begin(mac, a_ip, a_gateway, a_subnet);
	
	higgs_ETHERNETLog(higgs_Log_StartMethod, "initializeETHERNET",  "println", "connected");
}

void initializeETHERNET(Note a_ip, Note a_gateway, Note a_subnet, int CS_pin, byte* mac){
	higgs_ETHERNETLog(higgs_Log_StartMethod, "initializeETHERNET",  "println", "Note");

	higgs_ETHERNETLog(higgs_Log_StartMethod, "initializeETHERNET",  "println", "a_ip");
	higgs_ETHERNETLog(higgs_Log_StartMethod, "initializeETHERNET",  "println", a_ip);
	higgs_ETHERNETLog(higgs_Log_StartMethod, "initializeETHERNET",  "println", "a_gateway");
	higgs_ETHERNETLog(higgs_Log_StartMethod, "initializeETHERNET",  "println", a_gateway);
	higgs_ETHERNETLog(higgs_Log_StartMethod, "initializeETHERNET",  "println", "a_subnet");
	higgs_ETHERNETLog(higgs_Log_StartMethod, "initializeETHERNET",  "println", a_subnet);
	
	initializeETHERNET(toIPAddress(a_ip), toIPAddress(a_gateway), toIPAddress(a_subnet), CS_pin, mac);
	higgs_ETHERNETLog(higgs_Log_StartMethod, "initializeETHERNET",  "println", "");
}

// void initializeETHERNET(Note a_ip, Note a_gateway, Note a_subnet, int CS_pin, ByteArray mac){
	// initializeETHERNET(a_ip.toIPAddress(), a_gateway.toIPAddress(), a_subnet.toIPAddress(), CS_pin, mac.pointer());
// }

void haltUntilEthernetConnection(){
	higgs_ETHERNETLog(higgs_Log_StartMethod, "haltUntilEthernetConnection",  "println", "");
	while (Ethernet.linkStatus() != LinkON) {
		higgs_ETHERNETLog(higgs_Log_StartMethod, "haltUntilEthernetConnection",  "println", ".");
		delay(1000);
	}
	higgs_ETHERNETLog(higgs_Log_EndMethod, "haltUntilEthernetConnection",  "println", "");
}


bool hasLAN(){
	return Ethernet.linkStatus() == LinkON;
}
#endif

}

#endif
