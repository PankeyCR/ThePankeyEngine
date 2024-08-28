
#ifndef RawPointerMap_hpp
#define RawPointerMap_hpp

#include "RawMapEntry.hpp"

#ifdef RawPointerMap_LogApp
	#include "pankey_Logger.hpp"
	#define RawPointerMapLog(location,method,type,mns) pankey_Log((void*)this,location,"RawPointerMap",method,type,mns)
#else
	#define RawPointerMapLog(location,method,type,mns)
#endif

namespace pankey{

template <class K,class V>
class RawPointerMap{
    public:
		virtual ~RawPointerMap(){
			RawPointerMapLog(pankey_Log_StartMethod, "Constructor", "println", "");
			RawPointerMapLog(pankey_Log_EndMethod, "Constructor", "println", "");
		}

		virtual bool isEmpty()const=0;

		virtual void setOwner(bool a_owning){
			RawPointerMapLog(pankey_Log_StartMethod, "setOwner", "println", "");
			this->m_key_owner = a_owning;
			this->m_value_owner = a_owning;
			RawPointerMapLog(pankey_Log_EndMethod, "setOwner", "println", "");
		}
		virtual bool isOwner()const{
			RawPointerMapLog(pankey_Log_StartMethod, "isOwner", "println", "");
			RawPointerMapLog(pankey_Log_EndMethod, "isOwner", "println", "");
			return this->m_key_owner && this->m_value_owner;
		}
		virtual bool hasOwner()const{
			RawPointerMapLog(pankey_Log_StartMethod, "isOwner", "println", "");
			RawPointerMapLog(pankey_Log_EndMethod, "isOwner", "println", "");
			return this->m_key_owner || this->m_value_owner;
		}

		virtual void setKeyOwner(bool a_owning){
			RawPointerMapLog(pankey_Log_StartMethod, "setKeyOwner", "println", "");
			this->m_key_owner = a_owning;
			RawPointerMapLog(pankey_Log_EndMethod, "setKeyOwner", "println", "");
		}
		virtual bool isKeyOwner()const{
			RawPointerMapLog(pankey_Log_StartMethod, "isKeyOwner", "println", "");
			RawPointerMapLog(pankey_Log_EndMethod, "isKeyOwner", "println", "");
			return this->m_key_owner;
		}

		virtual void setValueOwner(bool a_owning){
			RawPointerMapLog(pankey_Log_StartMethod, "setValueOwner", "println", "");
			this->m_value_owner = a_owning;
			RawPointerMapLog(pankey_Log_EndMethod, "setValueOwner", "println", "");
		}
		virtual bool isValueOwner()const{
			RawPointerMapLog(pankey_Log_StartMethod, "isValueOwner", "println", "");
			RawPointerMapLog(pankey_Log_EndMethod, "isValueOwner", "println", "");
			return this->m_value_owner;
		}
		virtual void setPosition(int a_position){
			RawPointerMapLog(pankey_Log_StartMethod, "setPosition", "println", a_position);
			this->m_position = a_position;
			RawPointerMapLog(pankey_Log_EndMethod, "setPosition", "println", "");
		}
		virtual int getPosition()const{
			RawPointerMapLog(pankey_Log_StartMethod, "getPosition", "println", "");
			RawPointerMapLog(pankey_Log_EndMethod, "getPosition", "println", "");
			return this->m_position;
		}

		virtual void setSize(int a_size){
			RawPointerMapLog(pankey_Log_StartMethod, "setSize", "println", "");
			this->m_size = a_size;
			RawPointerMapLog(pankey_Log_EndMethod, "setSize", "println", "");
		}
		virtual int getSize()const{
			RawPointerMapLog(pankey_Log_StartMethod, "getSize", "println", "");
			RawPointerMapLog(pankey_Log_EndMethod, "getSize", "println", "");
			return this->m_size;
		}
		
		virtual int hasAvailableSize()const{
			RawPointerMapLog(pankey_Log_StartMethod, "getSize", "println", "");
			RawPointerMapLog(pankey_Log_EndMethod, "getSize", "println", "");
			return this->m_position < this->m_size  && this->m_size != 0;
		}

		virtual void addMove(RawPointerMap<K,V>* a_map){
			RawPointerMapLog(pankey_Log_StartMethod, "addMove", "println", "");
			for(int x = 0; x < a_map->getPosition(); x++){
				K* k = a_map->getKeyByPosition(x);
				V* v = a_map->getValueByPosition(x);
				this->addPointers(k,v);
				a_map->setRawMapEntryByPosition(x, RawMapEntry<K,V>());
			}
			RawPointerMapLog(pankey_Log_EndMethod, "addMove", "println", "");
		}

