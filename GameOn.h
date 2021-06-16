

#ifndef GameOn_h
#define GameOn_h

#include "cppObject.h"

class GameOn : public cppObject{
    public:		
		GameOn();
		virtual ~GameOn();
		virtual void setParent(GameOn *parent);
		virtual GameOn *getParent();
		
        virtual void setId(int id);
        virtual int getId();
		
		virtual bool isEnable();
		virtual void enable();
		virtual void disable();
		
		virtual void update(float tpc);
		
		virtual cppObjectClass* getClass();
		virtual String toString();
		virtual bool instanceof(cppObjectClass* cls);
		
        virtual GameOn operator =(const GameOn& c);
        virtual bool operator ==(const GameOn& c);
        virtual bool operator !=(const GameOn& c);
    
	protected:	
		GameOn* parent = nullptr;
		bool enabler = false;
};


#endif 
