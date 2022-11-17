
#ifndef CONFIGURATION_GameObject_hpp
#define CONFIGURATION_GameObject_hpp

	#include "ame_Enviroment.hpp"

	#if defined(DISABLE_GameObject)
		#define GameObject_hpp

		#define IMPLEMENTATION_GameObject
		#define IMPLEMENTING_GameObject
	#else
		#if defined(DISABLE_IMPLEMENTATION_GameObject)
			#define IMPLEMENTATION_GameObject
			#define IMPLEMENTING_GameObject
		#endif
	#endif
#endif

#ifndef GameObject_hpp
#define GameObject_hpp
#define GameObject_AVAILABLE

#ifndef DISABLE_IMPLEMENTATION_GameObject
	#define IMPLEMENTATION_GameObject IMPLEMENTATION(public GameObject)
	#define IMPLEMENTING_GameObject IMPLEMENTING(public GameObject)
#endif

#include "GameObject.hpp"
#include "GameOn.hpp"
#include "PrimitiveList.hpp"
#include "List.hpp"

#ifdef GameObject_LogApp
	#include "ame_Logger_config.hpp"
	#include "ame_Logger.hpp"

	#define GameObjectLog(location,method,type,mns) ame_Log(this,location,"GameObject",method,type,mns)
	#define const_GameObjectLog(location,method,type,mns)
#else
	#ifdef GameObject_LogDebugApp
		#include "ame_Logger_config.hpp"
		#include "ame_Logger.hpp"

		#define GameObjectLog(location,method,type,mns) ame_LogDebug(this,location,"GameObject",method,type)
		#define const_GameObjectLog(location,method,type,mns)
	#else
		#define GameObjectLog(location,method,type,mns)
		#define const_GameObjectLog(location,method,type,mns)
	#endif
#endif

namespace ame{

class GameObject : public GameOn{
    protected:
		PrimitiveList<GameOn> m_childs;
	
    public:
		
		GameObject(){
			GameObjectLog(ame_Log_StartMethod, "Constructor",  "println", "");
			GameObjectLog(ame_Log_EndMethod, "Constructor",  "println", "");
		}
		
		GameObject(const GameObject& c_obj){
			GameObjectLog(ame_Log_StartMethod, "Constructor",  "println", "");
			m_parent = c_obj.m_parent;
			m_enabler = c_obj.m_enabler;
			m_id = c_obj.m_id;

			for(int x = 0; x < c_obj.m_childs.getPosition(); x++){
				GameOn* f_game_on = c_obj.m_childs.getByPosition(x);
				m_childs.addPointer(f_game_on->clone());
			}
			GameObjectLog(ame_Log_EndMethod, "Constructor",  "println", "");
		}
		
		GameObject(const PrimitiveList<GameOn>& c_childs){
			GameObjectLog(ame_Log_StartMethod, "Constructor",  "println", "");
			for(int x = 0; x < c_childs.getPosition(); x++){
				GameOn* f_game_on = c_childs.getByPosition(x);
				m_childs.addPointer(f_game_on->clone());
			}
			GameObjectLog(ame_Log_EndMethod, "Constructor",  "println", "");
		}
		
		virtual ~GameObject(){
			GameObjectLog(ame_Log_StartMethod, "Destructor",  "println", "");
			GameObjectLog(ame_Log_EndMethod, "Destructor",  "println", "");
		}
		
		virtual void update(float tpc){
			for(int x = 0; x < m_childs.getPosition(); x++){
				GameOn* f_game_on = m_childs.getByPosition(x);
				f_game_on->update(tpc);
			}
		}
		
        virtual GameOn* attach(GameOn* a_game_on){
			GameObjectLog(ame_Log_StartMethod, "attach",  "println", "");
			if(a_game_on == nullptr){
				GameObjectLog(ame_Log_EndMethod, "attach",  "println", "");
				return nullptr;
			}
			a_game_on->setParent(this);
			a_game_on->setId(getId());
			m_childs.addPointer(a_game_on);
			GameObjectLog(ame_Log_EndMethod, "attach",  "println", "");
			return a_game_on;
		}
		
        virtual GameOn* getChildByPosition(int a_position){
			GameObjectLog(ame_Log_StartMethod, "getChildByPosition",  "println", "");
			GameObjectLog(ame_Log_EndMethod, "getChildByPosition",  "println", "");
			return m_childs.getByPosition(a_position);
		}
		
        virtual GameOn* getChildByClass(cppObjectClass* a_cls){
			GameObjectLog(ame_Log_StartMethod, "getChildByClass",  "println", "");
			for(int x = 0; x < m_childs.getPosition(); x++){
				GameOn* f_gameOn = m_childs.getByPosition(x);
				cppObjectClass* f_class = f_gameOn->getClass();
				if(f_class == a_cls){
					GameObjectLog(ame_Log_EndMethod, "getChildByClass",  "println", "");
					return f_gameOn;
				}
			}
			GameObjectLog(ame_Log_EndMethod, "getChildByClass",  "println", "");
			return nullptr;
		}
		
