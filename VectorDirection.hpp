
#ifndef VectorDirection_hpp
#define VectorDirection_hpp

#include "cppObject.hpp"

namespace ame{

class VectorDirection : public cppObject{
public:
VectorDirection(){
    vector = "x";
    direction = true;
}
VectorDirection(const Vector& v, const bool& d){
    vector = v;
    direction = d;
}
VectorDirection(const char* n, const bool& d){
    vector = n;
    direction = d;
}
virtual ~VectorDirection(){}
    
cppObjectClass* getClass(){
	return Class<VectorDirection>::classType;
}
    
String toString(){
	return this->vector.getName() + String(" ") + String (this->direction);
}
    
Vector getVector(){
	return this->vector;
}

bool getDirection(){
	return this->direction;
}

void setDirection(bool dir){
	this->direction = dir;
}

bool equal(cppObject* obj){
	if(obj==this){
		return true;
	}
	if(obj->instanceof<Vector>()){
		if(((Vector*)obj)->getName() == this->vector.getName()){
			return true;
		}
	}
	if(obj->instanceof<VectorDirection>()){
		if(((VectorDirection*)obj)->getDirection() == this->getDirection() && ((VectorDirection*)obj)->getVector() == this->getVector() ){
			return true;
		}
	}
	return false;
}

bool equal(const VectorDirection& obj){
	if(obj.getDirection() == this->getDirection() && obj.getVector() == this->getVector() ){
			return true;
		}
	return false;
}

VectorDirection* clone(){
	VectorDirection* cloner = new VectorDirection(this->getVector(),this->getDirection());
	return cloner;
}

bool instanceof(cppObjectClass* instance){
return instance == Class<VectorDirection>::classType || cppObject::instanceof(instance);
}

bool operator==(const VectorDirection& obj){
	if(obj.getVector().getName() == this->getVector().getName() &&
		obj.getDirection() == this->getDirection()){
		return true;
	}
	return false;
}

bool operator!=(const VectorDirection& obj){
	if(obj.getVector().getName() != this->getVector().getName() &&
		obj.getDirection() != this->getDirection()){
		return true;
	}
	return false;
}

bool operator==(const bool& n){
	return this->getDirection() == n;
}

bool operator!=(const bool& n){
	return this->getDirection() != n;
}

bool operator==(const Vector& obj){
	return obj.getName() == this->getVector().getName();
}

bool operator!=(const Vector& obj){
	return obj.getName() != this->getVector().getName();
}
    
protected:
Vector vector;
bool direction;
};

}

#endif