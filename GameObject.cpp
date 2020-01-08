
#ifndef GameObject_cpp
#define GameObject_cpp

#include "GameObject.h"

	GameObject::GameObject(){
		controls = new PList<Control,5>();
		childs = new PList<GameObject,5>();
	}
	
	GameObject::~GameObject(){
		delete controls;
		delete childs;
	}
	
	void GameObject::setParent(GameObject *obj){
		parent = obj;
	}
	
	GameObject *GameObject::get(){
		return parent;
	}
	
    void GameObject::update(){
		for(int x=0; x < controls->getPos(); x++){
			controls->getByPos(x)->update();
		}
		for(int x=0; x < childs->getPos(); x++){
			childs->getByPos(x)->update();
		}
	}
	
    void GameObject::addControl(Control *control){
		control->set(this);
		controls->add(control);
	}
	
    Control *GameObject::getControl(String className){
		for(int x=0; x < controls->getPos(); x++){
			if(controls->getByPos(x)->getClassName() == className){
				return controls->getByPos(x);				
			}
		}
		return nullptr;
	}
	
    Control *GameObject::getControl(Control *control){
		return controls->get(control);
	}
	
    Control *GameObject::getControl(int control){
		return controls->getByPos(control);
	}
	
    Control *GameObject::removeControl(Control *control){
		control->set(nullptr);
		return controls->remove(control);
	}
	
    Control *GameObject::removeControl(int control){
		Control *c = controls->removeByPos(control);
		if(c == nullptr){
			return nullptr;
		}
		c->set(nullptr);
		return c;
	}
	
    void GameObject::attach(GameObject *gameobject){
		gameobject->setParent(this);
		childs->add(gameobject);		
	}
	
    GameObject *GameObject::getChild(String className){
		for(int x=0; x < childs->getPos(); x++){
			if(childs->getByPos(x)->getClassName() == className){
				return childs->getByPos(x);				
			}
		}
		return nullptr;
	}
	
    GameObject *GameObject::getChild(GameObject *gameobject){
		return childs->get(gameobject);
	}
	
    GameObject *GameObject::getChild(int control){
		return childs->getByPos(control);
	}
	
    GameObject *GameObject::detach(GameObject *gameobject){
		gameobject->parent = nullptr;
		return childs->remove(gameobject);		
	}
	
    GameObject *GameObject::detach(int gameobject){
		GameObject *g = childs->removeByPos(gameobject);
		if(g == nullptr){
			return nullptr;
		}
		g->parent = nullptr;
		return g;		
	}
	
	void GameObject::onDelete(){
		controls->onDelete();
		childs->onDelete();
	}
	
	String GameObject::getClassName(){
		return "GameObject";
	}
	
	String GameObject::toString(){
		return "GameObject";
	}
	
	GameObject *GameObject::clone(){
		GameObject *gameobj = new GameObject();
		gameobj->controls = (List<Control>*)this->controls->clone();
		gameobj->childs = (List<GameObject>*)this->childs->clone();
		gameobj->parent = nullptr;
		return gameobj;
	}
	
    void GameObject::operator =(GameObject c){
			
	}
	
    bool GameObject::operator ==(GameObject c){
		return getClassName() == c.getClassName();
	}
	
    bool GameObject::operator !=(GameObject c){
		return getClassName() != c.getClassName();
	}

#endif 
