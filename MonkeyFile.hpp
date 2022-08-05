
/**
 *
 * @author PankeyCR - Manuel Sanchez Badilla
 *
 */
 
#include "ame_Enviroment.hpp"

#if defined(DISABLE_MonkeyFile)
	#define MonkeyFile_hpp
#endif

#ifndef MonkeyFile_hpp
#define MonkeyFile_hpp
#define MonkeyFile_AVAILABLE

#ifndef ame_Enviroment_Defined

#endif

#ifdef ame_Windows

#endif

#ifdef ame_ArduinoIDE
	#include "Arduino.h"
#endif


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

class MonkeyFile{
    public:
		virtual ~MonkeyFile(){}
		
		virtual void initialize(){}
		
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
		
		virtual bool fastCreateDir(Note path)=0;
		virtual bool createDir(Note path)=0;
		virtual bool createRootDir(Note path)=0;
		
		virtual bool deleteDir(Note path)=0;
		virtual bool deleteRootDir(Note path)=0;
		
		virtual bool fastCreateFile(Note file)=0;
		virtual bool createFile(Note file)=0;
		virtual bool createRootFile(Note file)=0;
		
		virtual bool deleteFile(Note file)=0;
		virtual bool deleteRootFile(Note file)=0;
		
		virtual bool fastClearFile(Note file)=0;
		virtual bool clearFile(Note file)=0;
		virtual bool clearRootFile(Note file)=0;
		
		virtual bool fastWriteText(Note text, Note file)=0;
		virtual bool writeText(Note text, Note file)=0;
		virtual bool writeRootText(Note text, Note file)=0;
		
		virtual Note fastReadText(Note file)=0;
		virtual Note readText(Note file)=0;
		virtual Note readRootText(Note file)=0;
		
		virtual bool writeByteArray(ByteArray array, Note file)=0;
		virtual bool writeRootByteArray(ByteArray text, Note file)=0;
		
		virtual ByteArray readByteArray(Note file)=0;
		virtual ByteArray readRootByteArray(Note file)=0;
		
		virtual bool exist(Note file)=0;
		virtual bool existRoot(Note file)=0;
		
		virtual Note fixRootPath(Note p){
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
				return this->rootPath + p.substring(1);
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
		
		virtual Note fixPath(Note p){
			if(p.length() == 0){
				return "";
			}
			if(p.charAt(0) == '/'){
				return p;
			}
			return Note("/") + p;
		}
		
		virtual Note fixPath(Note p, Note f){
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
				return p + f.substring(1);
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
		
		virtual int getFileSize(Note path)=0;
		virtual int getDirectoriesSize(Note path)=0;
		
		virtual PrimitiveMap<Note,Note> getDirectories(Note dirname, int levels)=0;
		
	protected:
		Note rootPath;
		bool m_open = false;
};

}

#endif