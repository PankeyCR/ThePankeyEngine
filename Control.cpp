
#ifndef Control_cpp
#define Control_cpp

#include "Control.h"
	
	Control::Control(){
		
	}
	
	Control::~Control(){
		
	}
	
	void Control::set(GameObject *obj){
		object = obj;
	}
	
	GameObject *Control::get(){
		return object;
	}
	
	void Control::update(){
		
	}
	
	bool Control::isValidControl(){
		if(this->object == nullptr){
			return false;
		}
		return true;
	}
	
	void Control::onDelete(){
		
	}
	
	String Control::getClassName(){
		return "Control";
	}
	
	String Control::toString(){
		return "Control";
	}
	
	Control *Control::clone(){
		Control *control = new Control();
		control->object = this->object;
		return control;
	}
	
    void Control::operator =(Control c){
			
	}
	
    bool Control::operator ==(Control c){
		if(this->object == nullptr){
			return false;
		}
		return this->getClassName() == c.getClassName();
	}
	
    bool Control::operator !=(Control c){
		if(this->object == nullptr){
			return true;
		}
		return this->getClassName() != c.getClassName();
	}
#endif 