		virtual void addDuplicate(RawPointerMap<K,V>* a_map){
			RawPointerMapLog(pankey_Log_StartMethod, "addDuplicate", "println", "");
			for(int x = 0; x < a_map->getPosition(); x++){
				K* k = a_map->getKeyByPosition(x);
				V* v = a_map->getValueByPosition(x);
				this->addPointers(k,v);
			}
			RawPointerMapLog(pankey_Log_EndMethod, "addDuplicate", "println", "");
		}

		virtual RawMapEntry<K,V> addPointers(K* a_key, V* a_value)=0;
		virtual RawMapEntry<K,V> addRawMapEntry(RawMapEntry<K,V> a_map_entry)=0;

		virtual RawMapEntry<K,V> putPointers(K* a_key, V* a_value){
			RawPointerMapLog(pankey_Log_StartMethod, "putPointers", "println", "");
			if(this->containPairPointers(a_key,a_value)){
				RawPointerMapLog(pankey_Log_EndMethod, "putPointers", "println", "");
				return RawMapEntry<K,V>(a_key, a_value);
			}
			RawPointerMapLog(pankey_Log_EndMethod, "putPointers", "println", "");
			return this->addPointers(a_key, a_value);
		}
		virtual RawMapEntry<K,V> putRawMapEntry(RawMapEntry<K,V> a_map_entry){
			RawPointerMapLog(pankey_Log_StartMethod, "putRawMapEntry", "println", "");
			if(this->containRawMapEntry(a_map_entry)){
				RawPointerMapLog(pankey_Log_EndMethod, "putRawMapEntry", "println", "");
				return RawMapEntry<K,V>(a_map_entry);
			}
			RawPointerMapLog(pankey_Log_EndMethod, "putRawMapEntry", "println", "");
			return this->addRawMapEntry(a_map_entry);
		}

		virtual RawMapEntry<K,V> setPointers(K* a_key, V* a_value)=0;
		virtual RawMapEntry<K,V> setRawMapEntry(RawMapEntry<K,V> a_map_entry)=0;

		virtual RawMapEntry<K,V> setKeyPointerByPosition(int a_position, K* a_key)=0;
		virtual RawMapEntry<K,V> setValuePointerByPosition(int a_position, V* a_value)=0;

		virtual RawMapEntry<K,V> setRawMapEntryByPosition(int a_position, RawMapEntry<K,V> a_map_entry)=0;

		virtual bool containPairPointers(K* a_key, V* a_value)=0;
		virtual bool containRawMapEntry(RawMapEntry<K,V> a_map_entry)=0;

		virtual bool containKeyByPointer(K* a_key)=0;
		virtual bool containValueByPointer(V* a_value)=0;

		virtual RawMapEntry<K,V> getRawMapEntryByPosition(int a_position)const=0;

		virtual K* getKeyByPointer(V* a_value)=0;
		virtual K* getKeyByPosition(int a_position)const=0;

		virtual V* getValueByPointer(const K* a_key)const=0;
		virtual V* getValueByPosition(int a_position)const=0;

		virtual void reset()=0;
		virtual void resetDelete()=0;
		virtual void resetDeleteKey()=0;
		virtual void resetDeleteValue()=0;

		virtual RawMapEntry<K,V> removeByKeyPointer(K* a_key)=0;
		virtual RawMapEntry<K,V> removeByValuePointer(V* a_value)=0;
		virtual RawMapEntry<K,V> removeByPosition(int a_position)=0;

		virtual bool removeDeleteByKeyPointer(K* a_key){
			RawPointerMapLog(pankey_Log_StartMethod, "removeDeleteByKeyPointer", "println", "");
			RawMapEntry<K,V> i_entry = this->removeByKeyPointer(a_key);
			bool removed = !i_entry.isNull();
			if(removed && this->isOwner()){
				i_entry.deleteEntry();
			}
			RawPointerMapLog(pankey_Log_EndMethod, "removeDeleteByKeyPointer", "println", "");
			return removed;
		}

