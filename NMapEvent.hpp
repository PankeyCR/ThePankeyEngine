
#include "ame_Enviroment.hpp"

#if defined(DISABLE_NMapEvent)
	#define NMapEvent_hpp
#endif

#ifndef NMapEvent_hpp
#define NMapEvent_hpp
#define NMapEvent_AVAILABLE

#ifndef ame_Enviroment_Defined

#endif

#ifdef ame_Windows

#endif

#ifdef ame_ArduinoIDE
	#include "Arduino.h"
#endif

#include "NMap.hpp"
#include "List.hpp"
#include "ArrayList.hpp"
#include "KPMap.hpp"
#include "KVMap.hpp"

namespace ame{

template <class N,class K,class V,class L>
class NMapEvent : public NMap<N,K,V,L>{
public:
	NMapEvent(N n){
		valueMap = new PrimitiveMap<N,PrimitiveMap<K,V,Ms>>();
		listMap = new PrimitiveMap<N,PrimitiveList<L>>();
		name = n;
	}
	
	
	cppObejctClass* getClass(){
		return Class<NMapEvent>::classType;
	}
	Note toNote(){
		return "NMapEvent";
	}
 
	
	N getName(){
		return name;
	}
	
	void addValueMap(){
		valueMap->add(name, new KVMap<K,V,Ms>());
	}
	
	void addValueMap(N m){
		valueMap->add(m, new KVMap<K,V,Ms>());
	}
	
	void addValueMap(N *m){
		valueMap->add(m, new KVMap<K,V,Ms>());
	}
	
	void addValueMap(List<N> *list){
		for(int x=0; x < list->getPos(); x++){
			valueMap->add(*list->getByPos(x), new KVMap<K,V,Ms>());			
		}				
	}
	
	void addValueMap(N m, KVMap<K,V,Ms> map){
		valueMap->add(m, map);
	}
	
	void addValueMap(N m, KVMap<K,V,Ms> *map){
		valueMap->add(m, map);
	}
	
	void addValueMap(N *m, KVMap<K,V,Ms> *map){
		valueMap->add(m, map);
	}
	
	void addValueMap( KVMap<K,V,Ms> map){
		valueMap->add(name, map);
	}
	
	void addValueMap( KVMap<K,V,Ms> *map){
		valueMap->add(name, map);
	}
	
	void addValue(K k,V v){
		if(valueMap->get(name)==NULL){
			return;
		}
		valueMap->get(name)->add(k,v);
	}
	
	void addValue(K k,V *v){
		if(valueMap->get(name)==NULL){
			return;
		}
		valueMap->get(name)->add(k,v);
	}
	
	void addValue(K *k,V *v){
		if(valueMap->get(name)==NULL){
			return;
		}
		valueMap->get(name)->add(k,v);
	}
	
	void addValue(N m, K k,V v){
		if(valueMap->get(m)==NULL){
			return;
		}
		valueMap->get(m)->add(k,v);
	}
	
	void addValue(N m, K k,V *v){
		if(valueMap->get(m)==NULL){
			return;
		}
		valueMap->get(m)->add(k,v);
	}
	
	void addValue(N m, K *k,V *v){
		if(valueMap->get(m)==NULL){
			return;
		}
		valueMap->get(m)->add(k,v);
	}
	
	void addValue(N *m, K *k,V *v){
		if(valueMap->get(m)==NULL){
			return;
		}
		valueMap->get(m)->add(k,v);
	}
	
	V *removeValue(K k){
		if(valueMap->get(name)==NULL){
			return NULL;
		}
		return valueMap->get(name)->remove(k);
	}
	
	V *removeValue(K *k){
		if(valueMap->get(name)==NULL){
			return NULL;
		}
		return valueMap->get(name)->remove(k);
	}
	
	V *removeValue(N m, K k){
		if(valueMap->get(m)==NULL){
			return NULL;
		}
		return valueMap->get(m)->remove(k);
	}
	
	V *removeValue(N m, K *k){
		if(valueMap->get(m)==NULL){
			return NULL;
		}
		return valueMap->get(m)->remove(k);
	}
	
