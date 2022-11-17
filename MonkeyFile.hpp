
/**
 *
 * @author PankeyCR - Manuel Sanchez Badilla
 *
 */

#ifndef CONFIGURATION_MonkeyFile_hpp
#define CONFIGURATION_MonkeyFile_hpp

	#include "ame_Enviroment.hpp"

	#if defined(DISABLE_MonkeyFile)
		#define MonkeyFile_hpp

		#define IMPLEMENTATION_MonkeyFile
		#define IMPLEMENTING_MonkeyFile
	#else
		#if defined(DISABLE_IMPLEMENTATION_MonkeyFile)
			#define IMPLEMENTATION_MonkeyFile
			#define IMPLEMENTING_MonkeyFile
		#endif
	#endif
#endif

#ifndef MonkeyFile_hpp
#define MonkeyFile_hpp
#define MonkeyFile_AVAILABLE

#ifndef DISABLE_IMPLEMENTATION_MonkeyFile
	#define IMPLEMENTATION_MonkeyFile IMPLEMENTATION(public MonkeyFile)
	#define IMPLEMENTING_MonkeyFile IMPLEMENTING(public MonkeyFile)
#endif

#include "Note.hpp"
#include "ByteArray.hpp"
#include "PrimitiveMap.hpp"


#ifdef MonkeyFile_LogApp
	#include "ame_Logger_config.hpp"
	#include "ame_Logger.hpp"

	#define MonkeyFileLog(location,method,type,mns) ame_Log(this,location,"MonkeyFile",method,type,mns)
	#define const_MonkeyFileLog(location,method,type,mns)
	#define StaticMonkeyFileLog(pointer,location,method,type,mns) ame_Log(pointer,location,"MonkeyFile",method,type,mns)
#else
	#ifdef MonkeyFile_LogDebugApp
		#include "ame_Logger_config.hpp"
		#include "ame_Logger.hpp"

		#define MonkeyFileLog(location,method,type,mns) ame_LogDebug(this,location,"MonkeyFile",method,type)
		#define const_MonkeyFileLog(location,method,type,mns)
		#define StaticMonkeyFileLog(pointer,location,method,type,mns) ame_LogDebug(pointer,location,"MonkeyFile",method,type)
	#else
		#define MonkeyFileLog(location,method,type,mns)
		#define const_MonkeyFileLog(location,method,type,mns)
		#define StaticMonkeyFileLog(pointer,location,method,type,mns)
	#endif
#endif


namespace ame{

class MonkeyFile IMPLEMENTATION_cppObject {
    public:
		MonkeyFile(){}
		MonkeyFile(const Note& a_root_folder){
			this->setRootPathFile(a_root_folder);
		}
		virtual ~MonkeyFile(){}

		virtual void initialize();

		virtual bool isOpen(){
			return m_open;
		}

		virtual void setRootPathFile(Note filepath){
			MonkeyFileLog(ame_Log_Statement, "setRootPathFile",  "println", filepath);
			this->rootPath = this->fixPath(filepath);
			this->createDir(this->rootPath);
		}
		virtual Note getRootPathFile(){
			return this->rootPath;
		}

		virtual bool fastCreateDir(Note path);
		virtual bool createDir(Note path);
		virtual bool createRootDir(Note path);

		virtual bool deleteDir(Note path);
		virtual bool deleteRootDir(Note path);

		virtual bool fastCreateFile(Note file);
		virtual bool createFile(Note file);
		virtual bool createRootFile(Note file);

		virtual bool deleteFile(Note file);
		virtual bool deleteRootFile(Note file);

		virtual bool fastClearFile(Note file);
		virtual bool clearFile(Note file);
		virtual bool clearRootFile(Note file);

		virtual bool fastWriteText(Note text, Note file);
		virtual bool writeText(Note text, Note file);
		virtual bool writeRootText(Note text, Note file);

		virtual Note fastReadText(Note file);
		virtual Note readText(Note file);
		virtual Note readRootText(Note file);

		virtual bool writeByteArray(ByteArray array, Note file);
		virtual bool writeRootByteArray(ByteArray text, Note file);

		virtual ByteArray readByteArray(Note file);
		virtual ByteArray readRootByteArray(Note file);

		virtual bool exist(Note file);
		virtual bool existRoot(Note file);

		virtual Note fixRootPath(Note p);

		virtual Note fixPath(Note p);

		virtual Note fixPath(Note p, Note f);

