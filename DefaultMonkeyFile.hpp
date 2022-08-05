
/**
 *
 * @author PankeyCR - Manuel Sanchez Badilla
 *
 */
 
#include "ame_Enviroment.hpp"

#if defined(DISABLE_DefaultMonkeyFile)
	#define DefaultMonkeyFile_hpp
#endif

#ifndef DefaultMonkeyFile_hpp
#define DefaultMonkeyFile_hpp
#define DefaultMonkeyFile_AVAILABLE

#ifndef ame_Enviroment_Defined

#endif

#ifdef ame_Windows

#endif

#ifdef ame_ArduinoIDE
	#include "Arduino.h"
	#include <SPI.h>
	#include <SD.h>
	#if defined(ame_GENERIC_ESP32)
		#include "FS.h"
	#endif
#endif

#include "MonkeyFile.hpp"
#include "PrimitiveMap.hpp"

#ifdef DefaultMonkeyFile_LogApp
	#include "ame_Logger_config.hpp"
	#include "ame_Logger.hpp"
	
	#define DefaultMonkeyFileLog(location,method,type,mns) ame_Log(this,location,"DefaultMonkeyFile",method,type,mns)
	#define const_DefaultMonkeyFileLog(location,method,type,mns) 
	#define StaticDefaultMonkeyFileLog(pointer,location,method,type,mns) ame_Log(pointer,location,"DefaultMonkeyFile",method,type,mns)
#else
	#ifdef DefaultMonkeyFile_LogDebugApp
		#include "ame_Logger_config.hpp"
		#include "ame_Logger.hpp"
		
		#define DefaultMonkeyFileLog(location,method,type,mns) ame_LogDebug(this,location,"DefaultMonkeyFile",method,type)
		#define const_DefaultMonkeyFileLog(location,method,type,mns) 
		#define StaticDefaultMonkeyFileLog(pointer,location,method,type,mns) ame_LogDebug(pointer,location,"DefaultMonkeyFile",method,type)
	#else
		#define DefaultMonkeyFileLog(location,method,type,mns) 
		#define const_DefaultMonkeyFileLog(location,method,type,mns) 
		#define StaticDefaultMonkeyFileLog(pointer,location,method,type,mns) 
	#endif
#endif

namespace ame{

template<class T>
class DefaultMonkeyFile : public MonkeyFile{
    public:
		static bool init;
		
		#ifdef ame_ArduinoIDE
		DefaultMonkeyFile(const DefaultMonkeyFile& file) : m_sd(file.m_sd){}
		DefaultMonkeyFile(T &t) : m_sd(t){}
		#endif
		
		virtual ~DefaultMonkeyFile(){}
		
		virtual void initialize(){
			if(!init){
				init = true;
				#if defined(ame_ESP32_DEV)
				DefaultMonkeyFile(ame_Log_Statement, "Constructor",  "println", "ARDUINO_ESP32_DEV");
				SPI.begin(14, 2, 15, 13);
				m_sd.begin(13);
				uint8_t cardType = m_sd.cardType();

				if(cardType == CARD_NONE){
					DefaultMonkeyFile(ame_Log_Statement, "Constructor",  "println", "No SD card attached");
					return;
				}
				#elif defined(ame_TTGO_T7)
				DefaultMonkeyFile(ame_Log_Statement, "Constructor",  "println", "ARDUINO_TTGO_T7_V14_Mini32");
				SPI.begin(21, 22, 19, 0);//sclk , miso , mosi , cs
				m_sd.begin(0);
				uint8_t cardType = m_sd.cardType();

				if(cardType == CARD_NONE){
					DefaultMonkeyFile(ame_Log_Statement, "Constructor",  "println", "No SD card attached");
					return;
				}
				#elif defined(ame_GENERIC_ARDUINO)
				DefaultMonkeyFile(ame_Log_Statement, "Constructor",  "println", "ARDUINO_ARCH_AVR");
				m_sd.begin(4);
				#elif defined(ame_ADAFRUIT_FEATHER_M0)
				DefaultMonkeyFile(ame_Log_Statement, "Constructor",  "println", "ARDUINO_SAMD_ZERO");
				m_sd.begin(4);
				#endif
				this->m_open = true;
				DefaultMonkeyFile(ame_Log_Statement, "Constructor",  "println", "ARDUINO_SAMD_ZERO");
			}
		}
		
