
#include "ame_Enviroment.hpp"

#if defined(DISABLE_SerialNetwork)
	#define SerialNetwork_hpp
#endif

#ifndef SerialNetwork_hpp
#define SerialNetwork_hpp
#define SerialNetwork_AVAILABLE

#ifndef ame_Enviroment_Defined

#endif

#ifdef ame_Windows

#endif

#ifdef ame_ArduinoIDE
	#include "Arduino.h"
#endif

#include "AppState.hpp"
#include "cppObjectClass.hpp"
#include "Class.hpp"
#include "Note.hpp"
#include "ByteArray.hpp"

namespace ame{

class SerialNetwork : public AppState{	
    public:	
		virtual ~SerialNetwork(){}
		
		virtual void instantSend(Note a_message){}
		
		virtual void instantSend(ByteArray a_message){}

		void instantSend(Note a_name, Note a_message){}

		void instantSend(Note a_name, ByteArray a_message){}
		
		void send(Note a_message){}
		
		void send(ByteArray a_message){}

		void send(Note a_name, Note a_message){}

		void send(Note a_name, ByteArray a_message){}
		
		bool isConnected(Note a_name){return false;}
    
		void connect() {}
		
		void connect(Note a_name) {}
		    
		void disconect() {}
		
		void disconect(Note a_name) {}
		
		virtual bool ping(Note a_name){
			return false;
		}
			
		virtual cppObjectClass* getClass(){
			return Class<SerialNetwork>::classType;
		}
		
		virtual bool instanceof(cppObjectClass* cls){
			return cls == Class<SerialNetwork>::getClass() || AppState::instanceof(cls);
		}

		virtual void operator=(SerialNetwork obj){}
		virtual bool operator==(SerialNetwork obj){return false;}
		virtual bool operator!=(SerialNetwork obj){return false;}
		
	protected:
};

}

#endif