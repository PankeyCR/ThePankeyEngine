
#include "ame_Enviroment.hpp"

#if defined(DISABLE_MapNote)
	#define MapNote_hpp
#endif

#ifndef MapNote_hpp
#define MapNote_hpp
#define MapNote_AVAILABLE

#ifndef ame_Enviroment_Defined

#endif

#ifdef ame_Windows

#endif

#ifdef ame_ArduinoIDE
	#include "Arduino.h"
#endif

#include "PrimitiveRawMap.hpp"
#include "PrimitiveMap.hpp"
#include "KVMap.hpp"
#include "KPMap.hpp"
#include "PMap.hpp"

namespace ame{

template<class K, class V>
Note ArrayKeyMapNote_p(char a_split, const PrimitiveRawMap<K,V>& a_map){
	Note n_map;
	if(a_map.isEmpty()){
		return n_map;
	}
	for(int x = 0; x < a_map.getPosition(); x++){
		n_map += Note(*a_map.getKeyByPosition(x));
		if(x != a_map.getPosition() - 1){
			n_map += a_split;
		}
	}
	
	return n_map;
}

template<class K, class V>
Note ArrayValueMapNote_p(char a_split, const PrimitiveRawMap<K,V>& a_map){
	Note n_map;
	if(a_map.isEmpty()){
		return n_map;
	}
	for(int x = 0; x < a_map.getPosition(); x++){
		n_map += Note(*a_map.getByPosition(x));
		if(x != a_map.getPosition() - 1){
			n_map += a_split;
		}
	}
	
	return n_map;
}

template<class K, class V>
Note ArrayKeyMapNote_n(char a_split, const PrimitiveRawMap<K,V>& a_map){
	Note n_map;
	if(a_map.isEmpty()){
		return n_map;
	}
	for(int x = 0; x < a_map.getPosition(); x++){
		n_map += a_map.getKeyByPosition(x)->toNote();
		if(x != a_map.getPosition() - 1){
			n_map += a_split;
		}
	}
	
	return n_map;
}

template<class K, class V>
Note ArrayValueMapNote_n(char a_split, const PrimitiveRawMap<K,V>& a_map){
	Note n_map;
	if(a_map.isEmpty()){
		return n_map;
	}
	for(int x = 0; x < a_map.getPosition(); x++){
		n_map += a_map.getByPosition(x)->toNote();
		if(x != a_map.getPosition() - 1){
			n_map += a_split;
		}
	}
	
	return n_map;
}

template<class K, class V>
Note MapNote_p(const PrimitiveRawMap<K,V>& a_map){
	Note n_map;
	if(a_map.isEmpty()){
		return n_map;
	}
	for(int x = 0; x < a_map.getPosition(); x++){
		n_map += "Key: ";
		n_map += Note(*a_map.getKeyByPosition(x));
		n_map += " Value: ";
		n_map += Note(*a_map.getByPosition(x));
		if(x != a_map.getPosition() - 1){
			n_map += '\n';
		}
	}
	
	return n_map;
}

template<class K, class V>
Note MapNote_n(const PrimitiveRawMap<K,V>& a_map){
	Note n_map;
	if(a_map.isEmpty()){
		return n_map;
	}
	for(int x = 0; x < a_map.getPosition(); x++){
		n_map += "Key: ";
		n_map += a_map.getKeyByPosition(x)->toNote();
		n_map += " Value: ";
		n_map += a_map.getByPosition(x)->toNote();
		if(x != a_map.getPosition() - 1){
			n_map += '\n';
		}
	}
	
	return n_map;
}

template<class K, class V>
Note MapNote_pn(const PrimitiveRawMap<K,V>& a_map){
	Note n_map;
	if(a_map.isEmpty()){
		return n_map;
	}
	for(int x = 0; x < a_map.getPosition(); x++){
		n_map += "Key: ";
		n_map += Note(*a_map.getKeyByPosition(x));
		n_map += " Value: ";
		n_map += a_map.getByPosition(x)->toNote();
		if(x != a_map.getPosition() - 1){
			n_map += '\n';
		}
	}
	
	return n_map;
}

template<class K, class V>
Note MapNote_np(const PrimitiveRawMap<K,V>& a_map){
	Note n_map;
	if(a_map.isEmpty()){
		return n_map;
	}
	for(int x = 0; x < a_map.getPosition(); x++){
		n_map += "Key: ";
		n_map += a_map.getKeyByPosition(x)->toNote();
		n_map += " Value: ";
		n_map += Note(*a_map.getByPosition(x));
		if(x != a_map.getPosition() - 1){
			n_map += '\n';
		}
	}
	
	return n_map;
}

}

#endif