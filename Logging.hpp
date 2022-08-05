
#ifndef Logging_h
#define Logging_h

#include "ame_Level.hpp"

#if defined(ame_untilLevel_1)

#ifndef ame_Enviroment_Defined

#endif

#ifdef ame_Windows

#endif

#ifdef ame_ArduinoIDE
	#include "Stream.h"
	#include "Arduino.h"
#endif

#include "Note.hpp"

namespace ame{

#ifdef ame_Windows
class Logging {
	public:
		Logging(){}
		virtual ~Logging(){}
		virtual void FastStaticLog(Note className, Note methodName, Note type){}
		virtual void StartFastStaticLog(Note className, Note methodName, Note type){}
		virtual void EndFastStaticLog(Note className, Note methodName, Note type){}
		
		virtual void StaticLog(Note className, Note methodName, Note type, Note mns){}
		virtual void StartStaticLog(Note className, Note methodName, Note type, Note mns){}
		virtual void EndStaticLog(Note className, Note methodName, Note type, Note mns){}
		
		virtual void addClass(Note className){}
		virtual void addMethod(Note methodName){}
		
		virtual void removeClass(Note className){}
		virtual void removeMethod(Note className){}
		
	protected:
};
#endif

#ifdef ame_ArduinoIDE
class Logging {
	public:
		Logging(Stream *p){
			port = p;
		}
		Logging(){}
		virtual ~Logging(){}
		
		virtual void FastStaticLog(Note className, Note methodName, Note type){}
		virtual void StartFastStaticLog(Note className, Note methodName, Note type){}
		virtual void EndFastStaticLog(Note className, Note methodName, Note type){}
		
		virtual void StaticLog(Note className, Note methodName, Note type, Note mns){
			if(port == nullptr){
				return;
			}Serial.println("Logging class");
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
		
		virtual void StartStaticLog(Note className, Note methodName, Note type, Note mns){}
		
		virtual void EndStaticLog(Note className, Note methodName, Note type, Note mns){}
		
		virtual void setSerial(Stream *p){
			port = p;
		}
		virtual void addClass(Note className){}
		virtual void addMethod(Note methodName){}
		
		virtual void removeClass(Note className){}
		virtual void removeMethod(Note className){}
		
	protected:
		Stream *port = nullptr;
};
#endif

}

#endif

#endif