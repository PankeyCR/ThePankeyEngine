
#ifndef GameObject_cpp
#define GameObject_cpp

#include "GameObject.h"
	
	GameObject::GameObject(){
		this->childs = new PrimitiveList<GameOn>();
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
		for(int x = 0; x < this->childs->getPos(); x++){
			if(this->childs->getByPos(x)->getClassName() == className){
				return this->childs->getByPos(x);
			}
		}
		return nullptr;
	}
	
    GameOn* GameObject::detach(String className){
		for(int x = 0; x < this->childs->getPos(); x++){
			if(this->childs->getByPos(x)->getClassName() == className){
				return this->childs->removeByPos(x);
			}
		}
		return nullptr;
	}
	
    void GameObject::detach(GameOn* gameon){
		this->childs->remove(gameon);
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
