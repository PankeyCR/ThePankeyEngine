
#include "ame_Enviroment.hpp"

#if defined(DISABLE_GameManager)
	#define GameManager_hpp
#endif

#ifndef GameManager_hpp
#define GameManager_hpp
#define GameManager_AVAILABLE

#ifndef ame_Enviroment_Defined

#endif

#ifdef ame_Windows

#endif

#ifdef ame_ArduinoIDE
	#include "Arduino.h"
#endif

#include "cppObject.hpp"
#include "AppState.hpp"
#include "GameObject.hpp"
#include "Map.hpp"
#include "PrimitiveMap.hpp"
#include "PrimitiveList.hpp"
#include "List.hpp"

#ifdef GameManagerLogApp
	#include "Logger.hpp"
	#define GameManagerLog(name,method,type,mns) Log(name,method,type,mns)
#else
	#define GameManagerLog(name,method,type,mns)
#endif

namespace ame{

class GameManager : public AppState{
    public:		
		GameManager(){}
		
		virtual ~GameManager(){}
		
		
		int createEntity(GameObject* obj){
			GameManagerLog("GameManager", "createEntity",  "println", "with parameters");
			if(obj == nullptr){
				GameManagerLog("GameManager", "createEntity",  "println", "obj == nullptr");
				return -1;
			}
			GameManagerLog("GameManager", "createEntity",  "println", Note("id ") + Note(m_gobjects.getPosition()));
			obj->setId(m_gobjects.getPosition());
			m_gobjects.addPointer(obj);
			return obj->getId();
		}
		
		GameObject* createGameObject(GameObject* obj){
			GameManagerLog("GameManager", "createGameObject",  "println", "with parameters");
			if(obj == nullptr){
				GameManagerLog("GameManager", "createGameObject",  "println", "obj == nullptr");
				return nullptr;
			}
			GameManagerLog("GameManager", "createGameObject",  "println", Note("id ") + Note(m_gobjects.getPosition()));
			obj->setId(m_gobjects.getPosition());
			m_gobjects.addPointer(obj);
			return obj;
		}
		
		
		int createEntity(){
			GameManagerLog("GameManager", "createEntity",  "println", "no parameters");
			GameManagerLog("GameManager", "createEntity",  "println", Note("id ") + Note(m_gobjects.getPosition()));
			GameObject* obj = new GameObject();
			obj->setId(m_gobjects.getPosition());
			m_gobjects.addPointer(obj);
			return obj->getId();
		}
		
		GameObject* createGameObject(){
			GameManagerLog("GameManager", "createGameObject",  "println", "no parameters");
			GameManagerLog("GameManager", "createGameObject",  "println", Note("id ") + Note(m_gobjects.getPosition()));
			GameObject* obj = new GameObject();
			obj->setId(m_gobjects.getPosition());
			m_gobjects.addPointer(obj);
			return obj;
		}
		
		
		void deleteEntity(int entity){
			GameManagerLog("GameManager", "deleteEntity",  "println", Note("id ") + Note(entity));
			GameObject* obj = m_gobjects.getByPosition(entity);
			if(obj == nullptr){
				GameManagerLog("GameManager", "deleteEntity",  "println", "obj == nullptr");
				return;
			}
			PrimitiveList<GameOn>& objChilds = obj->getChilds();
			GameManagerLog("GameManager", "deleteEntity",  "println", "start to look for the childs on the component lists");
			for(int x = 0; x < objChilds.getPosition(); x++){
				GameOn* child = objChilds.getByPosition(x);
				cppObjectClass* classT = child->getClass();
				PrimitiveList<GameOn>* list = components.getByPointer(classT);
				if(list == nullptr){
					GameManagerLog("GameManager", "deleteEntity",  "println", "list == nullptr");
					continue;
				}
				GameManagerLog("GameManager", "deleteEntity",  "println", "removing from the component list");
				list->removeByPointer(child);
			}
			GameManagerLog("GameManager", "deleteEntity",  "println", "removing-deleting from the GameObjects list");
			m_gobjects.removeDeleteByPosition(entity);
		}
		
