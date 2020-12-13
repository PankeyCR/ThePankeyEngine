

#ifndef Statement_h
#define Statement_h

#include "GameObject.h"
#include "Arduino.h"
#include "List.h"

class Statement{
    public:
		Statement();
		virtual ~Statement();
		
		virtual void operator=(Statement b);
		virtual bool operator==(Statement b);
		virtual bool operator!=(Statement b);
	protected:
		List<String>* syntaxList = nullptr;
};

#endif 
