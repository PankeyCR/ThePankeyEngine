

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
		void deleteAllEntities();
		
		void deleteEntityRequest(int entity);
		void deleteAllEntitiesRequest();
		
		int getEntity(String entityClassName);
		GameObject* getGameObject(String entityClassName);
		int getEntity(GameObject* obj);
		GameObject* getGameObject(int entity);
		
		void addComponent(int entity, GameOn* component);
		void addComponent(GameObject* obj, GameOn* component);
		
		void addComponentRequest(int entity, GameOn* component);
		void addComponentRequest(GameObject* obj, GameOn* component);
		
		bool containComponent(String componentClassName);
		bool containComponent(int entity, String componentClassName);
		bool containComponent(GameObject* obj, String componentClassName);
		
		bool isEmpty();
		
		GameOn* getComponent(int entity, int index);
		GameOn* getComponent(int entity, String componentClassName);
		GameOn* getComponent(GameObject* obj, String componentClassName);
		
		//returns the first component founded on the gameobjects list searched by the componentClassName
		GameOn* getComponent(String componentClassName);
		//returns the first entity founded with the componentClassName 
		int getEntityComponent(String componentClassName);
		
		int getComponentIndex(int entity, String componentClassName);
		int getComponentIndex(GameObject* obj, String componentClassName);
		
		//returns the position of the first component founded on the gameobjects list searched by the componentClassName
		int getComponentEntity(String componentClassName);
		
		List<GameOn>* getComponents(int entity);
		List<GameOn>* getComponents(GameObject* obj);
		List<GameOn>* getComponents(String componentClassName);
		
		void deleteComponent(String componentClassName);
		
		GameOn* removeComponent(int entity, String componentClassName);
		GameOn* removeComponent(GameObject* obj, String componentClassName);
		
		void deleteComponent(int entity, String componentClassName);
		void deleteComponent(GameObject* obj, String componentClassName);
		
		void deleteComponentRequest(int entity, String componentClassName);
		void deleteComponentRequest(GameObject* obj, String componentClassName);
		
		void removeComponent(int entity, GameOn* component);
		void removeComponent(GameObject* obj, GameOn* component);
		
		void deleteComponent(int entity, GameOn* component);
		void deleteComponent(GameObject* obj, GameOn* component);
		
		GameOn* removeComponentIterating(List<GameOn>* components);
		
		void deleteComponentIterating(List<GameOn>* components);
		
		int getEntitySize();
		int getComponentSize(int entity);
		
		String getClassName();
		String toString();
		bool equal(cppObject *b);
		cppObject *clone();
		
		void update(float tpc);
		
	protected:
		bool deleteAllE = false;
		List<int>* deleteERequest = nullptr;
		Map<int,GameOn>* addRequest = nullptr;
		Map<int,String>* deleteRequest = nullptr;
		Map<String,PrimitiveList<GameOn>>* components = nullptr;
		PrimitiveList<GameObject>* gameobjects = nullptr;
};


#endif 
