

#ifndef SimpleApplication_cpp
#define SimpleApplication_cpp

#include "SimpleApplication.h"

	ame::SimpleApplication::SimpleApplication(){
		this->states = new RenderStateManager();
		this->settings = new DefaultSettings();
		this->states->setApplication(this);
		this->rootNode = new Node();
		this->guiNode = new Node();
	}
	
	ame::SimpleApplication::~SimpleApplication(){
		delete this->states;
		delete this->settings;
		delete this->rootNode;
		delete this->guiNode;
	}
	
	void ame::SimpleApplication::setSettings(AppSettings *set){
		if(set != nullptr && this->settings != set){
			delete this->settings;
		}
		this->settings = set;
	}
	
	ame::AppSettings *ame::SimpleApplication::getSettings(){
		return this->settings;
	}
	
	void ame::SimpleApplication::setStateManager(AppStateManager *manager){
		if(manager != nullptr && this->states != manager){
			delete this->states;
		}
		this->states = manager;
	}
	
	ame::AppStateManager *ame::SimpleApplication::getStateManager(){
		return this->states;
	}
	
	void ame::SimpleApplication::setTimeControl(TimeControl *timecontrol){
		
	}
	
	ame::TimeControl *ame::SimpleApplication::getTimeControl(){
		return SimpleTimer::getInstance();
	}
	
	ame::Listener* ame::SimpleApplication::setListener(Listener *l){
		listener = l;
		listener->attach(this);
		return l;
	}
	
	ame::Listener *ame::SimpleApplication::getListener(){
		return listener;
	}
	
	ame::MemoryPool* ame::SimpleApplication::setMemoryPool(MemoryPool *l){
		memory = l;
		return l;
	}
	
	ame::MemoryPool *ame::SimpleApplication::getMemoryPool(){
		return memory;
	}
		
	void ame::SimpleApplication::update(){
		this->states->update();
		if(listener != nullptr){
			listener->InterruptEvent(this->states->tpc());
		}
		if(memory != nullptr){
			memory->update(this->states->tpc());
		}
	}
	
	ame::Node* ame::SimpleApplication::getRootNode(){
		return this->rootNode;
	}
	
	ame::Node* ame::SimpleApplication::getGuiNode(){
		return this->guiNode;
	}
	
	//cppObject part
	ame::cppObjectClass* ame::SimpleApplication::getClass(){
		return Class<SimpleApplication>::classType;
	}
	
	String ame::SimpleApplication::toString(){
		return "SimpleApplication";
	}
	
	bool ame::SimpleApplication::instanceof(ame::cppObjectClass* cls){
		return cls == ame::Class<SimpleApplication>::classType || ame::Application::instanceof(cls);
	}
	
		
#endif 
