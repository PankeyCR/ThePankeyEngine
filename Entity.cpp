
#ifndef Entity_cpp
#define Entity_cpp

#include "Entity.h"
	
	Entity::Entity(){
		this->childs = new PrimitiveList<GameOn>();
		this->data = new PrimitiveMap<String,cppObject>();
	}
	
	Entity::Entity(String idEntity){
		this->setId(idEntity);
		this->childs = new PrimitiveList<GameOn>();
		this->data = new PrimitiveMap<String,cppObject>();
	}
	
	Entity::~Entity(){
		if(this->data != nullptr){
			delete this->data;
		}
	}
	
    void Entity::setData(String name, cppObject* obj){
		if(this->data->contain(name)){
			this->data->set(name,obj);
			return;
		}
		this->data->add(name,obj);
	}
	
    cppObject* Entity::getData(String name){
		return this->data->get(name);
	}
	
	String Entity::getClassName(){
		return "Entity";
	}
	
	String Entity::toString(){
		return "Entity";
	}

#endif 
