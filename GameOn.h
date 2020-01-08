

#ifndef GameOn_h
#define GameOn_h

#include "cppObject.h"
#include "Note.h"
class GameObject;

class GameOn : public cppObject{
    public:		
		GameOn();
		virtual ~GameOn();
		virtual void setParent(GameObject *parent);
		virtual GameObject *getParent();
		
		virtual bool isEnable();
		virtual void enable();
		virtual void disable();
		
		//virtual Note getNote();
		
		virtual void update(float tpf);
        // virtual GameOn operator =(const Note& note);
        // virtual GameOn operator =(const GameOn& c);
        // virtual bool operator ==(const GameOn& c);
        // virtual bool operator !=(const GameOn& c);
    
	protected:	
		GameObject *parent;
		bool enabler = false;
};


#endif 
