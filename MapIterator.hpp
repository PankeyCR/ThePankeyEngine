
#ifndef MapIterator_hpp
#define MapIterator_hpp
#define MapIterator_AVAILABLE

#include "RawPointerMap.hpp"

#ifdef MapIterator_LogApp
	#include "ame_Logger_config.hpp"
	#include "ame_Logger.hpp"

	#define MapIteratorLog(location,method,type,mns) ame_Log((void*)this,location,"MapIterator",method,type,mns)
	#define const_MapIteratorLog(location,method,type,mns)
#else
	#ifdef MapIterator_LogDebugApp
		#include "ame_Logger_config.hpp"
		#include "ame_Logger.hpp"

		#define MapIteratorLog(location,method,type,mns) ame_LogDebug((void*)this,location,"MapIterator",method,type)
		#define const_MapIteratorLog(location,method,type,mns)
	#else
		#define MapIteratorLog(location,method,type,mns)
		#define const_MapIteratorLog(location,method,type,mns)
	#endif
#endif

namespace ame{

template <class K,class V>
class MapIterator{
    public:
	int position = 0;
	int size = 0;
	RawPointerMap<K,V>* m_map = nullptr;
	
	MapIterator(RawPointerMap<K,V>* i_map, int p, int s){
		m_map = i_map;
		position = p;
		size = s;
	}
	
	MapIterator(const MapIterator<K,V>& entry){
		m_map = entry.m_map;
		position = entry.position;
		size = entry.size;
	}
	
	MapIterator(MapIterator<K,V>&& entry){
		m_map = entry.m_map;
		position = entry.position;
		size = entry.size;
	}
	
	MapIterator& operator=(const MapIterator<K,V>& entry){
		m_map = entry.m_map;
		position = entry.position;
		size = entry.size;
		return *this;
	}
	
	MapIterator& operator=(MapIterator<K,V>&& entry){
		m_map = entry.m_map;
		position = entry.position;
		size = entry.size;
		return *this;
	}
	
	bool operator!=(const MapIterator<K,V>& entry){
		return position != entry.size;
	}
	
	bool operator==(const MapIterator<K,V>& entry){
		return position == entry.size;
	}
	
	virtual ~MapIterator(){
	}
	
	virtual bool isValid(){
		return m_map != nullptr;
	}
	
	virtual MapEntry<K,V> get(){
		return m_map->getMapEntryByPosition(position);
	}
	
	virtual K getKey(){
		K* key = m_map->getKeyByPosition(position);
		if(key == nullptr){
			return K();
		}
		return *key;
	}
	
	virtual K* getKeyPointer(){
		return m_map->getKeyByPosition(position);
	}
	
	virtual V getValue(){
		V* value = m_map->getValueByPosition(position);
		if(value == nullptr){
			return V();
		}
		return *value;
	}
	
	virtual V* getValuePointer(){
		return m_map->getValueByPosition(position);
	}
	
	virtual void setKey(K k){
		K* key = m_map->getKeyByPosition(position);
		if(key == nullptr){
			return;
		}
		*key = k;
	}
	
	virtual void setValue(V v){
		V* value = m_map->getValueByPosition(position);
		if(value == nullptr){
			return;
		}
		*value = v;
	}
		
	virtual void operator ++(){
		this->position++;
	}
	virtual MapIterator<K,V> operator *(){
		return MapIterator<K,V>(m_map,position,size);
	}
};

}

#endif