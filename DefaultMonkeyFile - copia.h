
/**
 *
 * @author PankeyCR - Manuel Sanchez Badilla
 *
 */
 
#ifndef DefaultMonkeyFile_h
#define DefaultMonkeyFile_h

#include "Arduino.h"

#if defined(ARDUINO_ESP32_DEV)
#include "FS.h"
#endif
#include "SD.h"
#include "SPI.h"
#include "MonkeyFile.h"
#include "MonkeyExporter.h"
#include "MonkeyImporter.h"
#include "CommandReader.h"
#include "LinkedList.h"
#include "PrimitiveList.h"
#include "PrimitiveMap.h"

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
		
    	virtual bool write(ElementId id, const int& value, String path){
			MonkeyFileLog("MonkeyFile", "write int",  "println", String(value));
			CommandReader cmd;
			cmd.setText(readText(path));
			int line = cmd.getCommandOrder(id.getId());
			cmd.removeLine(line);
			clearFile(path);
			writeText(cmd.getText(), path);
			return this->writeText(id.getId() + String(" ") + String(value) + "\n", path);
		}
		
    	virtual int read(ElementId id, int value, String path){
			MonkeyFileLog("MonkeyFile", "read int",  "println", String(value));
			CommandReader cmd;
			cmd.setText(readText(path));
			int x_1 = cmd.getCommandOrder(id.getId());
			if(x_1 == -1){
				return value;
			}
			return cmd.getArgument(x_1).toInt();
		}
		
    	virtual bool write(ElementId id, const float& value, String path){
			MonkeyFileLog("MonkeyFile", "write float",  "println", String(value));
			CommandReader cmd;
			cmd.setText(readText(path));
			int line = cmd.getCommandOrder(id.getId());
			cmd.removeLine(line);
			clearFile(path);
			writeText(cmd.getText(), path);
			return this->writeText(id.getId() + String(" ") + String(value) + "\n", path);
		}
		
    	virtual float read(ElementId id, float value, String path){
			MonkeyFileLog("MonkeyFile", "read float",  "println", String(value));
			CommandReader cmd;
			cmd.setText(readText(path));
			int x_1 = cmd.getCommandOrder(id.getId());
			if(x_1 == -1){
				return value;
			}
			return cmd.getArgument(x_1).toFloat();
		}
		
    	virtual bool write(ElementId id, const String& value, String path){
			MonkeyFileLog("MonkeyFile", "write String",  "println", value);
			CommandReader cmd;
			cmd.setText(readText(path));
			int line = cmd.getCommandOrder(id.getId());
			cmd.removeLine(line);
			clearFile(path);
			writeText(cmd.getText(), path);
			return this->writeText(id.getId() + String(" ") + value + "\n", path);
		}
		
    	virtual String read(ElementId id, String value, String path){
			MonkeyFileLog("MonkeyFile", "read String",  "println", value);
			CommandReader cmd;
			cmd.setText(readText(path));
			int x_1 = cmd.getCommandOrder(id.getId());
			if(x_1 == -1){
				return value;
			}
			return cmd.getArgument(x_1);
		}
		
    	virtual bool write(ElementId id, const char* value, String path){
			MonkeyFileLog("MonkeyFile", "write String",  "println", String(value));
			CommandReader cmd;
			cmd.setText(readText(path));
			int line = cmd.getCommandOrder(id.getId());
			cmd.removeLine(line);
			clearFile(path);
			writeText(cmd.getText(), path);
			return this->writeText(id.getId() + String(" ") + String(value) + "\n", path);
		}
		
    	virtual String read(ElementId id, char* value, String path){
			MonkeyFileLog("MonkeyFile", "read char*",  "println", String(value));
			CommandReader cmd;
			cmd.setText(readText(path));
			int x_1 = cmd.getCommandOrder(id.getId());
			if(x_1 == -1){
				return String(value);
			}
			return cmd.getArgument(x_1);
		}
		
		virtual bool write(ElementId id, const long& value, String path){
			MonkeyFileLog("MonkeyFile", "write String",  "println", String(value));
			CommandReader cmd;
			cmd.setText(readText(path));
			int line = cmd.getCommandOrder(id.getId());
			cmd.removeLine(line);
			clearFile(path);
			writeText(cmd.getText(), path);
			return this->writeText(id.getId() + String(" ") + String(value) + "\n", path);
		}
		
		virtual long read(ElementId id, long value, String path){
			MonkeyFileLog("MonkeyFile", "read long",  "println", String(value));
			CommandReader cmd;
			cmd.setText(readText(path));
			int x_1 = cmd.getCommandOrder(id.getId());
			if(x_1 == -1){
				return value;
			}
			return cmd.getArgument(x_1).toInt();
		}
		
		virtual bool write(ElementId id, const char& value, String path){
			MonkeyFileLog("MonkeyFile", "write String",  "println", String(value));
			CommandReader cmd;
			cmd.setText(readText(path));
			int line = cmd.getCommandOrder(id.getId());
			cmd.removeLine(line);
			clearFile(path);
			writeText(cmd.getText(), path);
			return this->writeText(id.getId() + String(" ") + String(value) + "\n", path);
		}
		
		virtual char read(ElementId id, char value, String path){
			MonkeyFileLog("MonkeyFile", "read char",  "println", String(value));
			CommandReader cmd;
			cmd.setText(readText(path));
			int x_1 = cmd.getCommandOrder(id.getId());
			if(x_1 == -1){
				return value;
			}
			String r = cmd.getArgument(x_1);
			if(r.length() == 0){
				return value;
			}
			return r.charAt(0);
		}
		
		virtual bool write(ElementId id, const ByteArray& value, String path){
			MonkeyFileLog("MonkeyFile", "write String",  "println", value.toString());
			CommandReader cmd;
			cmd.setText(readText(path));
			int line = cmd.getCommandOrder(id.getId());
			cmd.removeLine(line);
			clearFile(path);
			writeText(cmd.getText(), path);
			return this->writeText(id.getId() + String(" ") + value.toString() + "\n", path);
		}
		
		virtual ByteArray read(ElementId id, ByteArray value, String path){
			MonkeyFileLog("MonkeyFile", "read ByteArray",  "println", value.toString());
			CommandReader cmd;
			cmd.setText(readText(path));
			int x_1 = cmd.getCommandOrder(id.getId());
			if(x_1 == -1){
				return value;
			}
			return ByteArray(cmd.getArgument(x_1));
		}
		
		virtual bool write(ElementId id, const bool& value, String path){
			MonkeyFileLog("MonkeyFile", "write bool",  "println", String(value));
			CommandReader cmd;
			cmd.setText(readText(path));
			int line = cmd.getCommandOrder(id.getId());
			cmd.removeLine(line);
			clearFile(path);
			writeText(cmd.getText(), path);
			return this->writeText(id.getId() + String(" ") + String(value) + "\n", path);
		}
		
		virtual bool read(ElementId id, bool value, String path){
			MonkeyFileLog("MonkeyFile", "read bool",  "println", String(value));
			CommandReader cmd;
			cmd.setText(readText(path));
			int x_1 = cmd.getCommandOrder(id.getId());
			if(x_1 == -1){
				return value;
			}
			return cmd.getArgument(x_1) == "1";
		}
		
    	virtual bool write(ElementId id, const LinkedList<int>& value, String path){
			MonkeyFileLog("MonkeyFile", "write LinkedList int",  "println", "");
			if(value.getPosition() == 0){
				return false;
			}
			CommandReader cmd;
			cmd.setText(readText(path));
			int line = cmd.getCommandOrder(id.getId());
			cmd.removeLine(line);
			clearFile(path);
			writeText(cmd.getText(), path);
			bool rt = this->writeText(id.getId() + String(" "), path);
			if(!rt){
				return false;
			}
			for(int x = 0; x < value.getPosition(); x++){
				int v = *value.getByPosition(x);
				if(x == value.getPosition() - 1){
					rt = this->writeText(String(v) + String("\n"), path);
				}else{
					rt = this->writeText(String(v) + String(","), path);
				}
				if(!rt){
					return false;
				}
			}
			return true;
		}
		
    	virtual LinkedList<int> read(ElementId id, LinkedList<int> value, String path){
			MonkeyFileLog("MonkeyFile", "read LinkedList int",  "println", "");
			CommandReader cmd;
			cmd.setText(readText(path));
			int x_1 = cmd.getCommandOrder(id.getId());
			if(x_1 == -1){
				return value;
			}
			String arg = cmd.getArgument(x_1);
			LinkedList<int> list;
			int s = cmd.getSizeNoStartNoEnd(arg, ',');
			for(int x = 0; x < s; x++){
				int t = cmd.split(arg, x, ',').toInt();
				list.addLValue(t);
			}
			return list;
		}
		
    	virtual bool write(ElementId id, const PrimitiveList<int>& value, String path){
			MonkeyFileLog("MonkeyFile", "write PrimitiveList int",  "println", "");
			if(value.getPosition() == 0){
				return false;
			}
			CommandReader cmd;
			cmd.setText(readText(path));
			int line = cmd.getCommandOrder(id.getId());
			cmd.removeLine(line);
			clearFile(path);
			writeText(cmd.getText(), path);
			bool rt = this->writeText(id.getId() + String(" "), path);
			if(!rt){
				return false;
			}
			for(int x = 0; x < value.getPosition(); x++){
				int v = *value.getByPosition(x);
				if(x == value.getPosition() - 1){
					rt = this->writeText(String(v) + String("\n"), path);
				}else{
					rt = this->writeText(String(v) + String(","), path);
				}
				if(!rt){
					return false;
				}
			}
			return true;
		}
		
    	virtual PrimitiveList<int> read(ElementId id, PrimitiveList<int> value, String path){
			MonkeyFileLog("MonkeyFile", "read PrimitiveList int",  "println", "");
			CommandReader cmd;
			cmd.setText(readText(path));
			int x_1 = cmd.getCommandOrder(id.getId());
			if(x_1 == -1){
				return value;
			}
			String arg = cmd.getArgument(x_1);
			PrimitiveList<int> list;
			int s = cmd.getSizeNoStartNoEnd(arg, ',');
			for(int x = 0; x < s; x++){
				int t = cmd.split(arg, x, ',').toInt();
				list.addLValue(t);
			}
			return list;
		}
		
    	virtual bool write(ElementId id, const LinkedList<ByteArray>& value, String path){
			MonkeyFileLog("MonkeyFile", "write LinkedList ByteArray",  "println", "");
			if(value.getPosition() == 0){
				return false;
			}
			CommandReader cmd;
			cmd.setText(readText(path));
			int line = cmd.getCommandOrder(id.getId());
			cmd.removeLine(line);
			clearFile(path);
			writeText(cmd.getText(), path);
			bool rt = this->writeText(id.getId() + String(" "), path);
			if(!rt){
				return false;
			}
			for(int x = 0; x < value.getPosition(); x++){
				ByteArray v = *value.getByPosition(x);
				if(x == value.getPosition() - 1){
					rt = this->writeText(v.toString() + String("\n"), path);
				}else{
					rt = this->writeText(v.toString() + String(","), path);
				}
				if(!rt){
					return false;
				}
			}
			return true;
		}
		
    	virtual LinkedList<ByteArray> read(ElementId id, LinkedList<ByteArray> value, String path){
			MonkeyFileLog("MonkeyFile", "read LinkedList ByteArray",  "println", "");
			CommandReader cmd;
			cmd.setText(readText(path));
			int x_1 = cmd.getCommandOrder(id.getId());
			if(x_1 == -1){
				return value;
			}
			String arg = cmd.getArgument(x_1);
			LinkedList<ByteArray> list;
			int s = cmd.getSizeNoStartNoEnd(arg, ',');
			for(int x = 0; x < s; x++){
				ByteArray t = cmd.split(arg, x, ',');
				list.addLValue(t);
			}
			return list;
		}
		
    	virtual bool write(ElementId id, const PrimitiveList<ByteArray>& value, String path){
			MonkeyFileLog("MonkeyFile", "write PrimitiveList ByteArray",  "println", "");
			if(value.getPosition() == 0){
				return false;
			}
			CommandReader cmd;
			cmd.setText(readText(path));
			int line = cmd.getCommandOrder(id.getId());
			cmd.removeLine(line);
			clearFile(path);
			writeText(cmd.getText(), path);
			bool rt = this->writeText(id.getId() + String(" "), path);
			if(!rt){
				return false;
			}
			for(int x = 0; x < value.getPosition(); x++){
				ByteArray v = *value.getByPosition(x);
				if(x == value.getPosition() - 1){
					rt = this->writeText(v.toString() + String("\n"), path);
				}else{
					rt = this->writeText(v.toString() + String(","), path);
				}
				if(!rt){
					return false;
				}
			}
			return true;
		}
		
    	virtual PrimitiveList<ByteArray> read(ElementId id, PrimitiveList<ByteArray> value, String path){
			MonkeyFileLog("MonkeyFile", "read PrimitiveList ByteArray",  "println", "");
			CommandReader cmd;
			cmd.setText(readText(path));
			int x_1 = cmd.getCommandOrder(id.getId());
			if(x_1 == -1){
				return value;
			}
			String arg = cmd.getArgument(x_1);
			PrimitiveList<ByteArray> list;
			int s = cmd.getSizeNoStartNoEnd(arg, ',');
			for(int x = 0; x < s; x++){
				ByteArray t = cmd.split(arg, x, ',');
				list.addLValue(t);
			}
			return list;
		}
    	virtual bool write(ElementId id, const LinkedList<bool>& value, String path){
			MonkeyFileLog("MonkeyFile", "write LinkedList bool",  "println", "");
			if(value.getPosition() == 0){
				return false;
			}
			CommandReader cmd;
			cmd.setText(readText(path));
			int line = cmd.getCommandOrder(id.getId());
			cmd.removeLine(line);
			clearFile(path);
			writeText(cmd.getText(), path);
			bool rt = this->writeText(id.getId() + String(" "), path);
			if(!rt){
				return false;
			}
			for(int x = 0; x < value.getPosition(); x++){
				bool v = *value.getByPosition(x);
				if(x == value.getPosition() - 1){
					rt = this->writeText(String(v) + String("\n"), path);
				}else{
					rt = this->writeText(String(v) + String(","), path);
				}
				if(!rt){
					return false;
				}
			}
			return true;
		}
		
    	virtual LinkedList<bool> read(ElementId id, LinkedList<bool> value, String path){
			MonkeyFileLog("MonkeyFile", "read LinkedList bool",  "println", "");
			CommandReader cmd;
			cmd.setText(readText(path));
			int x_1 = cmd.getCommandOrder(id.getId());
			if(x_1 == -1){
				return value;
			}
			String arg = cmd.getArgument(x_1);
			LinkedList<bool> list;
			int s = cmd.getSizeNoStartNoEnd(arg, ',');
			for(int x = 0; x < s; x++){
				bool t = cmd.split(arg, x, ',') == "1";
				list.addLValue(t);
			}
			return list;
		}
		
    	virtual bool write(ElementId id, const PrimitiveList<bool>& value, String path){
			MonkeyFileLog("MonkeyFile", "write PrimitiveList bool",  "println", "");
			if(value.getPosition() == 0){
				return false;
			}
			CommandReader cmd;
			cmd.setText(readText(path));
			int line = cmd.getCommandOrder(id.getId());
			cmd.removeLine(line);
			clearFile(path);
			writeText(cmd.getText(), path);
			bool rt = this->writeText(id.getId() + String(" "), path);
			if(!rt){
				return false;
			}
			for(int x = 0; x < value.getPosition(); x++){
				bool v = *value.getByPosition(x);
				if(x == value.getPosition() - 1){
					rt = this->writeText(String(v) + String("\n"), path);
				}else{
					rt = this->writeText(String(v) + String(","), path);
				}
				if(!rt){
					return false;
				}
			}
			return true;
		}
		
    	virtual PrimitiveList<bool> read(ElementId id, PrimitiveList<bool> value, String path){
			MonkeyFileLog("MonkeyFile", "read PrimitiveList bool",  "println", "");
			CommandReader cmd;
			cmd.setText(readText(path));
			int x_1 = cmd.getCommandOrder(id.getId());
			if(x_1 == -1){
				return value;
			}
			String arg = cmd.getArgument(x_1);
			PrimitiveList<bool> list;
			int s = cmd.getSizeNoStartNoEnd(arg, ',');
			for(int x = 0; x < s; x++){
				bool t = cmd.split(arg, x, ',') == "1";
				list.addLValue(t);
			}
			return list;
		}
		
    	virtual bool write(ElementId id, const LinkedList<char>& value, String path){
			MonkeyFileLog("MonkeyFile", "write LinkedList char",  "println", "");
			if(value.getPosition() == 0){
				return false;
			}
			CommandReader cmd;
			cmd.setText(readText(path));
			int line = cmd.getCommandOrder(id.getId());
			cmd.removeLine(line);
			clearFile(path);
			writeText(cmd.getText(), path);
			bool rt = this->writeText(id.getId() + String(" "), path);
			if(!rt){
				return false;
			}
			for(int x = 0; x < value.getPosition(); x++){
				char v = *value.getByPosition(x);
				if(x == value.getPosition() - 1){
					rt = this->writeText(String(v) + String("\n"), path);
				}else{
					rt = this->writeText(String(v) + String(","), path);
				}
				if(!rt){
					return false;
				}
			}
			return true;
		}
		
    	virtual LinkedList<char> read(ElementId id, LinkedList<char> value, String path){
			MonkeyFileLog("MonkeyFile", "read LinkedList char",  "println", "");
			CommandReader cmd;
			cmd.setText(readText(path));
			int x_1 = cmd.getCommandOrder(id.getId());
			if(x_1 == -1){
				return value;
			}
			String arg = cmd.getArgument(x_1);
			LinkedList<char> list;
			int s = cmd.getSizeNoStartNoEnd(arg, ',');
			for(int x = 0; x < s; x++){
				String tt = cmd.split(arg, x, ',');
				if(tt == ""){
					return value;
				}
				char t = tt.charAt(0);
				list.addLValue(t);
			}
			return list;
		}
		
    	virtual bool write(ElementId id, const PrimitiveList<char>& value, String path){
			MonkeyFileLog("MonkeyFile", "write PrimitiveList char",  "println", "");
			if(value.getPosition() == 0){
				return false;
			}
			CommandReader cmd;
			cmd.setText(readText(path));
			int line = cmd.getCommandOrder(id.getId());
			cmd.removeLine(line);
			clearFile(path);
			writeText(cmd.getText(), path);
			bool rt = this->writeText(id.getId() + String(" "), path);
			if(!rt){
				return false;
			}
			for(int x = 0; x < value.getPosition(); x++){
				char v = *value.getByPosition(x);
				if(x == value.getPosition() - 1){
					rt = this->writeText(String(v) + String("\n"), path);
				}else{
					rt = this->writeText(String(v) + String(","), path);
				}
				if(!rt){
					return false;
				}
			}
			return true;
		}
		
    	virtual PrimitiveList<char> read(ElementId id, PrimitiveList<char> value, String path){
			MonkeyFileLog("MonkeyFile", "read PrimitiveList char",  "println", "");
			CommandReader cmd;
			cmd.setText(readText(path));
			int x_1 = cmd.getCommandOrder(id.getId());
			if(x_1 == -1){
				return value;
			}
			String arg = cmd.getArgument(x_1);
			PrimitiveList<char> list;
			int s = cmd.getSizeNoStartNoEnd(arg, ',');
			for(int x = 0; x < s; x++){
				String tt = cmd.split(arg, x, ',');
				if(tt == ""){
					return value;
				}
				char t = tt.charAt(0);
				list.addLValue(t);
			}
			return list;
		}
		
    	virtual bool write(ElementId id, const LinkedList<String>& value, String path){
			MonkeyFileLog("MonkeyFile", "write LinkedList String",  "println", "");
			if(value.getPosition() == 0){
				return false;
			}
			CommandReader cmd;
			cmd.setText(readText(path));
			int line = cmd.getCommandOrder(id.getId());
			cmd.removeLine(line);
			clearFile(path);
			writeText(cmd.getText(), path);
			bool rt = this->writeText(id.getId() + String(" "), path);
			if(!rt){
				return false;
			}
			for(int x = 0; x < value.getPosition(); x++){
				String v = *value.getByPosition(x);
				if(x == value.getPosition() - 1){
					rt = this->writeText(v + String("\n"), path);
				}else{
					rt = this->writeText(v + String(","), path);
				}
				if(!rt){
					return false;
				}
			}
			return true;
		}
		
    	virtual LinkedList<String> read(ElementId id, LinkedList<String> value, String path){
			MonkeyFileLog("MonkeyFile", "read LinkedList String",  "println", "");
			CommandReader cmd;
			cmd.setText(readText(path));
			int x_1 = cmd.getCommandOrder(id.getId());
			if(x_1 == -1){
				return value;
			}
			String arg = cmd.getArgument(x_1);
			LinkedList<String> list;
			int s = cmd.getSizeNoStartNoEnd(arg, ',');
			for(int x = 0; x < s; x++){
				String t = cmd.split(arg, x, ',');
				list.addLValue(t);
			}
			return list;
		}
		
    	virtual bool write(ElementId id, const PrimitiveList<String>& value, String path){
			MonkeyFileLog("MonkeyFile", "write PrimitiveList String",  "println", "");
			if(value.getPosition() == 0){
				return false;
			}
			CommandReader cmd;
			cmd.setText(readText(path));
			int line = cmd.getCommandOrder(id.getId());
			cmd.removeLine(line);
			clearFile(path);
			writeText(cmd.getText(), path);
			bool rt = this->writeText(id.getId() + String(" "), path);
			if(!rt){
				return false;
			}
			for(int x = 0; x < value.getPosition(); x++){
				String v = *value.getByPosition(x);
				if(x == value.getPosition() - 1){
					rt = this->writeText(v + String("\n"), path);
				}else{
					rt = this->writeText(v + String(","), path);
				}
				if(!rt){
					return false;
				}
			}
			return true;
		}
		
    	virtual PrimitiveList<String> read(ElementId id, PrimitiveList<String> value, String path){
			MonkeyFileLog("MonkeyFile", "read PrimitiveList String",  "println", "");
			CommandReader cmd;
			cmd.setText(readText(path));
			int x_1 = cmd.getCommandOrder(id.getId());
			if(x_1 == -1){
				return value;
			}
			String arg = cmd.getArgument(x_1);
			PrimitiveList<String> list;
			int s = cmd.getSizeNoStartNoEnd(arg, ',');
			for(int x = 0; x < s; x++){
				String t = cmd.split(arg, x, ',');
				list.addLValue(t);
			}
			return list;
		}
    	
		virtual bool write(ElementId id, const LinkedList<long>& value, String path){
			MonkeyFileLog("MonkeyFile", "write LinkedList long",  "println", "");
			if(value.getPosition() == 0){
				return false;
			}
			CommandReader cmd;
			cmd.setText(readText(path));
			int line = cmd.getCommandOrder(id.getId());
			cmd.removeLine(line);
			clearFile(path);
			writeText(cmd.getText(), path);
			bool rt = this->writeText(id.getId() + String(" "), path);
			if(!rt){
				return false;
			}
			for(int x = 0; x < value.getPosition(); x++){
				long v = *value.getByPosition(x);
				if(x == value.getPosition() - 1){
					rt = this->writeText(String(v) + String("\n"), path);
				}else{
					rt = this->writeText(String(v) + String(","), path);
				}
				if(!rt){
					return false;
				}
			}
			return true;
		}
		
    	virtual LinkedList<long> read(ElementId id, LinkedList<long> value, String path){
			MonkeyFileLog("MonkeyFile", "read LinkedList long",  "println", "");
			CommandReader cmd;
			cmd.setText(readText(path));
			int x_1 = cmd.getCommandOrder(id.getId());
			if(x_1 == -1){
				return value;
			}
			String arg = cmd.getArgument(x_1);
			LinkedList<long> list;
			int s = cmd.getSizeNoStartNoEnd(arg, ',');
			for(int x = 0; x < s; x++){
				long t = cmd.split(arg, x, ',').toInt();
				list.addLValue(t);
			}
			return list;
		}
		
    	virtual bool write(ElementId id, const PrimitiveList<long>& value, String path){
			MonkeyFileLog("MonkeyFile", "write PrimitiveList long",  "println", "");
			if(value.getPosition() == 0){
				return false;
			}
			CommandReader cmd;
			cmd.setText(readText(path));
			int line = cmd.getCommandOrder(id.getId());
			cmd.removeLine(line);
			clearFile(path);
			writeText(cmd.getText(), path);
			bool rt = this->writeText(id.getId() + String(" "), path);
			if(!rt){
				return false;
			}
			for(int x = 0; x < value.getPosition(); x++){
				long v = *value.getByPosition(x);
				if(x == value.getPosition() - 1){
					rt = this->writeText(String(v) + String("\n"), path);
				}else{
					rt = this->writeText(String(v) + String(","), path);
				}
				if(!rt){
					return false;
				}
			}
			return true;
		}
		
    	virtual PrimitiveList<long> read(ElementId id, PrimitiveList<long> value, String path){
			MonkeyFileLog("MonkeyFile", "read PrimitiveList long",  "println", "");
			CommandReader cmd;
			cmd.setText(readText(path));
			int x_1 = cmd.getCommandOrder(id.getId());
			if(x_1 == -1){
				return value;
			}
			String arg = cmd.getArgument(x_1);
			PrimitiveList<long> list;
			int s = cmd.getSizeNoStartNoEnd(arg, ',');
			for(int x = 0; x < s; x++){
				long t = cmd.split(arg, x, ',').toInt();
				list.addLValue(t);
			}
			return list;
		}
		
    	virtual bool write(ElementId id, const LinkedList<float>& value, String path){
			MonkeyFileLog("MonkeyFile", "write LinkedList float",  "println", "");
			if(value.getPosition() == 0){
				return false;
			}
			CommandReader cmd;
			cmd.setText(readText(path));
			int line = cmd.getCommandOrder(id.getId());
			cmd.removeLine(line);
			clearFile(path);
			writeText(cmd.getText(), path);
			bool rt = this->writeText(id.getId() + String(" "), path);
			if(!rt){
				return false;
			}
			for(int x = 0; x < value.getPosition(); x++){
				float v = *value.getByPosition(x);
				if(x == value.getPosition() - 1){
					rt = this->writeText(String(v) + String("\n"), path);
				}else{
					rt = this->writeText(String(v) + String(","), path);
				}
				if(!rt){
					return false;
				}
			}
			return true;
		}
		
    	virtual bool write(ElementId id, const PrimitiveList<float>& value, String path){
			MonkeyFileLog("MonkeyFile", "write PrimitiveList float",  "println", "");
			if(value.getPosition() == 0){
				return false;
			}
			CommandReader cmd;
			cmd.setText(readText(path));
			int line = cmd.getCommandOrder(id.getId());
			cmd.removeLine(line);
			clearFile(path);
			writeText(cmd.getText(), path);
			bool rt = this->writeText(id.getId() + String(" "), path);
			if(!rt){
				return false;
			}
			for(int x = 0; x < value.getPosition(); x++){
				float v = *value.getByPosition(x);
				if(x == value.getPosition() - 1){
					rt = this->writeText(String(v) + String("\n"), path);
				}else{
					rt = this->writeText(String(v) + String(","), path);
				}
				if(!rt){
					return false;
				}
			}
			return true;
		}
		
    	virtual LinkedList<float> read(ElementId id, LinkedList<float> value, String path){
			MonkeyFileLog("MonkeyFile", "read LinkedList float",  "println", "");
			CommandReader cmd;
			cmd.setText(readText(path));
			int x_1 = cmd.getCommandOrder(id.getId());
			if(x_1 == -1){
				return value;
			}
			String arg = cmd.getArgument(x_1);
			LinkedList<float> list;
			int s = cmd.getSizeNoStartNoEnd(arg, ',');
			for(int x = 0; x < s; x++){
				float t = cmd.split(arg, x, ',').toFloat();
				list.addLValue(t);
			}
			return list;
		}
		
    	virtual PrimitiveList<float> read(ElementId id, PrimitiveList<float> value, String path){
			MonkeyFileLog("MonkeyFile", "read PrimitiveList float",  "println", "");
			CommandReader cmd;
			cmd.setText(readText(path));
			int x_1 = cmd.getCommandOrder(id.getId());
			if(x_1 == -1){
				return value;
			}
			String arg = cmd.getArgument(x_1);
			PrimitiveList<float> list;
			int s = cmd.getSizeNoStartNoEnd(arg, ',');
			for(int x = 0; x < s; x++){
				float t = cmd.split(arg, x, ',').toFloat();
				list.addLValue(t);
			}
			return list;
		}
		
    	virtual bool write(ElementId id, const PrimitiveMap<String,bool>& value, String path){
			MonkeyFileLog("MonkeyFile", "write PrimitiveMap<String,bool>",  "println", "");
			if(value.getPosition() == 0){
				return false;
			}
			CommandReader cmd;
			cmd.setText(readText(path));
			
			ElementId keyId = id.child("key");
			int line_key = cmd.getCommandOrder(keyId.getId());
			cmd.removeLine(line_key);
			
			ElementId valueId = id.child("value");
			int line_value = cmd.getCommandOrder(valueId.getId());
			cmd.removeLine(line_value);
			
			clearFile(path);
			writeText(cmd.getText(), path);
			
			String var_key = keyId.getId() + String(" ");
			String var_value = valueId.getId() + String(" ");
			
			for(int x = 0; x < value.getPosition(); x++){
				String k = *value.getKeyByPosition(x);
				bool v = *value.getByPosition(x);
				if(x == value.getPosition() - 1){
					var_key += k + String("\n");
					var_value += String(v) + String("\n");
				}else{
					var_key += k + String(",");
					var_value += String(v) + String(",");
				}
			}
			
			bool rk = this->writeText(var_key, path);
			bool rv = this->writeText(var_value, path);
			if(!rk || !rv){
				return false;
			}
			return true;
		}
		
    	virtual PrimitiveMap<String,bool> read(ElementId id, PrimitiveMap<String,bool> value, String path){
			MonkeyFileLog("MonkeyFile", "read PrimitiveMap<String,bool>",  "println", "");
			CommandReader cmd;
			cmd.setText(readText(path));
			
			int x_key = cmd.getCommandOrder(id.child("key").getId());
			int x_value = cmd.getCommandOrder(id.child("value").getId());
			if(x_key == -1 || x_value == -1){
				return value;
			}
			
			String arg_key = cmd.getArgument(x_key);
			String arg_value = cmd.getArgument(x_value);
			
			PrimitiveMap<String,bool> map;
			
			int s_key = cmd.getSizeNoStartNoEnd(arg_key, ',');
			int s_value = cmd.getSizeNoStartNoEnd(arg_value, ',');
			if(s_key != s_value){
				return value;
			}
			
			for(int x = 0; x < s_key; x++){
				String k = cmd.split(arg_key, x, ',');
				bool v = cmd.split(arg_value, x, ',') == "1";
				map.addLValues(k,v);
			}
			return map;
		}
		
    	virtual bool write(ElementId id, const PrimitiveMap<String,String>& value, String path){
			MonkeyFileLog("MonkeyFile", "write PrimitiveMap<String,String>",  "println", "");
			if(value.getPosition() == 0){
				return false;
			}
			CommandReader cmd;
			cmd.setText(readText(path));
			
			ElementId keyId = id.child("key");
			int line_key = cmd.getCommandOrder(keyId.getId());
			cmd.removeLine(line_key);
			
			ElementId valueId = id.child("value");
			int line_value = cmd.getCommandOrder(valueId.getId());
			cmd.removeLine(line_value);
			
			clearFile(path);
			writeText(cmd.getText(), path);
			
			String var_key = keyId.getId() + String(" ");
			String var_value = valueId.getId() + String(" ");
			
			for(int x = 0; x < value.getPosition(); x++){
				String k = *value.getKeyByPosition(x);
				String v = *value.getByPosition(x);
				if(x == value.getPosition() - 1){
					var_key += k + String("\n");
					var_value += v + String("\n");
				}else{
					var_key += k + String(",");
					var_value += v + String(",");
				}
			}
			
			bool rk = this->writeText(var_key, path);
			bool rv = this->writeText(var_value, path);
			if(!rk || !rv){
				return false;
			}
			return true;
		}
		
    	virtual PrimitiveMap<String,String> read(ElementId id, PrimitiveMap<String,String> value, String path){
			MonkeyFileLog("MonkeyFile", "read PrimitiveMap<String,String>",  "println", "");
			CommandReader cmd;
			cmd.setText(readText(path));
			
			int x_key = cmd.getCommandOrder(id.child("key").getId());
			int x_value = cmd.getCommandOrder(id.child("value").getId());
			if(x_key == -1 || x_value == -1){
				return value;
			}
			
			String arg_key = cmd.getArgument(x_key);
			String arg_value = cmd.getArgument(x_value);
			
			PrimitiveMap<String,String> map;
			
			int s_key = cmd.getSizeNoStartNoEnd(arg_key, ',');
			int s_value = cmd.getSizeNoStartNoEnd(arg_value, ',');
			if(s_key != s_value){
				return value;
			}
			
			for(int x = 0; x < s_key; x++){
				String k = cmd.split(arg_key, x, ',');
				String v = cmd.split(arg_value, x, ',');
				map.addLValues(k,v);
			}
			return map;
		}
		
		
	protected:
		T& m_sd;
};

}

template<class T>
bool ame::DefaultMonkeyFile<T>::init = false;

#endif 
