
#ifndef Logger_hpp
#define Logger_hpp

#ifdef LogApp
	#define initializeLogger(loggingS) Logger::getLog()->setLog(loggingS)
	
	#define FastLog(name,method,type) Logger::FastStaticLog(name,method,type)
	#define StartFastLog(name,method,type) Logger::StartFastStaticLog(name,method,type)
	#define EndFastLog(name,method,type) Logger::EndFastStaticLog(name,method,type)
	
	#define Log(name,method,type,mns) Logger::StaticLog(name,method,type,mns)
	#define StartLog(name,method,type,mns) Logger::StartStaticLog(name,method,type,mns)
	#define EndLog(name,method,type,mns) Logger::EndStaticLog(name,method,type,mns)
	
	#define LogClass(name) Logger::addClass(name)
	#define LogMethod(name) Logger::addMethod(name)
	#define UnLogClass(name) Logger::removeClass(name)
	#define UnLogMethod(name) Logger::removeMethod(name)
#else
	#define initializeLogger(loggingS) 

	#define FastLog(name,method,type) 
	#define StartFastLog(name,method,type) 
	#define EndFastLog(name,method,type) 
	
	#define Log(name,method,type,mns) 
	#define StartLog(name,method,type,mns) 
	#define EndLog(name,method,type,mns) 
	
	#define LogClass(name) 
	#define LogMethod(name) 
	#define UnLogClass(name) 
	#define UnLogMethod(name) 
#endif

#include "higgs_Level.hpp"

#if defined(higgs_untilLevel_1)

#ifndef higgs_Enviroment_Defined

#endif

#ifdef higgs_Windows

#endif

#ifdef higgs_ArduinoIDE
	#include "Arduino.h"
	#include "Stream.h"
#endif

#include "Logging.hpp"

namespace higgs{

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
		
		static void FastStaticLog(Note className, Note methodName, Note type){
			// Serial.println(methodName);
			Logger* m_lg = Logger::getLog();
			if(m_lg->logging == nullptr){
				// Serial.println("m_lg->logging == nullptr");
				return;
			}
			m_lg->logging->FastStaticLog(className, methodName, type);
		}
		
		static void StartFastStaticLog(Note className, Note methodName, Note type){
			// Serial.println(methodName);
			Logger* m_lg = Logger::getLog();
			if(m_lg->logging == nullptr){
				// Serial.println("m_lg->logging == nullptr");
				return;
			}
			m_lg->logging->StartFastStaticLog(className, methodName, type);
		}
		
		static void EndFastStaticLog(Note className, Note methodName, Note type){
			// Serial.println(methodName);
			Logger* m_lg = Logger::getLog();
			if(m_lg->logging == nullptr){
				// Serial.println("m_lg->logging == nullptr");
				return;
			}
			m_lg->logging->EndFastStaticLog(className, methodName, type);
		}
		
		static void StaticLog(Note className, Note methodName, Note type, Note mns){
			// Serial.println(methodName);
			Logger* m_lg = Logger::getLog();
			if(m_lg->logging == nullptr){
				// Serial.println("m_lg->logging == nullptr");
				return;
			}
			m_lg->logging->StaticLog(className, methodName, type, mns);
		}
		
		static void StartStaticLog(Note className, Note methodName, Note type, Note mns){
			// Serial.println(methodName);
			Logger* m_lg = Logger::getLog();
			if(m_lg->logging == nullptr){
				// Serial.println("m_lg->logging == nullptr");
				return;
			}
			m_lg->logging->StartStaticLog(className, methodName, type, mns);
		}
		
		static void EndStaticLog(Note className, Note methodName, Note type, Note mns){
			// Serial.println(methodName);
			Logger* m_lg = Logger::getLog();
			if(m_lg->logging == nullptr){
				// Serial.println("m_lg->logging == nullptr");
				return;
			}
			m_lg->logging->EndStaticLog(className, methodName, type, mns);
		}
		
		static void addClass(Note className){
			Logger* m_lg = Logger::getLog();
			if(m_lg->logging == nullptr){
				return;
			}
			m_lg->logging->addClass(className);
		}
		
		static void addMethod(Note methodName){
			Logger* m_lg = Logger::getLog();
			if(m_lg->logging == nullptr){
				return;
			}
			m_lg->logging->addMethod(methodName);
		}
		
		
		static void removeClass(Note className){
			Logger* m_lg = Logger::getLog();
			if(m_lg->logging == nullptr){
				return;
			}
			m_lg->logging->removeClass(className);
		}
		
		static void removeMethod(Note methodName){
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

#endif 