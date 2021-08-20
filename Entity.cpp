
#ifndef Entity_cpp
#define Entity_cpp

#include "Entity.h"
	
	ame::Entity::Entity(){
		// this->childs = new PrimitiveList<GameOn>();
		this->data = new ame::PrimitiveMap<String,ame::cppObject>();
	}
	
	ame::Entity::Entity(int idEntity){
		this->setId(idEntity);
		this->childs = new ame::PrimitiveList<ame::GameOn>();
		this->data = new ame::PrimitiveMap<String,ame::cppObject>();
	}
	
	ame::Entity::~Entity(){
		if(this->data != nullptr){
			delete this->data;
		}
	}
	
    void ame::Entity::setData(String name, ame::cppObject* obj){
		if(this->data->containKeyByLValue(name)){
			this->data->setPointer(name,obj);
			return;
		}
		this->data->addPointer(name,obj);
	}
	
    ame::cppObject* ame::Entity::getData(String name){
		return this->data->getByLValue(name);
	}
	
	ame::cppObjectClass* ame::Entity::getClass(){
		return ame::Class<Entity>::classType;
	}
	
	String ame::Entity::toString(){
		return "ame::Entity";
	}

#endif 
