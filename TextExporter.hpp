
/**
 *
 * @author PankeyCR - Manuel Sanchez Badilla
 *
 */
 
#ifndef TextExporter_hpp
#define TextExporter_hpp

#include "ElementId.hpp"
#include "ByteArray.hpp"
#include "UUID.hpp"
#include "LinkedList.hpp"
#include "PrimitiveList.hpp"
#include "PrimitiveMap.hpp"
#include "MonkeyExporter.hpp"
#include "CommandReader.hpp"

#ifdef TextExporterLogApp
	#include "Logger.hpp"
	#define TextExporterLog(name,method,type,mns) Log(name,method,type,mns)
#else
	#define TextExporterLog(name,method,type,mns)
#endif

namespace ame{

class TextExporter : public MonkeyExporter{
    public:
		TextExporter(){}
		TextExporter(const String& strng){
			text = strng;
			setText(text);
		}
		virtual ~TextExporter(){}
		
    	virtual PrimitiveList<ElementId> read(ElementId id, PrimitiveList<ElementId> value){
			TextExporterLog("TextExporter", "read PrimitiveList ElementId",  "println", "");
			CommandReader cmd;
			cmd.setText(text);
			int x_1 = cmd.getCommandOrder(id.getId());
			if(x_1 == -1){
				return value;
			}
			String arg = cmd.getArgument(x_1);
			PrimitiveList<ElementId> list;
			int s = cmd.getSizeNoStartNoEnd(arg, ',');
			for(int x = 0; x < s; x++){
				ElementId t = cmd.split(arg, x, ',');
				list.addLValue(t);
			}
			return list;
		}
		
    	virtual PrimitiveMap<ElementId,String> read(ElementId id, PrimitiveMap<ElementId,String> value){
			TextExporterLog("TextExporter", "read PrimitiveMap<ElementId,String>",  "println", "");
			CommandReader cmd;
			cmd.setText(text);
			
			int x_key = cmd.getCommandOrder(id.child("key").getId());
			int x_value = cmd.getCommandOrder(id.child("value").getId());
			if(x_key == -1 || x_value == -1){
				return value;
			}
			
			String arg_key = cmd.getArgument(x_key);
			String arg_value = cmd.getArgument(x_value);
			
			PrimitiveMap<ElementId,String> map;
			
			int s_key = cmd.getSizeNoStartNoEnd(arg_key, ',');
			int s_value = cmd.getSizeNoStartNoEnd(arg_value, ',');
			if(s_key != s_value){
				return value;
			}
			
			for(int x = 0; x < s_key; x++){
				ElementId k = ElementId(cmd.split(arg_key, x, ','));
				String v = cmd.split(arg_value, x, ',');
				map.addLValues(k,v);
			}
			return map;
		}
		
		// int primitive
    	virtual bool write(ElementId id, const int& value){
			writeIds(id);
			writeIdsType(id,"int");
			TextExporterLog("TextExporter", "write int",  "println", String(value));
			CommandReader cmd;
			cmd.setText(text);
			int line = cmd.getCommandOrder(id.getId());
			if(line == -1){
				text += id.getId() + String(" ") + String(value) + "\n";
				return true;
			}
			cmd.removeLine(id.getId());
			
			text = cmd.getText();
			text += id.getId() + String(" ") + String(value) + "\n";
			return true;
		}
    	virtual bool write(ElementId id, const LinkedList<int>& value){
			writeIds(id);
			writeIdsType(id,"LinkedList<int>");
			TextExporterLog("TextExporter", "write LinkedList int",  "println", "");
			if(value.getPosition() == 0){
				return false;
			}
			CommandReader cmd;
			cmd.setText(text);
			int line = cmd.getCommandOrder(id.getId());
			cmd.removeLine(id.getId());
			
			text = cmd.getText();
			text += id.getId() + String(" ");
			for(int x = 0; x < value.getPosition(); x++){
				int v = *value.getByPosition(x);
				if(x == value.getPosition() - 1){
					text += String(v) + String("\n");
				}else{
					text += String(v) + String(",");
				}
			}
			return true;
		}
		
    	virtual bool write(ElementId id, const PrimitiveList<int>& value){
			writeIds(id);
			writeIdsType(id,"PrimitiveList<int>");
			TextExporterLog("TextExporter", "write PrimitiveList int",  "println", "");
			if(value.getPosition() == 0){
				return false;
			}
			CommandReader cmd;
			cmd.setText(text);
			int line = cmd.getCommandOrder(id.getId());
			cmd.removeLine(id.getId());
			
			text = cmd.getText();
			text += id.getId() + String(" ");
			for(int x = 0; x < value.getPosition(); x++){
				int v = *value.getByPosition(x);
				if(x == value.getPosition() - 1){
					text += String(v) + String("\n");
				}else{
					text += String(v) + String(",");
				}
			}
			return true;
		}
		

		// ByteArray primitive
    	virtual bool write(ElementId id, const ByteArray& value){
			writeIds(id);
			writeIdsType(id,"ByteArray");
			TextExporterLog("TextExporter", "write String",  "println", value.toString());
			CommandReader cmd;
			cmd.setText(text);
			int line = cmd.getCommandOrder(id.getId());
			if(line == -1){
				text += id.getId() + String(" ") + value.toString() + "\n";
				return true;
			}
			cmd.removeLine(id.getId());
			text = cmd.getText();
			text += id.getId() + String(" ") + value.toString() + "\n";
			return true;
		}
		
