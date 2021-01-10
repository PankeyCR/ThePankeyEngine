

#ifndef SimpleAppSettings_h
#define SimpleAppSettings_h

#include "KVMap.h"
#include "KPMap.h"
#include "AppSettings.h"

template <int size>
class SimpleAppSettings : public AppSettings{
    public:
		SimpleAppSettings(){
			intMap = new KVMap<String,int,size>();
			floatMap = new KVMap<String,float,size>();
			StringMap = new KVMap<String,String,size>();
			booleanMap = new KVMap<String,bool,size>();
			cppObjectMap = new KPMap<String,cppObject,size>(true);
		}
		~SimpleAppSettings(){
			delete intMap;
			delete floatMap;
			delete StringMap;
			delete booleanMap;
			delete cppObjectMap;
		}
		String toString(){
			return "SimpleAppSettings";
		}
		String getClassName(){
			return "SimpleAppSettings";
		}
		SimpleAppSettings *clone(){
			return new SimpleAppSettings();
		}
		void onDelete(){
			intMap->onDelete();
			floatMap->onDelete();
			StringMap->onDelete();
			booleanMap->onDelete();
		}
		void addInt(String s, int i){
			intMap->addLValues(s,i);
		}
		void setInt(String s, int i){
			intMap->setLValues(s,i);
		}
		int getInt(String s){
			return *intMap->getByLValue(s);
		}
		boolean containInt(String s){
			return intMap->containKeyByLValue(s);
		}
		void addFloat(String s, float i){
			floatMap->addLValues(s,i);
		}
		void setFloat(String s, float i){
			floatMap->setLValues(s,i);
		}
		float getFloat(String s){
			return *floatMap->getByLValue(s);
		}
		boolean containFloat(String s){
			return floatMap->containKeyByLValue(s);
		}
		void addString(String s, String i){
			StringMap->addLValues(s,i);
		}
		void setString(String s, String i){
			StringMap->setLValues(s,i);
		}
		boolean containString(String s){
			return StringMap->containKeyByLValue(s);
		}
		String getString(String s){
			return *StringMap->getByLValue(s);
		}
		void addBoolean(String s, bool i){
			booleanMap->addLValues(s,i);
		}
		void setBoolean(String s, bool i){
			booleanMap->setLValues(s,i);
		}
		bool getBoolean(String s){
			return *booleanMap->getByLValue(s);
		}
		bool containBoolean(String s){
			return booleanMap->containKeyByLValue(s);
		}
		void addCppObject(String s, cppObject *i){
			cppObjectMap->addPointer(s,i);
		}
		void setCppObject(String s, cppObject *i){
			cppObjectMap->setPointer(s,i);
		}
		cppObject *getCppObject(String s){
			return cppObjectMap->getByLValue(s);
		}
		bool containCppObject(String s){
			return cppObjectMap->containKeyByLValue(s);
		}
	protected:
		Map<String,int> *intMap;
		Map<String,float> *floatMap;
		Map<String,String> *StringMap;
		Map<String,bool> *booleanMap;
		Map<String,cppObject> *cppObjectMap;
};

#endif 
