

#ifndef GameManager_cpp
#define GameManager_cpp

#include "GameManager.h"

	GameManager::GameManager(){
		this->components = new PrimitiveMap<String,LinkedList<GameOn>>();
		this->gameobjects = new LinkedList<GameObject>();
	}
	
	GameManager::~GameManager(){
		if(this->components != nullptr){
			delete this->components;
		}
		if(this->gameobjects != nullptr){
			delete this->gameobjects;
		}
	}
	
	int GameManager::createEntity(GameObject* obj){
		obj->setId(this->gameobjects->getPos());
		this->gameobjects->add(obj);
		return obj->getId();
	}
	
	GameObject* GameManager::createGameObject(GameObject* obj){
		obj->setId(this->gameobjects->getPos());
		this->gameobjects->add(obj);
		return obj;
	}
	
	int GameManager::createEntity(){
		GameObject* obj = new GameObject();
		obj->setId(this->gameobjects->getPos());
		this->gameobjects->add(obj);
		return obj->getId();
	}
	
	GameObject* GameManager::createGameObject(){
		GameObject* obj = new GameObject();
		obj->setId(this->gameobjects->getPos());
		this->gameobjects->add(obj);
		return obj;
	}
	
	int GameManager::getEntity(GameObject* obj){
		return obj->getId();
	}
	
	GameObject* GameManager::getGameObject(int entity){
		return this->gameobjects->getByPos(entity);
	}
	
	void GameManager::addComponent(int entity, GameOn* component){
		GameObject* obj = this->gameobjects->getByPos(entity);
		if(obj == nullptr){
			return;
		}
		if(obj->getChilds()->contain(component)){
			return;
		}
		obj->attach(component);
		
		LinkedList<GameOn>* list = this->components->get(component->getClassName());
		if(list == nullptr){
			list = new LinkedList<GameOn>(false);
			this->components->add(component->getClassName(),list);
			list->add(component);
		}else{
			list->add(component);
		}
	}
	
	void GameManager::addComponent(GameObject* obj, GameOn* component){
		if(obj == nullptr){
			return;
		}
		if(obj->getChilds()->contain(component)){
			return;
		}
		obj->attach(component);
		
		List<GameOn>* list = this->components->get(component->getClassName());
		if(list == nullptr){
			list = new LinkedList<GameOn>(false);
			this->components->add(component->getClassName(),list);
			list->add(component);
		}else{
			list->add(component);
		}
	}
	
	bool GameManager::containComponents(int entity, String componentClassName){
		List<GameOn>* list = this->getComponents(entity);
		
		if(list == nullptr){
			return false;
		}
		iterate(list){
			if(list->getPointer()->getClassName() == componentClassName){
				return true;
			}
		}
		return false;
	}
	
	bool GameManager::containComponents(GameObject* obj, String componentClassName){
		if(obj == nullptr){
			return false;
		}
		List<GameOn>* list = obj->getChilds();
		
		if(list == nullptr){
			return false;
		}
		iterate(list){
			if(list->getPointer()->getClassName() == componentClassName){
				return true;
			}
		}
		return false;
	}
	
	GameOn* GameManager::getComponent(int entity, String componentClassName){
		List<GameOn>* list = this->getComponents(entity);
		
		if(list == nullptr){
			return nullptr;
		}
		iterate(list){
			if(list->getPointer()->getClassName() == componentClassName){
				return list->getPointer();
			}
		}
		return nullptr;
	}
	
	GameOn* GameManager::getComponent(GameObject* obj, String componentClassName){
		if(obj == nullptr){
			return nullptr;
		}
		List<GameOn>* list = obj->getChilds();
		
		if(list == nullptr){
			return nullptr;
		}
		iterate(list){
			if(list->getPointer()->getClassName() == componentClassName){
				return list->getPointer();
			}
		}
		return nullptr;
	}
	
	List<GameOn>* GameManager::getComponents(int entity){
		GameObject* obj = this->gameobjects->getByPos(entity);
		if(obj != nullptr){
			return obj->getChilds();
		}
		return nullptr;
	}
	
	List<GameOn>* GameManager::getComponents(GameObject* obj){
		if(obj != nullptr){
			return obj->getChilds();
		}
		return nullptr;
	}
	
	List<GameOn>* GameManager::getComponents(String componentClassName){
		List<GameOn>* list = this->components->get(componentClassName);
		if(list == nullptr){
			list = new LinkedList<GameOn>(false);
			this->components->add(componentClassName,list);
		}
		return list;
	}
	
	GameOn* GameManager::removeComponent(int entity, String componentClassName){
		GameObject* obj = this->gameobjects->getByPos(entity);
		if(obj == nullptr){
			return nullptr;
		}
		
		return obj->detach(componentClassName);
	}
	
	GameOn* GameManager::removeComponent(GameObject* obj, String componentClassName){
		if(obj == nullptr){
			return nullptr;
		}
		
		return obj->detach(componentClassName);
	}
	
	void GameManager::deleteComponent(int entity, String componentClassName){
		GameObject* obj = this->gameobjects->getByPos(entity);
		if(obj == nullptr){
			return;
		}
		
		GameOn* gon = obj->detach(componentClassName);
		if(gon != nullptr){
			delete gon;
		}
		
	}
	
	void GameManager::deleteComponent(GameObject* obj, String componentClassName){
		if(obj == nullptr){
			return;
		}
		
		GameOn* gon = obj->detach(componentClassName);
		if(gon != nullptr){
			delete gon;
		}
	}
	

#endif 
