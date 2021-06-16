
#ifndef List_h
#define List_h

#include "Iterator.h"
#include "cppObject.h"
#include "RawList.h"

template <class T>
class List : public cppObject , public Iterator , public RawList<T>{	
	public:
	virtual ~List(){}
	//cppObject part
	virtual List<T>* clone(void)=0;
	virtual List<T>* clone(bool owningMemory)=0;
	//iterator part
	virtual T getLValue(Iterator iterate)=0;
	virtual T get(Iterator iterate){
		this->getLValue(iterate);
	}
	virtual T* getPointer(Iterator iterate)=0;
	virtual T* setLValue(Iterator iterate, T s)=0;
	virtual T* setPointer(Iterator iterate, T* s)=0;
	virtual T* insertLValue(Iterator& iterate, T s)=0;
	virtual T* insertPointer(Iterator& iterate, T* s)=0;
	virtual T* remove(Iterator& iterate)=0;
	virtual void removeDelete(Iterator& iterate)=0;
	
	// virtual T* operator+=(const T& value){
		// return this->addLValue(value);
	// }
	private:
};
#endif 
