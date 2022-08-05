
#include "ame_Enviroment.hpp"

#if defined(DISABLE_GameBuilder)
	#define GameBuilder_hpp
#endif

#ifndef GameBuilder_hpp
#define GameBuilder_hpp
#define GameBuilder_AVAILABLE

#ifndef ame_Enviroment_Defined

#endif

#ifdef ame_Windows

#endif

#ifdef ame_ArduinoIDE
	#include "Arduino.h"
#endif

namespace ame{

template <class Building>
class GameBuilder {
	public:
		virtual Building* build();
    
	private:
};

}

#endif