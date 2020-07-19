

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
		/*
		bool checkSyntax(Map<String,String>* code);
		List<List<String>>* getBlocks(Map<String,String>* code);
		//GameObject* getBlock(Parser* parser);
		*/
		virtual void operator=(Block b);
		virtual bool operator==(Block b);
		virtual bool operator!=(Block b);
	protected:
		List<String>* syntaxList = nullptr;
};

#endif 
