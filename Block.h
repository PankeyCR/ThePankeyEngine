

#ifndef Block_h
#define Block_h

#include "GameObject.h"
#include "Arduino.h"
#include "Map.h"
#include "List.h"

class Block{
    public:
		Block();
		~Block();
		
		virtual void operator=(Block b);
		virtual bool operator==(Block b);
		virtual bool operator!=(Block b);
	protected:
		List<String>* syntaxList = nullptr;
};

#endif 
