
/**
 *
 * @author PankeyCR - Manuel Sanchez Badilla
 *
 */
 
#ifndef DefaultMonkeyFile_hpp
#define DefaultMonkeyFile_hpp

#include "Arduino.h"

#if defined(ARDUINO_ESP32_DEV)
#include "FS.h"
#endif
#include "SD.h"
#include "SPI.h"
#include "MonkeyFile.hpp"
#include "PrimitiveMap.hpp"

namespace ame{

template<class T>
class DefaultMonkeyFile : public MonkeyFile{
    public:
		static bool init;
		DefaultMonkeyFile(const DefaultMonkeyFile& file) : m_sd(file.m_sd){
			
		}
		DefaultMonkeyFile(T &t) : m_sd(t){
			if(!init){
				init = true;
				#if defined(ARDUINO_ESP32_DEV)
				MonkeyFileLog("MonkeyFile", "createDir",  "println", "ARDUINO_ESP32_DEV");
				SPI.begin(14, 2, 15, 13);
				m_sd.begin(13);
				uint8_t cardType = m_sd.cardType();

				if(cardType == CARD_NONE){
					MonkeyFileLog("MonkeyFile", "createDir",  "println", "No SD card attached");
					return;
				}
				#elif defined(ARDUINO_TTGO_T7_V14_Mini32)
				MonkeyFileLog("MonkeyFile", "createDir",  "println", "ARDUINO_TTGO_T7_V14_Mini32");
				SPI.begin(21, 22, 19, 0);//sclk , miso , mosi , cs
				m_sd.begin(0);
				uint8_t cardType = m_sd.cardType();

				if(cardType == CARD_NONE){
					MonkeyFileLog("MonkeyFile", "createDir",  "println", "No SD card attached");
					return;
				}
				#elif defined(ARDUINO_ARCH_AVR)
				MonkeyFileLog("MonkeyFile", "createDir",  "println", "ARDUINO_ARCH_AVR");
				m_sd.begin(4);
				#elif defined(ARDUINO_SAMD_ZERO)
				MonkeyFileLog("MonkeyFile", "createDir",  "println", "ARDUINO_SAMD_ZERO");
				m_sd.begin(4);
				#endif
				this->m_open = true;
			}
		}
		virtual ~DefaultMonkeyFile(){}
		
		virtual bool createDir(String p){
			String path = fixPath(p);
			MonkeyFileLog("MonkeyFile", "createDir",  "println", String(path));
			if(m_sd.exists(path)){
				MonkeyFileLog("MonkeyFile", "createDir",  "println", "all ready exists");
				return false;
			}
			if(m_sd.mkdir(path)){
				MonkeyFileLog("MonkeyFile", "createDir",  "println", "Dir created");
				return true;
			}else{
				MonkeyFileLog("MonkeyFile", "createDir",  "println", "mkdir failed");
			}
			return false;
		}
		
		virtual bool createRootDir(String path){
			String rpath = this->fixRootPath(path);
			if(!m_sd.exists(this->rootPath)){
				m_sd.mkdir(this->rootPath);
				MonkeyFileLog("MonkeyFile", "createRootDir",  "println", "creates rootdir");
			}
			if(m_sd.exists(rpath)){
				MonkeyFileLog("MonkeyFile", "createRootDir",  "println", "all ready exists");
				return false;
			}
			MonkeyFileLog("MonkeyFile", "createRootDir",  "println", this->rootPath+"/"+path);
			if(m_sd.mkdir(rpath)){
				MonkeyFileLog("MonkeyFile", "createRootDir",  "println", "Dir created");
			}else{
				MonkeyFileLog("MonkeyFile", "createRootDir",  "println", "mkdir failed");
			}
			return true;
		}
		
		virtual bool deleteDir(String p){
			String path = fixPath(p);
			MonkeyFileLog("MonkeyFile", "deleteDir",  "println", String(path));
			if(!m_sd.exists(path)){
				MonkeyFileLog("MonkeyFile", "deleteDir",  "println", "doesnt exists");
				return false;
			}
			if(m_sd.rmdir(path)){
				MonkeyFileLog("MonkeyFile", "deleteDir",  "println", "Dir deleted");
				return true;
			}else{
				MonkeyFileLog("MonkeyFile", "deleteDir",  "println", "rmdir failed");
			}
			return false;
		}
		
		virtual bool deleteRootDir(String path){
			String rpath = this->fixRootPath(path);
			MonkeyFileLog("MonkeyFile", "deleteRootDir",  "println", rpath);
			if(!m_sd.exists(rpath)){
				MonkeyFileLog("MonkeyFile", "deleteRootDir",  "println", "doesnt exists");
				return false;
			}
			if(m_sd.rmdir(rpath)){
				MonkeyFileLog("MonkeyFile", "deleteRootDir",  "println", "Dir deleted");
			}else{
				MonkeyFileLog("MonkeyFile", "deleteRootDir",  "println", "rmdir failed");
			}
			return true;
		}
		
