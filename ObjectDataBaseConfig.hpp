/*	
**	DataBase.project.name
**	DataBase.project.dir
**	DataBase.project.id
**	
**	
**	Layers: 3
**	
**	Layer 1:
**	ask for project name, if there is not, search on the greenFile
**	
**	
*/	

#include "ame_Enviroment.hpp"

#if defined(DISABLE_ObjectDataBaseConfig)
	#define ObjectDataBaseConfig_hpp
#endif

#ifndef ObjectDataBaseConfig_hpp
#define ObjectDataBaseConfig_hpp
#define ObjectDataBaseConfig_AVAILABLE

#ifndef ame_Enviroment_Defined

#endif

#ifdef ame_Windows

#endif

#ifdef ame_ArduinoIDE
	#include "Arduino.h"
#endif

#include "DataBaseConfig.hpp"
#include "MonkeyFile.hpp"
#include "SerialMessageState.hpp"
#include "MonkeyExporter.hpp"
#include "MonkeyImporter.hpp"
#include "TextExporter.hpp"
#include "TextImporter.hpp"
#include "MemoryRam.h"

#include "ame_Logger_config.hpp"
#include "ame_Logger.hpp"

#ifdef ObjectDataBaseConfig_LogApp
	#define ObjectDataBaseConfigLog(location,method,type,mns) ame_Log(this,location,"Note",method,type,mns)
	#define const_ObjectDataBaseConfigLog(location,method,type,mns) 
	#define StaticObjectDataBaseConfigLog(pointer,location,method,type,mns) ame_Log(pointer,location,"Note",method,type,mns)
#else
	#define ObjectDataBaseConfigLog(location,method,type,mns) ame_LogDebug(this,location,"Note",method,type)
	#define const_ObjectDataBaseConfigLog(location,method,type,mns) 
	#define StaticObjectDataBaseConfigLog(pointer,location,method,type,mns) ame_LogDebug(pointer,location,"Note",method,type)
#endif

namespace ame{

class ObjectDataBaseConfig : public DataBaseConfig{
    public:
		ObjectDataBaseConfig(){}
		virtual ~ObjectDataBaseConfig(){}
		
		virtual void initialize(MonkeyExporter* exporter, MonkeyImporter* importer, MonkeyFile* file, SerialMessageState* serialState){
			if(file == nullptr || serialState == nullptr || exporter == nullptr || importer == nullptr){
				return;
			}
			ObjectDataBaseConfigLog(ame_Log_Statement, "initialize", "println", "");
			Note rootPath = file->fixPath(rootDir);
			Note tag_path = file->fixPath(rootPath, tagPath);
			if(!file->exist(rootPath)){
				file->createDir(rootPath);
			}
			if(!file->exist(tag_path)){
				file->createFile(tag_path);
			}
			ObjectDataBaseConfigLog(ame_Log_Statement, "initialize", "println", "");
		}
		
		virtual void put(MonkeyExporter* exporter, MonkeyImporter* importer, MonkeyFile* file, SerialMessageState* serialState){
			if(file == nullptr || serialState == nullptr || exporter == nullptr || importer == nullptr){
				return;
			}
			ObjectDataBaseConfigLog(ame_Log_Statement, "put", "println", "");
			
			Note project_dir = importer->getTag("DataBase.project");
			
			
			ObjectDataBaseConfigLog(ame_Log_Statement, "put",  "println", "");
		}
			
