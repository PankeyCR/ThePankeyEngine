

/**
 *
 * @author PankeyCR - Manuel Sanchez Badilla
 *
 */
 
#ifndef MonkeyFile_h
#define MonkeyFile_h

#include "Arduino.h"
#include "cppObject.h"
#include "MonkeyFileFuntion.h"


template<class FileMC>
class MonkeyFile : public cppObject{
    public:
		virtual ~MonkeyFile(){}
		virtual void setRootPathFile(String filepath);
		virtual String getRootPathFile();
		virtual FileMC createFile(String file);
		virtual FileMC createRootFile(String file);
		virtual FileMC createRootDirection(String folder);
		virtual bool createDirection(String folder);
		virtual bool deleteFile(String file);
		virtual bool deleteRootFile(String file);
		virtual bool deleteRootDirection(String folder);
		virtual bool deleteDirection(String folder);
		virtual void addFileFuntion(String className,MonkeyFileFuntion<MonkeyFile>* funtion);
		virtual MonkeyFileFuntion<MonkeyFile>* getFileFuntion(String className);
		virtual MonkeyFileFuntion<MonkeyFile>* removeFileFuntion(String className);
		virtual void removeDeleteFileFuntion(String className);
		virtual bool save(cppObject* save,String path,String key);
		virtual bool saveRoot(cppObject* save,String path,String key);
		virtual cppObject* load(String className,cppObject* load,String path,String key);
		virtual cppObject* loadRoot(String className,cppObject* load,String path,String key);
		virtual bool deleting(String className,cppObject* load,String path,String key);
		virtual bool deletingRoot(String className,cppObject* load,String path,String key);
		
		virtual String getClassName();
		virtual String toString();
	protected:
	
	
};

#endif 
