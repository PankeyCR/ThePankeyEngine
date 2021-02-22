
#ifndef Vector_h
#define Vector_h

#include "cppObject.h"

class Vector : public cppObject , public Printable{
public:
Vector(){
    this->name = "x";
}
Vector(const char* n){
    this->name = String(n);
}
Vector(const String& n){
    this->name = n;
}
virtual ~Vector(){}

size_t printTo(Print& p) const{
	p.print(this->name);
}

String getName(){
	return this->name;
}
    
String getClassName(){
	return "Vector";
}
    
String toString(){
	return String("Vector: ") + this->name;
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

bool instanceof(String instance){
return instance == "Vector" || cppObject::instanceof(instance);
}

void operator=(Vector v){
	this->name =  v.getName();
}

void operator=(const char* n){
	this->name =  String(n);
}

void operator=(const String& n){
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

bool operator==(const String& n){
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

bool operator!=(const String& n){
	if(this->getName() != n){
		return true;
	}
	return false;
}
    
protected:
String name; 
};

#endif