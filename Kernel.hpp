
#include "ame_Level.hpp"

#if defined(ame_untilLevel_7)

#ifndef Kernel_hpp
#define Kernel_hpp

#include "Note.hpp"

namespace ame{
	
class OS;

class Kernel{
    public:
		Kernel(){}
		virtual ~Kernel(){}
		
		void setOS(OS* m){
			os = m;
		}
		
		virtual void run(Note cmd){
		}
		
		virtual void initialize(){}
		
		virtual void update(){}
	protected:
		OS* os = nullptr;
};

}

#endif 

#endif 
