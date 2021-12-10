
#include "ame_Level.hpp"

#if defined(ame_untilLevel_7)

#ifndef GameOn_hpp
#define GameOn_hpp

#include "cppObject.hpp"

namespace ame{

class GameOn : public cppObject{
    public:		
		GameOn(){}
		virtual ~GameOn(){}
		virtual void setParent(GameOn *m_parent){
			parent = m_parent;
		}
		
		virtual GameOn *getParent(){
			return parent;
		}
		
		
        virtual void setId(int id){
			if(parent != nullptr){
				parent->setId(id);
			}
		}
		
        virtual int getId(){
			if(parent != nullptr){
				return parent->getId();
			}
			return -1;
		}
			
		
		virtual bool isEnable(){
			return enabler;
		}
			
		virtual void enable(){
			enabler = true;
		}
		
		virtual void disable(){
			enabler = false;
		}
		
		
		virtual void update(float tpc){
			
		}
		
		
		virtual cppObjectClass* getClass(){
			return Class<GameOn>::classType;
		}
		
		virtual String toString(){
			return "GameOn";
		}
		
		virtual bool instanceof(cppObjectClass* cls){
			return cls == Class<GameOn>::classType || cppObject::instanceof(cls);
		}
		
		
        virtual GameOn& operator =(const GameOn& c){
			
			return *this;
		}
		
        virtual bool operator ==(const GameOn& c){
			return parent == c.parent && enabler == c.enabler;
		}
		
        virtual bool operator !=(const GameOn& c){
			return parent != c.parent && enabler != c.enabler;
		}
		
        virtual GameOn* clone(){
			return new GameOn();
		}
		
    
	protected:	
		GameOn* parent = nullptr;
		bool enabler = false;
};

}

#endif 

#endif 
