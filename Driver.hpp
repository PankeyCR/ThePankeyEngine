
#include "ame_Level.hpp"

#if defined(ame_untilLevel_7)

#ifndef Driver_hpp
#define Driver_hpp

namespace ame{

class Driver{
    public:
		Driver(){}
		virtual ~Driver(){}
		
		virtual void initialize(){}
		
		virtual void update(){}
};

}

#endif 

#endif 
