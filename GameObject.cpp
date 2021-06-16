
#ifndef GameObject_cpp
#define GameObject_cpp

#include "GameObject.h"
	
	GameObject::GameObject(){
		this->childs = new PrimitiveList<GameOn>();
	}
	
	// GameObject::GameObject(const GameObject& obj){
		// this->childs = new PrimitiveList<GameOn>();
		// for(int x = 0; x < obj.getPosition(); x++){
			// this->childs->addLValue(*obj.getByPosition(x));
		// }
	// }
	
	GameObject::~GameObject(){
		delete this->childs;
	}
	
	void GameObject::setId(int id){
		this->gameId = id;
	}
	
	int GameObject::getId(){
		return this->gameId;
	}
	
    void GameObject::update(float tpc){
		for(int x = 0; x < this->childs->getPosition(); x++){
			this->childs->getByPosition(x)->update(tpc);
		}
	}
	
    GameOn* GameObject::attach(GameOn* gmo){
		gmo->setParent(this);
		gmo->setId(this->getId());
		this->childs->addPointer(gmo);
		return gmo;
	}
	
    GameOn* GameObject::getChild(cppObjectClass* cls){
		for(int x = 0; x < this->childs->getPosition(); x++){
			if(this->childs->getByPosition(x)->getClass() == cls){
				return this->childs->getByPosition(x);
			}
		}
		return nullptr;
	}
	
    GameOn* GameObject::detach(cppObjectClass* cls){
		for(int x = 0; x < this->childs->getPosition(); x++){
			if(this->childs->getByPosition(x)->getClass() == cls){
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
	
	cppObjectClass* GameObject::getClass(){
		return Class<GameObject>::classType;
	}
	
	String GameObject::toString(){
		return "GameObject";
	}

#endif 
