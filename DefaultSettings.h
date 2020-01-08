

#ifndef DefaultSettings_h
#define DefaultSettings_h

#include "PrimitiveMap.h"
#include "AppSettings.h"

class DefaultSettings : public AppSettings{
    public:
		Map<String,int> *intMap;
		Map<String,float> *floatMap;
		Map<String,String> *StringMap;
		Map<String,bool> *boolMap;
		Map<String,cppObject> *cppObjectMap;
		
		DefaultSettings();
		~DefaultSettings();
		
		void addInt(String s, int i);
		void setInt(String s, int i);
		int getInt(String s);
		bool containInt(String s);
		
		void addFloat(String s, float i);
		void setFloat(String s, float i);
		float getFloat(String s);
		bool containFloat(String s);
		
		void addString(String s, String i);
		void setString(String s, String i);
		String getString(String s);
		bool containString(String s);
		
		void addBoolean(String s, bool i);
		void setBoolean(String s, bool i);
		bool getBoolean(String s);
		bool containBoolean(String s);
		
		void addCppObject(String s, cppObject *i);
		void setCppObject(String s, cppObject *i);
		cppObject *getCppObject(String s);
		bool containCppObject(String s);
		
	private:
};

#endif 
