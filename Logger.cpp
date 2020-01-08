
#ifndef Logger_cpp
#define Logger_cpp

#include "Logger.h"

    Logger *Logger::log = nullptr;

	Logger::Logger(){
    }
	
	Logger::~Logger(){
    }
	
	void Logger::setSerial(Stream *port){
		this->port = port;
    }
	
	Logger *Logger::getLog(){
		if(Logger::log == nullptr){
			Logger::log = new Logger();
		}
		return Logger::log;
    }
	
	void Logger::Logging(String priority,String mns){
		if(priority == "print"){
			if(Logger::getLog()->port != nullptr){
				Logger::getLog()->port->print(mns);
			}
		}
		if(priority == "println"){
			if(Logger::getLog()->port != nullptr){
				Logger::getLog()->port->println(mns);
			}
		}
    }
	
	
	
#endif 