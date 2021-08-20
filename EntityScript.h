#ifndef EntityScript_h
#define EntityScript_h

#include "cppObject.h"
#include "GameManager.h"
#include "Annotation.h"
#include "List.h"
#include "GameOn.h"
#include "Method.h"

namespace ame{

class EntityScript : public Method{
public:

EntityScript(Stream* port, GameManager* mana){
	serial = port;
	manager = mana;
}
~EntityScript(){}


cppObject* invokeGlobal(String method, String parameter1){
	if(method == "print"){
		serial->print(parameter1);
		return nullptr;
	}
	if(method == "println"){
		serial->println(parameter1);
		return nullptr;
	}
	return nullptr;
}
cppObject* invoke(String method){
	if(method == "createEntity"){
		manager->createEntity();
		return nullptr;
	}
	if(method == "printEntitySize"){
		serial->println(manager->getEntitySize());
		return nullptr;
	}
	return nullptr;
}

cppObject* invoke(String method, String parameter){
	if(method == "print"){
		serial->print(parameter);
		return nullptr;
	}
	if(method == "println"){
		serial->println(parameter);
		return nullptr;
	}
	if(method == "printComponentSize"){
		serial->println(manager->getComponentSize(parameter.toInt()));
		return nullptr;
	}
	if(method == "printComponents"){
		List<GameOn>* list = manager->getComponents(parameter.toInt());
		iterate(list){
			serial->println(list->getPointer()->getClassName());
		}
		return nullptr;
	}
  return nullptr;
}	
		
protected:
GameManager* manager = nullptr;
Stream* serial = nullptr;
};

}

#endif 
