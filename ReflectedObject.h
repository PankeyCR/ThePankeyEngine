#ifndef ReflectedObject_h
#define ReflectedObject_h

#include "Arduino.h"
#include "cppObject.h"
#include "Vector2f.h"

template <class R>
class ReflectedObject{	
    public:
		static R *newInstance();
		static R *newInstanceArray(int size);
		static R *cast(cppObject *obj);
		static bool isType(String is);
		
		
	private:
};
#endif 