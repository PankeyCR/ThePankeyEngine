
/**
 *
 * @author PankeyCR - Manuel Sanchez Badilla
 *
 */
 
#ifndef CONFIGURATION_TextExporter_hpp
#define CONFIGURATION_TextExporter_hpp

	#include "ame_Enviroment.hpp"

	#if defined(DISABLE_TextExporter)
		#define TextExporter_hpp

		#define IMPLEMENTATION_TextExporter
		#define IMPLEMENTING_TextExporter
	#else
		#if defined(DISABLE_IMPLEMENTATION_TextExporter)
			#define IMPLEMENTATION_TextExporter
			#define IMPLEMENTING_TextExporter
		#endif
	#endif
#endif

#ifndef TextExporter_hpp
#define TextExporter_hpp
#define TextExporter_AVAILABLE

#ifndef DISABLE_IMPLEMENTATION_TextExporter
	#define IMPLEMENTATION_TextExporter IMPLEMENTATION(public TextExporter)
	#define IMPLEMENTING_TextExporter IMPLEMENTING(public TextExporter)
#endif

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
#include "MonkeyExporter.hpp"
#include "Message.hpp"

#ifdef TextExporter_LogApp
	#include "ame_Logger_config.hpp"
	#include "ame_Logger.hpp"
	
	#define TextExporterLog(location,method,type,mns) ame_Log(this,location,"TextExporter",method,type,mns)
#else
	#ifdef TextExporter_LogDebugApp
		#include "ame_Logger_config.hpp"
		#include "ame_Logger.hpp"
		
		#define TextExporterLog(location,method,type,mns) ame_LogDebug(this,location,"TextExporter",method,type)
	#else
		#define TextExporterLog(location,method,type,mns) 
	#endif
#endif

namespace ame{

class TextExporter : public MonkeyExporter{
    public:
		TextExporter(){
			TextExporterLog(ame_Log_StartMethod, "Constructor", "println", "");
			TextExporterLog(ame_Log_EndMethod, "Constructor", "println", "");
		}
		TextExporter(const Note& c_note){
			TextExporterLog(ame_Log_StartMethod, "Constructor", "println", "");
			m_text = c_note;
			TextExporterLog(ame_Log_EndMethod, "Constructor", "println", "");
		}
		virtual ~TextExporter(){
			TextExporterLog(ame_Log_StartMethod, "Destructor", "println", "");
			TextExporterLog(ame_Log_EndMethod, "Destructor", "println", "");
		}
		
    	virtual PrimitiveList<ElementId> read(ElementId a_id, PrimitiveList<ElementId> a_value){
			TextExporterLog(ame_Log_StartMethod, "read",  "println", "");
			int i_order = m_text.getOrder(a_id.getId(), m_split, m_end);
			if(i_order == -1){
				TextExporterLog(ame_Log_EndMethod, "read", "println", "i_order == -1");
				return a_value;
			}
			Note i_arg = m_text.getArgument(i_order, m_split, m_end);
			PrimitiveList<ElementId> i_list;
			int i_size = i_arg.getSizeNoStartNoEnd( m_list_divide );
			for(int x = 0; x < i_size; x++){
				ElementId f_element_id= i_arg.split(x, m_list_divide );
				i_list.addLValue(f_element_id);
			}
			TextExporterLog(ame_Log_EndMethod, "read", "println", "");
			return i_list;
		}
		
    	virtual PrimitiveMap<ElementId,Note> read(ElementId a_id, PrimitiveMap<ElementId,Note> a_value){
			TextExporterLog(ame_Log_StartMethod, "read",  "println", "");
			
			int i_key = m_text.getOrder(a_id.child("key").getId(), m_split, m_end);
			int i_value = m_text.getOrder(a_id.child("value").getId(), m_split, m_end);
			if(i_key == -1 || i_value == -1){
				TextExporterLog(ame_Log_EndMethod, "read", "println", "i_key == -1 || i_value == -1");
				return a_value;
			}
			
			Note i_arg_key = m_text.getArgument(i_key, m_split, m_end);
			Note i_arg_value = m_text.getArgument(i_value, m_split, m_end);
			
			int i_key_size = i_arg_key.getSizeNoStartNoEnd( m_list_divide );
			int i_value_size = i_arg_value.getSizeNoStartNoEnd( m_list_divide );
			if(i_key_size != i_value_size){
				TextExporterLog(ame_Log_EndMethod, "read", "println", "s_key != s_value");
				return a_value;
			}
			
			PrimitiveMap<ElementId,Note> i_map;
			
			for(int x = 0; x < i_key_size; x++){
				ElementId f_element_id = ElementId(i_arg_key.split(x, m_list_divide ));
				Note f_note = i_arg_value.split(x, m_list_divide );
				i_map.addLValues(f_element_id, f_note);
			}
			TextExporterLog(ame_Log_EndMethod, "read", "println", "");
			return i_map;
		}
		
		// int primitive
    	virtual bool write(ElementId a_id, const int& a_value){
			TextExporterLog(ame_Log_StartMethod, "write",  "println", Note(a_value));
			TextExporterLog(ame_Log_Statement, "write",  "println", Note("making the id: ") + a_id.getId() + Note(" ") + Note(a_value) + Note("\n"));
			m_text += a_id.getId() + Note(" ") + Note(a_value) + Note("\n");
			TextExporterLog(ame_Log_EndMethod, "read", "println", "");
			return true;
		}
    	virtual bool write(ElementId a_id, const LinkedList<int>& a_value){
			TextExporterLog(ame_Log_StartMethod, "write",  "println", "");
			if(a_value.getPosition() == 0){
				TextExporterLog(ame_Log_EndMethod, "write", "println", "");
				return false;
			}
			m_text += a_id.getId() + Note(" ");
			for(int x = 0; x < a_value.getPosition(); x++){
				int v = *a_value.getByPosition(x);
				if(x == a_value.getPosition() - 1){
					m_text += Note(v) + Note("\n");
				}else{
					m_text += Note(v) + Note(",");
				}
			}
			TextExporterLog(ame_Log_EndMethod, "read", "println", "");
			return true;
		}
		
