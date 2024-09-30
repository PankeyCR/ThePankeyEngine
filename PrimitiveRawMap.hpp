
#ifndef PrimitiveRawMap_hpp
#define PrimitiveRawMap_hpp

#include "PrimitiveRawPointerMap.hpp"
#include "RawMap.hpp"
#include "RawMapIterator.hpp"

#ifdef PrimitiveRawMap_LogApp
	#include "pankey_Logger.hpp"
	#define PrimitiveRawMapLog(location,method,type,mns) pankey_Log((void*)this,location,"PrimitiveRawMap",method,type,mns)
#else
	#define PrimitiveRawMapLog(location,method,type,mns)
#endif

namespace pankey{

template <class K,class V>
class PrimitiveRawMap : public PrimitiveRawPointerMap<K,V>, virtual public RawMap<K,V>{	
    public:
		
		PrimitiveRawMap(){
			PrimitiveRawMapLog(pankey_Log_StartMethod, "Constructor", "println", "");
			PrimitiveRawMapLog(pankey_Log_EndMethod, "Constructor", "println", "");
		}
		
		PrimitiveRawMap(const PrimitiveRawMap<K,V>& c_map){
			PrimitiveRawMapLog(pankey_Log_StartMethod, "Constructor", "println", "");
			this->setOwner(false);
			this->expandLocal(c_map.getPosition());
			
			for(int x = 0; x < c_map.getPosition(); x++){
				K* k = c_map.getKeyByPosition(x);
				V* v = c_map.getValueByPosition(x);
				if(k != nullptr && v != nullptr){
					this->addLValues(*k,*v);
				}
				if(k != nullptr && v == nullptr){
					this->addPointer(*k,v);
				}
			}
			PrimitiveRawMapLog(pankey_Log_EndMethod, "Constructor", "println", "");
		}
		
		PrimitiveRawMap(int c_size) : PrimitiveRawPointerMap<K,V>(c_size){
			PrimitiveRawMapLog(pankey_Log_StartMethod, "Constructor", "println", "");
			PrimitiveRawMapLog(pankey_Log_EndMethod, "Constructor", "println", "");
		}
		
		PrimitiveRawMap(int c_size, bool c_key_own, bool c_value_own, bool c_reorder) : PrimitiveRawPointerMap<K,V>(c_size, c_key_own, c_value_own, c_reorder){
			PrimitiveRawMapLog(pankey_Log_StartMethod, "Constructor", "println", "");
			PrimitiveRawMapLog(pankey_Log_EndMethod, "Constructor", "println", "");
		}
		
		virtual ~PrimitiveRawMap(){
			PrimitiveRawMapLog(pankey_Log_StartMethod, "Destructor", "println", "");
			PrimitiveRawMapLog(pankey_Log_EndMethod, "Destructor", "println", "");
		}
		
		virtual void addMap(const PrimitiveRawMap<K,V>& a_map){
			PrimitiveRawMapLog(pankey_Log_StartMethod, "addLValues", "println", "");
			if(a_map.getSize() < this->getPosition() + a_map.getPosition()){
				this->expandLocal(a_map.getPosition());
			}
			for(int x = 0; x < a_map.getPosition(); x++){
				K* k = a_map.getKeyByPosition(x);
				V* v = a_map.getValueByPosition(x);
				if(k != nullptr && v != nullptr){
					this->addLValues(*k,*v);
				}
				if(k != nullptr && v == nullptr){
					this->addPointer(*k,nullptr);
				}
			}
			PrimitiveRawMapLog(pankey_Log_EndMethod, "addLValues", "println", "");
		}
		
		virtual RawMapEntry<K,V> addLValues(K a_key, V a_value){
			PrimitiveRawMapLog(pankey_Log_StartMethod, "addLValues", "println", "");
			K* i_key = new K(a_key);
			V* i_value = new V(a_value);
			PrimitiveRawMapLog(pankey_Log_EndMethod, "addLValues", "println", "");
			return this->addPointers(i_key, i_value);
		}
		
		virtual RawMapEntry<K,V> addPointer(K a_key, V *a_value){
			PrimitiveRawMapLog(pankey_Log_StartMethod, "addPointer", "println", "");
			K* i_key = new K(a_key);
			PrimitiveRawMapLog(pankey_Log_EndMethod, "addPointer", "println", "");
			return this->addPointers(i_key, a_value);
		}
		
