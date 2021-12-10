
#ifndef SimpleApplication_hpp
#define SimpleApplication_hpp

#ifndef ame_Enviroment_Defined
	#include "Arduino.h"
#endif

#ifdef ame_Windows

#endif

#ifdef ame_ArduinoIDE
	#include "Arduino.h"
#endif

#include "Application.hpp"
#include "AppStateManager.hpp"
#include "AppSettings.hpp"
#include "TimeControl.h"
#include "SimpleTimer.h"
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
		
		virtual MemoryPool* setMemoryPool(MemoryPool* mp){
			memory = mp;
			return mp;
		}
		virtual MemoryPool* getMemoryPool(){
			return memory;
		}
		
		virtual void update(){
			this->states->update();
			if(listener != nullptr){
				listener->InterruptEvent(this->states->tpc());
			}
			if(memory != nullptr){
				memory->update(this->states->tpc());
			}
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
		virtual String toString(){
			return "SimpleApplication";
		}
		virtual bool instanceof(cppObjectClass* cls){
			return cls == ame::Class<SimpleApplication>::classType || ame::Application::instanceof(cls);
		}
		
	private:
		AppStateManager* states = nullptr;
		AppSettings* settings = nullptr;
		Listener* listener = nullptr;
		MemoryPool* memory = nullptr;
		Node* rootNode = nullptr;
		Node* guiNode = nullptr;
};

}

#endif 