    	virtual bool write(ElementId a_id, const PrimitiveList<int>& a_value){
			TextExporterLog(ame_Log_StartMethod, "write",  "println", "");
			if(a_value.getPosition() == 0){
				TextExporterLog(ame_Log_EndMethod, "write", "println", "");
				return false;
			}
			m_text += a_id.getId() + Note(" ");
			for(int x = 0; x < a_value.getPosition(); x++){
				int v = *a_value.getByPosition(x);
				if(x == a_value.getPosition() - 1){
					m_text += Note(v) + Note("\n");
				}else{
					m_text += Note(v) + Note(",");
				}
			}
			TextExporterLog(ame_Log_EndMethod, "write", "println", "");
			return true;
		}
		
		// ByteArray primitive
    	virtual bool write(ElementId a_id, const ByteArray& a_value){
			TextExporterLog(ame_Log_StartMethod, "write",  "println", toNote(a_value));
			m_text += a_id.getId() + Note(" ") + toNote(a_value) + "\n";
			TextExporterLog(ame_Log_EndMethod, "write", "println", "");
			return true;
		}
		
    	virtual bool write(ElementId a_id, const LinkedList<ByteArray>& a_value){
			TextExporterLog(ame_Log_StartMethod, "write",  "println", "");
			if(a_value.getPosition() == 0){
				TextExporterLog(ame_Log_EndMethod, "write", "println", "");
				return false;
			}
			m_text += a_id.getId() + Note(" ");
			for(int x = 0; x < a_value.getPosition(); x++){
				ByteArray f_byte_array = *a_value.getByPosition(x);
				if(x == a_value.getPosition() - 1){
					m_text += toNote(f_byte_array) + Note("\n");
				}else{
					m_text += toNote(f_byte_array) + Note(",");
				}
			}
			TextExporterLog(ame_Log_EndMethod, "write", "println", "");
			return true;
		}
		
    	virtual bool write(ElementId a_id, const PrimitiveList<ByteArray>& a_value){
			TextExporterLog(ame_Log_StartMethod, "write",  "println", "");
			if(a_value.getPosition() == 0){
				TextExporterLog(ame_Log_EndMethod, "write", "println", "");
				return false;
			}
			m_text += a_id.getId() + Note(" ");
			for(int x = 0; x < a_value.getPosition(); x++){
				ByteArray f_byte_array = *a_value.getByPosition(x);
				if(x == a_value.getPosition() - 1){
					m_text += toNote(f_byte_array) + Note("\n");
				}else{
					m_text += toNote(f_byte_array) + Note(",");
				}
			}
			TextExporterLog(ame_Log_EndMethod, "read", "println", "");
			return true;
		}
		
		// bool primitive
    	virtual bool write(ElementId a_id, const bool& a_value){
			TextExporterLog(ame_Log_StartMethod, "write",  "println", Note(a_value));
			m_text += a_id.getId() + Note(" ") + Note(a_value) + "\n";
			TextExporterLog(ame_Log_EndMethod, "write", "println", "");
			return true;
		}
		
    	virtual bool write(ElementId a_id, const LinkedList<bool>& a_value){
			TextExporterLog(ame_Log_StartMethod, "write",  "println", "");
			if(a_value.getPosition() == 0){
				TextExporterLog(ame_Log_EndMethod, "write", "println", "");
				return false;
			}
			m_text += a_id.getId() + Note(" ");
			for(int x = 0; x < a_value.getPosition(); x++){
				bool v = *a_value.getByPosition(x);
				if(x == a_value.getPosition() - 1){
					m_text += Note(v) + Note("\n");
				}else{
					m_text += Note(v) + Note(",");
				}
			}
			TextExporterLog(ame_Log_EndMethod, "write", "println", "");
			return true;
		}
		
    	virtual bool write(ElementId a_id, const PrimitiveList<bool>& a_value){
			TextExporterLog(ame_Log_StartMethod, "write",  "println", "");
			if(a_value.getPosition() == 0){
				TextExporterLog(ame_Log_EndMethod, "write", "println", "");
				return false;
			}
			m_text += a_id.getId() + Note(" ");
			for(int x = 0; x < a_value.getPosition(); x++){
				bool v = *a_value.getByPosition(x);
				if(x == a_value.getPosition() - 1){
					m_text += Note(v) + Note("\n");
				}else{
					m_text += Note(v) + Note(",");
				}
			}
			TextExporterLog(ame_Log_EndMethod, "write", "println", "");
			return true;
		}
		
		// char primitive
    	virtual bool write(ElementId a_id, const char& a_value){
			TextExporterLog(ame_Log_StartMethod, "write",  "println", Note(a_value));
			m_text += a_id.getId() + Note(" ") + Note(a_value) + "\n";
			TextExporterLog(ame_Log_EndMethod, "write", "println", "");
			return true;
		}
		
    	virtual bool write(ElementId a_id, const LinkedList<char>& a_value){
			TextExporterLog(ame_Log_StartMethod, "write",  "println", "");
			if(a_value.getPosition() == 0){
				TextExporterLog(ame_Log_EndMethod, "write", "println", "");
				return false;
			}
			m_text += a_id.getId() + Note(" ");
			for(int x = 0; x < a_value.getPosition(); x++){
				char v = *a_value.getByPosition(x);
				if(x == a_value.getPosition() - 1){
					m_text += Note(v) + Note("\n");
				}else{
					m_text += Note(v) + Note(",");
				}
			}
			TextExporterLog(ame_Log_EndMethod, "write", "println", "");
			return true;
		}
		
