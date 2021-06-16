
#ifndef Map_h
#define Map_h

#include "cppObject.h"
#include "Iterator.h"
#include "RawMap.h"

template <class K,class V>
class Map : public cppObject , public Iterator , public RawMap<K,V>{	
    public:
		virtual ~Map(){}
		//iterator part
		virtual V getLValue(Iterator iterate)=0;
		virtual V* getPointer(Iterator iterate)=0;
		virtual K getKey(Iterator iterate)=0;
		virtual K* getKeyPointer(Iterator iterate)=0;
		//cppObject part
		virtual Map<K,V>* clone(void)=0;
		virtual Map<K,V>* clone(bool owningMemory)=0;
	private:
};
#endif 