		void deleteGameObject(GameObject* obj){
			GameManagerLog("GameManager", "deleteGameObject",  "println", "");
			if(!m_gobjects.containByPointer(obj)){
				GameManagerLog("GameManager", "deleteGameObject",  "println", "GameObjects dont contains obj");
				return;
			}
			PrimitiveList<GameOn>& objChilds = obj->getChilds();
			GameManagerLog("GameManager", "deleteGameObject",  "println", "start to look for the childs on the component lists");
			for(int x = 0; x < objChilds.getPosition(); x++){
				GameOn* child = objChilds.getByPosition(x);
				cppObjectClass* cls = child->getClass();
				PrimitiveList<GameOn>* list = components.getByPointer(cls);
				if(list == nullptr){
					GameManagerLog("GameManager", "deleteGameObject",  "println", "list == nullptr");
					continue;
				}
				GameManagerLog("GameManager", "deleteGameObject",  "println", "removing from the component list");
				list->removeByPointer(child);
			}
			GameManagerLog("GameManager", "deleteGameObject",  "println", "removing-deleting from the GameObjects list");
			m_gobjects.removeDeleteByPointer(obj);
		}
		
		void deleteAllEntities(){
			GameManagerLog("GameManager", "deleteAllEntities",  "println", "");
			GameManagerLog("GameManager", "deleteAllEntities",  "println", Note("total entities ") + Note(components.getPosition()));
			for(int x = 0; x < components.getPosition(); x++){
				List<GameOn>* childs = components.getByPosition(x);
				childs->reset();
			}
			m_gobjects.resetDelete();
		}
		
		
		void deleteEntityRequest(int entity){
			GameManagerLog("GameManager", "deleteEntityRequest",  "println", "adding entity to the delete request list");
			GameManagerLog("GameManager", "deleteEntityRequest",  "println", Note("id ") + Note(entity));
			GameObject* obj = m_gobjects.getByPosition(entity);
			if(obj == nullptr){
				return;
			}
			deleteERequest.addPointer(obj);
		}
		
		void deleteGameObjectRequest(GameObject* obj){
			GameManagerLog("GameManager", "deleteGameObjectRequest",  "println", "");
			if(!m_gobjects.containByPointer(obj)){
				return;
			}
			deleteERequest.addPointer(obj);
		}
		
		void deleteAllEntitiesRequest(){
			GameManagerLog("GameManager", "deleteAllEntitiesRequest",  "println", "");
			deleteAllE = true;
		}
		
		
		int getEntity(cppObjectClass* cls){
			GameManagerLog("GameManager", "getEntity",  "println", "");
			for(int x = 0; x < m_gobjects.getPosition(); x++){
				GameObject* obj = m_gobjects.getByPosition(x);
				if(obj->getClass() == cls){
					return obj->getId();
				}
			}
			return -1;
		}
		
		GameObject* getGameObject(cppObjectClass* cls){
			GameManagerLog("GameManager", "getGameObject",  "println", "");
			for(int x = 0; x < m_gobjects.getPosition(); x++){
				GameObject* obj = m_gobjects.getByPosition(x);
				if(obj->getClass() == cls){
					return obj;
				}
			}
			return nullptr;
		}
		
		int getEntity(GameObject* obj){
			GameManagerLog("GameManager", "getEntity",  "println", Note(obj->getId()));
			if(m_gobjects.containByPointer(obj)){
				return obj->getId();
			}
			return -1;
		}
		
		GameObject* getGameObject(int entity){
			GameManagerLog("GameManager", "getGameObject",  "println", Note(entity));
			return m_gobjects.getByPosition(entity);
		}
		
		
		int getFirstEntity(){
			GameManagerLog("GameManager", "getFirstEntity",  "println", "");
			int position = m_gobjects.getPosition();
			if(position <= 0){
				return -1;
			}
			return 0;
		}
		
