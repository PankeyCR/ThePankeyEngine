
/**
 *
 * @author PankeyCR - Manuel Sanchez Badilla
 *
 */
 
#ifndef MonkeyFile_hpp
#define MonkeyFile_hpp

#ifndef ame_Enviroment_Defined
	#include "Arduino.h"
#endif

#ifdef ame_Windows

#endif

#ifdef ame_ArduinoIDE
	#include "Arduino.h"
#endif

namespace ame{

class MonkeyFile;

}

#include "ElementId.hpp"
#include "ByteArray.hpp"
#include "LinkedList.hpp"
#include "PrimitiveList.hpp"
#include "PrimitiveMap.hpp"

#ifdef MonkeyFileLogApp
	#include "Logger.hpp"
	#define MonkeyFileLog(name,method,type,mns) Log(name,method,type,mns)
#else
	#define MonkeyFileLog(name,method,type,mns)
#endif

namespace ame{

class MonkeyFile{
    public:
		virtual ~MonkeyFile(){}
		
		virtual bool isOpen(){
			return m_open;
		}
		
		virtual void setRootPathFile(String filepath){
			MonkeyFileLog("MonkeyFile", "setRootPathFile",  "println", filepath);
			this->rootPath = this->fixPath(filepath);
			this->createDir(this->rootPath);
		}
		virtual String getRootPathFile(){
			return this->rootPath;
		}
		
		virtual bool createDir(String path)=0;
		virtual bool createRootDir(String path)=0;
		
		virtual bool deleteDir(String path)=0;
		virtual bool deleteRootDir(String path)=0;
		
		virtual bool createFile(String file)=0;
		virtual bool createRootFile(String file)=0;
		
		virtual bool deleteFile(String file)=0;
		virtual bool deleteRootFile(String file)=0;
		
		virtual bool clearFile(String file)=0;
		virtual bool clearRootFile(String file)=0;
		
		virtual bool writeText(String text, String file)=0;
		virtual bool writeRootText(String text, String file)=0;
		
		virtual String readText(String file)=0;
		virtual String readRootText(String file)=0;
		
		virtual bool writeByteArray(ByteArray array, String file)=0;
		virtual bool writeRootByteArray(ByteArray text, String file)=0;
		
		virtual ByteArray readByteArray(String file)=0;
		virtual ByteArray readRootByteArray(String file)=0;
		
		virtual bool exist(String file)=0;
		virtual bool existRoot(String file)=0;
		
		virtual String fixRootPath(String p){
			if(this->rootPath.length() == 0){
				if(p.length() == 0){
					return "";
				}
				if(p.charAt(0) == '/'){
					return p;
				}
			}
			if(this->rootPath.charAt(0) != '/'){
				MonkeyFileLog("MonkeyFile", "fixRootPath",  "println", String("this->rootPath.charAt(0) != '/'"));
				this->rootPath = "/" + this->rootPath;
			}
			int sizeRP = this->rootPath.length();
			if(this->rootPath.charAt(sizeRP - 1) == '/' && p.charAt(0) == '/'){
				MonkeyFileLog("MonkeyFile", "fixRootPath",  "println", String("this->rootPath.charAt(sizeRP - 1) == '/' && p.charAt(0) == '/'"));
				return this->rootPath + p.substring(1);
			}
			if(this->rootPath.charAt(sizeRP - 1) != '/' && p.charAt(0) == '/'){
				MonkeyFileLog("MonkeyFile", "fixRootPath",  "println", String("this->rootPath.charAt(sizeRP - 1) != '/' && p.charAt(0) == '/'"));
				return this->rootPath + p;
			}
			if(this->rootPath.charAt(sizeRP - 1) == '/' && p.charAt(0) != '/'){
				MonkeyFileLog("MonkeyFile", "fixRootPath",  "println", String("this->rootPath.charAt(sizeRP - 1) == '/' && p.charAt(0) != '/'"));
				return this->rootPath + p;
			}
			if(this->rootPath.charAt(sizeRP - 1) != '/' && p.charAt(0) != '/'){
				MonkeyFileLog("MonkeyFile", "fixRootPath",  "println", String("this->rootPath.charAt(sizeRP - 1) != '/' && p.charAt(0) != '/'"));
				return this->rootPath + '/' + p;
			}
			return this->rootPath + p;
		}
		
		virtual String fixPath(String p){
			if(p.length() == 0){
				return "";
			}
			if(p.charAt(0) == '/'){
				return p;
			}
			return "/" + p;
		}
		
		virtual String fixPath(String p, String f){
			if(p.length() == 0){
				if(f.length() == 0){
					return "";
				}
				if(f.charAt(0) == '/'){
					return f;
				}else{
					return "/" + f;
				}
			}
			if(p.charAt(0) != '/'){
				MonkeyFileLog("MonkeyFile", "fixRootPath",  "println", String("p.charAt(0) != '/'"));
				p = "/" + p;
			}
			int sizeRP = p.length();
			if(p.charAt(sizeRP - 1) == '/' && f.charAt(0) == '/'){
				MonkeyFileLog("MonkeyFile", "fixRootPath",  "println", "p.charAt(sizeRP - 1) == '/' && f.charAt(0) == '/'");
				return p + f.substring(1);
			}
			if(p.charAt(sizeRP - 1) != '/' && f.charAt(0) == '/'){
				MonkeyFileLog("MonkeyFile", "fixRootPath",  "println", "p.charAt(sizeRP - 1) != '/' && f.charAt(0) == '/'");
				return p + f;
			}
			if(p.charAt(sizeRP - 1) == '/' && f.charAt(0) != '/'){
				MonkeyFileLog("MonkeyFile", "fixRootPath",  "println", "p.charAt(sizeRP - 1) == '/' && f.charAt(0) != '/'");
				return p + f;
			}
			if(p.charAt(sizeRP - 1) != '/' && f.charAt(0) != '/'){
				MonkeyFileLog("MonkeyFile", "fixRootPath",  "println", "p.charAt(sizeRP - 1) != '/' && f.charAt(0) != '/'");
				return p + '/' + f;
			}
			return p + f;
		}
		
		virtual PrimitiveMap<String,String> getDirectories(String dirname, int levels)=0;
		
	protected:
		String rootPath;
		bool m_open = false;
};

}

#endif 
