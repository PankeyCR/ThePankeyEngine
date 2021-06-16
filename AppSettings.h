

#ifndef AppSettings_h
#define AppSettings_h

#include "Arduino.h"
#include "cppObject.h"

class AppSettings : public cppObject{
	private:	
	
    public:
		virtual ~AppSettings(){}
		
		virtual void addInt(String s, int i)=0;
		virtual void setInt(String s, int i)=0;
		virtual int getInt(String s)=0;
		virtual boolean containInt(String s)=0;
		
		virtual void addFloat(String s, float i)=0;
		virtual void setFloat(String s, float i)=0;
		virtual float getFloat(String s)=0;
		virtual boolean containFloat(String s)=0;
		
		virtual void addString(String s, String i)=0;
		virtual void setString(String s, String i)=0;
		virtual boolean containString(String s)=0;
		virtual String getString(String s)=0;
		
		virtual void addBoolean(String s, bool i)=0;
		virtual void setBoolean(String s, bool i)=0;
		virtual bool getBoolean(String s)=0;
		virtual bool containBoolean(String s)=0;
		
		virtual void addCppObject(String s, cppObject *i)=0;
		virtual void setCppObject(String s, cppObject *i)=0;
		virtual cppObject *getCppObject(String s)=0;
		virtual bool containCppObject(String s)=0;
};

#endif 
