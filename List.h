
#ifndef List_h
#define List_h

#include "Iterator.h"
#include "cppObject.h"

template <class T>
class List : public cppObject , public Iterator{	
	public:
	virtual bool isEmpty()const=0;
	virtual void setPosition(int p)=0;
	virtual int getPosition()=0;
	virtual int getSize()=0;
	virtual void addList(List<T> *list)=0;
	virtual T* addPointer(T* value)=0;
	virtual T* addLValue(T value)=0;
	virtual T* setLValue(int position, T value)=0;
	virtual T* setPointer(int position, T* value)=0;
	virtual T* insertLValue(int position, T value)=0;
	virtual T* insertPointer(int position, T* value)=0;
	virtual T* getByPointer(T* key)=0;
	virtual T* getByLValue(T key)=0;
	virtual T* getByPosition(int x)=0;
	virtual bool containByPointer(T* key)=0;
	virtual bool containByLValue(T key)=0;
	virtual int getIndexByPointer(T* key)=0;
	virtual int getIndexByLValue(T key)=0;
	virtual void reset()=0;
	virtual void resetDelete()=0;
	virtual T* removeByPointer(T* key)=0;
	virtual T* removeByLValue(T key)=0;
	virtual T* removeByPosition(int p)=0;
	virtual void removeDeleteByPointer(T* key)=0;
	virtual void removeDeleteByLValue(T key)=0;
	virtual void removeDeleteByPosition(int p)=0;
	virtual T& operator[](int x)=0;
	//cppObject part
	virtual List<T>* clone(void)=0;
	virtual List<T>* clone(bool owningMemory)=0;
	//iterator part
	virtual T getLValue(Iterator iterate)=0;
	virtual T* getPointer(Iterator iterate)=0;
	virtual T* setLValue(Iterator iterate, T s)=0;
	virtual T* setPointer(Iterator iterate, T* s)=0;
	virtual T* insertLValue(Iterator& iterate, T s)=0;
	virtual T* insertPointer(Iterator& iterate, T* s)=0;
	virtual T* remove(Iterator& iterate)=0;
	virtual void removeDelete(Iterator& iterate)=0;
	private:
};
#endif 