		virtual RawMapEntry<K,V> setLValues(K a_key, V a_value){
			PrimitiveRawMapLog(pankey_Log_StartMethod, "setLValues", "println", "");
			int i_index = this->getKeyIndexByLValue(a_key);
			if(i_index == -1){
				PrimitiveRawMapLog(pankey_Log_EndMethod, "setLValues", "println", "");
				return RawMapEntry<K,V>();
			}
			PrimitiveRawMapLog(pankey_Log_EndMethod, "setLValues", "println", "");
			return this->setValueLValueByPosition(i_index, a_value);
		}
		
		virtual RawMapEntry<K,V> setPointer(K a_key, V *a_value){
			PrimitiveRawMapLog(pankey_Log_StartMethod, "setPointer", "println", "");
			int i_index = this->getKeyIndexByLValue(a_key);
			if(i_index == -1){
				PrimitiveRawMapLog(pankey_Log_EndMethod, "setPointer", "println", "");
				return RawMapEntry<K,V>();
			}
			PrimitiveRawMapLog(pankey_Log_EndMethod, "setPointer", "println", "");
			return this->setValuePointerByPosition(i_index, a_value);
		}
		
		virtual RawMapEntry<K,V> setKeyLValueByPosition(int a_position, K a_key){
			PrimitiveRawMapLog(pankey_Log_StartMethod, "setKeyLValueByPosition", "println", "");
			K* i_key = new K(a_key);
			PrimitiveRawMapLog(pankey_Log_EndMethod, "setKeyLValueByPosition", "println", "");
			return this->setKeyPointerByPosition(a_position, i_key);
		}
		
		virtual RawMapEntry<K,V> setValueLValueByPosition(int a_position, V a_value){
			PrimitiveRawMapLog(pankey_Log_StartMethod, "setValueLValueByPosition", "println", "");
			V* i_value = new V(a_value);
			PrimitiveRawMapLog(pankey_Log_EndMethod, "setValueLValueByPosition", "println", "");
			return this->setValuePointerByPosition(a_position, i_value);
		}
		
		virtual bool containKeyByLValue(K a_key){
			PrimitiveRawMapLog(pankey_Log_StartMethod, "containKeyByLValue", "println", "");
			for(int x = 0; x < this->getPosition(); x++){
				K* f_key = this->getKeyByPosition(x);
				if(f_key == nullptr){
					continue;
				}
				if(*f_key == a_key){
					PrimitiveRawMapLog(pankey_Log_EndMethod, "containKeyByLValue", "println", "");
					return true;
				}
			}
			PrimitiveRawMapLog(pankey_Log_EndMethod, "containKeyByLValue", "println", "");
			return false;
		}
		
		virtual bool containValueByLValue(V a_value){
			PrimitiveRawMapLog(pankey_Log_StartMethod, "containValueByLValue", "println", "");
			for(int x = 0; x < this->getPosition(); x++){
				V* f_value = this->getValueByPosition(x);
				if(f_value == nullptr){
					continue;
				}
				if(*f_value == a_value){
					PrimitiveRawMapLog(pankey_Log_EndMethod, "containValueByLValue", "println", "");
					return true;
				}
			}
			PrimitiveRawMapLog(pankey_Log_EndMethod, "containValueByLValue", "println", "");
			return false;
		}
		
		virtual K* getKeyByLValue(V a_value)const{
			PrimitiveRawMapLog(pankey_Log_StartMethod, "getKeyByLValue", "println", "");
			for(int x = 0; x < this->getPosition(); x++){
				V* f_value = this->getValueByPosition(x);
				if(f_value == nullptr){
					continue;
				}
				if(*f_value == a_value){
					PrimitiveRawMapLog(pankey_Log_EndMethod, "getKeyByLValue", "println", "");
					return this->getKeyByPosition(x);
				}
			}
			PrimitiveRawMapLog(pankey_Log_EndMethod, "getKeyByLValue", "println", "");
			return nullptr;
		}
		
		virtual V* getValueByLValue(K a_key)const{
			PrimitiveRawMapLog(pankey_Log_StartMethod, "getValueByLValue", "println", "");
			for(int x = 0; x < this->getPosition(); x++){
				K* f_key = this->getKeyByPosition(x);
				if(f_key == nullptr){
					continue;
				}
				if(*f_key == a_key){
					PrimitiveRawMapLog(pankey_Log_EndMethod, "getValueByLValue", "println", "");
					return this->getValueByPosition(x);
				}
			}
			PrimitiveRawMapLog(pankey_Log_EndMethod, "getValueByLValue", "println", "");
			return nullptr;
		}
		
