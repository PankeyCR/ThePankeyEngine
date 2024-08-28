
#ifndef RawMapEntry_hpp
#define RawMapEntry_hpp

#ifdef RawMapEntry_LogApp
	#include "pankey_Logger.hpp"
	#define RawMapEntryLog(location,method,type,mns) pankey_Log((void*)this,location,"RawMapEntry",method,type,mns)
#else
	#define RawMapEntryLog(location,method,type,mns)
#endif

namespace pankey{

template <class K,class V>
class RawMapEntry{
    public:
		RawMapEntry(){
			RawMapEntryLog(pankey_Log_StartMethod, "Constructor", "println", "");
			RawMapEntryLog(pankey_Log_EndMethod, "Constructor", "println", "");
		}
		
		RawMapEntry(K* c_key, V* c_value){
			RawMapEntryLog(pankey_Log_StartMethod, "Constructor", "println", "");
			m_key = c_key;
			m_value = c_value;
			RawMapEntryLog(pankey_Log_EndMethod, "Constructor", "println", "");
		}
		
		RawMapEntry(const RawMapEntry<K,V>& c_map_entry){
			RawMapEntryLog(pankey_Log_StartMethod, "Constructor", "println", "");
			m_key = c_map_entry.m_key;
			m_value = c_map_entry.m_value;
			RawMapEntryLog(pankey_Log_EndMethod, "Constructor", "println", "");
		}
		
		RawMapEntry(RawMapEntry<K,V>&& c_map_entry){
			RawMapEntryLog(pankey_Log_StartMethod, "Constructor", "println", "");
			m_key = c_map_entry.m_key;
			m_value = c_map_entry.m_value;
			c_map_entry.m_key = nullptr;
			c_map_entry.m_value = nullptr;
			RawMapEntryLog(pankey_Log_EndMethod, "Constructor", "println", "");
		}
		
		virtual ~RawMapEntry(){
			RawMapEntryLog(pankey_Log_StartMethod, "Destructor", "println", "");
			RawMapEntryLog(pankey_Log_EndMethod, "Destructor", "println", "");
		}
		
		virtual K* getKey()const{
			RawMapEntryLog(pankey_Log_StartMethod, "getKey", "println", "");
			RawMapEntryLog(pankey_Log_EndMethod, "getKey", "println", "");
			return this->m_key;
		}
		virtual V* getValue()const{
			RawMapEntryLog(pankey_Log_StartMethod, "getValue", "println", "");
			RawMapEntryLog(pankey_Log_EndMethod, "getValue", "println", "");
			return this->m_value;
		}
		
		virtual RawMapEntry& operator=(const RawMapEntry<K,V>& a_map_entry){
			RawMapEntryLog(pankey_Log_StartMethod, "operator=", "println", "");
			m_key = a_map_entry.m_key;
			m_value = a_map_entry.m_value;
			RawMapEntryLog(pankey_Log_EndMethod, "operator=", "println", "");
			return *this;
		}
		
		virtual const RawMapEntry& operator=(RawMapEntry<K,V>&& a_map_entry){
			RawMapEntryLog(pankey_Log_StartMethod, "operator=", "println", "");
			m_key = a_map_entry.m_key;
			m_value = a_map_entry.m_value;
			a_map_entry.m_key = nullptr;
			a_map_entry.m_value = nullptr;
			RawMapEntryLog(pankey_Log_EndMethod, "operator=", "println", "");
			return *this;
		}
		
		virtual bool operator!=(const RawMapEntry<K,V>& a_map_entry){
			RawMapEntryLog(pankey_Log_StartMethod, "operator!=", "println", "");
			RawMapEntryLog(pankey_Log_EndMethod, "operator!=", "println", "");
			return m_key != a_map_entry.m_key && m_value != a_map_entry.m_value;
		}
		
		virtual bool operator==(const RawMapEntry<K,V>& a_map_entry){
			RawMapEntryLog(pankey_Log_StartMethod, "operator==", "println", "");
			RawMapEntryLog(pankey_Log_EndMethod, "operator==", "println", "");
			return m_key == a_map_entry.m_key && m_value == a_map_entry.m_value;
		}
		
		virtual bool isNull()const{
			RawMapEntryLog(pankey_Log_StartMethod, "isNull", "println", "");
			RawMapEntryLog(pankey_Log_EndMethod, "isNull", "println", "");
			return m_key == nullptr && m_value == nullptr;
		}
		
		virtual bool deleteEntry(){
			RawMapEntryLog(pankey_Log_StartMethod, "deleteEntry", "println", "");
			if(m_key == nullptr && m_value == nullptr){
				RawMapEntryLog(pankey_Log_EndMethod, "deleteEntry", "println", "");
				return false;
			}
			if(m_key != nullptr){
				delete this->m_key;
			}
			if(m_value != nullptr){
				delete this->m_value;
			}
			RawMapEntryLog(pankey_Log_EndMethod, "deleteEntry", "println", "");
			return true;
		}
		
		virtual bool deleteKeyEntry(){
			RawMapEntryLog(pankey_Log_StartMethod, "deleteKeyEntry", "println", "");
			if(m_key == nullptr){
				RawMapEntryLog(pankey_Log_EndMethod, "deleteKeyEntry", "println", "");
				return false;
			}
			if(m_key != nullptr){
				delete this->m_key;
			}
			RawMapEntryLog(pankey_Log_EndMethod, "deleteKeyEntry", "println", "");
			return true;
		}
		
		virtual bool deleteValueEntry(){
			RawMapEntryLog(pankey_Log_StartMethod, "deleteKeyEntry", "println", "");
			if(m_value == nullptr){
				RawMapEntryLog(pankey_Log_EndMethod, "deleteEntry", "println", "");
				return false;
			}
			if(m_value != nullptr){
				delete this->m_value;
			}
			RawMapEntryLog(pankey_Log_EndMethod, "deleteKeyEntry", "println", "");
			return true;
		}
	
	protected:
		K* m_key = nullptr;
		V* m_value = nullptr;
};

}

#endif