

#ifndef GameManager_cpp
#define GameManager_cpp

#include "GameManager.h"

	GameManager::GameManager(){
		this->deleteERequest = new PrimitiveList<GameObject>();
		this->addRequest = new PrimitiveMap<GameObject,GameOn>();
		this->deleteRequest = new PrimitiveMap<GameObject,String>();
		this->components = new PrimitiveMap<String,PrimitiveList<GameOn>>();
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
		obj->setId(this->gameobjects->getPosition());
		this->gameobjects->addPointer(obj);
		return obj->getId();
	}
	
	GameObject* GameManager::createGameObject(GameObject* obj){
		obj->setId(this->gameobjects->getPosition());
		this->gameobjects->addPointer(obj);
		return obj;
	}
	
	int GameManager::createEntity(){
		GameObject* obj = new GameObject();
		obj->setId(this->gameobjects->getPosition());
		this->gameobjects->addPointer(obj);
		return obj->getId();
	}
	
	GameObject* GameManager::createGameObject(){
		GameObject* obj = new GameObject();
		obj->setId(this->gameobjects->getPosition());
		this->gameobjects->addPointer(obj);
		return obj;
	}
	
	void GameManager::deleteEntity(int entity){
		GameObject* obj = this->gameobjects->getByPosition(entity);
		if(obj == nullptr){
			return;
		}
		List<GameOn>* objChilds = obj->getChilds();
		if(objChilds == nullptr){
			return;
		}
		for(int x = 0; x < objChilds->getPosition(); x++){
			GameOn* child = objChilds->getByPosition(x);
			String classnamae = child->getClassName();
			PrimitiveList<GameOn>* list = this->components->getByLValue(classnamae);
			if(list == nullptr){
				continue;
			}
			list->removeByPointer(child);
		}
		this->gameobjects->removeDeleteByPosition(entity);
	}
	
	void GameManager::deleteGameObject(GameObject* obj){
		// Serial.println("start deleteGameObject");
		if(!this->gameobjects->containByPointer(obj)){
			return;
		}
		// Serial.println("deleteGameObject 1");
		List<GameOn>* objChilds = obj->getChilds();
		if(objChilds == nullptr){
			return;
		}
		// Serial.println("deleteGameObject 2");
		for(int x = 0; x < objChilds->getPosition(); x++){
			GameOn* child = objChilds->getByPosition(x);
			String classnamae = child->getClassName();
			PrimitiveList<GameOn>* list = this->components->getByLValue(classnamae);
			if(list == nullptr){
				continue;
			}
			// for(int lc = 0; lc < list->getPosition(); lc++){
				
			// }
			// Serial.println("deleteGameObject 3");
			list->removeByPointer(child);
			// Serial.println(list->getPosition());
		}
		// Serial.println("deleteGameObject 4");
		this->gameobjects->removeDeleteByPointer(obj);
		// Serial.println(this->gameobjects->getPosition());
		// Serial.println(this->components->getPosition());
		// Serial.println(" end deleteGameObject");
	}
	
	void GameManager::deleteAllEntities(){
		for(int x = 0; x < this->components->getPosition(); x++){
			List<GameOn>* childs = this->components->getByPosition(x);
			childs->reset();
		}
		this->gameobjects->resetDelete();
	}
	
	void GameManager::deleteEntityRequest(int entity){
		GameObject* obj = this->gameobjects->getByPosition(entity);
		if(obj == nullptr){
			return;
		}
		deleteERequest->addPointer(obj);
	}
	
	void GameManager::deleteGameObjectRequest(GameObject* obj){
		if(!this->gameobjects->containByPointer(obj)){
			return;
		}
		deleteERequest->addPointer(obj);
	}
	
	void GameManager::deleteAllEntitiesRequest(){
		deleteAllE = true;
	}
	
	int GameManager::getEntity(GameObject* obj){
		if(gameobjects->containByPointer(obj)){
			return obj->getId();
		}
		return -1;
	}
	
	int GameManager::getEntity(String entityClassName){
		for(int x = 0; x < gameobjects->getPosition(); x++){
			GameOn* child = gameobjects->getByPosition(x);
			if(child->getClassName() == entityClassName){
				return x;
			}
		}
		return -1;
	}
	
	GameObject* GameManager::getGameObject(String entityClassName){
		for(int x = 0; x < gameobjects->getPosition(); x++){
			GameObject* obj = gameobjects->getByPosition(x);
			if(obj->getClassName() == entityClassName){
				return obj;
			}
		}
		return nullptr;
	}
	
	GameObject* GameManager::getGameObject(int entity){
		return this->gameobjects->getByPosition(entity);
	}
	
	void GameManager::addEntityComponent(int entity, GameOn* component){
		GameObject* obj = this->gameobjects->getByPosition(entity);
		if(obj == nullptr){
			return;
		}
		PrimitiveList<GameOn>* list = this->components->getByLValue(component->getClassName());
		if(list == nullptr){
			list = new PrimitiveList<GameOn>(false);
			this->components->addPointer(component->getClassName(),list);
		}
		if(!list->containByPointer(component)){
			list->addPointer(component);
		}
		if(!obj->getChilds()->containByPointer(component)){
			obj->attach(component);
		}
	}
	
	void GameManager::addGameObjectComponent(GameObject* obj, GameOn* component){
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
		
		PrimitiveList<GameOn>* list = this->components->getByLValue(component->getClassName());
		if(list == nullptr){
			list = new PrimitiveList<GameOn>(false);
			this->components->addPointer(component->getClassName(),list);
			list->addPointer(component);
		}else{
			list->addPointer(component);
		}
	}
	
	void GameManager::addEntityComponentRequest(int entity, GameOn* component){
		GameObject* obj = this->gameobjects->getByPosition(entity);
		if(obj == nullptr){
			return;
		}
		addRequest->addPointers(obj,component);
	}
	
	void GameManager::addGameObjectComponentRequest(GameObject* obj, GameOn* component){
		if(!this->gameobjects->containByPointer(obj)){
			return;
		}
		addRequest->addPointers(obj,component);
	}
	
	bool GameManager::containComponent(String componentClassName){
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
				if(child->getClassName() == componentClassName){
					return true;
				}
			}
		}
		return false;
	}
	
	bool GameManager::containEntityComponent(int entity, String componentClassName){
		List<GameOn>* list = this->getEntityComponents(entity);
		
		if(list == nullptr){
			return false;
		}
		for(int x = 0; x < list->getPosition(); x++){
			if(list->getByPosition(x)->getClassName() == componentClassName){
				return true;
			}
		}
		return false;
	}
	
	bool GameManager::containGameObjectComponent(GameObject* obj, String componentClassName){
		if(obj == nullptr){
			return false;
		}
		List<GameOn>* list = obj->getChilds();
		
		if(list == nullptr){
			return false;
		}
		for(int x = 0; x < list->getPosition(); x++){
			if(list->getByPosition(x)->getClassName() == componentClassName){
				return true;
			}
		}
		return false;
	}
	
	GameOn* GameManager::getEntityComponent(int entity, int index){
		GameObject* obj = this->gameobjects->getByPosition(entity);
		if(obj == nullptr){
			return nullptr;
		}
		return obj->getChilds()->getByPosition(index);
	}
	
	bool GameManager::isEmpty(){
		return gameobjects->isEmpty();
	}
	
	GameOn* GameManager::getEntityComponent(int entity, String componentClassName){
		List<GameOn>* list = this->getEntityComponents(entity);
		
		if(list == nullptr){
			return nullptr;
		}
		for(int x = 0; x < list->getPosition(); x++){
			if(list->getByPosition(x)->getClassName() == componentClassName){
				return list->getByPosition(x);
			}
		}
		return nullptr;
	}
	
	GameOn* GameManager::getGameObjectComponent(GameObject* obj, String componentClassName){
		if(obj == nullptr){
			return nullptr;
		}
		List<GameOn>* list = obj->getChilds();
		
		if(list == nullptr){
			return nullptr;
		}
		for(int x = 0; x < list->getPosition(); x++){
			if(list->getByPosition(x)->getClassName() == componentClassName){
				return list->getByPosition(x);
			}
		}
		return nullptr;
	}
	
	GameOn* GameManager::getComponent(String componentClassName){
		for(int x = 0; x < gameobjects->getPosition(); x++){
			for(int xc = 0; xc < gameobjects->getByPosition(x)->getChilds()->getPosition(); xc++){
				if(gameobjects->getByPosition(x)->getChilds()->getByPosition(xc)->getClassName() == componentClassName){
					return gameobjects->getByPosition(x)->getChilds()->getByPosition(xc);
				}
			}
		}
		return nullptr;
	}
	
	int GameManager::getEntityByComponent(String componentClassName){
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
				if(gameon->getClassName() == componentClassName){
					return x;
				}
			}
		}
		return -1;
	}
	
	int GameManager::getEntityComponentIndex(int entity, String componentClassName){
		List<GameOn>* list = this->getEntityComponents(entity);
		
		if(list == nullptr){
			return -1;
		}
		for(int x = 0; x < list->getPosition(); x++){
			if(list->getByPosition(x)->getClassName() == componentClassName){
				return x;
			}
		}
		return -1;
	}
	
	int GameManager::getGameObjectComponentIndex(GameObject* obj, String componentClassName){
		if(obj == nullptr){
			return -1;
		}
		List<GameOn>* list = obj->getChilds();
		
		if(list == nullptr){
			return -1;
		}
		for(int x = 0; x < list->getPosition(); x++){
			if(list->getByPosition(x)->getClassName() == componentClassName){
				return x;
			}
		}
		return -1;
	}
	
	int GameManager::getComponentEntity(String componentClassName){
		for(int x = 0; x < gameobjects->getPosition(); x++){
			GameObject* obj = gameobjects->getByPosition(x);
			List<GameOn>* list = obj->getChilds();
			for(int xs = 0; xs < list->getPosition(); xs++){
				GameOn* child = list->getByPosition(xs);
				if(child->getClassName() == componentClassName){
					return xs;
				}
			}
		}
		return -1;
	}
	
	List<GameOn>* GameManager::getEntityComponents(int entity){
		GameObject* obj = this->gameobjects->getByPosition(entity);
		if(obj != nullptr){
			return obj->getChilds();
		}
		return nullptr;
	}
	
	List<GameOn>* GameManager::getGameObjectComponents(GameObject* obj){
		if(obj != nullptr){
			return obj->getChilds();
		}
		return nullptr;
	}
	
	List<GameOn>* GameManager::getComponents(String componentClassName){
		PrimitiveList<GameOn>* list = this->components->getByLValue(componentClassName);
		if(list == nullptr){
			list = new PrimitiveList<GameOn>(false);
			this->components->addPointer(componentClassName,list);
		}
		return list;
	}
	
	void GameManager::deleteComponent(String componentClassName){
		for(int x= 0; x < gameobjects->getPosition(); x++){
			GameOn* gameon = nullptr;
			GameObject* obj = this->gameobjects->getByPosition(x);
			if(obj != nullptr){
				gameon = obj->detach(componentClassName);
			}
			PrimitiveList<GameOn>* list = this->components->getByLValue(componentClassName);
			if(list != nullptr){
				list->removeByPointer(gameon);
			}
			if(gameon == nullptr){
				return;
			}
			delete gameon;
		}
	}
	
	GameOn* GameManager::removeEntityComponent(int entity, String componentClassName){
		GameOn* gameon = nullptr;
		GameObject* obj = this->gameobjects->getByPosition(entity);
		if(obj != nullptr){
			gameon = obj->detach(componentClassName);
		}
		PrimitiveList<GameOn>* list = this->components->getByLValue(componentClassName);
		if(list != nullptr){
			list->removeByPointer(gameon);
		}
		return gameon;
	}
	
	GameOn* GameManager::removeGameObjectComponent(GameObject* obj, String componentClassName){
		GameOn* gameon = nullptr;
		if(obj != nullptr){
			gameon = obj->detach(componentClassName);
		}
		PrimitiveList<GameOn>* list = this->components->getByLValue(componentClassName);
		if(list != nullptr){
			list->removeByPointer(gameon);
		}
		return gameon;
	}
	
	void GameManager::deleteEntityComponent(int entity, String componentClassName){
		GameObject* obj = this->gameobjects->getByPosition(entity);
		if(obj == nullptr){
			return;
		}
		
		GameOn* gon = obj->detach(componentClassName);
		PrimitiveList<GameOn>* list = this->components->getByLValue(componentClassName);
		if(list != nullptr){
			list->removeByPointer(gon);
		}
		if(gon != nullptr){
			delete gon;
		}
	}
	
	void GameManager::deleteGameObjectComponent(GameObject* obj, String componentClassName){
		if(obj == nullptr){
			return;
		}
		
		GameOn* gon = obj->detach(componentClassName);
		PrimitiveList<GameOn>* list = this->components->getByLValue(componentClassName);
		if(list != nullptr){
			list->removeByPointer(gon);
		}
		if(gon != nullptr){
			delete gon;
		}
	}
	
	void GameManager::deleteEntityComponentRequest(int entity, String componentClassName){
		GameObject* obj = this->gameobjects->getByPosition(entity);
		if(obj == nullptr){
			return;
		}
		deleteRequest->addPointers(obj,new String(componentClassName));
	}
	
	void GameManager::deleteGameObjectComponentRequest(GameObject* obj, String componentClassName){
		if(!this->gameobjects->containByPointer(obj)){
			return;
		}
		deleteRequest->addPointers(obj,new String(componentClassName));
	}
	
	void GameManager::removeEntityComponent(int entity, GameOn* component){
		GameObject* obj = this->gameobjects->getByPosition(entity);
		if(obj != nullptr){
			obj->detach(component);
		}
		PrimitiveList<GameOn>* list = this->components->getByLValue(component->getClassName());
		if(list != nullptr){
			list->removeByPointer(component);
		}
	}
	
	void GameManager::removeGameObjectComponent(GameObject* obj, GameOn* component){
		if(obj != nullptr){
			 obj->detach(component);
		}
		PrimitiveList<GameOn>* list = this->components->getByLValue(component->getClassName());
		if(list != nullptr){
			list->removeByPointer(component);
		}
	}
	
	void GameManager::deleteEntityComponent(int entity, GameOn* component){
		if(component != nullptr){
			GameObject* obj = this->gameobjects->getByPosition(entity);
			if(obj == nullptr){
				return;
			}
			obj->detach(component);
			PrimitiveList<GameOn>* list = this->components->getByLValue(component->getClassName());
			if(list != nullptr){
				list->removeByPointer(component);
			}
			delete component;
		}
	}
	
	void GameManager::deleteGameObjectComponent(GameObject* obj, GameOn* component){
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
		PrimitiveList<GameOn>* list = this->components->getByLValue(component->getClassName());
		if(list != nullptr){
			list->removeByPointer(component);
		}
		delete component;
	}
	
	GameOn* GameManager::removeComponentIterating(Iterator& i, List<GameOn>* listComponents){
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
		if(listComponents == nullptr){
			return;
		}
		if(listComponents->isEmpty()){
			return;
		}
		String* s = this->components->getKeyByPointer(listComponents);
		if(s == nullptr){
			return;
		}
		for(int x = 0; x > this->gameobjects->getPosition(); x++){
			GameObject* obj = this->gameobjects->getByPosition(x);
			List<GameOn>* list = obj->getChilds();
			for(Iterator i : *list){
				GameOn* gameon = list->getPointer(i);
				if(gameon->getClassName() == *s){
					list->removeDelete(i);
				}
			}
		}
		listComponents->reset();
	}
	
	int GameManager::getEntitySize(){
		return gameobjects->getPosition();
	}
	
	int GameManager::getComponentSize(int entity){
		if(gameobjects->getByPosition(entity)==nullptr){
			return -1;
		}
		return gameobjects->getByPosition(entity)->getChilds()->getPosition();
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
		// Serial.println("start gamemanager update");
		for(int txp = 0; txp < this->addRequest->getPosition(); txp++){
			this->addGameObjectComponent(this->addRequest->getKeyByPosition(txp), this->addRequest->getByPosition(txp));
		}
		this->addRequest->reset();
		
		for(int txp = 0; txp < this->deleteRequest->getPosition(); txp++){
			this->deleteGameObjectComponent(this->deleteRequest->getKeyByPosition(txp), *this->deleteRequest->getByPosition(txp));
		}
		this->deleteRequest->resetDeleteValue();
		
		for(int txp = 0; txp < this->deleteERequest->getPosition(); txp++){
			this->deleteGameObject(this->deleteERequest->getByPosition(txp));
		}
		this->deleteERequest->reset();
		
		if(deleteAllE){
			deleteAllE = false;
			this->deleteAllEntities();
		}
		// Serial.println("end gamemanager update");
	}
	

#endif 
