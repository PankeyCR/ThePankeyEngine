
#ifndef RawMap_hpp
#define RawMap_hpp
#define RawMap_AVAILABLE

#include "RawPointerMap.hpp"

#ifdef RawMap_LogApp
	#include "ame_Logger_config.hpp"
	#include "ame_Logger.hpp"

	#define RawMapLog(location,method,type,mns) ame_Log((void*)this,location,"RawMap",method,type,mns)
	#define const_RawMapLog(location,method,type,mns)
#else
	#ifdef RawMap_LogDebugApp
		#include "ame_Logger_config.hpp"
		#include "ame_Logger.hpp"

		#define RawMapLog(location,method,type,mns) ame_LogDebug((void*)this,location,"RawMap",method,type)
		#define const_RawMapLog(location,method,type,mns)
	#else
		#define RawMapLog(location,method,type,mns)
		#define const_RawMapLog(location,method,type,mns)
	#endif
#endif

namespace ame{

template <class K,class V>
class RawMap : virtual public RawPointerMap<K,V>{
    public:
		virtual ~RawMap(){
			RawMapLog(ame_Log_StartMethod, "Destructor", "println", "");
			RawMapLog(ame_Log_EndMethod, "Destructor", "println", "");
		}

		virtual void addCopy(RawPointerMap<K,V>* a_map){
			RawMapLog(ame_Log_StartMethod, "addCopy", "println", "");
			for(int x = 0; x < a_map->getPosition(); x++){
				K* k = a_map->getKeyByPosition(x);
				V* v = a_map->getValueByPosition(x);
				if(k == nullptr || v == nullptr){
					continue;
				}
				this->addLValues(*k,*v);
			}
			RawMapLog(ame_Log_EndMethod, "addCopy", "println", "");
		}
		
		virtual MapEntry<K,V> addLValues(K a_key, V a_value)=0;
		virtual MapEntry<K,V> addPointer(K a_key, V* a_value)=0;
		
		virtual MapEntry<K,V> add(K a_key, V a_value){
			RawMapLog(ame_Log_StartMethod, "add", "println", "");
			RawMapLog(ame_Log_EndMethod, "add", "println", "");
			return this->addLValues(a_key, a_value);
		}

		virtual MapEntry<K,V> setLValues(K a_key, V a_value)=0;
		virtual MapEntry<K,V> setPointer(K a_key, V* a_value)=0;
		
		virtual MapEntry<K,V> setKeyLValueByPosition(int a_position, K a_key)=0;
		virtual MapEntry<K,V> setValueLValueByPosition(int a_position, V a_value)=0;
		
		virtual MapEntry<K,V> set(K a_key, V a_value){
			RawMapLog(ame_Log_StartMethod, "set", "println", "");
			RawMapLog(ame_Log_EndMethod, "set", "println", "");
			return this->setLValues(a_key,a_value);
		}
		
		virtual bool containKeyByLValue(K a_key)=0;
		virtual bool containValueByLValue(V a_value)=0;
		
		virtual bool contain(K a_key){
			RawMapLog(ame_Log_StartMethod, "contain", "println", "");
			RawMapLog(ame_Log_EndMethod, "contain", "println", "");
			return this->containKeyByLValue(a_key);
		}
		
		virtual K* getKeyByLValue(V a_value)=0;
		
		virtual V* getValueByLValue(K a_key)=0;
		
		virtual V get(K a_key){
			RawMapLog(ame_Log_StartMethod, "get", "println", "");
			V* i_value = this->getValueByLValue(a_key);
			if(i_value == nullptr){
				RawMapLog(ame_Log_EndMethod, "get", "println", "");
				return V();
			}
			RawMapLog(ame_Log_EndMethod, "get", "println", "");
			return *i_value;
		}
		virtual K getKey(int a_position){
			RawMapLog(ame_Log_StartMethod, "getKey", "println", "");
			K* i_key = this->getKeyByPosition(a_position);
			if(i_key == nullptr){
				RawMapLog(ame_Log_EndMethod, "getKey", "println", "");
				return K();
			}
			RawMapLog(ame_Log_EndMethod, "getKey", "println", "");
			return *i_key;
		}
		virtual V getValue(int a_position){
			RawMapLog(ame_Log_StartMethod, "getValue", "println", "");
			V* i_value = this->getValueByPosition(a_position);
			if(i_value == nullptr){
				RawMapLog(ame_Log_EndMethod, "getValue", "println", "");
				return V();
			}
			RawMapLog(ame_Log_EndMethod, "getValue", "println", "");
			return *i_value;
		}
		
		virtual MapEntry<K,V> removeByKeyLValue(K a_key)=0;
		virtual MapEntry<K,V> removeByValueLValue(V a_value)=0;
		
		virtual bool removeDeleteByKeyLValue(K a_key)=0;
		virtual bool removeDeleteByValueLValue(V a_value)=0;
		
		virtual bool remove(K a_key)=0;
		
		virtual MapEntry<K,V> putLValues(K a_key, V a_value)=0;
		virtual MapEntry<K,V> putPointer(K a_key, V* a_value)=0;
		
		virtual MapEntry<K,V> put(K a_key, V a_value){
			RawMapLog(ame_Log_StartMethod, "put", "println", "");
			RawMapLog(ame_Log_EndMethod, "put", "println", "");
			return this->putLValues(a_key, a_value);
		}
		
		virtual int getKeyIndexByLValue(K a_key)=0;
		
		virtual int getValueIndexByLValue(V a_key)=0;
		
		template<class... Args>
		void addKeyPack(Args... a_values){
			RawMapLog(ame_Log_StartMethod, "addKeyPack", "println", "");
			K i_array[] = {a_values...};
			for(const K& k : i_array){
				this->addPointers(new K(k), new V());
			}
			RawMapLog(ame_Log_EndMethod, "addKeyPack", "println", "");
		}
		
		template<class... Args>
		void addValuePack(Args... a_values){
			RawMapLog(ame_Log_StartMethod, "addValuePack", "println", "");
			V i_array[] = {a_values...};
			for(const V& v : i_array){
				this->addPointers(new K(), new V(v));
			}
			RawMapLog(ame_Log_EndMethod, "addValuePack", "println", "");
		}
		
		template<class... Args>
		void addKeyPack(V v, Args... a_values){
			RawMapLog(ame_Log_StartMethod, "addKeyPack", "println", "");
			K i_array[] = {a_values...};
			for(const K& k : i_array){
				this->addPointers(new K(k), new V(v));
			}
			RawMapLog(ame_Log_EndMethod, "addKeyPack", "println", "");
		}
		
		template<class... Args>
		void addValuePack(K k, Args... a_values){
			RawMapLog(ame_Log_StartMethod, "addValuePack", "println", "");
			V i_array[] = {a_values...};
			for(const V& v : i_array){
				this->addPointers(new K(k), new V(v));
			}
			RawMapLog(ame_Log_EndMethod, "addValuePack", "println", "");
		}
};

}

#endif