
#ifndef GameObject_h
#define GameObject_h

#include "Arduino.h"
#include "GameOn.h"
#include "LinkedList.h"
#include "List.h"

class GameObject : public GameOn{
    protected:
		List<GameOn>* childs = nullptr;
		int gameId = -1;
	
    public:
		
		GameObject();
		virtual ~GameObject();
		
        virtual void setId(int id);
        virtual int getId();
		
		virtual void update(float tpf);
		
        virtual GameOn* attach(GameOn* gameobject);
		
        virtual GameOn* getChild(String className);
		
        virtual GameOn* detach(String className);
		
        virtual List<GameOn>* getChilds();
		
		virtual String getClassName();
		virtual String toString();
};

#endif 