		virtual RawMapEntry<K,V> removeByKeyLValue(K a_key){
			PrimitiveRawMapLog(pankey_Log_StartMethod, "removeByKeyLValue", "println", "");
			int i_position = this->getKeyIndexByLValue(a_key);
			if(i_position == -1){
				PrimitiveRawMapLog(pankey_Log_EndMethod, "removeByKeyLValue", "println", "");
				return RawMapEntry<K,V>();
			}
			PrimitiveRawMapLog(pankey_Log_EndMethod, "removeByKeyLValue", "println", "");
			return this->removeByPosition(i_position);
		}
		
		virtual RawMapEntry<K,V> removeByValueLValue(V a_value){
			PrimitiveRawMapLog(pankey_Log_StartMethod, "removeByValueLValue", "println", "");
			int i_position = this->getValueIndexByLValue(a_value);
			if(i_position == -1){
				PrimitiveRawMapLog(pankey_Log_EndMethod, "removeByValueLValue", "println", "");
				return RawMapEntry<K,V>();
			}
			PrimitiveRawMapLog(pankey_Log_EndMethod, "removeByValueLValue", "println", "");
			return this->removeByPosition(i_position);
		}
		
		virtual bool removeDeleteByKeyLValue(K a_key){
			PrimitiveRawMapLog(pankey_Log_StartMethod, "removeDeleteByKeyLValue", "println", "");
			int i_position = this->getKeyIndexByLValue(a_key);
			if(i_position == -1){
				PrimitiveRawMapLog(pankey_Log_EndMethod, "removeDeleteByKeyLValue", "println", "");
				return false;
			}
			PrimitiveRawMapLog(pankey_Log_EndMethod, "removeDeleteByKeyLValue", "println", "");
			return this->removeDeleteByPosition(i_position);
		}
		
		virtual bool removeDeleteByValueLValue(V a_value){
			PrimitiveRawMapLog(pankey_Log_StartMethod, "removeDeleteByValueLValue", "println", "");
			int i_position = this->getValueIndexByLValue(a_value);
			if(i_position == -1){
				PrimitiveRawMapLog(pankey_Log_EndMethod, "removeDeleteByValueLValue", "println", "");
				return false;
			}
			PrimitiveRawMapLog(pankey_Log_EndMethod, "removeDeleteByValueLValue", "println", "");
			return this->removeDeleteByPosition(i_position);
		}
		
		virtual bool remove(K a_key){
			PrimitiveRawMapLog(pankey_Log_StartMethod, "remove", "println", "");
			int i_position = this->getKeyIndexByLValue(a_key);
			if(i_position == -1){
				PrimitiveRawMapLog(pankey_Log_EndMethod, "remove", "println", "");
				return false;
			}
			PrimitiveRawMapLog(pankey_Log_EndMethod, "remove", "println", "");
			return this->removeDeleteByPosition(i_position);
		}
		
		virtual RawMapEntry<K,V> putLValues(K a_key, V a_value){
			PrimitiveRawMapLog(pankey_Log_StartMethod, "putLValues", "println", "");
			int index = this->getKeyIndexByLValue(a_key);
			if(index != -1){
				PrimitiveRawMapLog(pankey_Log_EndMethod, "putLValues", "println", "index != -1");
				return this->getRawMapEntryByPosition(index);
			}
			PrimitiveRawMapLog(pankey_Log_EndMethod, "putLValues", "println", "");
			return this->addLValues(a_key, a_value);
		}
		
		virtual RawMapEntry<K,V> putPointer(K a_key, V* a_value){
			PrimitiveRawMapLog(pankey_Log_StartMethod, "putPointer", "println", "");
			int index = this->getKeyIndexByLValue(a_key);
			if(index != -1){
				PrimitiveRawMapLog(pankey_Log_EndMethod, "putLValues", "println", "index != -1");
				return this->getRawMapEntryByPosition(index);
			}
			PrimitiveRawMapLog(pankey_Log_EndMethod, "putPointer", "println", "");
			return this->addPointer(a_key, a_value);
		}
		
		virtual int getKeyIndexByLValue(K a_key){
			PrimitiveRawMapLog(pankey_Log_StartMethod, "getKeyIndexByLValue", "println", "");
			for(int x=0; x < this->getPosition(); x++){
				K* i_key = this->getKeyByPosition(x);
				if(i_key == nullptr){
					continue;
				}
				if(a_key == *i_key){
					PrimitiveRawMapLog(pankey_Log_EndMethod, "getKeyIndexByLValue", "println", x);
					return x;
				}
			}
			PrimitiveRawMapLog(pankey_Log_EndMethod, "getKeyIndexByLValue", "println", "");
			return -1;
		}
		
