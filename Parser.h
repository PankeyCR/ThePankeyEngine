

#ifndef Parser_h
#define Parser_h

#include "LinkedList.h"
#include "ArrayList.h"
#include "Arduino.h"
#include "List.h"

class Parser{
    public:
		Parser();
		~Parser();
		
	protected:
		List<String>* captureToken = nullptr;
		List<String>* tokens = nullptr;
		List<char>* breakPoint = nullptr;
};

#endif 
