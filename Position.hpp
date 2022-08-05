
#include "ame_Enviroment.hpp"

#ifndef Position_hpp
#define Position_hpp
/*
#include "cppObject.hpp"
#include "VectorValue.hpp"

template<class... args>
class Position : public cppObject{
public:
Position(){
	name = "origin";
}
Position(const char* n, args... x){
	name = n;
	vectors.addPack(x...);
}
Position(const String& n, args... x){
	name = n;
	vectors.addPack(x...);
}
virtual ~Position(){}
    
    
String getClassName(){
	return "Position";
}
    
String toString(){
	return String("Position: ") + name;
}

void addVectorValue(Vector vector,float value){
	vectors.add(new VectorValue(vector, value));
}

void addVectorValue(VectorValue vector){
	this.vectors.add(vector);
}

void addVectorValue(String vector,float value){
	this.vectors.add(new VectorValue(vector, value));
}

Vector getVector(int index){
	if(vectors.getByPos(index)==nullptr){
		return nullptr;
	}
	return vectors.getByPos(index)->getVector();
}

float getVectorValue(int index){
	if(vectors.getByPos(index)==nullptr){
		return 0;
	}
	return vectors.getByPos(index)->getValue();
}

void setVectorValue(VectorValue vector){
	for(int x=0; x<vectors.getPos();x++){
		if(vectors.getByPos(x).getVector().equal(vector.getVector())){
			vectors.getByPos(x)->setValue(vector.getValue());
		}
	}
}

void setVectorValue(int index,float value){
	if(vectors.getByPos(index)==nullptr){
		return;
	}
	vectors.getByPos(index)->setValue(value);
}

void setVectorValue(Vector vector,float value){
	for(int x=0; x<vectors.getPos();x++){
		if(vectors.getByPos(x).getVector().equal(vector)){
			vectors.getByPos(x).setValue(value);
		}
	}
}

void setVectorValue(FixVector vector,float value){
	for(int x=0; x<vectors.getPos();x++){
		if(vectors.getByPos(x)->getVector().equal(vector.getVector())){
			vectors.getByPos(x)->setValue(value);
		}
	}
}

bool containVector(String n){
	for(int x=0; x<vectors.getPos();x++){
		if(vectors.getByPos(x)->getVector() == n){
			return true;
		}
	}
	return false;
}

bool containVector(const char* n){
	for(int x=0; x<vectors.getPos();x++){
		if(vectors.getByPos(x)->getVector() == n){
			return true;
		}
	}
	return false;
}

bool containVector(Vector vector){
	for(int x=0; x<vectors.getPos();x++){
		if(vectors.getByPos(x)->getVector().equal(vector)){
			return true;
		}
	}
	return false;
}
/////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////
Vector getVector(String index){
	for(VectorValue vv : this.vectors.getArray()){
		if(vv.getVector().getName().equals(index)){
			return vv.getVector();
		}
	}
	return null;
}

float getVectorValue(String index){
	for(VectorValue vv : this.vectors.getArray()){
		if(vv.getVector().getName().equals(index)){
			return vv.getValue();
		}
	}
	return 0;
}

Position setVectorValue(String index,float value){
	for(VectorValue vv : this.vectors.getArray()){
		if(vv.getVector().getName().equals(index)){
			vv.setValue(value);
		}
	}
	return this;
}

float getPosition(Vector vector){
	for(int x=0; x<this.vectors.size();x++){
		if(this.vectors.get(x).getVector().equals(vector)){
			return this.vectors.get(x).getValue();
		}
	}
	return 0;
}

float getPosition(FixVector vector){
	for(int x=0; x<this.vectors.size();x++){
		if(this.vectors.get(x).getVector().equals(vector.getVector())){
			return this.vectors.get(x).getValue();
		}
	}
	return 0;
}

Position merge(Position position){
	for(VectorValue vector : this.vectors.getArray()){
		for(VectorValue vector1 : position.vectors.getArray()){
			if(!vector.getVector().equals(vector1.getVector())){
				this.addVectorValue(vector1.getVector(), vector1.getValue());
			}
		}
	}
	return this;
}

Position split(Position position){
	Position positionN = position.clone();
	for(VectorValue vector : this.vectors.getArray()){
		for(VectorValue vector1 : positionN.vectors.getArray()){
			if(vector.getVector().equals(vector1.getVector())){
				vector1.setValue(vector.getValue());
			}
		}
	}
	return positionN;
}

Position merge(GuiPositions position){
	for(VectorValue vector : this.vectors.getArray()){
		for(VectorValue vector1 : position.getPosition().vectors.getArray()){
			if(!vector.getVector().equals(vector1.getVector())){
				this.addVectorValue(vector1.getVector(), vector1.getValue());
			}
		}
	}
	return this;
}

Position split(GuiPositions position){
	Position positionN = position.clonePosition();
	for(VectorValue vector : this.vectors.getArray()){
		for(VectorValue vector1 : positionN.vectors.getArray()){
			if(vector.getVector().equals(vector1.getVector())){
				vector1.setValue(vector.getValue());
			}
		}
	}
	return positionN;
}

Position merge(String name,BoxPositions position){
	Position positionN = position.clonePosition();
	for(VectorValue vector : this.vectors.getArray()){
		for(VectorValue vector1 : positionN.vectors.getArray()){
			if(!vector.getVector().equals(vector1.getVector())){
				this.addVectorValue(vector1.getVector(), vector1.getValue());
			}
		}
	}
	positionN.name = name;
	return positionN;
}

Position split(String name,BoxPositions position){
	Position positionN = position.clonePosition();
	for(VectorValue vector : this.vectors.getArray()){
		for(VectorValue vector1 : positionN.vectors.getArray()){
			if(vector.getVector().equals(vector1.getVector())){
				vector1.setValue(vector.getValue());
			}
		}
	}
	positionN.name = name;
	return positionN;
}

String getName(){
	return this.name;
}

Position clone(){
	Position pos = new Position(this.getName());
	pos.vectors = this.vectors.clone();
	return pos;
}

boolean equals(Object obj){
	if(obj==this){
		return true;
	}
	if(obj instanceof String){
		if(((String)obj).equals(this.getName())){
			return true;
		}
	}
	if(obj instanceof GuiPositions){
		if(((GuiPositions)obj).getPosition().getName().equals(this.getName())){
			return true;
		}
	}
	if(obj instanceof BoxPositions){
		if(((BoxPositions)obj).getPosition().getName().equals(this.getName())){
			return true;
		}
	}
	
	return false;
}

bool equal(cppObject* obj){
	if(obj==this){
		return true;
	}
	if(obj->instanceof<Position>()){
		if(((Position*)obj)->vector.getName() == vector.getName()){
			return true;
		}
	}
	return false;
}

bool equal(const Position& obj){
	if(obj.vector.getName() == vector.getName()){
		return true;
	}
	return false;
}

Position* clone(){
	Position* cloner = new Position(this->getVector(),this->getValue());
	return cloner;
}

bool instanceof(String instance){
return instance == "Position" || cppObject::instanceof(instance);
}

void operator=(const Position& v){
	this->vector =  v.getVector();
	this->value =  v.getValue();
}

bool operator==(const Position& obj){
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

bool operator==(const String n){
	if(vector.getName() == n){
		return true;
	}
	return false;
}

bool operator!=(const Position& obj){
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

bool operator!=(const String n){
	if(vector.getName() != n){
		return true;
	}
	return false;
}
    
protected:
String name;
PrimitiveList<VectorValue> vectors;
};
*/
#endif