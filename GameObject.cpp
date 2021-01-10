
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
		for(Iterator i : *this->childs){
			this->childs->getPointer(i)->update(tpc);
		}
	}
	
    GameOn* GameObject::attach(GameOn* gmo){
		gmo->setParent(this);
		gmo->setId(this->getId());
		this->childs->addPointer(gmo);
		return gmo;
	}
	
    GameOn* GameObject::getChild(String className){
		for(int x = 0; x < this->childs->getPosition(); x++){
			if(this->childs->getByPosition(x)->getClassName() == className){
				return this->childs->getByPosition(x);
			}
		}
		return nullptr;
	}
	
    GameOn* GameObject::detach(String className){
		for(int x = 0; x < this->childs->getPosition(); x++){
			if(this->childs->getByPosition(x)->getClassName() == className){
				return this->childs->removeByPosition(x);
			}
		}
		return nullptr;
	}
	
    void GameObject::detach(GameOn* gameon){
		this->childs->removeByPointer(gameon);
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
