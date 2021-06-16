
#ifndef MonkeyFile_cpp
#define MonkeyFile_cpp

#include "MonkeyFile.h"

	
	MonkeyFile::MonkeyFile(){
		if (SD.begin(53)) {
			
		}else{
			
		}
	}
	
	MonkeyFile::MonkeyFile(int chip){
		this->fileFunctions = new KPMap<cppObjectClass,MonkeyFileFunction,10>();
		if (SD.begin(chip)) {
			
		}else{
			
		}
	}
	
	MonkeyFile::MonkeyFile(int chip, Map<cppObjectClass,MonkeyFileFunction>* functions){
		this->fileFunctions = functions;
		if (SD.begin(chip)) {
			
		}else{
			
		}
	}
	
	MonkeyFile::~MonkeyFile(){
		if(this->fileFunctions != nullptr){
			delete this->fileFunctions;
		}
	}
	
	void MonkeyFile::setRootPathFile(String filepath){
		this->rootPath = filepath;
	}
	
	String MonkeyFile::getRootPathFile(){
		return this->rootPath;
	}
	
	bool MonkeyFile::create(String file){
		File myFile = SD.open(file, FILE_WRITE);
		myFile.close();
		return true;
	}
	
	bool MonkeyFile::createRoot(String file){
		File myFile = SD.open(this->rootPath+"/"+file, FILE_WRITE);
		myFile.close();
		return true;
	}
	
	bool MonkeyFile::write(String file, String text){
		if(!SD.exists(file)){
			return false;
		}
		File myFile = SD.open(file, FILE_WRITE);
		myFile.println(text);
		myFile.close();
		return true;
	}
	
	bool MonkeyFile::writeRoot(String file, String text){
		if(!SD.exists(this->rootPath+"/"+file)){
			return false;
		}
		File myFile = SD.open(this->rootPath+"/"+file, FILE_WRITE);
		myFile.println(text);
		myFile.close();
		return true;
	}
	
	String MonkeyFile::read(String file){
		if(!SD.exists(file)){
			return "";
		}
		File myFile = SD.open(file);
		String r = "";
		while (myFile.available()) {
		  r.concat((char)myFile.read());
		}
		myFile.close();
		return r;
	}
	
	String MonkeyFile::readRoot(String file){
		if(!SD.exists(this->rootPath+"/"+file)){
			return "";
		}
		File myFile = SD.open(this->rootPath+"/"+file);
		String r = "";
		while (myFile.available()) {
		  r.concat((char)myFile.read());
		}
		myFile.close();
		return r;
	}
	
	bool MonkeyFile::exist(String file){
		return SD.exists(file);
	}
	
	bool MonkeyFile::existRoot(String file){
		return SD.exists(this->rootPath+"/"+file);
	}
	
	bool MonkeyFile::deleteFile(String file){
		return SD.remove(file);
	}
	
	bool MonkeyFile::deleteRootFile(String file){
		return SD.remove(this->rootPath+"/"+file);
	}
	
	void MonkeyFile::addFileFunction(cppObjectClass* cls,MonkeyFileFunction* function){
		this->fileFunctions->addPointers(cls, function);
	}
	
	MonkeyFileFunction* MonkeyFile::getFileFunction(cppObjectClass* cls){
		return this->fileFunctions->getByPointer(cls);
	}
	
	MonkeyFileFunction* MonkeyFile::removeFileFunction(cppObjectClass* cls){
		return this->fileFunctions->removeByPointer(cls);
	}
	
	void MonkeyFile::removeDeleteFileFunction(cppObjectClass* cls){
		MonkeyFileFunction* function = this->fileFunctions->removeByPointer(cls);
		if(function != nullptr){
			delete function;
		}
	}
	
	bool MonkeyFile::save(cppObject* save,String path,String key){
		MonkeyFileFunction* function = this->fileFunctions->getByPointer(save->getClass());
		if(function != nullptr){
			return function->SaveFileFunction(this, save, path, key);
		}
		return false;
	}
	
	bool MonkeyFile::saveRoot(cppObject* save,String path,String key){
		MonkeyFileFunction* function = this->fileFunctions->getByPointer(save->getClass());
		if(function != nullptr){
			return function->SaveFileFunction(this, save, this->rootPath+"/"+path, key);
		}
		return false;
	}
	
	cppObject* MonkeyFile::load(cppObjectClass* cls,cppObject* l,String path,String key){
		MonkeyFileFunction* function = this->fileFunctions->getByPointer(cls);
		if(function != nullptr){
			return function->LoadFileFunction(this, l, path, key);
		}
		return nullptr;
	}
	
	cppObject* MonkeyFile::loadRoot(cppObjectClass* cls,cppObject* l,String path,String key){
		MonkeyFileFunction* function = this->fileFunctions->getByPointer(cls);
		if(function != nullptr){
			return function->LoadFileFunction(this, l, this->rootPath+"/"+path, key);
		}
		return nullptr;
	}
	
	bool MonkeyFile::deleting(cppObjectClass* cls,cppObject* l,String path,String key){
		MonkeyFileFunction* function = this->fileFunctions->getByPointer(cls);
		if(function != nullptr){
			return function->DeleteFileFunction(this, l, this->rootPath+"/"+path, key);
		}
		return false;
	}
	
	bool MonkeyFile::deletingRoot(cppObjectClass* cls,cppObject* l,String path,String key){
		MonkeyFileFunction* function = this->fileFunctions->getByPointer(cls);
		if(function != nullptr){
			return function->DeleteFileFunction(this, l, this->rootPath+"/"+path, key);
		}
		return false;
	}
#endif 