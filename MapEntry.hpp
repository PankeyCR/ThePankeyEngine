
#ifndef MapEntry_hpp
#define MapEntry_hpp
#define MapEntry_AVAILABLE 

#ifdef MapEntry_LogApp
	#include "ame_Logger_config.hpp"
	#include "ame_Logger.hpp"

	#define MapEntryLog(location,method,type,mns) ame_Log((void*)this,location,"MapEntry",method,type,mns)
	#define const_MapEntryLog(location,method,type,mns)
#else
	#ifdef MapEntry_LogDebugApp
		#include "ame_Logger_config.hpp"
		#include "ame_Logger.hpp"

		#define MapEntryLog(location,method,type,mns) ame_LogDebug((void*)this,location,"MapEntry",method,type)
		#define const_MapEntryLog(location,method,type,mns)
	#else
		#define MapEntryLog(location,method,type,mns)
		#define const_MapEntryLog(location,method,type,mns)
	#endif
#endif

namespace ame{

template <class K,class V>
class MapEntry{
    public:
		MapEntry(){
			MapEntryLog(ame_Log_StartMethod, "Constructor", "println", "");
			MapEntryLog(ame_Log_EndMethod, "Constructor", "println", "");
		}
		
		MapEntry(K* c_key, V* c_value){
			MapEntryLog(ame_Log_StartMethod, "Constructor", "println", "");
			m_key = c_key;
			m_value = c_value;
			MapEntryLog(ame_Log_EndMethod, "Constructor", "println", "");
		}
		
		MapEntry(const MapEntry<K,V>& c_map_entry){
			MapEntryLog(ame_Log_StartMethod, "Constructor", "println", "");
			m_key = c_map_entry.m_key;
			m_value = c_map_entry.m_value;
			MapEntryLog(ame_Log_EndMethod, "Constructor", "println", "");
		}
		
		MapEntry(MapEntry<K,V>&& c_map_entry){
			MapEntryLog(ame_Log_StartMethod, "Constructor", "println", "");
			m_key = c_map_entry.m_key;
			m_value = c_map_entry.m_value;
			c_map_entry.m_key = nullptr;
			c_map_entry.m_value = nullptr;
			MapEntryLog(ame_Log_EndMethod, "Constructor", "println", "");
		}
		
		virtual ~MapEntry(){
			MapEntryLog(ame_Log_StartMethod, "Destructor", "println", "");
			MapEntryLog(ame_Log_EndMethod, "Destructor", "println", "");
		}
		
		virtual K* getKey()const{
			const_MapEntryLog(ame_Log_StartMethod, "getKey", "println", "");
			const_MapEntryLog(ame_Log_EndMethod, "getKey", "println", "");
			return this->m_key;
		}
		virtual V* getValue()const{
			const_MapEntryLog(ame_Log_StartMethod, "getValue", "println", "");
			const_MapEntryLog(ame_Log_EndMethod, "getValue", "println", "");
			return this->m_value;
		}
		
		virtual MapEntry& operator=(const MapEntry<K,V>& a_map_entry){
			MapEntryLog(ame_Log_StartMethod, "operator=", "println", "");
			m_key = a_map_entry.m_key;
			m_value = a_map_entry.m_value;
			MapEntryLog(ame_Log_EndMethod, "operator=", "println", "");
			return *this;
		}
		
		virtual const MapEntry& operator=(MapEntry<K,V>&& a_map_entry){
			MapEntryLog(ame_Log_StartMethod, "operator=", "println", "");
			m_key = a_map_entry.m_key;
			m_value = a_map_entry.m_value;
			a_map_entry.m_key = nullptr;
			a_map_entry.m_value = nullptr;
			MapEntryLog(ame_Log_EndMethod, "operator=", "println", "");
			return *this;
		}
		
		virtual bool operator!=(const MapEntry<K,V>& a_map_entry){
			MapEntryLog(ame_Log_StartMethod, "operator!=", "println", "");
			MapEntryLog(ame_Log_EndMethod, "operator!=", "println", "");
			return m_key != a_map_entry.m_key && m_value != a_map_entry.m_value;
		}
		
		virtual bool operator==(const MapEntry<K,V>& a_map_entry){
			MapEntryLog(ame_Log_StartMethod, "operator==", "println", "");
			MapEntryLog(ame_Log_EndMethod, "operator==", "println", "");
			return m_key == a_map_entry.m_key && m_value == a_map_entry.m_value;
		}
		
		virtual bool isNull()const{
			const_MapEntryLog(ame_Log_StartMethod, "isNull", "println", "");
			const_MapEntryLog(ame_Log_EndMethod, "isNull", "println", "");
			return m_key == nullptr && m_value == nullptr;
		}
		
		virtual bool deleteEntry(){
			MapEntryLog(ame_Log_StartMethod, "deleteEntry", "println", "");
			if(m_key == nullptr && m_value == nullptr){
				MapEntryLog(ame_Log_EndMethod, "deleteEntry", "println", "");
				return false;
			}
			if(m_key != nullptr){
				delete this->m_key;
			}
			if(m_value == nullptr){
				delete this->m_value;
			}
			MapEntryLog(ame_Log_EndMethod, "deleteEntry", "println", "");
			return true;
		}
	
	protected:
		K* m_key = nullptr;
		V* m_value = nullptr;
};

}

#endif