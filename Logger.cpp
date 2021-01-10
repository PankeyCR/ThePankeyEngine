
#ifndef Logger_cpp
#define Logger_cpp

#include "Logger.h"

    Logger *Logger::log = nullptr;

	Logger::Logger(){
    }
	
	Logger::~Logger(){
    }
	
	void Logger::setLog(Logging* l){
		this->logging = l;
    }
	
	Logger* Logger::getLog(){
		if(Logger::log == nullptr){
			Logger::log = new Logger();
		}
		return Logger::log;
    }
	
	void Logger::StaticLog(String className, String methodName, String type, String mns){
		Logger* logger = Logger::getLog();
		if(logger->logging == nullptr){
			// Serial.println("logger->logging == nullptr");
			return;
		}
		logger->logging->StaticLog(className, methodName, type, mns);
    }
	
	void Logger::addClass(String className){
		Logger* logger = Logger::getLog();
		if(logger->logging == nullptr){
			return;
		}
		logger->logging->addClass(className);
    }
	
	void Logger::addMethod(String methodName){
		Logger* logger = Logger::getLog();
		if(logger->logging == nullptr){
			return;
		}
		logger->logging->addMethod(methodName);
    }
	
	void Logger::removeClass(String className){
		Logger* logger = Logger::getLog();
		if(logger->logging == nullptr){
			return;
		}
		logger->logging->removeClass(className);
    }
	
	void Logger::removeMethod(String methodName){
		Logger* logger = Logger::getLog();
		if(logger->logging == nullptr){
			return;
		}
		logger->logging->removeMethod(methodName);
    }
	
	
	
#endif 