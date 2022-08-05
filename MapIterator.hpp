
#include "ame_Enviroment.hpp"

#if defined(DISABLE_MapIterator)
	#define MapIterator_hpp
#endif

#ifndef MapIterator_hpp
#define MapIterator_hpp
#define MapIterator_AVAILABLE

#ifndef ame_Enviroment_Defined

#endif

#ifdef ame_Windows

#endif

#ifdef ame_ArduinoIDE
	#include "Arduino.h"
#endif

#include "RawMap.hpp"

namespace ame{

template <class K,class V>
class MapIterator{
    public:
	int position = 0;
	int size = 0;
	RawMap<K,V>* m_map = nullptr;
	
	MapIterator(RawMap<K,V>* i_map, int p, int s){
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
	
	virtual K getKey(){
		K* key = m_map->getKeyByPosition(position);
		if(key == nullptr){
			return K();
		}
		return *key;
	}
	
	virtual V getValue(){
		V* value = m_map->getByPosition(position);
		if(value == nullptr){
			return V();
		}
		return *value;
	}
	
	virtual void setKey(K k){
		K* key = m_map->getKeyByPosition(position);
		if(key == nullptr){
			return;
		}
		*key = k;
	}
	
	virtual void setValue(V v){
		V* value = m_map->getByPosition(position);
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