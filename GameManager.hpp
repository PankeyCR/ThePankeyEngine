/*
*	Component is added first to the GameObject then to the Component-Class-List
*	Component is removed first fromthe GameObject then to the Component-Class-List
*/
#ifndef CONFIGURATION_GameManager_hpp
#define CONFIGURATION_GameManager_hpp

	#include "ame_Enviroment.hpp"

	#if defined(DISABLE_GameManager)
		#define GameManager_hpp

		#define IMPLEMENTATION_GameManager
		#define IMPLEMENTING_GameManager
	#else
		#if defined(DISABLE_IMPLEMENTATION_GameManager)
			#define IMPLEMENTATION_GameManager
			#define IMPLEMENTING_GameManager
		#endif
	#endif
#endif

#ifndef GameManager_hpp
#define GameManager_hpp
#define GameManager_AVAILABLE

#ifndef DISABLE_IMPLEMENTATION_GameManager
	#define IMPLEMENTATION_GameManager IMPLEMENTATION(public GameManager)
	#define IMPLEMENTING_GameManager IMPLEMENTING(public GameManager)
#endif

#include "cppObject.hpp"
#include "BaseAppState.hpp"
#include "PrimitiveMap.hpp"
#include "PrimitiveList.hpp"

#ifdef GameManager_LogApp
	#include "ame_Logger_config.hpp"
	#include "ame_Logger.hpp"

	#define GameManagerLog(location,method,type,mns) ame_Log(this,location,"GameManager",method,type,mns)
	#define const_GameManagerLog(location,method,type,mns)
#else
	#ifdef GameManager_LogDebugApp
		#include "ame_Logger_config.hpp"
		#include "ame_Logger.hpp"

		#define GameManagerLog(location,method,type,mns) ame_LogDebug(this,location,"GameManager",method,type)
		#define const_GameManagerLog(location,method,type,mns)
	#else
		#define GameManagerLog(location,method,type,mns)
		#define const_GameManagerLog(location,method,type,mns)
	#endif
#endif

namespace ame{

template<class ENTITY, class COMPONENT>
class GameManager IMPLEMENTATION_BaseAppState {
    public:		
		GameManager(){
			GameManagerLog(ame_Log_StartMethod, "Constructor",  "println", "");
			GameManagerLog(ame_Log_StartMethod, "Constructor",  "println", "");
		}
		virtual ~GameManager(){
			GameManagerLog(ame_Log_StartMethod, "Destructor",  "println", "");
			GameManagerLog(ame_Log_StartMethod, "Destructor",  "println", "");
		}
		
		virtual int createEntity(ENTITY* a_obj){
			GameManagerLog(ame_Log_StartMethod, "createEntity",  "println", "with parameters");
			if(a_obj == nullptr){
				GameManagerLog(ame_Log_EndMethod, "createEntity",  "println", "a_obj == nullptr");
				return -1;
			}
			GameManagerLog(ame_Log_Statement, "createEntity",  "println", Note("id ") + Note(m_game_objects.getPosition()));
			a_obj->setId(m_game_objects.getPosition());
			m_game_objects.addPointer(a_obj);
			GameManagerLog(ame_Log_EndMethod, "createEntity",  "println", "");
			return a_obj->getId();
		}
		
		virtual ENTITY* createGameObject(ENTITY* a_obj){
			GameManagerLog(ame_Log_StartMethod, "createGameObject",  "println", "with parameters");
			if(a_obj == nullptr){
				GameManagerLog(ame_Log_StartMethod, "createGameObject",  "println", "a_obj == nullptr");
				return nullptr;
			}
			GameManagerLog(ame_Log_Statement, "createGameObject",  "println", Note("id ") + Note(m_game_objects.getPosition()));
			a_obj->setId(m_game_objects.getPosition());
			m_game_objects.addPointer(a_obj);
			GameManagerLog(ame_Log_EndMethod, "createGameObject",  "println", "");
			return a_obj;
		}
		
		virtual int createEntity(){
			GameManagerLog(ame_Log_StartMethod, "createEntity",  "println", "no parameters");
			GameManagerLog(ame_Log_Statement, "createEntity",  "println", Note("id ") + Note(m_game_objects.getPosition()));
			ENTITY* i_obj = new ENTITY();
			i_obj->setId(m_game_objects.getPosition());
			m_game_objects.addPointer(i_obj);
			GameManagerLog(ame_Log_EndMethod, "createEntity",  "println", "");
			return i_obj->getId();
		}
		
		virtual ENTITY* createGameObject(){
			GameManagerLog(ame_Log_StartMethod, "createGameObject",  "println", "no parameters");
			GameManagerLog(ame_Log_StartMethod, "createGameObject",  "println", Note("id ") + Note(m_game_objects.getPosition()));
			ENTITY* i_obj = new ENTITY();
			i_obj->setId(m_game_objects.getPosition());
			m_game_objects.addPointer(i_obj);
			GameManagerLog(ame_Log_EndMethod, "createGameObject",  "println", "");
			return i_obj;
		}
		
		
		virtual void deleteEntity(int a_entity){
			GameManagerLog(ame_Log_StartMethod, "deleteEntity",  "println", Note("id ") + Note(entity));
			ENTITY* i_obj = m_game_objects.getByPosition(a_entity);
			if(i_obj == nullptr){
				GameManagerLog(ame_Log_StartMethod, "deleteEntity",  "println", "i_obj == nullptr");
				return;
			}
			PrimitiveList<COMPONENT>& i_objChilds = i_obj->getChilds();
			GameManagerLog(ame_Log_StartMethod, "deleteEntity",  "println", "start to look for the childs on the component lists");
			for(int x = 0; x < i_objChilds.getPosition(); x++){
				COMPONENT* i_child = i_objChilds.getByPosition(x);
				cppObjectClass* i_classT = i_child->getClass();
				PrimitiveList<COMPONENT>* i_list = m_components.getByPointer(i_classT);
				if(i_list == nullptr){
					GameManagerLog(ame_Log_StartMethod, "deleteEntity",  "println", "list == nullptr");
					continue;
				}
				GameManagerLog(ame_Log_StartMethod, "deleteEntity",  "println", "removing from the component list");
				i_list->removeByPointer(i_child);
			}
			GameManagerLog(ame_Log_StartMethod, "deleteEntity",  "println", "removing-deleting from the GameObjects list");
			m_game_objects.removeDeleteByPosition(a_entity);
			GameManagerLog(ame_Log_EndMethod, "deleteEntity",  "println", "");
		}
		