    	virtual bool write(ElementId id, const LinkedList<ByteArray>& value){
			writeIds(id);
			writeIdsType(id,"LinkedList<ByteArray>");
			TextExporterLog("TextExporter", "write LinkedList ByteArray",  "println", "");
			if(value.getPosition() == 0){
				return false;
			}
			CommandReader cmd;
			cmd.setText(text);
			int line = cmd.getCommandOrder(id.getId());
			cmd.removeLine(id.getId());
			
			text = cmd.getText();
			text += id.getId() + String(" ");
			for(int x = 0; x < value.getPosition(); x++){
				ByteArray v = *value.getByPosition(x);
				if(x == value.getPosition() - 1){
					text += v.toString() + String("\n");
				}else{
					text += v.toString() + String(",");
				}
			}
			return true;
		}
		
    	virtual bool write(ElementId id, const PrimitiveList<ByteArray>& value){
			writeIds(id);
			writeIdsType(id,"PrimitiveList<ByteArray>");
			TextExporterLog("TextExporter", "write PrimitiveList ByteArray",  "println", "");
			if(value.getPosition() == 0){
				return false;
			}
			CommandReader cmd;
			cmd.setText(text);
			int line = cmd.getCommandOrder(id.getId());
			cmd.removeLine(id.getId());
			
			text = cmd.getText();
			text += id.getId() + String(" ");
			for(int x = 0; x < value.getPosition(); x++){
				ByteArray v = *value.getByPosition(x);
				if(x == value.getPosition() - 1){
					text += v.toString() + String("\n");
				}else{
					text += v.toString() + String(",");
				}
			}
			return true;
		}
		

		// bool primitive
    	virtual bool write(ElementId id, const bool& value){
			writeIds(id);
			writeIdsType(id,"bool");
			TextExporterLog("TextExporter", "write bool",  "println", String(value));
			CommandReader cmd;
			cmd.setText(text);
			int line = cmd.getCommandOrder(id.getId());
			if(line == -1){
				text += id.getId() + String(" ") + String(value) + "\n";
				return true;
			}
			cmd.removeLine(id.getId());
			text = cmd.getText();
			text += id.getId() + String(" ") + String(value) + "\n";
			return true;
		}
		
    	virtual bool write(ElementId id, const LinkedList<bool>& value){
			writeIds(id);
			writeIdsType(id,"LinkedList<bool>");
			TextExporterLog("TextExporter", "write LinkedList bool",  "println", "");
			if(value.getPosition() == 0){
				return false;
			}
			CommandReader cmd;
			cmd.setText(text);
			int line = cmd.getCommandOrder(id.getId());
			cmd.removeLine(id.getId());
			
			text = cmd.getText();
			text += id.getId() + String(" ");
			for(int x = 0; x < value.getPosition(); x++){
				bool v = *value.getByPosition(x);
				if(x == value.getPosition() - 1){
					text += String(v) + String("\n");
				}else{
					text += String(v) + String(",");
				}
			}
			return true;
		}
		
    	virtual bool write(ElementId id, const PrimitiveList<bool>& value){
			writeIds(id);
			writeIdsType(id,"PrimitiveList<bool>");
			TextExporterLog("TextExporter", "write PrimitiveList bool",  "println", "");
			if(value.getPosition() == 0){
				return false;
			}
			CommandReader cmd;
			cmd.setText(text);
			int line = cmd.getCommandOrder(id.getId());
			cmd.removeLine(id.getId());
			
			text = cmd.getText();
			text += id.getId() + String(" ");
			for(int x = 0; x < value.getPosition(); x++){
				bool v = *value.getByPosition(x);
				if(x == value.getPosition() - 1){
					text += String(v) + String("\n");
				}else{
					text += String(v) + String(",");
				}
			}
			return true;
		}
		
		
		// char primitive
    	virtual bool write(ElementId id, const char& value){
			writeIds(id);
			writeIdsType(id,"char");
			TextExporterLog("TextExporter", "write String",  "println", String(value));
			CommandReader cmd;
			cmd.setText(text);
			int line = cmd.getCommandOrder(id.getId());
			if(line == -1){
				text += id.getId() + String(" ") + String(value) + "\n";
				return true;
			}
			cmd.removeLine(id.getId());
			text = cmd.getText();
			text += id.getId() + String(" ") + String(value) + "\n";
			return true;
		}
		
    	virtual bool write(ElementId id, const LinkedList<char>& value){
			writeIds(id);
			writeIdsType(id,"LinkedList<char>");
			TextExporterLog("TextExporter", "write LinkedList char",  "println", "");
			if(value.getPosition() == 0){
				return false;
			}
			CommandReader cmd;
			cmd.setText(text);
			int line = cmd.getCommandOrder(id.getId());
			cmd.removeLine(id.getId());
			
			text = cmd.getText();
			text += id.getId() + String(" ");
			for(int x = 0; x < value.getPosition(); x++){
				char v = *value.getByPosition(x);
				if(x == value.getPosition() - 1){
					text += String(v) + String("\n");
				}else{
					text += String(v) + String(",");
				}
			}
			return true;
		}
		
