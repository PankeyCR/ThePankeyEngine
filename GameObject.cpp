
#ifndef GameObject_cpp
#define GameObject_cpp

#include "GameObject.h"
	
	GameObject::~GameObject(){
		if(this->childs != nullptr){
			delete this->childs;
		}
	}
	
    void GameObject::update(float tpc){
		iterate(this->childs){
			return this->childs->getPointer()->update(tpc);
		}
	}
	
    GameOn* GameObject::attach(GameOn* gmo){
		gmo->setParent(this);
		this->childs->add(gmo);
		return gmo;
	}
	
    GameOn* GameObject::attach(String id, GameOn* gmo){
		gmo->setParent(this);
		gmo->setId(id);
		this->childs->add(gmo);
		return gmo;
	}
	
    GameOn* GameObject::getChild(String id_className){
		iterate(this->childs){
			if(this->childs->getPointer()->getId() == id_className){
				return this->childs->getPointer();
			}
			if(this->childs->getPointer()->getClassName() == id_className){
				return this->childs->getPointer();
			}
		}
		return nullptr;
	}
	
    GameOn* GameObject::getChild(String id, String className){
		iterate(this->childs){
			if(this->childs->getPointer()->getId() == id &&
			   this->childs->getPointer()->getClassName() == className){
					
				return this->childs->getPointer();
			}
		}
		return nullptr;
	}
	
    GameOn* GameObject::detach(String id_className){
		iterate(this->childs){
			if(this->childs->getPointer()->getId() == id_className){
				return this->childs->removeByPos(this->childs->getIteration());
			}
			if(this->childs->getPointer()->getClassName() == id_className){
				return this->childs->removeByPos(this->childs->getIteration());
			}
		}
		return nullptr;
	}
	
    GameOn* GameObject::detach(String id, String className){
		iterate(this->childs){
			if(this->childs->getPointer()->getId() == id &&
			   this->childs->getPointer()->getClassName() == className){
					
				return this->childs->removeByPos(this->childs->getIteration());
			}
		}
		return nullptr;
	}
	
	String GameObject::getClassName(){
		return "GameObject";
	}
	
	String GameObject::toString(){
		return "GameObject";
	}

#endif 
