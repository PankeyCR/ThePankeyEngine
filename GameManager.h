

#ifndef GameManager_h
#define GameManager_h

#include "cppObject.h"
#include "GameObject.h"
#include "Map.h"
#include "PrimitiveMap.h"
#include "LinkedList.h"
#include "List.h"

class GameManager : public cppObject{
    public:		
		GameManager();
		virtual ~GameManager();
		
		int createEntity(GameObject* obj);
		GameObject* createGameObject(GameObject* obj);
		
		int createEntity();
		GameObject* createGameObject();
		
		int getEntity(GameObject* obj);
		GameObject* getGameObject(int entity);
		
		void addComponent(int entity, GameOn* component);
		void addComponent(GameObject* obj, GameOn* component);
		
		bool containComponents(int entity, String componentClassName);
		bool containComponents(GameObject* obj, String componentClassName);
		
		GameOn* getComponent(int entity, String componentClassName);
		GameOn* getComponent(GameObject* obj, String componentClassName);
		
		List<GameOn>* getComponents(int entity);
		List<GameOn>* getComponents(GameObject* obj);
		List<GameOn>* getComponents(String componentClassName);
		
		GameOn* removeComponent(int entity, String componentClassName);
		GameOn* removeComponent(GameObject* obj, String componentClassName);
		
		void deleteComponent(int entity, String componentClassName);
		void deleteComponent(GameObject* obj, String componentClassName);
		
		virtual String getClassName();
		virtual String toString();
		virtual bool equal(cppObject *b);
		virtual cppObject *clone();
		
	protected:
		Map<String,LinkedList<GameOn>>* components = nullptr;
		List<GameObject>* gameobjects = nullptr;
};


#endif 
