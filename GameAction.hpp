
#ifndef GameAction_hpp
#define GameAction_hpp
#define GameAction_AVAILABLE

#include "GameOn.hpp"

namespace pankey{

class GameAction : public GameOn{
    public:
		virtual ~GameAction(){}
	
		virtual void Action(){}
};

}

#endif