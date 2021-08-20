

#ifndef GameManager_cpp
#define GameManager_cpp

#include "GameManager.h"

	ame::GameManager::GameManager(){
		this->deleteERequest = new ame::PrimitiveList<ame::GameObject>();
		this->addRequest = new ame::PrimitiveMap<ame::GameObject,ame::GameOn>();
		this->deleteRequest = new ame::PrimitiveMap<ame::GameObject,ame::cppObjectClass>();
		this->components = new ame::PrimitiveMap<ame::cppObjectClass,ame::PrimitiveList<ame::GameOn>>();
		this->m_gobjects = new ame::PrimitiveList<ame::GameObject>();
	}
	
	ame::GameManager::~GameManager(){
		delete this->deleteERequest;
		delete this->addRequest;
		delete this->deleteRequest;
		delete this->components;
		delete this->m_gobjects;
	}
	
	int ame::GameManager::createEntity(ame::GameObject* obj){
		GameManagerLog("GameManager", "createEntity",  "println", "with parameters");
		GameManagerLog("GameManager", "createEntity",  "println", String(this->m_gobjects->getPosition()));
		obj->setId(this->m_gobjects->getPosition());
		this->m_gobjects->addPointer(obj);
		return obj->getId();
	}
	
	ame::GameObject* ame::GameManager::createGameObject(ame::GameObject* obj){
		GameManagerLog("GameManager", "createame::GameObject",  "println", "with parameters");
		GameManagerLog("GameManager", "createame::GameObject",  "println", String(this->m_gobjects->getPosition()));
		obj->setId(this->m_gobjects->getPosition());
		this->m_gobjects->addPointer(obj);
		return obj;
	}
	
	int ame::GameManager::createEntity(){
		GameManagerLog("GameManager", "createEntity",  "println", "no parameters");
		GameManagerLog("GameManager", "createEntity",  "println", String(this->m_gobjects->getPosition()));
		ame::GameObject* obj = new ame::GameObject();
		obj->setId(this->m_gobjects->getPosition());
		this->m_gobjects->addPointer(obj);
		return obj->getId();
	}
	
	ame::GameObject* ame::GameManager::createGameObject(){
		GameManagerLog("GameManager", "createame::GameObject",  "println", "no parameters");
		GameManagerLog("GameManager", "createame::GameObject",  "println", String(this->m_gobjects->getPosition()));
		ame::GameObject* obj = new ame::GameObject();
		obj->setId(this->m_gobjects->getPosition());
		this->m_gobjects->addPointer(obj);
		return obj;
	}
	
	void ame::GameManager::deleteEntity(int entity){
		GameManagerLog("GameManager", "deleteEntity",  "println", String(entity));
		ame::GameObject* obj = this->m_gobjects->getByPosition(entity);
		if(obj == nullptr){
			GameManagerLog("GameManager", "deleteEntity",  "println", "obj == nullptr");
			return;
		}
		ame::List<ame::GameOn>* objChilds = obj->getChilds();
		if(objChilds == nullptr){
			GameManagerLog("GameManager", "deleteEntity",  "println", "objChilds == nullptr");
			return;
		}
		GameManagerLog("GameManager", "deleteEntity",  "println", "start to look for the childs on the component lists");
		for(int x = 0; x < objChilds->getPosition(); x++){
			ame::GameOn* child = objChilds->getByPosition(x);
			ame::cppObjectClass* classT = child->getClass();
			GameManagerLog("GameManager", "deleteEntity",  "println", String("child class name: ") + classnamae);
			ame::PrimitiveList<ame::GameOn>* list = this->components->getByPointer(classT);
			if(list == nullptr){
				GameManagerLog("GameManager", "deleteEntity",  "println", "list == nullptr");
				continue;
			}
			GameManagerLog("GameManager", "deleteEntity",  "println", "removing from the component list");
			list->removeByPointer(child);
		}
		GameManagerLog("GameManager", "deleteEntity",  "println", "removing-deleting from the ame::GameObjects list");
		this->m_gobjects->removeDeleteByPosition(entity);
	}
	
	void ame::GameManager::deleteGameObject(ame::GameObject* obj){
		GameManagerLog("GameManager", "deleteame::GameObject",  "println", "");
		if(!this->m_gobjects->containByPointer(obj)){
			GameManagerLog("GameManager", "deleteame::GameObject",  "println", "ame::GameObjects dont contains obj");
			return;
		}
		ame::List<ame::GameOn>* objChilds = obj->getChilds();
		if(objChilds == nullptr){
			GameManagerLog("GameManager", "deleteame::GameObject",  "println", "objChilds == nullptr");
			return;
		}
		GameManagerLog("GameManager", "deleteame::GameObject",  "println", "start to look for the childs on the component lists");
		for(int x = 0; x < objChilds->getPosition(); x++){
			GameOn* child = objChilds->getByPosition(x);
			cppObjectClass* cls = child->getClass();
			GameManagerLog("GameManager", "deleteame::GameObject",  "println", String("child class name: ") + classnamae);
			PrimitiveList<ame::GameOn>* list = this->components->getByPointer(cls);
			if(list == nullptr){
				GameManagerLog("GameManager", "deleteame::GameObject",  "println", "list == nullptr");
				continue;
			}
			GameManagerLog("GameManager", "deleteame::GameObject",  "println", "removing from the component list");
			list->removeByPointer(child);
		}
		GameManagerLog("GameManager", "deleteame::GameObject",  "println", "removing-deleting from the ame::GameObjects list");
		this->m_gobjects->removeDeleteByPointer(obj);
	}
	
	void ame::GameManager::deleteAllEntities(){
		GameManagerLog("GameManager", "deleteAllEntities",  "println", "");
		for(int x = 0; x < this->components->getPosition(); x++){
			ame::List<ame::GameOn>* childs = this->components->getByPosition(x);
			childs->reset();
		}
		this->m_gobjects->resetDelete();
	}
	
	void ame::GameManager::deleteEntityRequest(int entity){
		GameManagerLog("GameManager", "deleteEntityRequest",  "println", String(entity));
		ame::GameObject* obj = this->m_gobjects->getByPosition(entity);
		if(obj == nullptr){
			return;
		}
		deleteERequest->addPointer(obj);
	}
	
	void ame::GameManager::deleteGameObjectRequest(ame::GameObject* obj){
		GameManagerLog("GameManager", "deleteame::GameObjectRequest",  "println", "");
		if(!this->m_gobjects->containByPointer(obj)){
			return;
		}
		deleteERequest->addPointer(obj);
	}
	
	void ame::GameManager::deleteAllEntitiesRequest(){
		GameManagerLog("GameManager", "deleteAllEntitiesRequest",  "println", "");
		deleteAllE = true;
	}
	
	int ame::GameManager::getEntity(ame::GameObject* obj){
		GameManagerLog("GameManager", "getEntity",  "println", String(obj->getId()));
		if(this->m_gobjects->containByPointer(obj)){
			return obj->getId();
		}
		return -1;
	}
	
	int ame::GameManager::getEntity(cppObjectClass* cls){
		GameManagerLog("GameManager", "getEntity",  "println", entityClassName);
		for(int x = 0; x < this->m_gobjects->getPosition(); x++){
			GameOn* child = this->m_gobjects->getByPosition(x);
			if(child->getClass() == cls){
				return x;
			}
		}
		return -1;
	}
	
	ame::GameObject* ame::GameManager::getGameObject(ame::cppObjectClass* cls){
		GameManagerLog("GameManager", "getame::GameObject",  "println", entityClassName);
		for(int x = 0; x < this->m_gobjects->getPosition(); x++){
			ame::GameObject* obj = this->m_gobjects->getByPosition(x);
			if(obj->getClass() == cls){
				return obj;
			}
		}
		return nullptr;
	}
	
	ame::GameObject* ame::GameManager::getGameObject(int entity){
		GameManagerLog("GameManager", "getame::GameObject",  "println", String(entity));
		return this->m_gobjects->getByPosition(entity);
	}
	
	int ame::GameManager::getLastEntity(){
		GameManagerLog("GameManager", "getLastEntity",  "println", "");
		int position = this->m_gobjects->getPosition();
		if(position <= 0){
			return -1;
		}
		return position-1;
	}
	
	ame::GameObject* ame::GameManager::getLastGameObject(){
		GameManagerLog("GameManager", "getLastame::GameObject",  "println", "");
		int position = this->m_gobjects->getPosition();
		if(position <= 0){
			return nullptr;
		}
		return this->m_gobjects->getByPosition(position-1);
	}
	
	int ame::GameManager::getFirstEntity(){
		GameManagerLog("GameManager", "getFirstEntity",  "println", "");
		int position = this->m_gobjects->getPosition();
		if(position <= 0){
			return -1;
		}
		return 0;
	}
	
	ame::GameObject* ame::GameManager::getFirstGameObject(){
		GameManagerLog("GameManager", "getFirstame::GameObject",  "println", "");
		int position = this->m_gobjects->getPosition();
		if(position <= 0){
			return nullptr;
		}
		return this->m_gobjects->getByPosition(0);
	}
	
	void ame::GameManager::addEntityComponent(int entity, ame::GameOn* component){
		GameManagerLog("GameManager", "addEntityComponent",  "println", "");
		ame::GameObject* obj = this->m_gobjects->getByPosition(entity);
		if(obj == nullptr){
			return;
		}
		ame::PrimitiveList<ame::GameOn>* list = this->components->getByPointer(component->getClass());
		if(list == nullptr){
			list = new PrimitiveList<ame::GameOn>(false);
			this->components->addPointers(component->getClass(),list);
		}
		if(!list->containByPointer(component)){
			list->addPointer(component);
		}
		if(!obj->getChilds()->containByPointer(component)){
			obj->attach(component);
		}
	}
	
	void ame::GameManager::addGameObjectComponent(ame::GameObject* obj, GameOn* component){
		GameManagerLog("GameManager", "addame::GameObjectComponent",  "println", "");
		if(obj == nullptr){
			return;
		}
		if(!this->m_gobjects->containByPointer(obj)){
			return;
		}
		if(obj->getChilds()->containByPointer(component)){
			return;
		}
		obj->attach(component);
		
		PrimitiveList<ame::GameOn>* list = this->components->getByPointer(component->getClass());
		if(list == nullptr){
			list = new PrimitiveList<ame::GameOn>(false);
			this->components->addPointers(component->getClass(),list);
			list->addPointer(component);
		}else{
			list->addPointer(component);
		}
	}
	
	void ame::GameManager::addEntityComponentRequest(int entity, GameOn* component){
		GameManagerLog("GameManager", "addEntityComponentRequest",  "println", "");
		ame::GameObject* obj = this->m_gobjects->getByPosition(entity);
		if(obj == nullptr){
			return;
		}
		addRequest->addPointers(obj,component);
	}
	
	void ame::GameManager::addGameObjectComponentRequest(ame::GameObject* obj, GameOn* component){
		GameManagerLog("GameManager", "addame::GameObjectComponentRequest",  "println", "");
		if(!this->m_gobjects->containByPointer(obj)){
			return;
		}
		addRequest->addPointers(obj,component);
	}
	
	bool ame::GameManager::containComponent(cppObjectClass* cls){
		GameManagerLog("GameManager", "containComponent",  "println", "");
		for(int xxs = 0; xxs < this->m_gobjects->getPosition(); xxs++){
			ame::GameObject* obj = this->m_gobjects->getByPosition(xxs);
			if(obj == nullptr){
				return false;
			}
			ame::List<ame::GameOn>* objChilds = obj->getChilds();
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
	
	bool ame::GameManager::containEntityComponent(int entity, ame::cppObjectClass* cls){
		GameManagerLog("GameManager", "containEntityComponent",  "println", "");
		ame::List<ame::GameOn>* list = this->getEntityComponents(entity);
		
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
	
	bool ame::GameManager::containGameObjectComponent(ame::GameObject* obj, ame::cppObjectClass* cls){
		GameManagerLog("GameManager", "containame::GameObjectComponent",  "println", "");
		if(obj == nullptr){
			return false;
		}
		ame::List<ame::GameOn>* list = obj->getChilds();
		
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
	
	ame::GameOn* ame::GameManager::getEntityComponent(int entity, int index){
		GameManagerLog("GameManager", "getEntityComponent",  "println", "");
		ame::GameObject* obj = this->m_gobjects->getByPosition(entity);
		if(obj == nullptr){
			return nullptr;
		}
		return obj->getChilds()->getByPosition(index);
	}
	
	bool ame::GameManager::isEmpty(){
		GameManagerLog("GameManager", "isEmpty",  "println", "");
		return this->m_gobjects->isEmpty();
	}
	
	ame::GameOn* ame::GameManager::getEntityComponent(int entity, ame::cppObjectClass* cls){
		GameManagerLog("GameManager", "getEntityComponent",  "println", "");
		ame::List<ame::GameOn>* list = this->getEntityComponents(entity);
		
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
	
	ame::GameOn* ame::GameManager::getGameObjectComponent(ame::GameObject* obj, ame::cppObjectClass* cls){
		GameManagerLog("GameManager", "getame::GameObjectComponent",  "println", "");
		if(obj == nullptr){
			return nullptr;
		}
		ame::List<ame::GameOn>* list = obj->getChilds();
		
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
	
	ame::GameOn* ame::GameManager::getComponent(ame::cppObjectClass* cls){
		GameManagerLog("GameManager", "getComponent",  "println", "");
		for(int x = 0; x < this->m_gobjects->getPosition(); x++){
			for(int xc = 0; xc < this->m_gobjects->getByPosition(x)->getChilds()->getPosition(); xc++){
				if(this->m_gobjects->getByPosition(x)->getChilds()->getByPosition(xc)->getClass() == cls){
					return this->m_gobjects->getByPosition(x)->getChilds()->getByPosition(xc);
				}
			}
		}
		return nullptr;
	}
	
	int ame::GameManager::getEntityByComponent(ame::cppObjectClass* cls){
		GameManagerLog("GameManager", "getEntityByComponent",  "println", "");
		for(int x = 0; x < this->m_gobjects->getPosition(); x++){
			ame::GameObject* obj = this->m_gobjects->getByPosition(x);
			if(obj == nullptr){
				return -1;
			}
			ame::List<ame::GameOn>* list = obj->getChilds();
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
	
	int ame::GameManager::getEntityComponentIndex(int entity, ame::cppObjectClass* cls){
		GameManagerLog("GameManager", "getEntityComponentIndex",  "println", "");
		ame::List<ame::GameOn>* list = this->getEntityComponents(entity);
		
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
	
	int ame::GameManager::getGameObjectComponentIndex(ame::GameObject* obj, ame::cppObjectClass* cls){
		GameManagerLog("GameManager", "getame::GameObjectComponentIndex",  "println", "");
		if(obj == nullptr){
			return -1;
		}
		ame::List<ame::GameOn>* list = obj->getChilds();
		
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
	
	int ame::GameManager::getComponentEntity(ame::cppObjectClass* cls){
		GameManagerLog("GameManager", "getComponentEntity",  "println", "");
		for(int x = 0; x < this->m_gobjects->getPosition(); x++){
			ame::GameObject* obj = m_gobjects->getByPosition(x);
			ame::List<ame::GameOn>* list = obj->getChilds();
			for(int xs = 0; xs < list->getPosition(); xs++){
				GameOn* child = list->getByPosition(xs);
				if(child->getClass() == cls){
					return xs;
				}
			}
		}
		return -1;
	}
	
	ame::List<ame::GameOn>* ame::GameManager::getEntityComponents(int entity){
		GameManagerLog("GameManager", "getEntityComponents",  "println", "");
		ame::GameObject* obj = this->m_gobjects->getByPosition(entity);
		if(obj != nullptr){
			return obj->getChilds();
		}
		return nullptr;
	}
	
	ame::List<ame::GameOn>* ame::GameManager::getGameObjectComponents(ame::GameObject* obj){
		GameManagerLog("GameManager", "getame::GameObjectComponents",  "println", "");
		if(obj != nullptr){
			return obj->getChilds();
		}
		return nullptr;
	}
	
	ame::List<ame::GameOn>* ame::GameManager::getComponents(ame::cppObjectClass* cls){
		GameManagerLog("GameManager", "getComponents",  "println", "");
		ame::PrimitiveList<ame::GameOn>* list = this->components->getByPointer(cls);
		if(list == nullptr){
			list = new PrimitiveList<ame::GameOn>(false);
			this->components->addPointers(cls,list);
		}
		return list;
	}
	
	void ame::GameManager::deleteComponent(ame::cppObjectClass* cls){
		GameManagerLog("GameManager", "deleteComponent",  "println", "");
		for(int x= 0; x < this->m_gobjects->getPosition(); x++){
			ame::GameOn* gameon = nullptr;
			ame::GameObject* obj = this->m_gobjects->getByPosition(x);
			if(obj != nullptr){
				gameon = obj->detach(cls);
			}
			ame::PrimitiveList<ame::GameOn>* list = this->components->getByPointer(cls);
			if(list != nullptr){
				list->removeByPointer(gameon);
			}
			if(gameon == nullptr){
				return;
			}
			delete gameon;
		}
	}
	
	ame::GameOn* ame::GameManager::removeEntityComponent(int entity, ame::cppObjectClass* cls){
		GameManagerLog("GameManager", "removeEntityComponent",  "println", "");
		ame::GameOn* gameon = nullptr;
		ame::GameObject* obj = this->m_gobjects->getByPosition(entity);
		if(obj != nullptr){
			gameon = obj->detach(cls);
		}
		ame::PrimitiveList<ame::GameOn>* list = this->components->getByPointer(cls);
		if(list != nullptr){
			list->removeByPointer(gameon);
		}
		return gameon;
	}
	
	ame::GameOn* ame::GameManager::removeGameObjectComponent(ame::GameObject* obj, ame::cppObjectClass* cls){
		GameManagerLog("GameManager", "removeame::GameObjectComponent",  "println", "");
		ame::GameOn* gameon = nullptr;
		if(obj != nullptr){
			gameon = obj->detach(cls);
		}
		PrimitiveList<ame::GameOn>* list = this->components->getByPointer(cls);
		if(list != nullptr){
			list->removeByPointer(gameon);
		}
		return gameon;
	}
	
	void ame::GameManager::deleteEntityComponent(int entity, ame::cppObjectClass* cls){
		GameManagerLog("GameManager", "deleteEntityComponent",  "println", "");
		ame::GameObject* obj = this->m_gobjects->getByPosition(entity);
		if(obj == nullptr){
			return;
		}
		
		ame::GameOn* gon = obj->detach(cls);
		ame::PrimitiveList<ame::GameOn>* list = this->components->getByPointer(cls);
		if(list != nullptr){
			list->removeByPointer(gon);
		}
		if(gon != nullptr){
			delete gon;
		}
	}
	
	void ame::GameManager::deleteGameObjectComponent(ame::GameObject* obj, ame::cppObjectClass* cls){
		GameManagerLog("GameManager", "deleteame::GameObjectComponent",  "println", "");
		if(obj == nullptr){
			return;
		}
		
		ame::GameOn* gon = obj->detach(cls);
		ame::PrimitiveList<ame::GameOn>* list = this->components->getByPointer(cls);
		if(list != nullptr){
			list->removeByPointer(gon);
		}
		if(gon != nullptr){
			delete gon;
		}
	}
	
	void ame::GameManager::deleteEntityComponents(int entity){
		GameManagerLog("GameManager", "deleteEntityComponents",  "println", "");
		ame::GameObject* obj = this->m_gobjects->getByPosition(entity);
		if(obj == nullptr){
			return;
		}
		
		ame::List<ame::GameOn>* list = obj->getChilds();
		if(list == nullptr){
			return;
		}
		ame::PrimitiveList<ame::cppObjectClass> classT;
		for(int x = 0; x < list->getPosition(); x++){
			GameOn* gon = list->getByPosition(x);
			classT.addPointer(gon->getClass());
		}
		for(int x = 0; x < classT.getPosition(); x++){
			cppObjectClass* cls = classT.getByPosition(x);
			PrimitiveList<ame::GameOn>* list2 = this->components->getByPointer(cls);
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
	
	void ame::GameManager::deleteGameObjectComponents(ame::GameObject* obj){
		GameManagerLog("GameManager", "deleteame::GameObjectComponents",  "println", "");
		if(obj == nullptr){
			return;
		}
		
		ame::List<ame::GameOn>* list = obj->getChilds();
		if(list == nullptr){
			return;
		}
		ame::PrimitiveList<ame::cppObjectClass> classT;
		for(int x = 0; x < list->getPosition(); x++){
			GameOn* gon = list->getByPosition(x);
			classT.addPointer(gon->getClass());
		}
		for(int x = 0; x < classT.getPosition(); x++){
			ame::cppObjectClass* cls = classT.getByPosition(x);
			ame::PrimitiveList<ame::GameOn>* list2 = this->components->getByPointer(cls);
			if(list2 == nullptr){
				continue;
			}
			ame::GameOn* gon = obj->detach(cls);
			if(gon == nullptr){
				continue;
			}
			list2->removeByPointer(gon);
			delete gon;
		}
	}
	
	void ame::GameManager::deleteEntityComponentRequest(int entity, ame::cppObjectClass* cls){
		GameManagerLog("GameManager", "deleteEntityComponentRequest",  "println", "");
		ame::GameObject* obj = this->m_gobjects->getByPosition(entity);
		if(obj == nullptr){
			return;
		}
		deleteRequest->addPointers(obj,cls);
	}
	
	void ame::GameManager::deleteGameObjectComponentRequest(ame::GameObject* obj, ame::cppObjectClass* cls){
		GameManagerLog("GameManager", "deleteame::GameObjectComponentRequest",  "println", "");
		if(!this->m_gobjects->containByPointer(obj)){
			return;
		}
		deleteRequest->addPointers(obj,cls);
	}
	
	void ame::GameManager::removeEntityComponent(int entity, ame::GameOn* component){
		GameManagerLog("GameManager", "removeEntityComponent",  "println", "");
		ame::GameObject* obj = this->m_gobjects->getByPosition(entity);
		if(obj != nullptr){
			obj->detach(component);
		}
		ame::PrimitiveList<ame::GameOn>* list = this->components->getByPointer(component->getClass());
		if(list != nullptr){
			list->removeByPointer(component);
		}
	}
	
	void ame::GameManager::removeGameObjectComponent(ame::GameObject* obj, ame::GameOn* component){
		GameManagerLog("GameManager", "removeame::GameObjectComponent",  "println", "");
		if(obj != nullptr){
			 obj->detach(component);
		}
		ame::PrimitiveList<ame::GameOn>* list = this->components->getByPointer(component->getClass());
		if(list != nullptr){
			list->removeByPointer(component);
		}
	}
	
	void ame::GameManager::deleteEntityComponent(int entity, ame::GameOn* component){
		GameManagerLog("GameManager", "deleteEntityComponent",  "println", "");
		if(component != nullptr){
			ame::GameObject* obj = this->m_gobjects->getByPosition(entity);
			if(obj == nullptr){
				return;
			}
			obj->detach(component);
			ame::PrimitiveList<ame::GameOn>* list = this->components->getByPointer(component->getClass());
			if(list != nullptr){
				list->removeByPointer(component);
			}
			delete component;
		}
	}
	
	void ame::GameManager::deleteGameObjectComponent(ame::GameObject* obj, ame::GameOn* component){
		GameManagerLog("GameManager", "deleteame::GameObjectComponent",  "println", "");
		if(component == nullptr){
			return;
		}
		if(obj == nullptr){
			return;
		}
		if(!this->m_gobjects->containByPointer(obj)){
			return;
		}
		obj->detach(component);
		ame::PrimitiveList<ame::GameOn>* list = this->components->getByPointer(component->getClass());
		if(list != nullptr){
			list->removeByPointer(component);
		}
		delete component;
	}
	
	ame::GameOn* ame::GameManager::removeComponentIterating(ame::Iterator& i, ame::List<ame::GameOn>* listComponents){
		GameManagerLog("GameManager", "removeComponentIterating",  "println", "");
		if(listComponents != nullptr){
			ame::GameOn* gameon = listComponents->getPointer(i);
			listComponents->remove(i);
			ame::GameObject* obj = this->m_gobjects->getByPosition(gameon->getId());
			if(obj != nullptr){
				obj->detach(gameon);
			}
			i.last();
			return gameon;
		}
		return nullptr;
	}
	
	void ame::GameManager::deleteComponentIterating(ame::Iterator& i, ame::List<ame::GameOn>* listComponents){
		GameManagerLog("GameManager", "deleteComponentIterating",  "println", "");
		if(listComponents != nullptr){
			ame::GameOn* gameon = listComponents->getPointer(i);
			listComponents->remove(i);
			ame::GameObject* obj = this->m_gobjects->getByPosition(gameon->getId());
			if(obj == nullptr){
				return;
			}
			obj->detach(gameon);
			delete gameon;
			i.last();
		}
	}
	
	void ame::GameManager::deleteComponentsFromList(ame::PrimitiveList<ame::GameOn>* listComponents){
		GameManagerLog("GameManager", "deleteComponentsFromList",  "println", "");
		if(listComponents == nullptr){
			return;
		}
		if(listComponents->isEmpty()){
			return;
		}
		ame::cppObjectClass* s = this->components->getKeyByPointer(listComponents);
		if(s == nullptr){
			return;
		}
		for(int x = 0; x > this->m_gobjects->getPosition(); x++){
			ame::GameObject* obj = this->m_gobjects->getByPosition(x);
			ame::List<ame::GameOn>* list = obj->getChilds();
			for(int x = 0; x < list->getPosition(); x++){
				ame::GameOn* gameon = list->getByPosition(x);
				if(gameon->getClass() == s){
					list->removeDeleteByPosition(x);
					x--;
				}
			}
		}
		listComponents->reset();
	}
	
	int ame::GameManager::getEntitySize(){
		GameManagerLog("GameManager", "getEntitySize",  "println", "");
		return this->m_gobjects->getPosition();
	}
	
	int ame::GameManager::getComponentSize(int entity){
		GameManagerLog("GameManager", "getComponentSize",  "println", "");
		if(this->m_gobjects->getByPosition(entity)==nullptr){
			return -1;
		}
		return this->m_gobjects->getByPosition(entity)->getChilds()->getPosition();
	}
	
	void ame::GameManager::rearrange(){
		GameManagerLog("GameManager", "rearrange",  "println", "");
		for(int x = 0; x < this->m_gobjects->getPosition(); x++){
			GameOn* gameon = this->m_gobjects->getByPosition(x);
			gameon->setId(x);
		}
	}
	
	ame::cppObjectClass* ame::GameManager::getClass(){
		return ame::Class<GameManager>::classType;
	}
	
	String ame::GameManager::toString(){
		return "GameManager"+String(this->m_gobjects->getSize());
	}
	
	bool ame::GameManager::equal(ame::cppObject *b){
		if(b == this){
			return true;
		}
		if(b->getClass() == this->getClass()){
			return true;
		}
		return false;
	}
	
	ame::cppObject* ame::GameManager::clone(){
		return new ame::GameManager();
	}
	
	void ame::GameManager::update(float tpc){
		// Serial.println("start ame::GameManager update");
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
		// Serial.println("end ame::GameManager update");
	}
	

#endif 