		virtual void deleteGameObject(ENTITY* a_obj){
			GameManagerLog(ame_Log_StartMethod, "deleteGameObject",  "println", "");
			if(!m_game_objects.containByPointer(a_obj)){
				GameManagerLog(ame_Log_StartMethod, "deleteGameObject",  "println", "GameObjects dont contains obj");
				return;
			}
			PrimitiveList<COMPONENT>& i_objChilds = a_obj->getChilds();
			GameManagerLog(ame_Log_StartMethod, "deleteGameObject",  "println", "start to look for the childs on the component lists");
			for(int x = 0; x < i_objChilds.getPosition(); x++){
				COMPONENT* i_child = i_objChilds.getByPosition(x);
				cppObjectClass* i_cls = i_child->getClass();
				PrimitiveList<COMPONENT>* i_list = m_components.getByPointer(i_cls);
				if(i_list == nullptr){
					GameManagerLog(ame_Log_StartMethod, "deleteGameObject",  "println", "list == nullptr");
					continue;
				}
				GameManagerLog(ame_Log_StartMethod, "deleteGameObject",  "println", "removing from the component list");
				i_list->removeByPointer(i_child);
			}
			GameManagerLog(ame_Log_StartMethod, "deleteGameObject",  "println", "removing-deleting from the GameObjects list");
			m_game_objects.removeDeleteByPointer(a_obj);
			GameManagerLog(ame_Log_EndMethod, "deleteEntity",  "println", "");
		}
		
		virtual void deleteAllEntities(){
			GameManagerLog(ame_Log_StartMethod, "deleteAllEntities",  "println", "");
			GameManagerLog(ame_Log_StartMethod, "deleteAllEntities",  "println", Note("total entities ") + Note(components.getPosition()));
			for(int x = 0; x < m_components.getPosition(); x++){
				List<COMPONENT>* i_childs = m_components.getByPosition(x);
				i_childs->reset();
			}
			m_game_objects.resetDelete();
			GameManagerLog(ame_Log_EndMethod, "deleteEntity",  "println", "");
		}
		
		
		virtual void requestDeleteEntity(int a_entity){
			GameManagerLog(ame_Log_StartMethod, "deleteEntityRequest",  "println", "adding entity to the delete request list");
			GameManagerLog(ame_Log_StartMethod, "deleteEntityRequest",  "println", Note("id ") + Note(a_entity));
			ENTITY* i_obj = m_game_objects.getByPosition(a_entity);
			if(i_obj == nullptr){
				return;
			}
			m_deleteERequest.addPointer(i_obj);
			GameManagerLog(ame_Log_EndMethod, "deleteEntity",  "println", "");
		}
		
		virtual void deleteGameObjectRequest(ENTITY* a_obj){
			GameManagerLog(ame_Log_StartMethod, "deleteGameObjectRequest",  "println", "");
			if(!m_game_objects.containByPointer(a_obj)){
				return;
			}
			m_deleteERequest.addPointer(a_obj);
			GameManagerLog(ame_Log_EndMethod, "deleteEntity",  "println", "");
		}
		
		virtual void deleteAllEntitiesRequest(){
			GameManagerLog(ame_Log_StartMethod, "deleteAllEntitiesRequest",  "println", "");
			m_deleteAllE = true;
			GameManagerLog(ame_Log_EndMethod, "deleteEntity",  "println", "");
		}
		
		
		virtual int getEntity(cppObjectClass* a_cls){
			GameManagerLog(ame_Log_StartMethod, "getEntity",  "println", "");
			for(int x = 0; x < m_game_objects.getPosition(); x++){
				ENTITY* i_obj = m_game_objects.getByPosition(x);
				if(i_obj->getClass() == a_cls){
					GameManagerLog(ame_Log_EndMethod, "deleteEntity",  "println", "");
					return i_obj->getId();
				}
			}
			GameManagerLog(ame_Log_EndMethod, "deleteEntity",  "println", "");
			return -1;
		}
		
		virtual ENTITY* getGameObject(cppObjectClass* a_cls){
			GameManagerLog(ame_Log_StartMethod, "getGameObject",  "println", "");
			for(int x = 0; x < m_game_objects.getPosition(); x++){
				ENTITY* i_obj = m_game_objects.getByPosition(x);
				if(i_obj->getClass() == a_cls){
					GameManagerLog(ame_Log_EndMethod, "deleteEntity",  "println", "");
					return i_obj;
				}
			}
			GameManagerLog(ame_Log_EndMethod, "deleteEntity",  "println", "");
			return nullptr;
		}
		
		virtual int getEntity(ENTITY* a_obj){
			GameManagerLog(ame_Log_StartMethod, "getEntity",  "println", Note(a_obj->getId()));
			if(m_game_objects.containByPointer(a_obj)){
				GameManagerLog(ame_Log_EndMethod, "getEntity",  "println", "");
				return a_obj->getId();
			}
			GameManagerLog(ame_Log_EndMethod, "getEntity",  "println", "");
			return -1;
		}
		
		virtual ENTITY* getGameObject(int a_entity){
			GameManagerLog(ame_Log_StartMethod, "getGameObject",  "println", Note(a_entity));
			GameManagerLog(ame_Log_EndMethod, "getGameObject",  "println", "");
			return m_game_objects.getByPosition(a_entity);
		}
		
		
		virtual int getFirstEntity(){
			GameManagerLog(ame_Log_StartMethod, "getFirstEntity",  "println", "");
			int i_position = m_game_objects.getPosition();
			if(i_position <= 0){
				GameManagerLog(ame_Log_EndMethod, "getFirstEntity",  "println", "");
				return -1;
			}
			GameManagerLog(ame_Log_EndMethod, "getFirstEntity",  "println", "");
			return 0;
		}
		