    	virtual bool write(ElementId a_id, const PrimitiveList<char>& a_value){
			TextExporterLog(ame_Log_StartMethod, "write",  "println", "");
			if(a_value.getPosition() == 0){
				TextExporterLog(ame_Log_EndMethod, "write", "println", "");
				return false;
			}
			m_text += a_id.getId() + Note(" ");
			for(int x = 0; x < a_value.getPosition(); x++){
				char v = *a_value.getByPosition(x);
				if(x == a_value.getPosition() - 1){
					m_text += Note(v) + Note("\n");
				}else{
					m_text += Note(v) + Note(",");
				}
			}
			TextExporterLog(ame_Log_EndMethod, "write", "println", "");
			return true;
		}

		// ElementId primitive
    	virtual bool write(ElementId a_id, const ElementId& a_value){
			TextExporterLog(ame_Log_StartMethod, "write",  "println", a_value.getId());
			m_text += a_id.getId() + Note(" ") + a_value.getId() + "\n";
			TextExporterLog(ame_Log_EndMethod, "write", "println", "");
			return true;
		}
		
    	virtual bool write(ElementId a_id, const PrimitiveList<ElementId>& a_value){
			TextExporterLog(ame_Log_StartMethod, "write",  "println", "");
			if(a_value.getPosition() == 0){
			TextExporterLog(ame_Log_EndMethod, "write", "println", "");
				return false;
			}
			m_text += a_id.getId() + Note(" ");
			for(int x = 0; x < a_value.getPosition(); x++){
				ElementId v = *a_value.getByPosition(x);
				if(x == a_value.getPosition() - 1){
					m_text += v.getId() + Note("\n");
				}else{
					m_text += v.getId() + Note(",");
				}
			}
			TextExporterLog(ame_Log_EndMethod, "write", "println", "");
			return true;
		}
		
		// Note primitive
    	virtual bool write(ElementId a_id, const Note& a_value){
			TextExporterLog(ame_Log_StartMethod, "write",  "println", a_value);
			m_text += a_id.getId() + Note(" ") + a_value + "\n";
			TextExporterLog(ame_Log_EndMethod, "write", "println", "");
			return true;
		}
		
    	virtual bool write(ElementId a_id, const char* a_value){
			TextExporterLog(ame_Log_StartMethod, "write",  "println", Note(a_value));
			m_text += a_id.getId() + Note(" ") + Note(a_value) + "\n";
			TextExporterLog(ame_Log_EndMethod, "write", "println", "");
			return true;
		}
		
    	virtual bool write(ElementId a_id, const LinkedList<Note>& a_value){
			TextExporterLog(ame_Log_StartMethod, "write",  "println", "");
			if(a_value.getPosition() == 0){
			TextExporterLog(ame_Log_EndMethod, "write", "println", "");
				return false;
			}
			m_text += a_id.getId() + Note(" ");
			for(int x = 0; x < a_value.getPosition(); x++){
				Note v = *a_value.getByPosition(x);
				if(x == a_value.getPosition() - 1){
					m_text += v + Note("\n");
				}else{
					m_text += v + Note(",");
				}
			}
			TextExporterLog(ame_Log_EndMethod, "write", "println", "");
			return true;
		}
		
    	virtual bool write(ElementId a_id, const PrimitiveList<Note>& a_value){
			TextExporterLog(ame_Log_StartMethod, "write",  "println", "");
			if(a_value.getPosition() == 0){
			TextExporterLog(ame_Log_EndMethod, "write", "println", "");
				return false;
			}
			m_text += a_id.getId() + Note(" ");
			for(int x = 0; x < a_value.getPosition(); x++){
				Note v = *a_value.getByPosition(x);
				if(x == value.getPosition() - 1){
					m_text += v + Note("\n");
				}else{
					m_text += v + Note(",");
				}
			}
			TextExporterLog(ame_Log_EndMethod, "write", "println", "");
			return true;
		}
		
		
		// long primitive
    	virtual bool write(ElementId a_id, const long& a_value){
			TextExporterLog(ame_Log_StartMethod, "write",  "println", Note(a_value));
			m_text += a_id.getId() + Note(" ") + Note(a_value) + "\n";
			TextExporterLog(ame_Log_EndMethod, "write", "println", "");
			return true;
		}
		
    	virtual bool write(ElementId a_id, const LinkedList<long>& a_value){
			TextExporterLog(ame_Log_StartMethod, "write",  "println", "");
			if(a_value.getPosition() == 0){
			TextExporterLog(ame_Log_EndMethod, "write", "println", "");
				return false;
			}
			m_text += a_id.getId() + Note(" ");
			for(int x = 0; x < a_value.getPosition(); x++){
				long v = *a_value.getByPosition(x);
				if(x == a_value.getPosition() - 1){
					m_text += Note(v) + Note("\n");
				}else{
					m_text += Note(v) + Note(",");
				}
			}
			TextExporterLog(ame_Log_EndMethod, "write", "println", "");
			return true;
		}
		
    	virtual bool write(ElementId a_id, const PrimitiveList<long>& a_value){
			TextExporterLog(ame_Log_StartMethod, "write",  "println", "");
			if(a_value.getPosition() == 0){
			TextExporterLog(ame_Log_EndMethod, "write", "println", "");
				return false;
			}
			m_text += a_id.getId() + Note(" ");
			for(int x = 0; x < a_value.getPosition(); x++){
				long v = *a_value.getByPosition(x);
				if(x == a_value.getPosition() - 1){
					m_text += Note(v) + Note("\n");
				}else{
					m_text += Note(v) + Note(",");
				}
			}
			TextExporterLog(ame_Log_EndMethod, "write", "println", "");
			return true;
		}
		
		// float primitive
    	virtual bool write(ElementId a_id, const float& a_value){
			TextExporterLog(ame_Log_StartMethod, "write",  "println", Note(a_value));
			m_text += a_id.getId() + Note(" ") + Note(a_value) + "\n";
			TextExporterLog(ame_Log_EndMethod, "write", "println", "");
			return true;
		}
		
