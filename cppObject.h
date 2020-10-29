

#ifndef cppObject_h
#define cppObject_h

#include "Arduino.h"

class cppObject {
    public:
		cppObject();
		virtual ~cppObject();
		virtual void onDelete();
		virtual String getClassName();
		virtual String toString();
		virtual bool equal(cppObject *b);
		template<class T>
		bool instanceof(){
			T t;
			return this->instanceof(t.getClassName());
		}
		virtual bool instanceof(String name);
		virtual cppObject *clone();
		virtual void operator=(cppObject b);
		virtual bool operator==(cppObject b);
		virtual bool operator!=(cppObject b);
	private:
};

#endif 
