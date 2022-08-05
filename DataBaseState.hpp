
/*  
 *  DataBase.command
 *  1. put
 *  2. get
 *  3. delete
 *  4. copy
 *  4. cut
 *  
 *  DataBase.type
 *  1. object
 *  2. file
 *  3. 
 *  4. 
 *  5. 
 *
 */

#include "ame_Enviroment.hpp"

#if defined(DISABLE_DataBaseState)
	#define DataBaseState_hpp
#endif

#ifndef DataBaseState_hpp
#define DataBaseState_hpp
#define DataBaseState_AVAILABLE

#ifndef ame_Enviroment_Defined

#endif

#ifdef ame_Windows

#endif

#ifdef ame_ArduinoIDE
	#include "Arduino.h"
#endif

#include "SerialListener.hpp"
#include "ObjectDataBaseConfig.hpp"
#include "ElementId.hpp"
#include "AppState.hpp"
#include "DefaultMonkeyFile.hpp"
#include "SerialMessageState.hpp"
#include "MonkeyExporter.hpp"
#include "MonkeyImporter.hpp"
#include "TextExporter.hpp"
#include "TextImporter.hpp"
#include "SerialListener.hpp"
#include "PrimitiveList.hpp"
#include "AlwaysConnected.hpp"
#include "MemoryRam.h"

#include "ame_Logger_config.hpp"
#include "ame_Logger.hpp"

#ifdef DataBaseState_LogApp
	#define DataBaseStateLog(location,method,type,mns) ame_Log(this,location,"Note",method,type,mns)
	#define const_DataBaseStateLog(location,method,type,mns) 
	#define StaticDataBaseStateLog(pointer,location,method,type,mns) ame_Log(pointer,location,"Note",method,type,mns)
#else
	#define DataBaseStateLog(location,method,type,mns) ame_LogDebug(this,location,"Note",method,type)
	#define const_NoteLog(location,method,type,mns) 
	#define StaticNoteLog(pointer,location,method,type,mns) ame_LogDebug(pointer,location,"Note",method,type)
#endif

namespace ame{

class DataBaseState : public AppState , public SerialListener{
    public:
		DataBaseState(){
			DataBaseStateLog(ame_Log_Statement, "Constructor",  "println", "");
			owner = true;
			exporter = new TextExporter();
			importer = new TextImporter();
			file = new DefaultMonkeyFile<SDFileSystemClass>(SD);
		}
		DataBaseState(MonkeyFile* f){
			DataBaseStateLog(ame_Log_Statement, "Constructor",  "println", "");
			owner = true;
			exporter = new TextExporter();
			importer = new TextImporter();
			file = f;
		}
		
		DataBaseState(MonkeyExporter* e, MonkeyImporter* i, bool o){
			DataBaseStateLog(ame_Log_Statement, "Constructor",  "println", "");
			owner = o;
			exporter = e;
			importer = i;
		}
		
		DataBaseState(MonkeyExporter* e, MonkeyImporter* i, MonkeyFile* f, bool o){
			DataBaseStateLog(ame_Log_Statement, "Constructor",  "println", "");
			owner = o;
			exporter = e;
			importer = i;
			file = f;
		}
		
		virtual ~DataBaseState(){
			DataBaseStateLog(ame_Log_Statement, "Destructor",  "println", "");
			if(owner){
				delete exporter;
				delete importer;
				if(file != nullptr){
					delete file;
				}
			}
		}
		
		virtual bool instanceof(cppObjectClass* cls){
			return cls == Class<DataBaseState>::classType || AppState::instanceof(cls);
		}
		
		virtual cppObjectClass* getClass(){return Class<DataBaseState>::classType;}
		
		virtual void initialize(Application *app){
			DataBaseStateLog(ame_Log_Statement, "initialize",  "println", "start");
			AppState* m_state = app->getStateManager()->get(Class<SerialMessageState>::classType);
			if(m_state == nullptr){
				return;
			}
			serialState = (SerialMessageState*)m_state;
			serialState->addListener(this);
			for(int x = 0; x< configuration.getPosition(); x++){
				DataBaseConfig* c = configuration.getByPosition(x);
				c->initialize(exporter, importer, file, serialState);
			}
			init = true;
			DataBaseStateLog(ame_Log_Statement, "initialize",  "println", "end");
			if(file == nullptr){
				return;
			}
			file->initialize();
		}
		
		virtual void execute(Message* message){
			DataBaseStateLog(ame_Log_Statement, "execute",  "println", "start execute");
			if(file == nullptr || serialState == nullptr || exporter == nullptr || importer == nullptr){
				DataBaseStateLog(ame_Log_Statement, "execute",  "println", "file == nullptr || serialState == nullptr || exporter == nullptr || importer == nullptr");
			}
			if(exporter == nullptr || importer == nullptr){
				return;
			}
			DataBaseStateLog(ame_Log_Statement, "execute",  "println", message->text());
			importer->setMessage(message);
			// DataBaseStateLog(ame_Log_Statement, "execute",  "println", importer->toNote());
			
			Note command = importer->getTag(ElementId("DataBase.command"));
			Note type = importer->getTag(ElementId("DataBase.type"));
			
			importer->removeTag(ElementId("DataBase.command"));
			importer->removeTag(ElementId("DataBase.type"));
			
			DataBaseConfig* config = configuration.getByLValue(type);
			
			if(config == nullptr || command == ""){
				DataBaseStateLog(ame_Log_Statement, "execute",  "println", "config == nullptr || command.isEmpty");
				exporter->clear();
				importer->clear();
				return;
			}
			
			if(command == "put"){
				DataBaseStateLog(ame_Log_Statement, "execute",  "println", "command == put");
				exporter->clear();
				config->put(exporter,importer,file,serialState);
			}
			
			if(command == "get"){
				DataBaseStateLog(ame_Log_Statement, "execute",  "println", "command == get");
				exporter->clear();
				config->get(exporter,importer,file,serialState);
			}
			
			if(command == "delete"){
				DataBaseStateLog(ame_Log_Statement, "execute",  "println", "command == delete");
				exporter->clear();
				config->erase(exporter,importer,file,serialState);
			}
			
			if(command == "copy"){
				DataBaseStateLog(ame_Log_Statement, "execute",  "println", "command == copy");
				exporter->clear();
				config->copy(exporter,importer,file,serialState);
			}
			
			if(command == "cut"){
				DataBaseStateLog(ame_Log_Statement, "execute",  "println", "command == cut");
				exporter->clear();
				config->cut(exporter,importer,file,serialState);
			}
			
			exporter->clear();
			importer->clear();
		}
		
		virtual void update(float tpc){
			if(serialState == nullptr){
				return;
			}
			for(int x = 0; x < configuration.getPosition(); x++){
				DataBaseConfig* config = configuration.getByPosition(x);
				config->update(tpc);
			}
		}
		
		virtual DataBaseConfig* addDataBaseConfig(Note name, DataBaseConfig* c){
			configuration.addPointer(name, c);
			if(init){
				c->initialize(exporter, importer, file, serialState);
			}
			return c;
		}
	protected:
		MonkeyExporter* exporter = nullptr;
		MonkeyImporter* importer = nullptr;
		
		SerialMessageState* serialState = nullptr;
		AlwaysConnected* alwaysConnectedState = nullptr;
		
		MonkeyFile* file = nullptr;
		
		PrimitiveMap<Note,DataBaseConfig> configuration;
		
		bool init = false;
		bool owner = false;
};

}

#endif