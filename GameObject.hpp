
#include "ame_Enviroment.hpp"

#if defined(DISABLE_GameObject)
	#define GameObject_hpp
#endif

#ifndef GameObject_hpp
#define GameObject_hpp
#define GameObject_AVAILABLE

#ifndef ame_Enviroment_Defined

#endif

#ifdef ame_Windows

#endif

#ifdef ame_ArduinoIDE
	#include "Arduino.h"
#endif

#include "GameOn.hpp"
#include "PrimitiveList.hpp"
#include "List.hpp"

namespace ame{

class GameObject : public GameOn{
    protected:
		PrimitiveList<GameOn> childs;
		int gameId = -1;
	
    public:
		
		GameObject(){}
		
		GameObject(const int& i){
			gameId = i;
		}
		
		GameObject(const GameObject& obj){
			for(int x = 0; x < obj.childs.getPosition(); x++){
				childs.addPointer(obj.childs.getByPosition(x)->clone());
			}
		}
		
		GameObject(const PrimitiveList<GameOn>& m_childs){
			for(int x = 0; x < m_childs.getPosition(); x++){
				childs.addPointer(m_childs.getByPosition(x)->clone());
			}
		}
		
		virtual ~GameObject(){}
		
		virtual GameObject& operator=(const int& i){
			gameId = i;
			return *this;
		}
		
		virtual GameObject& operator=(const GameObject& obj){
			for(int x = 0; x < obj.childs.getPosition(); x++){
				childs.addPointer(obj.childs.getByPosition(x)->clone());
			}
			return *this;
		}
		
		virtual bool operator==(const GameObject& obj){
			if(childs.getPosition() != obj.childs.getPosition()){
				return false;
			}
			for(int x = 0; x < obj.childs.getPosition(); x++){
				if(childs[x] != obj.childs[x]){
					return false;
				}
			}
			return true;
		}
		
		virtual bool operator!=(const GameObject& obj){
			if(childs.getPosition() != obj.childs.getPosition()){
				return true;
			}
			for(int x = 0; x < obj.childs.getPosition(); x++){
				if(childs[x] != obj.childs[x]){
					return true;
				}
			}
			return false;
		}
		
		
        virtual void setId(int id){
			gameId = id;
		}
		
        virtual int getId(){
			return gameId;
		}
		
		
		virtual void update(float tpc){
			for(int x = 0; x < childs.getPosition(); x++){
				childs.getByPosition(x)->update(tpc);
			}
		}
		
		
        virtual GameOn* attach(GameOn* gmo){
			gmo->setParent(this);
			gmo->setId(getId());
			childs.addPointer(gmo);
			return gmo;
		}
		
		
        virtual GameOn* getChild(cppObjectClass* cls){
			for(int x = 0; x < childs.getPosition(); x++){
				GameOn* gameOn = childs.getByPosition(x);
				cppObjectClass* gOnClass = gameOn->getClass();
				if(gOnClass == cls){
					return gameOn;
				}
			}
			return nullptr;
		}
		
        virtual GameOn* detach(cppObjectClass* cls){
			for(int x = 0; x < childs.getPosition(); x++){
				GameOn* gameOn = childs.getByPosition(x);
				cppObjectClass* gOnClass = gameOn->getClass();
				if(gOnClass == cls){
					return childs.removeByPosition(x);
				}
			}
			return nullptr;
		}
		
		
        virtual GameOn* detach(GameOn* gon){
			return childs.removeByPointer(gon);
		}
		
        virtual void detachDelete(cppObjectClass* cls){
			GameOn* gon = detach(cls);
			if(gon == nullptr){
				return;
			}
			delete gon;
		}
		
        virtual void detachDelete(GameOn* gon){
			GameOn* g = childs.removeByPointer(gon);
			if(g == nullptr){
				return;
			}
			delete g;
		}
		
        virtual PrimitiveList<GameOn>& getChilds(){
			return childs;
		}
		
		
		virtual cppObjectClass* getClass(){
			return Class<GameObject>::classType;
		}
		
		virtual bool instanceof(cppObjectClass* cls){
			return Class<GameObject>::classType == cls || 
					GameOn::instanceof(cls);
		}
		
		virtual Note toNote(){
			return "GameObject";
		}
		
		virtual GameObject* clone(){
			return new GameObject(childs);
		}
};

}

#endif