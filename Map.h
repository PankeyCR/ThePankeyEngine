
#ifndef Map_h
#define Map_h

#include "cppObject.h"
#include "Iterator.h"

template <class K,class V>
class Map : public cppObject , public Iterator{	
    public:
		virtual ~Map(){}
		virtual void setPos(int p)=0;
		virtual int getPos()=0;
		virtual int getSize()=0;
		virtual void add(K *key, V *value)=0;
		virtual void add(K key, V value)=0;
		virtual void add(K key, V *value)=0;
		virtual void set(K *key, V *value)=0;
		virtual void set(K key, V value)=0;
		virtual void set(K key, V *value)=0;
		virtual void setKeyByPos(int p, K key)=0;
		virtual void setKeyByPos(int p, K *key)=0;
		virtual void setValueByPos(int p, V value)=0;
		virtual void setValueByPos(int p, V *value)=0;
		virtual bool contain(K *key)=0;
		virtual bool contain(K key)=0;
		virtual bool containValue(V *value)=0;
		virtual bool containValue(V value)=0;
		virtual V *get(K *key)=0;
		virtual V *get(K key)=0;
		virtual V *getByPos(int p)=0;
		virtual K *getKeyByPos(int p)=0;
		virtual K *getKey(V *value)=0;
		virtual K *getKey(V value)=0;
		virtual void reset()=0;
		virtual void resetDelete()=0;
		virtual V *remove(K *key)=0;
		virtual V *remove(K key)=0;
		virtual V *removeByPos(int p)=0;
		virtual void removeDelete(K *key)=0;
		virtual void removeDelete(K key)=0;
		virtual void removeDeleteByPos(int p)=0;
		//iterator part
		virtual V getValue()=0;
		virtual V *getPointer()=0;
		virtual K getKey()=0;
		virtual K *getKeyPointer()=0;
		virtual Map<K,V>* clone()=0;
	private:
};
#endif 