    	virtual bool write(ElementId a_id, const LinkedList<float>& a_value){
			TextExporterLog(ame_Log_StartMethod, "write",  "println", "");
			if(a_value.getPosition() == 0){
			TextExporterLog(ame_Log_EndMethod, "write", "println", "");
				return false;
			}
			m_text += a_id.getId() + Note(" ");
			for(int x = 0; x < a_value.getPosition(); x++){
				float v = *a_value.getByPosition(x);
				if(x == a_value.getPosition() - 1){
					m_text += Note(v) + Note("\n");
				}else{
					m_text += Note(v) + Note(",");
				}
			}
			TextExporterLog(ame_Log_EndMethod, "write", "println", "");
			return true;
		}
		
    	virtual bool write(ElementId a_id, const PrimitiveList<float>& a_value){
			TextExporterLog(ame_Log_StartMethod, "write",  "println", "");
			if(a_value.getPosition() == 0){
			TextExporterLog(ame_Log_EndMethod, "write", "println", "");
				return false;
			}
			m_text += a_id.getId() + Note(" ");
			for(int x = 0; x < a_value.getPosition(); x++){
				float v = *a_value.getByPosition(x);
				if(x == a_value.getPosition() - 1){
					m_text += Note(v) + Note("\n");
				}else{
					m_text += Note(v) + Note(",");
				}
			}
			TextExporterLog(ame_Log_EndMethod, "write", "println", "");
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

    	virtual bool write(ElementId a_id, const PrimitiveMap<Note,Note>& a_value){
			TextExporterLog(ame_Log_StartMethod, "write",  "println", "");
			if(a_value.getPosition() == 0){
			TextExporterLog(ame_Log_EndMethod, "write", "println", "");
				return false;
			}
			ElementId i_key_id = a_id.child("key");
			ElementId i_value_id = a_id.child("value");
			
			Note i_var_key = i_key_id.getId() + Note(" ");
			Note i_var_value = i_value_id.getId() + Note(" ");
			
			for(int x = 0; x < a_value.getPosition(); x++){
				Note k = *a_value.getKeyByPosition(x);
				Note v = *a_value.getByPosition(x);
				if(x == a_value.getPosition() - 1){
					i_var_key += k + Note("\n");
					i_var_value += v + Note("\n");
				}else{
					i_var_key += k + Note(",");
					i_var_value += v + Note(",");
				}
			}
			
			m_text += i_var_key;
			m_text += i_var_value;
			TextExporterLog(ame_Log_EndMethod, "write", "println", "");
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

    	virtual bool write(ElementId a_id, const PrimitiveMap<Note,bool>& a_value){
			TextExporterLog(ame_Log_StartMethod, "write",  "println", "");
			if(a_value.getPosition() == 0){
			TextExporterLog(ame_Log_EndMethod, "write", "println", "");
				return false;
			}
			ElementId i_key_id = a_id.child("key");
			ElementId i_value_id = a_id.child("value");

			Note i_var_key = i_key_id.getId() + Note(" ");
			Note i_var_value = i_value_id.getId() + Note(" ");
			
			for(int x = 0; x < a_value.getPosition(); x++){
				Note k = *a_value.getKeyByPosition(x);
				bool v = *a_value.getByPosition(x);
				if(x == a_value.getPosition() - 1){
					i_var_key += k + Note("\n");
					i_var_value += Note(v) + Note("\n");
				}else{
					i_var_key += k + Note(",");
					i_var_value += Note(v) + Note(",");
				}
			}
			
			m_text += i_var_key;
			m_text += i_var_value;
			TextExporterLog(ame_Log_EndMethod, "write", "println", "");
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
		
    	virtual bool write(ElementId a_id, const PrimitiveMap<ElementId,Note>& a_value){
			TextExporterLog(ame_Log_StartMethod, "write",  "println", "");
			if(a_value.getPosition() == 0){
				TextExporterLog(ame_Log_EndMethod, "write", "println", "");
				return false;
			}
			ElementId i_key_id = a_id.child("key");
			ElementId i_value_id = a_id.child("value");

			Note i_var_key = i_key_id.getId() + Note(" ");
			Note i_var_value = i_value_id.getId() + Note(" ");
			
			for(int x = 0; x < a_value.getPosition(); x++){
				ElementId k = *a_value.getKeyByPosition(x);
				Note v = *a_value.getByPosition(x);
				if(x == a_value.getPosition() - 1){
					i_var_key += k.getId() + Note("\n");
					i_var_value += v + Note("\n");
				}else{
					i_var_key += k.getId() + Note(",");
					i_var_value += v + Note(",");
				}
			}
			
			m_text += i_var_key;
			m_text += i_var_value;
			TextExporterLog(ame_Log_EndMethod, "write", "println", "");
			return true;
		}
		
		virtual void remove(ElementId a_id){
			TextExporterLog(ame_Log_StartMethod, "remove",  "println", "");
			m_text.removeLine(a_id.getId(), m_split, m_end);
			TextExporterLog(ame_Log_EndMethod, "remove", "println", "");
		}
		
		virtual void clear(){
			TextExporterLog(ame_Log_StartMethod, "clear",  "println", "");
			m_text.clear();
			TextExporterLog(ame_Log_EndMethod, "clear", "println", "");
		}
		
		/////////////////////////////////////////////////////////////////// ids
		virtual void addId(ElementId a_id){
			TextExporterLog(ame_Log_StartMethod, "addId",  "println", "");
			ids.add(a_id);
			TextExporterLog(ame_Log_EndMethod, "addId", "println", "");
		}
		
		virtual void addIds(PrimitiveList<ElementId>& a_ids_list){
			TextExporterLog(ame_Log_StartMethod, "addIds",  "println", "");
			for(int x = 0; x < a_ids_list.getPosition(); x++){
				ElementId* f_element_id = a_ids_list.getByPosition(x);
				m_ids_list.addLValue(*f_element_id);
			}
			TextExporterLog(ame_Log_EndMethod, "addIds", "println", "");
		}
		
		virtual bool containId(ElementId a_id){
			TextExporterLog(ame_Log_StartMethod, "containId",  "println", "");
			TextExporterLog(ame_Log_EndMethod, "containId", "println", "");
			return m_ids_list.containByLValue(a_id);
		}
		
		virtual PrimitiveList<ElementId>& getIds(){
			TextExporterLog(ame_Log_StartMethod, "getIds",  "println", "");
			TextExporterLog(ame_Log_EndMethod, "getIds", "println", "");
			return m_ids_list;
		}
		
		virtual ElementId getId(int x){
			TextExporterLog(ame_Log_StartMethod, "getId",  "println", "");
			if(x >= m_ids_list.getPosition()){
				TextExporterLog(ame_Log_EndMethod, "getId", "println", "");
				return ElementId();
			}
			TextExporterLog(ame_Log_EndMethod, "getId", "println", "");
			return m_ids_list[x];
		}
		
		virtual int getIdSize(){
			TextExporterLog(ame_Log_StartMethod, "getIdSize",  "println", "");
			TextExporterLog(ame_Log_EndMethod, "getIdSize", "println", "");
			return m_ids_list.getPosition();
		}
		
		virtual void removeId(ElementId a_id){
			TextExporterLog(ame_Log_StartMethod, "removeId",  "println", "");
			m_ids_list.removeDeleteByLValua(a_id);
			TextExporterLog(ame_Log_EndMethod, "removeId", "println", "");
		}
		
		virtual void removeIds(PrimitiveList<ElementId>& a_ids_list){
			TextExporterLog(ame_Log_StartMethod, "removeIds",  "println", "");
			for(int x = 0; x < a_ids_list.getPosition(); x++){
				ElementId* f_element_id = a_ids_list.getByPosition(x);
				m_ids_list.removeDeleteByLValue(*f_element_id);
			}
			TextExporterLog(ame_Log_EndMethod, "removeIds", "println", "");
		}
		
		virtual void removeIds(){
			TextExporterLog(ame_Log_StartMethod, "removeIds",  "println", "");
			m_ids_list.resetDelete();
			TextExporterLog(ame_Log_EndMethod, "removeIds", "println", "");
		}
		
		virtual void writeIds(){
			TextExporterLog(ame_Log_StartMethod, "writeIds",  "println", "");
			
			if(m_ids_list.getPosition() == 0){
				TextExporterLog(ame_Log_StartMethod, "writeIds",  "println", "ids.isEmpty");
				m_ids.clear();
				TextExporterLog(ame_Log_EndMethod, "writeIds", "println", "");
				return;
			}
			ElementId i_id = ElementId("transporter.ids");
			
			m_ids = i_id.getId() + Note(" ");
			for(int x = 0; x < m_ids_list.getPosition(); x++){
				ElementId f_element_id = *m_ids_list.getByPosition(x);
				if(x == m_ids_list.getPosition() - 1){
					m_ids += f_element_id.getId() + Note("\n");
				}else{
					m_ids += f_element_id.getId() + Note(",");
				}
			}
			TextExporterLog(ame_Log_EndMethod, "writeIds", "println", "");
		}
		
		virtual void writeId(ElementId a_value){
			TextExporterLog(ame_Log_StartMethod, "writeId",  "println", "");
			m_ids_list.put(a_value);

			ElementId i_id = ElementId("transporter.ids");
			
			m_ids = i_id.getId() + Note(" ");

			for(int x = 0; x < m_ids_list.getPosition(); x++){
				ElementId f_element_id = *m_ids_list.getByPosition(x);
				if(x == m_ids_list.getPosition() - 1){
					m_ids += f_element_id.getId() + Note("\n");
				}else{
					m_ids += f_element_id.getId() + Note(",");
				}
			}
			TextExporterLog(ame_Log_EndMethod, "writeId", "println", "");
		}
		
		virtual void eraseId(ElementId a_value){
			TextExporterLog(ame_Log_StartMethod, "eraseId",  "println", "");
			if(m_ids_list.getPosition() == 0){
				TextExporterLog(ame_Log_EndMethod, "eraseId", "println", "");
				return;
			}
			if(!m_ids_list.containByLValue(a_value)){
				TextExporterLog(ame_Log_EndMethod, "eraseId", "println", "");
				return;
			}
			
			m_ids_list.removeDeleteByLValue(a_value);
			if(m_ids_list.getPosition() == 0){
				TextExporterLog(ame_Log_EndMethod, "eraseId", "println", "");
				return;
			}
			
			ElementId i_id = ElementId("transporter.ids");
			
			m_ids = i_id.getId() + Note(" ");
			for(int x = 0; x < m_ids_list.getPosition(); x++){
				ElementId f_element_id = *m_ids_list.getByPosition(x);
				if(x == m_ids_list.getPosition() - 1){
					m_ids += f_element_id.getId() + Note("\n");
				}else{
					m_ids += f_element_id.getId() + Note(",");
				}
			}
			TextExporterLog(ame_Log_EndMethod, "eraseId", "println", "");
		}
		
		virtual void eraseIds(){
			TextExporterLog(ame_Log_StartMethod, "eraseIds",  "println", "");
			m_ids.clear();
			TextExporterLog(ame_Log_EndMethod, "eraseIds", "println", "");
		}
		
		virtual void clearIds(){
			TextExporterLog(ame_Log_StartMethod, "clearIds",  "println", "");
			m_ids.clear();
			m_ids_list.resetDelete();
			TextExporterLog(ame_Log_EndMethod, "clearIds", "println", "");
		}
		
		/////////////////////////////////////////////////////////////////// idType
		virtual void addType(ElementId a_id, Note a_type){
			TextExporterLog(ame_Log_StartMethod, "addIdType",  "println", "");
			m_types_map.addLValues(a_id, a_type);
			TextExporterLog(ame_Log_EndMethod, "addIdType", "println", "");
		}
		
		virtual void addType(PrimitiveMap<ElementId,Note>& a_types){
			TextExporterLog(ame_Log_StartMethod, "addType",  "println", "");
			for(int x = 0; x < a_types.getPosition(); x++){
				m_types_map.addLValues(a_types.getKey(x), a_types.getValue(x));
			}
			TextExporterLog(ame_Log_EndMethod, "addType", "println", "");
		}
		
		virtual bool containType(ElementId a_id){
			TextExporterLog(ame_Log_StartMethod, "containType",  "println", "");
			TextExporterLog(ame_Log_EndMethod, "containType", "println", "");
			return m_types_map.containKeyByLValue(a_id);
		}
		
		virtual PrimitiveMap<ElementId,Note>& getTypes(){
			TextExporterLog(ame_Log_StartMethod, "getTypes",  "println", "");
			TextExporterLog(ame_Log_EndMethod, "getTypes", "println", "");
			return m_types_map;
		}
		
		virtual Note getType(ElementId a_id){
			TextExporterLog(ame_Log_StartMethod, "getType",  "println", "");
			TextExporterLog(ame_Log_EndMethod, "getType", "println", "");
			return m_types_map.get(a_id);
		}
		
		virtual int getTypeSize(){
			TextExporterLog(ame_Log_StartMethod, "getTypeSize",  "println", "");
			TextExporterLog(ame_Log_EndMethod, "getTypeSize", "println", "");
			return m_types_map.getPosition();
		}
		
		virtual void removeIdType(ElementId a_id){
			TextExporterLog(ame_Log_StartMethod, "removeIdType",  "println", "");
			m_types_map.removeDeleteByLValue(a_id);
			TextExporterLog(ame_Log_EndMethod, "removeIdType", "println", "");
		}
		
		virtual void removeTypes(PrimitiveMap<ElementId,Note>& a_types_map){
			TextExporterLog(ame_Log_StartMethod, "removeTypes",  "println", "");
			for(int x = 0; x < a_types_map.getPosition(); x++){
				m_types_map.removeDeleteByLValue(a_types_map.getKey(x));
			}
			TextExporterLog(ame_Log_EndMethod, "removeTypes", "println", "");
		}
		
		virtual void removeTypes(){
			TextExporterLog(ame_Log_StartMethod, "removeTypes",  "println", "");
			m_types_map.resetDelete();
			TextExporterLog(ame_Log_EndMethod, "removeTypes", "println", "");
		}
		
		virtual void writeTypes(){
			TextExporterLog(ame_Log_StartMethod, "writeTypes",  "println", "");
			if(m_types_map.getPosition() == 0){
				TextExporterLog(ame_Log_StartMethod, "writeTypes",  "println", "ids.isEmpty");
				m_types.clear();
				TextExporterLog(ame_Log_EndMethod, "writeTypes", "println", "");
				return;
			}
			
			ElementId i_id = ElementId("transporter.types");
			
			ElementId i_key_id = i_id.child("key");
			
			ElementId i_value_id = i_id.child("value");
			
			Note i_var_key = i_key_id.getId() + Note(" ");
			Note i_var_value = i_value_id.getId() + Note(" ");
			
			for(int x = 0; x < m_types_map.getPosition(); x++){
				ElementId k = *m_types_map.getKeyByPosition(x);
				Note v = *m_types_map.getByPosition(x);
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
			TextExporterLog(ame_Log_EndMethod, "writeTypes", "println", "");
		}
		
		virtual void writeType(ElementId a_id, Note a_type){
			TextExporterLog(ame_Log_StartMethod, "writeType",  "println", "");
			
			m_types_map.addLValues(a_id, a_type);
			
			ElementId i_id = ElementId("transporter.types");
			
			ElementId i_key_id = i_id.child("key");
			
			ElementId i_value_id = i_id.child("value");
			
			Note i_var_key = i_key_id.getId() + Note(" ");
			Note i_var_value = i_value_id.getId() + Note(" ");
			
			for(int x = 0; x < m_types_map.getPosition(); x++){
				ElementId k = *m_types_map.getKeyByPosition(x);
				Note v = *m_types_map.getByPosition(x);
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
			TextExporterLog(ame_Log_EndMethod, "writeIdType", "println", "");
		}
		
		virtual void eraseType(ElementId a_id){
			TextExporterLog(ame_Log_StartMethod, "eraseType",  "println", "");
			m_types_map.removeDeleteByLValue(a_id);
			
			if(m_types_map.getPosition() == 0){
				m_types.clear();
				TextExporterLog(ame_Log_EndMethod, "eraseType", "println", "");
				return;
			}
			
			ElementId i_id = ElementId("transporter.types");
			
			ElementId i_key_id = i_id.child("key");
			
			ElementId i_value_id = i_id.child("value");
			
			Note i_var_key = i_key_id.getId() + Note(" ");
			Note i_var_value = i_value_id.getId() + Note(" ");
			
			for(int x = 0; x < m_types_map.getPosition(); x++){
				ElementId k = *m_types_map.getKeyByPosition(x);
				Note v = *m_types_map.getByPosition(x);
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
			TextExporterLog(ame_Log_EndMethod, "eraseType", "println", "");
		}
		
		virtual void eraseTypes(){
			TextExporterLog(ame_Log_StartMethod, "eraseTypes",  "println", "");
			m_types.clear();
			TextExporterLog(ame_Log_EndMethod, "eraseTypes", "println", "");
		}
		
		virtual void clearTypes(){
			TextExporterLog(ame_Log_StartMethod, "clearTypes",  "println", "");
			m_types.clear();
			m_types_map.resetDelete();
			TextExporterLog(ame_Log_EndMethod, "clearTypes", "println", "");
		}
		
		/////////////////////////////////////////////////////////////////// tags
		virtual void addTag(ElementId a_id, Note a_type){
			TextExporterLog(ame_Log_StartMethod, "addTag",  "println", "");
			m_tags_map.addLValues(a_id, a_type);
			TextExporterLog(ame_Log_EndMethod, "addTag", "println", "");
		}
		
		virtual void addTag(PrimitiveMap<ElementId,Note>& a_tags_map){
			TextExporterLog(ame_Log_StartMethod, "addTag",  "println", "");
			for(int x = 0; x < a_tags_map.getPosition(); x++){
				m_tags_map.addLValues(a_tags_map.getKey(x), a_tags_map.getValue(x));
			}
			TextExporterLog(ame_Log_EndMethod, "addTag", "println", "");
		}
		
		virtual bool containTag(ElementId a_id){
			TextExporterLog(ame_Log_StartMethod, "containTag",  "println", "");
			TextExporterLog(ame_Log_EndMethod, "containTag", "println", "");
			return m_tags_map.containKeyByLValue(a_id);
		}
		
		virtual PrimitiveMap<ElementId,Note>& getTags(){
			TextExporterLog(ame_Log_StartMethod, "getTags",  "println", "");
			TextExporterLog(ame_Log_EndMethod, "getTags", "println", "");
			return m_tags_map;
		}
		
		virtual Note getTag(ElementId a_id){
			TextExporterLog(ame_Log_StartMethod, "getTag",  "println", "");
			TextExporterLog(ame_Log_EndMethod, "getTag", "println", "");
			return m_tags_map.get(a_id);
		}
		
		virtual int getTagSize(){
			TextExporterLog(ame_Log_StartMethod, "getTagSize",  "println", "");
			TextExporterLog(ame_Log_EndMethod, "getTagSize", "println", "");
			return m_tags_map.getPosition();
		}
		
		virtual void removeTag(ElementId m_id){
			TextExporterLog(ame_Log_StartMethod, "removeTag",  "println", "");
			m_tags_map.removeDeleteByLValue(m_id);
			TextExporterLog(ame_Log_EndMethod, "removeTag", "println", "");
		}
		
		virtual void removeTags(PrimitiveMap<ElementId,Note>& a_types){
			TextExporterLog(ame_Log_StartMethod, "removeTags",  "println", "");
			for(int x = 0; x < a_types.getPosition(); x++){
				m_tags_map.removeDeleteByLValue(a_types.getKey(x));
			}
			TextExporterLog(ame_Log_EndMethod, "removeTags", "println", "");
		}
		
		virtual void removeTags(){
			TextExporterLog(ame_Log_StartMethod, "removeTags",  "println", "");
			m_tags_map.resetDelete();
			TextExporterLog(ame_Log_EndMethod, "removeTags", "println", "");
		}
		
		virtual void writeTags(){
			TextExporterLog(ame_Log_StartMethod, "writeTags",  "println", "");
			if(m_tags_map.isEmpty()){
				m_tags.clear();
				TextExporterLog(ame_Log_EndMethod, "writeTags", "println", "m_tags.isEmpty()");
				return;
			}
			
			ElementId i_id = ElementId("transporter.tags");
			
			ElementId i_key_id = i_id.child("key");
			
			ElementId i_value_id = i_id.child("value");
			
			Note i_var_key = i_key_id.getId() + Note(" ");
			Note i_var_value = i_value_id.getId() + Note(" ");
			
			for(int x = 0; x < m_tags_map.getPosition(); x++){
				ElementId k = *m_tags_map.getKeyByPosition(x);
				Note v = *m_tags_map.getByPosition(x);
				if(x == m_tags_map.getPosition() - 1){
					i_var_key += k.getId() + Note("\n");
					i_var_value += v + Note("\n");
				}else{
					i_var_key += k.getId() + Note(",");
					i_var_value += v + Note(",");
				}
			}
			
			m_tags = i_var_key;
			m_tags += i_var_value;
			TextExporterLog(ame_Log_EndMethod, "writeTags", "println", "");
		}
		
		virtual void writeTag(ElementId a_id, Note a_tag){
			TextExporterLog(ame_Log_StartMethod, "writeTag",  "println", "");
			
			m_tags_map.addLValues(a_id, a_tag);
			
			ElementId i_id = ElementId("transporter.tags");
			
			ElementId i_keyId = i_id.child("key");
			
			ElementId i_valueId = i_id.child("value");
			
			Note i_var_key = i_keyId.getId() + Note(" ");
			Note i_var_value = i_valueId.getId() + Note(" ");
			
			for(int x = 0; x < m_tags_map.getPosition(); x++){
				ElementId k = *m_tags_map.getKeyByPosition(x);
				Note v = *m_tags_map.getByPosition(x);
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
			TextExporterLog(ame_Log_EndMethod, "writeTag", "println", "");
		}
		
		virtual void eraseTag(ElementId a_id){
			TextExporterLog(ame_Log_StartMethod, "eraseTag",  "println", "");
			m_tags_map.removeDeleteByLValue(a_id);
			
			if(m_tags_map.getPosition() == 0){
				m_tags.clear();
				TextExporterLog(ame_Log_EndMethod, "eraseTag", "println", "");
				return;
			}
			
			ElementId i_id = ElementId("transporter.tags");
			
			ElementId i_keyId = i_id.child("key");
			
			ElementId i_valueId = i_id.child("value");
			
			Note var_key = i_keyId.getId() + Note(" ");
			Note var_value = i_valueId.getId() + Note(" ");
			
			for(int x = 0; x < m_tags_map.getPosition(); x++){
				ElementId k = *m_tags_map.getKeyByPosition(x);
				Note v = *m_tags_map.getByPosition(x);
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
			TextExporterLog(ame_Log_EndMethod, "eraseTag", "println", "");
		}
		
		virtual void eraseTags(){
			TextExporterLog(ame_Log_StartMethod, "eraseTags",  "println", "");
			m_tags.clear();
			TextExporterLog(ame_Log_EndMethod, "eraseTags", "println", "");
		}
		
		virtual void clearTags(){
			TextExporterLog(ame_Log_StartMethod, "clearTags",  "println", "");
			m_tags.clear();
			m_tags_map.resetDelete();
			TextExporterLog(ame_Log_EndMethod, "clearTags", "println", "");
		}
		
		virtual void setMessage(Message* a_message){
			TextExporterLog(ame_Log_StartMethod, "setMessage",  "println", "");
			if(a_message == nullptr){
			TextExporterLog(ame_Log_EndMethod, "setMessage", "println", "");
				return;
			}
			setText( a_message->text() );
			fix();
			TextExporterLog(ame_Log_EndMethod, "setMessage", "println", "");
		}
		
		virtual void read(MonkeyFile* a_file, Note a_path){
			TextExporterLog(ame_Log_StartMethod, "read",  "println", "");
			if(a_file == nullptr){
			TextExporterLog(ame_Log_EndMethod, "read", "println", "");
				return;
			}
			setText( a_file->readText(a_path) );
			fix();
			TextExporterLog(ame_Log_EndMethod, "read", "println", "");
		}
		
		virtual void write(MonkeyFile* a_file, Note a_path){
			TextExporterLog(ame_Log_StartMethod, "write",  "println", "");
			TextExporterLog(ame_Log_StartMethod, "write",  "println", "a_path");
			TextExporterLog(ame_Log_StartMethod, "write",  "println", a_path);
			if(a_file == nullptr){
				TextExporterLog(ame_Log_EndMethod, "write",  "println", "a_file == nullptr");
				return;
			}
			
			a_file->fastWriteText(this->toNote(), a_path);
			TextExporterLog(ame_Log_EndMethod, "write", "println", "");
		}
		
		virtual void setText(Note a_note){
			TextExporterLog(ame_Log_StartMethod, "setText",  "println", Note("text ") + a_note);
			m_text = a_note;
			TextExporterLog(ame_Log_EndMethod, "setText", "println", "");
		}
		
		virtual Note getText(){
			TextExporterLog(ame_Log_EndMethod, "getText", "println", "");
			TextExporterLog(ame_Log_EndMethod, "getText", "println", "");
			return m_text;
		}
		
		virtual void setIdsText(Note a_note){
			TextExporterLog(ame_Log_StartMethod, "setIds",  "println", Note("text ") + a_note);
			m_ids = a_note;
			TextExporterLog(ame_Log_EndMethod, "setIds", "println", "");
		}
		
		virtual Note getIdsText(){
			TextExporterLog(ame_Log_EndMethod, "getIds", "println", "");
			TextExporterLog(ame_Log_EndMethod, "getIds", "println", "");
			return m_ids;
		}
		
		virtual void getTypesText(Note a_note){
			TextExporterLog(ame_Log_StartMethod, "getTypes",  "println", Note("text ") + strng);
			m_types = a_note;
			TextExporterLog(ame_Log_EndMethod, "getTypes", "println", "");
		}
		
		virtual Note getTypesText(){
			TextExporterLog(ame_Log_StartMethod, "getTypes", "println", "");
			TextExporterLog(ame_Log_EndMethod, "getTypes", "println", "");
			return m_types;
		}
		
		virtual void setTagsText(Note a_note){
			TextExporterLog(ame_Log_StartMethod, "setTags",  "println", Note("text ") + strng);
			m_tags = a_note;
			TextExporterLog(ame_Log_EndMethod, "setTags", "println", "");
		}
		
		virtual Note getTagsText(){
			TextExporterLog(ame_Log_StartMethod, "getTags", "println", "");
			TextExporterLog(ame_Log_EndMethod, "getTags", "println", "");
			return m_tags;
		}
		
		virtual Note getExporterText(){
			TextExporterLog(ame_Log_StartMethod, "getExporterText", "println", "");
			TextExporterLog(ame_Log_EndMethod, "getExporterText", "println", "");
			return m_tags + m_ids + m_types + m_text;
		}
		
		virtual void fix(){
			TextExporterLog(ame_Log_StartMethod, "fix",  "println", "");
			m_tags = read(ElementId("transporter.tags"), PrimitiveMap<ElementId,Note>());
			m_ids = read(ElementId("transporter.ids"), PrimitiveList<ElementId>());
			m_types = read(ElementId("transporter.types"), PrimitiveMap<ElementId,Note>());
			
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
			
			TextExporterLog(ame_Log_Statement, "fix",  "println", Note("tags ") + m_tags);
			TextExporterLog(ame_Log_Statement, "fix",  "println", Note("ids ") + m_ids);
			TextExporterLog(ame_Log_Statement, "fix",  "println", Note("types ") + m_types);
			TextExporterLog(ame_Log_Statement, "fix",  "println", Note("text ") + m_text);
			TextExporterLog(ame_Log_EndMethod, "fix", "println", "");
		}
		
		virtual Note toNote(){
			TextExporterLog(ame_Log_StartMethod, "toNote", "println", "");
			TextExporterLog(ame_Log_EndMethod, "toNote", "println", "");
			return m_tags + m_ids + m_types + m_text;
		}
		
	protected:
		Note m_text = "";
		Note m_ids = "";
		Note m_types = "";
		Note m_tags = "";
		PrimitiveList<ElementId> m_ids_list;
		PrimitiveMap<ElementId,Note> m_types_map;
		PrimitiveMap<ElementId,Note> m_tags_map;
		
		char m_elementid_divider = ':';
		char m_list_divide = ',';
		char m_split = ' ';
		char m_end = '\n';
};

}

#endif