		virtual bool fastCreateDir(Note p){
			Note path = fixPath(p);
			DefaultMonkeyFile(ame_Log_Statement, "fastCreateDir",  "println", Note(path));
			return m_sd.mkdir(path.toString());
		}
		
		virtual bool createDir(Note p){
			Note path = fixPath(p);
			DefaultMonkeyFile(ame_Log_Statement, "createDir",  "println", Note(path));
			if(m_sd.exists(path.toString())){
				DefaultMonkeyFile(ame_Log_Statement, "createDir",  "println", "all ready exists");
				return false;
			}
			if(m_sd.mkdir(path.toString())){
				DefaultMonkeyFile(ame_Log_Statement, "createDir",  "println", "Dir created");
				return true;
			}else{
				DefaultMonkeyFile(ame_Log_Statement, "createDir",  "println", "mkdir failed");
			}
			return false;
		}
		
		virtual bool createRootDir(Note path){
			Note rpath = this->fixRootPath(path);
			if(!m_sd.exists(this->rootPath.toString())){
				m_sd.mkdir(this->rootPath.toString());
				DefaultMonkeyFile(ame_Log_Statement, "createRootDir",  "println", "creates rootdir");
			}
			if(m_sd.exists(rpath.toString())){
				DefaultMonkeyFile(ame_Log_Statement, "createRootDir",  "println", "all ready exists");
				return false;
			}
			DefaultMonkeyFile(ame_Log_Statement, "createRootDir",  "println", this->rootPath+"/"+path);
			if(m_sd.mkdir(rpath.toString())){
				DefaultMonkeyFile(ame_Log_Statement, "createRootDir",  "println", "Dir created");
			}else{
				DefaultMonkeyFile(ame_Log_Statement, "createRootDir",  "println", "mkdir failed");
			}
			return true;
		}
		
		virtual bool deleteDir(Note p){
			Note path = fixPath(p);
			DefaultMonkeyFile(ame_Log_Statement, "deleteDir",  "println", Note(path));
			if(!m_sd.exists(path.toString())){
				DefaultMonkeyFile(ame_Log_Statement, "deleteDir",  "println", "doesnt exists");
				return false;
			}
			if(m_sd.rmdir(path.toString())){
				DefaultMonkeyFile(ame_Log_Statement, "deleteDir",  "println", "Dir deleted");
				return true;
			}else{
				DefaultMonkeyFile(ame_Log_Statement, "deleteDir",  "println", "rmdir failed");
			}
			return false;
		}
		
		virtual bool deleteRootDir(Note path){
			Note rpath = this->fixRootPath(path);
			DefaultMonkeyFile(ame_Log_Statement, "deleteRootDir",  "println", rpath);
			if(!m_sd.exists(rpath.toString())){
				DefaultMonkeyFile(ame_Log_Statement, "deleteRootDir",  "println", "doesnt exists");
				return false;
			}
			if(m_sd.rmdir(rpath.toString())){
				DefaultMonkeyFile(ame_Log_Statement, "deleteRootDir",  "println", "Dir deleted");
			}else{
				DefaultMonkeyFile(ame_Log_Statement, "deleteRootDir",  "println", "rmdir failed");
			}
			return true;
		}
		
		virtual bool fastCreateFile(Note p){
			Note path = fixPath(p);
			DefaultMonkeyFile(ame_Log_Statement, "createFile",  "println", path);
			File myFile = m_sd.open(path.toString(), FILE_WRITE);
			myFile.close();
			return true;
		}
		
		virtual bool createFile(Note p){
			Note path = fixPath(p);
			DefaultMonkeyFile(ame_Log_Statement, "createFile",  "println", path);
			File myFile = m_sd.open(path.toString(), FILE_WRITE);
			myFile.close();
			return true;
		}
		virtual bool createRootFile(Note path){
			Note rpath = this->fixRootPath(path);
			DefaultMonkeyFile(ame_Log_Statement, "createRootFile",  "println", rpath);
			File myFile = m_sd.open(rpath.toString(), FILE_WRITE);
			myFile.close();
			return true;
		}
		
		virtual bool deleteFile(Note p){
			Note path = fixPath(p);
			DefaultMonkeyFile(ame_Log_Statement, "deleteFile",  "println", path);
			return m_sd.remove(path.toString());
		}
		virtual bool deleteRootFile(Note path){
			Note rpath = this->fixRootPath(path);
			DefaultMonkeyFile(ame_Log_Statement, "deleteRootFile",  "println", rpath);
			if(!m_sd.exists(rpath.toString())){
				DefaultMonkeyFile(ame_Log_Statement, "deleteRootDir",  "println", "doesnt exists");
				return false;
			}
			return m_sd.remove(rpath.toString());
		}
		
