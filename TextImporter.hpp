
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
#include "LinkedList.hpp"
#include "PrimitiveList.hpp"
#include "PrimitiveMap.hpp"
#include "MonkeyImporter.hpp"
#include "Message.hpp"

#ifdef TextImporter_LogApp
	#include "ame_Logger_config.hpp"
	#include "ame_Logger.hpp"
	
	#define TextImporterLog(location,method,type,mns) ame_Log(this,location,"TextImporter",method,type,mns)
#else
	#ifdef TextImporter_LogDebugApp
		#include "ame_Logger_config.hpp"
		#include "ame_Logger.hpp"
		
		#define TextImporterLog(location,method,type,mns) ame_LogDebug(this,location,"TextImporter",method,type)
	#else
		#define TextImporterLog(location,method,type,mns) 
	#endif
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
			TextImporterLog(ame_Log_StartMethod, "read int",  "println", Note(value));
			int x_1 = text.getOrder(id.getId(), m_split, m_end);
			if(x_1 == -1){
				TextImporterLog(ame_Log_StartMethod, "read int",  "println", "id line position = -1");
				return value;
			}
			TextImporterLog(ame_Log_StartMethod, "read int",  "println", Note("argument ") + cmd.getArgument(x_1));
			return text.getArgument(x_1, m_split, m_end).toInt();
		}
		
    	virtual LinkedList<int> read(ElementId id, LinkedList<int> value){
			TextImporterLog(ame_Log_StartMethod, "read LinkedList int",  "println", "");
			
			int x_1 = text.getOrder(id.getId(), m_split, m_end);
			if(x_1 == -1){
				return value;
			}
			Note arg = text.getArgument(x_1, m_split, m_end);
			LinkedList<int> list;
			int s = arg.getSizeNoStartNoEnd( m_list_divide );
			for(int x = 0; x < s; x++){
				int t = arg.split(x, m_list_divide).toInt();
				list.addLValue(t);
			}
			return list;
		}
		
    	virtual PrimitiveList<int> read(ElementId id, PrimitiveList<int> value){
			TextImporterLog(ame_Log_StartMethod, "read PrimitiveList int",  "println", "");
			
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
		
		// ByteArray primitive
    	virtual ByteArray read(ElementId id, ByteArray value){
			TextImporterLog(ame_Log_StartMethod, "read ByteArray",  "println", value.toNote());
			
			int x_1 = text.getOrder(id.getId(), m_split, m_end);
			if(x_1 == -1){
				return value;
			}
			return ByteArray(text.getArgument(x_1, m_split, m_end));
		}
		
    	virtual LinkedList<ByteArray> read(ElementId id, LinkedList<ByteArray> value){
			TextImporterLog(ame_Log_StartMethod, "read LinkedList ByteArray",  "println", "");
			
			int x_1 = text.getOrder(id.getId(), m_split, m_end);
			if(x_1 == -1){
				return value;
			}
			Note arg = text.getArgument(x_1, m_split, m_end);
			LinkedList<ByteArray> list;
			int s = arg.getSizeNoStartNoEnd( m_list_divide );
			for(int x = 0; x < s; x++){
				ByteArray t = arg.split(x, m_list_divide);
				list.addLValue(t);
			}
			return list;
		}
		
    	virtual PrimitiveList<ByteArray> read(ElementId id, PrimitiveList<ByteArray> value){
			TextImporterLog(ame_Log_StartMethod, "read PrimitiveList ByteArray",  "println", "");
			
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
		
		// bool primitive
    	virtual bool read(ElementId id, bool value){
			TextImporterLog(ame_Log_StartMethod, "read bool",  "println", Note(value));
			
			int x_1 = text.getOrder(id.getId(), m_split, m_end);
			if(x_1 == -1){
				return value;
			}
			return text.getArgument(x_1, m_split, m_end) == "1";
		}
		
    	virtual LinkedList<bool> read(ElementId id, LinkedList<bool> value){
			TextImporterLog(ame_Log_StartMethod, "read LinkedList bool",  "println", "");
			
			int x_1 = text.getOrder(id.getId(), m_split, m_end);
			if(x_1 == -1){
				return value;
			}
			Note arg = text.getArgument(x_1, m_split, m_end);
			LinkedList<bool> list;
			int s = arg.getSizeNoStartNoEnd(m_list_divide);
			for(int x = 0; x < s; x++){
				bool t = arg.split(x, m_list_divide) == "1";
				list.addLValue(t);
			}
			return list;
		}
		
    	virtual PrimitiveList<bool> read(ElementId id, PrimitiveList<bool> value){
			TextImporterLog(ame_Log_StartMethod, "read PrimitiveList bool",  "println", "");
			
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
		
		// char primitive
    	virtual char read(ElementId id, char value){
			TextImporterLog(ame_Log_StartMethod, "read char",  "println", Note(value));
			
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
		
    	virtual LinkedList<char> read(ElementId id, LinkedList<char> value){
			TextImporterLog(ame_Log_StartMethod, "read LinkedList char",  "println", "");
			
			int x_1 = text.getOrder(id.getId(), m_split, m_end);
			if(x_1 == -1){
				return value;
			}
			Note arg = text.getArgument(x_1, m_split, m_end);
			LinkedList<char> list;
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
		
    	virtual PrimitiveList<char> read(ElementId id, PrimitiveList<char> value){
			TextImporterLog(ame_Log_StartMethod, "read PrimitiveList char",  "println", "");
			
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

		// ElementId primitive
    	virtual ElementId read(ElementId id, ElementId value){
			TextImporterLog(ame_Log_StartMethod, "read ElementId",  "println", value.getId());
			
			int x_1 = text.getOrder(id.getId(), m_split, m_end);
			if(x_1 == -1){
				return value;
			}
			return ElementId(text.getArgument(x_1, m_split, m_end));
		}
		
    	virtual PrimitiveList<ElementId> read(ElementId id, PrimitiveList<ElementId> value){
			TextImporterLog(ame_Log_StartMethod, "read PrimitiveList ElementId",  "println", "");
			
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
			TextImporterLog(ame_Log_StartMethod, "read Note",  "println", value);
			
			int x_1 = text.getOrder(id.getId(), m_split, m_end);
			if(x_1 == -1){
				return value;
			}
			return text.getArgument(x_1, m_split, m_end);
		}
		
    	virtual Note read(ElementId id, char* value){
			TextImporterLog(ame_Log_StartMethod, "read char*",  "println", Note(value));
			
			int x_1 = text.getOrder(id.getId(), m_split, m_end);
			if(x_1 == -1){
				return Note(value);
			}
			return text.getArgument(x_1, m_split, m_end);
		}
		
    	virtual LinkedList<Note> read(ElementId id, LinkedList<Note> value){
			TextImporterLog(ame_Log_StartMethod, "read LinkedList Note",  "println", "");
			
			int x_1 = text.getOrder(id.getId(), m_split, m_end);
			if(x_1 == -1){
				return value;
			}
			Note arg = text.getArgument(x_1, m_split, m_end);
			LinkedList<Note> list;
			int s = arg.getSizeNoStartNoEnd( m_list_divide );
			for(int x = 0; x < s; x++){
				Note t = arg.split(x, m_list_divide);
				list.addLValue(t);
			}
			return list;
		}
		
    	virtual PrimitiveList<Note> read(ElementId id, PrimitiveList<Note> value){
			TextImporterLog(ame_Log_StartMethod, "read PrimitiveList Note",  "println", "");
			
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
		
		// long primitive
    	virtual long read(ElementId id, long value){
			TextImporterLog(ame_Log_StartMethod, "read long",  "println", Note(value));
			
			int x_1 = text.getOrder(id.getId(), m_split, m_end);
			if(x_1 == -1){
				return value;
			}
			return text.getArgument(x_1, m_split, m_end).toInt();
		}
		
    	virtual LinkedList<long> read(ElementId id, LinkedList<long> value){
			TextImporterLog(ame_Log_StartMethod, "read LinkedList long",  "println", "");
			
			int x_1 = text.getOrder(id.getId(), m_split, m_end);
			if(x_1 == -1){
				return value;
			}
			Note arg = text.getArgument(x_1, m_split, m_end);
			LinkedList<long> list;
			int s = arg.getSizeNoStartNoEnd( m_list_divide );
			for(int x = 0; x < s; x++){
				long t = arg.split(x, m_list_divide).toInt();
				list.addLValue(t);
			}
			return list;
		}
		
    	virtual PrimitiveList<long> read(ElementId id, PrimitiveList<long> value){
			TextImporterLog(ame_Log_StartMethod, "read PrimitiveList long",  "println", "");
			
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
		
    	virtual float read(ElementId id, float value){
			TextImporterLog(ame_Log_StartMethod, "read float",  "println", Note(value));
			
			int x_1 = text.getOrder(id.getId(), m_split, m_end);
			if(x_1 == -1){
				return value;
			}
			return text.getArgument(x_1, m_split, m_end).toFloat();
		}
		
    	virtual LinkedList<float> read(ElementId id, LinkedList<float> value){
			TextImporterLog(ame_Log_StartMethod, "read LinkedList float",  "println", "");
			
			int x_1 = text.getOrder(id.getId(), m_split, m_end);
			if(x_1 == -1){
				return value;
			}
			Note arg = text.getArgument(x_1, m_split, m_end);
			LinkedList<float> list;
			int s = arg.getSizeNoStartNoEnd( m_list_divide);
			for(int x = 0; x < s; x++){
				float t = arg.split(x, m_list_divide).toFloat();
				list.addLValue(t);
			}
			return list;
		}
		
    	virtual PrimitiveList<float> read(ElementId id, PrimitiveList<float> value){
			TextImporterLog(ame_Log_StartMethod, "read PrimitiveList float",  "println", "");
			
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
		
		// Savable primitive
    	/*virtual LinkedList<Savable> read(ElementId id, LinkedList<Savable> value)=0;
    	virtual PrimitiveList<Savable> read(ElementId id, PrimitiveList<Savable> value)=0;
    	// virtual PrimitiveMap<float> read(ElementId id, PrimitiveMap<float> value)=0;
		*/
		
    	virtual PrimitiveMap<Note,bool> read(ElementId id, PrimitiveMap<Note,bool> value){
			TextImporterLog(ame_Log_StartMethod, "read PrimitiveMap<Note,bool>",  "println", "");
			
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
			TextImporterLog(ame_Log_StartMethod, "read PrimitiveMap<Note,Note>",  "println", "");
			
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
			TextImporterLog(ame_Log_StartMethod, "read PrimitiveMap<ElementId,Note>",  "println", "");
			
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
			TextImporterLog(ame_Log_StartMethod, "clear",  "println", "");
			text = "";
		}
		
		/////////////////////////////////////////////////////////////////// ids
		virtual void addId(ElementId m_id){
			TextImporterLog(ame_Log_StartMethod, "addId",  "println", "");
			ids.add(m_id);
		}
		
		virtual void addIds(PrimitiveList<ElementId>& m_ids){
			TextImporterLog(ame_Log_StartMethod, "addIds",  "println", "");
			for(int x = 0; x < m_ids.getPosition(); x++){
				ElementId* l_eid = m_ids.getByPosition(x);
				ids.addLValue(*l_eid);
			}
		}
		
		virtual bool containId(ElementId m_id){
			TextImporterLog(ame_Log_StartMethod, "containId",  "println", "");
			return ids.containByLValue(m_id);
		}
		
		virtual PrimitiveList<ElementId>& getIds(){
			TextImporterLog(ame_Log_StartMethod, "getIds",  "println", "");
			return ids;
		}
		
		virtual ElementId getId(int x){
			TextImporterLog(ame_Log_StartMethod, "getId",  "println", "");
			if(x >= ids.getPosition()){
				return ElementId();
			}
			return ids[x];
		}
		
		virtual int getIdSize(){
			TextImporterLog(ame_Log_StartMethod, "getIdSize",  "println", "");
			return ids.getPosition();
		}
		
		virtual void removeId(ElementId i_id){
			TextImporterLog(ame_Log_StartMethod, "removeId",  "println", "");
			ids.removeDeleteByLValue(i_id);
		}
		
		virtual void removeIds(PrimitiveList<ElementId>& i_ids){
			TextImporterLog(ame_Log_StartMethod, "removeIds",  "println", "");
			for(int x = 0; x < i_ids.getPosition(); x++){
				ElementId* l_eid = i_ids.getByPosition(x);
				ids.removeDeleteByLValue(*l_eid);
			}
		}
		
		virtual void removeIds(){
			TextImporterLog(ame_Log_StartMethod, "removeIds",  "println", "");
			ids.resetDelete();
		}
		
		virtual void writeIds(){
			TextImporterLog(ame_Log_StartMethod, "writeIds",  "println", "");
			
			if(ids.getPosition() == 0){
				TextImporterLog(ame_Log_StartMethod, "writeIds",  "println", "ids.isEmpty");
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
			TextImporterLog(ame_Log_StartMethod, "writeId",  "println", "");
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
			TextImporterLog(ame_Log_StartMethod, "eraseId",  "println", "");
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
			TextImporterLog(ame_Log_StartMethod, "eraseIds",  "println", "");
			idText = "";
		}
		
		virtual void clearIds(){
			TextImporterLog(ame_Log_StartMethod, "clearIds",  "println", "");
			idText = "";
			ids.resetDelete();
		}
		
		/////////////////////////////////////////////////////////////////// idType
		virtual void addIdType(ElementId m_id, Note m_type){
			TextImporterLog(ame_Log_StartMethod, "addIdType",  "println", "");
			idsType.addLValues(m_id, m_type);
		}
		
		virtual void addIdType(PrimitiveMap<ElementId,Note>& m_idsType){
			TextImporterLog(ame_Log_StartMethod, "addIdType",  "println", "");
			for(int x = 0; x < m_idsType.getPosition(); x++){
				idsType.addLValues(m_idsType.getKey(x), m_idsType.getValue(x));
			}
		}
		
		virtual bool containIdType(ElementId id){
			TextImporterLog(ame_Log_StartMethod, "containIdType",  "println", "");
			return idsType.containKeyByLValue(id);
		}
		
		virtual PrimitiveMap<ElementId,Note>& getIdTypes(){
			TextImporterLog(ame_Log_StartMethod, "getIdTypes",  "println", "");
			return idsType;
		}
		
		virtual Note getIdType(ElementId id){
			TextImporterLog(ame_Log_StartMethod, "getIdType",  "println", "");
			return idsType.get(id);
		}
		
		virtual int getIdTypeSize(){
			TextImporterLog(ame_Log_StartMethod, "getIdTypeSize",  "println", "");
			return idsType.getPosition();
		}
		
		virtual void removeIdType(ElementId m_id){
			TextImporterLog(ame_Log_StartMethod, "removeIdType",  "println", "");
			idsType.removeDeleteByLValue(m_id);
		}
		
		virtual void removeIdTypes(PrimitiveMap<ElementId,Note>& m_idsType){
			TextImporterLog(ame_Log_StartMethod, "removeIdTypes",  "println", "");
			for(int x = 0; x < m_idsType.getPosition(); x++){
				idsType.removeDeleteByLValue(m_idsType.getKey(x));
			}
		}
		
		virtual void removeIdTypes(){
			TextImporterLog(ame_Log_StartMethod, "removeIdTypes",  "println", "");
			idsType.resetDelete();
		}
		
		virtual void writeIdTypes(){
			TextImporterLog(ame_Log_StartMethod, "writeIdTypes",  "println", "");
			if(idsType.getPosition() == 0){
				TextImporterLog(ame_Log_StartMethod, "writeIdTypes",  "println", "idsType.isEmpty");
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
			TextImporterLog(ame_Log_StartMethod, "writeIdType",  "println", "");
			
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
			TextImporterLog(ame_Log_StartMethod, "eraseIdType",  "println", "");
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
			TextImporterLog(ame_Log_StartMethod, "eraseIdTypes",  "println", "");
			idTypeText = "";
		}
		
		virtual void clearIdTypes(){
			TextImporterLog(ame_Log_StartMethod, "clearIds",  "println", "");
			idTypeText = "";
			idsType.resetDelete();
		}
		
		/////////////////////////////////////////////////////////////////// tags
		virtual void addTag(ElementId m_id, Note m_type){
			TextImporterLog(ame_Log_StartMethod, "addTag",  "println", "");
			tags.addLValues(m_id, m_type);
		}
		
		virtual void addTag(PrimitiveMap<ElementId,Note>& m_idsType){
			TextImporterLog(ame_Log_StartMethod, "addTag",  "println", "");
			for(int x = 0; x < m_idsType.getPosition(); x++){
				tags.addLValues(m_idsType.getKey(x), m_idsType.getValue(x));
			}
		}
		
		virtual bool containTag(ElementId id){
			TextImporterLog(ame_Log_StartMethod, "containTag",  "println", "");
			return tags.containKeyByLValue(id);
		}
		
		virtual PrimitiveMap<ElementId,Note>& getTags(){
			TextImporterLog(ame_Log_StartMethod, "getTags",  "println", "");
			return tags;
		}
		
		virtual Note getTag(ElementId id){
			TextImporterLog(ame_Log_StartMethod, "getTag",  "println", "");
			return tags.get(id);
		}
		
		virtual int getTagSize(){
			TextImporterLog(ame_Log_StartMethod, "getTagSize",  "println", "");
			return tags.getPosition();
		}
		
		virtual void removeTag(ElementId m_id){
			TextImporterLog(ame_Log_StartMethod, "removeTag",  "println", "");
			tags.removeDeleteByLValue(m_id);
		}
		
		virtual void removeTags(PrimitiveMap<ElementId,Note>& m_idsType){
			TextImporterLog(ame_Log_StartMethod, "removeTags",  "println", "");
			for(int x = 0; x < m_idsType.getPosition(); x++){
				tags.removeDeleteByLValue(m_idsType.getKey(x));
			}
		}
		
		virtual void removeTags(){
			TextImporterLog(ame_Log_StartMethod, "removeTags",  "println", "");
			tags.resetDelete();
		}
		
		virtual void writeTags(){
			TextImporterLog(ame_Log_StartMethod, "writeTags",  "println", "");
			if(tags.getPosition() == 0){
				TextImporterLog(ame_Log_StartMethod, "writeTags",  "println", "tags.isEmpty");
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
			TextImporterLog(ame_Log_StartMethod, "writeTag",  "println", "");
			
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
			TextImporterLog(ame_Log_StartMethod, "eraseTag",  "println", "");
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
			TextImporterLog(ame_Log_StartMethod, "eraseIdType",  "println", "");
			tagText = "";
		}
		
		virtual void clearTags(){
			TextImporterLog(ame_Log_StartMethod, "clearIds",  "println", "");
			tagText = "";
			tags.resetDelete();
		}
		
		virtual void setMessage(Message* message){
			TextImporterLog(ame_Log_StartMethod, "setMessage",  "println", "");
			if(message == nullptr){
				return;
			}
			setText(message->text());
			fix();
		}
		
		virtual void read(MonkeyFile* file, Note path){
			TextImporterLog(ame_Log_StartMethod, "read",  "println", "");
			if(file == nullptr){
				return;
			}
			setText( file->readText(path) );
			fix();
		}
		
		virtual void write(MonkeyFile* file, Note path){
			TextImporterLog(ame_Log_StartMethod, "write(file,path)",  "println", "");
			if(file == nullptr){
				TextImporterLog(ame_Log_StartMethod, "write(file,path)",  "println", path);
				return;
			}
			// file->fastWriteText(tagText, path);
			// file->fastWriteText(idText, path);
			// file->fastWriteText(idTypeText, path);
			// file->fastWriteText(text, path);
			
			file->fastWriteText(tagText + idText + idTypeText+ text, path);
		}
		
		virtual void setText(Note strng){
			TextImporterLog(ame_Log_StartMethod, "setText",  "println", Note("text ") + strng);
			text = strng;
		}
		
		virtual Note getText(){
			return text;
		}
		
		virtual void setIdText(Note strng){
			TextImporterLog(ame_Log_StartMethod, "setIdText",  "println", Note("text ") + strng);
			text = strng;
		}
		
		virtual Note getIdText(){
			return text;
		}
		
		virtual void setIdTypeText(Note strng){
			TextImporterLog(ame_Log_StartMethod, "setIdTypeText",  "println", Note("text ") + strng);
			text = strng;
		}
		
		virtual Note getIdTypeText(){
			return text;
		}
		
		virtual void setTagText(Note strng){
			TextImporterLog(ame_Log_StartMethod, "setTagText",  "println", Note("text ") + strng);
			text = strng;
		}
		
		virtual Note getTagText(){
			return text;
		}
		
		virtual Note getExporterText(){
			return tagText + idText + idTypeText + text;
		}
		
		virtual void fix(){
			TextImporterLog(ame_Log_StartMethod, "fix",  "println", "");
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
			
			TextImporterLog(ame_Log_StartMethod, "fix",  "println", Note("tagText ") + tagText);
			TextImporterLog(ame_Log_StartMethod, "fix",  "println", Note("idText ") + idText);
			TextImporterLog(ame_Log_StartMethod, "fix",  "println", Note("idTypeText ") + idTypeText);
			TextImporterLog(ame_Log_StartMethod, "fix",  "println", Note("text ") + text);
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