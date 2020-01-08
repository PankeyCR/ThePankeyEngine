

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
		virtual cppObject *clone();
		virtual void operator=(cppObject b);
		virtual bool operator==(cppObject b);
		virtual bool operator!=(cppObject b);
	private:
};

#endif 