		virtual int getValueIndexByLValue(V a_value){
			PrimitiveRawMapLog(pankey_Log_StartMethod, "getValueIndexByLValue", "println", "");
			for(int x=0; x < this->getPosition(); x++){
				V* i_value = this->getValueByPosition(x);
				if(i_value == nullptr){
					continue;
				}
				if(a_value == *i_value){
					PrimitiveRawMapLog(pankey_Log_EndMethod, "getValueIndexByLValue", "println", "");
					return x;
				}
			}
			PrimitiveRawMapLog(pankey_Log_EndMethod, "getValueIndexByLValue", "println", "");
			return -1;
		}
	
		////////////////////////////////////////////operator part///////////////////////////////////////////////
		
		
		virtual PrimitiveRawMap<K,V>& operator=(const PrimitiveRawMap<K,V>& a_map){
			PrimitiveRawMapLog(pankey_Log_StartMethod, "operator=", "println", "");
			this->resetDelete();
			for(int x = 0; x < a_map.getPosition(); x++){
				K* f_key = this->getKeyByPosition(x);
				V* f_value = this->getValueByPosition(x);
				if(f_key == nullptr || f_value == nullptr){
					continue;
				}
				this->addLValues(*f_key, *f_value);
			}
			PrimitiveRawMapLog(pankey_Log_EndMethod, "operator=", "println", "");
			return *this;
		}
		
		virtual bool operator==(const PrimitiveRawMap<K,V>& a_map){
			PrimitiveRawMapLog(pankey_Log_StartMethod, "operator==", "println", "");
			if(this->getPosition() != a_map.getPosition()){
				return false;
			}
			for(int x = 0; x < a_map.getPosition(); x++){
				K* f_key_1 = a_map.getKeyByPosition(x);
				V* f_value_1 = a_map.getValueByPosition(x);
				K* f_key_2 = this->getKeyByPosition(x);
				V* f_value_2 = this->getValueByPosition(x);
				if(f_key_1 == f_key_2 && f_value_1 == f_value_2){
					continue;
				}
				if(f_key_1 != nullptr && f_key_2 != nullptr && f_value_1 != nullptr && f_value_2 != nullptr){
					if(*f_key_1 != *f_key_2 || *f_value_1 != *f_value_2){
						return false;
					}
				}
			}
			PrimitiveRawMapLog(pankey_Log_EndMethod, "operator==", "println", "");
			return true;
		}
		
		virtual bool operator!=(const PrimitiveRawMap<K,V>& a_map){
			PrimitiveRawMapLog(pankey_Log_StartMethod, "operator!=", "println", "");
			if(this->getPosition() != a_map.getPosition()){
				return true;
			}
			for(int x = 0; x < a_map.getPosition(); x++){
				K* f_key_1 = a_map.getKeyByPosition(x);
				V* f_value_1 = a_map.getValueByPosition(x);
				K* f_key_2 = this->getKeyByPosition(x);
				V* f_value_2 = this->getValueByPosition(x);
				if(f_key_1 == f_key_2 && f_value_1 == f_value_2){
					continue;
				}
				if(f_key_1 != nullptr && f_key_2 != nullptr && f_value_1 != nullptr && f_value_2 != nullptr){
					if(*f_key_1 != *f_key_2 || *f_value_1 != *f_value_2){
						return true;
					}
				}
			}
			PrimitiveRawMapLog(pankey_Log_EndMethod, "operator!=", "println", "");
			return false;
		}
	
		////////////////////////////////////////////Iterator part///////////////////////////////////////////////
		
		virtual RawMapIterator<K,V> begin(){
			PrimitiveRawMapLog(pankey_Log_StartMethod, "begin", "println", this->getPosition());
			PrimitiveRawMapLog(pankey_Log_EndMethod, "begin", "println", "");
			return RawMapIterator<K,V>(this, 0, this->getPosition());
		}
		virtual RawMapIterator<K,V> end(){
			PrimitiveRawMapLog(pankey_Log_StartMethod, "end", "println", this->getPosition());
			PrimitiveRawMapLog(pankey_Log_EndMethod, "end", "println", "");
			return RawMapIterator<K,V>(this, this->getPosition() - 1, this->getPosition());
		}
		
	protected:
};

}

#endif