		virtual ENTITY* getFirstGameObject(){
			GameManagerLog(ame_Log_StartMethod, "getFirstGameObject",  "println", "");
			int i_position = m_game_objects.getPosition();
			if(i_position <= 0){
				GameManagerLog(ame_Log_EndMethod, "getFirstGameObject",  "println", "");
				return nullptr;
			}
			GameManagerLog(ame_Log_EndMethod, "getFirstGameObject",  "println", "");
			return m_game_objects.getByPosition(0);
		}
		
		virtual int getLastEntity(){
			GameManagerLog(ame_Log_StartMethod, "getLastEntity",  "println", "");
			int i_position = m_game_objects.getPosition();
			if(i_position <= 0){
				GameManagerLog(ame_Log_EndMethod, "getLastEntity",  "println", "");
				return -1;
			}
			GameManagerLog(ame_Log_EndMethod, "getLastEntity",  "println", "");
			return i_position-1;
		}
		
		virtual ENTITY* getLastGameObject(){
			GameManagerLog(ame_Log_StartMethod, "getLastGameObject",  "println", "");
			int i_position = m_game_objects.getPosition();
			if(i_position <= 0){
				GameManagerLog(ame_Log_EndMethod, "getLastGameObject",  "println", "");
				return nullptr;
			}
			GameManagerLog(ame_Log_EndMethod, "getLastGameObject",  "println", "");
			return m_game_objects.getByPosition(i_position-1);
		}
		
		/*
		*	Adds a component to a  entity
		*/
		virtual void addComponentToEntity(int a_entity, COMPONENT* a_component){
			GameManagerLog(ame_Log_StartMethod, "addEntityComponent",  "println", "");
			ENTITY* i_obj = m_game_objects.getByPosition(a_entity);
			if(i_obj == nullptr || a_component == nullptr){
				GameManagerLog(ame_Log_StartMethod, "addEntityComponent",  "println", "no object with these entity id");
				return;
			}
			PrimitiveList<COMPONENT>* i_list = m_components.getByPointer(a_component->getClass());
			if(i_list == nullptr){
				GameManagerLog(ame_Log_StartMethod, "addEntityComponent",  "println", "creating list for the component class");
				i_list = new PrimitiveList<COMPONENT>();
				i_list.setOwner(false);
				m_components.addPointers(a_component->getClass(), i_list);
			}
			if(!i_list->containByPointer(a_component)){
				GameManagerLog(ame_Log_StartMethod, "addEntityComponent",  "println", "adding component to the list");
				i_list->addPointer(a_component);
			}
			PrimitiveList<COMPONENT>& i_list_childs = i_obj->getChilds();
			if(!i_list_childs.containByPointer(a_component)){
				GameManagerLog(ame_Log_StartMethod, "addEntityComponent",  "println", "adding component to the gameobject");
				i_obj->attach(a_component);
			}
			GameManagerLog(ame_Log_EndMethod, "addEntityComponent",  "println", "");
		}
		
		virtual void addComponentToGameObject(ENTITY* a_obj, COMPONENT* a_component){
			GameManagerLog(ame_Log_StartMethod, "addGameObjectComponent",  "println", "");
			if(a_obj == nullptr){
				GameManagerLog(ame_Log_EndMethod, "addGameObjectComponent",  "println", "");
				return;
			}
			if(!m_game_objects.containByPointer(a_obj)){
				GameManagerLog(ame_Log_EndMethod, "addGameObjectComponent",  "println", "");
				return;
			}
			if(a_obj->getChilds().containByPointer(a_component)){
				GameManagerLog(ame_Log_EndMethod, "addGameObjectComponent",  "println", "");
				return;
			}
			a_obj->attach(a_component);
			
			PrimitiveList<COMPONENT>* i_list = m_components.getByPointer(a_component->getClass());
			if(i_list == nullptr){
				i_list = new PrimitiveList<COMPONENT>();
				i_list->setOwner(false);
				m_components.addPointers(a_component->getClass(), i_list);
			}
			i_list->addPointer(a_component);
			GameManagerLog(ame_Log_EndMethod, "addGameObjectComponent",  "println", "");
		}
		
		
		virtual void requestAddComponentToEntity(int a_entity, COMPONENT* a_component){
			GameManagerLog(ame_Log_StartMethod, "requestAddComponentToEntity",  "println", "");
			ENTITY* i_obj = m_game_objects.getByPosition(a_entity);
			if(i_obj == nullptr){
				GameManagerLog(ame_Log_EndMethod, "requestAddComponentToEntity",  "println", "");
				return;
			}
			m_addRequest.addPointers(i_obj, a_component);
			GameManagerLog(ame_Log_EndMethod, "requestAddComponentToEntity",  "println", "");
		}
		
		virtual void requestAddComponentToGameObject(ENTITY* a_obj, COMPONENT* a_component){
			GameManagerLog(ame_Log_StartMethod, "requestAddComponentToGameObject",  "println", "");
			if(!m_game_objects.containByPointer(a_obj)){
				GameManagerLog(ame_Log_EndMethod, "requestAddComponentToGameObject",  "println", "");
				return;
			}
			m_addRequest.addPointers(a_obj, a_component);
			GameManagerLog(ame_Log_EndMethod, "requestAddComponentToGameObject",  "println", "");
		}
		
		virtual bool containComponent(cppObjectClass* a_cls){
			GameManagerLog(ame_Log_StartMethod, "containComponent",  "println", "");
			if(a_cls == nullptr){
				GameManagerLog(ame_Log_EndMethod, "containComponent",  "println", "");
				return false;
			}
			for(int x = 0; x < m_game_objects.getPosition(); x++){
				ENTITY* f_obj = m_game_objects.getByPosition(x);
				if(f_obj == nullptr){
					GameManagerLog(ame_Log_EndMethod, "containComponent",  "println", "");
					continue;
				}
				PrimitiveList<COMPONENT>& f_objChilds = f_obj->getChilds();
				for(int y = 0; y < f_objChilds.getPosition(); y++){
					COMPONENT* ff_child = f_objChilds.getByPosition(y);
					if(ff_child == nullptr){
						GameManagerLog(ame_Log_EndMethod, "containComponent",  "println", "");
						continue;
					}
					if(ff_child->getClass() == a_cls){
						GameManagerLog(ame_Log_EndMethod, "containComponent",  "println", "");
						return true;
					}
				}
			}
			GameManagerLog(ame_Log_EndMethod, "containComponent",  "println", "");
			return false;
		}
		