    	virtual bool write(ElementId id, const PrimitiveList<char>& value){
			writeIds(id);
			writeIdsType(id,"PrimitiveList<char>");
			TextExporterLog("TextExporter", "write PrimitiveList char",  "println", "");
			if(value.getPosition() == 0){
				return false;
			}
			CommandReader cmd;
			cmd.setText(text);
			int line = cmd.getCommandOrder(id.getId());
			cmd.removeLine(id.getId());
			
			text = cmd.getText();
			text += id.getId() + String(" ");
			for(int x = 0; x < value.getPosition(); x++){
				char v = *value.getByPosition(x);
				if(x == value.getPosition() - 1){
					text += String(v) + String("\n");
				}else{
					text += String(v) + String(",");
				}
			}
			return true;
		}

		// ElementId primitive
    	virtual bool write(ElementId id, const ElementId& value){
			writeIds(id);
			writeIdsType(id,"ElementId");
			TextExporterLog("TextExporter", "write String",  "println", value.getId());
			CommandReader cmd;
			cmd.setText(text);
			int line = cmd.getCommandOrder(id.getId());
			if(line == -1){
				text += id.getId() + String(" ") + value.getId() + "\n";
				return true;
			}
			cmd.removeLine(id.getId());
			text = cmd.getText();
			text += id.getId() + String(" ") + value.getId() + "\n";
			return true;
		}
		
    	virtual bool write(ElementId id, const PrimitiveList<ElementId>& value){
			writeIds(id);
			writeIdsType(id,"PrimitiveList<ElementId>");
			TextExporterLog("TextExporter", "write PrimitiveList ElementId",  "println", "");
			if(value.getPosition() == 0){
				return false;
			}
			CommandReader cmd;
			cmd.setText(text);
			int line = cmd.getCommandOrder(id.getId());
			cmd.removeLine(id.getId());
			
			text = cmd.getText();
			text += id.getId() + String(" ");
			for(int x = 0; x < value.getPosition(); x++){
				ElementId v = *value.getByPosition(x);
				if(x == value.getPosition() - 1){
					text += v.getId() + String("\n");
				}else{
					text += v.getId() + String(",");
				}
			}
			return true;
		}
		
		// String primitive
    	virtual bool write(ElementId id, const String& value){
			writeIds(id);
			writeIdsType(id,"String");
			TextExporterLog("TextExporter", "write String",  "println", value);
			CommandReader cmd;
			cmd.setText(text);
			int line = cmd.getCommandOrder(id.getId());
			if(line == -1){
				text += id.getId() + String(" ") + value + "\n";
				return true;
			}
			cmd.removeLine(id.getId());
			text = cmd.getText();
			text += id.getId() + String(" ") + value + "\n";
			return true;
		}
		
    	virtual bool write(ElementId id, const char* value){
			writeIds(id);
			writeIdsType(id,"char*");
			TextExporterLog("TextExporter", "write String",  "println", String(value));
			CommandReader cmd;
			cmd.setText(text);
			int line = cmd.getCommandOrder(id.getId());
			if(line == -1){
				text += id.getId() + String(" ") + String(value) + "\n";
				return true;
			}
			cmd.removeLine(id.getId());
			text = cmd.getText();
			text += id.getId() + String(" ") + String(value) + "\n";
			return true;
		}
		
    	virtual bool write(ElementId id, const LinkedList<String>& value){
			writeIds(id);
			writeIdsType(id,"LinkedList<String>");
			TextExporterLog("TextExporter", "write LinkedList String",  "println", "");
			if(value.getPosition() == 0){
				return false;
			}
			CommandReader cmd;
			cmd.setText(text);
			int line = cmd.getCommandOrder(id.getId());
			cmd.removeLine(id.getId());
			
			text = cmd.getText();
			text += id.getId() + String(" ");
			for(int x = 0; x < value.getPosition(); x++){
				String v = *value.getByPosition(x);
				if(x == value.getPosition() - 1){
					text += v + String("\n");
				}else{
					text += v + String(",");
				}
			}
			return true;
		}
		
    	virtual bool write(ElementId id, const PrimitiveList<String>& value){
			writeIds(id);
			writeIdsType(id,"PrimitiveList<String>");
			TextExporterLog("TextExporter", "write PrimitiveList String",  "println", "");
			if(value.getPosition() == 0){
				return false;
			}
			CommandReader cmd;
			cmd.setText(text);
			int line = cmd.getCommandOrder(id.getId());
			cmd.removeLine(id.getId());
			
			text = cmd.getText();
			text += id.getId() + String(" ");
			for(int x = 0; x < value.getPosition(); x++){
				String v = *value.getByPosition(x);
				if(x == value.getPosition() - 1){
					text += v + String("\n");
				}else{
					text += v + String(",");
				}
			}
			return true;
		}
		
		
		// long primitive
    	virtual bool write(ElementId id, const long& value){
			writeIds(id);
			writeIdsType(id,"long");
			TextExporterLog("TextExporter", "write String",  "println", String(value));
			CommandReader cmd;
			cmd.setText(text);
			int line = cmd.getCommandOrder(id.getId());
			if(line == -1){
				text += id.getId() + String(" ") + String(value) + "\n";
				return true;
			}
			cmd.removeLine(id.getId());
			text = cmd.getText();
			text += id.getId() + String(" ") + String(value) + "\n";
			return true;
		}
		