		virtual bool fastClearFile(Note p){
			Note path = fixPath(p);
			m_sd.remove(path.toString());
			File myFile = m_sd.open(path.toString(), FILE_WRITE);
			myFile.close();
			return true;
		}
		
		virtual bool clearFile(Note p){
			Note path = fixPath(p);
			if(!m_sd.exists(path.toString())){
				DefaultMonkeyFile(ame_Log_Statement, "clearFile",  "println", "doesnt exists");
				return false;
			}
			m_sd.remove(path.toString());
			File myFile = m_sd.open(path.toString(), FILE_WRITE);
			myFile.close();
			return true;
		}
		
		virtual bool clearRootFile(Note p){
			Note path = fixRootPath(p);
			if(!m_sd.exists(path.toString())){
				DefaultMonkeyFile(ame_Log_Statement, "clearRootFile",  "println", "doesnt exists");
				return false;
			}
			m_sd.remove(path.toString());
			File myFile = m_sd.open(path.toString(), FILE_WRITE);
			myFile.close();
			return true;
		}
		
		virtual bool fastWriteText(Note text, Note p){
			Note path = fixPath(p);
			DefaultMonkeyFile(ame_Log_Statement, "fastWriteText",  "println", path);
			DefaultMonkeyFile(ame_Log_Statement, "fastWriteText",  "println", text);
			#if defined(ARDUINO_ARCH_AVR)
			File myFile = m_sd.open(path.toString(), FILE_WRITE);
			#elif defined(ARDUINO_ESP32_DEV)
			File myFile = m_sd.open(path.toString(), FILE_APPEND);
			#elif defined(ARDUINO_TTGO_T7_V14_Mini32)
			File myFile = m_sd.open(path.toString(), FILE_APPEND);
			#elif defined(ARDUINO_SAMD_ZERO)
			File myFile = m_sd.open(path.toString(), FILE_WRITE);
			#endif
			myFile.print(text.toString());
			myFile.close();
			return true;
		}
		
		virtual bool writeText(Note text, Note p){
			Note path = fixPath(p);
			DefaultMonkeyFile(ame_Log_Statement, "writeText",  "println", path);
			DefaultMonkeyFile(ame_Log_Statement, "writeText",  "println", text);
			if(!m_sd.exists(path.toString())){
				DefaultMonkeyFile(ame_Log_Statement, "writeText",  "println", "path doesnt exists");
				return false;
			}
			#if defined(ARDUINO_ARCH_AVR)
			File myFile = m_sd.open(path.toString(), FILE_WRITE);
			#elif defined(ARDUINO_ESP32_DEV)
			File myFile = m_sd.open(path.toString(), FILE_APPEND);
			#elif defined(ARDUINO_TTGO_T7_V14_Mini32)
			File myFile = m_sd.open(path.toString(), FILE_APPEND);
			#elif defined(ARDUINO_SAMD_ZERO)
			File myFile = m_sd.open(path.toString(), FILE_WRITE);
			#endif
			myFile.print(text.toString());
			myFile.close();
			return true;
		}
		virtual bool writeRootText(Note text, Note path){
			Note rpath = this->fixRootPath(path);
			DefaultMonkeyFile(ame_Log_Statement, "writeRootText",  "println", rpath);
			DefaultMonkeyFile(ame_Log_Statement, "writeRootText",  "println", text);
			if(!m_sd.exists(rpath.toString())){
				DefaultMonkeyFile(ame_Log_Statement, "writeRootText",  "println", "path doesnt exists");
				return false;
			}
			#if defined(ARDUINO_ARCH_AVR)
			File myFile = m_sd.open(rpath.toString(), FILE_WRITE);
			#elif defined(ARDUINO_ESP32_DEV)
			File myFile = m_sd.open(rpath.toString(), FILE_APPEND);
			#elif defined(ARDUINO_TTGO_T7_V14_Mini32)
			File myFile = m_sd.open(rpath.toString(), FILE_APPEND);
			#elif defined(ARDUINO_SAMD_ZERO)
			File myFile = m_sd.open(rpath.toString(), FILE_WRITE);
			#endif
			myFile.print(text.toString());
			myFile.close();
			return true;
		}
		