		virtual bool containEntityComponent(int a_entity, cppObjectClass* a_cls){
			GameManagerLog(ame_Log_StartMethod, "containEntityComponent",  "println", "");
			List<COMPONENT>* i_list = getAllComponentsFromEntity(a_entity);
			
			if(i_list == nullptr){
				GameManagerLog(ame_Log_EndMethod, "containEntityComponent",  "println", "");
				return false;
			}
			
			for(int x = 0; x < i_list->getPosition(); x++){
				COMPONENT* f_child = i_list->getByPosition(x);
				if(f_child == nullptr){
					continue;
				}
				if(f_child->getClass() == a_cls){
					GameManagerLog(ame_Log_EndMethod, "containEntityComponent",  "println", "");
					return true;
				}
			}
			GameManagerLog(ame_Log_EndMethod, "containEntityComponent",  "println", "");
			return false;
		}
		
		template<class... s>
		bool containEntityComponents(int a_entity, s... componentClass){
			PrimitiveList<Note> i_classNs;
			i_classNs.addPack(componentClass...);
			if(i_classNs.isEmpty()){
				GameManagerLog(ame_Log_EndMethod, "containEntityComponents",  "println", "");
				return false;
			}
			for(int x = 0; x < i_classNs.getPosition(); x++){
				cppObjectClass* f_cls = i_classNs.getByPosition(x);
				if(!this->containEntityComponent(a_entity, f_cls)){
					GameManagerLog(ame_Log_EndMethod, "containEntityComponents",  "println", "");
					return false;
				}
			}
			GameManagerLog(ame_Log_EndMethod, "containEntityComponents",  "println", "");
			return true;
		}
		
		virtual bool containGameObjectComponent(ENTITY* a_obj, cppObjectClass* a_cls){
			GameManagerLog(ame_Log_StartMethod, "containGameObjectComponent",  "println", "");
			if(a_obj == nullptr){
				GameManagerLog(ame_Log_EndMethod, "containGameObjectComponent",  "println", "");
				return false;
			}
			PrimitiveList<COMPONENT>& i_list = a_obj->getChilds();
			
			for(int x = 0; x < i_list.getPosition(); x++){
				COMPONENT* f_component = i_list.getByPosition(x);
				if(f_component->getClass() == a_cls){
					GameManagerLog(ame_Log_EndMethod, "containGameObjectComponent",  "println", "");
					return true;
				}
			}
			GameManagerLog(ame_Log_EndMethod, "containGameObjectComponent",  "println", "");
			return false;
		}
		
		virtual bool isEmpty(){
			GameManagerLog(ame_Log_StartMethod, "isEmpty",  "println", "");
			GameManagerLog(ame_Log_EndMethod, "isEmpty",  "println", "");
			return m_game_objects.isEmpty();
		}
		
		
		virtual COMPONENT* getEntityComponent(int a_entity, int a_index){
			GameManagerLog(ame_Log_StartMethod, "getEntityComponent",  "println", "");
			ENTITY* i_obj = m_game_objects.getByPosition(a_entity);
			if(i_obj == nullptr){
				GameManagerLog(ame_Log_EndMethod, "deleteEntity",  "println", "");
				return nullptr;
			}
			PrimitiveList<COMPONENT>& i_list = i_obj->getChilds();
			GameManagerLog(ame_Log_EndMethod, "deleteEntity",  "println", "");
			return i_list.getByPosition(a_index);
		}
		
		virtual COMPONENT* getEntityComponent(int a_entity, cppObjectClass* a_cls){
			GameManagerLog(ame_Log_StartMethod, "getEntityComponent",  "println", "");
			List<COMPONENT>* i_list = this->getAllComponentsFromEntity(a_entity);
			
			if(i_list == nullptr){
				GameManagerLog(ame_Log_EndMethod, "getEntityComponent",  "println", "");
				return nullptr;
			}
			
			for(int x = 0; x < i_list->getPosition(); x++){
				COMPONENT* f_child = i_list->getByPosition(x);
				if(f_child == nullptr){
					continue;
				}
				if(f_child->getClass() == a_cls){
				GameManagerLog(ame_Log_EndMethod, "getEntityComponent",  "println", "");
					return f_child;
				}
			}
			GameManagerLog(ame_Log_EndMethod, "getEntityComponent",  "println", "");
			return nullptr;
		}
		
		virtual COMPONENT* getGameObjectComponent(ENTITY* a_obj, cppObjectClass* a_cls){
			GameManagerLog(ame_Log_StartMethod, "getGameObjectComponent",  "println", "");
			if(a_obj == nullptr){
				GameManagerLog(ame_Log_EndMethod, "getGameObjectComponent",  "println", "");
				return nullptr;
			}
			PrimitiveList<COMPONENT>& i_list = a_obj->getChilds();
			
			for(int x = 0; x < i_list.getPosition(); x++){
				COMPONENT* f_child = i_list.getByPosition(x);
				if(f_child == nullptr){
					continue;
				}
				if(f_child->getClass() == a_cls){
					GameManagerLog(ame_Log_EndMethod, "getGameObjectComponent",  "println", "");
					return f_child;
				}
			}
			GameManagerLog(ame_Log_EndMethod, "getGameObjectComponent",  "println", "");
			return nullptr;
		}
		
		//returns the first component founded on the gameobjects list searched by the componentClassName
		virtual COMPONENT* getComponent(cppObjectClass* a_cls){
			GameManagerLog(ame_Log_StartMethod, "getComponent",  "println", "");
			for(int x = 0; x < m_game_objects.getPosition(); x++){
				ENTITY* f_obj = m_game_objects.getByPosition(x);
				if(f_obj == nullptr){
					continue;
				}
				PrimitiveList<COMPONENT>& i_list = f_obj->getChilds();
				for(int xc = 0; xc < i_list.getPosition(); xc++){
					COMPONENT* ff_objGON = i_list.getByPosition(x);
					if(ff_objGON == nullptr){
						continue;
					}
					cppObjectClass* ff_objClass = ff_objGON->getClass();
					if(ff_objClass == a_cls){
						GameManagerLog(ame_Log_EndMethod, "getComponent",  "println", "");
						return ff_objGON;
					}
				}
			}
			GameManagerLog(ame_Log_EndMethod, "getComponent",  "println", "");
			return nullptr;
		}
		
