
#ifndef RawMap_h
#define RawMap_h

#include "cppObject.h"
#include "Iterator.h"

namespace ame{

template <class K,class V>
class RawMap{	
    public:
		virtual ~RawMap(){}
		virtual bool isEmpty()const=0;
		virtual void setPosition(int p)=0;
		virtual int getPosition()const=0;
		virtual int getSize()const=0;
		virtual void addPointers(K* key, V* value)=0;
		virtual void addLValues(K key, V value)=0;
		virtual void add(K key, V value){
			addLValues(key,value);
		}
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
	private:
};

}
#endif 
