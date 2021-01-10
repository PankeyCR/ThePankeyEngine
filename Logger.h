
#ifndef Logger_h
#define Logger_h

#ifdef LogApp
	#define initializeLogger(loggingS) Logger::getLog()->setLog(loggingS)
	#define Log(name,method,type,mns) Logger::StaticLog(name,method,type,mns)
	#define LogClass(name) Logger::addClass(name)
	#define LogMethod(name) Logger::addMethod(name)
	#define UnLogClass(name) Logger::removeClass(name)
	#define UnLogMethod(name) Logger::removeMethod(name)
#else
	#define initializeLogger(loggingS) 
	#define Log(name,method,type,mns) 
	#define LogClass(name) 
	#define LogMethod(name) 
	#define UnLogClass(name) 
	#define UnLogMethod(name) 
#endif

#include "Stream.h"
#include "Logging.h"
class Logger {
	public:
		virtual ~Logger();
		static Logger *getLog();
		static void StaticLog(String className, String methodName, String type, String mns);
		
		static void addClass(String className);
		static void addMethod(String methodName);
		
		static void removeClass(String className);
		static void removeMethod(String className);
	
		virtual void setLog(Logging* l);
	protected:
		Logger();
		static Logger *log;
		Logging* logging = nullptr;
};
#endif 