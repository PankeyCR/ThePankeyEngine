

#ifndef DefaultSettings_cpp
#define DefaultSettings_cpp

#include "DefaultSettings.h"

	ame::DefaultSettings::DefaultSettings(){
		intMap = new PrimitiveMap<String,int>(2);
		floatMap = new PrimitiveMap<String,float>(2);
		StringMap = new PrimitiveMap<String,String>(2);
		boolMap = new PrimitiveMap<String,bool>(2);
		cppObjectMap = new PrimitiveMap<String,cppObject>(2);
	}
	
	ame::DefaultSettings::~DefaultSettings(){
		delete intMap;
		delete floatMap;
		delete StringMap;
		delete boolMap;
		delete cppObjectMap;
	}
	
	void ame::DefaultSettings::addInt(String s, int i){
		this->intMap->addLValues(s,i);
	}
	
	void ame::DefaultSettings::setInt(String s, int i){
		this->intMap->setLValues(s,i);
	}
	
	int ame::DefaultSettings::getInt(String s){
		int* i = this->intMap->getByLValue(s);
		if(i == nullptr){
			return -1;
		}
		return *i;
	}
	
	bool ame::DefaultSettings::containInt(String s){
		return this->intMap->containKeyByLValue(s);
	}
	
	void ame::DefaultSettings::addFloat(String s, float i){
		this->floatMap->addLValues(s,i);
	}
	
	void ame::DefaultSettings::setFloat(String s, float i){
		this->floatMap->setLValues(s,i);
	}
	
	float ame::DefaultSettings::getFloat(String s){
		float* f = this->floatMap->getByLValue(s);
		if(f == nullptr){
			return -1;
		}
		return *f;
	}
	
	bool ame::DefaultSettings::containFloat(String s){
		return this->floatMap->containKeyByLValue(s);
	}
	
	void ame::DefaultSettings::addString(String s, String i){
		this->StringMap->addLValues(s,i);
	}
	
	void ame::DefaultSettings::setString(String s, String i){
		this->StringMap->setLValues(s,i);
	}
	
	bool ame::DefaultSettings::containString(String s){
		return this->StringMap->containKeyByLValue(s);
	}
	
	String ame::DefaultSettings::getString(String s){
		String* st = this->StringMap->getByLValue(s);
		if(st == nullptr){
			return "";
		}
		return *st;
	}
	
	void ame::DefaultSettings::addBoolean(String s, bool i){
		this->boolMap->addLValues(s,i);
	}
	
	void ame::DefaultSettings::setBoolean(String s, bool i){
		this->boolMap->setLValues(s,i);
	}
	
	bool ame::DefaultSettings::getBoolean(String s){
		bool* b = this->boolMap->getByLValue(s);
		if(b == nullptr){
			return false;
		}
		return *b;
	}
	
	bool ame::DefaultSettings::containBoolean(String s){
		return this->boolMap->containKeyByLValue(s);
	}
	
	void ame::DefaultSettings::addCppObject(String s, cppObject *i){
		this->cppObjectMap->addPointer(s,i);
	}
	
	void ame::DefaultSettings::setCppObject(String s, cppObject *i){
		this->cppObjectMap->setPointer(s,i);
	}
	
	ame::cppObject *ame::DefaultSettings::getCppObject(String s){
		return this->cppObjectMap->getByLValue(s);
	}
	
	bool ame::DefaultSettings::containCppObject(String s){
		return this->cppObjectMap->containKeyByLValue(s);
	}
	String ame::DefaultSettings::toString(){
		return "DefaultSettings";
	}
	ame::cppObjectClass* ame::DefaultSettings::getClass(){
		return ame::Class<DefaultSettings>::classType;
	}
	
#endif 
