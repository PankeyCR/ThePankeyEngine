
#include "ame_Enviroment.hpp"

#if defined(DISABLE_FileDataBaseConfig)
	#define FileDataBaseConfig_hpp
#endif

#ifndef FileDataBaseConfig_hpp
#define FileDataBaseConfig_hpp
#define FileDataBaseConfig_AVAILABLE

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
#include "ExporterImporterHelper.hpp"

#ifdef FileDataBaseConfigLogApp
	#include "Logger.hpp"
	#define FileDataBaseConfigLog(name,method,type,mns) Log(name,method,type,mns)
#else
	#define FileDataBaseConfigLog(name,method,type,mns)
#endif

namespace ame{

class FileDataBaseConfig : public DataBaseConfig{
    public:
		FileDataBaseConfig(){}
		virtual ~FileDataBaseConfig(){}
		
		virtual void initialize(MonkeyExporter* exporter, MonkeyImporter* importer, MonkeyFile* file, SerialMessageState* serialState){
			if(file == nullptr || serialState == nullptr || exporter == nullptr || importer == nullptr){
				return;
			}
			
			FileDataBaseConfigLog("FileDataBaseConfig", "initialize",  "println", "");
		}
		
		virtual void put(MonkeyExporter* exporter, MonkeyImporter* importer, MonkeyFile* file, SerialMessageState* serialState){
			if(file == nullptr || serialState == nullptr || exporter == nullptr || importer == nullptr){
				return;
			}
			FileDataBaseConfigLog("FileDataBaseConfig", "put",  "println", "");
			Note dir = importer->read("DataBase.dir", Note());
			Note n_path = importer->read("DataBase.path", Note());
			
			if(dir == "" || n_path == ""){
				FileDataBaseConfigLog("FileDataBaseConfig", "put",  "println", "id.isEmpty");
				return;
			}
			
			importer->remove("DataBase.dir");
			importer->remove("DataBase.path");
			
			Note rootPath = file->fixPath(dir);
			Note path = file->fixPath(dir, n_path);
			
			if(path == ""){
				FileDataBaseConfigLog("FileDataBaseConfig", "put",  "println", "path.isEmpty");
				return;
			}
			
			if(!file->exist(rootPath)){
				FileDataBaseConfigLog("FileDataBaseConfig", "put",  "println", "create rootPath");
				file->createDir(rootPath);
			}
			if(!file->exist(path)){
				FileDataBaseConfigLog("FileDataBaseConfig", "put",  "println", "create path");
				file->createFile(path);
			}
			
			FileDataBaseConfigLog("FileDataBaseConfig", "put",  "println", Note("n_path ") + Note(n_path));
			FileDataBaseConfigLog("FileDataBaseConfig", "put",  "println", Note("path ") + Note(path));
			
			importer->write(file, path);
		}
			
		virtual void get(MonkeyExporter* exporter, MonkeyImporter* importer, MonkeyFile* file, SerialMessageState* serialState){
			if(file == nullptr || serialState == nullptr || exporter == nullptr || importer == nullptr){
				return;
			}
			FileDataBaseConfigLog("FileDataBaseConfig", "get",  "println", "");
			Note dir = importer->read("DataBase.dir", Note());
			Note n_path = importer->read("DataBase.path", Note());
			UUID uuid = importer->read("DataBase.uuid", UUID());
			
			if(dir == "" || n_path == ""){
				FileDataBaseConfigLog("FileDataBaseConfig", "get",  "println", "id.isEmpty");
				return;
			}
			
			importer->remove("DataBase.dir");
			importer->remove("DataBase.path");
			importer->remove("DataBase.uuid");
			
			Note rootPath = file->fixPath(dir);
			Note path = file->fixPath(dir, n_path);
			
			if(path == ""){
				FileDataBaseConfigLog("FileDataBaseConfig", "get",  "println", "path.isEmpty");
				return;
			}
			if(!file->exist(path)){
				FileDataBaseConfigLog("FileDataBaseConfig", "put",  "println", "no available path");
				return;
			}
			FileDataBaseConfigLog("FileDataBaseConfig", "get",  "println", Note("n_path ") + Note(n_path));
			FileDataBaseConfigLog("FileDataBaseConfig", "get",  "println", Note("path ") + Note(path));
			
			TextExporter objTextExporter = file->readText(path);
			objTextExporter.write("DataBase.uuid", uuid);
			Note port = importer->read("DataBase.reply", Note());
			
			if(port != ""){
				importer->remove("DataBase.reply");
				serialState->send(port, objTextExporter.getText());
			}else{
				serialState->send(objTextExporter.getText());
			}
			exporter->clear();
			exporter->read(file, path);
		}
			 
