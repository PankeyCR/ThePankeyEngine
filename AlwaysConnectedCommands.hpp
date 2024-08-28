
#ifndef AlwaysConnectedCommands_hpp
	#define AlwaysConnectedCommands_hpp

	#include "Note.hpp"
	#include "AlwaysConnected.hpp"
	#include "MemoryRam.hpp"

	#ifdef AlwaysConnectedCommands_LogApp
		#include "pankey_Logger.hpp"
		#define AlwaysConnectedCommandsLog(location,method,type,mns) pankey_Log(nullptr,location,"AlwaysConnectedCommands",method,type,mns)
	#else
		#define AlwaysConnectedCommandsLog(location,method,type,mns) 
	#endif

	namespace pankey{

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