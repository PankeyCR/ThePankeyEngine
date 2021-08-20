
#ifndef Logger_cpp
#define Logger_cpp

#include "Logger.h"

    ame::Logger *ame::Logger::log = nullptr;

	ame::Logger::Logger(){
    }
	
	ame::Logger::~Logger(){
		if(this->logging != nullptr){
			delete this->logging;
		}
    }
	
	void ame::Logger::setLog(ame::Logging* l){
		this->logging = l;
    }
	
	ame::Logger* ame::Logger::getLog(){
		if(ame::Logger::log == nullptr){
			ame::Logger::log = new ame::Logger();
		}
		return ame::Logger::log;
    }
	
	void ame::Logger::StaticLog(String className, String methodName, String type, String mns){
		ame::Logger* m_lg = ame::Logger::getLog();
		if(m_lg->logging == nullptr){
			// Serial.println("m_lg->logging == nullptr");
			return;
		}
		m_lg->logging->StaticLog(className, methodName, type, mns);
    }
	
	void ame::Logger::addClass(String className){
		ame::Logger* m_lg = ame::Logger::getLog();
		if(m_lg->logging == nullptr){
			return;
		}
		m_lg->logging->addClass(className);
    }
	
	void ame::Logger::addMethod(String methodName){
		ame::Logger* m_lg = ame::Logger::getLog();
		if(m_lg->logging == nullptr){
			return;
		}
		m_lg->logging->addMethod(methodName);
    }
	
	void ame::Logger::removeClass(String className){
		ame::Logger* m_lg = ame::Logger::getLog();
		if(m_lg->logging == nullptr){
			return;
		}
		m_lg->logging->removeClass(className);
    }
	
	void ame::Logger::removeMethod(String methodName){
		ame::Logger* m_lg = ame::Logger::getLog();
		if(m_lg->logging == nullptr){
			return;
		}
		m_lg->logging->removeMethod(methodName);
    }
	
	
	
#endif 