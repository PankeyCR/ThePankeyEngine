
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
		virtual T* add(T* value)=0;
		virtual T* add(T value)=0;
		virtual T* set(int position, T value)=0;
		virtual T* set(int position, T* value)=0;
		virtual T* insert(int position, T value)=0;
		virtual T* insert(int position, T* value)=0;
		virtual T* get(T* key)=0;
		virtual T* get(T key)=0;
		virtual T* getByPos(int x)=0;
		virtual bool contain(T* key)=0;
		virtual bool contain(T key)=0;
		virtual void reset()=0;
		virtual void resetDelete()=0;
		virtual T* remove(T* key)=0;
		virtual T* remove(T key)=0;
		virtual T* removeByPos(int p)=0;
		virtual void removeDelete(T* key)=0;
		virtual void removeDelete(T key)=0;
		virtual void removeDeleteByPos(int p)=0;
		virtual T& operator[](int x);
		//cppObject part
		virtual List<T>* clone();
		//iterator part
		virtual T getValue()=0;
		virtual T* getPointer()=0;
		virtual T* set(T s)=0;
		virtual T* set(T* s)=0;
		virtual T* insert(T s)=0;
		virtual T* insert(T* s)=0;
		virtual T* remove()=0;
		virtual void removeDelete()=0;
	private:
};
#endif 