    	virtual bool write(ElementId id, const LinkedList<long>& value){
			writeIds(id);
			writeIdsType(id,"LinkedList<long>");
			TextExporterLog("TextExporter", "write LinkedList long",  "println", "");
			if(value.getPosition() == 0){
				return false;
			}
			CommandReader cmd;
			cmd.setText(text);
			int line = cmd.getCommandOrder(id.getId());
			cmd.removeLine(id.getId());
			
			text = cmd.getText();
			text += id.getId() + String(" ");
			for(int x = 0; x < value.getPosition(); x++){
				long v = *value.getByPosition(x);
				if(x == value.getPosition() - 1){
					text += String(v) + String("\n");
				}else{
					text += String(v) + String(",");
				}
			}
			return true;
		}
		
    	virtual bool write(ElementId id, const PrimitiveList<long>& value){
			writeIds(id);
			writeIdsType(id,"PrimitiveList<long>");
			TextExporterLog("TextExporter", "write PrimitiveList long",  "println", "");
			if(value.getPosition() == 0){
				return false;
			}
			CommandReader cmd;
			cmd.setText(text);
			int line = cmd.getCommandOrder(id.getId());
			cmd.removeLine(id.getId());
			
			text = cmd.getText();
			text += id.getId() + String(" ");
			for(int x = 0; x < value.getPosition(); x++){
				long v = *value.getByPosition(x);
				if(x == value.getPosition() - 1){
					text += String(v) + String("\n");
				}else{
					text += String(v) + String(",");
				}
			}
			return true;
		}
		
		// UUID primitive
    	virtual bool write(ElementId id, UUID value){
			writeIds(id);
			writeIdsType(id,"UUID");
			TextExporterLog("TextExporter", "write UUID",  "println", String(value.getId()));
			CommandReader cmd;
			cmd.setText(text);
			int line = cmd.getCommandOrder(id.getId());
			if(line == -1){
				text += id.getId() + String(" ") + String(value.getId()) + "\n";
				return true;
			}
			cmd.removeLine(id.getId());
			text = cmd.getText();
			text += id.getId() + String(" ") + String(value.getId()) + "\n";
			return true;
		}
		
		// float primitive
    	virtual bool write(ElementId id, const float& value){
			writeIds(id);
			writeIdsType(id,"float");
			TextExporterLog("TextExporter", "write float",  "println", String(value));
			CommandReader cmd;
			cmd.setText(text);
			int line = cmd.getCommandOrder(id.getId());
			if(line == -1){
				text += id.getId() + String(" ") + String(value) + "\n";
				return true;
			}
			cmd.removeLine(id.getId());
			text = cmd.getText();
			text += id.getId() + String(" ") + String(value) + "\n";
			return true;
		}
		
    	virtual bool write(ElementId id, const LinkedList<float>& value){
			writeIds(id);
			writeIdsType(id,"LinkedList<float>");
			TextExporterLog("TextExporter", "write LinkedList float",  "println", "");
			if(value.getPosition() == 0){
				return false;
			}
			CommandReader cmd;
			cmd.setText(text);
			int line = cmd.getCommandOrder(id.getId());
			cmd.removeLine(id.getId());
			
			text = cmd.getText();
			text += id.getId() + String(" ");
			for(int x = 0; x < value.getPosition(); x++){
				float v = *value.getByPosition(x);
				if(x == value.getPosition() - 1){
					text += String(v) + String("\n");
				}else{
					text += String(v) + String(",");
				}
			}
			return true;
		}
		
    	virtual bool write(ElementId id, const PrimitiveList<float>& value){
			writeIds(id);
			writeIdsType(id,"PrimitiveList<float>");
			TextExporterLog("TextExporter", "write PrimitiveList float",  "println", "");
			if(value.getPosition() == 0){
				return false;
			}
			CommandReader cmd;
			cmd.setText(text);
			int line = cmd.getCommandOrder(id.getId());
			cmd.removeLine(id.getId());
			
			text = cmd.getText();
			text += id.getId() + String(" ");
			for(int x = 0; x < value.getPosition(); x++){
				float v = *value.getByPosition(x);
				if(x == value.getPosition() - 1){
					text += String(v) + String("\n");
				}else{
					text += String(v) + String(",");
				}
			}
			return true;
		}
		
		
		// Savable primitive
    	// virtual bool write(ElementId id, const LinkedList<Savable>& value)=0;
    	// virtual bool write(ElementId id, const PrimitiveList<Savable>& value)=0;
		
		// PrimitiveMap primitive
		// template<class K,class V>
    	// virtual bool write(ElementId id, Map<K,V>* value){
			
		// }
		
