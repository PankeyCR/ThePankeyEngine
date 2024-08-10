
#ifndef Vector_hpp
#define Vector_hpp

#include "cppObject.hpp"

namespace higgs{

class Vector : public cppObject , public Printable{
public:
Vector(){
    this->name = "x";
}
Vector(const char* n){
    this->name = Note(n);
}
Vector(const Note& n){
    this->name = n;
}
virtual ~Vector(){}

size_t printTo(Print& p) const{
	p.print(this->name);
}

Note getName(){
	return this->name;
}
    
cppObjectClass* getClass(){
	return Class<Vector>::classType;
}
    
Note toNote(){
	return Note("Vector: ") + this->name;
}

bool equal(cppObject* obj){
	if(obj==this){
		return true;
	}
	if(obj->instanceof<Vector>()){
		if(((Vector*)obj)->getName() == this->getName()){
			return true;
		}
	}
	return false;
}

Vector* clone(){
	Vector* cloner = new Vector(this->getName());
	return cloner;
}

bool instanceof(cppObjectClass* instance){
return instance == Class<Vector>::classType || cppObject::instanceof(instance);
}

void operator=(Vector v){
	this->name =  v.getName();
}

void operator=(const char* n){
	this->name =  Note(n);
}

void operator=(const Note& n){
	this->name =  n;
}

bool operator==(Vector obj){
	if(obj.getName() == this->getName()){
		return true;
	}
	return false;
}

bool operator==(const char* n){
	if(this->getName() == n){
		return true;
	}
	return false;
}

bool operator==(const Note& n){
	if(this->getName() == n){
		return true;
	}
	return false;
}

bool operator!=(Vector obj){
	if(obj.getName() != this->getName()){
		return true;
	}
	return false;
}

bool operator!=(const char* n){
	if(this->getName() != n){
		return true;
	}
	return false;
}

bool operator!=(const Note& n){
	if(this->getName() != n){
		return true;
	}
	return false;
}
    
protected:
Note name; 
};

}

#endif