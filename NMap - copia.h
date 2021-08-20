
#ifndef NMap_h
#define NMap_h
/*
#include "List.h"
#include "Map.h"

template <class N,class K,class V,class L>
class NMap : public cppObject{
public:
	virtual void setNMap(NMap<N,K,V,L> nmap)=0;
	virtual void setNMap(NMap<N,K,V,L>* nmap)=0;
	
	template<class... args>
	void NestMap(N mapName, args... x){
		PrimitiveList<N> n;
		n.addPack<args...>(x...);
		for(int x=0; x < n.getPosition(); x++){
			this->NestMap(mapName, *n.getByPosition(x));
		}
	}
	
	virtual void NestMap(N mapName, N subName)=0;
	virtual void NestMap(N mapName,List<N>* arrayMap)=0;
	
	template<class... args>
	Map<N,Map<N,NMap<N,K,V,L>>>* getNestMap(N m, args... x){
		return nullptr;
	}
	
	virtual Map<N,Map<N,NMap<N,K,V,L>>>* getNestMap(N m, N* n)=0;
	virtual Map<N,Map<N,NMap<N,K,V,L>>>* getNestMap(N m, List<N>* n)=0;
	
	template<class... args>
	NMap<N,K,V,L>* getNMap(N m, List<N> n){
		return nullptr;
	}
	
	virtual NMap<N,K,V,L>* getNMap(N m, N* n)=0;
	virtual NMap<N,K,V,L>* getNMap(N m, List<N>* n)=0;
	virtual N getName()=0;
	virtual N getFluxName()=0;
	virtual List<N> getFluxNames()=0;
	virtual N getFluxSubName()=0;
	virtual void addValueMap(N m, Map<K,V> map)=0;
	virtual void addValueMap(N m, Map<K,V> *map)=0;
	virtual void addValueMap(N *m, Map<K,V> *map)=0;
	virtual void addValueMap( Map<K,V> map)=0;
	virtual void addValueMap( Map<K,V> *map)=0;
	virtual void addValue(K k,V v)=0;
	virtual void addValue(K k,V *v)=0;
	virtual void addValue(K *k,V *v)=0;
	virtual void addValue(N m, K k,V v)=0;
	virtual void addValue(N m, K k,V *v)=0;
	virtual void addValue(N m, K *k,V *v)=0;
	virtual void addValue(N *m, K *k,V *v)=0;
	virtual V removeValue(K k)=0;
	virtual V removeValue(K *k)=0;
	virtual V removeValue(N m, K k)=0;
	virtual V removeValue(N m, K *k)=0;
	virtual V removeValue(N *m, K *k)=0;
	virtual Map<K,V> *getValueMap()=0;
	virtual Map<K,V> *getValueMap(N m)=0;
	virtual Map<K,V> *getValueMap(N *m)=0;
	virtual V *getValue(K k)=0;
	virtual V *getValue(K *k)=0;
	virtual V *getValue(N m,K k)=0;
	virtual V *getValue(N m,K *k)=0;
	virtual V *getValue(N *m,K *k)=0;
	virtual void addList(N m, List<L> list)=0;
	virtual void addList(N m, List<L> *list)=0;
	virtual void addList(N *m, List<L> *list)=0;
	virtual void addList(List<L> list)=0;
	virtual void addList(List<L> *list)=0;
	virtual void addList( L list)=0;
	virtual void addList( L *list)=0;
	virtual void addList(N m, L list)=0;
	virtual void addList(N m, L *list)=0;
	virtual void addList(N *m, L *list)=0;
	virtual List<L> *getList()=0;
	virtual List<L> *getList(N m)=0;
	virtual List<L> *getList(N *m)=0;
	virtual L *getList(int list)=0;
	virtual L *getList(N m, int list)=0;
	virtual L *getList(N *m, int list)=0;
	virtual NMap<N,K,V,L> *getFluxMap()=0;
	virtual void FluxMap(N m, List<N> n)=0;
	virtual void FluxMap(N m, List<N> *n)=0;
	virtual void putFluxValueMap(Map<K,V> map)=0;
	virtual void putFluxValueMap(Map<K,V> *map)=0;
	virtual void putFluxValueMap(N m, Map<K,V> map)=0;
	virtual void putFluxValueMap(N m, Map<K,V> *map)=0;
	virtual void putFluxValueMap(N *m, Map<K,V> *map)=0;
	virtual void putFluxValue(K k,V v)=0;
	virtual void putFluxValue(K k,V *v)=0;
	virtual void putFluxValue(K *k,V *v)=0;
	virtual void putFluxValue(N m, K k,V v)=0;
	virtual void putFluxValue(N m, K k,V *v)=0;
	virtual void putFluxValue(N m, K *k,V *v)=0;
	virtual void putFluxValue(N *m, K *k,V *v)=0;
	virtual Map<K,V> *getFluxValueMap()=0;
	virtual Map<K,V> *getFluxValueMap(N m)=0;
	virtual Map<K,V> *getFluxValueMap(N *m)=0;
	virtual V *getFluxValue(K k)=0;
	virtual V *getFluxValue(K *k)=0;
	virtual V *getFluxValue(N m,K k)=0;
	virtual V *getFluxValue(N m,K *k)=0;
	virtual V *getFluxValue(N *m,K *k)=0;
	virtual void addFluxList(N m, List<L> list)=0;
	virtual void addFluxList(N m, List<L> *list)=0;
	virtual void addFluxList(N *m, List<L> *list)=0;
	virtual void addFluxList(List<L> list)=0;
	virtual void addFluxList(List<L> *list)=0;
	virtual void addFluxList( L list)=0;
	virtual void addFluxList( L *list)=0;
	virtual void addFluxList(N m, L list)=0;
	virtual void addFluxList(N m, L *list)=0;
	virtual void addFluxList(N *m, L *list)=0;
	virtual List<L> *getFluxListMap()=0;
	virtual List<L> *getFluxListMap(N m)=0;
	virtual L *getFluxList(int list)=0;
	virtual L *getFluxList(N m, int list)=0;
	virtual L *getFluxList(N *m, int list)=0;
	virtual void restartMap()=0;
	virtual bool nextMap(N mapname, N mapsubname)=0;
	virtual bool nextMap(N mapname, N *mapsubname)=0;
	virtual bool nextMap(N *mapname, N *mapsubname)=0;
	virtual bool nextMap(N mapsubname)=0;
	virtual bool nextMap(N *mapsubname)=0;
	virtual bool lastMap()=0;
	virtual int getInfoListsize()=0;
	virtual void addInfoList(N list)=0;
	virtual void addInfoList(N *list)=0;
	virtual void removeInfoList(N list)=0;
	virtual void removeInfoList(N *list)=0;
	virtual void removeInfoList(int list)=0;
	virtual N getInfoList(int list)=0;
	virtual List<N> *getInfoListAttay()=0;
	virtual bool containsInfoList(N list)=0;
	virtual bool containsInfoList(N *list)=0;
	virtual int getInfoMapsize()=0;
	virtual void addInfoMap(N list)=0;
	virtual void addInfoMap(N *list)=0;
	virtual void removeInfoMap(N list)=0;
	virtual void removeInfoMap(N *list)=0;
	virtual void removeInfoMap(int list)=0;
	virtual N getInfoMap(int list)=0;
	virtual List<N> *getInfoMapArray()=0;
	virtual bool containsInfoMap(N list)=0;
	virtual bool containsInfoMap(N *list)=0;
	virtual int getFluxInfoListsize()=0;
	virtual void addFluxInfoList(N list)=0;
	virtual void addFluxInfoList(N *list)=0;
	virtual void removeFluxInfoList(N list)=0;
	virtual void removeFluxInfoList(N *list)=0;
	virtual void removeFluxInfoList(int list)=0;
	virtual N *getFluxInfoList(int list)=0;
	virtual List<N> *getFluxInfoListArray()=0;
	virtual bool containsFluxInfoList(N list)=0;
	virtual bool containsFluxInfoList(N *list)=0;
	virtual int getFluxInfoMapsize()=0;
	virtual void addFluxInfoMap(N list)=0;
	virtual void addFluxInfoMap(N *list)=0;
	virtual void removeFluxInfoMap(N list)=0;
	virtual void removeFluxInfoMap(N *list)=0;
	virtual void removeFluxInfoMap(int list)=0;
	virtual N *getFluxInfoMap(int list)=0;
	virtual List<N> *getFluxInfoMapArray()=0;
	virtual bool containsFluxInfoMap(N list)=0;
	virtual bool containsFluxInfoMap(N *list)=0;
	virtual NMap<N,K,V,L> *clone()=0;
};*/

#endif