		virtual Note fastReadText(Note p){
			Note path = fixPath(p);
			DefaultMonkeyFile(ame_Log_Statement, "readText",  "println", path);
			File myFile = m_sd.open(path.toString());
			Note r = "";
			while(myFile.available()){
				char c = (char)myFile.read();
				DefaultMonkeyFile(ame_Log_Statement, "readText",  "println", Note(c));
				r.concat(c);
			}
			myFile.close();
			return r;
		}
		
		virtual Note readText(Note p){
			Note path = fixPath(p);
			DefaultMonkeyFile(ame_Log_Statement, "readText",  "println", path);
			if(!m_sd.exists(path.toString())){
				DefaultMonkeyFile(ame_Log_Statement, "readText",  "println", "file doesnt exists");
				return "";
			}
			File myFile = m_sd.open(path.toString());
			Note r = "";
			while(myFile.available()){
				char c = (char)myFile.read();
				DefaultMonkeyFile(ame_Log_Statement, "readText",  "println", Note(c));
				r.concat(c);
			}
			myFile.close();
			return r;
		}
		virtual Note readRootText(Note path){
			Note rpath = this->fixRootPath(path);
			DefaultMonkeyFile(ame_Log_Statement, "readRootText",  "println", rpath);
			if(!m_sd.exists(rpath.toString())){
				DefaultMonkeyFile(ame_Log_Statement, "readRootText",  "println", "path doesnt exists");
				return "";
			}
			File myFile = m_sd.open(rpath.toString());
			Note r = "";
			while (myFile.available()) {
				char c = (char)myFile.read();
				DefaultMonkeyFile(ame_Log_Statement, "readRootText",  "println", Note(c));
				r.concat(c);
			}
			myFile.close();
			return r;
		}
		
		virtual bool writeByteArray(ByteArray array, Note p){
			Note path = fixPath(p);
			DefaultMonkeyFile(ame_Log_Statement, "writeByteArray",  "println", path);
			DefaultMonkeyFile(ame_Log_Statement, "writeByteArray",  "println", array.toNote());
			if(!m_sd.exists(path.toString())){
				DefaultMonkeyFile(ame_Log_Statement, "writeByteArray",  "println", "path doesnt exists");
				return false;
			}
			#if defined(ARDUINO_ARCH_AVR)
			File myFile = m_sd.open(path.toString(), FILE_WRITE);
			#elif defined(ARDUINO_ESP32_DEV)
			File myFile = m_sd.open(path.toString(), FILE_APPEND);
			#elif defined(ARDUINO_TTGO_T7_V14_Mini32)
			File myFile = m_sd.open(path.toString(), FILE_APPEND);
			#elif defined(ARDUINO_SAMD_ZERO)
			File myFile = m_sd.open(path.toString(), FILE_WRITE);
			#endif
			myFile.print(array.toNote().toString());
			myFile.close();
			return true;
		}
		virtual bool writeRootByteArray(ByteArray array, Note path){
			Note rpath = this->fixRootPath(path);
			DefaultMonkeyFile(ame_Log_Statement, "writeRootByteArray",  "println", rpath);
			DefaultMonkeyFile(ame_Log_Statement, "writeRootByteArray",  "println", array.toNote());
			if(!m_sd.exists(rpath.toString())){
				DefaultMonkeyFile(ame_Log_Statement, "writeRootByteArray",  "println", "path doesnt exists");
				return false;
			}
			#if defined(ARDUINO_ARCH_AVR)
			File myFile = m_sd.open(rpath.toString(), FILE_WRITE);
			#elif defined(ARDUINO_ESP32_DEV)
			File myFile = m_sd.open(rpath.toString(), FILE_APPEND);
			#elif defined(ARDUINO_TTGO_T7_V14_Mini32)
			File myFile = m_sd.open(rpath.toString(), FILE_APPEND);
			#elif defined(ARDUINO_SAMD_ZERO)
			File myFile = m_sd.open(rpath.toString(), FILE_WRITE);
			#endif
			myFile.print(array.toNote().toString());
			myFile.close();
			return true;
		}
		
		virtual ByteArray readByteArray(Note p){
			Note path = fixPath(p);
			DefaultMonkeyFile(ame_Log_Statement, "readByteArray",  "println", path);
			if(!m_sd.exists(path.toString())){
				DefaultMonkeyFile(ame_Log_Statement, "readByteArray",  "println", "file doesnt exists");
				return ByteArray();
			}
			File myFile = m_sd.open(path.toString());
			Note sr = "";
			while(myFile.available()){
				char c = (char)myFile.read();
				DefaultMonkeyFile(ame_Log_Statement, "readByteArray",  "println", Note(c));
				sr.concat(c);
			}
			myFile.close();
			ByteArray array = sr;
			return array;
		}
		
