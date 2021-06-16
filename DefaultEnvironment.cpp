/*
#ifndef DefaultEnvironment_cpp
#define DefaultEnvironment_cpp

#include "DefaultEnvironment.h"

	DefaultEnvironment::DefaultEnvironment(){
		intMap = new PrimitiveMap<String,int>(2);
		floatMap = new PrimitiveMap<String,float>(2);
		StringMap = new PrimitiveMap<String,String>(2);
		boolMap = new PrimitiveMap<String,bool>(2);
		cppObjectMap = new PrimitiveMap<String,cppObject>(2);
	}
	
	DefaultEnvironment::~DefaultEnvironment(){
		delete intMap;
		delete floatMap;
		delete StringMap;
		delete boolMap;
		delete cppObjectMap;
	}
	
	void DefaultEnvironment::addInt(String s, int i){
		this->intMap->addLValues(s,i);
	}
	
	void DefaultEnvironment::setInt(String s, int i){
		this->intMap->setLValues(s,i);
	}
	
	int DefaultEnvironment::getInt(String s){
		return *this->intMap->getByLValue(s);
	}
	
	bool DefaultEnvironment::containInt(String s){
		return this->intMap->containKeyByLValue(s);
	}
	
	void DefaultEnvironment::addFloat(String s, float i){
		this->floatMap->addLValues(s,i);
	}
	
	void DefaultEnvironment::setFloat(String s, float i){
		this->floatMap->setLValues(s,i);
	}
	
	float DefaultEnvironment::getFloat(String s){
		return *this->floatMap->getByLValue(s);
	}
	
	bool DefaultEnvironment::containFloat(String s){
		return this->floatMap->containKeyByLValue(s);
	}
	
	void DefaultEnvironment::addString(String s, String i){
		this->StringMap->addLValues(s,i);
	}
	
	void DefaultEnvironment::setString(String s, String i){
		this->StringMap->setLValues(s,i);
	}
	
	bool DefaultEnvironment::containString(String s){
		return this->StringMap->containKeyByLValue(s);
	}
	
	String DefaultEnvironment::getString(String s){
		return *this->StringMap->getByLValue(s);
	}
	
	void DefaultEnvironment::addBoolean(String s, bool i){
		this->boolMap->addLValues(s,i);
	}
	
	void DefaultEnvironment::setBoolean(String s, bool i){
		this->boolMap->setLValues(s,i);
	}
	
	bool DefaultEnvironment::getBoolean(String s){
		return *this->boolMap->getByLValue(s);
	}
	
	bool DefaultEnvironment::containBoolean(String s){
		return this->boolMap->containKeyByLValue(s);
	}
	
	void DefaultEnvironment::addCppObject(String s, cppObject *i){
		this->cppObjectMap->addPointer(s,i);
	}
	
	void DefaultEnvironment::setCppObject(String s, cppObject *i){
		this->cppObjectMap->setPointer(s,i);
	}
	
	cppObject *DefaultEnvironment::getCppObject(String s){
		return this->cppObjectMap->getByLValue(s);
	}
	
	bool DefaultEnvironment::containCppObject(String s){
		return this->cppObjectMap->containKeyByLValue(s);
	}
	String DefaultEnvironment::toString(){
		return "DefaultEnvironment";
	}
	String DefaultEnvironment::getClassName(){
		return "DefaultEnvironment";
	}
	
#endif 
*/