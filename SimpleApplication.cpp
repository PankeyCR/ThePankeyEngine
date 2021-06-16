

#ifndef SimpleApplication_cpp
#define SimpleApplication_cpp

#include "SimpleApplication.h"

	SimpleApplication::SimpleApplication(){
		this->states = new RenderStateManager();
		this->settings = new DefaultSettings();
		this->states->setApplication(this);
		this->rootNode = new Node();
		this->guiNode = new Node();
	}
	
	SimpleApplication::~SimpleApplication(){
		delete this->states;
		delete this->settings;
		delete this->rootNode;
		delete this->guiNode;
	}
	
	void SimpleApplication::setSettings(AppSettings *set){
		if(set != nullptr && this->settings != set){
			delete this->settings;
		}
		this->settings = set;
	}
	
	AppSettings *SimpleApplication::getSettings(){
		return this->settings;
	}
	
	void SimpleApplication::setStateManager(AppStateManager *manager){
		if(manager != nullptr && this->states != manager){
			delete this->states;
		}
		this->states = manager;
	}
	
	AppStateManager *SimpleApplication::getStateManager(){
		return this->states;
	}
	
	void SimpleApplication::setTimeControl(TimeControl *timecontrol){
		
	}
	
	TimeControl *SimpleApplication::getTimeControl(){
		return SimpleTimer::getInstance();
	}
	
	Listener* SimpleApplication::setListener(Listener *l){
		listener = l;
		listener->attach(this);
		return l;
	}
	
	Listener *SimpleApplication::getListener(){
		return listener;
	}
		
	void SimpleApplication::update(){
		this->states->update();
		if(listener != nullptr){
			listener->InterruptEvent(this->states->tpc());
		}
	}
	
	Node* SimpleApplication::getRootNode(){
		return this->rootNode;
	}
	
	Node* SimpleApplication::getGuiNode(){
		return this->guiNode;
	}
	
	//cppObject part
	String SimpleApplication::getClassName(){
		return "SimpleApplication";
	}
	
	String SimpleApplication::toString(){
		return "SimpleApplication";
	}
	
	bool SimpleApplication::instanceof(String name){
		return name == "SimpleApplication" || name == "Application";
	}
	
		
#endif 