		GameObject* getFirstGameObject(){
			GameManagerLog("GameManager", "getFirstGameObject",  "println", "");
			int position = m_gobjects.getPosition();
			if(position <= 0){
				return nullptr;
			}
			return m_gobjects.getByPosition(0);
		}
		
		int getLastEntity(){
			GameManagerLog("GameManager", "getLastEntity",  "println", "");
			int position = m_gobjects.getPosition();
			if(position <= 0){
				return -1;
			}
			return position-1;
		}
		
		GameObject* getLastGameObject(){
			GameManagerLog("GameManager", "getLastGameObject",  "println", "");
			int position = m_gobjects.getPosition();
			if(position <= 0){
				return nullptr;
			}
			return m_gobjects.getByPosition(position-1);
		}
		
		
		void addEntityComponent(int entity, GameOn* component){
			GameManagerLog("GameManager", "addEntityComponent",  "println", "");
			GameObject* obj = m_gobjects.getByPosition(entity);
			if(obj == nullptr){
				GameManagerLog("GameManager", "addEntityComponent",  "println", "no object with these entity id");
				return;
			}
			PrimitiveList<GameOn>* list = components.getByPointer(component->getClass());
			if(list == nullptr){
				GameManagerLog("GameManager", "addEntityComponent",  "println", "creating list for the component class");
				list = new PrimitiveList<GameOn>(false);
				components.addPointers(component->getClass(),list);
			}
			if(!list->containByPointer(component)){
				GameManagerLog("GameManager", "addEntityComponent",  "println", "adding component to the list");
				list->addPointer(component);
			}
			if(!obj->getChilds().containByPointer(component)){
				GameManagerLog("GameManager", "addEntityComponent",  "println", "adding component to the gameobject");
				obj->attach(component);
			}
		}
		
		void addGameObjectComponent(GameObject* obj, GameOn* component){
			GameManagerLog("GameManager", "addGameObjectComponent",  "println", "");
			if(obj == nullptr){
				return;
			}
			if(!m_gobjects.containByPointer(obj)){
				return;
			}
			if(obj->getChilds().containByPointer(component)){
				return;
			}
			obj->attach(component);
			
			PrimitiveList<GameOn>* list = components.getByPointer(component->getClass());
			if(list == nullptr){
				list = new PrimitiveList<GameOn>(false);
				components.addPointers(component->getClass(),list);
			}
			list->addPointer(component);
		}
		
		
		void addEntityComponentRequest(int entity, GameOn* component){
			GameManagerLog("GameManager", "addEntityComponentRequest",  "println", "");
			GameObject* obj = m_gobjects.getByPosition(entity);
			if(obj == nullptr){
				return;
			}
			addRequest.addPointers(obj,component);
		}
		
