
#include "ame_Level.hpp"

#if defined(ame_untilLevel_7)

#ifndef DefaultSettings_hpp
#define DefaultSettings_hpp

#include "PrimitiveMap.hpp"
#include "AppSettings.hpp"

namespace ame{

class DefaultSettings : public AppSettings{
    public:
		DefaultSettings(){
			intMap = new PrimitiveMap<String,int>(2);
			floatMap = new PrimitiveMap<String,float>(2);
			StringMap = new PrimitiveMap<String,String>(2);
			boolMap = new PrimitiveMap<String,bool>(2);
			cppObjectMap = new PrimitiveMap<String,cppObject>(2);
		}
		virtual ~DefaultSettings(){
			delete intMap;
			delete floatMap;
			delete StringMap;
			delete boolMap;
			delete cppObjectMap;
		}
		
		virtual void addInt(String s, int i){
			this->intMap->addLValues(s,i);
		}
		virtual void setInt(String s, int i){
			this->intMap->setLValues(s,i);
		}
		virtual int getInt(String s){
			int* i = this->intMap->getByLValue(s);
			if(i == nullptr){
				return -1;
			}
			return *i;
		}
		virtual bool containInt(String s){
			return this->intMap->containKeyByLValue(s);
		}
		
		virtual void addFloat(String s, float i){
			this->floatMap->addLValues(s,i);
		}
		virtual void setFloat(String s, float i){
			this->floatMap->setLValues(s,i);
		}
		virtual float getFloat(String s){
			float* f = this->floatMap->getByLValue(s);
			if(f == nullptr){
				return -1.0f;
			}
			return *f;
		}
		virtual bool containFloat(String s){
			return this->floatMap->containKeyByLValue(s);
		}
		
		virtual void addString(String s, String i){
			this->StringMap->addLValues(s,i);
		}
		virtual void setString(String s, String i){
			this->StringMap->setLValues(s,i);
		}
		virtual String getString(String s){
			String* st = this->StringMap->getByLValue(s);
			if(st == nullptr){
				return "";
			}
			return *st;
		}
		virtual bool containString(String s){
			return this->StringMap->containKeyByLValue(s);
		}
		
		virtual void addBoolean(String s, bool i){
			this->boolMap->addLValues(s,i);
		}
		virtual void setBoolean(String s, bool i){
			this->boolMap->setLValues(s,i);
		}
		virtual bool getBoolean(String s){
			bool* b = this->boolMap->getByLValue(s);
			if(b == nullptr){
				return false;
			}
			return *b;
		}
		virtual bool containBoolean(String s){
			return this->boolMap->containKeyByLValue(s);
		}
		
		virtual void addCppObject(String s, cppObject *i){
			this->cppObjectMap->addPointer(s,i);
		}
		virtual void setCppObject(String s, cppObject *i){
			this->cppObjectMap->setPointer(s,i);
		}
		virtual cppObject *getCppObject(String s){
			return this->cppObjectMap->getByLValue(s);
		}
		virtual bool containCppObject(String s){
			return this->cppObjectMap->containKeyByLValue(s);
		}
		
		virtual String toString(){
			return "DefaultSettings";
		}
		virtual cppObjectClass* getClass(){
			return ame::Class<DefaultSettings>::classType;
		}
		
	protected:
		Map<String,int> *intMap;
		Map<String,float> *floatMap;
		Map<String,String> *StringMap;
		Map<String,bool> *boolMap;
		Map<String,cppObject> *cppObjectMap;
};

}

#endif 

#endif 