    	// virtual bool write(ElementId id, const PrimitiveMap<int,int>& value)=0;
    	// virtual bool write(ElementId id, const PrimitiveMap<bool,bool>& value)=0;
    	// virtual bool write(ElementId id, const PrimitiveMap<char,char>& value)=0;
    	// virtual bool write(ElementId id, const PrimitiveMap<long,long>& value)=0;
    	// virtual bool write(ElementId id, const PrimitiveMap<float,float>& value)=0;
    	virtual bool write(ElementId id, const PrimitiveMap<String,String>& value){
			writeIds(id);
			writeIdsType(id,"PrimitiveMap<String,String>");
			TextExporterLog("TextExporter", "write PrimitiveMap<String,String>",  "println", "");
			if(value.getPosition() == 0){
				return false;
			}
			CommandReader cmd;
			cmd.setText(text);
			
			ElementId keyId = id.child("key");
			int line_key = cmd.getCommandOrder(keyId.getId());
			cmd.removeLine(keyId.getId());
			
			ElementId valueId = id.child("value");
			int line_value = cmd.getCommandOrder(valueId.getId());
			cmd.removeLine(valueId.getId());
			
			text = cmd.getText();
			
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
			
			text += var_key;
			text += var_value;
			return true;
		}
		
    	// virtual bool write(ElementId id, const PrimitiveMap<Savable,Savable>& value)=0;
		
    	// virtual bool write(ElementId id, const PrimitiveMap<int,bool>& value)=0;
    	// virtual bool write(ElementId id, const PrimitiveMap<int,char>& value)=0;
    	// virtual bool write(ElementId id, const PrimitiveMap<int,long>& value)=0;
    	// virtual bool write(ElementId id, const PrimitiveMap<int,float>& value)=0;
    	// virtual bool write(ElementId id, const PrimitiveMap<int,String>& value)=0;
    	// virtual bool write(ElementId id, const PrimitiveMap<int,Savable>& value)=0;
		
    	// virtual bool write(ElementId id, const PrimitiveMap<bool,int>& value)=0;
    	// virtual bool write(ElementId id, const PrimitiveMap<bool,char>& value)=0;
    	// virtual bool write(ElementId id, const PrimitiveMap<bool,long>& value)=0;
    	// virtual bool write(ElementId id, const PrimitiveMap<bool,float>& value)=0;
    	// virtual bool write(ElementId id, const PrimitiveMap<bool,String>& value)=0;
    	// virtual bool write(ElementId id, const PrimitiveMap<bool,Savable>& value)=0;
		
    	// virtual bool write(ElementId id, const PrimitiveMap<char,int>& value)=0;
    	// virtual bool write(ElementId id, const PrimitiveMap<char,bool>& value)=0;
    	// virtual bool write(ElementId id, const PrimitiveMap<char,long>& value)=0;
    	// virtual bool write(ElementId id, const PrimitiveMap<char,float>& value)=0;
    	// virtual bool write(ElementId id, const PrimitiveMap<char,String>& value)=0;
    	// virtual bool write(ElementId id, const PrimitiveMap<char,Savable>& value)=0;
		
    	// virtual bool write(ElementId id, const PrimitiveMap<long,int>& value)=0;
    	// virtual bool write(ElementId id, const PrimitiveMap<long,bool>& value)=0;
    	// virtual bool write(ElementId id, const PrimitiveMap<long,char>& value)=0;
    	// virtual bool write(ElementId id, const PrimitiveMap<long,float>& value)=0;
    	// virtual bool write(ElementId id, const PrimitiveMap<long,String>& value)=0;
    	// virtual bool write(ElementId id, const PrimitiveMap<long,Savable>& value)=0;
		
    	// virtual bool write(ElementId id, const PrimitiveMap<float,int>& value)=0;
    	// virtual bool write(ElementId id, const PrimitiveMap<float,bool>& value)=0;
    	// virtual bool write(ElementId id, const PrimitiveMap<float,char>& value)=0;
    	// virtual bool write(ElementId id, const PrimitiveMap<float,long>& value)=0;
    	// virtual bool write(ElementId id, const PrimitiveMap<float,String>& value)=0;
    	// virtual bool write(ElementId id, const PrimitiveMap<float,Savable>& value)=0;
		
    	// virtual bool write(ElementId id, const PrimitiveMap<String,int>& value)=0;
    	virtual bool write(ElementId id, const PrimitiveMap<String,bool>& value){
			writeIds(id);
			writeIdsType(id,"PrimitiveMap<String,bool>");
			TextExporterLog("TextExporter", "write PrimitiveMap<String,bool>",  "println", "");
			if(value.getPosition() == 0){
				return false;
			}
			CommandReader cmd;
			cmd.setText(text);
			
			ElementId keyId = id.child("key");
			int line_key = cmd.getCommandOrder(keyId.getId());
			cmd.removeLine(keyId.getId());
			
			ElementId valueId = id.child("value");
			int line_value = cmd.getCommandOrder(valueId.getId());
			cmd.removeLine(valueId.getId());
			
			text = cmd.getText();
			
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
			
			text += var_key;
			text += var_value;
			return true;
		}
		
    	// virtual bool write(ElementId id, const PrimitiveMap<String,char>& value)=0;
    	// virtual bool write(ElementId id, const PrimitiveMap<String,long>& value)=0;
    	// virtual bool write(ElementId id, const PrimitiveMap<String,float>& value)=0;
    	// virtual bool write(ElementId id, const PrimitiveMap<String,Savable>& value)=0;
		