        virtual GameOn* detachByClass(cppObjectClass* a_cls){
			GameObjectLog(ame_Log_StartMethod, "detach",  "println", "");
			for(int x = 0; x < m_childs.getPosition(); x++){
				GameOn* f_game_on = m_childs.getByPosition(x);
				cppObjectClass* f_class = f_game_on->getClass();
				if(f_class == a_cls){
					GameObjectLog(ame_Log_EndMethod, "detach",  "println", "");
					return m_childs.removeByPosition(x);
				}
			}
			GameObjectLog(ame_Log_EndMethod, "detach",  "println", "");
			return nullptr;
		}
		
		
        virtual GameOn* detachByPointer(GameOn* gon){
			GameObjectLog(ame_Log_StartMethod, "detach",  "println", "");
			GameObjectLog(ame_Log_EndMethod, "detach",  "println", "");
			return m_childs.removeByPointer(gon);
		}
		
        virtual void detachDeleteByClass(cppObjectClass* a_cls){
			GameObjectLog(ame_Log_StartMethod, "detachDeleteByClass",  "println", "");
			GameOn* i_game_on = this->detachByClass(a_cls);
			if(i_game_on == nullptr){
				GameObjectLog(ame_Log_EndMethod, "detachDeleteByClass",  "println", "");
				return;
			}
			delete i_game_on;
			GameObjectLog(ame_Log_EndMethod, "detachDeleteByClass",  "println", "");
		}
		
        virtual void detachDeleteByPointer(GameOn* a_game_on){
			GameObjectLog(ame_Log_StartMethod, "detachDeleteByPointer",  "println", "");
			GameOn* i_game_on = m_childs.removeByPointer(a_game_on);
			if(i_game_on == nullptr){
				GameObjectLog(ame_Log_EndMethod, "detachDeleteByPointer",  "println", "");
				return;
			}
			delete i_game_on;
			GameObjectLog(ame_Log_EndMethod, "detachDeleteByPointer",  "println", "");
		}
		
        virtual PrimitiveList<GameOn>& getChilds(){
			GameObjectLog(ame_Log_StartMethod, "getChilds",  "println", "");
			GameObjectLog(ame_Log_EndMethod, "getChilds",  "println", "");
			return m_childs;
		}
		
        virtual List<GameOn>* getChildsPointer(){
			GameObjectLog(ame_Log_StartMethod, "getChildsPointer",  "println", "");
			GameObjectLog(ame_Log_EndMethod, "getChildsPointer",  "println", "");
			return &m_childs;
		}
		
		virtual void operator=(const GameObject& obj){
			GameObjectLog(ame_Log_StartMethod, "operator=",  "println", "");
			for(int x = 0; x < obj.m_childs.getPosition(); x++){
				m_childs.addPointer(obj.m_childs.getByPosition(x)->clone());
			}
			GameObjectLog(ame_Log_EndMethod, "operator=",  "println", "");
		}
		
		virtual bool operator==(const GameObject& obj){
			GameObjectLog(ame_Log_StartMethod, "operator==",  "println", "");
			if(m_childs.getPosition() != obj.m_childs.getPosition()){
				GameObjectLog(ame_Log_EndMethod, "operator==",  "println", "");
				return false;
			}
			for(int x = 0; x < obj.m_childs.getPosition(); x++){
				if(m_childs[x] != obj.m_childs[x]){
					GameObjectLog(ame_Log_EndMethod, "operator==",  "println", "");
					return false;
				}
			}
			GameObjectLog(ame_Log_EndMethod, "operator==",  "println", "");
			return true;
		}
		
		virtual bool operator!=(const GameObject& obj){
			GameObjectLog(ame_Log_StartMethod, "operator!=",  "println", "");
			if(m_childs.getPosition() != obj.m_childs.getPosition()){
				GameObjectLog(ame_Log_EndMethod, "operator!=",  "println", "");
				return true;
			}
			for(int x = 0; x < obj.m_childs.getPosition(); x++){
				if(m_childs[x] != obj.m_childs[x]){
					GameObjectLog(ame_Log_EndMethod, "operator!=",  "println", "");
					return true;
				}
			}
			GameObjectLog(ame_Log_EndMethod, "operator!=",  "println", "");
			return false;
		}
		
		virtual cppObjectClass* getClass(){
			return Class<GameObject>::classType;
		}
		
		virtual bool instanceof(cppObjectClass* cls){
			return Class<GameObject>::classType == cls || 
					GameOn::instanceof(cls);
		}
		
		virtual GameObject* clone(){
			return new GameObject(*this);
		}
};

}

#endif