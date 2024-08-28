
#ifndef VectorValue_hpp
#define VectorValue_hpp

#include "cppObject.hpp"

namespace pankey{

class VectorValue : public cppObject{
public:
VectorValue(){
	value = 0.0f;
	vector = "x";
}
VectorValue(const char* vec, float v){
	value = v;
	vector = vec;
}
VectorValue(const Note& vec, float v){
	value = v;
	vector = vec;
}
VectorValue(const Vector& vec, float v){
	value = v;
	vector = vec;
}
virtual ~VectorValue(){}
    
float getValue(){
	return value;
}

void setValue(float v){
	value=v;
}

Vector getVector(){
	return vector;
}
    
cppObjectClass* getClass(){
	return Class<VectorValue>::classType;
}
    
Note toNote(){
	return Note("VectorValue: ") + vector.getName() + Note(" ") + value;
}

bool equal(cppObject* obj){
	if(obj==this){
		return true;
	}
	if(obj->instanceof<VectorValue>()){
		if(((VectorValue*)obj)->vector.getName() == vector.getName()){
			return true;
		}
	}
	return false;
}

bool equal(const VectorValue& obj){
	if(obj.vector.getName() == vector.getName()){
		return true;
	}
	return false;
}

VectorValue* clone(){
	VectorValue* cloner = new VectorValue(this->getVector(),this->getValue());
	return cloner;
}

bool instanceof(cppObjectClass* instance){
return instance == Class<VectorValue>::classType || cppObject::instanceof(instance);
}

void operator=(const VectorValue& v){
	this->vector =  v.getVector();
	this->value =  v.getValue();
}

bool operator==(const VectorValue& obj){
	if(obj.vector.getName() == vector.getName()){
		return true;
	}
	return false;
}

bool operator==(const char* n){
	if(vector.getName() == n){
		return true;
	}
	return false;
}

bool operator==(const Note n){
	if(vector.getName() == n){
		return true;
	}
	return false;
}

bool operator!=(const VectorValue& obj){
	if(obj.vector.getName() != vector.getName()){
		return true;
	}
	return false;
}

bool operator!=(const char* n){
	if(vector.getName() != n){
		return true;
	}
	return false;
}

bool operator!=(const Note n){
	if(vector.getName() != n){
		return true;
	}
	return false;
}
    
protected:
float value;
Vector vector;
};

}

#endif