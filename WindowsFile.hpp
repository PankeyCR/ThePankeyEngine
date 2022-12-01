
/**
 *
 * @author PankeyCR - Manuel Sanchez Badilla
 *
 */

#ifndef CONFIGURATION_WindowsFile_hpp
#define CONFIGURATION_WindowsFile_hpp

	#include "ame_Enviroment.hpp"

	#if defined(DISABLE_WindowsFile) || !defined(ame_Windows) 
		#define WindowsFile_hpp

		#define IMPLEMENTATION_WindowsFile
		#define IMPLEMENTING_WindowsFile
	#else
		#if defined(DISABLE_IMPLEMENTATION_WindowsFile)
			#define IMPLEMENTATION_WindowsFile
			#define IMPLEMENTING_WindowsFile
		#endif
	#endif
#endif

#ifndef WindowsFile_hpp
#define WindowsFile_hpp
#define WindowsFile_AVAILABLE

#ifndef DISABLE_IMPLEMENTATION_WindowsFile
	#define IMPLEMENTATION_WindowsFile IMPLEMENTATION(public WindowsFile)
	#define IMPLEMENTING_WindowsFile IMPLEMENTING(public WindowsFile)
#endif

#include <windows.h>
#include <fstream>

#include "MonkeyFile.hpp"
#include "PrimitiveMap.hpp"
#include "Class.hpp"
#include "ByteArrayHelper.hpp"

#ifdef WindowsFile_LogApp
	#include "ame_Logger_config.hpp"
	#include "ame_Logger.hpp"

	#define WindowsFileLog(location,method,type,mns) ame_Log(this,location,"WindowsFile",method,type,mns)
	#define const_WindowsFileLog(location,method,type,mns)
	#define StaticWindowsFileLog(pointer,location,method,type,mns) ame_Log(pointer,location,"WindowsFile",method,type,mns)
#else
	#ifdef WindowsFile_LogDebugApp
		#include "ame_Logger_config.hpp"
		#include "ame_Logger.hpp"

		#define WindowsFileLog(location,method,type,mns) ame_LogDebug(this,location,"WindowsFile",method,type)
		#define const_WindowsFileLog(location,method,type,mns)
		#define StaticWindowsFileLog(pointer,location,method,type,mns) ame_LogDebug(pointer,location,"WindowsFile",method,type)
	#else
		#define WindowsFileLog(location,method,type,mns)
		#define const_WindowsFileLog(location,method,type,mns)
		#define StaticWindowsFileLog(pointer,location,method,type,mns)
	#endif
#endif

namespace ame{

using namespace std;

class WindowsFile : public MonkeyFile{
    public:

		#ifdef ame_Windows
		WindowsFile(){}
		#endif

		virtual ~WindowsFile(){}

		virtual void initialize(){}

		virtual bool fastCreateDir(Note a_path){
			Note i_path = fixPath(a_path);
			WindowsFileLog(ame_Log_Statement, "fastCreateDir",  "println", Note(i_path));
            CreateDirectory (i_path.pointer(), NULL);
			return true;
		}

		virtual bool createDir(Note a_path){
			Note i_path = fixPath(a_path);
			WindowsFileLog(ame_Log_Statement, "createDir",  "println", Note(i_path));
            CreateDirectory (i_path.pointer(), NULL);
			return true;
		}

		virtual bool createRootDir(Note a_path){
			Note i_path = this->fixRootPath(a_path);
			WindowsFileLog(ame_Log_Statement, "createDir",  "println", Note(i_path));
            CreateDirectory (i_path.pointer(), NULL);
			return true;
		}

		virtual bool deleteDir(Note a_path){
			Note i_path = fixPath(a_path);
			WindowsFileLog(ame_Log_Statement, "deleteDir",  "println", Note(i_path));

			return false;
		}

		virtual bool deleteRootDir(Note path){
			Note i_path = this->fixRootPath(path);
			WindowsFileLog(ame_Log_Statement, "deleteRootDir",  "println", i_path);

			return true;
		}

		virtual bool fastCreateFile(Note a_path){
			Note i_path = fixPath(a_path);
            fstream i_file;
            i_file.open(i_path.pointer(),ios::out);
            i_file.close();
			return true;
		}

		virtual bool createFile(Note a_path){
			Note i_path = fixPath(a_path);
            fstream file;
            file.open(i_path.pointer(),ios::out);
            file.close();
			return true;
		}
		virtual bool createRootFile(Note a_path){
			Note i_path = this->fixRootPath(a_path);
            fstream file;
            file.open(i_path.pointer(),ios::out);
            file.close();
			return true;
		}

		virtual bool deleteFile(Note a_path){
			Note i_path = fixPath(a_path);
			WindowsFileLog(ame_Log_Statement, "deleteFile",  "println", i_path);
			return false;
		}
		virtual bool deleteRootFile(Note a_path){
			Note i_path = this->fixRootPath(a_path);
			WindowsFileLog(ame_Log_Statement, "deleteRootFile",  "println", i_path);
			return false;
		}

		virtual bool fastClearFile(Note a_path){
			Note i_path = fixPath(a_path);
            fstream file;
            file.open(i_path.pointer(),ios::out);
            file.close();
			return true;
		}

		virtual bool clearFile(Note a_path){
			Note i_path = fixPath(a_path);
            fstream file;
            file.open(i_path.pointer(),ios::out);
            file.close();
			return true;
		}

