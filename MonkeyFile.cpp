
#ifndef MonkeyFile_cpp
#define MonkeyFile_cpp

#include "MonkeyFile.h"

	
	ame::MonkeyFile::MonkeyFile(){
		if (SD.begin(53)) {
			
		}else{
			
		}
	}
	
	ame::MonkeyFile::MonkeyFile(int chip){
		this->fileFunctions = new ame::KPMap<cppObjectClass,MonkeyFileFunction,10>();
		if (SD.begin(chip)) {
			
		}else{
			
		}
	}
	
	ame::MonkeyFile::MonkeyFile(int chip, ame::Map<ame::cppObjectClass,ame::MonkeyFileFunction>* functions){
		this->fileFunctions = functions;
		if (SD.begin(chip)) {
			
		}else{
			
		}
	}
	
	ame::MonkeyFile::~MonkeyFile(){
		if(this->fileFunctions != nullptr){
			delete this->fileFunctions;
		}
	}
	
	void ame::MonkeyFile::setRootPathFile(String filepath){
		this->rootPath = filepath;
	}
	
	String ame::MonkeyFile::getRootPathFile(){
		return this->rootPath;
	}
	
	bool ame::MonkeyFile::create(String file){
		File myFile = SD.open(file, FILE_WRITE);
		myFile.close();
		return true;
	}
	
	bool ame::MonkeyFile::createRoot(String file){
		File myFile = SD.open(this->rootPath+"/"+file, FILE_WRITE);
		myFile.close();
		return true;
	}
	
	bool ame::MonkeyFile::write(String file, String text){
		if(!SD.exists(file)){
			return false;
		}
		File myFile = SD.open(file, FILE_WRITE);
		myFile.println(text);
		myFile.close();
		return true;
	}
	
	bool ame::MonkeyFile::writeRoot(String file, String text){
		if(!SD.exists(this->rootPath+"/"+file)){
			return false;
		}
		File myFile = SD.open(this->rootPath+"/"+file, FILE_WRITE);
		myFile.println(text);
		myFile.close();
		return true;
	}
	
	String ame::MonkeyFile::read(String file){
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
	
	String ame::MonkeyFile::readRoot(String file){
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
	
	bool ame::MonkeyFile::exist(String file){
		return SD.exists(file);
	}
	
	bool ame::MonkeyFile::existRoot(String file){
		return SD.exists(this->rootPath+"/"+file);
	}
	
	bool ame::MonkeyFile::deleteFile(String file){
		return SD.remove(file);
	}
	
	bool ame::MonkeyFile::deleteRootFile(String file){
		return SD.remove(this->rootPath+"/"+file);
	}
	
	void ame::MonkeyFile::addFileFunction(ame::cppObjectClass* cls, ame::MonkeyFileFunction* function){
		this->fileFunctions->addPointers(cls, function);
	}
	
	ame::MonkeyFileFunction* ame::MonkeyFile::getFileFunction(ame::cppObjectClass* cls){
		return this->fileFunctions->getByPointer(cls);
	}
	
	ame::MonkeyFileFunction* ame::MonkeyFile::removeFileFunction(cppObjectClass* cls){
		return this->fileFunctions->removeByPointer(cls);
	}
	
	void ame::MonkeyFile::removeDeleteFileFunction(ame::cppObjectClass* cls){
		MonkeyFileFunction* function = this->fileFunctions->removeByPointer(cls);
		if(function != nullptr){
			delete function;
		}
	}
	
	bool ame::MonkeyFile::save(ame::cppObject* save,String path,String key){
		ame::MonkeyFileFunction* function = this->fileFunctions->getByPointer(save->getClass());
		if(function != nullptr){
			return function->SaveFileFunction(this, save, path, key);
		}
		return false;
	}
	
	bool ame::MonkeyFile::saveRoot(ame::cppObject* save,String path,String key){
		ame::MonkeyFileFunction* function = this->fileFunctions->getByPointer(save->getClass());
		if(function != nullptr){
			return function->SaveFileFunction(this, save, this->rootPath+"/"+path, key);
		}
		return false;
	}
	
	ame::cppObject* ame::MonkeyFile::load(ame::cppObjectClass* cls, ame::cppObject* l,String path,String key){
		MonkeyFileFunction* function = this->fileFunctions->getByPointer(cls);
		if(function != nullptr){
			return function->LoadFileFunction(this, l, path, key);
		}
		return nullptr;
	}
	
	ame::cppObject* ame::MonkeyFile::loadRoot(ame::cppObjectClass* cls, ame::cppObject* l,String path,String key){
		ame::MonkeyFileFunction* function = this->fileFunctions->getByPointer(cls);
		if(function != nullptr){
			return function->LoadFileFunction(this, l, this->rootPath+"/"+path, key);
		}
		return nullptr;
	}
	
	bool ame::MonkeyFile::deleting( ame::cppObjectClass* cls, ame::cppObject* l,String path,String key){
		ame::MonkeyFileFunction* function = this->fileFunctions->getByPointer(cls);
		if(function != nullptr){
			return function->DeleteFileFunction(this, l, this->rootPath+"/"+path, key);
		}
		return false;
	}
	
	bool ame::MonkeyFile::deletingRoot(ame::cppObjectClass* cls, ame::cppObject* l,String path,String key){
		ame::MonkeyFileFunction* function = this->fileFunctions->getByPointer(cls);
		if(function != nullptr){
			return function->DeleteFileFunction(this, l, this->rootPath+"/"+path, key);
		}
		return false;
	}
#endif 