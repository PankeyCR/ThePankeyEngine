

#ifndef DefaultSettings_cpp
#define DefaultSettings_cpp

#include "DefaultSettings.h"

	DefaultSettings::DefaultSettings(){
		intMap = new PrimitiveMap<String,int>(1);
		floatMap = new PrimitiveMap<String,float>(1);
		StringMap = new PrimitiveMap<String,String>(1);
		boolMap = new PrimitiveMap<String,bool>(1);
		cppObjectMap = new PrimitiveMap<String,cppObject>(1);
	}
	
	DefaultSettings::~DefaultSettings(){
		delete intMap;
		delete floatMap;
		delete StringMap;
		delete boolMap;
		delete cppObjectMap;
	}
	
	void DefaultSettings::addInt(String s, int i){
		this->intMap->add(s,i);
	}
	
	void DefaultSettings::setInt(String s, int i){
		this->intMap->set(s,i);
	}
	
	int DefaultSettings::getInt(String s){
		return *this->intMap->get(s);
	}
	
	bool DefaultSettings::containInt(String s){
		return this->intMap->contain(s);
	}
	
	void DefaultSettings::addFloat(String s, float i){
		this->floatMap->add(s,i);
	}
	
	void DefaultSettings::setFloat(String s, float i){
		this->floatMap->set(s,i);
	}
	
	float DefaultSettings::getFloat(String s){
		return *this->floatMap->get(s);
	}
	
	bool DefaultSettings::containFloat(String s){
		return this->floatMap->contain(s);
	}
	
	void DefaultSettings::addString(String s, String i){
		this->StringMap->add(s,i);
	}
	
	void DefaultSettings::setString(String s, String i){
		this->StringMap->set(s,i);
	}
	
	bool DefaultSettings::containString(String s){
		return this->StringMap->contain(s);
	}
	
	String DefaultSettings::getString(String s){
		return *this->StringMap->get(s);
	}
	
	void DefaultSettings::addBoolean(String s, bool i){
		this->boolMap->add(s,i);
	}
	
	void DefaultSettings::setBoolean(String s, bool i){
		this->boolMap->set(s,i);
	}
	
	bool DefaultSettings::getBoolean(String s){
		return *this->boolMap->get(s);
	}
	
	bool DefaultSettings::containBoolean(String s){
		return this->boolMap->contain(s);
	}
	
	void DefaultSettings::addCppObject(String s, cppObject *i){
		this->cppObjectMap->add(s,i);
	}
	
	void DefaultSettings::setCppObject(String s, cppObject *i){
		this->cppObjectMap->set(s,i);
	}
	
	cppObject *DefaultSettings::getCppObject(String s){
		return this->cppObjectMap->get(s);
	}
	
	bool DefaultSettings::containCppObject(String s){
		return this->cppObjectMap->contain(s);
	}
	
#endif 