		virtual bool clearRootFile(Note a_path){
			Note i_path = fixRootPath(a_path);
            fstream file;
            file.open(i_path.pointer(),ios::out);
            file.close();
			return true;
		}

		virtual bool fastWriteText(Note a_text, Note a_path){
			Note i_path = fixPath(a_path);
			WindowsFileLog(ame_Log_Statement, "fastWriteText",  "println", i_path);
			WindowsFileLog(ame_Log_Statement, "fastWriteText",  "println", a_text);
            fstream outfile;

            outfile.open(i_path.pointer(), std::ios_base::out);
            if (!outfile.is_open()) {
                outfile.close();
                return false;
            }
            outfile.write(a_text.pointer(), a_text.getPosition());
            outfile.close();
			return true;
		}

		virtual bool writeText(Note a_text, Note a_path){
			Note i_path = fixPath(a_path);
			WindowsFileLog(ame_Log_Statement, "fastWriteText",  "println", i_path);
			WindowsFileLog(ame_Log_Statement, "fastWriteText",  "println", a_text);
            fstream outfile;

            outfile.open(i_path.pointer(), std::ios_base::out);
            if (!outfile.is_open()) {
                outfile.close();
                return false;
            }
            outfile.write(a_text.pointer(), a_text.getPosition());
            outfile.close();
			return true;
		}

		virtual bool writeRootText(Note a_text, Note a_path){
			Note i_path = this->fixRootPath(a_path);
			WindowsFileLog(ame_Log_Statement, "fastWriteText",  "println", i_path);
			WindowsFileLog(ame_Log_Statement, "fastWriteText",  "println", a_text);
            fstream outfile;

            outfile.open(i_path.pointer(), std::ios_base::out);
            if (!outfile.is_open()) {
                outfile.close();
                return false;
            }
            outfile.write(a_text.pointer(), a_text.getPosition());
            outfile.close();
			return true;
		}

		virtual Note fastReadText(Note a_path){
			Note i_path = fixPath(a_path);
			WindowsFileLog(ame_Log_Statement, "readText",  "println", i_path);
            std::string readLineFromInput;

            std::ifstream readFile(i_path.pointer());
            if (readFile)
                std::getline(readFile, readLineFromInput);
            return Note(readLineFromInput.c_str());
		}

		virtual Note readText(Note a_path){
			Note i_path = fixPath(a_path);
			WindowsFileLog(ame_Log_Statement, "readText",  "println", i_path);
            std::string readLineFromInput;

            std::ifstream readFile(i_path.pointer());
            if (readFile)
                std::getline(readFile, readLineFromInput);
            return Note(readLineFromInput.c_str());
		}

		virtual Note readRootText(Note a_path){
			Note i_path = this->fixRootPath(a_path);
			WindowsFileLog(ame_Log_Statement, "readRootText",  "println", i_path);
            std::string readLineFromInput;

            std::ifstream readFile(i_path.pointer());
            if (readFile)
                std::getline(readFile, readLineFromInput);
            return Note(readLineFromInput.c_str());
		}

		virtual bool writeByteArray(ByteArray array, Note a_path){
			Note i_path = fixPath(a_path);
			WindowsFileLog(ame_Log_Statement, "writeByteArray",  "println", i_path);

			return true;
		}

		virtual bool writeRootByteArray(ByteArray array, Note path){
			Note rpath = this->fixRootPath(path);
			WindowsFileLog(ame_Log_Statement, "writeRootByteArray",  "println", rpath);

			return true;
		}

		virtual ByteArray readByteArray(Note p){
			Note path = fixPath(p);
			WindowsFileLog(ame_Log_Statement, "readByteArray",  "println", path);

			ByteArray array;
			return array;
		}

		virtual ByteArray readRootByteArray(Note path){
			Note rpath = this->fixRootPath(path);
			WindowsFileLog(ame_Log_Statement, "readRootByteArray",  "println", rpath);

			ByteArray array;
			return array;
		}

		virtual bool exist(Note p){
			Note path = fixPath(p);
			WindowsFileLog(ame_Log_Statement, "exist",  "println", "");
			WindowsFileLog(ame_Log_Statement, "path ",  "println", path);
			return false;
		}
		virtual bool existRoot(Note path){
			Note rpath = this->fixRootPath(path);
			WindowsFileLog(ame_Log_Statement, "existRoot",  "println", "");
			WindowsFileLog(ame_Log_Statement, "path ",  "println", rpath);
			return false;
		}

		virtual bool isOpen(){
			return true;
		}

		virtual int getFileSize(Note path){
			WindowsFileLog(ame_Log_Statement, "getDirectoriesSize",  "println", Note("path: ") + path);

			return 0;
		}

		virtual int getDirectoriesSize(Note path){
			WindowsFileLog(ame_Log_Statement, "getDirectoriesSize",  "println", Note("path: ") + path);

			return 0;
		}

		virtual PrimitiveMap<Note,Note> getDirectories(Note dirname, int levels){
			WindowsFileLog(ame_Log_Statement, "getDirectories",  "println", Note("Listing directory: ") + dirname);

			PrimitiveMap<Note,Note> m_map;
			return m_map;
		}

		#if defined(cppObject_AVAILABLE) && defined(cppObjectClass_AVAILABLE) && defined(ArgsClass_AVAILABLE)
		virtual cppObjectClass* getClass(){
			return ArgsClass<WindowsFile>::getClass();
		}

		virtual bool instanceof(cppObjectClass* cls){
			return cls == ArgsClass<WindowsFile>::getClass();
		}
		#endif

	protected:
};

}

#endif
