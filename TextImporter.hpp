
/**
 *
 * @author PankeyCR - Manuel Sanchez Badilla
 *
 */
 
#ifndef TextImporter_hpp
#define TextImporter_hpp

#include "ElementId.hpp"
#include "ByteArray.hpp"
#include "UUID.hpp"
#include "LinkedList.hpp"
#include "PrimitiveList.hpp"
#include "PrimitiveMap.hpp"
#include "MonkeyImporter.hpp"
#include "CommandReader.hpp"
#include "Message.hpp"

#ifdef TextImporterLogApp
	#include "Logger.hpp"
	#define TextImporterLog(name,method,type,mns) Log(name,method,type,mns)
#else
	#define TextImporterLog(name,method,type,mns)
#endif

namespace ame{

class TextImporter : public MonkeyImporter{
    public:
		TextImporter(){}
		TextImporter(const String& strng){
			setText(strng);
		}
		virtual ~TextImporter(){}
		
		// int primitive
    	virtual int read(ElementId id, int value){
			TextImporterLog("TextImporter", "read int",  "println", String(value));
			CommandReader cmd;
			cmd.setText(text);
			int x_1 = cmd.getCommandOrder(id.getId());
			if(x_1 == -1){
				return value;
			}
			return cmd.getArgument(x_1).toInt();
		}
    	virtual LinkedList<int> read(ElementId id, LinkedList<int> value){
			TextImporterLog("TextImporter", "read LinkedList int",  "println", "");
			CommandReader cmd;
			cmd.setText(text);
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
		
    	virtual PrimitiveList<int> read(ElementId id, PrimitiveList<int> value){
			TextImporterLog("TextImporter", "read PrimitiveList int",  "println", "");
			CommandReader cmd;
			cmd.setText(text);
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
		
    	// virtual PrimitiveMap<int> read(ElementId id, PrimitiveMap<int> value)=0;
		
		// ByteArray primitive
    	virtual ByteArray read(ElementId id, ByteArray value){
			TextImporterLog("TextImporter", "read ByteArray",  "println", value.toString());
			CommandReader cmd;
			cmd.setText(text);
			int x_1 = cmd.getCommandOrder(id.getId());
			if(x_1 == -1){
				return value;
			}
			return ByteArray(cmd.getArgument(x_1));
		}
		
    	virtual LinkedList<ByteArray> read(ElementId id, LinkedList<ByteArray> value){
			TextImporterLog("TextImporter", "read LinkedList ByteArray",  "println", "");
			CommandReader cmd;
			cmd.setText(text);
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
		
    	virtual PrimitiveList<ByteArray> read(ElementId id, PrimitiveList<ByteArray> value){
			TextImporterLog("TextImporter", "read PrimitiveList ByteArray",  "println", "");
			CommandReader cmd;
			cmd.setText(text);
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
    	// virtual PrimitiveMap<bool> read(ElementId id, PrimitiveMap<bool> value)=0;
		
		// bool primitive
    	virtual bool read(ElementId id, bool value){
			TextImporterLog("TextImporter", "read bool",  "println", String(value));
			CommandReader cmd;
			cmd.setText(text);
			int x_1 = cmd.getCommandOrder(id.getId());
			if(x_1 == -1){
				return value;
			}
			return cmd.getArgument(x_1) == "1";
		}
		
    	virtual LinkedList<bool> read(ElementId id, LinkedList<bool> value){
			TextImporterLog("TextImporter", "read LinkedList bool",  "println", "");
			CommandReader cmd;
			cmd.setText(text);
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
		
    	virtual PrimitiveList<bool> read(ElementId id, PrimitiveList<bool> value){
			TextImporterLog("TextImporter", "read PrimitiveList bool",  "println", "");
			CommandReader cmd;
			cmd.setText(text);
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
		
    	// virtual PrimitiveMap<bool> read(ElementId id, PrimitiveMap<bool> value)=0;
		
		// char primitive
    	virtual char read(ElementId id, char value){
			TextImporterLog("TextImporter", "read char",  "println", String(value));
			CommandReader cmd;
			cmd.setText(text);
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
		
    	virtual LinkedList<char> read(ElementId id, LinkedList<char> value){
			TextImporterLog("TextImporter", "read LinkedList char",  "println", "");
			CommandReader cmd;
			cmd.setText(text);
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
		
    	virtual PrimitiveList<char> read(ElementId id, PrimitiveList<char> value){
			TextImporterLog("TextImporter", "read PrimitiveList char",  "println", "");
			CommandReader cmd;
			cmd.setText(text);
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
		
    	// virtual PrimitiveMap<char> read(ElementId id, PrimitiveMap<char> value)=0;

		// ElementId primitive
    	virtual ElementId read(ElementId id, ElementId value){
			TextImporterLog("TextImporter", "read ElementId",  "println", value.getId());
			CommandReader cmd;
			cmd.setText(text);
			int x_1 = cmd.getCommandOrder(id.getId());
			if(x_1 == -1){
				return value;
			}
			return ElementId(cmd.getArgument(x_1));
		}
		
    	virtual PrimitiveList<ElementId> read(ElementId id, PrimitiveList<ElementId> value){
			TextImporterLog("TextImporter", "read PrimitiveList ElementId",  "println", "");
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
		

		// String primitive
    	virtual String read(ElementId id, String value){
			TextImporterLog("TextImporter", "read String",  "println", value);
			CommandReader cmd;
			cmd.setText(text);
			int x_1 = cmd.getCommandOrder(id.getId());
			if(x_1 == -1){
				return value;
			}
			return cmd.getArgument(x_1);
		}
		
    	virtual String read(ElementId id, char* value){
			TextImporterLog("TextImporter", "read char*",  "println", String(value));
			CommandReader cmd;
			cmd.setText(text);
			int x_1 = cmd.getCommandOrder(id.getId());
			if(x_1 == -1){
				return String(value);
			}
			return cmd.getArgument(x_1);
		}
		
    	virtual LinkedList<String> read(ElementId id, LinkedList<String> value){
			TextImporterLog("TextImporter", "read LinkedList String",  "println", "");
			CommandReader cmd;
			cmd.setText(text);
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
		
    	virtual PrimitiveList<String> read(ElementId id, PrimitiveList<String> value){
			TextImporterLog("TextImporter", "read PrimitiveList String",  "println", "");
			CommandReader cmd;
			cmd.setText(text);
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
		
    	
    	// virtual PrimitiveMap<String> read(ElementId id, PrimitiveMap<String> value)=0;
		
		// long primitive
    	virtual long read(ElementId id, long value){
			TextImporterLog("TextImporter", "read long",  "println", String(value));
			CommandReader cmd;
			cmd.setText(text);
			int x_1 = cmd.getCommandOrder(id.getId());
			if(x_1 == -1){
				return value;
			}
			return cmd.getArgument(x_1).toInt();
		}
		
    	virtual LinkedList<long> read(ElementId id, LinkedList<long> value){
			TextImporterLog("TextImporter", "read LinkedList long",  "println", "");
			CommandReader cmd;
			cmd.setText(text);
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
		
    	virtual PrimitiveList<long> read(ElementId id, PrimitiveList<long> value){
			TextImporterLog("TextImporter", "read PrimitiveList long",  "println", "");
			CommandReader cmd;
			cmd.setText(text);
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
		
    	// virtual PrimitiveMap<long> read(ElementId id, PrimitiveMap<long> value)=0;
		
		// UUID primitive
    	virtual UUID read(ElementId id, UUID value){
			TextImporterLog("TextImporter", "read UUID",  "println", String(value.getId()));
			CommandReader cmd;
			cmd.setText(text);
			int x_1 = cmd.getCommandOrder(id.getId());
			if(x_1 == -1){
				return value;
			}
			return UUID(cmd.getArgument(x_1).toFloat());
		}
		
    	virtual float read(ElementId id, float value){
			TextImporterLog("TextImporter", "read float",  "println", String(value));
			CommandReader cmd;
			cmd.setText(text);
			int x_1 = cmd.getCommandOrder(id.getId());
			if(x_1 == -1){
				return value;
			}
			return cmd.getArgument(x_1).toFloat();
		}
		
    	virtual LinkedList<float> read(ElementId id, LinkedList<float> value){
			TextImporterLog("TextImporter", "read LinkedList float",  "println", "");
			CommandReader cmd;
			cmd.setText(text);
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
		
    	virtual PrimitiveList<float> read(ElementId id, PrimitiveList<float> value){
			TextImporterLog("TextImporter", "read PrimitiveList float",  "println", "");
			CommandReader cmd;
			cmd.setText(text);
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
		
    	// virtual PrimitiveMap<float> read(ElementId id, PrimitiveMap<float> value)=0;
		
		// Savable primitive
    	/*virtual LinkedList<Savable> read(ElementId id, LinkedList<Savable> value)=0;
    	virtual PrimitiveList<Savable> read(ElementId id, PrimitiveList<Savable> value)=0;
    	// virtual PrimitiveMap<float> read(ElementId id, PrimitiveMap<float> value)=0;
		*/
		
    	virtual PrimitiveMap<String,bool> read(ElementId id, PrimitiveMap<String,bool> value){
			TextImporterLog("TextImporter", "read PrimitiveMap<String,bool>",  "println", "");
			CommandReader cmd;
			cmd.setText(text);
			
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
		
    	virtual PrimitiveMap<String,String> read(ElementId id, PrimitiveMap<String,String> value){
			TextImporterLog("TextImporter", "read PrimitiveMap<String,String>",  "println", "");
			CommandReader cmd;
			cmd.setText(text);
			
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
		
    	virtual PrimitiveMap<ElementId,String> read(ElementId id, PrimitiveMap<ElementId,String> value){
			TextImporterLog("TextImporter", "read PrimitiveMap<ElementId,String>",  "println", "");
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
		
		
		virtual PrimitiveList<ElementId> getIds(){
			TextImporterLog("TextImporter", "getIds",  "println", "");
			return ids;
		}
		
		virtual bool containType(ElementId id){
			TextImporterLog("TextImporter", "containType",  "println", "");
			return idsType.containKeyByLValue(id);
		}
		
		virtual String readType(ElementId id){
			TextImporterLog("TextImporter", "readType",  "println", "");
			return idsType.get(id);
		}
		
		virtual void addIds(PrimitiveList<ElementId> m_ids){
			TextImporterLog("TextImporter", "addIds",  "println", "");
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
			TextImporterLog("TextImporter", "removeIds",  "println", "");
			for(int x = 0; x < m_ids.getPosition(); x++){
				ids.removeByLValue(m_ids[x]);
			}
			if(ids.getPosition() == 0){
				return;
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
			TextImporterLog("TextImporter", "writeIds",  "println", "");
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
			TextImporterLog("TextImporter", "removeIds",  "println", "");
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
			TextImporterLog("TextImporter", "removeIds",  "println", "");
			TextImporterLog("TextImporter", "removeIds",  "println", String("start text ") + text);
			ElementId id = ElementId("transporter.ids");
			CommandReader cmd;
			cmd.setText(text);
			cmd.removeLine(id.getId());
			text = cmd.getText();
			ids.resetDelete();
			TextImporterLog("TextImporter", "removeIds",  "println", String("end text ") + text);
		}
		
		virtual void addIdsType(PrimitiveMap<ElementId,String> m_idsType){
			TextImporterLog("TextImporter", "addIdsType",  "println", "");
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
			TextImporterLog("TextImporter", "removeIdsType",  "println", "");
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
			TextImporterLog("TextImporter", "writeIdsType",  "println", "");
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
			TextImporterLog("TextImporter", "removeIdsType",  "println", "");
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
			TextImporterLog("TextImporter", "removeIdsType",  "println", "");
			TextImporterLog("TextImporter", "removeIdsType",  "println", String("start text ") + text);
			ElementId idKey = ElementId("transporter.idsType.key");
			ElementId idValue = ElementId("transporter.idsType.value");
			CommandReader cmd;
			cmd.setText(text);
			cmd.removeLine(idKey.getId());
			cmd.removeLine(idValue.getId());
			text = cmd.getText();
			idsType.resetDelete();
			TextImporterLog("TextImporter", "removeIdsType",  "println", String("end text ") + text);
		}
		
		// virtual void fix(){
			// PrimitiveList<ElementId> m_ids = read(ElementId("transporter.ids"), PrimitiveList<ElementId>());
			// PrimitiveMap<ElementId,String> m_idsType = read(ElementId("transporter.idsType"), PrimitiveMap<ElementId,String>());
			
			// String n_text = "";
			// for(int x = 0; x < m_ids.getPosition(); x++){
				
			// }
			
			// text = n_text;
		// }
		
		virtual void remove(ElementId id){
			TextImporterLog("TextImporter", "remove",  "println", "");
			CommandReader cmd;
			cmd.setText(text);
			cmd.removeLine(id.getId());
			text = cmd.getText();
			removeIds(id);
			removeIdsType(id);
		}
		
		virtual void setMessage(Message* message){
			if(message == nullptr){
				return;
			}
			setText(message->text());
		}
		
		virtual void read(MonkeyFile* file, String path){
			TextImporterLog("TextImporter", "read(file,path)",  "println", "");
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
			
			TextImporter f_importer = f_text;
			
			for(int x = 0; x < f_importer.ids.getPosition(); x++){
				ElementId i_id = f_importer.ids[x];
				remove(i_id);
			}
			
			f_importer.addIds(ids);
			f_importer.addIdsType(idsType);
			
			removeIds();
			removeIdsType();
			
			text += f_importer.getText();
		}
		
		virtual void write(MonkeyFile* file, String path){
			TextImporterLog("TextImporter", "write(file,path)",  "println", "");
			if(file == nullptr){
				TextImporterLog("TextImporter", "write(file,path)",  "println", path);
				return;
			}
			if(!file->exist(path)){
				TextImporterLog("TextImporter", "write(file,path)",  "println", "!file->exist(path)");
				TextImporterLog("TextImporter", "write(file,path)",  "println", String("path ") + path);
				file->createFile(path);
			}
			if(!file->exist(path)){
				TextImporterLog("TextImporter", "write(file,path)",  "println", "definitly no path");
				TextImporterLog("TextImporter", "write(file,path)",  "println", String("path ") + path);
				return;
			}
			String f_text = file->readText(path);
			if(f_text == ""){
				TextImporterLog("TextImporter", "write(file,path)",  "println", "!f_text");
				file->writeText(text, path);
				return;
			}
			
			TextImporter f_importer = f_text;
			
			for(int x = 0; x < ids.getPosition(); x++){
				ElementId i_id = ids[x];
				f_importer.remove(i_id);
			}
			TextImporterLog("TextImporter", "write(file,path)",  "println", String("f_importer.getText() ") + f_importer.getText());
			TextImporterLog("TextImporter", "write(file,path)",  "println", String("text ") + text);
			
			addIds(f_importer.ids);
			addIdsType(f_importer.idsType);
			
			TextImporterLog("TextImporter", "write(file,path)",  "println", String("f_importer.getText() ") + f_importer.getText());
			TextImporterLog("TextImporter", "write(file,path)",  "println", String("text ") + text);
			
			f_importer.removeIds();
			f_importer.removeIdsType();
			
			TextImporterLog("TextImporter", "write(file,path)",  "println", String("f_importer.getText() ") + f_importer.getText());
			TextImporterLog("TextImporter", "write(file,path)",  "println", String("text ") + text);
			
			file->clearFile(path);
			
			file->writeText(f_importer.getText(), path);
			file->writeText(text, path);
			
			TextImporterLog("TextImporter", "write(file,path)",  "println", String("path ") + String(path));
			TextImporterLog("TextImporter", "write(file,path)",  "println", String("f_importer.getText() ") + f_importer.getText());
			TextImporterLog("TextImporter", "write(file,path)",  "println", String("text ") + text);
			TextImporterLog("TextImporter", "write(file,path)",  "println", String("file text ") + file->readText(path));
		}
		
		virtual void clear(){
			TextImporterLog("TextImporter", "clear",  "println", "");
			text = "";
			ids.resetDelete();
			idsType.resetDelete();
		}
		
		virtual void setText(String strng){
			TextImporterLog("TextImporter", "setText",  "println", String("text ") + strng);
			text = strng;
			ids = read(ElementId("transporter.ids"), PrimitiveList<ElementId>());
			idsType = read(ElementId("transporter.idsType"), PrimitiveMap<ElementId,String>());
		}
		
		virtual String getText(){
			return text;
		}
		
	protected:
		String text;
		PrimitiveList<ElementId> ids;
		PrimitiveMap<ElementId,String> idsType;
};

}

#endif 
