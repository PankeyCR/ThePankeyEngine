

#ifndef GameManager_cpp
#define GameManager_cpp

#include "GameManager.h"

	GameManager::GameManager(){
		this->deleteERequest = new PrimitiveList<GameObject>();
		this->addRequest = new PrimitiveMap<GameObject,GameOn>();
		this->deleteRequest = new PrimitiveMap<GameObject,cppObjectClass>();
		this->components = new PrimitiveMap<cppObjectClass,PrimitiveList<GameOn>>();
		this->gameobjects = new PrimitiveList<GameObject>();
	}
	
	GameManager::~GameManager(){
		delete this->deleteERequest;
		delete this->addRequest;
		delete this->deleteRequest;
		delete this->components;
		delete this->gameobjects;
	}
	
	int GameManager::createEntity(GameObject* obj){
		GameManagerLog("GameManager", "createEntity",  "println", "with parameters");
		GameManagerLog("GameManager", "createEntity",  "println", String(this->gameobjects->getPosition()));
		obj->setId(this->gameobjects->getPosition());
		this->gameobjects->addPointer(obj);
		return obj->getId();
	}
	
	GameObject* GameManager::createGameObject(GameObject* obj){
		GameManagerLog("GameManager", "createGameObject",  "println", "with parameters");
		GameManagerLog("GameManager", "createGameObject",  "println", String(this->gameobjects->getPosition()));
		obj->setId(this->gameobjects->getPosition());
		this->gameobjects->addPointer(obj);
		return obj;
	}
	
	int GameManager::createEntity(){
		GameManagerLog("GameManager", "createEntity",  "println", "no parameters");
		GameManagerLog("GameManager", "createEntity",  "println", String(this->gameobjects->getPosition()));
		GameObject* obj = new GameObject();
		obj->setId(this->gameobjects->getPosition());
		this->gameobjects->addPointer(obj);
		return obj->getId();
	}
	
	GameObject* GameManager::createGameObject(){
		GameManagerLog("GameManager", "createGameObject",  "println", "no parameters");
		GameManagerLog("GameManager", "createGameObject",  "println", String(this->gameobjects->getPosition()));
		GameObject* obj = new GameObject();
		obj->setId(this->gameobjects->getPosition());
		this->gameobjects->addPointer(obj);
		return obj;
	}
	
	void GameManager::deleteEntity(int entity){
		GameManagerLog("GameManager", "deleteEntity",  "println", String(entity));
		GameObject* obj = this->gameobjects->getByPosition(entity);
		if(obj == nullptr){
			GameManagerLog("GameManager", "deleteEntity",  "println", "obj == nullptr");
			return;
		}
		List<GameOn>* objChilds = obj->getChilds();
		if(objChilds == nullptr){
			GameManagerLog("GameManager", "deleteEntity",  "println", "objChilds == nullptr");
			return;
		}
		GameManagerLog("GameManager", "deleteEntity",  "println", "start to look for the childs on the component lists");
		for(int x = 0; x < objChilds->getPosition(); x++){
			GameOn* child = objChilds->getByPosition(x);
			cppObjectClass* classT = child->getClass();
			GameManagerLog("GameManager", "deleteEntity",  "println", String("child class name: ") + classnamae);
			PrimitiveList<GameOn>* list = this->components->getByPointer(classT);
			if(list == nullptr){
				GameManagerLog("GameManager", "deleteEntity",  "println", "list == nullptr");
				continue;
			}
			GameManagerLog("GameManager", "deleteEntity",  "println", "removing from the component list");
			list->removeByPointer(child);
		}
		GameManagerLog("GameManager", "deleteEntity",  "println", "removing-deleting from the gameobjects list");
		this->gameobjects->removeDeleteByPosition(entity);
	}
	
	void GameManager::deleteGameObject(GameObject* obj){
		GameManagerLog("GameManager", "deleteGameObject",  "println", "");
		if(!this->gameobjects->containByPointer(obj)){
			GameManagerLog("GameManager", "deleteGameObject",  "println", "gameobjects dont contains obj");
			return;
		}
		List<GameOn>* objChilds = obj->getChilds();
		if(objChilds == nullptr){
			GameManagerLog("GameManager", "deleteGameObject",  "println", "objChilds == nullptr");
			return;
		}
		GameManagerLog("GameManager", "deleteGameObject",  "println", "start to look for the childs on the component lists");
		for(int x = 0; x < objChilds->getPosition(); x++){
			GameOn* child = objChilds->getByPosition(x);
			cppObjectClass* cls = child->getClass();
			GameManagerLog("GameManager", "deleteGameObject",  "println", String("child class name: ") + classnamae);
			PrimitiveList<GameOn>* list = this->components->getByPointer(cls);
			if(list == nullptr){
				GameManagerLog("GameManager", "deleteGameObject",  "println", "list == nullptr");
				continue;
			}
			GameManagerLog("GameManager", "deleteGameObject",  "println", "removing from the component list");
			list->removeByPointer(child);
		}
		GameManagerLog("GameManager", "deleteGameObject",  "println", "removing-deleting from the gameobjects list");
		this->gameobjects->removeDeleteByPointer(obj);
	}
	
	void GameManager::deleteAllEntities(){
		GameManagerLog("GameManager", "deleteAllEntities",  "println", "");
		for(int x = 0; x < this->components->getPosition(); x++){
			List<GameOn>* childs = this->components->getByPosition(x);
			childs->reset();
		}
		this->gameobjects->resetDelete();
	}
	
	void GameManager::deleteEntityRequest(int entity){
		GameManagerLog("GameManager", "deleteEntityRequest",  "println", String(entity));
		GameObject* obj = this->gameobjects->getByPosition(entity);
		if(obj == nullptr){
			return;
		}
		deleteERequest->addPointer(obj);
	}
	
	void GameManager::deleteGameObjectRequest(GameObject* obj){
		GameManagerLog("GameManager", "deleteGameObjectRequest",  "println", "");
		if(!this->gameobjects->containByPointer(obj)){
			return;
		}
		deleteERequest->addPointer(obj);
	}
	
	void GameManager::deleteAllEntitiesRequest(){
		GameManagerLog("GameManager", "deleteAllEntitiesRequest",  "println", "");
		deleteAllE = true;
	}
	
	int GameManager::getEntity(GameObject* obj){
		GameManagerLog("GameManager", "getEntity",  "println", String(obj->getId()));
		if(gameobjects->containByPointer(obj)){
			return obj->getId();
		}
		return -1;
	}
	
	int GameManager::getEntity(cppObjectClass* cls){
		GameManagerLog("GameManager", "getEntity",  "println", entityClassName);
		for(int x = 0; x < gameobjects->getPosition(); x++){
			GameOn* child = gameobjects->getByPosition(x);
			if(child->getClass() == cls){
				return x;
			}
		}
		return -1;
	}
	
	GameObject* GameManager::getGameObject(cppObjectClass* cls){
		GameManagerLog("GameManager", "getGameObject",  "println", entityClassName);
		for(int x = 0; x < gameobjects->getPosition(); x++){
			GameObject* obj = gameobjects->getByPosition(x);
			if(obj->getClass() == cls){
				return obj;
			}
		}
		return nullptr;
	}
	
	GameObject* GameManager::getGameObject(int entity){
		GameManagerLog("GameManager", "getGameObject",  "println", String(entity));
		return this->gameobjects->getByPosition(entity);
	}
	
	int GameManager::getLastEntity(){
		GameManagerLog("GameManager", "getLastEntity",  "println", "");
		int position = this->gameobjects->getPosition();
		if(position <= 0){
			return -1;
		}
		return position-1;
	}
	
	GameObject* GameManager::getLastGameObject(){
		GameManagerLog("GameManager", "getLastGameObject",  "println", "");
		int position = this->gameobjects->getPosition();
		if(position <= 0){
			return nullptr;
		}
		return this->gameobjects->getByPosition(position-1);
	}
	
	int GameManager::getFirstEntity(){
		GameManagerLog("GameManager", "getFirstEntity",  "println", "");
		int position = this->gameobjects->getPosition();
		if(position <= 0){
			return -1;
		}
		return 0;
	}
	
	GameObject* GameManager::getFirstGameObject(){
		GameManagerLog("GameManager", "getFirstGameObject",  "println", "");
		int position = this->gameobjects->getPosition();
		if(position <= 0){
			return nullptr;
		}
		return this->gameobjects->getByPosition(0);
	}
	
	void GameManager::addEntityComponent(int entity, GameOn* component){
		GameManagerLog("GameManager", "addEntityComponent",  "println", "");
		GameObject* obj = this->gameobjects->getByPosition(entity);
		if(obj == nullptr){
			return;
		}
		PrimitiveList<GameOn>* list = this->components->getByPointer(component->getClass());
		if(list == nullptr){
			list = new PrimitiveList<GameOn>(false);
			this->components->addPointers(component->getClass(),list);
		}
		if(!list->containByPointer(component)){
			list->addPointer(component);
		}
		if(!obj->getChilds()->containByPointer(component)){
			obj->attach(component);
		}
	}
	
	void GameManager::addGameObjectComponent(GameObject* obj, GameOn* component){
		GameManagerLog("GameManager", "addGameObjectComponent",  "println", "");
		if(obj == nullptr){
			return;
		}
		if(!this->gameobjects->containByPointer(obj)){
			return;
		}
		if(obj->getChilds()->containByPointer(component)){
			return;
		}
		obj->attach(component);
		
		PrimitiveList<GameOn>* list = this->components->getByPointer(component->getClass());
		if(list == nullptr){
			list = new PrimitiveList<GameOn>(false);
			this->components->addPointers(component->getClass(),list);
			list->addPointer(component);
		}else{
			list->addPointer(component);
		}
	}
	
	void GameManager::addEntityComponentRequest(int entity, GameOn* component){
		GameManagerLog("GameManager", "addEntityComponentRequest",  "println", "");
		GameObject* obj = this->gameobjects->getByPosition(entity);
		if(obj == nullptr){
			return;
		}
		addRequest->addPointers(obj,component);
	}
	
	void GameManager::addGameObjectComponentRequest(GameObject* obj, GameOn* component){
		GameManagerLog("GameManager", "addGameObjectComponentRequest",  "println", "");
		if(!this->gameobjects->containByPointer(obj)){
			return;
		}
		addRequest->addPointers(obj,component);
	}
	
	bool GameManager::containComponent(cppObjectClass* cls){
		GameManagerLog("GameManager", "containComponent",  "println", "");
		for(int xxs = 0; xxs < gameobjects->getPosition(); xxs++){
			GameObject* obj = gameobjects->getByPosition(xxs);
			if(obj == nullptr){
				return false;
			}
			List<GameOn>* objChilds = obj->getChilds();
			if(objChilds == nullptr){
				return false;
			}
			for(int yys = 0; yys < objChilds->getPosition(); yys++){
				GameOn* child = objChilds->getByPosition(yys);
				if(child == nullptr){
					return false;
				}
				if(child->getClass() == cls){
					return true;
				}
			}
		}
		return false;
	}
	
	bool GameManager::containEntityComponent(int entity, cppObjectClass* cls){
		GameManagerLog("GameManager", "containEntityComponent",  "println", "");
		List<GameOn>* list = this->getEntityComponents(entity);
		
		if(list == nullptr){
			return false;
		}
		for(int x = 0; x < list->getPosition(); x++){
			if(list->getByPosition(x)->getClass() == cls){
				return true;
			}
		}
		return false;
	}
	
	bool GameManager::containGameObjectComponent(GameObject* obj, cppObjectClass* cls){
		GameManagerLog("GameManager", "containGameObjectComponent",  "println", "");
		if(obj == nullptr){
			return false;
		}
		List<GameOn>* list = obj->getChilds();
		
		if(list == nullptr){
			return false;
		}
		for(int x = 0; x < list->getPosition(); x++){
			if(list->getByPosition(x)->getClass() == cls){
				return true;
			}
		}
		return false;
	}
	
	GameOn* GameManager::getEntityComponent(int entity, int index){
		GameManagerLog("GameManager", "getEntityComponent",  "println", "");
		GameObject* obj = this->gameobjects->getByPosition(entity);
		if(obj == nullptr){
			return nullptr;
		}
		return obj->getChilds()->getByPosition(index);
	}
	
	bool GameManager::isEmpty(){
		GameManagerLog("GameManager", "isEmpty",  "println", "");
		return gameobjects->isEmpty();
	}
	
	GameOn* GameManager::getEntityComponent(int entity, cppObjectClass* cls){
		GameManagerLog("GameManager", "getEntityComponent",  "println", "");
		List<GameOn>* list = this->getEntityComponents(entity);
		
		if(list == nullptr){
			return nullptr;
		}
		for(int x = 0; x < list->getPosition(); x++){
			if(list->getByPosition(x)->getClass() == cls){
				return list->getByPosition(x);
			}
		}
		return nullptr;
	}
	
	GameOn* GameManager::getGameObjectComponent(GameObject* obj, cppObjectClass* cls){
		GameManagerLog("GameManager", "getGameObjectComponent",  "println", "");
		if(obj == nullptr){
			return nullptr;
		}
		List<GameOn>* list = obj->getChilds();
		
		if(list == nullptr){
			return nullptr;
		}
		for(int x = 0; x < list->getPosition(); x++){
			if(list->getByPosition(x)->getClass() == cls){
				return list->getByPosition(x);
			}
		}
		return nullptr;
	}
	
	GameOn* GameManager::getComponent(cppObjectClass* cls){
		GameManagerLog("GameManager", "getComponent",  "println", "");
		for(int x = 0; x < gameobjects->getPosition(); x++){
			for(int xc = 0; xc < gameobjects->getByPosition(x)->getChilds()->getPosition(); xc++){
				if(gameobjects->getByPosition(x)->getChilds()->getByPosition(xc)->getClass() == cls){
					return gameobjects->getByPosition(x)->getChilds()->getByPosition(xc);
				}
			}
		}
		return nullptr;
	}
	
	int GameManager::getEntityByComponent(cppObjectClass* cls){
		GameManagerLog("GameManager", "getEntityByComponent",  "println", "");
		for(int x = 0; x < gameobjects->getPosition(); x++){
			GameObject* obj = gameobjects->getByPosition(x);
			if(obj == nullptr){
				return -1;
			}
			List<GameOn>* list = obj->getChilds();
			if(list == nullptr){
				return -1;
			}
			for(int y = 0; y < list->getPosition(); y++){
				GameOn* gameon = list->getByPosition(y);
				if(gameon == nullptr){
					return -1;
				}
				if(gameon->getClass() == cls){
					return x;
				}
			}
		}
		return -1;
	}
	
	int GameManager::getEntityComponentIndex(int entity, cppObjectClass* cls){
		GameManagerLog("GameManager", "getEntityComponentIndex",  "println", "");
		List<GameOn>* list = this->getEntityComponents(entity);
		
		if(list == nullptr){
			return -1;
		}
		for(int x = 0; x < list->getPosition(); x++){
			if(list->getByPosition(x)->getClass() == cls){
				return x;
			}
		}
		return -1;
	}
	
	int GameManager::getGameObjectComponentIndex(GameObject* obj, cppObjectClass* cls){
		GameManagerLog("GameManager", "getGameObjectComponentIndex",  "println", "");
		if(obj == nullptr){
			return -1;
		}
		List<GameOn>* list = obj->getChilds();
		
		if(list == nullptr){
			return -1;
		}
		for(int x = 0; x < list->getPosition(); x++){
			if(list->getByPosition(x)->getClass() == cls){
				return x;
			}
		}
		return -1;
	}
	
	int GameManager::getComponentEntity(cppObjectClass* cls){
		GameManagerLog("GameManager", "getComponentEntity",  "println", "");
		for(int x = 0; x < gameobjects->getPosition(); x++){
			GameObject* obj = gameobjects->getByPosition(x);
			List<GameOn>* list = obj->getChilds();
			for(int xs = 0; xs < list->getPosition(); xs++){
				GameOn* child = list->getByPosition(xs);
				if(child->getClass() == cls){
					return xs;
				}
			}
		}
		return -1;
	}
	
	List<GameOn>* GameManager::getEntityComponents(int entity){
		GameManagerLog("GameManager", "getEntityComponents",  "println", "");
		GameObject* obj = this->gameobjects->getByPosition(entity);
		if(obj != nullptr){
			return obj->getChilds();
		}
		return nullptr;
	}
	
	List<GameOn>* GameManager::getGameObjectComponents(GameObject* obj){
		GameManagerLog("GameManager", "getGameObjectComponents",  "println", "");
		if(obj != nullptr){
			return obj->getChilds();
		}
		return nullptr;
	}
	
	List<GameOn>* GameManager::getComponents(cppObjectClass* cls){
		GameManagerLog("GameManager", "getComponents",  "println", "");
		PrimitiveList<GameOn>* list = this->components->getByPointer(cls);
		if(list == nullptr){
			list = new PrimitiveList<GameOn>(false);
			this->components->addPointers(cls,list);
		}
		return list;
	}
	
	void GameManager::deleteComponent(cppObjectClass* cls){
		GameManagerLog("GameManager", "deleteComponent",  "println", "");
		for(int x= 0; x < gameobjects->getPosition(); x++){
			GameOn* gameon = nullptr;
			GameObject* obj = this->gameobjects->getByPosition(x);
			if(obj != nullptr){
				gameon = obj->detach(cls);
			}
			PrimitiveList<GameOn>* list = this->components->getByPointer(cls);
			if(list != nullptr){
				list->removeByPointer(gameon);
			}
			if(gameon == nullptr){
				return;
			}
			delete gameon;
		}
	}
	
	GameOn* GameManager::removeEntityComponent(int entity, cppObjectClass* cls){
		GameManagerLog("GameManager", "removeEntityComponent",  "println", "");
		GameOn* gameon = nullptr;
		GameObject* obj = this->gameobjects->getByPosition(entity);
		if(obj != nullptr){
			gameon = obj->detach(cls);
		}
		PrimitiveList<GameOn>* list = this->components->getByPointer(cls);
		if(list != nullptr){
			list->removeByPointer(gameon);
		}
		return gameon;
	}
	
	GameOn* GameManager::removeGameObjectComponent(GameObject* obj, cppObjectClass* cls){
		GameManagerLog("GameManager", "removeGameObjectComponent",  "println", "");
		GameOn* gameon = nullptr;
		if(obj != nullptr){
			gameon = obj->detach(cls);
		}
		PrimitiveList<GameOn>* list = this->components->getByPointer(cls);
		if(list != nullptr){
			list->removeByPointer(gameon);
		}
		return gameon;
	}
	
	void GameManager::deleteEntityComponent(int entity, cppObjectClass* cls){
		GameManagerLog("GameManager", "deleteEntityComponent",  "println", "");
		GameObject* obj = this->gameobjects->getByPosition(entity);
		if(obj == nullptr){
			return;
		}
		
		GameOn* gon = obj->detach(cls);
		PrimitiveList<GameOn>* list = this->components->getByPointer(cls);
		if(list != nullptr){
			list->removeByPointer(gon);
		}
		if(gon != nullptr){
			delete gon;
		}
	}
	
	void GameManager::deleteGameObjectComponent(GameObject* obj, cppObjectClass* cls){
		GameManagerLog("GameManager", "deleteGameObjectComponent",  "println", "");
		if(obj == nullptr){
			return;
		}
		
		GameOn* gon = obj->detach(cls);
		PrimitiveList<GameOn>* list = this->components->getByPointer(cls);
		if(list != nullptr){
			list->removeByPointer(gon);
		}
		if(gon != nullptr){
			delete gon;
		}
	}
	
	void GameManager::deleteEntityComponents(int entity){
		GameManagerLog("GameManager", "deleteEntityComponents",  "println", "");
		GameObject* obj = this->gameobjects->getByPosition(entity);
		if(obj == nullptr){
			return;
		}
		
		List<GameOn>* list = obj->getChilds();
		if(list == nullptr){
			return;
		}
		PrimitiveList<cppObjectClass> classT;
		for(int x = 0; x < list->getPosition(); x++){
			GameOn* gon = list->getByPosition(x);
			classT.addPointer(gon->getClass());
		}
		for(int x = 0; x < classT.getPosition(); x++){
			cppObjectClass* cls = classT.getByPosition(x);
			PrimitiveList<GameOn>* list2 = this->components->getByPointer(cls);
			if(list2 == nullptr){
				continue;
			}
			GameOn* gon = obj->detach(cls);
			if(gon == nullptr){
				continue;
			}
			list2->removeByPointer(gon);
			delete gon;
		}
	}
	
	void GameManager::deleteGameObjectComponents(GameObject* obj){
		GameManagerLog("GameManager", "deleteGameObjectComponents",  "println", "");
		if(obj == nullptr){
			return;
		}
		
		List<GameOn>* list = obj->getChilds();
		if(list == nullptr){
			return;
		}
		PrimitiveList<cppObjectClass> classT;
		for(int x = 0; x < list->getPosition(); x++){
			GameOn* gon = list->getByPosition(x);
			classT.addPointer(gon->getClass());
		}
		for(int x = 0; x < classT.getPosition(); x++){
			cppObjectClass* cls = classT.getByPosition(x);
			PrimitiveList<GameOn>* list2 = this->components->getByPointer(cls);
			if(list2 == nullptr){
				continue;
			}
			GameOn* gon = obj->detach(cls);
			if(gon == nullptr){
				continue;
			}
			list2->removeByPointer(gon);
			delete gon;
		}
	}
	
	void GameManager::deleteEntityComponentRequest(int entity, cppObjectClass* cls){
		GameManagerLog("GameManager", "deleteEntityComponentRequest",  "println", "");
		GameObject* obj = this->gameobjects->getByPosition(entity);
		if(obj == nullptr){
			return;
		}
		deleteRequest->addPointers(obj,cls);
	}
	
	void GameManager::deleteGameObjectComponentRequest(GameObject* obj, cppObjectClass* cls){
		GameManagerLog("GameManager", "deleteGameObjectComponentRequest",  "println", "");
		if(!this->gameobjects->containByPointer(obj)){
			return;
		}
		deleteRequest->addPointers(obj,cls);
	}
	
	void GameManager::removeEntityComponent(int entity, GameOn* component){
		GameManagerLog("GameManager", "removeEntityComponent",  "println", "");
		GameObject* obj = this->gameobjects->getByPosition(entity);
		if(obj != nullptr){
			obj->detach(component);
		}
		PrimitiveList<GameOn>* list = this->components->getByPointer(component->getClass());
		if(list != nullptr){
			list->removeByPointer(component);
		}
	}
	
	void GameManager::removeGameObjectComponent(GameObject* obj, GameOn* component){
		GameManagerLog("GameManager", "removeGameObjectComponent",  "println", "");
		if(obj != nullptr){
			 obj->detach(component);
		}
		PrimitiveList<GameOn>* list = this->components->getByPointer(component->getClass());
		if(list != nullptr){
			list->removeByPointer(component);
		}
	}
	
	void GameManager::deleteEntityComponent(int entity, GameOn* component){
		GameManagerLog("GameManager", "deleteEntityComponent",  "println", "");
		if(component != nullptr){
			GameObject* obj = this->gameobjects->getByPosition(entity);
			if(obj == nullptr){
				return;
			}
			obj->detach(component);
			PrimitiveList<GameOn>* list = this->components->getByPointer(component->getClass());
			if(list != nullptr){
				list->removeByPointer(component);
			}
			delete component;
		}
	}
	
	void GameManager::deleteGameObjectComponent(GameObject* obj, GameOn* component){
		GameManagerLog("GameManager", "deleteGameObjectComponent",  "println", "");
		if(component == nullptr){
			return;
		}
		if(obj == nullptr){
			return;
		}
		if(!this->gameobjects->containByPointer(obj)){
			return;
		}
		obj->detach(component);
		PrimitiveList<GameOn>* list = this->components->getByPointer(component->getClass());
		if(list != nullptr){
			list->removeByPointer(component);
		}
		delete component;
	}
	
	GameOn* GameManager::removeComponentIterating(Iterator& i, List<GameOn>* listComponents){
		GameManagerLog("GameManager", "removeComponentIterating",  "println", "");
		if(listComponents != nullptr){
			GameOn* gameon = listComponents->getPointer(i);
			listComponents->remove(i);
			GameObject* obj = this->gameobjects->getByPosition(gameon->getId());
			if(obj != nullptr){
				obj->detach(gameon);
			}
			i.last();
			return gameon;
		}
		return nullptr;
	}
	
	void GameManager::deleteComponentIterating(Iterator& i, List<GameOn>* listComponents){
		GameManagerLog("GameManager", "deleteComponentIterating",  "println", "");
		if(listComponents != nullptr){
			GameOn* gameon = listComponents->getPointer(i);
			listComponents->remove(i);
			GameObject* obj = this->gameobjects->getByPosition(gameon->getId());
			if(obj == nullptr){
				return;
			}
			obj->detach(gameon);
			delete gameon;
			i.last();
		}
	}
	
	void GameManager::deleteComponentsFromList(PrimitiveList<GameOn>* listComponents){
		GameManagerLog("GameManager", "deleteComponentsFromList",  "println", "");
		if(listComponents == nullptr){
			return;
		}
		if(listComponents->isEmpty()){
			return;
		}
		cppObjectClass* s = this->components->getKeyByPointer(listComponents);
		if(s == nullptr){
			return;
		}
		for(int x = 0; x > this->gameobjects->getPosition(); x++){
			GameObject* obj = this->gameobjects->getByPosition(x);
			List<GameOn>* list = obj->getChilds();
			for(int x = 0; x < list->getPosition(); x++){
				GameOn* gameon = list->getByPosition(x);
				if(gameon->getClass() == s){
					list->removeDeleteByPosition(x);
					x--;
				}
			}
		}
		listComponents->reset();
	}
	
	int GameManager::getEntitySize(){
		GameManagerLog("GameManager", "getEntitySize",  "println", "");
		return gameobjects->getPosition();
	}
	
	int GameManager::getComponentSize(int entity){
		GameManagerLog("GameManager", "getComponentSize",  "println", "");
		if(gameobjects->getByPosition(entity)==nullptr){
			return -1;
		}
		return gameobjects->getByPosition(entity)->getChilds()->getPosition();
	}
	
	void GameManager::rearrange(){
		GameManagerLog("GameManager", "rearrange",  "println", "");
		for(int x = 0; x < gameobjects->getPosition(); x++){
			GameOn* gameon = gameobjects->getByPosition(x);
			gameon->setId(x);
		}
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
		if(b->getClass() == this->getClass()){
			return true;
		}
		return false;
	}
	
	cppObject* GameManager::clone(){
		return new GameManager();
	}
	
	void GameManager::update(float tpc){
		// Serial.println("start gamemanager update");
		for(int txp = 0; txp < this->addRequest->getPosition(); txp++){
			GameManagerLog("GameManager", "update",  "println", "addRequest");
			this->addGameObjectComponent(this->addRequest->getKeyByPosition(txp), this->addRequest->getByPosition(txp));
		}
		this->addRequest->reset();
		
		for(int txp = 0; txp < this->deleteRequest->getPosition(); txp++){
			GameManagerLog("GameManager", "update",  "println", "deleteRequest");
			this->deleteGameObjectComponent(this->deleteRequest->getKeyByPosition(txp), this->deleteRequest->getByPosition(txp));
		}
		this->deleteRequest->resetDeleteValue();
		
		for(int txp = 0; txp < this->deleteERequest->getPosition(); txp++){
			GameManagerLog("GameManager", "update",  "println", "deleteERequest");
			this->deleteGameObject(this->deleteERequest->getByPosition(txp));
		}
		this->deleteERequest->reset();
		
		if(deleteAllE){
			GameManagerLog("GameManager", "update",  "println", "deleteAllE");
			deleteAllE = false;
			this->deleteAllEntities();
		}
		// Serial.println("end gamemanager update");
	}
	

#endif 
