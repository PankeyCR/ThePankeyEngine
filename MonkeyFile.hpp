
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

		virtual bool fastCreateDir(Note path){return false;}
		virtual bool createDir(Note path){return false;}
		virtual bool createRootDir(Note path){return false;}

		virtual bool deleteDir(Note path){return false;}
		virtual bool deleteRootDir(Note path){return false;}

		virtual bool fastCreateFile(Note file){return false;}
		virtual bool createFile(Note file){return false;}
		virtual bool createRootFile(Note file){return false;}

		virtual bool deleteFile(Note file){return false;}
		virtual bool deleteRootFile(Note file){return false;}

		virtual bool fastClearFile(Note file){return false;}
		virtual bool clearFile(Note file){return false;}
		virtual bool clearRootFile(Note file){return false;}

		virtual bool fastWriteText(Note text, Note file){return false;}
		virtual bool writeText(Note text, Note file){return false;}
		virtual bool writeRootText(Note text, Note file){return false;}

		virtual Note fastReadText(Note file){return "";}
		virtual Note readText(Note file){return "";}
		virtual Note readRootText(Note file){return "";}

		virtual bool writeByteArray(ByteArray array, Note file){return false;}
		virtual bool writeRootByteArray(ByteArray text, Note file){return false;}

		virtual ByteArray readByteArray(Note file){return ByteArray();}
		virtual ByteArray readRootByteArray(Note file){return ByteArray();}

		virtual bool exist(Note file){return false;}
		virtual bool existRoot(Note file){return false;}

		virtual Note fixRootPath(Note p);

		virtual Note fixPath(Note p);

		virtual Note fixPath(Note p, Note f);

		virtual int getFileSize(Note path){return 0;}
		virtual int getDirectoriesSize(Note path){return 0;}

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

Note MonkeyFile::fixRootPath(Note p){
	if(this->rootPath.length() == 0){
		if(p.length() == 0){
			return "";
		}
		if(p[0] == '/'){
			return p;
		}
	}
	if(this->rootPath[0] != '/'){
		MonkeyFileLog(ame_Log_Statement, "fixRootPath",  "println", Note("this->rootPath[0] != '/'"));
		this->rootPath = Note("/") + this->rootPath;
	}
	int sizeRP = this->rootPath.length();
	if(this->rootPath[sizeRP - 1] == '/' && p[0] == '/'){
		MonkeyFileLog(ame_Log_Statement, "fixRootPath",  "println", Note("this->rootPath[sizeRP - 1] == '/' && p[0] == '/'"));
		return this->rootPath + p.subNote(1);
	}
	if(this->rootPath[sizeRP - 1] != '/' && p[0] == '/'){
		MonkeyFileLog(ame_Log_Statement, "fixRootPath",  "println", Note("this->rootPath[sizeRP - 1] != '/' && p[0] == '/'"));
		return this->rootPath + p;
	}
	if(this->rootPath[sizeRP - 1] == '/' && p[0] != '/'){
		MonkeyFileLog(ame_Log_Statement, "fixRootPath",  "println", Note("this->rootPath[sizeRP - 1] == '/' && p[0] != '/'"));
		return this->rootPath + p;
	}
	if(this->rootPath[sizeRP - 1] != '/' && p[0] != '/'){
		MonkeyFileLog(ame_Log_Statement, "fixRootPath",  "println", Note("this->rootPath[sizeRP - 1] != '/' && p[0] != '/'"));
		return this->rootPath + Note('/') + p;
	}
	return this->rootPath + p;
}

Note MonkeyFile::fixPath(Note p){
	if(p.length() == 0){
		return "";
	}
	if(p[0] == '/'){
		return p;
	}
	return Note("/") + p;
}

Note MonkeyFile::fixPath(Note p, Note f){
	if(p.length() == 0){
		if(f.length() == 0){
			return "";
		}
		if(f[0] == '/'){
			return f;
		}else{
			return Note("/") + f;
		}
	}
	if(f.length() == 0){
		if(p[0] == '/'){
			return p;
		}else{
			return Note("/") + p;
		}
	}
	if(p[0] != '/'){
		MonkeyFileLog(ame_Log_Statement, "fixPath",  "println", Note("p[0] != '/'"));
		p = Note("/") + p;
	}
	int sizeRP = p.length();
	if(p[sizeRP - 1] == '/' && f[0] == '/'){
		MonkeyFileLog(ame_Log_Statement, "fixPath",  "println", "p[sizeRP - 1] == '/' && f[0] == '/'");
		return p + f.subNote(1);
	}
	if(p[sizeRP - 1] != '/' && f[0] == '/'){
		MonkeyFileLog(ame_Log_Statement, "fixPath",  "println", "p[sizeRP - 1] != '/' && f[0] == '/'");
		return p + f;
	}
	if(p[sizeRP - 1] == '/' && f[0] != '/'){
		MonkeyFileLog(ame_Log_Statement, "fixPath",  "println", "p[sizeRP - 1] == '/' && f[0] != '/'");
		return p + f;
	}
	if(p[sizeRP - 1] != '/' && f[0] != '/'){
		MonkeyFileLog(ame_Log_Statement, "fixPath",  "println", "p[sizeRP - 1] != '/' && f[0] != '/'");
		return p + Note('/') + f;
	}
	return p + f;
}

}

#endif