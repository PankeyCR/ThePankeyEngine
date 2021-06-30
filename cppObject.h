
#ifndef cppObject_h
#define cppObject_h

#include "Arduino.h"
#include "Method.h"
#include "cppObjectClass.h"
#include "ClassType.h"

template<class cls>
struct Class{
	static ClassType<cls>* classType;
};

template<class cls> ClassType<cls>* Class<cls>::classType = new ClassType<cls>();

//class cppObject/* : public ManegedMemory<cppObject>*/{
class cppObject{
    public:
		cppObject();
		virtual ~cppObject();
		virtual void onDelete();
		virtual String toString();
		virtual bool equal(cppObject *b);
		template<class T>
		bool instanceof(){
			return this->instanceof(Class<T>::classType);
		}
		virtual bool instanceof(cppObjectClass* cls);
		
		virtual cppObject *clone(void);
		virtual cppObject *clone(bool owningMemory);
		
		virtual cppObjectClass* getClass();
		
		virtual void operator=(cppObject b);
		virtual bool operator==(cppObject b);
		virtual bool operator!=(cppObject b);
	private:
};

#endif 
