
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

#ifndef DataBaseState_hpp
#define DataBaseState_hpp

#include "SerialListener.hpp"
#include "ObjectDataBaseConfig.hpp"
#include "ElementId.hpp"
#include "AppState.hpp"
#include "Arduino.h"
#include "DefaultMonkeyFile.hpp"
#include "SerialMessageState.hpp"
#include "MonkeyExporter.hpp"
#include "MonkeyImporter.hpp"
#include "TextExporter.hpp"
#include "TextImporter.hpp"
#include "SerialListener.hpp"
#include "PrimitiveList.hpp"
#include "MemoryRam.hpp"

#ifdef DataBaseStateLogApp
	#include "Logger.hpp"
	#define DataBaseStateLog(name,method,type,mns) Log(name,method,type,mns)
#else
	#define DataBaseStateLog(name,method,type,mns)
#endif

namespace ame{

class DataBaseState : public AppState , public SerialListener{
    public:
		DataBaseState(){
			DataBaseStateLog("DataBaseState", "Constructor",  "println", "");
			owner = true;
			exporter = new TextExporter();
			importer = new TextImporter();
			file = new DefaultMonkeyFile<SDFileSystemClass>(SD);
		}
		DataBaseState(MonkeyFile* f){
			DataBaseStateLog("DataBaseState", "Constructor",  "println", "");
			owner = true;
			exporter = new TextExporter();
			importer = new TextImporter();
			file = f;
		}
		
		DataBaseState(MonkeyExporter* e, MonkeyImporter* i, bool o){
			DataBaseStateLog("DataBaseState", "Constructor",  "println", "");
			owner = o;
			exporter = e;
			importer = i;
		}
		
		DataBaseState(MonkeyExporter* e, MonkeyImporter* i, MonkeyFile* f, bool o){
			DataBaseStateLog("DataBaseState", "Constructor",  "println", "");
			owner = o;
			exporter = e;
			importer = i;
			file = f;
		}
		
		virtual ~DataBaseState(){
			DataBaseStateLog("DataBaseState", "Destructor",  "println", "");
			if(owner){
				delete exporter;
				delete importer;
				if(file != nullptr){
					delete file;
				}
			}
		}
		
		virtual bool instanceof(cppObjectClass* cls){
			return cls == Class<DataBaseState>::classType;
		}
		
		virtual cppObjectClass* getClass(){return Class<DataBaseState>::classType;}
		
		virtual void initialize(Application *app){
			DataBaseStateLog("DataBaseState", "initialize",  "println", "start");
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
			DataBaseStateLog("DataBaseState", "initialize",  "println", "end");
		}
		
		virtual void execute(Message* message){
			DataBaseStateLog("DataBaseState", "execute",  "println", "start execute");
			if(file == nullptr || serialState == nullptr || exporter == nullptr || importer == nullptr){
				DataBaseStateLog("DataBaseState", "execute",  "println", "file == nullptr || serialState == nullptr || exporter == nullptr || importer == nullptr");
			}
			if(exporter == nullptr || importer == nullptr){
				return;
			}
			DataBaseStateLog("DataBaseState", "execute",  "println", message->text());
			importer->setMessage(message);
			
			// importer->fix();
			
			String command = importer->read(ElementId("DataBase.command"), String());
			String type = importer->read(ElementId("DataBase.type"), String());
			
			importer->remove(ElementId("DataBase.command"));
			importer->remove(ElementId("DataBase.type"));
			
			DataBaseConfig* config = configuration.getByLValue(type);
			
			if(config == nullptr || command == ""){
				DataBaseStateLog("DataBaseState", "execute",  "println", "config == nullptr || command.isEmpty");
				exporter->clear();
				importer->clear();
				return;
			}
			
			if(command == "put"){
				DataBaseStateLog("DataBaseState", "execute",  "println", "command == put");
				exporter->clear();
				config->put(exporter,importer,file,serialState);
			}
			
			if(command == "get"){
				DataBaseStateLog("DataBaseState", "execute",  "println", "command == get");
				exporter->clear();
				config->get(exporter,importer,file,serialState);
			}
			
			if(command == "delete"){
				DataBaseStateLog("DataBaseState", "execute",  "println", "command == delete");
				exporter->clear();
				config->erase(exporter,importer,file,serialState);
			}
			
			if(command == "copy"){
				DataBaseStateLog("DataBaseState", "execute",  "println", "command == copy");
				exporter->clear();
				config->copy(exporter,importer,file,serialState);
			}
			
			if(command == "cut"){
				DataBaseStateLog("DataBaseState", "execute",  "println", "command == cut");
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
		
		virtual DataBaseConfig* addDataBaseConfig(String name, DataBaseConfig* c){
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
		
		MonkeyFile* file = nullptr;
		
		PrimitiveMap<String,DataBaseConfig> configuration;
		
		bool init = false;
		bool owner = false;
};

}

#endif 

