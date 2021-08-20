
#ifndef GameObject_cpp
#define GameObject_cpp

#include "GameObject.h"
	
	ame::GameObject::GameObject(){
		this->childs = new PrimitiveList<ame::GameOn>();
	}
	
	// ame::GameObject::GameObject(const ame::GameObject& obj){
		// this->childs = new PrimitiveList<ame::GameOn>();
		// for(int x = 0; x < obj.getPosition(); x++){
			// this->childs->addLValue(*obj.getByPosition(x));
		// }
	// }
	
	ame::GameObject::~GameObject(){
		delete this->childs;
	}
	
	void ame::GameObject::setId(int id){
		this->gameId = id;
	}
	
	int ame::GameObject::getId(){
		return this->gameId;
	}
	
    void ame::GameObject::update(float tpc){
		for(int x = 0; x < this->childs->getPosition(); x++){
			this->childs->getByPosition(x)->update(tpc);
		}
	}
	
    ame::GameOn* ame::GameObject::attach(ame::GameOn* gmo){
		gmo->setParent(this);
		gmo->setId(this->getId());
		this->childs->addPointer(gmo);
		return gmo;
	}
	
    ame::GameOn* ame::GameObject::getChild(ame::cppObjectClass* cls){
		for(int x = 0; x < this->childs->getPosition(); x++){
			if(this->childs->getByPosition(x)->getClass() == cls){
				return this->childs->getByPosition(x);
			}
		}
		return nullptr;
	}
	
    ame::GameOn* ame::GameObject::detach(ame::cppObjectClass* cls){
		for(int x = 0; x < this->childs->getPosition(); x++){
			if(this->childs->getByPosition(x)->getClass() == cls){
				return this->childs->removeByPosition(x);
			}
		}
		return nullptr;
	}
	
    void ame::GameObject::detach(ame::GameOn* gon){
		this->childs->removeByPointer(gon);
	}
	
	ame::List<ame::GameOn>* ame::GameObject::getChilds(){
		return this->childs;
	}
	
	ame::cppObjectClass* ame::GameObject::getClass(){
		return ame::Class<ame::GameObject>::classType;
	}
	
	String ame::GameObject::toString(){
		return "GameObject";
	}

#endif 
