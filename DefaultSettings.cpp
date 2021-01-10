

#ifndef DefaultSettings_cpp
#define DefaultSettings_cpp

#include "DefaultSettings.h"

	DefaultSettings::DefaultSettings(){
		intMap = new PrimitiveMap<String,int>(2);
		floatMap = new PrimitiveMap<String,float>(2);
		StringMap = new PrimitiveMap<String,String>(2);
		boolMap = new PrimitiveMap<String,bool>(2);
		cppObjectMap = new PrimitiveMap<String,cppObject>(2);
	}
	
	DefaultSettings::~DefaultSettings(){
		delete intMap;
		delete floatMap;
		delete StringMap;
		delete boolMap;
		delete cppObjectMap;
	}
	
	void DefaultSettings::addInt(String s, int i){
		this->intMap->addLValues(s,i);
	}
	
	void DefaultSettings::setInt(String s, int i){
		this->intMap->setLValues(s,i);
	}
	
	int DefaultSettings::getInt(String s){
		return *this->intMap->getByLValue(s);
	}
	
	bool DefaultSettings::containInt(String s){
		return this->intMap->containKeyByLValue(s);
	}
	
	void DefaultSettings::addFloat(String s, float i){
		this->floatMap->addLValues(s,i);
	}
	
	void DefaultSettings::setFloat(String s, float i){
		this->floatMap->setLValues(s,i);
	}
	
	float DefaultSettings::getFloat(String s){
		return *this->floatMap->getByLValue(s);
	}
	
	bool DefaultSettings::containFloat(String s){
		return this->floatMap->containKeyByLValue(s);
	}
	
	void DefaultSettings::addString(String s, String i){
		this->StringMap->addLValues(s,i);
	}
	
	void DefaultSettings::setString(String s, String i){
		this->StringMap->setLValues(s,i);
	}
	
	bool DefaultSettings::containString(String s){
		return this->StringMap->containKeyByLValue(s);
	}
	
	String DefaultSettings::getString(String s){
		return *this->StringMap->getByLValue(s);
	}
	
	void DefaultSettings::addBoolean(String s, bool i){
		this->boolMap->addLValues(s,i);
	}
	
	void DefaultSettings::setBoolean(String s, bool i){
		this->boolMap->setLValues(s,i);
	}
	
	bool DefaultSettings::getBoolean(String s){
		return *this->boolMap->getByLValue(s);
	}
	
	bool DefaultSettings::containBoolean(String s){
		return this->boolMap->containKeyByLValue(s);
	}
	
	void DefaultSettings::addCppObject(String s, cppObject *i){
		this->cppObjectMap->addPointer(s,i);
	}
	
	void DefaultSettings::setCppObject(String s, cppObject *i){
		this->cppObjectMap->setPointer(s,i);
	}
	
	cppObject *DefaultSettings::getCppObject(String s){
		return this->cppObjectMap->getByLValue(s);
	}
	
	bool DefaultSettings::containCppObject(String s){
		return this->cppObjectMap->containKeyByLValue(s);
	}
	String DefaultSettings::toString(){
		return "DefaultSettings";
	}
	String DefaultSettings::getClassName(){
		return "DefaultSettings";
	}
	
#endif 
