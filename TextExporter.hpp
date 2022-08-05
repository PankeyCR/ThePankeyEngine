
/**
 *
 * @author PankeyCR - Manuel Sanchez Badilla
 *
 */
 
#include "ame_Enviroment.hpp"

#if defined(DISABLE_TextExporter)
	#define TextExporter_hpp
#endif

#ifndef TextExporter_hpp
#define TextExporter_hpp
#define TextExporter_AVAILABLE

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
#include "MonkeyExporter.hpp"
#include "Message.hpp"

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
		TextExporter(const Note& strng){
			text = strng;
		}
		virtual ~TextExporter(){}
		
    	virtual PrimitiveList<ElementId> read(ElementId id, PrimitiveList<ElementId> value){
			TextExporterLog("TextExporter", "read PrimitiveList ElementId",  "println", "");
			int x_1 = text.getOrder(id.getId(), m_split, m_end);
			if(x_1 == -1){
				return value;
			}
			Note arg = text.getArgument(x_1, m_split, m_end);
			PrimitiveList<ElementId> list;
			int s = arg.getSizeNoStartNoEnd( m_list_divide );
			for(int x = 0; x < s; x++){
				ElementId t = arg.split(x, m_list_divide );
				list.addLValue(t);
			}
			return list;
		}
		
    	virtual PrimitiveMap<ElementId,Note> read(ElementId id, PrimitiveMap<ElementId,Note> value){
			TextExporterLog("TextExporter", "read PrimitiveMap<ElementId,Note>",  "println", "");
			
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
				ElementId k = ElementId(arg_key.split(x, m_list_divide ));
				Note v = arg_value.split(x, m_list_divide );
				map.addLValues(k,v);
			}
			return map;
		}
		
		// int primitive
    	virtual bool write(ElementId id, const int& value){
			TextExporterLog("TextExporter", "write int",  "println", Note(value));
			TextExporterLog("TextExporter", "write int",  "println", Note("making the id: ") + id.getId() + Note(" ") + Note(value) + Note("\n"));
			text += id.getId() + Note(" ") + Note(value) + Note("\n");
			return true;
		}
    	// virtual bool write(ElementId id, const LinkedList<int>& value){
			// TextExporterLog("TextExporter", "write LinkedList int",  "println", "");
			// if(value.getPosition() == 0){
				// return false;
			// }
			// text += id.getId() + Note(" ");
			// for(int x = 0; x < value.getPosition(); x++){
				// int v = *value.getByPosition(x);
				// if(x == value.getPosition() - 1){
					// text += Note(v) + Note("\n");
				// }else{
					// text += Note(v) + Note(",");
				// }
			// }
			// return true;
		// }
		
    	virtual bool write(ElementId id, const PrimitiveList<int>& value){
			TextExporterLog("TextExporter", "write PrimitiveList int",  "println", "");
			if(value.getPosition() == 0){
				return false;
			}
			text += id.getId() + Note(" ");
			for(int x = 0; x < value.getPosition(); x++){
				int v = *value.getByPosition(x);
				if(x == value.getPosition() - 1){
					text += Note(v) + Note("\n");
				}else{
					text += Note(v) + Note(",");
				}
			}
			return true;
		}
		

		// ByteArray primitive
    	virtual bool write(ElementId id, const ByteArray& value){
			TextExporterLog("TextExporter", "write Note",  "println", value.toNote());
			text += id.getId() + Note(" ") + value.toNote() + "\n";
			return true;
		}
		
    	// virtual bool write(ElementId id, const LinkedList<ByteArray>& value){
			// TextExporterLog("TextExporter", "write LinkedList ByteArray",  "println", "");
			// if(value.getPosition() == 0){
				// return false;
			// }
			// text += id.getId() + Note(" ");
			// for(int x = 0; x < value.getPosition(); x++){
				// ByteArray v = *value.getByPosition(x);
				// if(x == value.getPosition() - 1){
					// text += v.toNote() + Note("\n");
				// }else{
					// text += v.toNote() + Note(",");
				// }
			// }
			// return true;
		// }
		
    	virtual bool write(ElementId id, const PrimitiveList<ByteArray>& value){
			TextExporterLog("TextExporter", "write PrimitiveList ByteArray",  "println", "");
			if(value.getPosition() == 0){
				return false;
			}
			text += id.getId() + Note(" ");
			for(int x = 0; x < value.getPosition(); x++){
				ByteArray v = *value.getByPosition(x);
				if(x == value.getPosition() - 1){
					text += v.toNote() + Note("\n");
				}else{
					text += v.toNote() + Note(",");
				}
			}
			return true;
		}
		

		// bool primitive
    	virtual bool write(ElementId id, const bool& value){
			TextExporterLog("TextExporter", "write bool",  "println", Note(value));
			text += id.getId() + Note(" ") + Note(value) + "\n";
			return true;
		}
		
    	// virtual bool write(ElementId id, const LinkedList<bool>& value){
			// TextExporterLog("TextExporter", "write LinkedList bool",  "println", "");
			// if(value.getPosition() == 0){
				// return false;
			// }
			// text += id.getId() + Note(" ");
			// for(int x = 0; x < value.getPosition(); x++){
				// bool v = *value.getByPosition(x);
				// if(x == value.getPosition() - 1){
					// text += Note(v) + Note("\n");
				// }else{
					// text += Note(v) + Note(",");
				// }
			// }
			// return true;
		// }
		
    	virtual bool write(ElementId id, const PrimitiveList<bool>& value){
			TextExporterLog("TextExporter", "write PrimitiveList bool",  "println", "");
			if(value.getPosition() == 0){
				return false;
			}
			text += id.getId() + Note(" ");
			for(int x = 0; x < value.getPosition(); x++){
				bool v = *value.getByPosition(x);
				if(x == value.getPosition() - 1){
					text += Note(v) + Note("\n");
				}else{
					text += Note(v) + Note(",");
				}
			}
			return true;
		}
		
		
		// char primitive
    	virtual bool write(ElementId id, const char& value){
			TextExporterLog("TextExporter", "write Note",  "println", Note(value));
			text += id.getId() + Note(" ") + Note(value) + "\n";
			return true;
		}
		
    	// virtual bool write(ElementId id, const LinkedList<char>& value){
			// TextExporterLog("TextExporter", "write LinkedList char",  "println", "");
			// if(value.getPosition() == 0){
				// return false;
			// }
			// text += id.getId() + Note(" ");
			// for(int x = 0; x < value.getPosition(); x++){
				// char v = *value.getByPosition(x);
				// if(x == value.getPosition() - 1){
					// text += Note(v) + Note("\n");
				// }else{
					// text += Note(v) + Note(",");
				// }
			// }
			// return true;
		// }
		
    	virtual bool write(ElementId id, const PrimitiveList<char>& value){
			TextExporterLog("TextExporter", "write PrimitiveList char",  "println", "");
			if(value.getPosition() == 0){
				return false;
			}
			text += id.getId() + Note(" ");
			for(int x = 0; x < value.getPosition(); x++){
				char v = *value.getByPosition(x);
				if(x == value.getPosition() - 1){
					text += Note(v) + Note("\n");
				}else{
					text += Note(v) + Note(",");
				}
			}
			return true;
		}

		// ElementId primitive
    	virtual bool write(ElementId id, const ElementId& value){
			TextExporterLog("TextExporter", "write Note",  "println", value.getId());
			text += id.getId() + Note(" ") + value.getId() + "\n";
			return true;
		}
		
    	virtual bool write(ElementId id, const PrimitiveList<ElementId>& value){
			TextExporterLog("TextExporter", "write PrimitiveList ElementId",  "println", "");
			if(value.getPosition() == 0){
				return false;
			}
			text += id.getId() + Note(" ");
			for(int x = 0; x < value.getPosition(); x++){
				ElementId v = *value.getByPosition(x);
				if(x == value.getPosition() - 1){
					text += v.getId() + Note("\n");
				}else{
					text += v.getId() + Note(",");
				}
			}
			return true;
		}
		
		// Note primitive
    	virtual bool write(ElementId id, const Note& value){
			TextExporterLog("TextExporter", "write Note",  "println", value);
			text += id.getId() + Note(" ") + value + "\n";
			return true;
		}
		
    	virtual bool write(ElementId id, const char* value){
			TextExporterLog("TextExporter", "write Note",  "println", Note(value));
			text += id.getId() + Note(" ") + Note(value) + "\n";
			return true;
		}
		
    	// virtual bool write(ElementId id, const LinkedList<Note>& value){
			// TextExporterLog("TextExporter", "write LinkedList Note",  "println", "");
			// if(value.getPosition() == 0){
				// return false;
			// }
			// text += id.getId() + Note(" ");
			// for(int x = 0; x < value.getPosition(); x++){
				// Note v = *value.getByPosition(x);
				// if(x == value.getPosition() - 1){
					// text += v + Note("\n");
				// }else{
					// text += v + Note(",");
				// }
			// }
			// return true;
		// }
		
    	virtual bool write(ElementId id, const PrimitiveList<Note>& value){
			TextExporterLog("TextExporter", "write PrimitiveList Note",  "println", "");
			if(value.getPosition() == 0){
				return false;
			}
			text += id.getId() + Note(" ");
			for(int x = 0; x < value.getPosition(); x++){
				Note v = *value.getByPosition(x);
				if(x == value.getPosition() - 1){
					text += v + Note("\n");
				}else{
					text += v + Note(",");
				}
			}
			return true;
		}
		
		
		// long primitive
    	virtual bool write(ElementId id, const long& value){
			TextExporterLog("TextExporter", "write Note",  "println", Note(value));
			text += id.getId() + Note(" ") + Note(value) + "\n";
			return true;
		}
		
    	// virtual bool write(ElementId id, const LinkedList<long>& value){
			// TextExporterLog("TextExporter", "write LinkedList long",  "println", "");
			// if(value.getPosition() == 0){
				// return false;
			// }
			// text += id.getId() + Note(" ");
			// for(int x = 0; x < value.getPosition(); x++){
				// long v = *value.getByPosition(x);
				// if(x == value.getPosition() - 1){
					// text += Note(v) + Note("\n");
				// }else{
					// text += Note(v) + Note(",");
				// }
			// }
			// return true;
		// }
		
    	virtual bool write(ElementId id, const PrimitiveList<long>& value){
			TextExporterLog("TextExporter", "write PrimitiveList long",  "println", "");
			if(value.getPosition() == 0){
				return false;
			}
			text += id.getId() + Note(" ");
			for(int x = 0; x < value.getPosition(); x++){
				long v = *value.getByPosition(x);
				if(x == value.getPosition() - 1){
					text += Note(v) + Note("\n");
				}else{
					text += Note(v) + Note(",");
				}
			}
			return true;
		}
		
		// float primitive
    	virtual bool write(ElementId id, const float& value){
			TextExporterLog("TextExporter", "write float",  "println", Note(value));
			text += id.getId() + Note(" ") + Note(value) + "\n";
			return true;
		}
		
    	// virtual bool write(ElementId id, const LinkedList<float>& value){
			// TextExporterLog("TextExporter", "write LinkedList float",  "println", "");
			// if(value.getPosition() == 0){
				// return false;
			// }
			// text += id.getId() + Note(" ");
			// for(int x = 0; x < value.getPosition(); x++){
				// float v = *value.getByPosition(x);
				// if(x == value.getPosition() - 1){
					// text += Note(v) + Note("\n");
				// }else{
					// text += Note(v) + Note(",");
				// }
			// }
			// return true;
		// }
		
    	virtual bool write(ElementId id, const PrimitiveList<float>& value){
			TextExporterLog("TextExporter", "write PrimitiveList float",  "println", "");
			if(value.getPosition() == 0){
				return false;
			}
			text += id.getId() + Note(" ");
			for(int x = 0; x < value.getPosition(); x++){
				float v = *value.getByPosition(x);
				if(x == value.getPosition() - 1){
					text += Note(v) + Note("\n");
				}else{
					text += Note(v) + Note(",");
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
    	virtual bool write(ElementId id, const PrimitiveMap<Note,Note>& value){
			TextExporterLog("TextExporter", "write PrimitiveMap<Note,Note>",  "println", "");
			if(value.getPosition() == 0){
				return false;
			}
			ElementId keyId = id.child("key");
			ElementId valueId = id.child("value");
			
			Note var_key = keyId.getId() + Note(" ");
			Note var_value = valueId.getId() + Note(" ");
			
			for(int x = 0; x < value.getPosition(); x++){
				Note k = *value.getKeyByPosition(x);
				Note v = *value.getByPosition(x);
				if(x == value.getPosition() - 1){
					var_key += k + Note("\n");
					var_value += v + Note("\n");
				}else{
					var_key += k + Note(",");
					var_value += v + Note(",");
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
    	// virtual bool write(ElementId id, const PrimitiveMap<int,Note>& value)=0;
    	// virtual bool write(ElementId id, const PrimitiveMap<int,Savable>& value)=0;
		
    	// virtual bool write(ElementId id, const PrimitiveMap<bool,int>& value)=0;
    	// virtual bool write(ElementId id, const PrimitiveMap<bool,char>& value)=0;
    	// virtual bool write(ElementId id, const PrimitiveMap<bool,long>& value)=0;
    	// virtual bool write(ElementId id, const PrimitiveMap<bool,float>& value)=0;
    	// virtual bool write(ElementId id, const PrimitiveMap<bool,Note>& value)=0;
    	// virtual bool write(ElementId id, const PrimitiveMap<bool,Savable>& value)=0;
		
    	// virtual bool write(ElementId id, const PrimitiveMap<char,int>& value)=0;
    	// virtual bool write(ElementId id, const PrimitiveMap<char,bool>& value)=0;
    	// virtual bool write(ElementId id, const PrimitiveMap<char,long>& value)=0;
    	// virtual bool write(ElementId id, const PrimitiveMap<char,float>& value)=0;
    	// virtual bool write(ElementId id, const PrimitiveMap<char,Note>& value)=0;
    	// virtual bool write(ElementId id, const PrimitiveMap<char,Savable>& value)=0;
		
    	// virtual bool write(ElementId id, const PrimitiveMap<long,int>& value)=0;
    	// virtual bool write(ElementId id, const PrimitiveMap<long,bool>& value)=0;
    	// virtual bool write(ElementId id, const PrimitiveMap<long,char>& value)=0;
    	// virtual bool write(ElementId id, const PrimitiveMap<long,float>& value)=0;
    	// virtual bool write(ElementId id, const PrimitiveMap<long,Note>& value)=0;
    	// virtual bool write(ElementId id, const PrimitiveMap<long,Savable>& value)=0;
		
    	// virtual bool write(ElementId id, const PrimitiveMap<float,int>& value)=0;
    	// virtual bool write(ElementId id, const PrimitiveMap<float,bool>& value)=0;
    	// virtual bool write(ElementId id, const PrimitiveMap<float,char>& value)=0;
    	// virtual bool write(ElementId id, const PrimitiveMap<float,long>& value)=0;
    	// virtual bool write(ElementId id, const PrimitiveMap<float,Note>& value)=0;
    	// virtual bool write(ElementId id, const PrimitiveMap<float,Savable>& value)=0;
		
    	// virtual bool write(ElementId id, const PrimitiveMap<Note,int>& value)=0;
    	virtual bool write(ElementId id, const PrimitiveMap<Note,bool>& value){
			TextExporterLog("TextExporter", "write PrimitiveMap<Note,bool>",  "println", "");
			if(value.getPosition() == 0){
				return false;
			}
			ElementId keyId = id.child("key");
			ElementId valueId = id.child("value");
			Note var_key = keyId.getId() + Note(" ");
			Note var_value = valueId.getId() + Note(" ");
			
			for(int x = 0; x < value.getPosition(); x++){
				Note k = *value.getKeyByPosition(x);
				bool v = *value.getByPosition(x);
				if(x == value.getPosition() - 1){
					var_key += k + Note("\n");
					var_value += Note(v) + Note("\n");
				}else{
					var_key += k + Note(",");
					var_value += Note(v) + Note(",");
				}
			}
			
			text += var_key;
			text += var_value;
			return true;
		}
		
    	// virtual bool write(ElementId id, const PrimitiveMap<Note,char>& value)=0;
    	// virtual bool write(ElementId id, const PrimitiveMap<Note,long>& value)=0;
    	// virtual bool write(ElementId id, const PrimitiveMap<Note,float>& value)=0;
    	// virtual bool write(ElementId id, const PrimitiveMap<Note,Savable>& value)=0;
		
    	// virtual bool write(ElementId id, const PrimitiveMap<Savable,int>& value)=0;
    	// virtual bool write(ElementId id, const PrimitiveMap<Savable,bool>& value)=0;
    	// virtual bool write(ElementId id, const PrimitiveMap<Savable,char>& value)=0;
    	// virtual bool write(ElementId id, const PrimitiveMap<Savable,long>& value)=0;
    	// virtual bool write(ElementId id, const PrimitiveMap<Savable,float>& value)=0;
    	// virtual bool write(ElementId id, const PrimitiveMap<Savable,Note>& value)=0;
		
    	virtual bool write(ElementId id, const PrimitiveMap<ElementId,Note>& value){
			TextExporterLog("TextExporter", "write PrimitiveMap<ElementId,Note>",  "println", "");
			if(value.getPosition() == 0){
				return false;
			}
			ElementId keyId = id.child("key");
			ElementId valueId = id.child("value");
			Note var_key = keyId.getId() + Note(" ");
			Note var_value = valueId.getId() + Note(" ");
			
			for(int x = 0; x < value.getPosition(); x++){
				ElementId k = *value.getKeyByPosition(x);
				Note v = *value.getByPosition(x);
				if(x == value.getPosition() - 1){
					var_key += k.getId() + Note("\n");
					var_value += v + Note("\n");
				}else{
					var_key += k.getId() + Note(",");
					var_value += v + Note(",");
				}
			}
			
			text += var_key;
			text += var_value;
			return true;
		}
		
		virtual void remove(ElementId id){
			TextExporterLog("TextExporter", "remove",  "println", "");
			text.removeLine(id.getId(), m_split, m_end);
		}
		
		virtual void clear(){
			TextExporterLog("TextExporter", "clear",  "println", "");
			text = "";
		}
		
		/////////////////////////////////////////////////////////////////// ids
		virtual void addId(ElementId m_id){
			TextExporterLog("TextExporter", "addId",  "println", "");
			ids.add(m_id);
		}
		
		virtual void addIds(PrimitiveList<ElementId>& m_ids){
			TextExporterLog("TextExporter", "addIds",  "println", "");
			for(int x = 0; x < m_ids.getPosition(); x++){
				ElementId* l_eid = m_ids.getByPosition(x);
				ids.addLValue(*l_eid);
			}
		}
		
		virtual bool containId(ElementId m_id){
			TextExporterLog("TextExporter", "containId",  "println", "");
			return ids.containByLValue(m_id);
		}
		
		virtual PrimitiveList<ElementId>& getIds(){
			TextExporterLog("TextExporter", "getIds",  "println", "");
			return ids;
		}
		
		virtual ElementId getId(int x){
			TextExporterLog("TextExporter", "getId",  "println", "");
			if(x >= ids.getPosition()){
				return ElementId();
			}
			return ids[x];
		}
		
		virtual int getIdSize(){
			TextExporterLog("TextExporter", "getIdSize",  "println", "");
			return ids.getPosition();
		}
		
		virtual void removeId(ElementId i_id){
			TextExporterLog("TextExporter", "removeId",  "println", "");
			ids.removeDeleteByLValue(i_id);
		}
		
		virtual void removeIds(PrimitiveList<ElementId>& i_ids){
			TextExporterLog("TextExporter", "removeIds",  "println", "");
			for(int x = 0; x < i_ids.getPosition(); x++){
				ElementId* l_eid = i_ids.getByPosition(x);
				ids.removeDeleteByLValue(*l_eid);
			}
		}
		
		virtual void removeIds(){
			TextExporterLog("TextExporter", "removeIds",  "println", "");
			ids.resetDelete();
		}
		
		virtual void writeIds(){
			TextExporterLog("TextExporter", "writeIds",  "println", "");
			
			if(ids.getPosition() == 0){
				TextExporterLog("TextExporter", "writeIds",  "println", "ids.isEmpty");
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
			TextExporterLog("TextExporter", "writeId",  "println", "");
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
			TextExporterLog("TextExporter", "eraseId",  "println", "");
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
			TextExporterLog("TextExporter", "eraseIds",  "println", "");
			idText = "";
		}
		
		virtual void clearIds(){
			TextExporterLog("TextExporter", "clearIds",  "println", "");
			idText = "";
			ids.resetDelete();
		}
		
		/////////////////////////////////////////////////////////////////// idType
		virtual void addIdType(ElementId m_id, Note m_type){
			TextExporterLog("TextExporter", "addIdType",  "println", "");
			idsType.addLValues(m_id, m_type);
		}
		
		virtual void addIdType(PrimitiveMap<ElementId,Note>& m_idsType){
			TextExporterLog("TextExporter", "addIdType",  "println", "");
			for(int x = 0; x < m_idsType.getPosition(); x++){
				idsType.addLValues(m_idsType.getKey(x), m_idsType.getValue(x));
			}
		}
		
		virtual bool containIdType(ElementId id){
			TextExporterLog("TextExporter", "containIdType",  "println", "");
			return idsType.containKeyByLValue(id);
		}
		
		virtual PrimitiveMap<ElementId,Note>& getIdTypes(){
			TextExporterLog("TextExporter", "getIdTypes",  "println", "");
			return idsType;
		}
		
		virtual Note getIdType(ElementId id){
			TextExporterLog("TextExporter", "getIdType",  "println", "");
			return idsType.get(id);
		}
		
		virtual int getIdTypeSize(){
			TextExporterLog("TextExporter", "getIdTypeSize",  "println", "");
			return idsType.getPosition();
		}
		
		virtual void removeIdType(ElementId m_id){
			TextExporterLog("TextExporter", "removeIdType",  "println", "");
			idsType.removeDeleteByLValue(m_id);
		}
		
		virtual void removeIdTypes(PrimitiveMap<ElementId,Note>& m_idsType){
			TextExporterLog("TextExporter", "removeIdTypes",  "println", "");
			for(int x = 0; x < m_idsType.getPosition(); x++){
				idsType.removeDeleteByLValue(m_idsType.getKey(x));
			}
		}
		
		virtual void removeIdTypes(){
			TextExporterLog("TextExporter", "removeIdTypes",  "println", "");
			idsType.resetDelete();
		}
		
		virtual void writeIdTypes(){
			TextExporterLog("TextExporter", "writeIdTypes",  "println", "");
			if(idsType.getPosition() == 0){
				TextExporterLog("TextExporter", "writeIdTypes",  "println", "ids.isEmpty");
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
			TextExporterLog("TextExporter", "writeIdType",  "println", "");
			
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
			TextExporterLog("TextExporter", "eraseIdType",  "println", "");
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
			TextExporterLog("TextExporter", "eraseIdTypes",  "println", "");
			idTypeText = "";
		}
		
		virtual void clearIdTypes(){
			TextExporterLog("TextExporter", "clearIds",  "println", "");
			idTypeText = "";
			idsType.resetDelete();
		}
		
		/////////////////////////////////////////////////////////////////// tags
		virtual void addTag(ElementId m_id, Note m_type){
			TextExporterLog("TextExporter", "addTag",  "println", "");
			tags.addLValues(m_id, m_type);
		}
		
		virtual void addTag(PrimitiveMap<ElementId,Note>& m_idsType){
			TextExporterLog("TextExporter", "addTag",  "println", "");
			for(int x = 0; x < m_idsType.getPosition(); x++){
				tags.addLValues(m_idsType.getKey(x), m_idsType.getValue(x));
			}
		}
		
		virtual bool containTag(ElementId id){
			TextExporterLog("TextExporter", "containTag",  "println", "");
			return tags.containKeyByLValue(id);
		}
		
		virtual PrimitiveMap<ElementId,Note>& getTags(){
			TextExporterLog("TextExporter", "getTags",  "println", "");
			return tags;
		}
		
		virtual Note getTag(ElementId id){
			TextExporterLog("TextExporter", "getTag",  "println", "");
			return tags.get(id);
		}
		
		virtual int getTagSize(){
			TextExporterLog("TextExporter", "getTagSize",  "println", "");
			return tags.getPosition();
		}
		
		virtual void removeTag(ElementId m_id){
			TextExporterLog("TextExporter", "removeTag",  "println", "");
			tags.removeDeleteByLValue(m_id);
		}
		
		virtual void removeTags(PrimitiveMap<ElementId,Note>& m_idsType){
			TextExporterLog("TextExporter", "removeTags",  "println", "");
			for(int x = 0; x < m_idsType.getPosition(); x++){
				tags.removeDeleteByLValue(m_idsType.getKey(x));
			}
		}
		
		virtual void removeTags(){
			TextExporterLog("TextExporter", "removeTags",  "println", "");
			tags.resetDelete();
		}
		
		virtual void writeTags(){
			TextExporterLog("TextExporter", "writeTags",  "println", "");
			if(tags.getPosition() == 0){
				TextExporterLog("TextExporter", "writeTags",  "println", "ids.isEmpty");
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
			
			tagText = var_key;
			tagText += var_value;
		}
		
		virtual void writeTag(ElementId i_id, Note type){
			TextExporterLog("TextExporter", "writeTag",  "println", "");
			
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
			TextExporterLog("TextExporter", "eraseTag",  "println", "");
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
			TextExporterLog("TextExporter", "eraseIdType",  "println", "");
			tagText = "";
		}
		
		virtual void clearTags(){
			TextExporterLog("TextExporter", "clearIds",  "println", "");
			tagText = "";
			tags.resetDelete();
		}
		
		virtual void setMessage(Message* message){
			TextExporterLog("TextExporter", "setMessage",  "println", "");
			if(message == nullptr){
				return;
			}
			setText(message->text());
			fix();
		}
		
		virtual void read(MonkeyFile* file, Note path){
			TextExporterLog("TextExporter", "read",  "println", "");
			if(file == nullptr){
				return;
			}
			setText( file->readText(path) );
			fix();
		}
		
		virtual void write(MonkeyFile* file, Note path){
			TextExporterLog("TextExporter", "write(file,path)",  "println", "");
			if(file == nullptr){
				TextExporterLog("TextExporter", "write(file,path)",  "println", path);
				return;
			}
			// file->fastWriteText(tagText, path);
			// file->fastWriteText(idText, path);
			// file->fastWriteText(idTypeText, path);
			// file->fastWriteText(text, path);
			
			file->fastWriteText(tagText + idText + idTypeText+ text, path);
		}
		
		virtual void setText(Note strng){
			TextExporterLog("TextExporter", "setText",  "println", Note("text ") + strng);
			text = strng;
		}
		
		virtual Note getText(){
			return text;
		}
		
		virtual void setIdText(Note strng){
			TextExporterLog("TextExporter", "setIdText",  "println", Note("text ") + strng);
			idText = strng;
		}
		
		virtual Note getIdText(){
			return idText;
		}
		
		virtual void setIdTypeText(Note strng){
			TextExporterLog("TextExporter", "setIdTypeText",  "println", Note("text ") + strng);
			idTypeText = strng;
		}
		
		virtual Note getIdTypeText(){
			return idTypeText;
		}
		
		virtual void setTagText(Note strng){
			TextExporterLog("TextExporter", "setTagText",  "println", Note("text ") + strng);
			tagText = strng;
		}
		
		virtual Note getTagText(){
			return tagText;
		}
		
		virtual Note getExporterText(){
			return tagText + idText + idTypeText + text;
		}
		
		virtual void fix(){
			TextExporterLog("TextExporter", "fix",  "println", "");
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
			
			TextExporterLog("TextExporter", "fix",  "println", Note("tagText ") + tagText);
			TextExporterLog("TextExporter", "fix",  "println", Note("idText ") + idText);
			TextExporterLog("TextExporter", "fix",  "println", Note("idTypeText ") + idTypeText);
			TextExporterLog("TextExporter", "fix",  "println", Note("text ") + text);
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