    	// virtual bool write(ElementId id, const PrimitiveMap<Savable,int>& value)=0;
    	// virtual bool write(ElementId id, const PrimitiveMap<Savable,bool>& value)=0;
    	// virtual bool write(ElementId id, const PrimitiveMap<Savable,char>& value)=0;
    	// virtual bool write(ElementId id, const PrimitiveMap<Savable,long>& value)=0;
    	// virtual bool write(ElementId id, const PrimitiveMap<Savable,float>& value)=0;
    	// virtual bool write(ElementId id, const PrimitiveMap<Savable,String>& value)=0;
		
    	virtual bool write(ElementId id, const PrimitiveMap<ElementId,String>& value){
			writeIds(id);
			writeIdsType(id,"PrimitiveMap<ElementId,String>");
			TextExporterLog("TextExporter", "write PrimitiveMap<ElementId,String>",  "println", "");
			if(value.getPosition() == 0){
				return false;
			}
			CommandReader cmd;
			cmd.setText(text);
			
			ElementId keyId = id.child("key");
			int line_key = cmd.getCommandOrder(keyId.getId());
			cmd.removeLine(keyId.getId());
			
			ElementId valueId = id.child("value");
			int line_value = cmd.getCommandOrder(valueId.getId());
			cmd.removeLine(valueId.getId());
			
			text = cmd.getText();
			
			String var_key = keyId.getId() + String(" ");
			String var_value = valueId.getId() + String(" ");
			
			for(int x = 0; x < value.getPosition(); x++){
				ElementId k = *value.getKeyByPosition(x);
				String v = *value.getByPosition(x);
				if(x == value.getPosition() - 1){
					var_key += k.getId() + String("\n");
					var_value += v + String("\n");
				}else{
					var_key += k.getId() + String(",");
					var_value += v + String(",");
				}
			}
			
			text += var_key;
			text += var_value;
			return true;
		}
		
		virtual PrimitiveList<ElementId> getIds(){
			TextExporterLog("TextExporter", "getIds",  "println", "");
			return ids;
		}
		
		virtual bool containType(ElementId id){
			TextExporterLog("TextExporter", "containType",  "println", "");
			return idsType.containKeyByLValue(id);
		}
		
		virtual String readType(ElementId id){
			TextExporterLog("TextExporter", "readType",  "println", "");
			return idsType.get(id);
		}
		
		virtual void addIds(PrimitiveList<ElementId> m_ids){
			TextExporterLog("TextExporter", "addIds",  "println", "");
			for(int x = 0; x < m_ids.getPosition(); x++){
				ids.add(m_ids[x]);
			}
			if(ids.getPosition() == 0){
				return;
			}
			ElementId id = ElementId("transporter.ids");
			CommandReader cmd;
			cmd.setText(text);
			cmd.removeLine(id.getId());
			text = cmd.getText();
			text += id.getId() + String(" ");
			for(int x = 0; x < ids.getPosition(); x++){
				ElementId v = *ids.getByPosition(x);
				if(x == ids.getPosition() - 1){
					text += v.getId() + String("\n");
				}else{
					text += v.getId() + String(",");
				}
			}
		}
		
		virtual void removeIds(PrimitiveList<ElementId> m_ids){
			TextExporterLog("TextExporter", "removeIds",  "println", "");
			for(int x = 0; x < m_ids.getPosition(); x++){
				ids.removeByLValue(m_ids[x]);
			}
			ElementId id = ElementId("transporter.ids");
			CommandReader cmd;
			cmd.setText(text);
			cmd.removeLine(id.getId());
			text = cmd.getText();
			if(ids.getPosition() == 0){
				return;
			}
			text += id.getId() + String(" ");
			for(int x = 0; x < ids.getPosition(); x++){
				ElementId v = *ids.getByPosition(x);
				if(x == ids.getPosition() - 1){
					text += v.getId() + String("\n");
				}else{
					text += v.getId() + String(",");
				}
			}
		}
		
		virtual void writeIds(ElementId value){
			TextExporterLog("TextExporter", "writeIds",  "println", "");
			ids.put(value);
			ElementId id = ElementId("transporter.ids");
			if(ids.getPosition() == 0){
				return;
			}
			CommandReader cmd;
			cmd.setText(text);
			cmd.removeLine(id.getId());
			text = cmd.getText();
			text += id.getId() + String(" ");
			for(int x = 0; x < ids.getPosition(); x++){
				ElementId v = *ids.getByPosition(x);
				if(x == ids.getPosition() - 1){
					text += v.getId() + String("\n");
				}else{
					text += v.getId() + String(",");
				}
			}
		}
		
		virtual void removeIds(ElementId value){
			TextExporterLog("TextExporter", "removeIds",  "println", "");
			if(ids.getPosition() == 0){
				return;
			}
			if(!ids.containByLValue(value)){
				return;
			}
			ids.removeByLValue(value);
			ElementId id = ElementId("transporter.ids");
			CommandReader cmd;
			cmd.setText(text);
			cmd.removeLine(id.getId());
			text = cmd.getText();
			if(ids.getPosition() == 0){
				return;
			}
			text += id.getId() + String(" ");
			for(int x = 0; x < ids.getPosition(); x++){
				ElementId v = *ids.getByPosition(x);
				if(x == ids.getPosition() - 1){
					text += v.getId() + String("\n");
				}else{
					text += v.getId() + String(",");
				}
			}
		}
		
