

#ifndef MindSystem_h
#define MindSystem_h

#include "GameSystem.h"

namespace ame{

template<class T>
class MindSystem : public GameSystem<T>{
	public:

	MindSystem(){}

	virtual ~MindSystem(){}

	virtual cppObjectClass* getClass(){
		return Class<MindSystem>::classType;
	}

	virtual bool instanceof(cppObjectClass* cls){
		return name == Class<MindSystem>::classType || GameSystem<T>::instanceof(cls);
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
