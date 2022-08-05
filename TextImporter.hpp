
/**
 *
 * @author PankeyCR - Manuel Sanchez Badilla
 *
 */
 
#include "ame_Enviroment.hpp"

#if defined(DISABLE_TextImporter)
	#define TextImporter_hpp
#endif

#ifndef TextImporter_hpp
#define TextImporter_hpp
#define TextImporter_AVAILABLE

#ifndef ame_Enviroment_Defined

#endif

#ifdef ame_Windows

#endif

#ifdef ame_ArduinoIDE
	#include "Arduino.h"
#endif

#include "ElementId.hpp"
#include "ByteArray.hpp"
// #include "LinkedList.hpp"
#include "PrimitiveList.hpp"
#include "PrimitiveMap.hpp"
#include "MonkeyImporter.hpp"
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
		TextImporter(const Note& strng){
			setText(strng);
		}
		virtual ~TextImporter(){}
		
		// int primitive
    	virtual int read(ElementId id, int value){
			TextImporterLog("TextImporter", "read int",  "println", Note(value));
			int x_1 = text.getOrder(id.getId(), m_split, m_end);
			if(x_1 == -1){
				TextImporterLog("TextImporter", "read int",  "println", "id line position = -1");
				return value;
			}
			TextImporterLog("TextImporter", "read int",  "println", Note("argument ") + cmd.getArgument(x_1));
			return text.getArgument(x_1, m_split, m_end).toInt();
		}
		
    	// virtual LinkedList<int> read(ElementId id, LinkedList<int> value){
			// TextImporterLog("TextImporter", "read LinkedList int",  "println", "");
			
			// int x_1 = text.getOrder(id.getId(), m_split, m_end);
			// if(x_1 == -1){
				// return value;
			// }
			// Note arg = text.getArgument(x_1, m_split, m_end);
			// LinkedList<int> list;
			// int s = arg.getSizeNoStartNoEnd( m_list_divide );
			// for(int x = 0; x < s; x++){
				// int t = arg.split(x, m_list_divide).toInt();
				// list.addLValue(t);
			// }
			// return list;
		// }
		
    	virtual PrimitiveList<int> read(ElementId id, PrimitiveList<int> value){
			TextImporterLog("TextImporter", "read PrimitiveList int",  "println", "");
			
			int x_1 = text.getOrder(id.getId(), m_split, m_end);
			if(x_1 == -1){
				return value;
			}
			Note arg = text.getArgument(x_1, m_split, m_end);
			PrimitiveList<int> list;
			int s = arg.getSizeNoStartNoEnd( m_list_divide );
			for(int x = 0; x < s; x++){
				int t = arg.split(x, m_list_divide).toInt();
				list.addLValue(t);
			}
			return list;
		}
		
    	// virtual PrimitiveMap<int> read(ElementId id, PrimitiveMap<int> value)=0;
		
		// ByteArray primitive
    	virtual ByteArray read(ElementId id, ByteArray value){
			TextImporterLog("TextImporter", "read ByteArray",  "println", value.toNote());
			
			int x_1 = text.getOrder(id.getId(), m_split, m_end);
			if(x_1 == -1){
				return value;
			}
			return ByteArray(text.getArgument(x_1, m_split, m_end));
		}
		
    	// virtual LinkedList<ByteArray> read(ElementId id, LinkedList<ByteArray> value){
			// TextImporterLog("TextImporter", "read LinkedList ByteArray",  "println", "");
			
			// int x_1 = text.getOrder(id.getId(), m_split, m_end);
			// if(x_1 == -1){
				// return value;
			// }
			// Note arg = text.getArgument(x_1, m_split, m_end);
			// LinkedList<ByteArray> list;
			// int s = arg.getSizeNoStartNoEnd( m_list_divide );
			// for(int x = 0; x < s; x++){
				// ByteArray t = arg.split(x, m_list_divide);
				// list.addLValue(t);
			// }
			// return list;
		// }
		
    	virtual PrimitiveList<ByteArray> read(ElementId id, PrimitiveList<ByteArray> value){
			TextImporterLog("TextImporter", "read PrimitiveList ByteArray",  "println", "");
			
			int x_1 = text.getOrder(id.getId(), m_split, m_end);
			if(x_1 == -1){
				return value;
			}
			Note arg = text.getArgument(x_1, m_split, m_end);
			PrimitiveList<ByteArray> list;
			int s = arg.getSizeNoStartNoEnd( m_list_divide );
			for(int x = 0; x < s; x++){
				ByteArray t = arg.split(x, m_list_divide);
				list.addLValue(t);
			}
			return list;
		}
    	// virtual PrimitiveMap<bool> read(ElementId id, PrimitiveMap<bool> value)=0;
		
		// bool primitive
    	virtual bool read(ElementId id, bool value){
			TextImporterLog("TextImporter", "read bool",  "println", Note(value));
			
			int x_1 = text.getOrder(id.getId(), m_split, m_end);
			if(x_1 == -1){
				return value;
			}
			return text.getArgument(x_1, m_split, m_end) == "1";
		}
		
    	// virtual LinkedList<bool> read(ElementId id, LinkedList<bool> value){
			// TextImporterLog("TextImporter", "read LinkedList bool",  "println", "");
			
			// int x_1 = text.getOrder(id.getId(), m_split, m_end);
			// if(x_1 == -1){
				// return value;
			// }
			// Note arg = text.getArgument(x_1, m_split, m_end);
			// LinkedList<bool> list;
			// int s = arg.getSizeNoStartNoEnd(m_list_divide);
			// for(int x = 0; x < s; x++){
				// bool t = arg.split(x, m_list_divide) == "1";
				// list.addLValue(t);
			// }
			// return list;
		// }
		
    	virtual PrimitiveList<bool> read(ElementId id, PrimitiveList<bool> value){
			TextImporterLog("TextImporter", "read PrimitiveList bool",  "println", "");
			
			int x_1 = text.getOrder(id.getId(), m_split, m_end);
			if(x_1 == -1){
				return value;
			}
			Note arg = text.getArgument(x_1, m_split, m_end);
			PrimitiveList<bool> list;
			int s = arg.getSizeNoStartNoEnd( m_list_divide );
			for(int x = 0; x < s; x++){
				bool t = arg.split(x, m_list_divide) == "1";
				list.addLValue(t);
			}
			return list;
		}
		
    	// virtual PrimitiveMap<bool> read(ElementId id, PrimitiveMap<bool> value)=0;
		
		// char primitive
    	virtual char read(ElementId id, char value){
			TextImporterLog("TextImporter", "read char",  "println", Note(value));
			
			int x_1 = text.getOrder(id.getId(), m_split, m_end);
			if(x_1 == -1){
				return value;
			}
			Note r = text.getArgument(x_1, m_split, m_end);
			if(r.length() == 0){
				return value;
			}
			return r.charAt(0);
		}
		
    	// virtual LinkedList<char> read(ElementId id, LinkedList<char> value){
			// TextImporterLog("TextImporter", "read LinkedList char",  "println", "");
			
			// int x_1 = text.getOrder(id.getId(), m_split, m_end);
			// if(x_1 == -1){
				// return value;
			// }
			// Note arg = text.getArgument(x_1, m_split, m_end);
			// LinkedList<char> list;
			// int s = arg.getSizeNoStartNoEnd( m_list_divide );
			// for(int x = 0; x < s; x++){
				// Note tt = arg.split(x, m_list_divide);
				// if(tt == ""){
					// return value;
				// }
				// char t = tt.charAt(0);
				// list.addLValue(t);
			// }
			// return list;
		// }
		
    	virtual PrimitiveList<char> read(ElementId id, PrimitiveList<char> value){
			TextImporterLog("TextImporter", "read PrimitiveList char",  "println", "");
			
			int x_1 = text.getOrder(id.getId(), m_split, m_end);
			if(x_1 == -1){
				return value;
			}
			Note arg = text.getArgument(x_1, m_split, m_end);
			PrimitiveList<char> list;
			int s = arg.getSizeNoStartNoEnd( m_list_divide );
			for(int x = 0; x < s; x++){
				Note tt = arg.split(x, m_list_divide);
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
			
			int x_1 = text.getOrder(id.getId(), m_split, m_end);
			if(x_1 == -1){
				return value;
			}
			return ElementId(text.getArgument(x_1, m_split, m_end));
		}
		
    	virtual PrimitiveList<ElementId> read(ElementId id, PrimitiveList<ElementId> value){
			TextImporterLog("TextImporter", "read PrimitiveList ElementId",  "println", "");
			
			int x_1 = text.getOrder(id.getId(), m_split, m_end);
			if(x_1 == -1){
				return value;
			}
			Note arg = text.getArgument(x_1, m_split, m_end);
			PrimitiveList<ElementId> list;
			int s = arg.getSizeNoStartNoEnd( m_list_divide );
			for(int x = 0; x < s; x++){
				ElementId t = arg.split(x, m_list_divide);
				list.addLValue(t);
			}
			return list;
		}
		

		// Note primitive
    	virtual Note read(ElementId id, Note value){
			TextImporterLog("TextImporter", "read Note",  "println", value);
			
			int x_1 = text.getOrder(id.getId(), m_split, m_end);
			if(x_1 == -1){
				return value;
			}
			return text.getArgument(x_1, m_split, m_end);
		}
		
    	virtual Note read(ElementId id, char* value){
			TextImporterLog("TextImporter", "read char*",  "println", Note(value));
			
			int x_1 = text.getOrder(id.getId(), m_split, m_end);
			if(x_1 == -1){
				return Note(value);
			}
			return text.getArgument(x_1, m_split, m_end);
		}
		
    	// virtual LinkedList<Note> read(ElementId id, LinkedList<Note> value){
			// TextImporterLog("TextImporter", "read LinkedList Note",  "println", "");
			
			// int x_1 = text.getOrder(id.getId(), m_split, m_end);
			// if(x_1 == -1){
				// return value;
			// }
			// Note arg = text.getArgument(x_1, m_split, m_end);
			// LinkedList<Note> list;
			// int s = arg.getSizeNoStartNoEnd( m_list_divide );
			// for(int x = 0; x < s; x++){
				// Note t = arg.split(x, m_list_divide);
				// list.addLValue(t);
			// }
			// return list;
		// }
		
    	virtual PrimitiveList<Note> read(ElementId id, PrimitiveList<Note> value){
			TextImporterLog("TextImporter", "read PrimitiveList Note",  "println", "");
			
			int x_1 = text.getOrder(id.getId(), m_split, m_end);
			if(x_1 == -1){
				return value;
			}
			Note arg = text.getArgument(x_1, m_split, m_end);
			PrimitiveList<Note> list;
			int s = arg.getSizeNoStartNoEnd( m_list_divide );
			for(int x = 0; x < s; x++){
				Note t = arg.split(x, m_list_divide);
				list.addLValue(t);
			}
			return list;
		}
		
    	
    	// virtual PrimitiveMap<Note> read(ElementId id, PrimitiveMap<Note> value)=0;
		
		// long primitive
    	virtual long read(ElementId id, long value){
			TextImporterLog("TextImporter", "read long",  "println", Note(value));
			
			int x_1 = text.getOrder(id.getId(), m_split, m_end);
			if(x_1 == -1){
				return value;
			}
			return text.getArgument(x_1, m_split, m_end).toInt();
		}
		
    	// virtual LinkedList<long> read(ElementId id, LinkedList<long> value){
			// TextImporterLog("TextImporter", "read LinkedList long",  "println", "");
			
			// int x_1 = text.getOrder(id.getId(), m_split, m_end);
			// if(x_1 == -1){
				// return value;
			// }
			// Note arg = text.getArgument(x_1, m_split, m_end);
			// LinkedList<long> list;
			// int s = arg.getSizeNoStartNoEnd( m_list_divide );
			// for(int x = 0; x < s; x++){
				// long t = arg.split(x, m_list_divide).toInt();
				// list.addLValue(t);
			// }
			// return list;
		// }
		
    	virtual PrimitiveList<long> read(ElementId id, PrimitiveList<long> value){
			TextImporterLog("TextImporter", "read PrimitiveList long",  "println", "");
			
			int x_1 = text.getOrder(id.getId(), m_split, m_end);
			if(x_1 == -1){
				return value;
			}
			Note arg = text.getArgument(x_1, m_split, m_end);
			PrimitiveList<long> list;
			int s = arg.getSizeNoStartNoEnd( m_list_divide );
			for(int x = 0; x < s; x++){
				long t = arg.split(x, m_list_divide).toInt();
				list.addLValue(t);
			}
			return list;
		}
		
    	// virtual PrimitiveMap<long> read(ElementId id, PrimitiveMap<long> value)=0;
		
    	virtual float read(ElementId id, float value){
			TextImporterLog("TextImporter", "read float",  "println", Note(value));
			
			int x_1 = text.getOrder(id.getId(), m_split, m_end);
			if(x_1 == -1){
				return value;
			}
			return text.getArgument(x_1, m_split, m_end).toFloat();
		}
		
    	// virtual LinkedList<float> read(ElementId id, LinkedList<float> value){
			// TextImporterLog("TextImporter", "read LinkedList float",  "println", "");
			
			// int x_1 = text.getOrder(id.getId(), m_split, m_end);
			// if(x_1 == -1){
				// return value;
			// }
			// Note arg = text.getArgument(x_1, m_split, m_end);
			// LinkedList<float> list;
			// int s = arg.getSizeNoStartNoEnd( m_list_divide);
			// for(int x = 0; x < s; x++){
				// float t = arg.split(x, m_list_divide).toFloat();
				// list.addLValue(t);
			// }
			// return list;
		// }
		
    	virtual PrimitiveList<float> read(ElementId id, PrimitiveList<float> value){
			TextImporterLog("TextImporter", "read PrimitiveList float",  "println", "");
			
			int x_1 = text.getOrder(id.getId(), m_split, m_end);
			if(x_1 == -1){
				return value;
			}
			Note arg = text.getArgument(x_1, m_split, m_end);
			PrimitiveList<float> list;
			int s = arg.getSizeNoStartNoEnd( m_list_divide );
			for(int x = 0; x < s; x++){
				float t = arg.split(x, m_list_divide).toFloat();
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
		
    	virtual PrimitiveMap<Note,bool> read(ElementId id, PrimitiveMap<Note,bool> value){
			TextImporterLog("TextImporter", "read PrimitiveMap<Note,bool>",  "println", "");
			
			int x_key = text.getOrder(id.child("key").getId(), m_split, m_end);
			int x_value = text.getOrder(id.child("value").getId(), m_split, m_end);
			if(x_key == -1 || x_value == -1){
				return value;
			}
			
			Note arg_key = text.getArgument(x_key, m_split, m_end);
			Note arg_value = text.getArgument(x_value, m_split, m_end);
			
			PrimitiveMap<Note,bool> map;
			
			int s_key = arg_key.getSizeNoStartNoEnd( m_list_divide );
			int s_value = arg_value.getSizeNoStartNoEnd( m_list_divide );
			if(s_key != s_value){
				return value;
			}
			
			for(int x = 0; x < s_key; x++){
				Note k = arg_key.split(x, m_list_divide);
				bool v = arg_value.split(x, m_list_divide) == "1";
				map.addLValues(k,v);
			}
			return map;
		}
		
    	virtual PrimitiveMap<Note,Note> read(ElementId id, PrimitiveMap<Note,Note> value){
			TextImporterLog("TextImporter", "read PrimitiveMap<Note,Note>",  "println", "");
			
			int x_key = text.getOrder(id.child("key").getId(), m_split, m_end);
			int x_value = text.getOrder(id.child("value").getId(), m_split, m_end);
			if(x_key == -1 || x_value == -1){
				return value;
			}
			
			Note arg_key = text.getArgument(x_key, m_split, m_end);
			Note arg_value = text.getArgument(x_value, m_split, m_end);
			
			PrimitiveMap<Note,Note> map;
			
			int s_key = arg_key.getSizeNoStartNoEnd( m_list_divide );
			int s_value = arg_value.getSizeNoStartNoEnd( m_list_divide );
			if(s_key != s_value){
				return value;
			}
			
			for(int x = 0; x < s_key; x++){
				Note k = arg_key.split(x, m_list_divide);
				Note v = arg_value.split(x, m_list_divide);
				map.addLValues(k,v);
			}
			return map;
		}
		
    	virtual PrimitiveMap<ElementId,Note> read(ElementId id, PrimitiveMap<ElementId,Note> value){
			TextImporterLog("TextImporter", "read PrimitiveMap<ElementId,Note>",  "println", "");
			
			int x_key = text.getOrder(id.child("key").getId(), m_split, m_end);
			int x_value = text.getOrder(id.child("value").getId(), m_split, m_end);
			if(x_key == -1 || x_value == -1){
				return value;
			}
			
			Note arg_key = text.getArgument(x_key, m_split, m_end);
			Note arg_value = text.getArgument(x_value, m_split, m_end);
			
			PrimitiveMap<ElementId,Note> map;
			
			int s_key = arg_key.getSizeNoStartNoEnd( m_list_divide );
			int s_value = arg_value.getSizeNoStartNoEnd( m_list_divide );
			if(s_key != s_value){
				return value;
			}
			
			for(int x = 0; x < s_key; x++){
				ElementId k = ElementId(arg_key.split(x, m_list_divide));
				Note v = arg_value.split(x, ',');
				map.addLValues(k,v);
			}
			return map;
		}
		
		virtual void remove(ElementId id){
			TextImporterLog("TextExporter", "remove",  "println", "");
			
			text.removeLine(id.getId(), m_split, m_end);
		}
		
		virtual void clear(){
			TextImporterLog("TextImporter", "clear",  "println", "");
			text = "";
		}
		
		/////////////////////////////////////////////////////////////////// ids
		virtual void addId(ElementId m_id){
			TextImporterLog("TextImporter", "addId",  "println", "");
			ids.add(m_id);
		}
		
		virtual void addIds(PrimitiveList<ElementId>& m_ids){
			TextImporterLog("TextImporter", "addIds",  "println", "");
			for(int x = 0; x < m_ids.getPosition(); x++){
				ElementId* l_eid = m_ids.getByPosition(x);
				ids.addLValue(*l_eid);
			}
		}
		
		virtual bool containId(ElementId m_id){
			TextImporterLog("TextImporter", "containId",  "println", "");
			return ids.containByLValue(m_id);
		}
		
		virtual PrimitiveList<ElementId>& getIds(){
			TextImporterLog("TextImporter", "getIds",  "println", "");
			return ids;
		}
		
		virtual ElementId getId(int x){
			TextImporterLog("TextImporter", "getId",  "println", "");
			if(x >= ids.getPosition()){
				return ElementId();
			}
			return ids[x];
		}
		
		virtual int getIdSize(){
			TextImporterLog("TextImporter", "getIdSize",  "println", "");
			return ids.getPosition();
		}
		
		virtual void removeId(ElementId i_id){
			TextImporterLog("TextImporter", "removeId",  "println", "");
			ids.removeDeleteByLValue(i_id);
		}
		
		virtual void removeIds(PrimitiveList<ElementId>& i_ids){
			TextImporterLog("TextImporter", "removeIds",  "println", "");
			for(int x = 0; x < i_ids.getPosition(); x++){
				ElementId* l_eid = i_ids.getByPosition(x);
				ids.removeDeleteByLValue(*l_eid);
			}
		}
		
		virtual void removeIds(){
			TextImporterLog("TextImporter", "removeIds",  "println", "");
			ids.resetDelete();
		}
		
		virtual void writeIds(){
			TextImporterLog("TextImporter", "writeIds",  "println", "");
			
			if(ids.getPosition() == 0){
				TextImporterLog("TextImporter", "writeIds",  "println", "ids.isEmpty");
				idText = "";
				return;
			}
			ElementId id = ElementId("transporter.ids");
			
			idText = id.getId() + Note(" ");
			for(int x = 0; x < ids.getPosition(); x++){
				ElementId v = *ids.getByPosition(x);
				if(x == ids.getPosition() - 1){
					idText += v.getId() + Note("\n");
				}else{
					idText += v.getId() + Note(",");
				}
			}
		}
		
		virtual void writeId(ElementId value){
			TextImporterLog("TextImporter", "writeId",  "println", "");
			ids.put(value);
			ElementId id = ElementId("transporter.ids");
			
			idText = id.getId() + Note(" ");
			for(int x = 0; x < ids.getPosition(); x++){
				ElementId v = *ids.getByPosition(x);
				if(x == ids.getPosition() - 1){
					idText += v.getId() + Note("\n");
				}else{
					idText += v.getId() + Note(",");
				}
			}
		}
		
		virtual void eraseId(ElementId value){
			TextImporterLog("TextImporter", "eraseId",  "println", "");
			if(ids.getPosition() == 0){
				return;
			}
			if(!ids.containByLValue(value)){
				return;
			}
			
			ids.removeDeleteByLValue(value);
			if(ids.getPosition() == 0){
				return;
			}
			
			ElementId id = ElementId("transporter.ids");
			
			idText = id.getId() + Note(" ");
			for(int x = 0; x < ids.getPosition(); x++){
				ElementId v = *ids.getByPosition(x);
				if(x == ids.getPosition() - 1){
					idText += v.getId() + Note("\n");
				}else{
					idText += v.getId() + Note(",");
				}
			}
		}
		
		virtual void eraseIds(){
			TextImporterLog("TextImporter", "eraseIds",  "println", "");
			idText = "";
		}
		
		virtual void clearIds(){
			TextImporterLog("TextImporter", "clearIds",  "println", "");
			idText = "";
			ids.resetDelete();
		}
		
		/////////////////////////////////////////////////////////////////// idType
		virtual void addIdType(ElementId m_id, Note m_type){
			TextImporterLog("TextImporter", "addIdType",  "println", "");
			idsType.addLValues(m_id, m_type);
		}
		
		virtual void addIdType(PrimitiveMap<ElementId,Note>& m_idsType){
			TextImporterLog("TextImporter", "addIdType",  "println", "");
			for(int x = 0; x < m_idsType.getPosition(); x++){
				idsType.addLValues(m_idsType.getKey(x), m_idsType.getValue(x));
			}
		}
		
		virtual bool containIdType(ElementId id){
			TextImporterLog("TextImporter", "containIdType",  "println", "");
			return idsType.containKeyByLValue(id);
		}
		
		virtual PrimitiveMap<ElementId,Note>& getIdTypes(){
			TextImporterLog("TextImporter", "getIdTypes",  "println", "");
			return idsType;
		}
		
		virtual Note getIdType(ElementId id){
			TextImporterLog("TextImporter", "getIdType",  "println", "");
			return idsType.get(id);
		}
		
		virtual int getIdTypeSize(){
			TextImporterLog("TextImporter", "getIdTypeSize",  "println", "");
			return idsType.getPosition();
		}
		
		virtual void removeIdType(ElementId m_id){
			TextImporterLog("TextImporter", "removeIdType",  "println", "");
			idsType.removeDeleteByLValue(m_id);
		}
		
		virtual void removeIdTypes(PrimitiveMap<ElementId,Note>& m_idsType){
			TextImporterLog("TextImporter", "removeIdTypes",  "println", "");
			for(int x = 0; x < m_idsType.getPosition(); x++){
				idsType.removeDeleteByLValue(m_idsType.getKey(x));
			}
		}
		
		virtual void removeIdTypes(){
			TextImporterLog("TextImporter", "removeIdTypes",  "println", "");
			idsType.resetDelete();
		}
		
		virtual void writeIdTypes(){
			TextImporterLog("TextImporter", "writeIdTypes",  "println", "");
			if(idsType.getPosition() == 0){
				TextImporterLog("TextImporter", "writeIdTypes",  "println", "idsType.isEmpty");
				idTypeText = "";
				return;
			}
			
			ElementId id = ElementId("transporter.idsType");
			
			ElementId keyId = id.child("key");
			
			ElementId valueId = id.child("value");
			
			Note var_key = keyId.getId() + Note(" ");
			Note var_value = valueId.getId() + Note(" ");
			
			for(int x = 0; x < idsType.getPosition(); x++){
				ElementId k = *idsType.getKeyByPosition(x);
				Note v = *idsType.getByPosition(x);
				if(x == idsType.getPosition() - 1){
					var_key += k.getId() + Note("\n");
					var_value += v + Note("\n");
				}else{
					var_key += k.getId() + Note(",");
					var_value += v + Note(",");
				}
			}
			
			idTypeText += var_key;
			idTypeText += var_value;
		}
		
		virtual void writeIdType(ElementId i_id, Note type){
			TextImporterLog("TextImporter", "writeIdType",  "println", "");
			
			idsType.addLValues(i_id, type);
			
			ElementId id = ElementId("transporter.idsType");
			
			ElementId keyId = id.child("key");
			
			ElementId valueId = id.child("value");
			
			Note var_key = keyId.getId() + Note(" ");
			Note var_value = valueId.getId() + Note(" ");
			
			for(int x = 0; x < idsType.getPosition(); x++){
				ElementId k = *idsType.getKeyByPosition(x);
				Note v = *idsType.getByPosition(x);
				if(x == idsType.getPosition() - 1){
					var_key += k.getId() + Note("\n");
					var_value += v + Note("\n");
				}else{
					var_key += k.getId() + Note(",");
					var_value += v + Note(",");
				}
			}
			
			idTypeText += var_key;
			idTypeText += var_value;
		}
		
		virtual void eraseIdType(ElementId i_id){
			TextImporterLog("TextImporter", "eraseIdType",  "println", "");
			idsType.removeDeleteByLValue(i_id);
			
			if(idsType.getPosition() == 0){
				idTypeText = "";
				return;
			}
			
			ElementId id = ElementId("transporter.idsType");
			
			ElementId keyId = id.child("key");
			
			ElementId valueId = id.child("value");
			
			Note var_key = keyId.getId() + Note(" ");
			Note var_value = valueId.getId() + Note(" ");
			
			for(int x = 0; x < idsType.getPosition(); x++){
				ElementId k = *idsType.getKeyByPosition(x);
				Note v = *idsType.getByPosition(x);
				if(x == idsType.getPosition() - 1){
					var_key += k.getId() + Note("\n");
					var_value += v + Note("\n");
				}else{
					var_key += k.getId() + Note(",");
					var_value += v + Note(",");
				}
			}
			
			idTypeText += var_key;
			idTypeText += var_value;
		}
		
		virtual void eraseIdTypes(){
			TextImporterLog("TextImporter", "eraseIdTypes",  "println", "");
			idTypeText = "";
		}
		
		virtual void clearIdTypes(){
			TextImporterLog("TextImporter", "clearIds",  "println", "");
			idTypeText = "";
			idsType.resetDelete();
		}
		
		/////////////////////////////////////////////////////////////////// tags
		virtual void addTag(ElementId m_id, Note m_type){
			TextImporterLog("TextImporter", "addTag",  "println", "");
			tags.addLValues(m_id, m_type);
		}
		
		virtual void addTag(PrimitiveMap<ElementId,Note>& m_idsType){
			TextImporterLog("TextImporter", "addTag",  "println", "");
			for(int x = 0; x < m_idsType.getPosition(); x++){
				tags.addLValues(m_idsType.getKey(x), m_idsType.getValue(x));
			}
		}
		
		virtual bool containTag(ElementId id){
			TextImporterLog("TextImporter", "containTag",  "println", "");
			return tags.containKeyByLValue(id);
		}
		
		virtual PrimitiveMap<ElementId,Note>& getTags(){
			TextImporterLog("TextImporter", "getTags",  "println", "");
			return tags;
		}
		
		virtual Note getTag(ElementId id){
			TextImporterLog("TextImporter", "getTag",  "println", "");
			return tags.get(id);
		}
		
		virtual int getTagSize(){
			TextImporterLog("TextImporter", "getTagSize",  "println", "");
			return tags.getPosition();
		}
		
		virtual void removeTag(ElementId m_id){
			TextImporterLog("TextImporter", "removeTag",  "println", "");
			tags.removeDeleteByLValue(m_id);
		}
		
		virtual void removeTags(PrimitiveMap<ElementId,Note>& m_idsType){
			TextImporterLog("TextImporter", "removeTags",  "println", "");
			for(int x = 0; x < m_idsType.getPosition(); x++){
				tags.removeDeleteByLValue(m_idsType.getKey(x));
			}
		}
		
		virtual void removeTags(){
			TextImporterLog("TextImporter", "removeTags",  "println", "");
			tags.resetDelete();
		}
		
		virtual void writeTags(){
			TextImporterLog("TextImporter", "writeTags",  "println", "");
			if(tags.getPosition() == 0){
				TextImporterLog("TextImporter", "writeTags",  "println", "tags.isEmpty");
				tagText = "";
				return;
			}
			
			ElementId id = ElementId("transporter.tags");
			
			ElementId keyId = id.child("key");
			
			ElementId valueId = id.child("value");
			
			Note var_key = keyId.getId() + Note(" ");
			Note var_value = valueId.getId() + Note(" ");
			
			for(int x = 0; x < tags.getPosition(); x++){
				ElementId k = *tags.getKeyByPosition(x);
				Note v = *tags.getByPosition(x);
				if(x == tags.getPosition() - 1){
					var_key += k.getId() + Note("\n");
					var_value += v + Note("\n");
				}else{
					var_key += k.getId() + Note(",");
					var_value += v + Note(",");
				}
			}
			
			tagText += var_key;
			tagText += var_value;
		}
		
		virtual void writeTag(ElementId i_id, Note type){
			TextImporterLog("TextImporter", "writeTag",  "println", "");
			
			tags.addLValues(i_id, type);
			
			ElementId id = ElementId("transporter.tags");
			
			ElementId keyId = id.child("key");
			
			ElementId valueId = id.child("value");
			
			Note var_key = keyId.getId() + Note(" ");
			Note var_value = valueId.getId() + Note(" ");
			
			for(int x = 0; x < tags.getPosition(); x++){
				ElementId k = *tags.getKeyByPosition(x);
				Note v = *tags.getByPosition(x);
				if(x == tags.getPosition() - 1){
					var_key += k.getId() + Note("\n");
					var_value += v + Note("\n");
				}else{
					var_key += k.getId() + Note(",");
					var_value += v + Note(",");
				}
			}
			
			tagText += var_key;
			tagText += var_value;
		}
		
		virtual void eraseTag(ElementId i_id){
			TextImporterLog("TextImporter", "eraseTag",  "println", "");
			tags.removeDeleteByLValue(i_id);
			
			if(tags.getPosition() == 0){
				tagText = "";
				return;
			}
			
			ElementId id = ElementId("transporter.tags");
			
			ElementId keyId = id.child("key");
			
			ElementId valueId = id.child("value");
			
			Note var_key = keyId.getId() + Note(" ");
			Note var_value = valueId.getId() + Note(" ");
			
			for(int x = 0; x < tags.getPosition(); x++){
				ElementId k = *tags.getKeyByPosition(x);
				Note v = *tags.getByPosition(x);
				if(x == tags.getPosition() - 1){
					var_key += k.getId() + Note("\n");
					var_value += v + Note("\n");
				}else{
					var_key += k.getId() + Note(",");
					var_value += v + Note(",");
				}
			}
			
			tagText += var_key;
			tagText += var_value;
		}
		
		virtual void eraseTags(){
			TextImporterLog("TextImporter", "eraseIdType",  "println", "");
			tagText = "";
		}
		
		virtual void clearTags(){
			TextImporterLog("TextImporter", "clearIds",  "println", "");
			tagText = "";
			tags.resetDelete();
		}
		
		virtual void setMessage(Message* message){
			TextImporterLog("TextImporter", "setMessage",  "println", "");
			if(message == nullptr){
				return;
			}
			setText(message->text());
			fix();
		}
		
		virtual void read(MonkeyFile* file, Note path){
			TextImporterLog("TextImporter", "read",  "println", "");
			if(file == nullptr){
				return;
			}
			setText( file->readText(path) );
			fix();
		}
		
		virtual void write(MonkeyFile* file, Note path){
			TextImporterLog("TextImporter", "write(file,path)",  "println", "");
			if(file == nullptr){
				TextImporterLog("TextImporter", "write(file,path)",  "println", path);
				return;
			}
			// file->fastWriteText(tagText, path);
			// file->fastWriteText(idText, path);
			// file->fastWriteText(idTypeText, path);
			// file->fastWriteText(text, path);
			
			file->fastWriteText(tagText + idText + idTypeText+ text, path);
		}
		
		virtual void setText(Note strng){
			TextImporterLog("TextImporter", "setText",  "println", Note("text ") + strng);
			text = strng;
		}
		
		virtual Note getText(){
			return text;
		}
		
		virtual void setIdText(Note strng){
			TextImporterLog("TextImporter", "setIdText",  "println", Note("text ") + strng);
			text = strng;
		}
		
		virtual Note getIdText(){
			return text;
		}
		
		virtual void setIdTypeText(Note strng){
			TextImporterLog("TextImporter", "setIdTypeText",  "println", Note("text ") + strng);
			text = strng;
		}
		
		virtual Note getIdTypeText(){
			return text;
		}
		
		virtual void setTagText(Note strng){
			TextImporterLog("TextImporter", "setTagText",  "println", Note("text ") + strng);
			text = strng;
		}
		
		virtual Note getTagText(){
			return text;
		}
		
		virtual Note getExporterText(){
			return tagText + idText + idTypeText + text;
		}
		
		virtual void fix(){
			TextImporterLog("TextImporter", "fix",  "println", "");
			ids = read(ElementId("transporter.ids"), PrimitiveList<ElementId>());
			idsType = read(ElementId("transporter.idsType"), PrimitiveMap<ElementId,Note>());
			tags = read(ElementId("transporter.tags"), PrimitiveMap<ElementId,Note>());
			
			eraseIds();
			eraseIdTypes();
			eraseTags();
			
			writeIds();
			writeIdTypes();
			writeTags();
			
			remove("transporter.tags.key");
			remove("transporter.tags.value");
			
			remove("transporter.ids.key");
			remove("transporter.ids.value");
			
			remove("transporter.idsType.key");
			remove("transporter.idsType.value");
			
			TextImporterLog("TextImporter", "fix",  "println", Note("tagText ") + tagText);
			TextImporterLog("TextImporter", "fix",  "println", Note("idText ") + idText);
			TextImporterLog("TextImporter", "fix",  "println", Note("idTypeText ") + idTypeText);
			TextImporterLog("TextImporter", "fix",  "println", Note("text ") + text);
		}
		
		virtual Note toNote(){
			return tagText + idText + idTypeText + text;
		}
		
	protected:
		Note text = "";
		Note idText = "";
		Note idTypeText = "";
		Note tagText = "";
		PrimitiveList<ElementId> ids;
		PrimitiveMap<ElementId,Note> idsType;
		PrimitiveMap<ElementId,Note> tags;
		
		char m_list_divide = ',';
		char m_split = ' ';
		char m_end = '\n';
};

}

#endif