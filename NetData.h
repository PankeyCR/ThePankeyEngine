#ifndef NetData_h
#define NetData_h

#include "cppObject.h"

class NetData : public cppObject{
	public:
		NetData();
		~NetData();
		
		virtual void initialize(cppObject *obj);
		virtual void update();
		
		//cppObject part
		virtual String getClassName();
		virtual String toString();
		virtual NetData *clone();
		
	private:
};

#endif