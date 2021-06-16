

#ifndef DefaultSettings_h
#define DefaultSettings_h

#include "PrimitiveMap.h"
#include "AppSettings.h"

class DefaultSettings : public AppSettings{
    public:
		DefaultSettings();
		virtual ~DefaultSettings();
		
		virtual void addInt(String s, int i);
		virtual void setInt(String s, int i);
		virtual int getInt(String s);
		virtual bool containInt(String s);
		
		virtual void addFloat(String s, float i);
		virtual void setFloat(String s, float i);
		virtual float getFloat(String s);
		virtual bool containFloat(String s);
		
		virtual void addString(String s, String i);
		virtual void setString(String s, String i);
		virtual String getString(String s);
		virtual bool containString(String s);
		
		virtual void addBoolean(String s, bool i);
		virtual void setBoolean(String s, bool i);
		virtual bool getBoolean(String s);
		virtual bool containBoolean(String s);
		
		virtual void addCppObject(String s, cppObject *i);
		virtual void setCppObject(String s, cppObject *i);
		virtual cppObject *getCppObject(String s);
		virtual bool containCppObject(String s);
		
		virtual String toString();
		virtual String getClassName();
		
	protected:
		Map<String,int> *intMap;
		Map<String,float> *floatMap;
		Map<String,String> *StringMap;
		Map<String,bool> *boolMap;
		Map<String,cppObject> *cppObjectMap;
};

#endif 
