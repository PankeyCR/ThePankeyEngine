
#ifndef ActionComponent_hpp
	#define ActionComponent_hpp

	#include "GameOn.hpp"

	namespace pankey{

		class ActionComponent : public GameOn{
			public:
				virtual ~ActionComponent(){}
			
				virtual void Action(){}
		};

	}

#endif