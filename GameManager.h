

#ifndef GameManager_h
#define GameManager_h

#include "cppObject.h"
#include "AppState.h"
#include "GameObject.h"
#include "Map.h"
#include "PrimitiveMap.h"
#include "PrimitiveList.h"
#include "List.h"

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
		
		int getEntity(String entityClassName);
		GameObject* getGameObject(String entityClassName);
		int getEntity(GameObject* obj);
		GameObject* getGameObject(int entity);
		
		void addEntityComponent(int entity, GameOn* component);
		void addGameObjectComponent(GameObject* obj, GameOn* component);
		
		void addEntityComponentRequest(int entity, GameOn* component);
		void addGameObjectComponentRequest(GameObject* obj, GameOn* component);
		
		bool containComponent(String componentClassName);
		bool containEntityComponent(int entity, String componentClassName);
		bool containGameObjectComponent(GameObject* obj, String componentClassName);
		
		bool isEmpty();
		
		GameOn* getEntityComponent(int entity, int index);
		GameOn* getEntityComponent(int entity, String componentClassName);
		GameOn* getGameObjectComponent(GameObject* obj, String componentClassName);
		
		//returns the first component founded on the gameobjects list searched by the componentClassName
		GameOn* getComponent(String componentClassName);
		//returns the first entity founded with the componentClassName 
		int getEntityByComponent(String componentClassName);
		
		int getEntityComponentIndex(int entity, String componentClassName);
		int getGameObjectComponentIndex(GameObject* obj, String componentClassName);
		
		//returns the position of the first component founded on the gameobjects list searched by the componentClassName
		int getComponentEntity(String componentClassName);
		
		List<GameOn>* getEntityComponents(int entity);
		List<GameOn>* getGameObjectComponents(GameObject* obj);
		List<GameOn>* getComponents(String componentClassName);
		
		void deleteComponent(String componentClassName);
		
		GameOn* removeEntityComponent(int entity, String componentClassName);
		GameOn* removeGameObjectComponent(GameObject* obj, String componentClassName);
		
		void deleteEntityComponent(int entity, String componentClassName);
		void deleteGameObjectComponent(GameObject* obj, String componentClassName);
		
		void deleteEntityComponentRequest(int entity, String componentClassName);
		void deleteGameObjectComponentRequest(GameObject* obj, String componentClassName);
		
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
		
		String getClassName();
		String toString();
		bool equal(cppObject *b);
		cppObject *clone();
		
		void update(float tpc);
		
	protected:
		bool deleteAllE = false;
		List<GameObject>* deleteERequest = nullptr;
		Map<GameObject,GameOn>* addRequest = nullptr;
		Map<GameObject,String>* deleteRequest = nullptr;
		Map<String,PrimitiveList<GameOn>>* components = nullptr;
		PrimitiveList<GameObject>* gameobjects = nullptr;
};


#endif 