		//returns the first entity founded with the componentClassName 
		virtual int getEntityByComponent(cppObjectClass* a_cls){
			GameManagerLog(ame_Log_StartMethod, "getEntityByComponent",  "println", "");
			for(int x = 0; x < m_game_objects.getPosition(); x++){
				ENTITY* f_obj = m_game_objects.getByPosition(x);
				if(f_obj == nullptr){
					GameManagerLog(ame_Log_EndMethod, "getEntityByComponent",  "println", "");
					return -1;
				}
				PrimitiveList<COMPONENT>& i_list = f_obj->getChilds();
				for(int y = 0; y < i_list.getPosition(); y++){
					COMPONENT* ff_component = i_list.getByPosition(y);
					if(ff_component == nullptr){
						GameManagerLog(ame_Log_EndMethod, "getEntityByComponent",  "println", "");
						return -1;
					}
					if(ff_component->getClass() == a_cls){
						GameManagerLog(ame_Log_EndMethod, "getEntityByComponent",  "println", "");
						return x;
					}
				}
			}
			GameManagerLog(ame_Log_EndMethod, "getEntityByComponent",  "println", "");
			return -1;
		}
		
		virtual int getEntityByComponent(COMPONENT* a_component){
			GameManagerLog(ame_Log_StartMethod, "getEntityByComponent",  "println", "");
			for(int x = 0; x < m_game_objects.getPosition(); x++){
				ENTITY* f_obj = m_game_objects.getByPosition(x);
				if(f_obj == nullptr){
					GameManagerLog(ame_Log_EndMethod, "getEntityByComponent",  "println", "");
					return -1;
				}
				PrimitiveList<COMPONENT>& i_list = f_obj->getChilds();
				for(int y = 0; y < i_list.getPosition(); y++){
					COMPONENT* ff_component = i_list.getByPosition(y);
					if(ff_component == nullptr){
						GameManagerLog(ame_Log_EndMethod, "getEntityByComponent",  "println", "");
						return -1;
					}
					if(ff_component == a_component){
						GameManagerLog(ame_Log_EndMethod, "getEntityByComponent",  "println", "");
						return x;
					}
				}
			}
			GameManagerLog(ame_Log_EndMethod, "getEntityByComponent",  "println", "");
			return -1;
		}

		template<class... s>
		int getEntityByComponents(s... a_componentClass){
			GameManagerLog(ame_Log_StartMethod, "getEntityByComponents",  "println", "");
			PrimitiveList<cppObjectClass> i_classNs;
			i_classNs.addPack(a_componentClass...);
			if(i_classNs.isEmpty()){
				GameManagerLog(ame_Log_EndMethod, "getEntityByComponents",  "println", "");
				return -1;
			}
			int i_ec = -1;
			for(int x = 0; x < i_classNs.getPosition(); x++){
				cppObjectClass* f_cls = i_classNs.getByPosition(x);
				i_ec = this->getEntityByComponent(f_cls);
				if(i_ec == -1){
					GameManagerLog(ame_Log_EndMethod, "getEntityByComponents",  "println", "");
					return -1;
				}
			}
			GameManagerLog(ame_Log_EndMethod, "getEntityByComponents",  "println", "");
			return i_ec;
		}
		
		virtual int getEntityComponentIndex(int a_entity, cppObjectClass* a_cls){
			GameManagerLog(ame_Log_StartMethod, "getEntityComponentIndex",  "println", "");
			List<COMPONENT>* i_list = getAllComponentsFromEntity(a_entity);
			
			if(i_list == nullptr){
				GameManagerLog(ame_Log_EndMethod, "getEntityComponentIndex",  "println", "");
				return -1;
			}
			
			for(int x = 0; x < i_list->getPosition(); x++){
				COMPONENT* f_child = i_list->getByPosition(x);
				if(f_child == nullptr){
					continue;
				}
				if(f_child->getClass() == a_cls){
					GameManagerLog(ame_Log_EndMethod, "getEntityComponentIndex",  "println", "");
					return x;
				}
			}
			GameManagerLog(ame_Log_EndMethod, "getEntityComponentIndex",  "println", "");
			return -1;
		}
		
		virtual int getGameObjectComponentIndex(ENTITY* a_obj, cppObjectClass* a_cls){
			GameManagerLog(ame_Log_StartMethod, "getGameObjectComponentIndex",  "println", "");
			if(a_obj == nullptr){
				GameManagerLog(ame_Log_EndMethod, "getGameObjectComponentIndex",  "println", "");
				return -1;
			}
			PrimitiveList<COMPONENT>& i_list = a_obj->getChilds();
			
			for(int x = 0; x < i_list.getPosition(); x++){
				COMPONENT* f_component = i_list.getByPosition(x);
				if(f_component == nullptr){
					continue;
				}
				if(f_component->getClass() == a_cls){
					GameManagerLog(ame_Log_EndMethod, "getGameObjectComponentIndex",  "println", "");
					return x;
				}
			}
			GameManagerLog(ame_Log_EndMethod, "getGameObjectComponentIndex",  "println", "");
			return -1;
		}

		//returns the position of the first component founded on the gameobjects list searched by the componentClassName
		virtual int getComponentEntity(cppObjectClass* a_cls){
			GameManagerLog(ame_Log_StartMethod, "getComponentEntity",  "println", "");
			for(int x = 0; x < m_game_objects.getPosition(); x++){
				ENTITY* f_obj = m_game_objects.getByPosition(x);
				if(f_obj == nullptr){
					continue;
				}
				PrimitiveList<COMPONENT>& i_list = f_obj->getChilds();
				for(int y = 0; y < i_list.getPosition(); y++){
					COMPONENT* ff_child = i_list.getByPosition(y);
					if(ff_child == nullptr){
						continue;
					}
					if(ff_child->getClass() == a_cls){
						GameManagerLog(ame_Log_EndMethod, "getComponentEntity",  "println", "");
						return y;
					}
				}
			}
			GameManagerLog(ame_Log_EndMethod, "getComponentEntity",  "println", "");
			return -1;
		}
		
