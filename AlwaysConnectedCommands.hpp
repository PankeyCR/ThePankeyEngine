
#ifndef AlwaysConnectedCommands_hpp
#define AlwaysConnectedCommands_hpp
#define AlwaysConnectedCommands_AVAILABLE

#include "Note.hpp"
#include "AlwaysConnected.hpp"
#include "MemoryRam.hpp"

#ifdef AlwaysConnectedCommands_LogApp
	#include "ame_Logger_config.hpp"
	#include "ame_Logger.hpp"
	
	#define AlwaysConnectedCommandsLog(location,method,type,mns) ame_Log(nullptr,location,"AlwaysConnectedCommands",method,type,mns)
#else
	#ifdef AlwaysConnectedCommands_LogDebugApp
		#include "ame_Logger_config.hpp"
		#include "ame_Logger.hpp"
		
		#define AlwaysConnectedCommandsLog(location,method,type,mns) ame_LogDebug(nullptr,location,"AlwaysConnectedCommands",method,type)
	#else
		#define AlwaysConnectedCommandsLog(location,method,type,mns) 
	#endif
#endif

namespace ame{

AlwaysConnected* g_alwaysConnected = nullptr;

void setAlwaysConnected(AlwaysConnected* a_state){
	g_alwaysConnected = a_state;
}

void AlwaysConnectedCommands(Note* message){
	if (message == nullptr || g_alwaysConnected == nullptr) {
		System::console.println("message == nullptr || g_alwaysConnected == nullptr");
		return;
	}
	System::console.println("AlwaysConnectedCommands");
	
	Note mns = *message;
	PrimitiveList<Note> commands = splitNote(mns, ' ');

	if (mns == "ram") {
		System::console.print("ram: ");
		System::console.println(getRamSize());
	}
}

}

#endif