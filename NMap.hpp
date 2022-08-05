
#include "ame_Enviroment.hpp"

#if defined(DISABLE_NMap)
	#define NMap_hpp
#endif

#ifndef NMap_hpp
#define NMap_hpp
#define NMap_AVAILABLE

#ifndef ame_Enviroment_Defined

#endif

#ifdef ame_Windows

#endif

#ifdef ame_ArduinoIDE
	#include "Arduino.h"
	#include "Printable.h"
#endif

#include "List.hpp"
#include "Map.hpp"

namespace ame{

template <class N,class K,class V,class L>
class NMap : public cppObject{
	private:	
	
    public:
		virtual N getName()=0;
		virtual void addValueMap()=0;
		virtual void addValueMap(N m)=0;
		virtual void addValueMap(N *m)=0;
		virtual void addValueMap(List<N> *list)=0;
		virtual void addValue(K k,V v)=0;
		virtual void addValue(K k,V *v)=0;
		virtual void addValue(K *k,V *v)=0;
		virtual void addValue(N m, K k,V v)=0;
		virtual void addValue(N m, K k,V *v)=0;
		virtual void addValue(N m, K *k,V *v)=0;
		virtual void addValue(N *m, K *k,V *v)=0;
		virtual V *removeValue(K k)=0;
		virtual V *removeValue(K *k)=0;
		virtual V *removeValue(N m, K k)=0;
		virtual V *removeValue(N m, K *k)=0;
		virtual V *removeValue(N *m, K *k)=0;
		virtual Map<K,V> *getValueMap()=0;
		virtual Map<K,V> *getValueMap(N m)=0;
		virtual Map<K,V> *getValueMap(N *m)=0;
		virtual V *getValue(K k)=0;
		virtual V *getValue(K *k)=0;
		virtual V *getValue(N m,K k)=0;
		virtual V *getValue(N m,K *k)=0;
		virtual V *getValue(N *m,K *k)=0;
		virtual void addListMap()=0;
		virtual void addListMap(N m)=0;
		virtual void addListMap(N *m)=0;
	//	virtual void addList(N m, List<L> list)=0;
	//	virtual void addList(N m, List<L> *list)=0;
		//virtual void addList(N *m, List<L> *list)=0;
		//virtual void addList(List<L> list)=0;
		//virtual void addList(List<L> *list)=0;
		virtual void addList( L list)=0;
		virtual void addList( L *list)=0;
		virtual void addList(N m, L list)=0;
		virtual void addList(N m, L *list)=0;
		virtual void addList(N *m, L *list)=0;
		virtual List<L> *getListMap()=0;
		virtual List<L> *getListMap(N m)=0;
		virtual List<L> *getListMap(N *m)=0;
		virtual L *getList(int list)=0;
		virtual L *getList(N m, int list)=0;
		virtual L *getList(N *m, int list)=0;
};

}

#endif