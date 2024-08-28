
#ifndef BufferProtocol_hpp
	#define BufferProtocol_hpp

	#include "PortProtocol.hpp"
	#include "SerialPort.hpp"

	#ifdef BufferProtocol_LogApp
		#include "pankey_Logger.hpp"
		#define BufferProtocolLog(location,method,type,mns) pankey_Log(nullptr,location,"BufferProtocol",method,type,mns)
	#else
		#define BufferProtocolLog(location,method,type,mns) 
	#endif

	namespace pankey{

		class BufferProtocol : public PortProtocol{	
			public:
				BufferProtocol(){}
				virtual ~BufferProtocol(){}
				
				virtual void InstantBroadcastMessage(SerialPort* port, const Note& mns){
					BufferProtocolLog(pankey_Log_Statement, "InstantBroadcastMessage",  "println", port->getName());
					BufferProtocolLog(pankey_Log_Statement, "InstantBroadcastMessage",  "println", mns);
					m_buffer.addPointers(port, new Note(mns));
				}
				
				virtual void InstantPrivateMessage(SerialPort* port, const Note& mns){
					BufferProtocolLog(pankey_Log_Statement, "InstantPrivateMessage",  "println", port->getName());
					BufferProtocolLog(pankey_Log_Statement, "InstantPrivateMessage",  "println", mns);
					m_buffer.addPointers(port, new Note(mns));
				}
				
				virtual void BroadcastMessage(SerialPort* port, const Note& mns){
					BufferProtocolLog(pankey_Log_Statement, "BroadcastMessage",  "println", port->getName());
					BufferProtocolLog(pankey_Log_Statement, "BroadcastMessage",  "println", mns);
					m_buffer.addPointers(port, new Note(mns));
				}
				virtual void PrivateMessage(SerialPort* port, const Note& mns){
					BufferProtocolLog(pankey_Log_Statement, "PrivateMessage",  "println", port->getName());
					BufferProtocolLog(pankey_Log_Statement, "PrivateMessage",  "println", mns);
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