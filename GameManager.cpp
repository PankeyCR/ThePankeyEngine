

#ifndef GameManager_cpp
#define GameManager_cpp

#include "GameManager.h"

	GameManager::GameManager(){
		this->deleteERequest = new PrimitiveList<int>();
		this->addRequest = new PrimitiveMap<int,GameOn>();
		this->deleteRequest = new PrimitiveMap<int,String>();
		this->components = new PrimitiveMap<String,PrimitiveList<GameOn>>();
		this->gameobjects = new PrimitiveList<GameObject>();
	}
	
	GameManager::~GameManager(){
		if(this->deleteERequest != nullptr){
			delete this->deleteERequest;
		}
		if(this->addRequest != nullptr){
			delete this->addRequest;
		}
		if(this->deleteRequest != nullptr){
			delete this->deleteRequest;
		}
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
	
	void GameManager::deleteEntity(int entity){
		GameObject* obj = this->gameobjects->getByPos(entity);
		if(obj == nullptr){
			return;
		}
		List<GameOn>* objChilds = obj->getChilds();
		if(objChilds == nullptr){
			return;
		}
		for(int x = 0; x < objChilds->getPos(); x++){
			GameOn* child = objChilds->getByPos(x);
			String classnamae = child->getClassName();
			PrimitiveList<GameOn>* list = this->components->get(classnamae);
			if(list == nullptr){
				return;
			}
			list->remove(child);
		}
		this->gameobjects->removeDeleteByPos(entity);
	}
	
	void GameManager::deleteAllEntities(){
		Serial.println("deliting all entities");
		this->gameobjects->resetDelete();
		Serial.println("finish deliting all entities");
		for(int x = 0; x < components->getPos(); x++){
			List<GameOn>* childs = components->getByPos(x);
			childs->reset();
		}
	}
	
	void GameManager::deleteEntityRequest(int entity){
		deleteERequest->add(entity);
	}
	
	void GameManager::deleteAllEntitiesRequest(){
		deleteAllE = true;
	}
	
	int GameManager::getEntity(GameObject* obj){
		return obj->getId();
	}
	
	int GameManager::getEntity(String entityClassName){
		for(int x = 0; x < gameobjects->getPos(); x++){
			GameOn* child = gameobjects->getByPos(x);
			if(child->getClassName() == entityClassName){
				return x;
			}
		}
		return -1;
	}
	
	GameObject* GameManager::getGameObject(String entityClassName){
		for(int x = 0; x < gameobjects->getPos(); x++){
			GameObject* obj = gameobjects->getByPos(x);
			if(obj->getClassName() == entityClassName){
				return obj;
			}
		}
		return nullptr;
	}
	
	GameObject* GameManager::getGameObject(int entity){
		return this->gameobjects->getByPos(entity);
	}
	
	void GameManager::addComponent(int entity, GameOn* component){
		GameObject* obj = this->gameobjects->getByPos(entity);
		if(obj == nullptr){
			return;
		}
		PrimitiveList<GameOn>* list = this->components->get(component->getClassName());
		if(list == nullptr){
			list = new PrimitiveList<GameOn>(false);
			this->components->add(component->getClassName(),list);
		}
		if(!list->contain(component)){
			list->add(component);
		}
		if(!obj->getChilds()->contain(component)){
			obj->attach(component);
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
			list = new PrimitiveList<GameOn>(false);
			this->components->add(component->getClassName(),list);
			list->add(component);
		}else{
			list->add(component);
		}
	}
	
	void GameManager::addComponentRequest(int entity, GameOn* component){
		addRequest->add(entity,component);
	}
	
	void GameManager::addComponentRequest(GameObject* obj, GameOn* component){
		int index = gameobjects->getIndex(obj);
		if(index == -1){
			return;
		}
		addRequest->add(index,component);
	}
	
	bool GameManager::containComponent(String componentClassName){
		for(int xxs = 0; xxs < gameobjects->getPos(); xxs++){
			GameObject* obj = gameobjects->getByPos(xxs);
			if(obj == nullptr){
				return false;
			}
			List<GameOn>* objChilds = obj->getChilds();
			if(objChilds == nullptr){
				return false;
			}
			for(int yys = 0; yys < objChilds->getPos(); yys++){
				GameOn* child = objChilds->getByPos(yys);
				if(child == nullptr){
					return false;
				}
				if(child->getClassName() == componentClassName){
					return true;
				}
			}
		}
		return false;
	}
	
	bool GameManager::containComponent(int entity, String componentClassName){
		List<GameOn>* list = this->getComponents(entity);
		
		if(list == nullptr){
			return false;
		}
		for(int x = 0; x < list->getPos(); x++){
			if(list->getByPos(x)->getClassName() == componentClassName){
				return true;
			}
		}
		return false;
	}
	
	bool GameManager::containComponent(GameObject* obj, String componentClassName){
		if(obj == nullptr){
			return false;
		}
		List<GameOn>* list = obj->getChilds();
		
		if(list == nullptr){
			return false;
		}
		for(int x = 0; x < list->getPos(); x++){
			if(list->getByPos(x)->getClassName() == componentClassName){
				return true;
			}
		}
		return false;
	}
	
	GameOn* GameManager::getComponent(int entity, int index){
		GameObject* obj = this->gameobjects->getByPos(entity);
		if(obj == nullptr){
			return nullptr;
		}
		return obj->getChilds()->getByPos(index);
	}
	
	bool GameManager::isEmpty(){
		return gameobjects->isEmpty();
	}
	
	GameOn* GameManager::getComponent(int entity, String componentClassName){
		List<GameOn>* list = this->getComponents(entity);
		
		if(list == nullptr){
			return nullptr;
		}
		for(int x = 0; x < list->getPos(); x++){
			if(list->getByPos(x)->getClassName() == componentClassName){
				return list->getByPos(x);
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
		for(int x = 0; x < list->getPos(); x++){
			if(list->getByPos(x)->getClassName() == componentClassName){
				return list->getByPos(x);
			}
		}
		return nullptr;
	}
	
	GameOn* GameManager::getComponent(String componentClassName){
		for(int x = 0; x < gameobjects->getPos(); x++){
			for(int xc = 0; xc < gameobjects->getByPos(x)->getChilds()->getPos(); xc++){
				if(gameobjects->getByPos(x)->getChilds()->getByPos(xc)->getClassName() == componentClassName){
					return gameobjects->getByPos(x)->getChilds()->getByPos(xc);
				}
			}
		}
		return nullptr;
	}
	
	int GameManager::getEntityComponent(String componentClassName){
		for(int x = 0; x < gameobjects->getPos(); x++){
			GameObject* obj = gameobjects->getByPos(x);
			if(obj == nullptr){
				return -1;
			}
			List<GameOn>* list = obj->getChilds();
			if(list == nullptr){
				return -1;
			}
			for(int y = 0; y < list->getPos(); y++){
				GameOn* gameon = list->getByPos(y);
				if(gameon == nullptr){
					return -1;
				}
				if(gameon->getClassName() == componentClassName){
					return x;
				}
			}
		}
		return -1;
	}
	
	int GameManager::getComponentIndex(int entity, String componentClassName){
		List<GameOn>* list = this->getComponents(entity);
		
		if(list == nullptr){
			return -1;
		}
		for(int x = 0; x < list->getPos(); x++){
			if(list->getByPos(x)->getClassName() == componentClassName){
				return x;
			}
		}
		return -1;
	}
	
	int GameManager::getComponentIndex(GameObject* obj, String componentClassName){
		if(obj == nullptr){
			return -1;
		}
		List<GameOn>* list = obj->getChilds();
		
		if(list == nullptr){
			return -1;
		}
		for(int x = 0; x < list->getPos(); x++){
			if(list->getByPos(x)->getClassName() == componentClassName){
				return x;
			}
		}
		return -1;
	}
	
	int GameManager::getComponentEntity(String componentClassName){
		for(int x = 0; x < gameobjects->getPos(); x++){
			GameObject* obj = gameobjects->getByPos(x);
			List<GameOn>* list = obj->getChilds();
			for(int xs = 0; xs < list->getPos(); xs++){
				GameOn* child = list->getByPos(xs);
				if(child->getClassName() == componentClassName){
					return xs;
				}
			}
		}
		return -1;
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
		PrimitiveList<GameOn>* list = this->components->get(componentClassName);
		if(list == nullptr){
			list = new PrimitiveList<GameOn>(false);
			this->components->add(componentClassName,list);
		}
		return list;
	}
	
	void GameManager::deleteComponent(String componentClassName){
		for(int x= 0; x < gameobjects->getPos(); x++){
			GameOn* gameon = nullptr;
			GameObject* obj = this->gameobjects->getByPos(x);
			if(obj != nullptr){
				gameon = obj->detach(componentClassName);
			}
			List<GameOn>* list = this->components->get(componentClassName);
			if(list != nullptr){
				list->remove(gameon);
			}
			if(gameon == nullptr){
				return;
			}
			delete gameon;
		}
	}
	
	GameOn* GameManager::removeComponent(int entity, String componentClassName){
		GameOn* gameon = nullptr;
		GameObject* obj = this->gameobjects->getByPos(entity);
		if(obj != nullptr){
			gameon = obj->detach(componentClassName);
		}
		List<GameOn>* list = this->components->get(componentClassName);
		if(list != nullptr){
			list->remove(gameon);
		}
		return gameon;
	}
	
	GameOn* GameManager::removeComponent(GameObject* obj, String componentClassName){
		GameOn* gameon = nullptr;
		if(obj != nullptr){
			gameon = obj->detach(componentClassName);
		}
		List<GameOn>* list = this->components->get(componentClassName);
		if(list != nullptr){
			list->remove(gameon);
		}
		return gameon;
	}
	
	void GameManager::deleteComponent(int entity, String componentClassName){
		GameObject* obj = this->gameobjects->getByPos(entity);
		if(obj == nullptr){
			return;
		}
		
		GameOn* gon = obj->detach(componentClassName);
		List<GameOn>* list = this->components->get(componentClassName);
		if(list != nullptr){
			list->remove(gon);
		}
		if(gon != nullptr){
			delete gon;
		}
	}
	
	void GameManager::deleteComponent(GameObject* obj, String componentClassName){
		if(obj == nullptr){
			return;
		}
		
		GameOn* gon = obj->detach(componentClassName);
		List<GameOn>* list = this->components->get(componentClassName);
		if(list != nullptr){
			list->remove(gon);
		}
		if(gon != nullptr){
			delete gon;
		}
	}
	
	void GameManager::deleteComponentRequest(int entity, String componentClassName){
		deleteRequest->add(entity,componentClassName);
	}
	
	void GameManager::deleteComponentRequest(GameObject* obj, String componentClassName){
		int index = gameobjects->getIndex(obj);
		if(index == -1){
			return;
		}
		deleteRequest->add(index,componentClassName);
	}
	
	void GameManager::removeComponent(int entity, GameOn* component){
		GameObject* obj = this->gameobjects->getByPos(entity);
		if(obj != nullptr){
			obj->detach(component);
		}
		List<GameOn>* list = this->components->get(component->getClassName());
		if(list != nullptr){
			list->remove(component);
		}
	}
	
	void GameManager::removeComponent(GameObject* obj, GameOn* component){
		if(obj != nullptr){
			 obj->detach(component);
		}
		List<GameOn>* list = this->components->get(component->getClassName());
		if(list != nullptr){
			list->remove(component);
		}
	}
	
	void GameManager::deleteComponent(int entity, GameOn* component){
		if(component != nullptr){
			GameObject* obj = this->gameobjects->getByPos(entity);
			if(obj == nullptr){
				return;
			}
			obj->detach(component);
			List<GameOn>* list = this->components->get(component->getClassName());
			if(list != nullptr){
				list->remove(component);
			}
			delete component;
		}
	}
	
	void GameManager::deleteComponent(GameObject* obj, GameOn* component){
		if(component != nullptr){
			if(obj == nullptr){
				return;
			}
			obj->detach(component);
			List<GameOn>* list = this->components->get(component->getClassName());
			if(list != nullptr){
				list->remove(component);
			}
			delete component;
		}
	}
	
	GameOn* GameManager::removeComponentIterating(List<GameOn>* components){
		if(components != nullptr){
			GameOn* gameon = components->getPointer();
			components->remove();
			GameObject* obj = this->gameobjects->getByPos(gameon->getId());
			if(obj != nullptr){
				obj->detach(gameon);
			}
			return gameon;
		}
		return nullptr;
	}
	
	void GameManager::deleteComponentIterating(List<GameOn>* components){
		if(components != nullptr){
			GameOn* gameon = components->getPointer();
			components->remove();
			GameObject* obj = this->gameobjects->getByPos(gameon->getId());
			if(obj == nullptr){
				return;
			}
			obj->detach(gameon);
			delete gameon;
		}
	}
	
	int GameManager::getEntitySize(){
		return gameobjects->getPos();
	}
	
	int GameManager::getComponentSize(int entity){
		if(gameobjects->getByPos(entity)==nullptr){
			return -1;
		}
		return gameobjects->getByPos(entity)->getChilds()->getPos();
	}
	
	String GameManager::getClassName(){
		return "GameManager";
	}
	
	String GameManager::toString(){
		return "GameManager"+String(gameobjects->getSize());
	}
	
	bool GameManager::equal(cppObject *b){
		if(b == this){
			return true;
		}
		if(b->getClassName() == this->getClassName()){
			return true;
		}
		return false;
	}
	
	cppObject* GameManager::clone(){
		return new GameManager();
	}
	
	void GameManager::update(float tpc){
		for(int txp = 0; txp < this->addRequest->getPos(); txp++){
			this->addComponent(*this->addRequest->getKeyByPos(txp), this->addRequest->getByPos(txp));
			this->addRequest->setValueByPos(txp, nullptr);
		}
		this->addRequest->resetDelete();
		
		for(int txp = 0; txp < this->deleteRequest->getPos(); txp++){
			this->deleteComponent(*this->deleteRequest->getKeyByPos(txp), *this->deleteRequest->getByPos(txp));
		}
		this->deleteRequest->resetDelete();
		
		for(int txp = 0; txp < this->deleteERequest->getPos(); txp++){
			this->deleteEntity(*this->deleteERequest->getByPos(txp));
		}
		this->deleteERequest->resetDelete();
		
		if(deleteAllE){
			deleteAllE = false;
			this->deleteAllEntities();
		}
	}
	

#endif 
