
#ifndef Function_h
#define Function_h

#include "cppObject.h"

template<class T,class... args>
class Function : public cppObject{
	public:
		virtual ~Function(){}
		virtual T f(args... mf)=0;
	protected:
	
};

#endif 
