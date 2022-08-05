
#include "ame_Enviroment.hpp"

#if defined(DISABLE_ame_ETHERNET)
	#define ame_ETHERNET_hpp
#endif

#ifndef ame_ETHERNET_hpp
#define ame_ETHERNET_hpp
#define ame_ETHERNET_AVAILABLE

#ifndef ame_Enviroment_Defined

#endif

#ifdef ame_Windows

#endif

#ifdef ame_ArduinoIDE
	#include "Arduino.h"
#endif

#ifdef ame_ETHERNETLogApp
	#include "Logger.hpp"
	#define ame_ETHERNETLog(name,method,type,mns) Log(name,method,type,mns)
#else
	#define ame_ETHERNETLog(name,method,type,mns)
#endif

namespace ame{

#ifdef ame_ArduinoIDE
void initializeETHERNET(IPAddress a_ip, IPAddress a_gateway, IPAddress a_subnet, int CS_pin, byte* mac){
	ame_ETHERNETLog("ame_ETHERNET", "initializeETHERNET",  "println", "");
	
	Ethernet.init(CS_pin);
	Ethernet.begin(mac, a_ip, a_gateway, a_subnet);
	
	ame_ETHERNETLog("ame_ETHERNET", "initializeETHERNET",  "println", "connected");
}

void initializeETHERNET(Note a_ip, Note a_gateway, Note a_subnet, int CS_pin, byte* mac){
	initializeETHERNET(toIPAddress(a_ip), toIPAddress(a_gateway), toIPAddress(a_subnet), CS_pin, mac);
}

// void initializeETHERNET(Note a_ip, Note a_gateway, Note a_subnet, int CS_pin, ByteArray mac){
	// initializeETHERNET(a_ip.toIPAddress(), a_gateway.toIPAddress(), a_subnet.toIPAddress(), CS_pin, mac.pointer());
// }


bool hasLAN(){
	return Ethernet.linkStatus() == LinkON;
}
#endif

}

#endif
