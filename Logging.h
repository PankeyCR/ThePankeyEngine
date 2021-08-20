
#ifndef Logging_h
#define Logging_h

#include "Arduino.h"

namespace ame{

class Logging {
	public:
		Logging(Stream *p){
			port = p;
		}
		Logging(){}
		virtual ~Logging(){}
		virtual void StaticLog(String className, String methodName, String type, String mns){
			if(port == nullptr){
				return;
			}Serial.println("whyyyy");
			if(type == "print"){
				port->print("Loggin class: ");
				port->print(className);
				port->print(" - Method: ");
				port->print(methodName);
				port->print(" - Log: ");
				port->print(mns);
			}
			if(type == "println"){
				port->print("Loggin class: ");
				port->print(className);
				port->print(" - Method: ");
				port->print(methodName);
				port->print(" - Log: ");
				port->println(mns);
			}
		}
		
		virtual void setSerial(Stream *p){
			port = p;
		}
		virtual void addClass(String className){}
		virtual void addMethod(String methodName){}
		
		virtual void removeClass(String className){}
		virtual void removeMethod(String className){}
		
	protected:
		Stream *port = nullptr;
};

}

#endif 