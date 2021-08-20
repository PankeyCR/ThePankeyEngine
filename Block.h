

#ifndef Block_h
#define Block_h

#include "Environment.h"

namespace ame{

class Block{
    public:
		Block(){}
		virtual ~Block(){}
		
		virtual void setCode(String c){code = c;}
		virtual Block* run(<T,args...>(Environment* e){return nullptr;}
		
		virtual void operator=(Block b){code = b.code;}
		virtual bool operator==(Block b){code == b.code;}
		virtual bool operator!=(Block b){code != b.code;}
	protected:
		String code;
};

}

#endif 
