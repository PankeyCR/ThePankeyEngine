
#include "ame_Level.hpp"

#if defined(ame_untilLevel_7)

#ifndef IFBlock_hpp
#define IFBlock_hpp

#include "Environment.hpp"

namespace ame{

class IFBlock{
    public:
		IFBlock(){}
		virtual ~IFBlock(){}
		
		virtual IFBlock* run(Environment* e){
			Block* b = nullptr;
			if(e->containBoolean(code)){
				b = ifB_m;
			}else{
				b = elseB_m;
			}
			for(int x = 0; b != nullptr; x++){
				b = b->run(e);
			}
			return nullptr;
		}
		virtual void setIFBlock(Block* b){
			ifB_m = b;
		}
		virtual void setIFBlock(Block* b){
			elseB_m = b;
		}
	protected:
		Block* ifB_m = nullptr;
		Block* elseB_m = nullptr;
};

}

#endif 

#endif 
