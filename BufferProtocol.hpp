
#include "ame_Enviroment.hpp"

#if defined(DISABLE_BufferProtocol)
	#define BufferProtocol_hpp
#endif

#ifndef BufferProtocol_hpp
#define BufferProtocol_hpp
#define BufferProtocol_AVAILABLE

#ifndef ame_Enviroment_Defined

#endif

#ifdef ame_Windows

#endif

#ifdef ame_ArduinoIDE
	#include "Arduino.h"
#endif

#include "PortProtocol.hpp"
#include "SerialPort.hpp"

#ifdef BufferProtocol_LogApp
	#include "ame_Logger_config.hpp"
	#include "ame_Logger.hpp"
	
	#define BufferProtocolLog(location,method,type,mns) ame_Log(this,location,"BufferProtocol",method,type,mns)
	#define const_BufferProtocolLog(location,method,type,mns) 
	#define StaticBufferProtocolLog(pointer,location,method,type,mns) ame_Log(pointer,location,"BufferProtocol",method,type,mns)
#else
	#ifdef BufferProtocol_LogDebugApp
		#include "ame_Logger_config.hpp"
		#include "ame_Logger.hpp"
		
		#define BufferProtocolLog(location,method,type,mns) ame_LogDebug(this,location,"BufferProtocol",method,type)
		#define const_BufferProtocolLog(location,method,type,mns) 
		#define StaticBufferProtocolLog(pointer,location,method,type,mns) ame_LogDebug(pointer,location,"BufferProtocol",method,type)
	#else
		#define BufferProtocolLog(location,method,type,mns) 
		#define const_BufferProtocolLog(location,method,type,mns) 
		#define StaticBufferProtocolLog(pointer,location,method,type,mns) 
	#endif
#endif

namespace ame{

class BufferProtocol : public PortProtocol{	
    public:
		BufferProtocol(){}
		virtual ~BufferProtocol(){}
		
		virtual void InstantBroadcastMessage(SerialPort* port, const Note& mns){
			BufferProtocolLog(ame_Log_Statement, "InstantBroadcastMessage",  "println", port->getName());
			BufferProtocolLog(ame_Log_Statement, "InstantBroadcastMessage",  "println", mns);
			m_buffer.addPointers(port, new Note(mns));
		}
		
		virtual void InstantPrivateMessage(SerialPort* port, const Note& mns){
			BufferProtocolLog(ame_Log_Statement, "InstantPrivateMessage",  "println", port->getName());
			BufferProtocolLog(ame_Log_Statement, "InstantPrivateMessage",  "println", mns);
			m_buffer.addPointers(port, new Note(mns));
		}
		
		virtual void BroadcastMessage(SerialPort* port, const Note& mns){
			BufferProtocolLog(ame_Log_Statement, "BroadcastMessage",  "println", port->getName());
			BufferProtocolLog(ame_Log_Statement, "BroadcastMessage",  "println", mns);
			m_buffer.addPointers(port, new Note(mns));
		}
		virtual void PrivateMessage(SerialPort* port, const Note& mns){
			BufferProtocolLog(ame_Log_Statement, "PrivateMessage",  "println", port->getName());
			BufferProtocolLog(ame_Log_Statement, "PrivateMessage",  "println", mns);
			m_buffer.addPointers(port, new Note(mns));
		}
		
		virtual cppObjectClass* getClass(){return Class<BufferProtocol>::classType;}
		
		virtual bool instanceof(cppObjectClass* cls){
			return cls == Class<BufferProtocol>::classType || PortProtocol::instanceof(cls);
		}
		
		virtual Note getMessage(){
			Note* i_note = m_buffer.getByPosition(0);
			if(i_note == nullptr){
				return Note();
			}
			return *i_note;
		}
		
		virtual char getMessage(int x){
			Note* i_note = m_buffer.getByPosition(0);
			if(i_note == nullptr){
				return ' ';
			}
			return i_note->charAt(x);
		}
		
		virtual void nextMessage(){
			m_buffer.removeDeleteByPosition(0);
		}
	protected:
		PrimitiveMap<SerialPort,Note> m_buffer;
		
};

}

#endif