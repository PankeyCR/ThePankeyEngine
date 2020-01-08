
#ifndef Control_h
#define Control_h

#include "cppObject.h"
class GameObject;

class Control : public cppObject{
    private:
	
    public:
		GameObject *object;
		Control();
		virtual ~Control();
        virtual void set(GameObject *obj);
        virtual GameObject *get();
        virtual bool isValidControl();
        virtual void update();
        virtual void onDelete();
		virtual String getClassName();
		virtual String toString();
		virtual Control *clone();
        void operator =(Control c);
        bool operator ==(Control c);
        bool operator !=(Control c);
};

#endif 
