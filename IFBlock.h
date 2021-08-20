

#ifndef IFBlock_h
#define IFBlock_h

#include "Environment.h"

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
