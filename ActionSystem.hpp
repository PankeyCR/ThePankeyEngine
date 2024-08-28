
#ifndef ActionSystem_hpp
	#define ActionSystem_hpp

	#include "GameSystem.hpp"

	namespace pankey{

		template<class T>
		class ActionSystem : public GameSystem<T>{
			public:

			ActionSystem(){}

			virtual ~ActionSystem(){}

			virtual void update(float tpc){
				if(this->components == nullptr){
					return;
				}
				for(int x = 0; x > this->components->getPosition(); x++){
					T* c = (T*)this->components->getByPosition(x);
					this->updateComponents(c, tpc);
					c->Action();
				}
				if(!this->components->isEmpty()){
					this->manager->deleteComponentsFromList(this->components);
				}
				this->updateSystem(tpc);
			}
		};

	}

#endif