		virtual List<COMPONENT>* getAllComponentsFromEntity(int a_entity){
			GameManagerLog(ame_Log_StartMethod, "getAllComponentsFromEntity",  "println", "");
			ENTITY* i_obj = m_game_objects.getByPosition(a_entity);
			if(i_obj != nullptr){
				GameManagerLog(ame_Log_EndMethod, "getAllComponentsFromEntity",  "println", "");
				return i_obj->getChildsPointer();
			}
			GameManagerLog(ame_Log_EndMethod, "getAllComponentsFromEntity",  "println", "");
			return nullptr;
		}
		
		virtual List<COMPONENT>* getAllComponentsFromGameObject(ENTITY* a_obj){
			GameManagerLog(ame_Log_StartMethod, "getAllComponentsFromGameObject",  "println", "");
			if(a_obj != nullptr){
			GameManagerLog(ame_Log_EndMethod, "getAllComponentsFromGameObject",  "println", "");
				return a_obj->getChildsPointer();
			}
			GameManagerLog(ame_Log_EndMethod, "getAllComponentsFromGameObject",  "println", "");
			return nullptr;
		}
		
		virtual PrimitiveList<COMPONENT>* getComponents(cppObjectClass* a_cls){
			GameManagerLog(ame_Log_StartMethod, "getComponents",  "println", "");
			PrimitiveList<COMPONENT>* i_list = m_components.getByPointer(a_cls);
			if(i_list == nullptr){
				i_list = new PrimitiveList<COMPONENT>(5, false, true);
				m_components.addPointers(a_cls, i_list);
			}
			GameManagerLog(ame_Log_EndMethod, "getComponents",  "println", "");
			return i_list;
		}
		
		virtual void deleteComponent(cppObjectClass* a_cls){
			GameManagerLog(ame_Log_StartMethod, "deleteComponent",  "println", "");
			for(int x= 0; x < m_game_objects.getPosition(); x++){
				COMPONENT* f_component = nullptr;
				ENTITY* f_obj = m_game_objects.getByPosition(x);
				if(f_obj == nullptr){
					continue;
				}
				f_component = f_obj->detach(a_cls);
				if(f_component == nullptr){
					continue;
				}
				PrimitiveList<COMPONENT>* f_list = m_components.getByPointer(a_cls);
				if(f_list == nullptr){
					continue;
				}
				f_list->removeByPointer(f_component);
				if(f_component == nullptr){
					continue;
				}
				delete f_component;
			}
			GameManagerLog(ame_Log_EndMethod, "deleteComponent",  "println", "");
		}
		
		/*
		*	removes the component from the gameobject and the component class list
		*/
		virtual COMPONENT* removeComponentFromEntity(int a_entity, cppObjectClass* a_cls){
			GameManagerLog(ame_Log_StartMethod, "removeComponentFromEntity",  "println", "");
			COMPONENT* i_component = nullptr;
			ENTITY* i_obj = m_game_objects.getByPosition(a_entity);
			if(i_obj == nullptr){
				GameManagerLog(ame_Log_EndMethod, "removeComponentFromEntity",  "println", "a_obj == nullptr");
				return nullptr;
			}

			i_component = i_obj->detach(a_cls);
			PrimitiveList<COMPONENT>* i_list = m_components.getByPointer(a_cls);
			if(i_list != nullptr){
				i_list->removeByPointer(i_component);
			}
			GameManagerLog(ame_Log_EndMethod, "removeComponentFromEntity",  "println", "");
			return i_component;
		}
		
		virtual COMPONENT* removeComponentFromGameObject(ENTITY* a_obj, cppObjectClass* a_cls){
			GameManagerLog(ame_Log_StartMethod, "removeComponentFromGameObject",  "println", "");
			COMPONENT* i_component = nullptr;
			if(a_obj == nullptr){
				GameManagerLog(ame_Log_EndMethod, "removeComponentFromGameObject",  "println", "a_obj == nullptr");
				return nullptr;
			}

			i_component = a_obj->detach(a_cls);
			PrimitiveList<COMPONENT>* i_list = m_components.getByPointer(a_cls);
			if(i_list != nullptr){
				i_list->removeByPointer(i_component);
			}
			GameManagerLog(ame_Log_EndMethod, "removeComponentFromGameObject",  "println", "");
			return i_component;
		}
		
		virtual void deleteComponentFromEntity(int a_entity, cppObjectClass* a_cls){
			GameManagerLog(ame_Log_StartMethod, "deleteComponentFromEntity",  "println", "");
			ENTITY* i_obj = m_game_objects.getByPosition(a_entity);
			if(i_obj == nullptr){
				GameManagerLog(ame_Log_EndMethod, "deleteEntity",  "println", "");
				return;
			}
			
			COMPONENT* i_component = i_obj->detach(a_cls);
			PrimitiveList<COMPONENT>* i_list = m_components.getByPointer(a_cls);
			if(i_list != nullptr){
				i_list->removeByPointer(i_component);
			}
			if(i_component != nullptr){
				delete i_component;
			}
			GameManagerLog(ame_Log_EndMethod, "deleteComponentFromEntity",  "println", "");
		}
		
		virtual void deleteComponentFromGameObject(ENTITY* a_obj, cppObjectClass* a_cls){
			GameManagerLog(ame_Log_StartMethod, "deleteGameObjectComponent",  "println", "");
			if(a_obj == nullptr){
				GameManagerLog(ame_Log_EndMethod, "deleteGameObjectComponent",  "println", "");
				return;
			}
			
			COMPONENT* i_component = a_obj->detach(a_cls);
			PrimitiveList<COMPONENT>* i_list = m_components.getByPointer(a_cls);
			if(i_list != nullptr){
				i_list->removeByPointer(i_component);
			}
			if(i_component != nullptr){
				delete i_component;
			}
			GameManagerLog(ame_Log_EndMethod, "deleteGameObjectComponent",  "println", "");
		}
		
