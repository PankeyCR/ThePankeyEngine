
#include "ame_Level.hpp"

#if defined(ame_untilLevel_7)

#ifndef GameBuilder_hpp
#define GameBuilder_hpp

namespace ame{

template <class Building>
class GameBuilder {
	public:
		virtual Building* build();
    
	private:
};

}

#endif

#endif