		virtual bool createFile(String p){
			String path = fixPath(p);
			MonkeyFileLog("MonkeyFile", "createFile",  "println", path);
			File myFile = m_sd.open(path, FILE_WRITE);
			myFile.close();
			return true;
		}
		virtual bool createRootFile(String path){
			String rpath = this->fixRootPath(path);
			MonkeyFileLog("MonkeyFile", "createRootFile",  "println", rpath);
			File myFile = m_sd.open(rpath, FILE_WRITE);
			myFile.close();
			return true;
		}
		
		virtual bool deleteFile(String p){
			String path = fixPath(p);
			MonkeyFileLog("MonkeyFile", "deleteFile",  "println", path);
			return m_sd.remove(path);
		}
		virtual bool deleteRootFile(String path){
			String rpath = this->fixRootPath(path);
			MonkeyFileLog("MonkeyFile", "deleteRootFile",  "println", rpath);
			if(!m_sd.exists(rpath)){
				MonkeyFileLog("MonkeyFile", "deleteRootDir",  "println", "doesnt exists");
				return false;
			}
			return m_sd.remove(rpath);
		}
		
		virtual bool clearFile(String p){
			String path = fixPath(p);
			if(!m_sd.exists(path)){
				MonkeyFileLog("MonkeyFile", "clearFile",  "println", "doesnt exists");
				return false;
			}
			m_sd.remove(path);
			File myFile = m_sd.open(path, FILE_WRITE);
			myFile.close();
			return true;
		}
		
		virtual bool clearRootFile(String p){
			String path = fixRootPath(p);
			if(!m_sd.exists(path)){
				MonkeyFileLog("MonkeyFile", "clearFile",  "println", "doesnt exists");
				return false;
			}
			m_sd.remove(path);
			File myFile = m_sd.open(path, FILE_WRITE);
			myFile.close();
			return true;
		}
		
		virtual bool writeText(String text, String p){
			String path = fixPath(p);
			MonkeyFileLog("MonkeyFile", "writeText",  "println", path);
			MonkeyFileLog("MonkeyFile", "writeText",  "println", text);
			if(!m_sd.exists(path)){
				MonkeyFileLog("MonkeyFile", "writeText",  "println", "path doesnt exists");
				return false;
			}
			#if defined(ARDUINO_ARCH_AVR)
			File myFile = m_sd.open(path, FILE_WRITE);
			#elif defined(ARDUINO_ESP32_DEV)
			File myFile = m_sd.open(path, FILE_APPEND);
			#elif defined(ARDUINO_TTGO_T7_V14_Mini32)
			File myFile = m_sd.open(path, FILE_APPEND);
			#elif defined(ARDUINO_SAMD_ZERO)
			File myFile = m_sd.open(path, FILE_WRITE);
			#endif
			myFile.print(text);
			myFile.close();
			return true;
		}
		virtual bool writeRootText(String text, String path){
			String rpath = this->fixRootPath(path);
			MonkeyFileLog("MonkeyFile", "writeRootText",  "println", rpath);
			MonkeyFileLog("MonkeyFile", "writeRootText",  "println", text);
			if(!m_sd.exists(rpath)){
				MonkeyFileLog("MonkeyFile", "writeRootText",  "println", "path doesnt exists");
				return false;
			}
			#if defined(ARDUINO_ARCH_AVR)
			File myFile = m_sd.open(rpath, FILE_WRITE);
			#elif defined(ARDUINO_ESP32_DEV)
			File myFile = m_sd.open(rpath, FILE_APPEND);
			#elif defined(ARDUINO_TTGO_T7_V14_Mini32)
			File myFile = m_sd.open(rpath, FILE_APPEND);
			#elif defined(ARDUINO_SAMD_ZERO)
			File myFile = m_sd.open(rpath, FILE_WRITE);
			#endif
			myFile.print(text);
			myFile.close();
			return true;
		}
		
		virtual String readText(String p){
			String path = fixPath(p);
			MonkeyFileLog("MonkeyFile", "readText",  "println", path);
			if(!m_sd.exists(path)){
				MonkeyFileLog("MonkeyFile", "readText",  "println", "file doesnt exists");
				return "";
			}
			File myFile = m_sd.open(path);
			String r = "";
			while(myFile.available()){
				char c = (char)myFile.read();
				MonkeyFileLog("MonkeyFile", "readText",  "println", String(c));
				r.concat(c);
			}
			myFile.close();
			return r;
		}
		virtual String readRootText(String path){
			String rpath = this->fixRootPath(path);
			MonkeyFileLog("MonkeyFile", "readRootText",  "println", rpath);
			if(!m_sd.exists(rpath)){
				MonkeyFileLog("MonkeyFile", "readRootText",  "println", "path doesnt exists");
				return "";
			}
			File myFile = m_sd.open(rpath);
			String r = "";
			while (myFile.available()) {
				char c = (char)myFile.read();
				MonkeyFileLog("MonkeyFile", "readRootText",  "println", String(c));
				r.concat(c);
			}
			myFile.close();
			return r;
		}
		