	V *removeValue(N *m, K *k){
		if(valueMap->get(m)==NULL){
			return NULL;
		}
		return valueMap->get(m)->remove(k);
	}
	
	Map<K,V> *getValueMap(){
		if(valueMap->get(name)==NULL){
			return NULL;
		}
		return valueMap->get(name);
	}
	
	Map<K,V> *getValueMap(N m){
		if(valueMap->get(m)==NULL){
			return NULL;
		}
		return valueMap->get(m);
	}
	
	Map<K,V> *getValueMap(N *m){
		if(valueMap->get(m)==NULL){
			return NULL;
		}
		return valueMap->get(m);
	}
	
	V *getValue(K k){
		if(valueMap->get(name)==NULL){
			return NULL;
		}
		return valueMap->get(name)->get(k);
	}
	
	V *getValue(K *k){
		if(valueMap->get(name)==NULL){
			return NULL;
		}
		return valueMap->get(name)->get(k);
	}
	
	V *getValue(N m,K k){
		if(valueMap->get(m)==NULL){
			return NULL;
		}
		return valueMap->get(m)->get(k);
	}
	
	V *getValue(N m,K *k){
		if(valueMap->get(m)==NULL){
			return NULL;
		}
		return valueMap->get(m)->get(k);
	}
	
	V *getValue(N *m,K *k){
		if(valueMap->get(m)==NULL){
			return NULL;
		}
		return valueMap->get(m)->get(k);
	}
	
	void addListMap(){
		listMap->add(name,new ArrayList<L,Ls>());
	}
	
	void addListMap(N m){
		listMap->add(m,new ArrayList<L,Ls>());
	}
	
	void addListMap(N *m){
		listMap->add(m,new ArrayList<L,Ls>());
	}
	
	void addListMap(N m, ArrayList<L,Ls> *list){
		listMap->add(m,list);
	}
	
	void addListMap(N *m, ArrayList<L,Ls> *list){
		listMap->add(m,list);
	}
	
	void addListMap(ArrayList<L,Ls> *list){
		listMap->add(name,list);
	}
	
	void addList( L list){
		if(listMap->get(name)==NULL){
			return;
		}
		listMap->get(name)->add(list);
	}
	
	void addList( L *list){
		if(listMap->get(name)==NULL){
			return;
		}
		listMap->get(name)->add(list);
	}
	
	void addList(N m, L list){
		if(listMap->get(m)==NULL){
			return;
		}
		listMap->get(m)->add(list);
	}
	
	void addList(N m, L *list){
		if(listMap->get(m)==NULL){
			return;
		}
		listMap->get(m)->add(list);
	}
	
	void addList(N *m, L *list){
		if(listMap->get(m)==NULL){
			return;
		}
		listMap->get(m)->add(list);
	}
	
	List<L> *getListMap(){
		if(listMap->get(name)==NULL){
			return NULL;
		}
		return listMap->get(name);
	}
	
	List<L> *getListMap(N m){
		if(listMap->get(m)==NULL){
			return NULL;
		}
		return listMap->get(m);
	}
	
	List<L> *getListMap(N *m){
		if(listMap->get(m)==NULL){
			return NULL;
		}
		return listMap->get(m);
	}
	
	L *getList(int list){
		if(listMap->get(name)==NULL){
			return NULL;
		}
		return listMap->get(name)->getByPos(list);
	}
	
	L *getList(N m, int list){
		if(listMap->get(m)==NULL){
			return NULL;
		}
		return listMap->get(m)->getByPos(list);
	}
	
	L *getList(N *m, int list){
		if(listMap->get(m)==NULL){
			return NULL;
		}
		return listMap->get(m)->getByPos(list);
	}
	
	NMap<N,K,V,L> *clone(){
		return NULL;
	}
private:
	KPMap<N,KVMap<K,V,Ms>,Nm> *valueMap;
	KPMap<N,ArrayList<L,Ls>,Nl> *listMap;
	N name;
};

}

#endif