		virtual void deleteAllComponentsFromEntity(int a_entity){
			GameManagerLog(ame_Log_StartMethod, "deleteAllComponentsFromEntity",  "println", "");
			ENTITY* i_obj = m_game_objects.getByPosition(a_entity);
			if(i_obj == nullptr){
				GameManagerLog(ame_Log_EndMethod, "deleteAllComponentsFromEntity",  "println", "");
				return;
			}
			
			PrimitiveList<COMPONENT>& i_list = i_obj->getChilds();
			PrimitiveList<cppObjectClass> i_classT;
			for(int x = 0; x < i_list.getPosition(); x++){
				COMPONENT* f_component = i_list.getByPosition(x);
				i_classT.addPointer(f_component->getClass());
			}
			for(int x = 0; x < i_classT.getPosition(); x++){
				cppObjectClass* f_cls = i_classT.getByPosition(x);
				PrimitiveList<COMPONENT>* f_list2 = m_components.getByPointer(f_cls);
				if(f_list2 == nullptr){
					continue;
				}
				COMPONENT* f_component = i_obj->detach(f_cls);
				if(f_component == nullptr){
					continue;
				}
				f_list2->removeByPointer(f_component);
				delete f_component;
			}
			GameManagerLog(ame_Log_EndMethod, "deleteAllComponentsFromEntity",  "println", "");
		}
		
		virtual void deleteAllComponentsFromGameObject(ENTITY* a_obj){
			GameManagerLog(ame_Log_StartMethod, "deleteAllComponentsFromGameObject",  "println", "");
			if(a_obj == nullptr){
				GameManagerLog(ame_Log_EndMethod, "deleteAllComponentsFromGameObject",  "println", "");
				return;
			}
			
			PrimitiveList<COMPONENT>& i_list = a_obj->getChilds();
			PrimitiveList<cppObjectClass> i_classT;
			for(int x = 0; x < i_list.getPosition(); x++){
				COMPONENT* f_component = i_list.getByPosition(x);
				i_classT.addPointer(f_component->getClass());
			}
			for(int x = 0; x < i_classT.getPosition(); x++){
				cppObjectClass* f_cls = i_classT.getByPosition(x);
				PrimitiveList<COMPONENT>* f_list2 = m_components.getByPointer(f_cls);
				if(f_list2 == nullptr){
					continue;
				}
				COMPONENT* f_component = a_obj->detach(f_cls);
				if(f_component == nullptr){
					continue;
				}
				f_list2->removeByPointer(f_component);
				delete f_component;
			}
			GameManagerLog(ame_Log_EndMethod, "deleteAllComponentsFromGameObject",  "println", "");
		}
		
		virtual void requestDeleteComponentFromEntity(int a_entity, cppObjectClass* a_cls){
			GameManagerLog(ame_Log_StartMethod, "requestDeleteComponentFromEntity",  "println", "");
			ENTITY* i_obj = m_game_objects.getByPosition(a_entity);
			if(i_obj == nullptr){
				GameManagerLog(ame_Log_EndMethod, "requestDeleteComponentFromEntity",  "println", "");
				return;
			}
			m_deleteRequest.addPointers(i_obj, a_cls);
			GameManagerLog(ame_Log_EndMethod, "requestDeleteComponentFromEntity",  "println", "");
		}
		
		void requestDeleteComponentFromGameObject(ENTITY* a_obj, cppObjectClass* a_cls){
			GameManagerLog(ame_Log_StartMethod, "requestDeleteComponentFromGameObject",  "println", "");
			if(!m_game_objects.containByPointer(a_obj)){
				GameManagerLog(ame_Log_EndMethod, "requestDeleteComponentFromGameObject",  "println", "");
				return;
			}
			m_deleteRequest.addPointers(a_obj, a_cls);
			GameManagerLog(ame_Log_EndMethod, "requestDeleteComponentFromGameObject",  "println", "");
		}
		
		virtual void removeComponentFromEntity(int a_entity, COMPONENT* a_component){
			GameManagerLog(ame_Log_StartMethod, "removeComponentFromEntity",  "println", "");
			ENTITY* i_obj = m_game_objects.getByPosition(a_entity);
			if(i_obj == nullptr){
				GameManagerLog(ame_Log_EndMethod, "removeComponentFromEntity",  "println", "");
				return;
			}
			
			i_obj->detach(a_component);
			PrimitiveList<COMPONENT>* i_list = m_components.getByPointer(a_component->getClass());
			if(i_list == nullptr){
				GameManagerLog(ame_Log_EndMethod, "removeComponentFromEntity",  "println", "");
				return;
			}

			i_list->removeByPointer(a_component);
			GameManagerLog(ame_Log_EndMethod, "removeComponentFromEntity",  "println", "");
		}
		
		virtual void removeComponentFromGameObject(ENTITY* a_obj, COMPONENT* a_component){
			GameManagerLog(ame_Log_StartMethod, "removeComponentFromGameObject",  "println", "");
			if(a_obj == nullptr){
				GameManagerLog(ame_Log_EndMethod, "removeComponentFromGameObject",  "println", "");
				return;
			}
			
			a_obj->detach(a_component);
			PrimitiveList<COMPONENT>* i_list = m_components.getByPointer(a_component->getClass());
			if(i_list == nullptr){
				GameManagerLog(ame_Log_EndMethod, "removeComponentFromGameObject",  "println", "");
				return;
			}

			i_list->removeByPointer(a_component);
			GameManagerLog(ame_Log_EndMethod, "removeComponentFromGameObject",  "println", "");
		}
		
		virtual void deleteComponentFromEntity(int a_entity, COMPONENT* a_component){
			GameManagerLog(ame_Log_StartMethod, "deleteComponentFromEntity",  "println", "");
			if(a_component == nullptr){
				return;
			}
			
			ENTITY* i_obj = m_game_objects.getByPosition(a_entity);
			if(i_obj == nullptr){
				GameManagerLog(ame_Log_EndMethod, "deleteComponentFromEntity",  "println", "");
				return;
			}
			i_obj->detach(a_component);
			PrimitiveList<COMPONENT>* i_list = m_components.getByPointer(a_component->getClass());
			if(i_list != nullptr){
				i_list->removeByPointer(a_component);
			}
			delete a_component;
			GameManagerLog(ame_Log_EndMethod, "deleteComponentFromEntity",  "println", "");
		}
		
