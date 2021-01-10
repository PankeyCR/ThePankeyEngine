

#ifndef MindSystem_h
#define MindSystem_h

#include "GameSystem.h"

template<class T>
class MindSystem : public GameSystem<T>{
	public:

	MindSystem(){}

	virtual ~MindSystem(){}

	virtual String getClassName(){
		return "MindSystem";
	}

	virtual bool instanceof(String name){
		return name == "MindSystem" || GameSystem<T>::instanceof(name);
	}

	virtual void update(float tpc){
		if(this->components == nullptr){
			return;
		}
		for(Iterator i : *this->components){
			T* c = (T*)this->components->getByPosition(x);
			this->updateComponents(c, tpc);
			if(c->doneThinking()){
				manager->deleteComponentIterating(i);
			}
		}
		this->updateSystem(tpc);
	}
};

#endif 
