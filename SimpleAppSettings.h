

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
			intMap->add(s,i);
		}
		void setInt(String s, int i){
			intMap->set(s,i);
		}
		int getInt(String s){
			return *intMap->get(s);
		}
		boolean containInt(String s){
			return intMap->contain(s);
		}
		void addFloat(String s, float i){
			floatMap->add(s,i);
		}
		void setFloat(String s, float i){
			floatMap->set(s,i);
		}
		float getFloat(String s){
			return *floatMap->get(s);
		}
		boolean containFloat(String s){
			return floatMap->contain(s);
		}
		void addString(String s, String i){
			StringMap->add(s,i);
		}
		void setString(String s, String i){
			StringMap->set(s,i);
		}
		boolean containString(String s){
			return StringMap->contain(s);
		}
		String getString(String s){
			return *StringMap->get(s);
		}
		void addBoolean(String s, bool i){
			booleanMap->add(s,i);
		}
		void setBoolean(String s, bool i){
			booleanMap->set(s,i);
		}
		bool getBoolean(String s){
			return *booleanMap->get(s);
		}
		bool containBoolean(String s){
			return booleanMap->contain(s);
		}
		void addCppObject(String s, cppObject *i){
			cppObjectMap->add(s,i);
		}
		void setCppObject(String s, cppObject *i){
			cppObjectMap->set(s,i);
		}
		cppObject *getCppObject(String s){
			return cppObjectMap->get(s);
		}
		bool containCppObject(String s){
			return cppObjectMap->contain(s);
		}
	protected:
		Map<String,int> *intMap;
		Map<String,float> *floatMap;
		Map<String,String> *StringMap;
		Map<String,bool> *booleanMap;
		Map<String,cppObject> *cppObjectMap;
};

#endif 