		virtual void removeIds(){
			TextExporterLog("TextExporter", "removeIds",  "println", "");
			ElementId id = ElementId("transporter.ids");
			CommandReader cmd;
			cmd.setText(text);
			cmd.removeLine(id.getId());
			text = cmd.getText();
			ids.resetDelete();
		}
		
		virtual void addIdsType(PrimitiveMap<ElementId,String> m_idsType){
			TextExporterLog("TextExporter", "addIdsType",  "println", "");
			for(int x = 0; x < m_idsType.getPosition(); x++){
				idsType.addLValues(*m_idsType.getKeyByPosition(x), *m_idsType.getByPosition(x));
			}
			ElementId id = ElementId("transporter.idsType");
			if(idsType.getPosition() == 0){
				return;
			}
			CommandReader cmd;
			cmd.setText(text);
			
			ElementId keyId = id.child("key");
			int line_key = cmd.getCommandOrder(keyId.getId());
			cmd.removeLine(keyId.getId());
			
			ElementId valueId = id.child("value");
			int line_value = cmd.getCommandOrder(valueId.getId());
			cmd.removeLine(valueId.getId());
			
			text = cmd.getText();
			
			String var_key = keyId.getId() + String(" ");
			String var_value = valueId.getId() + String(" ");
			
			for(int x = 0; x < idsType.getPosition(); x++){
				ElementId k = *idsType.getKeyByPosition(x);
				String v = *idsType.getByPosition(x);
				if(x == idsType.getPosition() - 1){
					var_key += k.getId() + String("\n");
					var_value += v + String("\n");
				}else{
					var_key += k.getId() + String(",");
					var_value += v + String(",");
				}
			}
			
			text += var_key;
			text += var_value;
		}
		
		virtual void removeIdsType(PrimitiveMap<ElementId,String> m_idsType){
			TextExporterLog("TextExporter", "removeIdsType",  "println", "");
			for(int x = 0; x < m_idsType.getPosition(); x++){
				idsType.removeByLValue(*m_idsType.getKeyByPosition(x));
			}
			ElementId id = ElementId("transporter.idsType");
			
			CommandReader cmd;
			cmd.setText(text);
			
			ElementId keyId = id.child("key");
			int line_key = cmd.getCommandOrder(keyId.getId());
			cmd.removeLine(keyId.getId());
			
			ElementId valueId = id.child("value");
			int line_value = cmd.getCommandOrder(valueId.getId());
			cmd.removeLine(valueId.getId());
			
			text = cmd.getText();
			
			if(idsType.getPosition() == 0){
				return;
			}
			
			String var_key = keyId.getId() + String(" ");
			String var_value = valueId.getId() + String(" ");
			
			for(int x = 0; x < idsType.getPosition(); x++){
				ElementId k = *idsType.getKeyByPosition(x);
				String v = *idsType.getByPosition(x);
				if(x == idsType.getPosition() - 1){
					var_key += k.getId() + String("\n");
					var_value += v + String("\n");
				}else{
					var_key += k.getId() + String(",");
					var_value += v + String(",");
				}
			}
			
			text += var_key;
			text += var_value;
		}
		
		virtual void writeIdsType(ElementId i, String type){
			TextExporterLog("TextExporter", "writeIdsType",  "println", "");
			idsType.put(i, type);
			ElementId id = ElementId("transporter.idsType");
			
			if(idsType.getPosition() == 0){
				return;
			}
			
			CommandReader cmd;
			cmd.setText(text);
			
			ElementId keyId = id.child("key");
			int line_key = cmd.getCommandOrder(keyId.getId());
			cmd.removeLine(keyId.getId());
			
			ElementId valueId = id.child("value");
			int line_value = cmd.getCommandOrder(valueId.getId());
			cmd.removeLine(valueId.getId());
			
			text = cmd.getText();
			
			String var_key = keyId.getId() + String(" ");
			String var_value = valueId.getId() + String(" ");
			
			for(int x = 0; x < idsType.getPosition(); x++){
				ElementId k = *idsType.getKeyByPosition(x);
				String v = *idsType.getByPosition(x);
				if(x == idsType.getPosition() - 1){
					var_key += k.getId() + String("\n");
					var_value += v + String("\n");
				}else{
					var_key += k.getId() + String(",");
					var_value += v + String(",");
				}
			}
			
			text += var_key;
			text += var_value;
		}
		
		virtual void removeIdsType(ElementId i){
			TextExporterLog("TextExporter", "removeIdsType",  "println", "");
			if(idsType.getPosition() == 0){
				return;
			}
			if(!idsType.containKeyByLValue(i)){
				return;
			}
			idsType.removeDeleteByLValue(i);
			ElementId id = ElementId("transporter.idsType");
			CommandReader cmd;
			cmd.setText(text);
			
			ElementId keyId = id.child("key");
			cmd.removeLine(keyId.getId());
			
			ElementId valueId = id.child("value");
			cmd.removeLine(valueId.getId());
			
			text = cmd.getText();
			
			if(idsType.getPosition() == 0){
				return;
			}
			
			String var_key = keyId.getId() + String(" ");
			String var_value = valueId.getId() + String(" ");
			
			for(int x = 0; x < idsType.getPosition(); x++){
				ElementId k = *idsType.getKeyByPosition(x);
				String v = *idsType.getByPosition(x);
				if(x == idsType.getPosition() - 1){
					var_key += k.getId() + String("\n");
					var_value += v + String("\n");
				}else{
					var_key += k.getId() + String(",");
					var_value += v + String(",");
				}
			}
			
			text += var_key;
			text += var_value;
		}
		
