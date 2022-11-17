
#ifndef EthernetCommands_hpp
#define EthernetCommands_hpp
#define EthernetCommands_AVAILABLE

#include "Note.hpp"
#include "SerialState.hpp"
#include "MemoryRam.hpp"
#include "System.hpp"

#ifdef EthernetCommands_LogApp
	#include "ame_Logger_config.hpp"
	#include "ame_Logger.hpp"
	
	#define EthernetCommandsLog(location,method,type,mns) ame_Log(this,location,"EthernetCommands",method,type,mns)
	#define const_EthernetCommandsLog(location,method,type,mns) 
	#define StaticEthernetCommandsLog(pointer,location,method,type,mns) ame_Log(pointer,location,"EthernetCommands",method,type,mns)
#else
	#ifdef EthernetCommands_LogDebugApp
		#include "ame_Logger_config.hpp"
		#include "ame_Logger.hpp"
		
		#define EthernetCommandsLog(location,method,type,mns) ame_LogDebug(this,location,"EthernetCommands",method,type)
		#define const_EthernetCommandsLog(location,method,type,mns) 
		#define StaticEthernetCommandsLog(pointer,location,method,type,mns) ame_LogDebug(pointer,location,"EthernetCommands",method,type)
	#else
		#define EthernetCommandsLog(location,method,type,mns) 
		#define const_EthernetCommandsLog(location,method,type,mns) 
		#define StaticEthernetCommandsLog(pointer,location,method,type,mns) 
	#endif
#endif

namespace ame{

SerialState* g_serialState = nullptr;

void setSerialState(SerialState* a_state){
	g_serialState = a_state;
}

void EthernetCommands(Note* message){
	if (message == nullptr || g_serialState == nullptr) {
		System::console.println("message == nullptr || g_serialState == nullptr");
		return;
	}
	System::console.println("EthernetCommands");
	
	Note mns = *message;

	if (mns == "ram") {
		System::console.print("ram: ");
		System::console.println(getRamSize());
	}
}

}

#endif