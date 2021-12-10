
#ifndef Order_hpp
#define Order_hpp

#ifndef ame_Enviroment_Defined
	#include "Arduino.h"
#endif

#ifdef ame_Windows

#endif

#ifdef ame_ArduinoIDE
	#include "Arduino.h"
#endif

#include "cppObject.hpp"
#include "PrimitiveList.hpp"

namespace ame{

template<class T,class... args>
class Order : public cppObject{
public:
Order(){
    name = "";
}
Order(String n, args... x){
    name = n;
	order.addPack(x...);
}
Order(const Order<T,args...>& o){
    name = o.getName();
	order.add(o.order);
}
virtual ~Order(){}
    
cppObjectClass* getClass(){
	return Class<Order>::classType;
}
    
String toString(){
	return String("Order: ") + name;
}

bool instanceof(cppObjectClass* instance){
return instance == Class<Order>::classType || cppObject::instanceof(instance);
}

String getName(){
	return name;
}
    
int getSize(){
	return order.getSize();
}

T* getByIndex(int index){
	return order.getByPos(index);
}

int getOrder(cppObject* element){
	for(int x=0; x < order.getPos(); x++){
		if(order.getByPos(x)->equal(element)){
			return x;
		}
	}
	return -1;
}

bool equal(cppObject* obj){        
	if(obj==this){
		return true;
	}
	if(obj->instanceof<Order<T>>()){
		if(this->getName() != ((Order*)obj)->getName()){
			return false;
		}
		if(order.getPos() != ((Order*)obj)->order.getPos()){
			return false;
		}
		for(int x=0; x < order.getPos(); x++){
			if(!((Order*)obj)->order.getByPos(x)->equal(order.getByPos(x))){
				return false;
			}
		}
		return true;
	}
	return false;
}

void operator=(const Order<T,args...>& obj){
    name = obj.getName();
	order.resetDelete();
	order.add(obj.order);
}

bool operator==(const Order<T,args...>& obj){
	if(this->getName() != obj.getName()){
		return false;
	}
	if(order.getPos() != obj.order.getPos()){
		return false;
	}
	for(int x=0; x < order.getPos(); x++){
		if(!obj.order.getByPos(x)->equal(order.getByPos(x))){
			return false;
		}
	}
	return true;
}
        

protected:
    String name;
    PrimitiveList<T> order;
};

}

#endif