		virtual bool writeByteArray(ByteArray array, String p){
			String path = fixPath(p);
			MonkeyFileLog("MonkeyFile", "writeByteArray",  "println", path);
			MonkeyFileLog("MonkeyFile", "writeByteArray",  "println", array.toString());
			if(!m_sd.exists(path)){
				MonkeyFileLog("MonkeyFile", "writeByteArray",  "println", "path doesnt exists");
				return false;
			}
			#if defined(ARDUINO_ARCH_AVR)
			File myFile = m_sd.open(path, FILE_WRITE);
			#elif defined(ARDUINO_ESP32_DEV)
			File myFile = m_sd.open(path, FILE_APPEND);
			#elif defined(ARDUINO_TTGO_T7_V14_Mini32)
			File myFile = m_sd.open(path, FILE_APPEND);
			#elif defined(ARDUINO_SAMD_ZERO)
			File myFile = m_sd.open(path, FILE_WRITE);
			#endif
			myFile.print(array.toString());
			myFile.close();
			return true;
		}
		virtual bool writeRootByteArray(ByteArray array, String path){
			String rpath = this->fixRootPath(path);
			MonkeyFileLog("MonkeyFile", "writeRootByteArray",  "println", rpath);
			MonkeyFileLog("MonkeyFile", "writeRootByteArray",  "println", array.toString());
			if(!m_sd.exists(rpath)){
				MonkeyFileLog("MonkeyFile", "writeRootByteArray",  "println", "path doesnt exists");
				return false;
			}
			#if defined(ARDUINO_ARCH_AVR)
			File myFile = m_sd.open(rpath, FILE_WRITE);
			#elif defined(ARDUINO_ESP32_DEV)
			File myFile = m_sd.open(rpath, FILE_APPEND);
			#elif defined(ARDUINO_TTGO_T7_V14_Mini32)
			File myFile = m_sd.open(rpath, FILE_APPEND);
			#elif defined(ARDUINO_SAMD_ZERO)
			File myFile = m_sd.open(rpath, FILE_WRITE);
			#endif
			myFile.print(array.toString());
			myFile.close();
			return true;
		}
		
		virtual ByteArray readByteArray(String p){
			String path = fixPath(p);
			MonkeyFileLog("MonkeyFile", "readByteArray",  "println", path);
			if(!m_sd.exists(path)){
				MonkeyFileLog("MonkeyFile", "readByteArray",  "println", "file doesnt exists");
				return ByteArray();
			}
			File myFile = m_sd.open(path);
			String sr = "";
			while(myFile.available()){
				char c = (char)myFile.read();
				MonkeyFileLog("MonkeyFile", "readByteArray",  "println", String(c));
				sr.concat(c);
			}
			myFile.close();
			ByteArray array = sr;
			return array;
		}
		
		virtual ByteArray readRootByteArray(String path){
			String rpath = this->fixRootPath(path);
			MonkeyFileLog("MonkeyFile", "readRootByteArray",  "println", rpath);
			if(!m_sd.exists(rpath)){
				MonkeyFileLog("MonkeyFile", "readRootByteArray",  "println", "path doesnt exists");
				return ByteArray();
			}
			File myFile = m_sd.open(rpath);
			String s;
			while (myFile.available()) {
				char c = (char)myFile.read();
				MonkeyFileLog("MonkeyFile", "readRootByteArray",  "println", String(c));
				s.concat(c);
			}
			myFile.close();
			ByteArray array = s;
			return array;
		}
		
		virtual bool exist(String p){
			String path = fixPath(p);
			MonkeyFileLog("MonkeyFile", "exist",  "println", path);
			return m_sd.exists(path);
		}
		virtual bool existRoot(String path){
			String rpath = this->fixRootPath(path);
			MonkeyFileLog("MonkeyFile", "existRoot",  "println", rpath);
			return m_sd.exists(rpath);
		}
		
		virtual bool isOpen(){
			return init;
		}
		
		virtual PrimitiveMap<String,String> getDirectories(String dirname, int levels){
			MonkeyFileLog("MonkeyFile", "fixRootPath",  "println", String("Listing directory: ") + dirname);

			PrimitiveMap<String,String> m_map;
			File root = m_sd.open(dirname);
			if(!root){
				MonkeyFileLog("MonkeyFile", "fixRootPath",  "println", "Failed to open directory");
				return m_map;
			}
			if(!root.isDirectory()){
				MonkeyFileLog("MonkeyFile", "fixRootPath",  "println", "Not a directory");
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
