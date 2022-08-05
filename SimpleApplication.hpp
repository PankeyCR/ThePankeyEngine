
#include "ame_Enviroment.hpp"

#if defined(DISABLE_SimpleApplication)
	#define SimpleApplication_hpp
#endif

#ifndef SimpleApplication_hpp
#define SimpleApplication_hpp
#define SimpleApplication_AVAILABLE

#ifndef ame_Enviroment_Defined

#endif

#ifdef ame_Windows

#endif

#ifdef ame_ArduinoIDE
	#include "Arduino.h"
#endif

#include "Application.hpp"
#include "AppStateManager.hpp"
#include "AppSettings.hpp"
#include "TimeControl.hpp"
#include "SimpleTimer.hpp"
#include "Logger.hpp"
#include "Listener.hpp"
#include "Node.hpp"
#include "DefaultSettings.hpp"
#include "RenderStateManager.hpp"

namespace ame{

class SimpleApplication : public Application{
    public:
		SimpleApplication(){
			this->states = new RenderStateManager();
			this->settings = new DefaultSettings();
			this->states->setApplication(this);
			this->rootNode = new Node();
			this->guiNode = new Node();
		}
		virtual ~SimpleApplication(){
			delete this->states;
			delete this->settings;
			delete this->rootNode;
			delete this->guiNode;
		}
		
		virtual void setSettings(AppSettings *setting){
			if(setting != nullptr && this->settings != setting){
				delete this->settings;
			}
			this->settings = setting;
		}
		virtual AppSettings *getSettings(){
			return this->settings;
		}
		
		virtual void setStateManager(AppStateManager *manager){
			if(manager != nullptr && this->states != manager){
				delete this->states;
			}
			this->states = manager;
		}
		virtual AppStateManager *getStateManager(){
			return this->states;
		}
				
		virtual void setTimeControl(TimeControl *timecontrol){}
		virtual TimeControl *getTimeControl(){
			return SimpleTimer::getInstance();
		}
		
		virtual Listener* setListener(Listener* l){
			listener = l;
			listener->attach(this);
			return l;
		}
		virtual Listener* getListener(){
			return listener;
		}
		
		#if !defined(ame_HAS_NO_MEMORYMANGEMENT)
		
		virtual MemoryPool* setMemoryPool(MemoryPool* mp){
			memory = mp;
			return mp;
		}
		virtual MemoryPool* getMemoryPool(){
			return memory;
		}
		
		#endif
		
		virtual void update(){
			this->states->update();
			if(listener != nullptr){
				listener->InterruptEvent(this->states->tpc());
			}
			#if !defined(ame_HAS_NO_MEMORYMANGEMENT)
			if(memory != nullptr){
				memory->update(this->states->tpc());
			}
			#endif
		}
		
		virtual Node* getRootNode(){
			return this->rootNode;
		}
		virtual Node* getGuiNode(){
			return this->guiNode;
		}
		
		//cppObject part
		virtual cppObjectClass* getClass(){
			return Class<SimpleApplication>::classType;
		}
		virtual Note toNote(){
			return "SimpleApplication";
		}
		virtual bool instanceof(cppObjectClass* cls){
			return cls == ame::Class<SimpleApplication>::classType || ame::Application::instanceof(cls);
		}
		
	private:
		AppStateManager* states = nullptr;
		AppSettings* settings = nullptr;
		Listener* listener = nullptr;
		
		#if !defined(ame_HAS_NO_MEMORYMANGEMENT)
		MemoryPool* memory = nullptr;
		#endif
		
		Node* rootNode = nullptr;
		Node* guiNode = nullptr;
};

}

#endif