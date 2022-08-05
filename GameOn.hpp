
#include "ame_Enviroment.hpp"

#if defined(DISABLE_GameOn)
	#define GameOn_hpp
#endif

#ifndef GameOn_hpp
#define GameOn_hpp
#define GameOn_AVAILABLE

#ifndef ame_Enviroment_Defined

#endif

#ifdef ame_Windows

#endif

#ifdef ame_ArduinoIDE
	#include "Arduino.h"
#endif

#include "cppObject.hpp"
#include "Class.hpp"

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
		
		virtual Note toNote(){
			return "GameOn";
		}
		
		virtual bool instanceof(cppObjectClass* cls){
			return cls == Class<GameOn>::classType || cls == Class<cppObject>::classType;
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

#define CreateComponentMacro(T)\
class T : public GameOn{\
    public:\
	T(){}\
	virtual ~T(){}\
	virtual cppObjectClass* getClass(){return Class<T>::classType;}\
	virtual Note toNote(){return "T";}\
	virtual bool instanceof(cppObjectClass* cls){return cls == Class<T>::classType || GameOn::instanceof(cls);}\
};\


#define ComponentMacro(T){\
	virtual cppObjectClass* getClass(){return Class<T>::classType;}\
	virtual Note toNote(){return "T";}\
	virtual bool instanceof(cppObjectClass* cls){return cls == Class<T>::classType || cppObject::instanceof(cls);}\
}

}//end ame namespace


#endif