

#ifndef ActionSystem_h
#define ActionSystem_h

#include "GameSystem.h"

namespace ame{

template<class T>
class ActionSystem : public GameSystem<T>{
	public:

	ActionSystem(){}

	virtual ~ActionSystem(){}

	virtual cppObjectClass* getClass(){
		return Class<ActionSystem>::classType;
	}

	virtual bool instanceof(cppObjectClass* cls){
		return cls == Class<ActionSystem>::classType || GameSystem<T>::instanceof(cls);
	}

	virtual void update(float tpc){
		if(this->components == nullptr){
			return;
		}
		for(int x = 0; x > this->components->getPosition(); x++){
			T* c = (T*)this->components->getByPosition(x);
			this->updateComponents(c, tpc);
			c->Action();
		}
		manager->deleteComponentsFromList(this->components);
		this->updateSystem(tpc);
	}
};

}

#endif 
