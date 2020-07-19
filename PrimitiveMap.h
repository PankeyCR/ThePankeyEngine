
#ifndef PrimitiveMap_h
#define PrimitiveMap_h

#include "TimeElapsed.h"
#include "AbstractRead.h"
#include "LinkedList.h"
#include "cppObject.h"
#include "AppState.h"
#include "Arduino.h"
#include "GameOn.h"
#include "Map.h"

template <class K,class V>
class PrimitiveMap : public Map<K,V>{	
    public:
		int expandSize=5;
		PrimitiveMap();
		PrimitiveMap(int msize);
		~PrimitiveMap();
		
		virtual void setPos(int p);
		virtual int getPos();
		virtual int getSize();
		virtual void add(K *key, V *value);
		virtual void add(K key, V value);
		virtual void add(K key, V *value);
		virtual void set(K *key, V *value);
		virtual void set(K key, V value);
		virtual void set(K key, V *value);
		virtual void setKeyByPos(int p, K key);
		virtual void setKeyByPos(int p, K *key);
		virtual void setValueByPos(int p, V value);
		virtual void setValueByPos(int p, V *value);
		virtual bool contain(K *key);
		virtual bool contain(K key);
		virtual bool containValue(V *value);
		virtual bool containValue(V value);
		virtual V *get(K *key);
		virtual V *get(K key);
		virtual V *getByPos(int p);
		virtual K *getKeyByPos(int p);
		virtual K *getKey(V *value);
		virtual K *getKey(V value);
		virtual void reset();
		virtual void resetDelete();
		virtual V *remove(K *key);
		virtual V *remove(K key);
		virtual V *removeByPos(int p);
		virtual void removeDelete(K *key);
		virtual void removeDelete(K key);
		virtual void removeDeleteByPos(int p);
		
		//iterator part
		virtual V getValue();
		virtual V *getPointer();
		virtual K getKey();
		virtual K *getKeyPointer();		
		virtual int getIterationSize();
		
		
		//cppObject part
		virtual void onDelete();
		virtual String getClassName();
		virtual String toString();
		virtual Map<K,V>* clone();
		
		//resize length by adding more space
		virtual void expandLocal(int add);
		virtual PrimitiveMap<K,V>* expand(int add);
	protected:
		K **key;
		V **value;
		int pos=0;
		int size=10;
};
#endif 
