
#ifndef AppSettings_hpp
#define AppSettings_hpp
#define AppSettings_AVAILABLE

#include "cppObject.hpp"
#include "Note.hpp"

namespace ame{

class AppSettings : public cppObject{
	private:	
	
    public:
		virtual ~AppSettings(){}
		
		virtual void addInt(Note s, int i)=0;
		virtual void setInt(Note s, int i)=0;
		virtual int getInt(Note s)=0;
		virtual bool containInt(Note s)=0;
		
		virtual void addFloat(Note s, float i)=0;
		virtual void setFloat(Note s, float i)=0;
		virtual float getFloat(Note s)=0;
		virtual bool containFloat(Note s)=0;
		
		virtual void addNote(Note s, Note i)=0;
		virtual void setNote(Note s, Note i)=0;
		virtual bool containNote(Note s)=0;
		virtual Note getNote(Note s)=0;
		
		virtual void addBoolean(Note s, bool i)=0;
		virtual void setBoolean(Note s, bool i)=0;
		virtual bool getBoolean(Note s)=0;
		virtual bool containBoolean(Note s)=0;
		
		virtual void addCppObject(Note s, cppObject *i)=0;
		virtual void setCppObject(Note s, cppObject *i)=0;
		virtual cppObject *getCppObject(Note s)=0;
		virtual bool containCppObject(Note s)=0;
};

}

#endif