		virtual void get(MonkeyExporter* exporter, MonkeyImporter* importer, MonkeyFile* file, SerialMessageState* serialState){
			if(file == nullptr || serialState == nullptr || exporter == nullptr || importer == nullptr){
				return;
			}
			ObjectDataBaseConfigLog(ame_Log_Statement, "get",  "println", "");
			
			Note project_dir = importer->getTag("DataBase.project");
			if(project_dir == ""){
				return;
			}
			importer->removeTag("DataBase.project");
			
			Note project_folder_path = file->fixPath(rootDir, project_dir);
			Note project_folder_tag_path = file->fixPath(project_folder_path, tagPath);
			Note project_folder_helper_path = file->fixPath(project_folder_path, helperPath);
			
			if(!file->exist(project_folder_path)){
				ObjectDataBaseConfigLog(ame_Log_Statement, "put", "println", "!file->exist(project_folder_path)");
				// ObjectDataBaseConfigLog(ame_Log_Statement, "put", "println", Note("project_folder_path ") + project_folder_path);
				return;
			}
			
			Note folder_dir = importer->getTag("DataBase.dir");
			
			if(folder_dir == ""){
				ObjectDataBaseConfigLog(ame_Log_Statement, "put",  "println", "folder_dir.isEmpty");
				return;
			}
			
			ElementId id = importer->getTag("DataBase.id");
			
			if(id == ""){
				ObjectDataBaseConfigLog(ame_Log_Statement, "get",  "println", "id.isEmpty");
				return;
			}
			
			importer->removeTag("DataBase.id");
			
			Note objMap_path = file->fixPath(folder_dir, idRegisterPath);
			
			TextImporter textImporter = file->fastReadText(objMap_path);
			Note idPath = textImporter.read(id, "");
			
			if(idPath == ""){
				ObjectDataBaseConfigLog(ame_Log_Statement, "get",  "println", "path.isEmpty");
				return;
			}
			// ObjectDataBaseConfigLog(ame_Log_Statement, "get",  "println", Note("idPath ") + Note(idPath));
			
			Note port = importer->getTag("DataBase.port");
			Note idText = file->fastReadText(idPath);
			
			if(port == ""){
				ObjectDataBaseConfigLog(ame_Log_Statement, "get",  "println", "broadcast");
				serialState->send(idText);
			}else{
				ObjectDataBaseConfigLog(ame_Log_Statement, "get",  "println", "not broadcast");
				importer->removeTag("DataBase.port");
				serialState->send(port.toInt(), idText);
			}
			// ObjectDataBaseConfigLog(ame_Log_Statement, "get",  "println", Note("sending ") + objTextImporter.getText());
			// exporter->clear();
			// exporter->read(file, idPath);
		}
			 
		virtual void erase(MonkeyExporter* exporter, MonkeyImporter* importer, MonkeyFile* file, SerialMessageState* serialState){
			if(file == nullptr || serialState == nullptr || exporter == nullptr || importer == nullptr){
				return;
			}
			Note all = importer->read("DataBase.All", "");
			
			Note rootPath = file->fixPath(rootDir);
			Note path = file->fixPath(rootPath, tagPath);
			
			if(all != ""){
				ObjectDataBaseConfigLog(ame_Log_Statement, "get",  "println", "delete all");
				file->deleteFile(path);
				return;
			}
			
			ElementId id = importer->read("DataBase.id", ElementId());
			
			if(id == ""){
				ObjectDataBaseConfigLog(ame_Log_Statement, "get",  "println", "id.isEmpty");
				return;
			}
			
			importer->remove("DataBase.id");
			
			TextImporter textImporter = file->fastReadText(path);
			Note idPath = textImporter.read(id, "");
			
			if(idPath == ""){
				return;
			}
			
			textImporter.remove(id);
			
			file->fastClearFile(path);
			file->writeText(textImporter.getText(), path);
			
			file->deleteFile(idPath);
		}
			
		virtual void copy(MonkeyExporter* exporter, MonkeyImporter* importer, MonkeyFile* file, SerialMessageState* serialState){
			if(file == nullptr || serialState == nullptr || exporter == nullptr || importer == nullptr){
				return;
			}
			ElementId id = importer->read("DataBase.id", ElementId());
			
			if(id == ""){
				return;
			}
			
			importer->remove("DataBase.id");
			
			Note rootPath = file->fixPath(rootDir);
			Note path = file->fixPath(rootPath, tagPath);
			
			TextImporter textImporter = file->fastReadText(path);
			Note idPath = textImporter.read(id, "");
			Note copyPath = importer->read("DataBase.copy.path", "");
			
			if(idPath == "" || copyPath == ""){
				return;
			}
			
			Note f_1 = file->fastReadText(idPath);
			file->writeText(f_1, copyPath);
		}
			
		virtual void cut(MonkeyExporter* exporter, MonkeyImporter* importer, MonkeyFile* file, SerialMessageState* serialState){
			if(file == nullptr || serialState == nullptr || exporter == nullptr || importer == nullptr){
				return;
			}
			ElementId id = importer->read("DataBase.id", ElementId());
			
			if(id == ""){
				return;
			}
			
			importer->remove("DataBase.id");
			
			Note rootPath = file->fixPath(rootDir);
			Note path = file->fixPath(rootPath, tagPath);
			
			TextImporter textImporter = file->fastReadText(path);
			Note idPath = textImporter.read(id, "");
			Note copyPath = importer->read("DataBase.cut.path", "");
			
			if(idPath == "" || copyPath == ""){
				return;
			}
			
			Note f_1 = file->fastReadText(idPath);
			file->writeText(f_1, copyPath);
			file->deleteFile(idPath);
		}
		
		virtual void setFileSize(int s){
			fileSize = s;
		}
		
	protected:
		Note rootDir = "DataBase";
		Note tagPath = "Tags.txt";
		Note helperPath = "Helper.txt";
		
		Note idRegisterPath = "idRegister.txt";
		
		int fileSize = 50;
		
		Note m_idName = "object";
		Note m_fileName = "object";
		Note m_folderName = "object";
};

}

#endif