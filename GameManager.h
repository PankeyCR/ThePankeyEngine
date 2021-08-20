

#ifndef GameManager_h
#define GameManager_h

#include "cppObject.h"
#include "AppState.h"
#include "GameObject.h"
#include "Map.h"
#include "PrimitiveMap.h"
#include "PrimitiveList.h"
#include "List.h"

#ifdef GameManagerLogApp
	#include "Logger.h"
	#define GameManagerLog(name,method,type,mns) Log(name,method,type,mns)
#else
	#define GameManagerLog(name,method,type,mns)
#endif

namespace ame{

class GameManager : public AppState{
    public:		
		GameManager();
		virtual ~GameManager();
		
		int createEntity(GameObject* obj);
		GameObject* createGameObject(GameObject* obj);
		
		int createEntity();
		GameObject* createGameObject();
		
		void deleteEntity(int entity);
		void deleteGameObject(GameObject* obj);
		void deleteAllEntities();
		
		void deleteEntityRequest(int entity);
		void deleteGameObjectRequest(GameObject* obj);
		void deleteAllEntitiesRequest();
		
		int getEntity(cppObjectClass* cls);
		GameObject* getGameObject(cppObjectClass* cls);
		int getEntity(GameObject* obj);
		GameObject* getGameObject(int entity);
		
		int getFirstEntity();
		GameObject* getFirstGameObject();
		int getLastEntity();
		GameObject* getLastGameObject();
		
		void addEntityComponent(int entity, GameOn* component);
		void addGameObjectComponent(GameObject* obj, GameOn* component);
		
		void addEntityComponentRequest(int entity, GameOn* component);
		void addGameObjectComponentRequest(GameObject* obj, GameOn* component);
		
		bool containComponent(cppObjectClass* cls);
		template<class... s>
		bool containComponents(s... componentClass){
			if(this->isEmpty()){
				return false;
			}
			PrimitiveList<cppObjectClass> classNs;
			classNs.addPack(componentClass...);
			if(classNs.isEmpty()){
				return false;
			}
			int ec = this->getEntityByComponent(classNs.getByPosition(0));
			for(int x = 0; x < classNs.getPosition(); x++){
				cppObjectClass* cls = *classNs.getByPosition(x);
				int edec = this->getEntityByComponent(cls);
				if(ec != edec){
					return false;
				}
			}
			return true;
		}
		
		bool containEntityComponent(int entity, cppObjectClass* cls);
		template<class... s>
		bool containEntityComponents(int entity, s... componentClass){
			PrimitiveList<String> classNs;
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
		bool containGameObjectComponent(GameObject* obj, cppObjectClass* cls);
		
		bool isEmpty();
		
		GameOn* getEntityComponent(int entity, int index);
		GameOn* getEntityComponent(int entity, cppObjectClass* cls);
		GameOn* getGameObjectComponent(GameObject* obj, cppObjectClass* cls);
		
		//returns the first component founded on the gameobjects list searched by the componentClassName
		GameOn* getComponent(cppObjectClass* cls);
		//returns the first entity founded with the componentClassName 
		int getEntityByComponent(cppObjectClass* cls);
		
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
		
		int getEntityComponentIndex(int entity, cppObjectClass* cls);
		int getGameObjectComponentIndex(GameObject* obj, cppObjectClass* cls);
		
		//returns the position of the first component founded on the gameobjects list searched by the componentClassName
		int getComponentEntity(cppObjectClass* cls);
		
		List<GameOn>* getEntityComponents(int entity);
		List<GameOn>* getGameObjectComponents(GameObject* obj);
		List<GameOn>* getComponents(cppObjectClass* cls);
		
		void deleteComponent(cppObjectClass* cls);
		
		GameOn* removeEntityComponent(int entity, cppObjectClass* cls);
		GameOn* removeGameObjectComponent(GameObject* obj, cppObjectClass* cls);
		
		void deleteEntityComponent(int entity, cppObjectClass* cls);
		void deleteGameObjectComponent(GameObject* obj, cppObjectClass* cls);
		
		void deleteEntityComponents(int entity);
		void deleteGameObjectComponents(GameObject* obj);
		
		void deleteEntityComponentRequest(int entity, cppObjectClass* cls);
		void deleteGameObjectComponentRequest(GameObject* obj, cppObjectClass* cls);
		
		void removeEntityComponent(int entity, GameOn* component);
		void removeGameObjectComponent(GameObject* obj, GameOn* component);
		
		void deleteEntityComponent(int entity, GameOn* component);
		void deleteGameObjectComponent(GameObject* obj, GameOn* component);
		
		GameOn* removeComponentIterating(Iterator& i, List<GameOn>* listComponents);
		
		void deleteComponentIterating(Iterator& i, List<GameOn>* listComponents);
		
		//resets the list and it deletes the components from there entities
		void deleteComponentsFromList(PrimitiveList<GameOn>* listComponents);
		
		int getEntitySize();
		int getComponentSize(int entity);
		
		void rearrange();
		
		cppObjectClass* getClass();
		String toString();
		bool equal(cppObject *b);
		cppObject *clone();
		
		void update(float tpc);
		
	protected:
		bool deleteAllE = false;
		List<GameObject>* deleteERequest = nullptr;
		Map<GameObject,GameOn>* addRequest = nullptr;
		Map<GameObject,cppObjectClass>* deleteRequest = nullptr;
		Map<cppObjectClass,PrimitiveList<GameOn>>* components = nullptr;
		PrimitiveList<GameObject>* m_gobjects = nullptr;
};

}

#endif 
