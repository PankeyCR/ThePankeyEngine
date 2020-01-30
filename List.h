
#ifndef SafeValueArrayList_h
#define SafeValueArrayList_h

#include "Iterator.h"
#include "cppObject.h"

template <class T>
class List : public cppObject , public Iterator{	
    public:
		virtual void setPos(int p)=0;
		virtual int getPos()=0;
		virtual int getSize()=0;
		virtual void add(List<T> *list)=0;
		virtual void add(T *value)=0;
		virtual void add(T value)=0;
		virtual void set(int pos,T value)=0;
		virtual void set(int pos,T *value)=0;
		virtual T *get(T *key)=0;
		virtual T *get(T key)=0;
		virtual T *getByPos(int x)=0;
		virtual bool contain(T *key)=0;
		virtual bool contain(T key)=0;
		virtual void reset()=0;
		virtual void resetDelete()=0;
		virtual T *remove(T *key)=0;
		virtual T *remove(T key)=0;
		virtual T *removeByPos(int p)=0;
		virtual void removeDelete(T *key)=0;
		virtual void removeDelete(T key)=0;
		virtual void removeDeleteByPos(int p)=0;
		//iterator part
		virtual T getValue()=0;
		virtual T *getPointer()=0;
		// virtual void set(T s)=0;
		// virtual void set(T* s)=0;
	private:
};
#endif 
