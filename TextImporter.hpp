
/**
 *
 * @author PankeyCR - Manuel Sanchez Badilla
 *
 */
 
#ifndef CONFIGURATION_TextImporter_hpp
#define CONFIGURATION_TextImporter_hpp

	#include "ame_Enviroment.hpp"

	#if defined(DISABLE_TextImporter)
		#define TextImporter_hpp

		#define IMPLEMENTATION_TextImporter
		#define IMPLEMENTING_TextImporter
	#else
		#if defined(DISABLE_IMPLEMENTATION_TextImporter)
			#define IMPLEMENTATION_TextImporter
			#define IMPLEMENTING_TextImporter
		#endif
	#endif
#endif

#ifndef TextImporter_hpp
#define TextImporter_hpp
#define TextImporter_AVAILABLE

#ifndef DISABLE_IMPLEMENTATION_TextImporter
	#define IMPLEMENTATION_TextImporter IMPLEMENTATION(public TextImporter)
	#define IMPLEMENTING_TextImporter IMPLEMENTING(public TextImporter)
#endif

#ifndef ame_Enviroment_Defined

#endif

#ifdef ame_Windows

#endif

#ifdef ame_ArduinoIDE
	#include "Arduino.h"
#endif

#include "Note.hpp"
#include "NoteHelper.hpp"
#include "ByteArray.hpp"
#include "ByteArrayHelper.hpp"
#include "ElementId.hpp"
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
		TextImporter(){
			TextImporterLog(ame_Log_StartMethod, "Constructor", "println", "");
			TextImporterLog(ame_Log_EndMethod, "Constructor", "println", "");
		}
		TextImporter(const Note& c_note){
			setText(c_note);
		}
		virtual ~TextImporter(){
			TextImporterLog(ame_Log_StartMethod, "Destructor", "println", "");
			TextImporterLog(ame_Log_EndMethod, "Destructor", "println", "");
		}
		
		// int primitive
    	virtual int read(ElementId a_id, int a_value){
			TextImporterLog(ame_Log_StartMethod, "read int",  "println", Note(a_value));
			int i_order = m_text.getOrder(a_id.getId(), m_split, m_end);
			if(i_order == -1){
				TextImporterLog(ame_Log_StartMethod, "read int",  "println", "i_order == -1");
				return a_value;
			}
			TextImporterLog(ame_Log_StartMethod, "read int",  "println", Note("argument ") + cmd.getArgument(x_1));
			return m_text.getArgument(i_order, m_split, m_end).toInt();
		}
		
    	virtual LinkedList<int> read(ElementId a_id, LinkedList<int> a_value){
			TextImporterLog(ame_Log_StartMethod, "read",  "println", "");
			
			int i_order = m_text.getOrder(a_id.getId(), m_split, m_end);
			if(i_order == -1){
				TextImporterLog(ame_Log_StartMethod, "read",  "println", "");
				return a_value;
			}
			Note i_arg = m_text.getArgument(i_order, m_split, m_end);
			LinkedList<int> i_list;
			int i_size = i_arg.getSizeNoStartNoEnd( m_list_divide );
			for(int x = 0; x < i_size; x++){
				int f_value = i_arg.split(x, m_list_divide).toInt();
				i_list.addLValue(f_value);
			}
			TextImporterLog(ame_Log_StartMethod, "read",  "println", "");
			return i_list;
		}
		
    	virtual PrimitiveList<int> read(ElementId a_id, PrimitiveList<int> a_value){
			TextImporterLog(ame_Log_StartMethod, "read PrimitiveList int",  "println", "");
			
			int i_order = m_text.getOrder(a_id.getId(), m_split, m_end);
			if(i_order == -1){
				TextImporterLog(ame_Log_StartMethod, "read",  "println", "");
				return a_value;
			}
			Note i_arg = m_text.getArgument(i_order, m_split, m_end);
			PrimitiveList<int> i_list;
			int i_size = i_arg.getSizeNoStartNoEnd( m_list_divide );
			for(int x = 0; x < i_size; x++){
				int f_value = i_arg.split(x, m_list_divide).toInt();
				i_list.addLValue(f_value);
			}
			TextImporterLog(ame_Log_StartMethod, "read",  "println", "");
			return i_list;
		}
		
		// ByteArray primitive
    	virtual ByteArray read(ElementId a_id, ByteArray a_value){
			TextImporterLog(ame_Log_StartMethod, "read ByteArray",  "println", toNote(a_value));
			
			int i_order = m_text.getOrder(a_id.getId(), m_split, m_end);
			if(i_order == -1){
				TextImporterLog(ame_Log_StartMethod, "read",  "println", "");
				return a_value;
			}
			TextImporterLog(ame_Log_StartMethod, "read",  "println", "");
			ByteArray i_byte_array = toByteArray(m_text.getArgument(i_order, m_split, m_end));
			return i_byte_array;
		}
		
    	virtual LinkedList<ByteArray> read(ElementId a_id, LinkedList<ByteArray> a_value){
			TextImporterLog(ame_Log_StartMethod, "read LinkedList ByteArray",  "println", "");
			
			int i_order = m_text.getOrder(a_id.getId(), m_split, m_end);
			if(i_order == -1){
				TextImporterLog(ame_Log_StartMethod, "read",  "println", "");
				return a_value;
			}
			Note i_arg = m_text.getArgument(i_order, m_split, m_end);
			LinkedList<ByteArray> i_list;
			int i_size = i_arg.getSizeNoStartNoEnd( m_list_divide );
			for(int x = 0; x < i_size; x++){
				Note f_note = i_arg.split(x, m_list_divide);
				ByteArray f_byte_array = toByteArray(f_note);
				i_list.addLValue(f_byte_array);
			}
			TextImporterLog(ame_Log_StartMethod, "read",  "println", "");
			return i_list;
		}
		
    	virtual PrimitiveList<ByteArray> read(ElementId a_id, PrimitiveList<ByteArray> a_value){
			TextImporterLog(ame_Log_StartMethod, "read",  "println", "");
			
			int i_order = m_text.getOrder(a_id.getId(), m_split, m_end);
			if(i_order == -1){
				TextImporterLog(ame_Log_StartMethod, "read",  "println", "");
				return a_value;
			}
			Note i_arg = m_text.getArgument(i_order, m_split, m_end);
			PrimitiveList<ByteArray> i_list;
			int i_size = i_arg.getSizeNoStartNoEnd( m_list_divide );
			for(int x = 0; x < i_size; x++){
				Note f_note = i_arg.split(x, m_list_divide);
				ByteArray f_byte_array = toByteArray(f_note);
				i_list.addLValue(f_byte_array);
			}
			TextImporterLog(ame_Log_StartMethod, "read",  "println", "");
			return i_list;
		}
		
		// bool primitive
    	virtual bool read(ElementId a_id, bool a_value){
			TextImporterLog(ame_Log_StartMethod, "read bool",  "println", Note(a_value));
			
			int i_order = m_text.getOrder(a_id.getId(), m_split, m_end);
			if(i_order == -1){
				TextImporterLog(ame_Log_StartMethod, "read",  "println", "");
				return a_value;
			}
			Note i_note_bool = m_text.getArgument(i_order, m_split, m_end);
			TextImporterLog(ame_Log_StartMethod, "read",  "println", "");
			return i_note_bool == "1";
		}
		
    	virtual LinkedList<bool> read(ElementId a_id, LinkedList<bool> a_value){
			TextImporterLog(ame_Log_StartMethod, "read LinkedList bool",  "println", "");
			
			int i_order = m_text.getOrder(a_id.getId(), m_split, m_end);
			if(i_order == -1){
				TextImporterLog(ame_Log_StartMethod, "read",  "println", "");
				return a_value;
			}
			Note i_arg = m_text.getArgument(i_order, m_split, m_end);
			LinkedList<bool> i_list;
			int s = i_arg.getSizeNoStartNoEnd(m_list_divide);
			for(int x = 0; x < s; x++){
				bool f_value = i_arg.split(x, m_list_divide) == "1";
				i_list.addLValue(f_value);
			}
			TextImporterLog(ame_Log_StartMethod, "read",  "println", "");
			return i_list;
		}
		
    	virtual PrimitiveList<bool> read(ElementId a_id, PrimitiveList<bool> a_value){
			TextImporterLog(ame_Log_StartMethod, "read PrimitiveList bool",  "println", "");
			
			int i_order = m_text.getOrder(a_id.getId(), m_split, m_end);
			if(i_order == -1){
				return a_value;
			}
			Note i_arg = m_text.getArgument(i_order, m_split, m_end);
			PrimitiveList<bool> i_list;
			int s = i_arg.getSizeNoStartNoEnd( m_list_divide );
			for(int x = 0; x < s; x++){
				bool t = i_arg.split(x, m_list_divide) == "1";
				i_list.addLValue(t);
			}
			return i_list;
		}
		
		// char primitive
    	virtual char read(ElementId a_id, char a_value){
			TextImporterLog(ame_Log_StartMethod, "read char",  "println", Note(a_value));
			
			int i_order = m_text.getOrder(a_id.getId(), m_split, m_end);
			if(i_order == -1){
				return a_value;
			}
			Note r = m_text.getArgument(i_order, m_split, m_end);
			if(r.length() == 0){
				return a_value;
			}
			return r.get(0);
		}
		
    	virtual LinkedList<char> read(ElementId a_id, LinkedList<char> a_value){
			TextImporterLog(ame_Log_StartMethod, "read LinkedList char",  "println", "");
			
			int i_order = m_text.getOrder(a_id.getId(), m_split, m_end);
			if(i_order == -1){
				return a_value;
			}
			Note i_arg = m_text.getArgument(i_order, m_split, m_end);
			LinkedList<char> i_list;
			int i_size = i_arg.getSizeNoStartNoEnd( m_list_divide );
			for(int x = 0; x < i_size; x++){
				Note f_value = i_arg.split(x, m_list_divide);
				if(f_value.isEmpty()){
					return a_value;
				}
				char f_char = f_value.get(0);
				i_list.addLValue(f_char);
			}
			return i_list;
		}
		
    	virtual PrimitiveList<char> read(ElementId a_id, PrimitiveList<char> a_value){
			TextImporterLog(ame_Log_StartMethod, "read PrimitiveList char",  "println", "");
			
			int i_order = m_text.getOrder(a_id.getId(), m_split, m_end);
			if(i_order == -1){
				return a_value;
			}
			Note i_arg = m_text.getArgument(i_order, m_split, m_end);
			PrimitiveList<char> i_list;
			int i_size = i_arg.getSizeNoStartNoEnd( m_list_divide );
			for(int x = 0; x < i_size; x++){
				Note f_note = i_arg.split(x, m_list_divide);
				if(f_note == ""){
					return a_value;
				}
				char f_char = f_note.get(0);
				i_list.addLValue(f_char);
			}
			return i_list;
		}

		// ElementId primitive
    	virtual ElementId read(ElementId a_id, ElementId a_value){
			TextImporterLog(ame_Log_StartMethod, "read",  "println", a_value.getId());
			
			int i_order = m_text.getOrder(a_id.getId(), m_split, m_end);
			if(i_order == -1){
				return a_value;
			}
			return ElementId(m_text.getArgument(i_order, m_split, m_end));
		}
		
    	virtual PrimitiveList<ElementId> read(ElementId a_id, PrimitiveList<ElementId> a_value){
			TextImporterLog(ame_Log_StartMethod, "read",  "println", "");
			
			int i_order = m_text.getOrder(a_id.getId(), m_split, m_end);
			if(i_order == -1){
				return a_value;
			}
			Note i_arg = m_text.getArgument(i_order, m_split, m_end);
			PrimitiveList<ElementId> i_list;
			int s = i_arg.getSizeNoStartNoEnd( m_list_divide );
			for(int x = 0; x < s; x++){
				ElementId f_element_id = i_arg.split(x, m_list_divide);
				i_list.addLValue(f_element_id);
			}
			return i_list;
		}
		
		// Note primitive
    	virtual Note read(ElementId a_id, Note a_value){
			TextImporterLog(ame_Log_StartMethod, "read Note",  "println", a_value);
			
			int i_order = m_text.getOrder(a_id.getId(), m_split, m_end);
			if(i_order == -1){
				return a_value;
			}
			return m_text.getArgument(i_order, m_split, m_end);
		}
		
    	virtual Note read(ElementId a_id, char* a_value){
			TextImporterLog(ame_Log_StartMethod, "read char*",  "println", Note(a_value));
			
			int i_order = m_text.getOrder(a_id.getId(), m_split, m_end);
			if(i_order == -1){
				return Note(a_value);
			}
			return m_text.getArgument(i_order, m_split, m_end);
		}
		
    	virtual LinkedList<Note> read(ElementId a_id, LinkedList<Note> a_value){
			TextImporterLog(ame_Log_StartMethod, "read",  "println", "");
			
			int i_order = m_text.getOrder(a_id.getId(), m_split, m_end);
			if(i_order == -1){
				return a_value;
			}
			Note i_arg = m_text.getArgument(i_order, m_split, m_end);
			LinkedList<Note> i_list;
			int i_size = i_arg.getSizeNoStartNoEnd( m_list_divide );
			for(int x = 0; x < i_size; x++){
				Note t = i_arg.split(x, m_list_divide);
				i_list.addLValue(t);
			}
			return i_list;
		}
		
    	virtual PrimitiveList<Note> read(ElementId a_id, PrimitiveList<Note> a_value){
			TextImporterLog(ame_Log_StartMethod, "read",  "println", "");
			
			int i_order = m_text.getOrder(a_id.getId(), m_split, m_end);
			if(i_order == -1){
				return a_value;
			}
			Note i_arg = m_text.getArgument(i_order, m_split, m_end);
			PrimitiveList<Note> i_list;
			int i_size = i_arg.getSizeNoStartNoEnd( m_list_divide );
			for(int x = 0; x < i_size; x++){
				Note f_note = i_arg.split(x, m_list_divide);
				i_list.addLValue(f_note);
			}
			return i_list;
		}
		
		// long primitive
    	virtual long read(ElementId a_id, long a_value){
			TextImporterLog(ame_Log_StartMethod, "read long",  "println", Note(a_value));
			
			int i_order = m_text.getOrder(a_id.getId(), m_split, m_end);
			if(i_order == -1){
				return a_value;
			}
			return m_text.getArgument(i_order, m_split, m_end).toInt();
		}
		
    	virtual LinkedList<long> read(ElementId a_id, LinkedList<long> a_value){
			TextImporterLog(ame_Log_StartMethod, "read",  "println", "");
			
			int i_order = m_text.getOrder(a_id.getId(), m_split, m_end);
			if(i_order == -1){
				return a_value;
			}
			Note i_arg = m_text.getArgument(i_order, m_split, m_end);
			LinkedList<long> i_list;
			int i_size = i_arg.getSizeNoStartNoEnd( m_list_divide );
			for(int x = 0; x < i_size; x++){
				long t = i_arg.split(x, m_list_divide).toInt();
				i_list.addLValue(t);
			}
			return i_list;
		}
		
    	virtual PrimitiveList<long> read(ElementId a_id, PrimitiveList<long> a_value){
			TextImporterLog(ame_Log_StartMethod, "read PrimitiveList long",  "println", "");
			
			int i_order = m_text.getOrder(a_id.getId(), m_split, m_end);
			if(i_order == -1){
				return a_value;
			}
			Note i_arg = m_text.getArgument(i_order, m_split, m_end);
			PrimitiveList<long> i_list;
			int i_size = i_arg.getSizeNoStartNoEnd( m_list_divide );
			for(int x = 0; x < i_size; x++){
				long f_value = i_arg.split(x, m_list_divide).toInt();
				i_list.addLValue(f_value);
			}
			return i_list;
		}
		
    	virtual float read(ElementId a_id, float a_value){
			TextImporterLog(ame_Log_StartMethod, "read",  "println", Note(value));
			
			int i_order = m_text.getOrder(a_id.getId(), m_split, m_end);
			if(i_order == -1){
				return a_value;
			}
			return m_text.getArgument(i_order, m_split, m_end).toFloat();
		}
		
    	virtual LinkedList<float> read(ElementId a_id, LinkedList<float> a_value){
			TextImporterLog(ame_Log_StartMethod, "read",  "println", "");
			
			int i_order = m_text.getOrder(a_id.getId(), m_split, m_end);
			if(i_order == -1){
				return a_value;
			}
			Note i_arg = m_text.getArgument(i_order, m_split, m_end);
			LinkedList<float> i_list;
			int s = i_arg.getSizeNoStartNoEnd( m_list_divide);
			for(int x = 0; x < s; x++){
				float f_value = i_arg.split(x, m_list_divide).toFloat();
				i_list.addLValue(f_value);
			}
			return i_list;
		}
		
    	virtual PrimitiveList<float> read(ElementId a_id, PrimitiveList<float> a_value){
			TextImporterLog(ame_Log_StartMethod, "read",  "println", "");
			
			int i_order = m_text.getOrder(a_id.getId(), m_split, m_end);
			if(i_order == -1){
				return a_value;
			}
			Note i_arg = m_text.getArgument(i_order, m_split, m_end);
			PrimitiveList<float> i_list;
			int s = i_arg.getSizeNoStartNoEnd( m_list_divide );
			for(int x = 0; x < s; x++){
				float f_value = i_arg.split(x, m_list_divide).toFloat();
				i_list.addLValue(f_value);
			}
			return i_list;
		}
		
		// Savable primitive
    	/*virtual LinkedList<Savable> read(ElementId id, LinkedList<Savable> value)=0;
    	virtual PrimitiveList<Savable> read(ElementId id, PrimitiveList<Savable> value)=0;
    	// virtual PrimitiveMap<float> read(ElementId id, PrimitiveMap<float> value)=0;
		*/
		
    	virtual PrimitiveMap<Note,bool> read(ElementId a_id, PrimitiveMap<Note,bool> a_value){
			TextImporterLog(ame_Log_StartMethod, "read",  "println", "");
			
			int i_key_order = m_text.getOrder(a_id.child("key").getId(), m_split, m_end);
			int i_value_order = m_text.getOrder(a_id.child("value").getId(), m_split, m_end);
			if(i_key_order == -1 || i_value_order == -1){
				return a_value;
			}
			
			Note i_arg_key = m_text.getArgument(i_key_order, m_split, m_end);
			Note i_arg_value = m_text.getArgument(i_value_order, m_split, m_end);
			
			PrimitiveMap<Note,bool> i_map;
			
			int i_key_size = i_arg_key.getSizeNoStartNoEnd( m_list_divide );
			int i_value_size = i_arg_value.getSizeNoStartNoEnd( m_list_divide );
			if(i_key_size != i_value_size){
				return a_value;
			}
			
			for(int x = 0; x < i_key_size; x++){
				Note k = i_arg_key.split(x, m_list_divide);
				bool v = i_arg_value.split(x, m_list_divide) == "1";
				i_map.addLValues(k,v);
			}
			return i_map;
		}
		
    	virtual PrimitiveMap<Note,Note> read(ElementId a_id, PrimitiveMap<Note,Note> a_value){
			TextImporterLog(ame_Log_StartMethod, "read",  "println", "");
			
			int i_key_order = m_text.getOrder(a_id.child("key").getId(), m_split, m_end);
			int i_value_order = m_text.getOrder(a_id.child("value").getId(), m_split, m_end);
			if(i_key_order == -1 || i_value_order == -1){
				return a_value;
			}
			
			Note i_arg_key = m_text.getArgument(i_key_order, m_split, m_end);
			Note i_arg_value = m_text.getArgument(i_value_order, m_split, m_end);
			
			PrimitiveMap<Note,Note> i_map;
			
			int i_key_size = i_arg_key.getSizeNoStartNoEnd( m_list_divide );
			int i_value_size = i_arg_value.getSizeNoStartNoEnd( m_list_divide );
			if(i_key_size != i_value_size){
				return a_value;
			}
			
			for(int x = 0; x < i_key_size; x++){
				Note k = i_arg_key.split(x, m_list_divide);
				Note v = i_arg_value.split(x, m_list_divide);
				i_map.addLValues(k,v);
			}
			return i_map;
		}
		
    	virtual PrimitiveMap<ElementId,Note> read(ElementId a_id, PrimitiveMap<ElementId,Note> a_value){
			TextImporterLog(ame_Log_StartMethod, "read PrimitiveMap<ElementId,Note>",  "println", "");
			
			int i_key_order = m_text.getOrder(a_id.child("key").getId(), m_split, m_end);
			int i_value_order = m_text.getOrder(a_id.child("value").getId(), m_split, m_end);
			if(i_key_order == -1 || i_value_order == -1){
				return a_value;
			}
			
			Note i_arg_key = m_text.getArgument(i_key_order, m_split, m_end);
			Note i_arg_value = m_text.getArgument(i_value_order, m_split, m_end);
			
			int i_key_size = i_arg_key.getSizeNoStartNoEnd( m_list_divide );
			int i_value_size = i_arg_value.getSizeNoStartNoEnd( m_list_divide );

			if(i_key_size != i_value_size){
				return a_value;
			}
			
			PrimitiveMap<ElementId,Note> i_map;
			
			for(int x = 0; x < i_key_size; x++){
				ElementId k = ElementId(i_arg_key.split(x, m_list_divide));
				Note v = i_arg_value.split(x, ',');
				i_map.addLValues(k,v);
			}
			return i_map;
		}
		
		virtual void remove(ElementId a_id){
			TextImporterLog("TextExporter", "remove",  "println", "");
			
			m_text.removeLine(a_id.getId(), m_split, m_end);
		}
		
		virtual void clear(){
			TextImporterLog(ame_Log_StartMethod, "clear",  "println", "");
			m_text.clear();
		}
		
		/////////////////////////////////////////////////////////////////// ids
		virtual void addId(ElementId a_id){
			TextImporterLog(ame_Log_StartMethod, "addId",  "println", "");
			m_ids_list.add(a_id);
		}
		
		virtual void addIds(PrimitiveList<ElementId>& a_ids){
			TextImporterLog(ame_Log_StartMethod, "addIds",  "println", "");
			for(int x = 0; x < a_ids.getPosition(); x++){
				ElementId* f_element_id = a_ids.getByPosition(x);
				m_ids_list.addLValue(*f_element_id);
			}
		}
		
		virtual bool containId(ElementId a_id){
			TextImporterLog(ame_Log_StartMethod, "containId",  "println", "");
			return m_ids_list.containByLValue(a_id);
		}
		
		virtual PrimitiveList<ElementId>& getIds(){
			TextImporterLog(ame_Log_StartMethod, "getIds",  "println", "");
			return m_ids_list;
		}
		
		virtual ElementId getId(int x){
			TextImporterLog(ame_Log_StartMethod, "getId",  "println", "");
			if(x >= m_ids_list.getPosition()){
				return ElementId();
			}
			return m_ids_list[x];
		}
		
		virtual int getIdSize(){
			TextImporterLog(ame_Log_StartMethod, "getIdSize",  "println", "");
			return m_ids_list.getPosition();
		}
		
		virtual void removeId(ElementId i_id){
			TextImporterLog(ame_Log_StartMethod, "removeId",  "println", "");
			m_ids_list.removeDeleteByLValue(i_id);
		}
		
		virtual void removeIds(PrimitiveList<ElementId>& i_ids){
			TextImporterLog(ame_Log_StartMethod, "removeIds",  "println", "");
			for(int x = 0; x < i_ids.getPosition(); x++){
				ElementId* l_eid = i_ids.getByPosition(x);
				m_ids_list.removeDeleteByLValue(*l_eid);
			}
		}
		
		virtual void removeIds(){
			TextImporterLog(ame_Log_StartMethod, "removeIds",  "println", "");
			m_ids_list.resetDelete();
		}
		
		virtual void writeIds(){
			TextImporterLog(ame_Log_StartMethod, "writeIds",  "println", "");
			
			if(m_ids_list.getPosition() == 0){
				TextImporterLog(ame_Log_StartMethod, "writeIds",  "println", "ids.isEmpty");
				m_ids = "";
				return;
			}
			ElementId id = ElementId("transporter.ids");
			
			m_ids = id.getId() + Note(" ");
			for(int x = 0; x < m_ids_list.getPosition(); x++){
				ElementId v = *m_ids_list.getByPosition(x);
				if(x == m_ids_list.getPosition() - 1){
					m_ids += v.getId() + Note("\n");
				}else{
					m_ids += v.getId() + Note(",");
				}
			}
		}
		
		virtual void writeId(ElementId value){
			TextImporterLog(ame_Log_StartMethod, "writeId",  "println", "");
			m_ids_list.put(value);
			ElementId id = ElementId("transporter.ids");
			
			m_ids = id.getId() + Note(" ");
			for(int x = 0; x < m_ids_list.getPosition(); x++){
				ElementId v = *m_ids_list.getByPosition(x);
				if(x == m_ids_list.getPosition() - 1){
					m_ids += v.getId() + Note("\n");
				}else{
					m_ids += v.getId() + Note(",");
				}
			}
		}
		
		virtual void eraseId(ElementId value){
			TextImporterLog(ame_Log_StartMethod, "eraseId",  "println", "");
			if(m_ids_list.getPosition() == 0){
				return;
			}
			if(!m_ids_list.containByLValue(value)){
				return;
			}
			
			m_ids_list.removeDeleteByLValue(value);
			if(m_ids_list.getPosition() == 0){
				return;
			}
			
			ElementId id = ElementId("transporter.ids");
			
			m_ids = id.getId() + Note(" ");
			for(int x = 0; x < m_ids_list.getPosition(); x++){
				ElementId v = *m_ids_list.getByPosition(x);
				if(x == m_ids_list.getPosition() - 1){
					m_ids += v.getId() + Note("\n");
				}else{
					m_ids += v.getId() + Note(",");
				}
			}
		}
		
		virtual void eraseIds(){
			TextImporterLog(ame_Log_StartMethod, "eraseIds",  "println", "");
			m_ids = "";
		}
		
		virtual void clearIds(){
			TextImporterLog(ame_Log_StartMethod, "clearIds",  "println", "");
			m_ids = "";
			m_ids_list.resetDelete();
		}
		
		/////////////////////////////////////////////////////////////////// idType
		virtual void addType(ElementId a_id, Note a_type){
			TextImporterLog(ame_Log_StartMethod, "addType",  "println", "");
			m_types_map.addLValues(a_id, a_type);
		}
		
		virtual void addType(PrimitiveMap<ElementId,Note>& a_types_map){
			TextImporterLog(ame_Log_StartMethod, "addType",  "println", "");
			for(int x = 0; x < a_types_map.getPosition(); x++){
				m_types_map.addLValues(a_types_map.getKey(x), a_types_map.getValue(x));
			}
		}
		
		virtual bool containType(ElementId a_id){
			TextImporterLog(ame_Log_StartMethod, "containIdType",  "println", "");
			return m_types_map.containKeyByLValue(a_id);
		}
		
		virtual PrimitiveMap<ElementId,Note>& getTypes(){
			TextImporterLog(ame_Log_StartMethod, "getIdTypes",  "println", "");
			return m_types_map;
		}
		
		virtual Note getType(ElementId id){
			TextImporterLog(ame_Log_StartMethod, "getIdType",  "println", "");
			return m_types_map.get(id);
		}
		
		virtual int getTypeSize(){
			TextImporterLog(ame_Log_StartMethod, "getIdTypeSize",  "println", "");
			return m_types_map.getPosition();
		}
		
		virtual void removeType(ElementId m_id){
			TextImporterLog(ame_Log_StartMethod, "removeIdType",  "println", "");
			m_types_map.removeDeleteByKeyLValue(m_id);
		}
		
		virtual void removeTypes(PrimitiveMap<ElementId,Note>& a_types_map){
			TextImporterLog(ame_Log_StartMethod, "removeIdTypes",  "println", "");
			for(int x = 0; x < a_types_map.getPosition(); x++){
				m_types_map.removeDeleteByKeyLValue(a_types_map.getKey(x));
			}
		}
		
		virtual void removeTypes(){
			TextImporterLog(ame_Log_StartMethod, "removeIdTypes",  "println", "");
			m_types_map.resetDelete();
		}
		
		virtual void writeTypes(){
			TextImporterLog(ame_Log_StartMethod, "writeIdTypes",  "println", "");
			if(m_types_map.getPosition() == 0){
				TextImporterLog(ame_Log_StartMethod, "writeIdTypes",  "println", "idsType.isEmpty");
				m_types.clear();
				return;
			}
			
			ElementId i_id = ElementId("transporter.idsType");
			
			ElementId i_key_id = i_id.child("key");
			
			ElementId i_value_id = i_id.child("value");

			Note i_var_key = i_key_id.getId() + Note(" ");
			Note i_var_value = i_value_id.getId() + Note(" ");
			
			for(int x = 0; x < m_types_map.getPosition(); x++){
				ElementId k = *m_types_map.getKeyByPosition(x);
				Note v = *m_types_map.getValueByPosition(x);
				if(x == m_types_map.getPosition() - 1){
					i_var_key += k.getId() + Note("\n");
					i_var_value += v + Note("\n");
				}else{
					i_var_key += k.getId() + Note(",");
					i_var_value += v + Note(",");
				}
			}
			
			m_types += i_var_key;
			m_types += i_var_value;
		}
		
		virtual void writeType(ElementId a_id, Note a_type){
			TextImporterLog(ame_Log_StartMethod, "writeIdType",  "println", "");
			
			m_types_map.addLValues(a_id, a_type);
			
			ElementId i_id = ElementId("transporter.types");
			
			ElementId i_key_id = i_id.child("key");
			
			ElementId i_value_id = i_id.child("value");
			
			Note i_var_key = i_key_id.getId() + Note(" ");
			Note i_var_value = i_value_id.getId() + Note(" ");
			
			for(int x = 0; x < m_types_map.getPosition(); x++){
				ElementId k = *m_types_map.getKeyByPosition(x);
				Note v = *m_types_map.getValueByPosition(x);
				if(x == m_types_map.getPosition() - 1){
					i_var_key += k.getId() + Note("\n");
					i_var_value += v + Note("\n");
				}else{
					i_var_key += k.getId() + Note(",");
					i_var_value += v + Note(",");
				}
			}
			
			m_types += i_var_key;
			m_types += i_var_value;
		}
		
		virtual void eraseType(ElementId a_id){
			TextImporterLog(ame_Log_StartMethod, "eraseIdType",  "println", "");
			m_types_map.removeDeleteByKeyLValue(a_id);
			
			if(m_types_map.getPosition() == 0){
				m_types.clear();
				return;
			}
			
			ElementId i_id = ElementId("transporter.idsType");
			
			ElementId i_key_id = i_id.child("key");
			
			ElementId i_value_id = i_id.child("value");
			
			Note i_var_key = i_key_id.getId() + Note(" ");
			Note i_var_value = i_value_id.getId() + Note(" ");
			
			for(int x = 0; x < m_types_map.getPosition(); x++){
				ElementId k = *m_types_map.getKeyByPosition(x);
				Note v = *m_types_map.getValueByPosition(x);
				if(x == m_types_map.getPosition() - 1){
					i_var_key += k.getId() + Note("\n");
					i_var_value += v + Note("\n");
				}else{
					i_var_key += k.getId() + Note(",");
					i_var_value += v + Note(",");
				}
			}
			
			m_types += i_var_key;
			m_types += i_var_value;
		}
		
		virtual void eraseTypes(){
			TextImporterLog(ame_Log_StartMethod, "eraseIdTypes",  "println", "");
			m_types.clear();
		}
		
		virtual void clearTypes(){
			TextImporterLog(ame_Log_StartMethod, "clearIds",  "println", "");
			m_types.clear();
			m_types_map.resetDelete();
		}
		
		/////////////////////////////////////////////////////////////////// tags
		virtual void addTag(ElementId m_id, Note m_type){
			TextImporterLog(ame_Log_StartMethod, "addTag",  "println", "");
			m_tags_map.addLValues(m_id, m_type);
		}
		
		virtual void addTag(PrimitiveMap<ElementId,Note>& m_idsType){
			TextImporterLog(ame_Log_StartMethod, "addTag",  "println", "");
			for(int x = 0; x < m_idsType.getPosition(); x++){
				m_tags_map.addLValues(m_idsType.getKey(x), m_idsType.getValue(x));
			}
		}
		
		virtual bool containTag(ElementId id){
			TextImporterLog(ame_Log_StartMethod, "containTag",  "println", "");
			return m_tags_map.containKeyByLValue(id);
		}
		
		virtual PrimitiveMap<ElementId,Note>& getTags(){
			TextImporterLog(ame_Log_StartMethod, "getTags",  "println", "");
			return m_tags_map;
		}
		
		virtual Note getTag(ElementId id){
			TextImporterLog(ame_Log_StartMethod, "getTag",  "println", "");
			return m_tags_map.get(id);
		}
		
		virtual int getTagSize(){
			TextImporterLog(ame_Log_StartMethod, "getTagSize",  "println", "");
			return m_tags_map.getPosition();
		}
		
		virtual void removeTag(ElementId m_id){
			TextImporterLog(ame_Log_StartMethod, "removeTag",  "println", "");
			m_tags_map.removeDeleteByKeyLValue(m_id);
		}
		
		virtual void removeTags(PrimitiveMap<ElementId,Note>& m_idsType){
			TextImporterLog(ame_Log_StartMethod, "removeTags",  "println", "");
			for(int x = 0; x < m_idsType.getPosition(); x++){
				m_tags_map.removeDeleteByKeyLValue(m_idsType.getKey(x));
			}
		}
		
		virtual void removeTags(){
			TextImporterLog(ame_Log_StartMethod, "removeTags",  "println", "");
			m_tags_map.resetDelete();
		}
		
		virtual void writeTags(){
			TextImporterLog(ame_Log_StartMethod, "writeTags",  "println", "");
			if(m_tags_map.getPosition() == 0){
				TextImporterLog(ame_Log_StartMethod, "writeTags",  "println", "m_tags_map.isEmpty");
				m_tags.clear();
				return;
			}
			
			ElementId i_id = ElementId("transporter.tags");
			
			ElementId i_key_id = i_id.child("key");
			
			ElementId i_value_id = i_id.child("value");
			
			Note i_var_key = i_key_id.getId() + Note(" ");
			Note i_var_value = i_value_id.getId() + Note(" ");
			
			for(int x = 0; x < m_tags_map.getPosition(); x++){
				ElementId k = *m_tags_map.getKeyByPosition(x);
				Note v = *m_tags_map.getValueByPosition(x);
				if(x == m_tags_map.getPosition() - 1){
					i_var_key += k.getId() + Note("\n");
					i_var_value += v + Note("\n");
				}else{
					i_var_key += k.getId() + Note(",");
					i_var_value += v + Note(",");
				}
			}
			
			m_tags += i_var_key;
			m_tags += i_var_value;
		}
		
		virtual void writeTag(ElementId a_id, Note a_type){
			TextImporterLog(ame_Log_StartMethod, "writeTag",  "println", "");
			
			m_tags_map.addLValues(a_id, a_type);
			
			ElementId i_id = ElementId("transporter.tags");
			
			ElementId i_key_id = i_id.child("key");
			
			ElementId i_value_id = i_id.child("value");
			
			Note i_var_key = i_key_id.getId() + Note(" ");
			Note i_var_value = i_value_id.getId() + Note(" ");
			
			for(int x = 0; x < m_tags_map.getPosition(); x++){
				ElementId k = *m_tags_map.getKeyByPosition(x);
				Note v = *m_tags_map.getValueByPosition(x);
				if(x == m_tags_map.getPosition() - 1){
					i_var_key += k.getId() + Note("\n");
					i_var_value += v + Note("\n");
				}else{
					i_var_key += k.getId() + Note(",");
					i_var_value += v + Note(",");
				}
			}
			
			m_tags += i_var_key;
			m_tags += i_var_value;
		}
		
		virtual void eraseTag(ElementId a_id){
			TextImporterLog(ame_Log_StartMethod, "eraseTag",  "println", "");
			m_tags_map.removeDeleteByKeyLValue(a_id);
			
			if(m_tags_map.getPosition() == 0){
				m_tags.clear();
				return;
			}
			
			ElementId i_id = ElementId("transporter.tags");
			
			ElementId i_key_id = i_id.child("key");
			
			ElementId i_value_id = i_id.child("value");
			
			Note i_var_key = i_key_id.getId() + Note(" ");
			Note i_var_value = i_value_id.getId() + Note(" ");
			
			for(int x = 0; x < m_tags_map.getPosition(); x++){
				ElementId k = *m_tags_map.getKeyByPosition(x);
				Note v = *m_tags_map.getValueByPosition(x);
				if(x == m_tags_map.getPosition() - 1){
					i_var_key += k.getId() + Note("\n");
					i_var_value += v + Note("\n");
				}else{
					i_var_key += k.getId() + Note(",");
					i_var_value += v + Note(",");
				}
			}
			
			m_tags += i_var_key;
			m_tags += i_var_value;
		}
		
		virtual void eraseTags(){
			TextImporterLog(ame_Log_StartMethod, "eraseIdType",  "println", "");
			m_tags.clear();
		}
		
		virtual void clearTags(){
			TextImporterLog(ame_Log_StartMethod, "clearIds",  "println", "");
			m_tags.clear();
			m_tags_map.resetDelete();
		}
		
		virtual void setMessage(Message* a_message){
			TextImporterLog(ame_Log_StartMethod, "setMessage",  "println", "");
			if(a_message == nullptr){
				return;
			}
			setText(a_message->text());
			fix();
		}
		
		virtual void read(MonkeyFile* a_file, Note a_path){
			TextImporterLog(ame_Log_StartMethod, "read",  "println", "");
			if(a_file == nullptr){
				return;
			}
			setText( a_file->readText(a_path) );
			fix();
		}
		
		virtual void write(MonkeyFile* a_file, Note a_path){
			TextImporterLog(ame_Log_StartMethod, "write",  "println", "");
			if(a_file == nullptr){
				TextImporterLog(ame_Log_StartMethod, "write",  "println", a_path);
				return;
			}
			// file->fastWriteText(m_tags, path);
			// file->fastWriteText(m_ids, path);
			// file->fastWriteText(m_types, path);
			// file->fastWriteText(m_text, path);
			
			a_file->fastWriteText(this->toNote(), a_path);
		}
		
		virtual void setText(Note strng){
			TextImporterLog(ame_Log_StartMethod, "setText",  "println", Note("text ") + strng);
			m_text = strng;
		}
		
		virtual Note getText(){
			return m_text;
		}
		
		virtual void setIdsText(Note strng){
			TextImporterLog(ame_Log_StartMethod, "setm_ids",  "println", Note("text ") + strng);
			m_ids = strng;
		}
		
		virtual Note getIdsText(){
			return m_ids;
		}
		
		virtual void setTypesText(Note strng){
			TextImporterLog(ame_Log_StartMethod, "setm_types",  "println", Note("text ") + strng);
			m_types = strng;
		}
		
		virtual Note getTypesText(){
			return m_types;
		}
		
		virtual void setTagsText(Note strng){
			TextImporterLog(ame_Log_StartMethod, "setTags",  "println", Note("text ") + strng);
			m_tags = strng;
		}
		
		virtual Note getTagsText(){
			return m_tags;
		}
		
		virtual Note getExporterText(){
			return m_tags + m_ids + m_types + m_text;
		}
		
		virtual void fix(){
			TextImporterLog(ame_Log_StartMethod, "fix",  "println", "");
			m_ids_list = read(ElementId("transporter.ids"), PrimitiveList<ElementId>());
			m_types_map = read(ElementId("transporter.types"), PrimitiveMap<ElementId,Note>());
			m_tags_map = read(ElementId("transporter.tags"), PrimitiveMap<ElementId,Note>());
			
			eraseIds();
			eraseTypes();
			eraseTags();
			
			writeIds();
			writeTypes();
			writeTags();
			
			remove("transporter.tags.key");
			remove("transporter.tags.value");
			
			remove("transporter.ids.key");
			remove("transporter.ids.value");
			
			remove("transporter.types.key");
			remove("transporter.types.value");
			
			TextImporterLog(ame_Log_StartMethod, "fix",  "println", Note("m_tags ") + m_tags);
			TextImporterLog(ame_Log_StartMethod, "fix",  "println", Note("m_ids ") + m_ids);
			TextImporterLog(ame_Log_StartMethod, "fix",  "println", Note("m_types ") + m_types);
			TextImporterLog(ame_Log_StartMethod, "fix",  "println", Note("text ") + m_text);
		}
		
		virtual Note toNote(){
			return m_tags + m_ids + m_types + m_text;
		}
		
	protected:
		Note m_text;
		Note m_ids = "";
		Note m_types;
		Note m_tags;
		PrimitiveList<ElementId> m_ids_list;
		PrimitiveMap<ElementId,Note> m_types_map;
		PrimitiveMap<ElementId,Note> m_tags_map;
		
		char m_list_divide = ',';
		char m_split = ' ';
		char m_end = '\n';
};

}

#endif