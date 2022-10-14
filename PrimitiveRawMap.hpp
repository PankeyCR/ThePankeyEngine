
#ifndef PrimitiveRawMap_hpp
#define PrimitiveRawMap_hpp
#define PrimitiveRawMap_AVAILABLE

#include "PrimitiveRawPointerMap.hpp"
#include "RawMap.hpp"
#include "MapIterator.hpp"

#ifdef PrimitiveRawMap_LogApp
	#include "ame_Logger_config.hpp"
	#include "ame_Logger.hpp"

	#define PrimitiveRawMapLog(location,method,type,mns) ame_Log((void*)this,location,"PrimitiveRawMap",method,type,mns)
	#define const_PrimitiveRawMapLog(location,method,type,mns)
#else
	#ifdef PrimitiveRawMap_LogDebugApp
		#include "ame_Logger_config.hpp"
		#include "ame_Logger.hpp"

		#define PrimitiveRawMapLog(location,method,type,mns) ame_LogDebug((void*)this,location,"PrimitiveRawMap",method,type)
		#define const_PrimitiveRawMapLog(location,method,type,mns)
	#else
		#define PrimitiveRawMapLog(location,method,type,mns)
		#define const_PrimitiveRawMapLog(location,method,type,mns)
	#endif
#endif

namespace ame{

template <class K,class V>
class PrimitiveRawMap : public PrimitiveRawPointerMap<K,V>, virtual public RawMap<K,V>{	
    public:
		
		PrimitiveRawMap(){
			PrimitiveRawMapLog(ame_Log_StartMethod, "Constructor", "println", "");
			PrimitiveRawMapLog(ame_Log_EndMethod, "Constructor", "println", "");
		}
		
		PrimitiveRawMap(const PrimitiveRawMap<K,V>& c_map){
			PrimitiveRawMapLog(ame_Log_StartMethod, "Constructor", "println", "");
			this->setOwner(c_map.m_owner);
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
			PrimitiveRawMapLog(ame_Log_EndMethod, "Constructor", "println", "");
		}
		
		PrimitiveRawMap(int c_size) : PrimitiveRawPointerMap<K,V>(c_size){
			PrimitiveRawMapLog(ame_Log_StartMethod, "Constructor", "println", "");
			PrimitiveRawMapLog(ame_Log_EndMethod, "Constructor", "println", "");
		}
		
		PrimitiveRawMap(int c_size, bool c_own) : PrimitiveRawPointerMap<K,V>(c_size, c_own){
			PrimitiveRawMapLog(ame_Log_StartMethod, "Constructor", "println", "");
			PrimitiveRawMapLog(ame_Log_EndMethod, "Constructor", "println", "");
		}
		
		virtual ~PrimitiveRawMap(){
			PrimitiveRawMapLog(ame_Log_StartMethod, "Destructor", "println", "");
			PrimitiveRawMapLog(ame_Log_EndMethod, "Destructor", "println", "");
		}
		
		virtual MapEntry<K,V> addLValues(K a_key, V a_value){
			PrimitiveRawMapLog(ame_Log_StartMethod, "addLValues", "println", "");
			K* i_key = new K(a_key);
			V* i_value = new V(a_value);
			PrimitiveRawMapLog(ame_Log_EndMethod, "addLValues", "println", "");
			return this->addPointers(i_key, i_value);
		}
		
		virtual MapEntry<K,V> addPointer(K a_key, V *a_value){
			PrimitiveRawMapLog(ame_Log_StartMethod, "addPointer", "println", "");
			K* i_key = new K(a_key);
			PrimitiveRawMapLog(ame_Log_EndMethod, "addPointer", "println", "");
			return this->addPointers(i_key, a_value);
		}
		
		virtual MapEntry<K,V> setLValues(K a_key, V a_value){
			PrimitiveRawMapLog(ame_Log_StartMethod, "setLValues", "println", "");
			int i_index = this->getKeyIndexByLValue(a_key);
			if(i_index == -1){
				PrimitiveRawMapLog(ame_Log_EndMethod, "setLValues", "println", "");
				return MapEntry<K,V>();
			}
			PrimitiveRawMapLog(ame_Log_EndMethod, "setLValues", "println", "");
			return this->setValueLValueByPosition(i_index, a_value);
		}
		
		virtual MapEntry<K,V> setPointer(K a_key, V *a_value){
			PrimitiveRawMapLog(ame_Log_StartMethod, "setPointer", "println", "");
			int i_index = this->getKeyIndexByLValue(a_key);
			if(i_index == -1){
				PrimitiveRawMapLog(ame_Log_EndMethod, "setPointer", "println", "");
				return MapEntry<K,V>();
			}
			PrimitiveRawMapLog(ame_Log_EndMethod, "setPointer", "println", "");
			return this->setValuePointerByPosition(i_index, a_value);
		}
		
