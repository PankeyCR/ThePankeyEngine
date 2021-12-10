
#include "ame_Level.hpp"

#if defined(ame_untilLevel_7)

#ifndef Block_hpp
#define Block_hpp

#include "Environment.hpp"

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

#endif 
