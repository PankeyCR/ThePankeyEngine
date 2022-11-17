
#ifndef CONFIGURATION_AppSettings_hpp
#define CONFIGURATION_AppSettings_hpp

	#include "ame_Enviroment.hpp"

	#if defined(DISABLE_AppSettings)
		#define AppSettings_hpp

		#define IMPLEMENTATION_AppSettings
		#define IMPLEMENTING_AppSettings
	#else
		#if defined(DISABLE_IMPLEMENTATION_AppSettings)
			#define IMPLEMENTATION_AppSettings
			#define IMPLEMENTING_AppSettings
		#endif
	#endif
#endif

#ifndef AppSettings_hpp
#define AppSettings_hpp
#define AppSettings_AVAILABLE

#ifndef DISABLE_IMPLEMENTATION_AppSettings
	#define IMPLEMENTATION_AppSettings IMPLEMENTATION(public AppSettings)
	#define IMPLEMENTING_AppSettings IMPLEMENTING(public AppSettings)
#endif

#include "cppObject.hpp"
#include "Note.hpp"

namespace ame{

/*
*	Class Configuration:
*	DISABLE_cppObject
*	DISABLE_cppObjectClass
*	DISABLE_AbstractClass
*	DISABLE_IMPLEMENTATION_cppObject
*/
class AppSettings IMPLEMENTATION_cppObject {
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
		
		#if defined(cppObject_AVAILABLE)
		virtual void addCppObject(Note s, cppObject *i)=0;
		virtual void setCppObject(Note s, cppObject *i)=0;
		virtual cppObject *getCppObject(Note s)=0;
		virtual bool containCppObject(Note s)=0;
		#endif

		#if defined(cppObject_AVAILABLE) && defined(cppObjectClass_AVAILABLE) && defined(AbstractClass_AVAILABLE)
		virtual cppObjectClass* getClass(){
			return AbstractClass<AppSettings>::classType;
		}
		
		virtual bool instanceof(cppObjectClass* cls){
			return cls == AbstractClass<AppSettings>::classType;
		}
		#endif
};

}

#endif