		virtual void removeIdsType(){
			TextExporterLog("TextExporter", "removeIdsType",  "println", "");
			ElementId idKey = ElementId("transporter.idsType.key");
			ElementId idValue = ElementId("transporter.idsType.value");
			CommandReader cmd;
			cmd.setText(text);
			cmd.removeLine(idKey.getId());
			cmd.removeLine(idValue.getId());
			text = cmd.getText();
			idsType.resetDelete();
		}
		
		// virtual void fix(){
			
		// }
		
		virtual void remove(ElementId id){
			TextExporterLog("TextExporter", "remove",  "println", "");
			CommandReader cmd;
			cmd.setText(text);
			cmd.removeLine(id.getId());
			text = cmd.getText();
			removeIds(id);
			removeIdsType(id);
		}
		
		virtual void setMessage(Message* message){
			TextExporterLog("TextExporter", "setMessage",  "println", "");
			if(message == nullptr){
				return;
			}
			setText(message->text());
		}
		
		virtual void read(MonkeyFile* file, String path){
			TextExporterLog("TextExporter", "read",  "println", "");
			if(file == nullptr){
				return;
			}
			if(!file->exist(path)){
				return;
			}
			String f_text = file->readText(path);
			if(f_text == ""){
				return;
			}
			
			TextExporter f_exporter = f_text;
			
			for(int x = 0; x < f_exporter.ids.getPosition(); x++){
				ElementId i_id = f_exporter.ids[x];
				remove(i_id);
			}
			
			f_exporter.addIds(ids);
			f_exporter.addIdsType(idsType);
			
			removeIds();
			removeIdsType();
			
			text += f_exporter.getText();
		}
		
		virtual void write(MonkeyFile* file, String path){
			TextExporterLog("TextExporter", "write(file,path)",  "println", "");
			if(file == nullptr){
				TextExporterLog("TextExporter", "write(file,path)",  "println", path);
				return;
			}
			if(!file->exist(path)){
				TextExporterLog("TextExporter", "write(file,path)",  "println", "!file->exist(path)");
				TextExporterLog("TextExporter", "write(file,path)",  "println", String("path ") + path);
				file->createFile(path);
			}
			if(!file->exist(path)){
				TextExporterLog("TextExporter", "write(file,path)",  "println", "definitly no path");
				TextExporterLog("TextExporter", "write(file,path)",  "println", String("path ") + path);
				return;
			}
			String f_text = file->readText(path);
			if(f_text == ""){
				TextExporterLog("TextExporter", "write(file,path)",  "println", "!f_text");
				TextExporterLog("TextExporter", "write(file,path)",  "println", String("f_text ") + f_text);
				file->writeText(text, path);
				return;
			}
			
			TextExporter f_exporter = f_text;
			
			for(int x = 0; x < ids.getPosition(); x++){
				ElementId i_id = ids[x];
				f_exporter.remove(i_id);
			}
			TextExporterLog("TextExporter", "write(file,path)",  "println", String("f_exporter.getText() ") + f_exporter.getText());
			TextExporterLog("TextExporter", "write(file,path)",  "println", String("text ") + text);
			
			addIds(f_exporter.ids);
			addIdsType(f_exporter.idsType);
			
			TextExporterLog("TextExporter", "write(file,path)",  "println", String("f_exporter.getText() ") + f_exporter.getText());
			TextExporterLog("TextExporter", "write(file,path)",  "println", String("text ") + text);
			
			f_exporter.removeIds();
			f_exporter.removeIdsType();
			
			TextExporterLog("TextExporter", "write(file,path)",  "println", String("f_exporter.getText() ") + f_exporter.getText());
			TextExporterLog("TextExporter", "write(file,path)",  "println", String("text ") + text);
			
			file->clearFile(path);
			
			file->writeText(f_exporter.getText(), path);
			file->writeText(text, path);
			
			TextExporterLog("TextExporter", "write(file,path)",  "println", String("path ") + String(path));
			TextExporterLog("TextExporter", "write(file,path)",  "println", String("f_exporter.getText() ") + f_exporter.getText());
			TextExporterLog("TextExporter", "write(file,path)",  "println", String("text ") + text);
			TextExporterLog("TextExporter", "write(file,path)",  "println", String("file text ") + file->readText(path));
		}
		
		virtual void clear(){
			TextExporterLog("TextExporter", "clear",  "println", "");
			text = "";
			ids.resetDelete();
			idsType.resetDelete();
		}
		
		virtual void setText(String strng){
			TextExporterLog("TextExporter", "setText",  "println", String("text ") + strng);
			text = strng;
			ids = read(ElementId("transporter.ids"), PrimitiveList<ElementId>());
			idsType = read(ElementId("transporter.idsType"), PrimitiveMap<ElementId,String>());
		}
		
		virtual String getText(){
			return text;
		}
		
	protected:
		String text = "";
		PrimitiveList<ElementId> ids;
		PrimitiveMap<ElementId,String> idsType;
};

}

#endif 
