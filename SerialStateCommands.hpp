
#ifndef SerialStateCommands_hpp
#define SerialStateCommands_hpp
#define SerialStateCommands_AVAILABLE

#include "Note.hpp"
#include "SerialState.hpp"
#include "NoteHelper.hpp"
#include "MemoryRam.hpp"

#ifdef SerialStateCommands_LogApp
	#include "higgs_Logger_config.hpp"
	#include "higgs_Logger.hpp"
	
	#define SerialStateCommandsLog(location,method,type,mns) higgs_Log(nullptr,location,"SerialStateCommands",method,type,mns)
#else
	#ifdef SerialStateCommands_LogDebugApp
		#include "higgs_Logger_config.hpp"
		#include "higgs_Logger.hpp"
		
		#define SerialStateCommandsLog(location,method,type,mns) higgs_LogDebug(nullptr,location,"SerialStateCommands",method,type)
	#else
		#define SerialStateCommandsLog(location,method,type,mns) 
	#endif
#endif

namespace higgs{

class SerialStateCommands : public Command<Note>{
	public:
		SerialStateCommands(){
			SerialStateCommandsLog(higgs_Log_StartMethod, "Constructor",  "println", "");
			SerialStateCommandsLog(higgs_Log_EndMethod, "Constructor",  "println", "");
		}
		SerialStateCommands(SerialState* a_serial){
			SerialStateCommandsLog(higgs_Log_StartMethod, "Constructor",  "println", "");
			m_serialState = a_serial;
			SerialStateCommandsLog(higgs_Log_EndMethod, "Constructor",  "println", "");
		}
		virtual ~SerialStateCommands(){
			SerialStateCommandsLog(higgs_Log_StartMethod, "Destructor",  "println", "");
			SerialStateCommandsLog(higgs_Log_EndMethod, "Destructor",  "println", "");
		}

		virtual void execute(const Note& message){
			SerialStateCommandsLog(higgs_Log_StartMethod, "Destructor",  "println", "");
			if(m_serialState == nullptr) {
				System::console.println("message == nullptr || m_serialState == nullptr");
				return;
			}
			System::console.println("SerialStateCommands");
			
			PrimitiveList<Note> commands = splitNote(message, ' ');

			if(commands.getPosition() == 1){
				Note command_0 = commands[0];

				if (command_0 == "getSerialPortSize") {
					m_serialState->instantSend("SerialPort Size");
					m_serialState->instantSend(Note(m_serialState->getSerialPortSize()));
				}
			}

			if(commands.getPosition() == 2){
				Note command_0 = commands[0];
				Note command_1 = commands[1];

				if (command_0 == "broadcastSerialState") {
					m_serialState->instantSend(command_1);
				}
			}
			SerialStateCommandsLog(higgs_Log_EndMethod, "Destructor",  "println", "");
		}

	protected:
		SerialState* m_serialState = nullptr;
};

}

#endif