		virtual MapEntry<K,V> setKeyLValueByPosition(int a_position, K a_key){
			PrimitiveRawMapLog(ame_Log_StartMethod, "setKeyLValueByPosition", "println", "");
			K* i_key = new K(a_key);
			PrimitiveRawMapLog(ame_Log_EndMethod, "setKeyLValueByPosition", "println", "");
			return this->setKeyPointerByPosition(a_position, i_key);
		}
		
		virtual MapEntry<K,V> setValueLValueByPosition(int a_position, V a_value){
			PrimitiveRawMapLog(ame_Log_StartMethod, "setValueLValueByPosition", "println", "");
			V* i_value = new V(a_value);
			PrimitiveRawMapLog(ame_Log_EndMethod, "setValueLValueByPosition", "println", "");
			return this->setValuePointerByPosition(a_position, i_value);
		}
		
		virtual bool containKeyByLValue(K a_key){
			PrimitiveRawMapLog(ame_Log_StartMethod, "containKeyByLValue", "println", "");
			for(int x = 0; x < this->getPosition(); x++){
				K* f_key = this->getKeyByPosition(x);
				if(f_key == nullptr){
					continue;
				}
				if(*f_key == a_key){
					PrimitiveRawMapLog(ame_Log_EndMethod, "containKeyByLValue", "println", "");
					return true;
				}
			}
			PrimitiveRawMapLog(ame_Log_EndMethod, "containKeyByLValue", "println", "");
			return false;
		}
		
		virtual bool containValueByLValue(V a_value){
			PrimitiveRawMapLog(ame_Log_StartMethod, "containValueByLValue", "println", "");
			for(int x = 0; x < this->getPosition(); x++){
				V* f_value = this->getValueByPosition(x);
				if(f_value == nullptr){
					continue;
				}
				if(*f_value == a_value){
					PrimitiveRawMapLog(ame_Log_EndMethod, "containValueByLValue", "println", "");
					return true;
				}
			}
			PrimitiveRawMapLog(ame_Log_EndMethod, "containValueByLValue", "println", "");
			return false;
		}
		
		virtual K* getKeyByLValue(V a_value){
			PrimitiveRawMapLog(ame_Log_StartMethod, "getKeyByLValue", "println", "");
			for(int x = 0; x < this->getPosition(); x++){
				V* f_value = this->getValueByPosition(x);
				if(f_value == nullptr){
					continue;
				}
				if(*f_value == a_value){
					PrimitiveRawMapLog(ame_Log_EndMethod, "getKeyByLValue", "println", "");
					return this->getKeyByPosition(x);
				}
			}
			PrimitiveRawMapLog(ame_Log_EndMethod, "getKeyByLValue", "println", "");
			return nullptr;
		}
		
		virtual V* getValueByLValue(K a_key){
			PrimitiveRawMapLog(ame_Log_StartMethod, "getValueByLValue", "println", "");
			for(int x = 0; x < this->getPosition(); x++){
				K* f_key = this->getKeyByPosition(x);
				if(f_key == nullptr){
					continue;
				}
				if(*f_key == a_key){
					PrimitiveRawMapLog(ame_Log_EndMethod, "getValueByLValue", "println", "");
					return this->getValueByPosition(x);
				}
			}
			PrimitiveRawMapLog(ame_Log_EndMethod, "getValueByLValue", "println", "");
			return nullptr;
		}
		
		virtual MapEntry<K,V> removeByKeyLValue(K a_key){
			PrimitiveRawMapLog(ame_Log_StartMethod, "removeByKeyLValue", "println", "");
			int i_position = this->getKeyIndexByLValue(a_key);
			if(i_position == -1){
				PrimitiveRawMapLog(ame_Log_EndMethod, "removeByKeyLValue", "println", "");
				return MapEntry<K,V>();
			}
			PrimitiveRawMapLog(ame_Log_EndMethod, "removeByKeyLValue", "println", "");
			return this->removeByPosition(i_position);
		}
		
		virtual MapEntry<K,V> removeByValueLValue(V a_value){
			PrimitiveRawMapLog(ame_Log_StartMethod, "removeByValueLValue", "println", "");
			int i_position = this->getValueIndexByLValue(a_value);
			if(i_position == -1){
				PrimitiveRawMapLog(ame_Log_EndMethod, "removeByValueLValue", "println", "");
				return MapEntry<K,V>();
			}
			PrimitiveRawMapLog(ame_Log_EndMethod, "removeByValueLValue", "println", "");
			return this->removeByPosition(i_position);
		}
		