		virtual bool removeDeleteByValuePointer(V* a_value){
			RawPointerMapLog(pankey_Log_StartMethod, "removeDeleteByValuePointer", "println", "");
			RawMapEntry<K,V> i_entry = this->removeByValuePointer(a_value);
			bool removed = !i_entry.isNull();
			if(removed && this->isOwner()){
				i_entry.deleteEntry();
			}
			RawPointerMapLog(pankey_Log_EndMethod, "removeDeleteByValuePointer", "println", "");
			return removed;
		}

		virtual bool removeDeleteByPosition(int a_position){
			RawPointerMapLog(pankey_Log_StartMethod, "removeDeleteByPosition", "println", "");
			RawMapEntry<K,V> i_entry = this->removeByPosition(a_position);
			bool removed = !i_entry.isNull();
			if(removed && isOwner()){
				i_entry.deleteEntry();
			}
			RawPointerMapLog(pankey_Log_EndMethod, "removeDeleteByPosition", "println", "");
			return removed;
		}

		virtual int getKeyIndexByPointer(K* a_key){
			RawPointerMapLog(pankey_Log_StartMethod, "getKeyIndexByPointer", "println", "");
			if(this->isEmpty()){
				RawPointerMapLog(pankey_Log_EndMethod, "getKeyIndexByPointer", "println", "");
				return -1;
			}
			for(int x = 0; x < this->getPosition(); x++){
				if(a_key == this->getKeyByPosition(x)){
					RawPointerMapLog(pankey_Log_EndMethod, "getKeyIndexByPointer", "println", "");
					return x;
				}
			}
			RawPointerMapLog(pankey_Log_EndMethod, "getKeyIndexByPointer", "println", "");
			return -1;
		}

		virtual int getValueIndexByPointer(V* a_value){
			RawPointerMapLog(pankey_Log_StartMethod, "getValueIndexByPointer", "println", "");
			if(this->isEmpty()){
				RawPointerMapLog(pankey_Log_EndMethod, "getValueIndexByPointer", "println", "");
				return -1;
			}
			for(int x = 0; x < this->getPosition(); x++){
				if(a_value == this->getValueByPosition(x)){
					RawPointerMapLog(pankey_Log_EndMethod, "getValueIndexByPointer", "println", "");
					return x;
				}
			}
			RawPointerMapLog(pankey_Log_EndMethod, "getValueIndexByPointer", "println", "");
			return -1;
		}

	protected:

		virtual void incrementPosition(){
			RawPointerMapLog(pankey_Log_StartMethod, "incrementPosition", "println", this->m_position);
			this->m_position++;
			RawPointerMapLog(pankey_Log_EndMethod, "incrementPosition", "println", this->m_position);
		}
		virtual void decrementPosition(){
			RawPointerMapLog(pankey_Log_StartMethod, "decrementPosition", "println", this->m_position);
			this->m_position--;
			if(this->m_position < 0){
				this->m_position = 0;
			}
			RawPointerMapLog(pankey_Log_EndMethod, "decrementPosition", "println", this->m_position);
		}

		virtual void incrementPosition(int a_size){
			RawPointerMapLog(pankey_Log_StartMethod, "incrementPosition", "println", this->m_position);
			this->m_position += a_size;
			RawPointerMapLog(pankey_Log_EndMethod, "incrementPosition", "println", this->m_position);
		}
		virtual void decrementPosition(int a_size){
			RawPointerMapLog(pankey_Log_StartMethod, "decrementPosition", "println", this->m_position);
			this->m_position -= a_size;
			if(this->m_position < 0){
				this->m_position = 0;
			}
			RawPointerMapLog(pankey_Log_EndMethod, "decrementPosition", "println", this->m_position);
		}
		
		virtual bool isEqualKey(K* a_key_1, K* a_key_2){
			if(a_key_1 != nullptr && a_key_2 != nullptr){
				if(*a_key_1 != *a_key_2){
					return false;
				}
			}else{
				if((a_key_1 != nullptr || a_key_2 != nullptr) && (a_key_1 != a_key_2)){
					return false;
				}
			}
			return true;
		}
		
		virtual bool isEqualValue(V* a_value_1, V* a_value_2){
			if(a_value_1 != nullptr && a_value_2 != nullptr){
				if(*a_value_1 != *a_value_2){
					return false;
				}
			}else{
				if((a_value_1 != nullptr || a_value_2 != nullptr) && (a_value_1 != a_value_2)){
					return false;
				}
			}
			return true;
		}
		
	protected:
		bool m_key_owner = true;
		bool m_value_owner = true;
		int m_position = 0;
		int m_size = 0;
};

}

#endif
