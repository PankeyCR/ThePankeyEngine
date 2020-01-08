
#ifndef GameObject_h
#define GameObject_h

#include "Arduino.h"
#include "cppObject.h"
#include "Control.h"
#include "List.h"
#include "PList.h"

class GameObject : public cppObject{
    private:
	
    public:
		List<Control> *controls = nullptr;
		List<GameObject> *childs = nullptr;
		GameObject *parent = nullptr;
		
		GameObject();
		virtual ~GameObject();
        virtual void setParent(GameObject *obj);
        virtual GameObject *get();
        virtual void update();
        virtual void addControl(Control *control);
        virtual Control *getControl(String className);
        virtual Control *getControl(Control *control);
        virtual Control *getControl(int control);
        virtual Control *removeControl(Control *control);
        virtual Control *removeControl(int control);
        virtual void attach(GameObject *gameobject);
        virtual GameObject *getChild(String className);
        virtual GameObject *getChild(GameObject *gameobject);
        virtual GameObject *getChild(int control);
        virtual GameObject *detach(GameObject *gameobject);
        virtual GameObject *detach(int gameobject);
        virtual void onDelete();
		virtual String getClassName();
		virtual String toString();
		virtual GameObject *clone();
        void operator =(GameObject c);
        bool operator ==(GameObject c);
        bool operator !=(GameObject c);
};

#endif 