		virtual ByteArray readRootByteArray(Note path){
			Note rpath = this->fixRootPath(path);
			DefaultMonkeyFile(ame_Log_Statement, "readRootByteArray",  "println", rpath);
			if(!m_sd.exists(rpath.toString())){
				DefaultMonkeyFile(ame_Log_Statement, "readRootByteArray",  "println", "path doesnt exists");
				return ByteArray();
			}
			File myFile = m_sd.open(rpath.toString());
			Note s;
			while (myFile.available()) {
				char c = (char)myFile.read();
				DefaultMonkeyFile(ame_Log_Statement, "readRootByteArray",  "println", Note(c));
				s.concat(c);
			}
			myFile.close();
			ByteArray array = s;
			return array;
		}
		
		virtual bool exist(Note p){
			Note path = fixPath(p);
			DefaultMonkeyFile(ame_Log_Statement, "exist",  "println", "");
			DefaultMonkeyFile(ame_Log_Statement, "path ",  "println", path);
			DefaultMonkeyFile(ame_Log_Statement, "does exist? ",  "println", m_sd.exists(path.toString()));
			return m_sd.exists(path.toString());
		}
		virtual bool existRoot(Note path){
			Note rpath = this->fixRootPath(path);
			DefaultMonkeyFile(ame_Log_Statement, "existRoot",  "println", "");
			DefaultMonkeyFile(ame_Log_Statement, "path ",  "println", rpath);
			DefaultMonkeyFile(ame_Log_Statement, "does exist? ",  "println", m_sd.exists(rpath.toString()));
			return m_sd.exists(rpath.toString());
		}
		
		virtual bool isOpen(){
			return init;
		}
		
		virtual int getFileSize(Note path){
			DefaultMonkeyFile(ame_Log_Statement, "getDirectoriesSize",  "println", Note("path: ") + path);

			File root = m_sd.open(path.toString());
			if(!root){
				DefaultMonkeyFile(ame_Log_Statement, "getDirectoriesSize",  "println", "Failed to open directory");
				return 0;
			}
			if(!root.isDirectory()){
				DefaultMonkeyFile(ame_Log_Statement, "getDirectoriesSize",  "println", "Not a directory");
				return 0;
			}
			int x = 0;
			File file = root.openNextFile();
			while(file){
				if(!file.isDirectory()){
					x++;
				}
				file = root.openNextFile();
			}
			return x;
		}
		
		virtual int getDirectoriesSize(Note path){
			DefaultMonkeyFile(ame_Log_Statement, "getDirectoriesSize",  "println", Note("path: ") + path);

			File root = m_sd.open(path.toString());
			if(!root){
				DefaultMonkeyFile(ame_Log_Statement, "getDirectoriesSize",  "println", "Failed to open directory");
				return 0;
			}
			if(!root.isDirectory()){
				DefaultMonkeyFile(ame_Log_Statement, "getDirectoriesSize",  "println", "Not a directory");
				return 0;
			}
			int x = 0;
			File file = root.openNextFile();
			while(file){
				if(file.isDirectory()){
					x++;
				}
				file = root.openNextFile();
			}
			return x;
		}
		
		virtual PrimitiveMap<Note,Note> getDirectories(Note dirname, int levels){
			DefaultMonkeyFile(ame_Log_Statement, "getDirectories",  "println", Note("Listing directory: ") + dirname);

			PrimitiveMap<Note,Note> m_map;
			File root = m_sd.open(dirname.toString());
			if(!root){
				DefaultMonkeyFile(ame_Log_Statement, "getDirectories",  "println", "Failed to open directory");
				return m_map;
			}
			if(!root.isDirectory()){
				DefaultMonkeyFile(ame_Log_Statement, "getDirectories",  "println", "Not a directory");
				return m_map;
			}
			File file = root.openNextFile();
			while(file){
				if(file.isDirectory()){
					m_map.add("Dir", file.name());
					if(levels){
						m_map.add(getDirectories(file.name(), levels -1));
					}
				} else {
					m_map.add("File", file.name());
				}
				file = root.openNextFile();
			}
			return m_map;
		}
		
		
	protected:
		T& m_sd;
};

}

template<class T>
bool ame::DefaultMonkeyFile<T>::init = false;

#endif