		virtual bool removeDeleteByKeyLValue(K a_key){
			PrimitiveRawMapLog(ame_Log_StartMethod, "removeDeleteByKeyLValue", "println", "");
			int i_position = this->getKeyIndexByLValue(a_key);
			if(i_position == -1){
				PrimitiveRawMapLog(ame_Log_EndMethod, "removeDeleteByKeyLValue", "println", "");
				return false;
			}
			PrimitiveRawMapLog(ame_Log_EndMethod, "removeDeleteByKeyLValue", "println", "");
			return this->removeDeleteByPosition(i_position);
		}
		
		virtual bool removeDeleteByValueLValue(V a_value){
			PrimitiveRawMapLog(ame_Log_StartMethod, "removeDeleteByValueLValue", "println", "");
			int i_position = this->getValueIndexByLValue(a_value);
			if(i_position == -1){
				PrimitiveRawMapLog(ame_Log_EndMethod, "removeDeleteByValueLValue", "println", "");
				return false;
			}
			PrimitiveRawMapLog(ame_Log_EndMethod, "removeDeleteByValueLValue", "println", "");
			return this->removeDeleteByPosition(i_position);
		}
		
		virtual bool remove(K a_key){
			PrimitiveRawMapLog(ame_Log_StartMethod, "remove", "println", "");
			int i_position = this->getKeyIndexByLValue(a_key);
			if(i_position == -1){
				PrimitiveRawMapLog(ame_Log_EndMethod, "remove", "println", "");
				return false;
			}
			PrimitiveRawMapLog(ame_Log_EndMethod, "remove", "println", "");
			return this->removeDeleteByPosition(i_position);
		}
		
		virtual MapEntry<K,V> putLValues(K a_key, V a_value){
			PrimitiveRawMapLog(ame_Log_StartMethod, "putLValues", "println", "");
			int index = this->getKeyIndexByLValue(a_key);
			if(index != -1){
				PrimitiveRawMapLog(ame_Log_EndMethod, "putLValues", "println", "index != -1");
				return this->getMapEntryByPosition(index);
			}
			PrimitiveRawMapLog(ame_Log_EndMethod, "putLValues", "println", "");
			return this->addLValues(a_key, a_value);
		}
		
		virtual MapEntry<K,V> putPointer(K a_key, V* a_value){
			PrimitiveRawMapLog(ame_Log_StartMethod, "putPointer", "println", "");
			int index = this->getKeyIndexByLValue(a_key);
			if(index != -1){
				PrimitiveRawMapLog(ame_Log_EndMethod, "putLValues", "println", "index != -1");
				return this->getMapEntryByPosition(index);
			}
			PrimitiveRawMapLog(ame_Log_EndMethod, "putPointer", "println", "");
			return this->addPointer(a_key, a_value);
		}
		
		virtual int getKeyIndexByLValue(K a_key){
			PrimitiveRawMapLog(ame_Log_StartMethod, "getKeyIndexByLValue", "println", "");
			for(int x=0; x < this->getPosition(); x++){
				K* i_key = this->getKeyByPosition(x);
				if(i_key == nullptr){
					continue;
				}
				if(a_key == *i_key){
					PrimitiveRawMapLog(ame_Log_EndMethod, "getKeyIndexByLValue", "println", x);
					return x;
				}
			}
			PrimitiveRawMapLog(ame_Log_EndMethod, "getKeyIndexByLValue", "println", "");
			return -1;
		}
		
		virtual int getValueIndexByLValue(V a_value){
			PrimitiveRawMapLog(ame_Log_StartMethod, "getValueIndexByLValue", "println", "");
			for(int x=0; x < this->getPosition(); x++){
				V* i_value = this->getValueByPosition(x);
				if(i_value == nullptr){
					continue;
				}
				if(a_value == *i_value){
					PrimitiveRawMapLog(ame_Log_EndMethod, "getValueIndexByLValue", "println", "");
					return x;
				}
			}
			PrimitiveRawMapLog(ame_Log_EndMethod, "getValueIndexByLValue", "println", "");
			return -1;
		}
		
		virtual MapIterator<K,V> begin(){
			PrimitiveRawMapLog(ame_Log_StartMethod, "begin", "println", this->getPosition());
			PrimitiveRawMapLog(ame_Log_EndMethod, "begin", "println", "");
			return MapIterator<K,V>(this, 0, this->getPosition());
		}
		virtual MapIterator<K,V> end(){
			PrimitiveRawMapLog(ame_Log_StartMethod, "end", "println", this->getPosition());
			PrimitiveRawMapLog(ame_Log_EndMethod, "end", "println", "");
			return MapIterator<K,V>(this, this->getPosition() - 1, this->getPosition());
		}
		
	protected:
};

}

#endif