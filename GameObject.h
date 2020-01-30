
#ifndef GameObject_h
#define GameObject_h

#include "Arduino.h"
#include "GameOn.h"
#include "List.h"

class GameObject : public GameOn{
    protected:
		List<GameOn>* childs = nullptr;
	
    public:
		
		virtual ~GameObject();
		
		virtual void update(float tpf);
		
        virtual GameOn* attach(GameOn* gameobject);
        virtual GameOn* attach(String id, GameOn* gameobject);
		
        virtual GameOn* getChild(String id_className);
        virtual GameOn* getChild(String id, String className);
		
        virtual GameOn* detach(String id_className);
        virtual GameOn* detach(String id, String className);
		
		virtual String getClassName();
		virtual String toString();
};

#endif 
