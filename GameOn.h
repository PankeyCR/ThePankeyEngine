

#ifndef GameOn_h
#define GameOn_h

#include "cppObject.h"
#include "Note.h"

class GameOn : public cppObject{
    public:		
		GameOn();
		virtual ~GameOn();
		virtual void setParent(GameOn *parent);
		virtual GameOn *getParent();
		
        virtual void setId(String id);
        virtual String getId();
		
		virtual bool isEnable();
		virtual void enable();
		virtual void disable();
		
		virtual void update(float tpf);
		
		virtual String getClassName();
		virtual String toString();
		
        virtual GameOn operator =(const GameOn& c);
        virtual bool operator ==(const GameOn& c);
        virtual bool operator !=(const GameOn& c);
    
	protected:	
		GameOn* parent;
		bool enabler = false;
		String idm;
};


#endif 