		virtual int getFileSize(Note path);
		virtual int getDirectoriesSize(Note path);

		virtual PrimitiveMap<Note,Note> getDirectories(Note dirname, int levels);
			
		#if defined(cppObject_AVAILABLE) && defined(cppObjectClass_AVAILABLE) && defined(Class_AVAILABLE)
		virtual cppObjectClass* getClass(){
			return Class<MonkeyFile>::getClass();
		}
		
		virtual bool instanceof(cppObjectClass* cls){
			return cls == Class<MonkeyFile>::getClass();
		}
		#endif

	protected:
		Note rootPath;
		bool m_open = false;
};

}

#ifndef ame_Enviroment_Defined

#endif

#ifdef ame_ArduinoIDE
	#include "Arduino.h"
	

namespace ame{

void MonkeyFile::initialize(){}

bool MonkeyFile::fastCreateDir(Note path){
	return false;
}

bool MonkeyFile::createDir(Note path){
	return false;
}

bool MonkeyFile::createRootDir(Note path){
	return false;
}


bool MonkeyFile::deleteDir(Note path){
	return false;
}

bool MonkeyFile::deleteRootDir(Note path){
	return false;
}


bool MonkeyFile::fastCreateFile(Note file){
	return false;
}

bool MonkeyFile::createFile(Note file){
	return false;
}

bool MonkeyFile::createRootFile(Note file){
	return false;
}


bool MonkeyFile::deleteFile(Note file){
	return false;
}

bool MonkeyFile::deleteRootFile(Note file){
	return false;
}


bool MonkeyFile::fastClearFile(Note file){
	return false;
}

bool MonkeyFile::clearFile(Note file){
	return false;
}

bool MonkeyFile::clearRootFile(Note file){
	return false;
}


bool MonkeyFile::fastWriteText(Note text, Note file){
	return false;
}

bool MonkeyFile::writeText(Note text, Note file){
	return false;
}

bool MonkeyFile::writeRootText(Note text, Note file){
	return false;
}


Note MonkeyFile::fastReadText(Note file){
	return Note();
}

Note MonkeyFile::readText(Note file){
	return Note();
}

Note MonkeyFile::readRootText(Note file){
	return Note();
}


bool MonkeyFile::writeByteArray(ByteArray array, Note file){
	return false;
}

bool MonkeyFile::writeRootByteArray(ByteArray text, Note file){
	return false;
}


ByteArray MonkeyFile::readByteArray(Note file){
	return ByteArray();
}

ByteArray MonkeyFile::readRootByteArray(Note file){
	return ByteArray();
}


bool MonkeyFile::exist(Note file){
	return false;
}

bool MonkeyFile::existRoot(Note file){
	return false;
}

Note MonkeyFile::fixRootPath(Note p){
	if(this->rootPath.length() == 0){
		if(p.length() == 0){
			return "";
		}
		if(p.charAt(0) == '/'){
			return p;
		}
	}
	if(this->rootPath.charAt(0) != '/'){
		MonkeyFileLog(ame_Log_Statement, "fixRootPath",  "println", Note("this->rootPath.charAt(0) != '/'"));
		this->rootPath = Note("/") + this->rootPath;
	}
	int sizeRP = this->rootPath.length();
	if(this->rootPath.charAt(sizeRP - 1) == '/' && p.charAt(0) == '/'){
		MonkeyFileLog(ame_Log_Statement, "fixRootPath",  "println", Note("this->rootPath.charAt(sizeRP - 1) == '/' && p.charAt(0) == '/'"));
		return this->rootPath + p.subNote(1);
	}
	if(this->rootPath.charAt(sizeRP - 1) != '/' && p.charAt(0) == '/'){
		MonkeyFileLog(ame_Log_Statement, "fixRootPath",  "println", Note("this->rootPath.charAt(sizeRP - 1) != '/' && p.charAt(0) == '/'"));
		return this->rootPath + p;
	}
	if(this->rootPath.charAt(sizeRP - 1) == '/' && p.charAt(0) != '/'){
		MonkeyFileLog(ame_Log_Statement, "fixRootPath",  "println", Note("this->rootPath.charAt(sizeRP - 1) == '/' && p.charAt(0) != '/'"));
		return this->rootPath + p;
	}
	if(this->rootPath.charAt(sizeRP - 1) != '/' && p.charAt(0) != '/'){
		MonkeyFileLog(ame_Log_Statement, "fixRootPath",  "println", Note("this->rootPath.charAt(sizeRP - 1) != '/' && p.charAt(0) != '/'"));
		return this->rootPath + Note('/') + p;
	}
	return this->rootPath + p;
}

Note MonkeyFile::fixPath(Note p){
	if(p.length() == 0){
		return "";
	}
	if(p.charAt(0) == '/'){
		return p;
	}
	return Note("/") + p;
}

Note MonkeyFile::fixPath(Note p, Note f){
	if(p.length() == 0){
		if(f.length() == 0){
			return "";
		}
		if(f.charAt(0) == '/'){
			return f;
		}else{
			return Note("/") + f;
		}
	}
	if(f.length() == 0){
		if(p.charAt(0) == '/'){
			return p;
		}else{
			return Note("/") + p;
		}
	}
	if(p.charAt(0) != '/'){
		MonkeyFileLog(ame_Log_Statement, "fixPath",  "println", Note("p.charAt(0) != '/'"));
		p = Note("/") + p;
	}
	int sizeRP = p.length();
	if(p.charAt(sizeRP - 1) == '/' && f.charAt(0) == '/'){
		MonkeyFileLog(ame_Log_Statement, "fixPath",  "println", "p.charAt(sizeRP - 1) == '/' && f.charAt(0) == '/'");
		return p + f.subNote(1);
	}
	if(p.charAt(sizeRP - 1) != '/' && f.charAt(0) == '/'){
		MonkeyFileLog(ame_Log_Statement, "fixPath",  "println", "p.charAt(sizeRP - 1) != '/' && f.charAt(0) == '/'");
		return p + f;
	}
	if(p.charAt(sizeRP - 1) == '/' && f.charAt(0) != '/'){
		MonkeyFileLog(ame_Log_Statement, "fixPath",  "println", "p.charAt(sizeRP - 1) == '/' && f.charAt(0) != '/'");
		return p + f;
	}
	if(p.charAt(sizeRP - 1) != '/' && f.charAt(0) != '/'){
		MonkeyFileLog(ame_Log_Statement, "fixPath",  "println", "p.charAt(sizeRP - 1) != '/' && f.charAt(0) != '/'");
		return p + Note('/') + f;
	}
	return p + f;
}

int MonkeyFile::getFileSize(Note path){
	return 0;
}

int MonkeyFile::getDirectoriesSize(Note path){
	return 0;
}

PrimitiveMap<Note,Note> MonkeyFile::getDirectories(Note dirname, int levels){
	PrimitiveMap<Note,Note> i_map;
	return i_map;
}

}
#endif

