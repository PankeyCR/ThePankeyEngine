

/**
 *
 * @author PankeyCR - Manuel Sanchez Badilla
 *
 */
 
#ifndef MonkeyFile_h
#define MonkeyFile_h

#include "Arduino.h"

namespace ame{

class MonkeyFile;

}

#include "Map.h"
#include "KPMap.h"
#include "MonkeyFileFuntion.h"

#include <SPI.h>
#include <SD.h>

namespace ame{

class MonkeyFile{
    public:
		MonkeyFile();
		MonkeyFile(int chip);
		MonkeyFile(int chip, Map<cppObjectClass, MonkeyFileFunction>* functions);
		virtual ~MonkeyFile();
		
		virtual void setRootPathFile(String filepath);
		virtual String getRootPathFile();
		
		virtual bool create(String file);
		virtual bool createRoot(String file);
		
		virtual bool write(String file, String text);
		virtual bool writeRoot(String file, String text);
		
		virtual String read(String file);
		virtual String readRoot(String file);
		
		virtual bool exist(String file);
		virtual bool existRoot(String file);
		
		virtual bool deleteFile(String file);
		virtual bool deleteRootFile(String file);
		
		virtual void addFileFunction(cppObjectClass* cls, MonkeyFileFunction* funtion);
		virtual MonkeyFileFunction* getFileFunction(cppObjectClass* cls);
		virtual MonkeyFileFunction* removeFileFunction(cppObjectClass* cls);
		virtual void removeDeleteFileFunction(cppObjectClass* cls);
		
		virtual bool save(cppObject* save,String path,String key);
		virtual bool saveRoot(cppObject* save,String path,String key);
		
		virtual cppObject* load(cppObjectClass* cls,cppObject* load,String path,String key);
		virtual cppObject* loadRoot(cppObjectClass* cls,cppObject* load,String path,String key);
		
		virtual bool deleting(cppObjectClass* cls,cppObject* load,String path,String key);
		virtual bool deletingRoot(cppObjectClass* cls,cppObject* load,String path,String key);
	protected:
		String rootPath;
		Map<cppObjectClass, MonkeyFileFunction>* fileFunctions = nullptr;
};

}

#endif 
