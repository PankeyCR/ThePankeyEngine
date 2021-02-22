
#ifndef Map_h
#define Map_h

#include "cppObject.h"
#include "Iterator.h"

template <class K,class V>
class Map : public cppObject , public Iterator{	
    public:
		virtual ~Map(){}
		virtual bool isEmpty()=0;
		virtual void setPosition(int p)=0;
		virtual int getPosition()=0;
		virtual int getSize()=0;
		virtual void addPointers(K* key, V* value)=0;
		virtual void addLValues(K key, V value)=0;
		virtual void addPointer(K key, V* value)=0;
		virtual void setPointers(K* key, V* value)=0;
		virtual void setLValues(K key, V value)=0;
		virtual void setPointer(K key, V* value)=0;
		virtual void setKeyLValueByPosition(int p, K key)=0;
		virtual void setKeyPointerByPosition(int p, K* key)=0;
		virtual void setValueByPosition(int p, V value)=0;
		virtual void setValuePointerByPosition(int p, V *value)=0;
		virtual bool containKeyByPointer(K* key)=0;
		virtual bool containKeyByLValue(K key)=0;
		virtual bool containValueByPointer(V* value)=0;
		virtual bool containValueByLValue(V value)=0;
		virtual V* getByPointer(K* key)=0;
		virtual V* getByLValue(K key)=0;
		virtual V* getByPosition(int p)=0;
		virtual K* getKeyByPosition(int p)=0;
		virtual K* getKeyByPointer(V* value)=0;
		virtual K* getKeyByLValue(V value)=0;
		virtual void reset()=0;
		virtual void resetDelete()=0;
		virtual void resetDeleteKey()=0;
		virtual void resetDeleteValue()=0;
		virtual V* removeByPointer(K* key)=0;
		virtual V* removeByLValue(K key)=0;
		virtual V* removeByPosition(int p)=0;
		virtual void removeDeleteByPointer(K* key)=0;
		virtual void removeDeleteByLValue(K key)=0;
		virtual void removeDeleteByPosition(int p)=0;
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