#ifdef ame_Windows

namespace ame{

void MonkeyFile::initialize(){}

bool MonkeyFile::fastCreateDir(Note path){
	return false;
}

bool MonkeyFile::createDir(Note path){
	return false;
}

bool MonkeyFile::createRootDir(Note path){
	return false;
}


bool MonkeyFile::deleteDir(Note path){
	return false;
}

bool MonkeyFile::deleteRootDir(Note path){
	return false;
}


bool MonkeyFile::fastCreateFile(Note file){
	return false;
}

bool MonkeyFile::createFile(Note file){
	return false;
}

bool MonkeyFile::createRootFile(Note file){
	return false;
}


bool MonkeyFile::deleteFile(Note file){
	return false;
}

bool MonkeyFile::deleteRootFile(Note file){
	return false;
}


bool MonkeyFile::fastClearFile(Note file){
	return false;
}

bool MonkeyFile::clearFile(Note file){
	return false;
}

bool MonkeyFile::clearRootFile(Note file){
	return false;
}


bool MonkeyFile::fastWriteText(Note text, Note file){
	return false;
}

bool MonkeyFile::writeText(Note text, Note file){
	return false;
}

bool MonkeyFile::writeRootText(Note text, Note file){
	return false;
}


Note MonkeyFile::fastReadText(Note file){
	return Note();
}

Note MonkeyFile::readText(Note file){
	return Note();
}

Note MonkeyFile::readRootText(Note file){
	return Note();
}


bool MonkeyFile::writeByteArray(ByteArray array, Note file){
	return false;
}

bool MonkeyFile::writeRootByteArray(ByteArray text, Note file){
	return false;
}


ByteArray MonkeyFile::readByteArray(Note file){
	return ByteArray();
}

ByteArray MonkeyFile::readRootByteArray(Note file){
	return ByteArray();
}


bool MonkeyFile::exist(Note file){
	return false;
}

bool MonkeyFile::existRoot(Note file){
	return false;
}

Note MonkeyFile::fixRootPath(Note p){
	if(this->rootPath.length() == 0){
		if(p.length() == 0){
			return "";
		}
		if(p.charAt(0) == '/'){
			return p;
		}
	}
	if(this->rootPath.charAt(0) != '/'){
		MonkeyFileLog(ame_Log_Statement, "fixRootPath",  "println", Note("this->rootPath.charAt(0) != '/'"));
		this->rootPath = Note("/") + this->rootPath;
	}
	int sizeRP = this->rootPath.length();
	if(this->rootPath.charAt(sizeRP - 1) == '/' && p.charAt(0) == '/'){
		MonkeyFileLog(ame_Log_Statement, "fixRootPath",  "println", Note("this->rootPath.charAt(sizeRP - 1) == '/' && p.charAt(0) == '/'"));
		return this->rootPath + p.subNote(1);
	}
	if(this->rootPath.charAt(sizeRP - 1) != '/' && p.charAt(0) == '/'){
		MonkeyFileLog(ame_Log_Statement, "fixRootPath",  "println", Note("this->rootPath.charAt(sizeRP - 1) != '/' && p.charAt(0) == '/'"));
		return this->rootPath + p;
	}
	if(this->rootPath.charAt(sizeRP - 1) == '/' && p.charAt(0) != '/'){
		MonkeyFileLog(ame_Log_Statement, "fixRootPath",  "println", Note("this->rootPath.charAt(sizeRP - 1) == '/' && p.charAt(0) != '/'"));
		return this->rootPath + p;
	}
	if(this->rootPath.charAt(sizeRP - 1) != '/' && p.charAt(0) != '/'){
		MonkeyFileLog(ame_Log_Statement, "fixRootPath",  "println", Note("this->rootPath.charAt(sizeRP - 1) != '/' && p.charAt(0) != '/'"));
		return this->rootPath + Note('/') + p;
	}
	return this->rootPath + p;
}

Note MonkeyFile::fixPath(Note p){
	if(p.length() == 0){
		return "";
	}
	if(p.charAt(0) == '/'){
		return p;
	}
	return Note("/") + p;
}

Note MonkeyFile::fixPath(Note p, Note f){
	if(p.length() == 0){
		if(f.length() == 0){
			return "";
		}
		if(f.charAt(0) == '/'){
			return f;
		}else{
			return Note("/") + f;
		}
	}
	if(f.length() == 0){
		if(p.charAt(0) == '/'){
			return p;
		}else{
			return Note("/") + p;
		}
	}
	if(p.charAt(0) != '/'){
		MonkeyFileLog(ame_Log_Statement, "fixPath",  "println", Note("p.charAt(0) != '/'"));
		p = Note("/") + p;
	}
	int sizeRP = p.length();
	if(p.charAt(sizeRP - 1) == '/' && f.charAt(0) == '/'){
		MonkeyFileLog(ame_Log_Statement, "fixPath",  "println", "p.charAt(sizeRP - 1) == '/' && f.charAt(0) == '/'");
		return p + f.subNote(1);
	}
	if(p.charAt(sizeRP - 1) != '/' && f.charAt(0) == '/'){
		MonkeyFileLog(ame_Log_Statement, "fixPath",  "println", "p.charAt(sizeRP - 1) != '/' && f.charAt(0) == '/'");
		return p + f;
	}
	if(p.charAt(sizeRP - 1) == '/' && f.charAt(0) != '/'){
		MonkeyFileLog(ame_Log_Statement, "fixPath",  "println", "p.charAt(sizeRP - 1) == '/' && f.charAt(0) != '/'");
		return p + f;
	}
	if(p.charAt(sizeRP - 1) != '/' && f.charAt(0) != '/'){
		MonkeyFileLog(ame_Log_Statement, "fixPath",  "println", "p.charAt(sizeRP - 1) != '/' && f.charAt(0) != '/'");
		return p + Note('/') + f;
	}
	return p + f;
}

int MonkeyFile::getFileSize(Note path){
	return 0;
}

int MonkeyFile::getDirectoriesSize(Note path){
	return 0;
}

PrimitiveMap<Note,Note> MonkeyFile::getDirectories(Note dirname, int levels){
	PrimitiveMap<Note,Note> i_map;
	return i_map;
}

}

#endif

#endif
