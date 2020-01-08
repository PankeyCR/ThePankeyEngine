

#ifndef PrimitiveList_h
#define PrimitiveList_h

#include "TimeElapsed.h"
#include "AbstractRead.h"
#include "cppObject.h"
#include "AppState.h"
#include "Arduino.h"
#include "Neuron.h"
#include "List.h"

template<class T>
class PrimitiveList : public List<T>{
	public:
		int expandSize=5;
		PrimitiveList();
		PrimitiveList(int lsize);
		~PrimitiveList();
		
		virtual void setPos(int p);
		virtual int getPos();
		virtual int getSize();
		virtual void add(List<T> *list);
		virtual void add(T *value);
		virtual void add(T value);
		virtual void set(int pos,T value);
		virtual void set(int pos,T *value);
		virtual T *get(T *key);
		virtual T *get(T key);
		virtual T *getByPos(int x);
		virtual bool contain(T *key);
		virtual bool contain(T key);
		virtual void reset();
		virtual void resetDelete();
		virtual T *remove(T *key);
		virtual T *remove(T key);
		virtual T *removeByPos(int p);
		virtual void removeDelete(T *key);
		virtual void removeDelete(T key);
		virtual void removeDeleteByPos(int p);
		
		//iterator part
		virtual T getValue();
		virtual T *getPointer();		
		virtual int getIterationSize();
		
		//cppObject part
		virtual void onDelete();
		virtual String getClassName();
		virtual String toString();
		virtual PrimitiveList<T>* clone();
		
		//resize length by adding more space
		virtual void expandLocal(int add);
		virtual PrimitiveList<T>* expand(int add);
	protected:
		T **value;
		int pos=0;
		int size=10;
};

#endif 
