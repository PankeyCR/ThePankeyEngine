
#ifndef ObjectDataBaseConfig_hpp
#define ObjectDataBaseConfig_hpp

#include "DataBaseConfig.hpp"
#include "MonkeyFile.hpp"
#include "SerialMessageState.hpp"
#include "MonkeyExporter.hpp"
#include "MonkeyImporter.hpp"
#include "TextExporter.hpp"
#include "TextImporter.hpp"

#ifdef ObjectDataBaseConfigLogApp
	#include "Logger.hpp"
	#define ObjectDataBaseConfigLog(name,method,type,mns) Log(name,method,type,mns)
#else
	#define ObjectDataBaseConfigLog(name,method,type,mns)
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
			String rootPath = file->fixPath(rootDir);
			String path = file->fixPath(rootPath, filePath);
			if(!file->exist(rootPath)){
				file->createDir(rootPath);
			}
			if(!file->exist(path)){
				file->createFile(path);
			}
			ObjectDataBaseConfigLog("ObjectDataBaseConfig", "initialize",  "println", "");
		}
		
		virtual void put(MonkeyExporter* exporter, MonkeyImporter* importer, MonkeyFile* file, SerialMessageState* serialState){
			if(file == nullptr || serialState == nullptr || exporter == nullptr || importer == nullptr){
				return;
			}
			ObjectDataBaseConfigLog("ObjectDataBaseConfig", "put",  "println", "");
			ElementId id = importer->read("DataBase.id", ElementId());
			
			String rootPath = file->fixPath(rootDir);
			String path = file->fixPath(rootPath, filePath);
			
			if(path == ""){
				ObjectDataBaseConfigLog("ObjectDataBaseConfig", "put",  "println", "path.isEmpty");
				return;
			}
			
			if(!file->exist(rootPath)){
				ObjectDataBaseConfigLog("ObjectDataBaseConfig", "put",  "println", "!file->exist(rootPath)");
				ObjectDataBaseConfigLog("ObjectDataBaseConfig", "write",  "println", String("rootPath ") + rootPath);
				file->createDir(rootPath);
			}
			if(!file->exist(path)){
				ObjectDataBaseConfigLog("ObjectDataBaseConfig", "put",  "println", "!file->exist(path)");
				ObjectDataBaseConfigLog("ObjectDataBaseConfig", "write",  "println", String("path ") + path);
				file->createFile(path);
			}
			
			TextImporter textImporter = file->readText(path);
			
			if(id == ""){
				ObjectDataBaseConfigLog("ObjectDataBaseConfig", "put",  "println", "id.isEmpty");
				String idName = textImporter.read("DataBase.idName", "");
				int idCount = textImporter.read("DataBase.idCount", -1);
			
				if(idName == "" || idCount == -1){
					ObjectDataBaseConfigLog("ObjectDataBaseConfig", "put",  "println", "fileName.isEmpty || fileCount == -1");
					TextExporter txtExporter = file->readText(path);
					txtExporter.write("DataBase.idName", "object");
					txtExporter.write("DataBase.idCount", 0);
					txtExporter.write(file, path);
					
					idName = "object";
					idCount = 0;
				}
				ElementId n_element = idName;
				id = n_element.child(String(idCount));
				
				idCount++;
				
				TextExporter txtExporter = file->readText(path);
				txtExporter.write("DataBase.idCount", idCount);
				txtExporter.write(file, path);
			}
        
			LinkedList<String> objList = textImporter.read("DataBase.objList", LinkedList<String>());
			
			if(!objList.containByLValue(id.getId())){
				objList.add(id.getId());
			}
			
			TextExporter txtExporterObj = file->readText(path);
			txtExporterObj.write("DataBase.objList", objList);

			txtExporterObj.write(file, path);
			
			// importer->remove("DataBase.id");
			
			String idPath = textImporter.read(id, "");
			String fileName = textImporter.read("DataBase.fileName", "");
			int fileCount = textImporter.read("DataBase.fileCount", -1);
			
			if(fileName == "" || fileCount == -1){
				ObjectDataBaseConfigLog("ObjectDataBaseConfig", "put",  "println", "fileName.isEmpty || fileCount == -1");
				TextExporter txtExporter = file->readText(path);
				txtExporter.write("DataBase.fileName", "object");
				txtExporter.write("DataBase.fileCount", 0);
				txtExporter.write(file, path);
				
				fileName = "object";
				fileCount = 0;
			}
			
			if(idPath == ""){
				ObjectDataBaseConfigLog("ObjectDataBaseConfig", "put",  "println", "idPath.isEmpty");
				idPath = file->fixPath(rootPath, fileName + String(fileCount) + String(".txt"));
				
				if(!file->exist(rootPath)){
					ObjectDataBaseConfigLog("ObjectDataBaseConfig", "put",  "println", "!file->exist(rootPath)");
					file->createDir(rootPath);
				}
				if(!file->exist(idPath)){
					ObjectDataBaseConfigLog("ObjectDataBaseConfig", "put",  "println", "!file->exist(idPath)");
					file->createFile(idPath);
				}

				fileCount++;

				TextExporter txtExporter = file->readText(path);
				txtExporter.write(id, idPath);
				txtExporter.write("DataBase.fileCount", fileCount);
				txtExporter.write(file, path);
			}
			ObjectDataBaseConfigLog("ObjectDataBaseConfig", "put",  "println", String("idPath ") + String(idPath));
			ObjectDataBaseConfigLog("ObjectDataBaseConfig", "put",  "println", String("path ") + String(path));
			ObjectDataBaseConfigLog("ObjectDataBaseConfig", "put",  "println", String("fileName ") + fileName);
			ObjectDataBaseConfigLog("ObjectDataBaseConfig", "put",  "println", String("fileCount ") + String(fileCount));
			
        
			int idPathSize = importer->read("DataBase.id.path.size", -1);
			
			if(idPathSize != 0 || idPathSize != -1){
	//            importer.remove(new ElementId("DataBase.id.path.size"));
				for(int x = 0; x < idPathSize; x++){
					String idExtraPath = importer->read(String("DataBase.id.path.") + String(x), "");
					if(idExtraPath == ""){
						continue;
					}
	//                importer.remove(new ElementId(idExtraPath));
					idExtraPath = file->fixPath(rootPath, idExtraPath + ".txt");
					
					if(!file->exist(rootPath)){
						file->createDir(rootPath);
					}
					if(!file->exist(idExtraPath)){
						file->createFile(idExtraPath);
					}
				
					importer->write(file, idExtraPath);
				}
			}
			
			importer->write(file, idPath);
		}
			
		virtual void get(MonkeyExporter* exporter, MonkeyImporter* importer, MonkeyFile* file, SerialMessageState* serialState){
			if(file == nullptr || serialState == nullptr || exporter == nullptr || importer == nullptr){
				return;
			}
			ObjectDataBaseConfigLog("ObjectDataBaseConfig", "get",  "println", "");
			
			String rootPath = file->fixPath(rootDir);
			String path = file->fixPath(rootPath, filePath);
        
			bool getObjList = importer->read("DataBase.getObjList", false);
			
			if(getObjList){
				ObjectDataBaseConfigLog("ObjectDataBaseConfig", "get",  "println", "getObjList");
				TextImporter textImporter = file->readText(path);
				
				LinkedList<String> objList = textImporter.read("DataBase.objList", LinkedList<String>());
				
				if(!objList.isEmpty()){
					ObjectDataBaseConfigLog("ObjectDataBaseConfig", "get",  "println", "objList isEmpty");
					String objListS = importer->read("DataBase.objList", "");
					int port = importer->read("DataBase.port", -1);

					if(port == -1){
						serialState->send(objListS);
					}else{
						serialState->send(port, objListS);
					}
					exporter->clear();
					exporter->write("DataBase.objList", objList);
				}
				return;
			}
			
			ElementId id = importer->read("DataBase.id", ElementId());
			bool objectsPath = importer->read("DataBase.objects", false);
			
			ObjectDataBaseConfigLog("ObjectDataBaseConfig", "get",  "println", String("id ") + id.getId());
			ObjectDataBaseConfigLog("ObjectDataBaseConfig", "get",  "println", String("objectsPath ") + String(objectsPath));
			ObjectDataBaseConfigLog("ObjectDataBaseConfig", "get",  "println", String("path ") + String(path));
			
			if(objectsPath && path != ""){
				ObjectDataBaseConfigLog("ObjectDataBaseConfig", "get",  "println", "objectsPath not Empty");
				String textPath = file->readText(path);
				ObjectDataBaseConfigLog("ObjectDataBaseConfig", "get",  "println", String("textPath ") + textPath);
				
				if(textPath != ""){
					int port = importer->read("DataBase.port", -1);
					ObjectDataBaseConfigLog("ObjectDataBaseConfig", "get",  "println", "sending all");
					
					if(port == -1){
						serialState->send(textPath);
					}else{
						serialState->send(port, textPath);
					}
				}
			}
			
			if(id == ""){
				ObjectDataBaseConfigLog("ObjectDataBaseConfig", "get",  "println", "id.isEmpty");
				return;
			}
			
			// importer->remove("DataBase.id");
			
			TextImporter textImporter = file->readText(path);
			String idPath = textImporter.read(id, "");
			
			if(idPath == ""){
				ObjectDataBaseConfigLog("ObjectDataBaseConfig", "get",  "println", "path.isEmpty");
				return;
			}
			ObjectDataBaseConfigLog("ObjectDataBaseConfig", "get",  "println", String("idPath ") + String(idPath));
			
			TextImporter objTextImporter = file->readText(idPath);
			int port = importer->read("DataBase.port", -1);
			
			if(port == -1){
				ObjectDataBaseConfigLog("ObjectDataBaseConfig", "get",  "println", "broadcast");
				serialState->send(objTextImporter.getText());
			}else{
				ObjectDataBaseConfigLog("ObjectDataBaseConfig", "get",  "println", "not broadcast");
				// importer->remove("DataBase.port");
				serialState->send(port, objTextImporter.getText());
			}
			ObjectDataBaseConfigLog("ObjectDataBaseConfig", "get",  "println", String("sending ") + objTextImporter.getText());
			exporter->clear();
			exporter->read(file, idPath);
		}
			 
		virtual void erase(MonkeyExporter* exporter, MonkeyImporter* importer, MonkeyFile* file, SerialMessageState* serialState){
			if(file == nullptr || serialState == nullptr || exporter == nullptr || importer == nullptr){
				return;
			}
			String all = importer->read("DataBase.All", "");
			
			String rootPath = file->fixPath(rootDir);
			String path = file->fixPath(rootPath, filePath);
			
			if(all != ""){
				ObjectDataBaseConfigLog("ObjectDataBaseConfig", "get",  "println", "delete all");
				file->deleteFile(path);
				return;
			}
			
			ElementId id = importer->read("DataBase.id", ElementId());
			
			if(id == ""){
				ObjectDataBaseConfigLog("ObjectDataBaseConfig", "get",  "println", "id.isEmpty");
				return;
			}
			
			importer->remove("DataBase.id");
			
			TextImporter textImporter = file->readText(path);
			String idPath = textImporter.read(id, "");
			
			if(idPath == ""){
				return;
			}
			
			textImporter.remove(id);
			
			file->clearFile(path);
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
			
			String rootPath = file->fixPath(rootDir);
			String path = file->fixPath(rootPath, filePath);
			
			TextImporter textImporter = file->readText(path);
			String idPath = textImporter.read(id, "");
			String copyPath = importer->read("DataBase.copy.path", "");
			
			if(idPath == "" || copyPath == ""){
				return;
			}
			
			String f_1 = file->readText(idPath);
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
			
			String rootPath = file->fixPath(rootDir);
			String path = file->fixPath(rootPath, filePath);
			
			TextImporter textImporter = file->readText(path);
			String idPath = textImporter.read(id, "");
			String copyPath = importer->read("DataBase.cut.path", "");
			
			if(idPath == "" || copyPath == ""){
				return;
			}
			
			String f_1 = file->readText(idPath);
			file->writeText(f_1, copyPath);
			file->deleteFile(idPath);
		}
		
	protected:
		String rootDir = "DataBase";
		String filePath = "DataBaseObjectPath.txt";
};

}

#endif