		void addGameObjectComponentRequest(GameObject* obj, GameOn* component){
			GameManagerLog("GameManager", "addGameObjectComponentRequest",  "println", "");
			if(!m_gobjects.containByPointer(obj)){
				return;
			}
			addRequest.addPointers(obj,component);
		}
		
		
		bool containComponent(cppObjectClass* cls){
			GameManagerLog("GameManager", "containComponent",  "println", "");
			if(cls == nullptr){
				return false;
			}
			for(int x = 0; x < m_gobjects.getPosition(); x++){
				GameObject* obj = m_gobjects.getByPosition(x);
				if(obj == nullptr){
					return false;
				}
				PrimitiveList<GameOn>& objChilds = obj->getChilds();
				for(int y = 0; y < objChilds.getPosition(); y++){
					GameOn* child = objChilds.getByPosition(y);
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
		
		template<class... s>
		bool containComponents(s... componentClass){
			if(isEmpty()){
				return false;
			}
			PrimitiveList<cppObjectClass> classNs;
			classNs.addPack(componentClass...);
			if(classNs.isEmpty()){
				return false;
			}
			for(int x = 0; x < m_gobjects.getPosition(); x++){
				GameObject* obj = m_gobjects.getByPosition(x);
				PrimitiveList<GameOn>& objChilds = obj->getChilds();
				for(int y = 0; y < objChilds.getPosition(); y++){
					GameOn* child = objChilds.getByPosition(y);
					if(child == nullptr){
						return false;
					}
					for(int z = 0; z < classNs.getPosition(); z++){
						cppObjectClass* cls = classNs.getByPosition(z);
						if(child->getClass() == cls){
							return true;
						}
					}
				}
			}
			return true;
		}
		
		bool containEntityComponent(int entity, cppObjectClass* cls){
			GameManagerLog("GameManager", "containEntityComponent",  "println", "");
			List<GameOn>* list = getEntityComponents(entity);
			
			if(list == nullptr){
				return false;
			}
			
			for(int x = 0; x < list->getPosition(); x++){
				GameOn* child = list->getByPosition(x);
				if(child == nullptr){
					continue;
				}
				if(child->getClass() == cls){
					return true;
				}
			}
			return false;
		}
		
		template<class... s>
		bool containEntityComponents(int entity, s... componentClass){
			PrimitiveList<Note> classNs;
			classNs.addPack(componentClass...);
			if(classNs.isEmpty()){
				return false;
			}
			bool ec = false;
			for(int x = 0; x < classNs.getPosition(); x++){
				cppObjectClass* cls = classNs.getByPosition(x);
				ec = containEntityComponent(entity, cls);
				if(ec == false){
					return false;
				}
			}
			return ec;
		}
		bool containGameObjectComponent(GameObject* obj, cppObjectClass* cls){
			GameManagerLog("GameManager", "containGameObjectComponent",  "println", "");
			if(obj == nullptr){
				return false;
			}
			PrimitiveList<GameOn>& list = obj->getChilds();
			
			for(int x = 0; x < list.getPosition(); x++){
				if(list.getByPosition(x)->getClass() == cls){
					return true;
				}
			}
			return false;
		}
		
		
		bool isEmpty(){
			GameManagerLog("GameManager", "isEmpty",  "println", "");
			return m_gobjects.isEmpty();
		}
		
		
		GameOn* getEntityComponent(int entity, int index){
			GameManagerLog("GameManager", "getEntityComponent",  "println", "");
			GameObject* obj = m_gobjects.getByPosition(entity);
			if(obj == nullptr){
				return nullptr;
			}
			return obj->getChilds().getByPosition(index);
		}
		
		GameOn* getEntityComponent(int entity, cppObjectClass* cls){
			GameManagerLog("GameManager", "getEntityComponent",  "println", "");
			List<GameOn>* list = getEntityComponents(entity);
			
			if(list == nullptr){
				return nullptr;
			}
			
			for(int x = 0; x < list->getPosition(); x++){
				GameOn* child = list->getByPosition(x);
				if(child == nullptr){
					continue;
				}
				if(child->getClass() == cls){
					return child;
				}
			}
			return nullptr;
		}
		
		GameOn* getGameObjectComponent(GameObject* obj, cppObjectClass* cls){
			GameManagerLog("GameManager", "getGameObjectComponent",  "println", "");
			if(obj == nullptr){
				return nullptr;
			}
			PrimitiveList<GameOn>& list = obj->getChilds();
			
			for(int x = 0; x < list.getPosition(); x++){
				GameOn* child = list.getByPosition(x);
				if(child == nullptr){
					continue;
				}
				if(child->getClass() == cls){
					return list.getByPosition(x);
				}
			}
			return nullptr;
		}
		
		
		//returns the first component founded on the gameobjects list searched by the componentClassName
		GameOn* getComponent(cppObjectClass* cls){
			GameManagerLog("GameManager", "getComponent",  "println", "");
			for(int x = 0; x < m_gobjects.getPosition(); x++){
				GameObject* obj = m_gobjects.getByPosition(x);
				if(obj == nullptr){
					continue;
				}
				PrimitiveList<GameOn>& list = obj->getChilds();
				for(int xc = 0; xc < list.getPosition(); xc++){
					GameOn* objGON = list.getByPosition(x);
					if(objGON == nullptr){
						continue;
					}
					cppObjectClass* objClass = objGON->getClass();
					if(objClass == cls){
						return objGON;
					}
				}
			}
			return nullptr;
		}
		
		//returns the first entity founded with the componentClassName 
		int getEntityByComponent(cppObjectClass* cls){
			GameManagerLog("GameManager", "getEntityByComponent",  "println", "");
			for(int x = 0; x < m_gobjects.getPosition(); x++){
				GameObject* obj = m_gobjects.getByPosition(x);
				if(obj == nullptr){
					return -1;
				}
				PrimitiveList<GameOn>& list = obj->getChilds();
				for(int y = 0; y < list.getPosition(); y++){
					GameOn* gameon = list.getByPosition(y);
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
		int getEntityByComponent(GameOn* gmon){
			GameManagerLog("GameManager", "getEntityByComponent",  "println", "");
			for(int x = 0; x < m_gobjects.getPosition(); x++){
				GameObject* obj = m_gobjects.getByPosition(x);
				if(obj == nullptr){
					return -1;
				}
				PrimitiveList<GameOn>& list = obj->getChilds();
				for(int y = 0; y < list.getPosition(); y++){
					GameOn* gameon = list.getByPosition(y);
					if(gameon == nullptr){
						return -1;
					}
					if(gameon == gmon){
						return x;
					}
				}
			}
			return -1;
		}
		
		
		template<class... s>
		int getEntityByComponents(s... componentClass){
			PrimitiveList<cppObjectClass> classNs;
			classNs.addPack(componentClass...);
			if(classNs.isEmpty()){
				return -1;
			}
			int ec = -1;
			for(int x = 0; x < classNs.getPosition(); x++){
				cppObjectClass* cls = classNs.getByPosition(x);
				ec = getEntityByComponent(cls);
				if(ec == -1){
					return -1;
				}
			}
			return ec;
		}
		
		int getEntityComponentIndex(int entity, cppObjectClass* cls){
			GameManagerLog("GameManager", "getEntityComponentIndex",  "println", "");
			List<GameOn>* list = getEntityComponents(entity);
			
			if(list == nullptr){
				return -1;
			}
			
			for(int x = 0; x < list->getPosition(); x++){
				GameOn* child = list->getByPosition(x);
				if(child == nullptr){
					continue;
				}
				if(child->getClass() == cls){
					return x;
				}
			}
			return -1;
		}
		
		int getGameObjectComponentIndex(GameObject* obj, cppObjectClass* cls){
			GameManagerLog("GameManager", "getGameObjectComponentIndex",  "println", "");
			if(obj == nullptr){
				return -1;
			}
			PrimitiveList<GameOn>& list = obj->getChilds();
			
			for(int x = 0; x < list.getPosition(); x++){
				GameOn* listGON = list.getByPosition(x);
				if(listGON == nullptr){
					continue;
				}
				if(listGON->getClass() == cls){
					return x;
				}
			}
			return -1;
		}
		
		
		//returns the position of the first component founded on the gameobjects list searched by the componentClassName
		int getComponentEntity(cppObjectClass* cls){
			GameManagerLog("GameManager", "getComponentEntity",  "println", "");
			for(int x = 0; x < m_gobjects.getPosition(); x++){
				GameObject* obj = m_gobjects.getByPosition(x);
				if(obj == nullptr){
					continue;
				}
				PrimitiveList<GameOn>& list = obj->getChilds();
				for(int xs = 0; xs < list.getPosition(); xs++){
					GameOn* child = list.getByPosition(xs);
					if(child == nullptr){
						continue;
					}
					if(child->getClass() == cls){
						return xs;
					}
				}
			}
			return -1;
		}
		
		List<GameOn>* getEntityComponents(int entity){
			GameManagerLog("GameManager", "getEntityComponents",  "println", "");
			GameObject* obj = m_gobjects.getByPosition(entity);
			if(obj != nullptr){
				return &obj->getChilds();
			}
			return nullptr;
		}
		
		List<GameOn>* getGameObjectComponents(GameObject* obj){
			GameManagerLog("GameManager", "getGameObjectComponents",  "println", "");
			if(obj != nullptr){
				return &obj->getChilds();
			}
			return nullptr;
		}
		
		PrimitiveList<GameOn>* getComponents(cppObjectClass* cls){
			GameManagerLog("GameManager", "getComponents",  "println", "");
			PrimitiveList<GameOn>* list = components.getByPointer(cls);
			if(list == nullptr){
				list = new PrimitiveList<GameOn>(false);
				components.addPointers(cls,list);
			}
			return list;
		}
		
		
		void deleteComponent(cppObjectClass* cls){
			GameManagerLog("GameManager", "deleteComponent",  "println", "");
			for(int x= 0; x < m_gobjects.getPosition(); x++){
				GameOn* gameon = nullptr;
				GameObject* obj = m_gobjects.getByPosition(x);
				if(obj != nullptr){
					gameon = obj->detach(cls);
				}
				PrimitiveList<GameOn>* list = components.getByPointer(cls);
				if(list != nullptr){
					list->removeByPointer(gameon);
				}
				if(gameon == nullptr){
					return;
				}
				delete gameon;
			}
		}
		
		
		GameOn* removeEntityComponent(int entity, cppObjectClass* cls){
			GameManagerLog("GameManager", "removeEntityComponent",  "println", "");
			GameOn* gameon = nullptr;
			GameObject* obj = m_gobjects.getByPosition(entity);
			if(obj != nullptr){
				gameon = obj->detach(cls);
			}
			PrimitiveList<GameOn>* list = components.getByPointer(cls);
			if(list != nullptr){
				list->removeByPointer(gameon);
			}
			return gameon;
		}
		
		GameOn* removeGameObjectComponent(GameObject* obj, cppObjectClass* cls){
			GameManagerLog("GameManager", "removeGameObjectComponent",  "println", "");
			GameOn* gameon = nullptr;
			if(obj != nullptr){
				gameon = obj->detach(cls);
			}
			PrimitiveList<GameOn>* list = components.getByPointer(cls);
			if(list != nullptr){
				list->removeByPointer(gameon);
			}
			return gameon;
		}
		
		
		void deleteEntityComponent(int entity, cppObjectClass* cls){
			GameManagerLog("GameManager", "deleteEntityComponent",  "println", "");
			GameObject* obj = m_gobjects.getByPosition(entity);
			if(obj == nullptr){
				return;
			}
			
			GameOn* gon = obj->detach(cls);
			PrimitiveList<GameOn>* list = components.getByPointer(cls);
			if(list != nullptr){
				list->removeByPointer(gon);
			}
			if(gon != nullptr){
				delete gon;
			}
		}
		
		void deleteGameObjectComponent(GameObject* obj, cppObjectClass* cls){
			GameManagerLog("GameManager", "deleteGameObjectComponent",  "println", "");
			if(obj == nullptr){
				return;
			}
			
			GameOn* gon = obj->detach(cls);
			PrimitiveList<GameOn>* list = components.getByPointer(cls);
			if(list != nullptr){
				list->removeByPointer(gon);
			}
			if(gon != nullptr){
				delete gon;
			}
		}
		
		
		void deleteEntityComponents(int entity){
			GameManagerLog("GameManager", "deleteEntityComponents",  "println", "");
			GameObject* obj = m_gobjects.getByPosition(entity);
			if(obj == nullptr){
				return;
			}
			
			PrimitiveList<GameOn>& list = obj->getChilds();
			PrimitiveList<cppObjectClass> classT;
			for(int x = 0; x < list.getPosition(); x++){
				GameOn* gon = list.getByPosition(x);
				classT.addPointer(gon->getClass());
			}
			for(int x = 0; x < classT.getPosition(); x++){
				cppObjectClass* cls = classT.getByPosition(x);
				PrimitiveList<GameOn>* list2 = components.getByPointer(cls);
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
		
		void deleteGameObjectComponents(GameObject* obj){
			GameManagerLog("GameManager", "deleteGameObjectComponents",  "println", "");
			if(obj == nullptr){
				return;
			}
			
			PrimitiveList<GameOn>& list = obj->getChilds();
			PrimitiveList<cppObjectClass> classT;
			for(int x = 0; x < list.getPosition(); x++){
				GameOn* gon = list.getByPosition(x);
				classT.addPointer(gon->getClass());
			}
			for(int x = 0; x < classT.getPosition(); x++){
				cppObjectClass* cls = classT.getByPosition(x);
				PrimitiveList<GameOn>* list2 = components.getByPointer(cls);
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
		
		
		void deleteEntityComponentRequest(int entity, cppObjectClass* cls){
			GameManagerLog("GameManager", "deleteEntityComponentRequest",  "println", "");
			GameObject* obj = m_gobjects.getByPosition(entity);
			if(obj == nullptr){
				return;
			}
			deleteRequest.addPointers(obj,cls);
		}
		
		void deleteGameObjectComponentRequest(GameObject* obj, cppObjectClass* cls){
			GameManagerLog("GameManager", "deleteGameObjectComponentRequest",  "println", "");
			if(!m_gobjects.containByPointer(obj)){
				return;
			}
			deleteRequest.addPointers(obj,cls);
		}
		
		
		void removeEntityComponent(int entity, GameOn* component){
			GameManagerLog("GameManager", "removeEntityComponent",  "println", "");
			GameObject* obj = m_gobjects.getByPosition(entity);
			if(obj != nullptr){
				obj->detach(component);
			}
			PrimitiveList<GameOn>* list = components.getByPointer(component->getClass());
			if(list != nullptr){
				list->removeByPointer(component);
			}
		}
		
		void removeGameObjectComponent(GameObject* obj, GameOn* component){
			GameManagerLog("GameManager", "removeGameObjectComponent",  "println", "");
			if(obj != nullptr){
				 obj->detach(component);
			}
			PrimitiveList<GameOn>* list = components.getByPointer(component->getClass());
			if(list != nullptr){
				list->removeByPointer(component);
			}
		}
		
		
		void deleteEntityComponent(int entity, GameOn* component){
			GameManagerLog("GameManager", "deleteEntityComponent",  "println", "");
			if(component != nullptr){
				GameObject* obj = m_gobjects.getByPosition(entity);
				if(obj == nullptr){
					return;
				}
				obj->detach(component);
				PrimitiveList<GameOn>* list = components.getByPointer(component->getClass());
				if(list != nullptr){
					list->removeByPointer(component);
				}
				delete component;
			}
		}
		
		void deleteGameObjectComponent(GameObject* obj, GameOn* component){
			GameManagerLog("GameManager", "deleteGameObjectComponent",  "println", "");
			if(component == nullptr){
				return;
			}
			if(obj == nullptr){
				return;
			}
			if(!m_gobjects.containByPointer(obj)){
				return;
			}
			obj->detach(component);
			PrimitiveList<GameOn>* list = components.getByPointer(component->getClass());
			if(list != nullptr){
				list->removeByPointer(component);
			}
			delete component;
		}
		
		
		// GameOn* removeComponentIterating(Iterator& i, List<GameOn>* listComponents){
			// GameManagerLog("GameManager", "removeComponentIterating",  "println", "");
			// if(listComponents != nullptr){
				// GameOn* gameon = listComponents->getPointer(i);
				// listComponents->remove(i);
				// GameObject* obj = m_gobjects.getByPosition(gameon->getId());
				// if(obj != nullptr){
					// obj->detach(gameon);
				// }
				// i.last();
				// return gameon;
			// }
			// return nullptr;
		// }
		
		
		// void deleteComponentIterating(Iterator& i, List<GameOn>* listComponents){
			// GameManagerLog("GameManager", "deleteComponentIterating",  "println", "");
			// if(listComponents != nullptr){
				// GameOn* gameon = listComponents->getPointer(i);
				// listComponents->remove(i);
				// GameObject* obj = m_gobjects.getByPosition(gameon->getId());
				// if(obj == nullptr){
					// return;
				// }
				// obj->detach(gameon);
				// delete gameon;
				// i.last();
			// }
		// }
		
		
		//resets the list and it deletes the components from there entities
		void deleteComponentsFromList(PrimitiveList<GameOn>* listComponents){
			GameManagerLog("GameManager", "deleteComponentsFromList",  "println", "");
			if(listComponents == nullptr){
				return;
			}
			if(listComponents->isEmpty()){
				return;
			}
			cppObjectClass* s = components.getKeyByPointer(listComponents);
			if(s == nullptr){
				return;
			}
			for(int x = 0; x > m_gobjects.getPosition(); x++){
				GameObject* obj = m_gobjects.getByPosition(x);
				PrimitiveList<GameOn>& list = obj->getChilds();
				for(int x = 0; x < list.getPosition(); x++){
					GameOn* gameon = list.getByPosition(x);
					if(gameon->getClass() == s){
						list.removeDeleteByPosition(x);
						x--;
					}
				}
			}
			listComponents->reset();
		}
		
		
		int getEntitySize(){
			GameManagerLog("GameManager", "getEntitySize",  "println", "");
			return m_gobjects.getPosition();
		}
		
		int getComponentSize(int entity){
			GameManagerLog("GameManager", "getComponentSize",  "println", "");
			if(m_gobjects.getByPosition(entity)==nullptr){
				return -1;
			}
			GameObject* obj = m_gobjects.getByPosition(entity);
			if(obj == nullptr){
				return -1;
			}
			PrimitiveList<GameOn>& list = obj->getChilds();
			return list.getPosition();
		}
		
		
		void rearrange(){
			GameManagerLog("GameManager", "rearrange",  "println", "");
			for(int x = 0; x < m_gobjects.getPosition(); x++){
				GameOn* gameon = m_gobjects.getByPosition(x);
				gameon->setId(x);
			}
		}
		
		
		cppObjectClass* getClass(){
			return Class<GameManager>::classType;
		}
		
		Note toNote(){
			return Note("GameManager") + Note(m_gobjects.getSize());
		}
		
		bool equal(cppObject *b){
			if(b == this){
				return true;
			}
			if(b->getClass() == this->getClass()){
				return true;
			}
			return false;
		}
		
		GameManager* clone(){
			return new GameManager();
		}
		
		
		void update(float tpc){
			// Serial.println("start GameManager update");
			for(int txp = 0; txp < this->addRequest.getPosition(); txp++){
				GameManagerLog("GameManager", "update",  "println", "addRequest");
				this->addGameObjectComponent(this->addRequest.getKeyByPosition(txp), this->addRequest.getByPosition(txp));
			}
			this->addRequest.reset();
			
			for(int txp = 0; txp < this->deleteRequest.getPosition(); txp++){
				GameManagerLog("GameManager", "update",  "println", "deleteRequest");
				this->deleteGameObjectComponent(this->deleteRequest.getKeyByPosition(txp), this->deleteRequest.getByPosition(txp));
			}
			this->deleteRequest.resetDeleteValue();
			
			for(int txp = 0; txp < this->deleteERequest.getPosition(); txp++){
				GameManagerLog("GameManager", "update",  "println", "deleteERequest");
				this->deleteGameObject(this->deleteERequest.getByPosition(txp));
			}
			this->deleteERequest.reset();
			
			if(deleteAllE){
				GameManagerLog("GameManager", "update",  "println", "deleteAllE");
				deleteAllE = false;
				this->deleteAllEntities();
			}
			// Serial.println("end GameManager update");
		}
		
	protected:
		bool deleteAllE = false;
		PrimitiveList<GameObject> deleteERequest;
		PrimitiveMap<GameObject,GameOn> addRequest;
		PrimitiveMap<GameObject,cppObjectClass> deleteRequest;
		PrimitiveMap<cppObjectClass,PrimitiveList<GameOn>> components;
		PrimitiveList<GameObject> m_gobjects;
};

}

#endif