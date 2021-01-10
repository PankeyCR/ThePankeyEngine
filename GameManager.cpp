

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
				return;
			}
			list->removeByPointer(child);
		}
		this->gameobjects->removeDeleteByPosition(entity);
	}
	
	void GameManager::deleteAllEntities(){
		this->gameobjects->resetDelete();
		for(int x = 0; x < components->getPosition(); x++){
			List<GameOn>* childs = components->getByPosition(x);
			childs->reset();
		}
	}
	
	void GameManager::deleteEntityRequest(int entity){
		deleteERequest->addLValue(entity);
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
	
	void GameManager::addComponent(int entity, GameOn* component){
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
	
	void GameManager::addComponent(GameObject* obj, GameOn* component){
		if(obj == nullptr){
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
	
	void GameManager::addComponentRequest(int entity, GameOn* component){
		addRequest->addPointer(entity,component);
	}
	
	void GameManager::addComponentRequest(GameObject* obj, GameOn* component){
		int index = gameobjects->getIndexByPointer(obj);
		if(index == -1){
			return;
		}
		addRequest->addPointer(index,component);
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
	
	bool GameManager::containComponent(int entity, String componentClassName){
		List<GameOn>* list = this->getComponents(entity);
		
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
	
	bool GameManager::containComponent(GameObject* obj, String componentClassName){
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
	
	GameOn* GameManager::getComponent(int entity, int index){
		GameObject* obj = this->gameobjects->getByPosition(entity);
		if(obj == nullptr){
			return nullptr;
		}
		return obj->getChilds()->getByPosition(index);
	}
	
	bool GameManager::isEmpty(){
		return gameobjects->isEmpty();
	}
	
	GameOn* GameManager::getComponent(int entity, String componentClassName){
		List<GameOn>* list = this->getComponents(entity);
		
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
	
	GameOn* GameManager::getComponent(GameObject* obj, String componentClassName){
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
	
	int GameManager::getEntityComponent(String componentClassName){
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
	
	int GameManager::getComponentIndex(int entity, String componentClassName){
		List<GameOn>* list = this->getComponents(entity);
		
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
	
	int GameManager::getComponentIndex(GameObject* obj, String componentClassName){
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
	
	List<GameOn>* GameManager::getComponents(int entity){
		GameObject* obj = this->gameobjects->getByPosition(entity);
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
	
	GameOn* GameManager::removeComponent(int entity, String componentClassName){
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
	
	GameOn* GameManager::removeComponent(GameObject* obj, String componentClassName){
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
	
	void GameManager::deleteComponent(int entity, String componentClassName){
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
	
	void GameManager::deleteComponent(GameObject* obj, String componentClassName){
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
	
	void GameManager::deleteComponentRequest(int entity, String componentClassName){
		deleteRequest->addLValues(entity,componentClassName);
	}
	
	void GameManager::deleteComponentRequest(GameObject* obj, String componentClassName){
		int index = gameobjects->getIndexByPointer(obj);
		if(index == -1){
			return;
		}
		deleteRequest->addLValues(index,componentClassName);
	}
	
	void GameManager::removeComponent(int entity, GameOn* component){
		GameObject* obj = this->gameobjects->getByPosition(entity);
		if(obj != nullptr){
			obj->detach(component);
		}
		PrimitiveList<GameOn>* list = this->components->getByLValue(component->getClassName());
		if(list != nullptr){
			list->removeByPointer(component);
		}
	}
	
	void GameManager::removeComponent(GameObject* obj, GameOn* component){
		if(obj != nullptr){
			 obj->detach(component);
		}
		PrimitiveList<GameOn>* list = this->components->getByLValue(component->getClassName());
		if(list != nullptr){
			list->removeByPointer(component);
		}
	}
	
	void GameManager::deleteComponent(int entity, GameOn* component){
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
	
	void GameManager::deleteComponent(GameObject* obj, GameOn* component){
		if(component != nullptr){
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
		for(int txp = 0; txp < this->addRequest->getPosition(); txp++){
			this->addComponent(*this->addRequest->getKeyByPosition(txp), this->addRequest->getByPosition(txp));
			this->addRequest->setValuePointerByPosition(txp, nullptr);
		}
		this->addRequest->resetDelete();
		
		for(int txp = 0; txp < this->deleteRequest->getPosition(); txp++){
			this->deleteComponent(*this->deleteRequest->getKeyByPosition(txp), *this->deleteRequest->getByPosition(txp));
		}
		this->deleteRequest->resetDelete();
		
		for(int txp = 0; txp < this->deleteERequest->getPosition(); txp++){
			this->deleteEntity(*this->deleteERequest->getByPosition(txp));
		}
		this->deleteERequest->resetDelete();
		
		if(deleteAllE){
			deleteAllE = false;
			this->deleteAllEntities();
		}
	}
	

#endif 