		virtual void erase(MonkeyExporter* exporter, MonkeyImporter* importer, MonkeyFile* file, SerialMessageState* serialState){
			if(file == nullptr || serialState == nullptr || exporter == nullptr || importer == nullptr){
				return;
			}
			FileDataBaseConfigLog("FileDataBaseConfig", "erase",  "println", "");
			Note dir = importer->read("DataBase.dir", Note());
			Note n_path = importer->read("DataBase.path", Note());
			
			if(dir == "" || n_path == ""){
				FileDataBaseConfigLog("FileDataBaseConfig", "erase",  "println", "id.isEmpty");
				return;
			}
			
			importer->remove("DataBase.dir");
			importer->remove("DataBase.path");
			
			Note rootPath = file->fixPath(dir);
			Note path = file->fixPath(dir, n_path);
			
			if(path == ""){
				FileDataBaseConfigLog("FileDataBaseConfig", "erase",  "println", "path.isEmpty");
				return;
			}
			FileDataBaseConfigLog("FileDataBaseConfig", "erase",  "println", Note("n_path ") + Note(n_path));
			FileDataBaseConfigLog("FileDataBaseConfig", "erase",  "println", Note("path ") + Note(path));
			
			if(file->exist(path)){
				file->deleteFile(path);
			}
		}
			
		virtual void copy(MonkeyExporter* exporter, MonkeyImporter* importer, MonkeyFile* file, SerialMessageState* serialState){
			if(file == nullptr || serialState == nullptr || exporter == nullptr || importer == nullptr){
				return;
			}
			FileDataBaseConfigLog("FileDataBaseConfig", "copy",  "println", "");
			Note dir = importer->read("DataBase.dir", Note());
			Note n_path = importer->read("DataBase.path", Note());
			Note n_copy_path = importer->read("DataBase.copy.path", Note());
			
			if(dir == "" || n_path == "" || n_copy_path == ""){
				FileDataBaseConfigLog("FileDataBaseConfig", "copy",  "println", "id.isEmpty");
				return;
			}
			
			importer->remove("DataBase.dir");
			importer->remove("DataBase.path");
			
			Note rootPath = file->fixPath(dir);
			Note path = file->fixPath(dir, n_path);
			Note c_path = file->fixPath(dir, n_copy_path);
			
			if(path == "" || c_path == ""){
				FileDataBaseConfigLog("FileDataBaseConfig", "copy",  "println", "path.isEmpty");
				return;
			}
			
			if(!file->exist(rootPath)){
				return;
			}
			if(!file->exist(path)){
				return;
			}
			if(!file->exist(c_path)){
				file->createFile(c_path);
			}
			
			FileDataBaseConfigLog("FileDataBaseConfig", "copy",  "println", Note("n_path ") + Note(n_path));
			FileDataBaseConfigLog("FileDataBaseConfig", "copy",  "println", Note("path ") + Note(path));
			FileDataBaseConfigLog("FileDataBaseConfig", "copy",  "println", Note("copy path ") + Note(c_path));
			
			Note o_text = file->readText(path);
			
			file->writeText(o_text, c_path);
		}
			
		virtual void cut(MonkeyExporter* exporter, MonkeyImporter* importer, MonkeyFile* file, SerialMessageState* serialState){
			if(file == nullptr || serialState == nullptr || exporter == nullptr || importer == nullptr){
				return;
			}
			FileDataBaseConfigLog("FileDataBaseConfig", "cut",  "println", "");
			Note dir = importer->read("DataBase.dir", Note());
			Note n_path = importer->read("DataBase.path", Note());
			Note n_cut_path = importer->read("DataBase.cut.path", Note());
			
			if(dir == "" || n_path == "" || n_cut_path == ""){
				FileDataBaseConfigLog("FileDataBaseConfig", "cut",  "println", "id.isEmpty");
				return;
			}
			
			importer->remove("DataBase.dir");
			importer->remove("DataBase.path");
			
			Note rootPath = file->fixPath(dir);
			Note path = file->fixPath(dir, n_path);
			Note c_path = file->fixPath(dir, n_cut_path);
			
			if(path == "" || c_path == ""){
				FileDataBaseConfigLog("FileDataBaseConfig", "cut",  "println", "path.isEmpty");
				return;
			}
			
			if(!file->exist(rootPath)){
				return;
			}
			if(!file->exist(path)){
				return;
			}
			if(!file->exist(c_path)){
				file->createFile(c_path);
			}
			
			FileDataBaseConfigLog("FileDataBaseConfig", "cut",  "println", Note("n_path ") + Note(n_path));
			FileDataBaseConfigLog("FileDataBaseConfig", "cut",  "println", Note("path ") + Note(path));
			FileDataBaseConfigLog("FileDataBaseConfig", "cut",  "println", Note("copy path ") + Note(c_path));
			
			Note o_text = file->readText(path);
			
			file->writeText(o_text, c_path);
			
			file->deleteFile(path);
		}
		
	protected:
};

}

#endif