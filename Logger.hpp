
#ifndef Logger_hpp
#define Logger_hpp

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

#ifndef ame_Enviroment_Defined
	#include "Stream.h"
#endif

#ifdef ame_Windows

#endif

#ifdef ame_ArduinoIDE
	#include "Stream.h"
#endif

#include "Logging.hpp"

namespace ame{

class Logger {
	public:
		virtual ~Logger(){
			if(this->logging != nullptr){
				delete this->logging;
			}
		}
		
		static Logger *getLog(){
			if(Logger::log == nullptr){
				Logger::log = new Logger();
			}
			return Logger::log;
		}
		
		static void StaticLog(String className, String methodName, String type, String mns){
			Logger* m_lg = Logger::getLog();
			if(m_lg->logging == nullptr){
				// Serial.println("m_lg->logging == nullptr");
				return;
			}
			m_lg->logging->StaticLog(className, methodName, type, mns);
		}
		
		static void addClass(String className){
			Logger* m_lg = Logger::getLog();
			if(m_lg->logging == nullptr){
				return;
			}
			m_lg->logging->addClass(className);
		}
		
		static void addMethod(String methodName){
			Logger* m_lg = Logger::getLog();
			if(m_lg->logging == nullptr){
				return;
			}
			m_lg->logging->addMethod(methodName);
		}
		
		
		static void removeClass(String className){
			Logger* m_lg = Logger::getLog();
			if(m_lg->logging == nullptr){
				return;
			}
			m_lg->logging->removeClass(className);
		}
		
		static void removeMethod(String methodName){
			Logger* m_lg = Logger::getLog();
			if(m_lg->logging == nullptr){
				return;
			}
			m_lg->logging->removeMethod(methodName);
		}
	
		virtual void setLog(Logging* l){
			this->logging = l;
		}
	
	protected:
		Logger(){}
		static Logger *log;
		Logging* logging = nullptr;
};

}

ame::Logger* ame::Logger::log = nullptr;

#endif 