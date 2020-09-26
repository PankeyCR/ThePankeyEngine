
#ifndef GameObject_cpp
#define GameObject_cpp

#include "GameObject.h"
	
	GameObject::GameObject(){
		this->childs = new LinkedList<GameOn>();
	}
	
	GameObject::~GameObject(){
		if(this->childs != nullptr){
			delete this->childs;
			this->childs = nullptr;
		}
	}
	
	void GameObject::setId(int id){
		this->gameId = id;
	}
	
	int GameObject::getId(){
		return this->gameId;
	}
	
    void GameObject::update(float tpc){
		iterate(this->childs){
			this->childs->getPointer()->update(tpc);
		}
	}
	
    GameOn* GameObject::attach(GameOn* gmo){
		gmo->setParent(this);
		gmo->setId(this->getId());
		this->childs->add(gmo);
		return gmo;
	}
	
    GameOn* GameObject::getChild(String className){
		iterate(this->childs){
			if(this->childs->getPointer()->getClassName() == className){
				return this->childs->getPointer();
			}
		}
		return nullptr;
	}
	
    GameOn* GameObject::detach(String className){
		iterate(this->childs){
			if(this->childs->getPointer()->getClassName() == className){
				return this->childs->removeByPos(this->childs->getIteration());
			}
		}
		return nullptr;
	}
	
	List<GameOn>* GameObject::getChilds(){
		return this->childs;
	}
	
	String GameObject::getClassName(){
		return "GameObject";
	}
	
	String GameObject::toString(){
		return "GameObject";
	}

#endif 
