
#include "ame_Enviroment.hpp"

#if defined(DISABLE_ImporterListenerState)
	#define ImporterListenerState_hpp
#endif

#ifndef ImporterListenerState_hpp
#define ImporterListenerState_hpp
#define ImporterListenerState_AVAILABLE

#ifndef ame_Enviroment_Defined

#endif

#ifdef ame_Windows

#endif

#ifdef ame_ArduinoIDE
	#include "Arduino.h"
#endif

#include "ServerProtocol.hpp"
#include "PortProtocol.hpp"
#include "SerialServer.hpp"
#include "SerialPort.hpp"
#include "Application.hpp"
#include "AppState.hpp"
#include "Command.hpp"
#include "List.hpp"
#include "PrimitiveList.hpp"
#include "Map.hpp"
#include "PrimitiveMap.hpp"
#include "SerialConnectionStateChanger.hpp"
#include "Message.hpp"
#include "SerialListener.hpp"

#include "ame_Logger_config.hpp"
#include "ame_Logger.hpp"

#ifdef ImporterListenerState_LogApp
	#define ImporterListenerStateLog(location,method,type,mns) ame_Log(this,location,"ImporterListenerState",method,type,mns)
	#define const_ImporterListenerStateLog(location,method,type,mns) 
	#define StaticImporterListenerStateLog(pointer,location,method,type,mns) ame_Log(pointer,location,"ImporterListenerState",method,type,mns)
#else
	#define ImporterListenerStateLog(location,method,type,mns) ame_LogDebug(this,location,"ImporterListenerState",method,type)
	#define const_ImporterListenerStateLog(location,method,type,mns) 
	#define StaticImporterListenerStateLog(pointer,location,method,type,mns) ame_LogDebug(pointer,location,"ImporterListenerState",method,type)
#endif

namespace ame{

class ImporterListenerState : public AppState{	
    public:
		// using ImporterListenerMethod = void (*)(SerialImporter*);
		
		Application* app;
		
		ImporterListenerState(){
			ImporterListenerStateLog(ame_Log_StartMethod, "Constructor", "println", "");
			
			// receivedSerialImporter = new PrimitiveList<SerialImporter>();
			// importerListener = new PrimitiveList<SerialImporterListener>();
			// methodImporterListener = new PrimitiveList<ImporterListenerMethod>();
			
			ImporterListenerStateLog(ame_Log_EndMethod, "Constructor", "println", "");
		}
		virtual ~ImporterListenerState(){
			ImporterListenerStateLog(ame_Log_StartMethod, "Destructor", "println", "");
			
			// delete receivedSerialImporter;
			// delete importerListener;
			// delete methodImporterListener;
			
			ImporterListenerStateLog(ame_Log_EndMethod, "Destructor", "println", "");
		}
		
		// SerialImporterListener* addListener(SerialImporterListener* mnsCmd){
			//////ImporterListenerStateLog(ame_Log_Statement, "addListener",  "println", "");
			// mnsCmd->setSerialState(this);
			// importerListener->addPointer(mnsCmd);
			// return mnsCmd;
		// }
		
		// void addListener(ImporterListenerMethod method){
			//////ImporterListenerStateLog(ame_Log_Statement, "addListener",  "println", "");
			// methodImporterListener->add(method);
		// }
		
		// SerialImporterListener* getSerialImporterListener(cppObjectClass* cls){
			//////ImporterListenerStateLog(ame_Log_Statement, "getSerialImporterListener",  "println", "");
			// for(int x = 0; x < importerListener->getPosition(); x++){
				// SerialImporterListener* serialListener = importerListener->getByPosition(x);
				// if(serialListener->getClass() == cls){
					// return serialListener;
				// }
			// }
			// return nullptr;
		// }

		// void removeDeleteSerialImporterListener(int index) {
			//////ImporterListenerStateLog(ame_Log_Statement, "removeDeleteSerialImporterListener",  "println", "");
			//////ImporterListenerStateLog(ame_Log_Statement, "removeDeleteSerialImporterListener",  "println", Note("index: ") + Note(index));
			// importerListener->removeDeleteByPosition(index);
		// }

		void removeAllListener() {
			ImporterListenerStateLog(ame_Log_Statement, "removeAllListener",  "println", "");
			importerListener->resetDelete();
		}
		
		// void addReceivedSerialImporter(SerialImporter* m){
			// receivedSerialImporter->addPointer(m);
		// }
		
		// List<SerialImporter>* getSerialImporters(){
			// return receivedSerialImporter;
		// }
		
		virtual void update(float tpc){
			for(int x = 0; x < receivedSerialImporter->getPosition(); x++){
				for(int y = 0; y < methodImporterListener->getPosition(); y++){
					ImporterListenerMethod  event = *methodImporterListener->getByPosition(y);
					event(receivedSerialImporter->getByPosition(x));
				}
				for(int y = 0; y < importerListener->getPosition(); y++){
					importerListener->getByPosition(y)->execute(receivedSerialImporter->getByPosition(x));
				}
			}
			receivedSerialImporter->resetDelete();
		}
		
	protected:
		//Importer
		List<SerialImporter>* receivedSerialImporter = nullptr;
		
		List<SerialImporterListener>* importerListener = nullptr;
		
		List<ImporterListenerMethod>* methodImporterListener = nullptr;
};

}

#endif