		virtual void deleteComponentFromGameObject(ENTITY* a_obj, COMPONENT* a_component){
			GameManagerLog(ame_Log_StartMethod, "deleteGameObjectComponent",  "println", "");
			if(a_component == nullptr){
				GameManagerLog(ame_Log_EndMethod, "deleteGameObjectComponent",  "println", "");
				return;
			}
			if(a_obj == nullptr){
				GameManagerLog(ame_Log_EndMethod, "deleteGameObjectComponent",  "println", "");
				return;
			}
			if(!m_game_objects.containByPointer(a_obj)){
				GameManagerLog(ame_Log_EndMethod, "deleteGameObjectComponent",  "println", "");
				return;
			}
			a_obj->detach(a_component);
			PrimitiveList<COMPONENT>* i_list = m_components.getByPointer(a_component->getClass());
			if(i_list != nullptr){
				i_list->removeByPointer(a_component);
			}
			delete a_component;
			GameManagerLog(ame_Log_EndMethod, "deleteGameObjectComponent",  "println", "");
		}
		
		//resets the list and it deletes the components from there entities
		virtual void deleteComponentsFromList(PrimitiveList<COMPONENT>* a_list_components){
			GameManagerLog(ame_Log_StartMethod, "deleteComponentsFromList",  "println", "");
			if(a_list_components == nullptr){
				GameManagerLog(ame_Log_EndMethod, "deleteComponentsFromList",  "println", "");
				return;
			}
			if(a_list_components->isEmpty()){
				GameManagerLog(ame_Log_EndMethod, "deleteComponentsFromList",  "println", "");
				return;
			}
			cppObjectClass* i_class = m_components.getKeyByPointer(a_list_components);
			if(i_class == nullptr){
				GameManagerLog(ame_Log_EndMethod, "deleteComponentsFromList",  "println", "");
				return;
			}
			for(int x = 0; x > m_game_objects.getPosition(); x++){
				ENTITY* f_obj = m_game_objects.getByPosition(x);
				PrimitiveList<COMPONENT>& f_list = f_obj->getChilds();
				for(int x = 0; x < f_list.getPosition(); x++){
					COMPONENT* ff_component = f_list.getByPosition(x);
					if(ff_component->getClass() == i_class){
						f_list.removeDeleteByPosition(x);
						x--;
					}
				}
			}
			a_list_components->reset();
			GameManagerLog(ame_Log_EndMethod, "deleteComponentsFromList",  "println", "");
		}
		
		virtual int getEntitySize(){
			GameManagerLog(ame_Log_StartMethod, "getEntitySize",  "println", "");
			GameManagerLog(ame_Log_EndMethod, "deleteEntity",  "println", "");
			return m_game_objects.getPosition();
		}
		
		virtual int getComponentSize(int a_entity){
			GameManagerLog(ame_Log_StartMethod, "getComponentSize",  "println", "");
			if(m_game_objects.getByPosition(a_entity)==nullptr){
				GameManagerLog(ame_Log_EndMethod, "deleteEntity",  "println", "");
				return -1;
			}
			ENTITY* i_obj = m_game_objects.getByPosition(a_entity);
			if(i_obj == nullptr){
				GameManagerLog(ame_Log_EndMethod, "deleteEntity",  "println", "");
				return -1;
			}
			PrimitiveList<COMPONENT>& i_list = i_obj->getChilds();
			GameManagerLog(ame_Log_EndMethod, "deleteEntity",  "println", "");
			return i_list.getPosition();
		}
		
		virtual void rearrange(){
			GameManagerLog(ame_Log_StartMethod, "rearrange",  "println", "");
			for(int x = 0; x < m_game_objects.getPosition(); x++){
				COMPONENT* f_game_object = m_game_objects.getByPosition(x);
				f_game_object->setId(x);
			}
			GameManagerLog(ame_Log_EndMethod, "deleteEntity",  "println", "");
		}
		
		virtual cppObjectClass* getClass(){
			return Class<GameManager>::classType;
		}
		
		virtual void updateState(float tpc){
			// Serial.println("start GameManager update");
			for(int txp = 0; txp < this->m_addRequest.getPosition(); txp++){
				GameManagerLog(ame_Log_Statement, "update",  "println", "addRequest");
				this->addComponentToGameObject(this->m_addRequest.getKeyByPosition(txp), this->m_addRequest.getByPosition(txp));
			}
			this->m_addRequest.reset();
			
			for(int txp = 0; txp < this->m_deleteRequest.getPosition(); txp++){
				GameManagerLog(ame_Log_Statement, "update",  "println", "deleteRequest");
				this->addComponentToGameObject(this->m_deleteRequest.getKeyByPosition(txp), this->m_deleteRequest.getByPosition(txp));
			}
			this->m_deleteRequest.resetDeleteValue();
			
			for(int txp = 0; txp < this->m_deleteERequest.getPosition(); txp++){
				GameManagerLog(ame_Log_Statement, "update",  "println", "deleteERequest");
				this->deleteGameObject(this->m_deleteERequest.getByPosition(txp));
			}
			this->m_deleteERequest.reset();
			
			if(this->m_deleteAllE){
				GameManagerLog(ame_Log_Statement, "update",  "println", "deleteAllE");
				m_deleteAllE = false;
				this->deleteAllEntities();
			}
		}
		
	protected:

		bool m_deleteAllE = false;

		PrimitiveList<ENTITY> m_deleteERequest = PrimitiveList<ENTITY>(5, false, true);
		PrimitiveMap<ENTITY,COMPONENT> m_addRequest = PrimitiveMap<ENTITY,COMPONENT>(5, false, false, true);
		PrimitiveMap<ENTITY,cppObjectClass> m_deleteRequest = PrimitiveMap<ENTITY,cppObjectClass>(5, false, false, true);

		PrimitiveMap<cppObjectClass,PrimitiveList<COMPONENT>> m_components = PrimitiveMap<cppObjectClass,PrimitiveList<COMPONENT>>(5, false, true, true);
		PrimitiveList<ENTITY> m_game_objects = PrimitiveList<ENTITY>(5, true, true);
};

}

#endif