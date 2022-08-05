
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
			if(project_dir == ""){
				return;
			}
			importer->removeTag("DataBase.project");
			
			Note project_folder_path = file->fixPath(rootDir, project_dir);
			Note project_folder_tag_path = file->fixPath(project_folder_path, tagPath);
			Note project_folder_helper_path = file->fixPath(project_folder_path, helperPath);
			
			if(!file->exist(project_folder_path)){
				ObjectDataBaseConfigLog(ame_Log_Statement, "put", "println", "!file->exist(project_folder_path)");
				// ObjectDataBaseConfigLog(ame_Log_Statement, "put", "println", ame_String("project_folder_path ") + project_folder_path);
				file->fastCreateDir(project_folder_path);
				
				// ObjectDataBaseConfigLog(ame_Log_Statement, "put", "println", Note("project_folder_tag_path ") + project_folder_tag_path);
				
				file->fastCreateFile(project_folder_tag_path);
				
				// ObjectDataBaseConfigLog(ame_Log_Statement, "write", "println", Note("project_folder_helper_path ") + project_folder_helper_path);
				
				file->fastCreateFile(project_folder_helper_path);
			}
			
			Note folder_dir = importer->getTag("DataBase.dir");
			Note helper_path = file->fixPath(folder_dir, helperPath);
			Note objMap_path = file->fixPath(folder_dir, idRegisterPath);
			
			if(folder_dir == ""){
				ObjectDataBaseConfigLog(ame_Log_Statement, "put",  "println", "folder_dir.isEmpty");
				
				TextImporter project_helper_Importer = file->fastReadText(project_folder_helper_path);
				Note folderName = project_helper_Importer.read("DataBase.folder.name", "");
				int folderCount = project_helper_Importer.read("DataBase.folder.count", -1);
				
				// ObjectDataBaseConfigLog(ame_Log_Statement, "put",  "println", Note("folderName ") + folderName);
				ObjectDataBaseConfigLog(ame_Log_Statement, "put",  "println", ame_String("folderCount ") + ame_String(folderCount));
				
				if(folderName == "" || folderCount == -1){
					ObjectDataBaseConfigLog(ame_Log_Statement, "put",  "println", "folderName.isEmpty || folderCount == -1");
					TextExporter txtExporter;
					if(folderName == ""){
						txtExporter.write("DataBase.folder.name", m_folderName);
						folderName = m_folderName;
					}
					if(folderCount == -1){
						txtExporter.write("DataBase.folder.count", 0);
						folderCount = 0;
					}
					txtExporter.write(file, project_folder_helper_path);
				
					folder_dir = file->fixPath(project_folder_path, folderName + Note(folderCount));
					Note tag_path = file->fixPath(folder_dir, tagPath);
					helper_path = file->fixPath(folder_dir, helperPath);
					objMap_path = file->fixPath(folder_dir, idRegisterPath);

					if(!file->exist(folder_dir)){
						ObjectDataBaseConfigLog(ame_Log_Statement, "put",  "println", "!file->exist(folder_dir)");
						// ObjectDataBaseConfigLog(ame_Log_Statement, "write",  "println", Note("folder_dir ") + folder_dir);
						file->fastCreateDir(folder_dir);
						
						// ObjectDataBaseConfigLog(ame_Log_Statement, "write",  "println", Note("tag_path ") + tag_path);
						file->fastCreateFile(tag_path);
						
						// ObjectDataBaseConfigLog(ame_Log_Statement, "write",  "println", Note("helper_path ") + helper_path);
						file->fastCreateFile(helper_path);
						
						file->fastCreateFile(objMap_path);
					}
				}else{
					folder_dir = file->fixPath(project_folder_path, folderName + Note(folderCount));
					helper_path = file->fixPath(folder_dir, helperPath);
					objMap_path = file->fixPath(folder_dir, idRegisterPath);
				}
				
				// ObjectDataBaseConfigLog(ame_Log_Statement, "put",  "println", Note("folderName ") + folderName);
				ObjectDataBaseConfigLog(ame_Log_Statement, "put",  "println", ame_String("folderCount ") + ame_String(folderCount));
			}else{
				importer->removeTag("DataBase.dir");
				
				Note tag_path = file->fixPath(folder_dir, tagPath);
				helper_path = file->fixPath(folder_dir, helperPath);
				objMap_path = file->fixPath(folder_dir, idRegisterPath);
				
				if(!file->exist(folder_dir)){
					ObjectDataBaseConfigLog(ame_Log_Statement, "put",  "println", "!file->exist(folder_dir)");
					// ObjectDataBaseConfigLog(ame_Log_Statement, "write",  "println", Note("folder_dir ") + folder_dir);
					file->fastCreateDir(folder_dir);
					
					// ObjectDataBaseConfigLog(ame_Log_Statement, "write",  "println", Note("tag_path ") + tag_path);
					file->fastCreateFile(tag_path);
					
					// ObjectDataBaseConfigLog(ame_Log_Statement, "write",  "println", Note("helper_path ") + helper_path);
					file->fastCreateFile(helper_path);
					
					file->fastCreateFile(objMap_path);
				}
			}
			
			if(folder_dir == ""){
				ObjectDataBaseConfigLog(ame_Log_Statement, "put",  "println", "folder_dir.isEmpty");
				return;
			}
			
			ObjectDataBaseConfigLog(ame_Log_Statement, "put",  "println", ame_String("file->getFileSize(folder_dir) ") + ame_String(file->getFileSize(folder_dir)));
			
			if(file->getFileSize(folder_dir) >= fileSize){
				TextImporter project_helper_Importer = file->fastReadText(project_folder_helper_path);
				Note folderName = project_helper_Importer.read("DataBase.folder.name", "");
				int folderCount = project_helper_Importer.read("DataBase.folder.count", -1);
				
				// ObjectDataBaseConfigLog(ame_Log_Statement, "put",  "println", Note("folderName ") + folderName);
				ObjectDataBaseConfigLog(ame_Log_Statement, "put",  "println", ame_String("folderCount ") + ame_String(folderCount));
				
				folderCount++;
				
				ObjectDataBaseConfigLog(ame_Log_Statement, "put",  "println", ame_String("folderCount ") + ame_String(folderCount));
				
				TextExporter txtExporter = file->fastReadText(project_folder_helper_path);
				
				txtExporter.remove("DataBase.folder.count");
				txtExporter.write("DataBase.folder.count", folderCount);
				
				file->fastClearFile(project_folder_helper_path);
				txtExporter.write(file, project_folder_helper_path);
				
				folder_dir = file->fixPath(project_folder_path, folderName + Note(folderCount));
				
				if(folder_dir == ""){
					ObjectDataBaseConfigLog(ame_Log_Statement, "put",  "println", "folder_dir.isEmpty");
					return;
				}
				Note tag_path = file->fixPath(folder_dir, tagPath);
				helper_path = file->fixPath(folder_dir, helperPath);
				objMap_path = file->fixPath(folder_dir, idRegisterPath);
				
				if(!file->exist(folder_dir)){
					ObjectDataBaseConfigLog(ame_Log_Statement, "put",  "println", "!file->exist(folder_dir)");
					// ObjectDataBaseConfigLog(ame_Log_Statement, "write",  "println", Note("folder_dir ") + folder_dir);
					file->fastCreateFile(folder_dir);
					
					// ObjectDataBaseConfigLog(ame_Log_Statement, "write",  "println", Note("tag_path ") + tag_path);
					file->fastCreateFile(tag_path);
					
					// ObjectDataBaseConfigLog(ame_Log_Statement, "write",  "println", Note("helper_path ") + helper_path);
					file->fastCreateFile(helper_path);
					
					file->fastCreateFile(objMap_path);
				}
			}
			
			TextImporter textImporter = file->fastReadText(helper_path);
			
			ElementId id = importer->getTag("DataBase.id");
			
			if(id == ""){
				ObjectDataBaseConfigLog(ame_Log_Statement, "put",  "println", "id.isEmpty");
				Note idName = textImporter.read("DataBase.id.name", "");
				int idCount = textImporter.read("DataBase.id.count", -1);
				
				// ObjectDataBaseConfigLog(ame_Log_Statement, "put",  "println", Note("idName ") + idName);
				ObjectDataBaseConfigLog(ame_Log_Statement, "put",  "println", ame_String("idCount ") + ame_String(idCount));
				
				if(idName == "" || idCount == -1){
					ObjectDataBaseConfigLog(ame_Log_Statement, "put",  "println", "idName.isEmpty || idCount == -1");
					TextExporter txtExporter;
					if(idName == ""){
						txtExporter.write("DataBase.id.name", m_idName);
						idName = m_idName;
					}
					if(idCount == -1){
						txtExporter.write("DataBase.id.count", 0);
						idCount = 0;
					}
					txtExporter.write(file, helper_path);
				}
				// ObjectDataBaseConfigLog(ame_Log_Statement, "put",  "println", Note("idName ") + idName);
				ObjectDataBaseConfigLog(ame_Log_Statement, "put",  "println", ame_String("idCount ") + ame_String(idCount));
					
				ElementId n_element = idName;
				id = n_element.child(Note(idCount));
				
				idCount++;
				
				TextExporter txtExporter = file->fastReadText(helper_path);
				
				txtExporter.remove("DataBase.id.count");
				txtExporter.write("DataBase.id.count", idCount);
				
				file->fastClearFile(helper_path);
				txtExporter.write(file, helper_path);
			}
			
			Note fileName = importer->getTag("DataBase.file.name");
			Note idPath;
			bool fCounting = false;
			if(fileName == ""){
				fCounting = true;
				textImporter.setText(file->fastReadText(helper_path));
				fileName = textImporter.read("DataBase.file.name", "");
			}else{
				importer->removeTag("DataBase.file.name");
				idPath = file->fixPath(folder_dir, fileName + Note(".txt"));
				if(!file->exist(idPath)){
					ObjectDataBaseConfigLog(ame_Log_Statement, "put",  "println", "!file->exist(idPath)");
					file->fastCreateFile(idPath);
				}
			}
			
			if(fileName == ""){
				ObjectDataBaseConfigLog(ame_Log_Statement, "put",  "println", "fileName.isEmpty");
				textImporter.setText(file->fastReadText(helper_path));
				
				int fileCount = textImporter.read("DataBase.file.count", -1);
				
				// ObjectDataBaseConfigLog(ame_Log_Statement, "put",  "println", Note("fileName ") + fileName);
				ObjectDataBaseConfigLog(ame_Log_Statement, "put",  "println", ame_String("fileCount ") + ame_String(fileCount));
				
				TextExporter txtExporter;
				if(fileName == ""){
					txtExporter.write("DataBase.file.name", m_fileName);
					fileName = m_fileName;
				}
				if(fileCount == -1){
					txtExporter.write("DataBase.file.count", 0);
					fileCount = 0;
				}
				txtExporter.write(file, helper_path);
			}
			
			if(idPath == ""){
				int fileCount = textImporter.read("DataBase.file.count", 0);
				idPath = file->fixPath(folder_dir, fileName + Note(fileCount) + Note(".txt"));
				file->fastCreateFile(idPath);
			}

			if(fCounting){
				ObjectDataBaseConfigLog(ame_Log_Statement, "put",  "println", "counting to the next file");
				
				int fileCount = textImporter.read("DataBase.file.count", 0);
				fileCount++;

				ObjectDataBaseConfigLog(ame_Log_Statement, "put",  "println", "fastReadText");
				TextExporter txtExporter = file->fastReadText(helper_path);
				
				ObjectDataBaseConfigLog(ame_Log_Statement, "put",  "println", "txtExporter remove");
				txtExporter.remove("DataBase.file.count");
				ObjectDataBaseConfigLog(ame_Log_Statement, "put",  "println", "txtExporter write");
				txtExporter.write("DataBase.file.count", fileCount);
				
				ObjectDataBaseConfigLog(ame_Log_Statement, "put",  "println", "fastClearFile");
				file->fastClearFile(helper_path);
				ObjectDataBaseConfigLog(ame_Log_Statement, "put",  "println", "txtExporter file write");
				txtExporter.write(file, helper_path);
			}
			
			ObjectDataBaseConfigLog(ame_Log_Statement, "put",  "println", "addTag");
			importer->addTag("id", id.getId());
			ObjectDataBaseConfigLog(ame_Log_Statement, "put",  "println", "eraseTags");
			importer->eraseTags();
			ObjectDataBaseConfigLog(ame_Log_Statement, "put",  "println", "writeTags");
			importer->writeTags();
			ObjectDataBaseConfigLog(ame_Log_Statement, "put",  "println", "importer write");
			importer->write(file, idPath);
			
			
			file->writeText(id.getId() + Note(" ") + idPath + Note('\n'), objMap_path);
			
			// ObjectDataBaseConfigLog(ame_Log_Statement, "put",  "println", ame_String("idPath ") + ame_String(idPath));
			// ObjectDataBaseConfigLog(ame_Log_Statement, "put",  "println", ame_String("helper_path ") + ame_String(helper_path));
			// ObjectDataBaseConfigLog(ame_Log_Statement, "put",  "println", Note("fileName ") + fileName);
			
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