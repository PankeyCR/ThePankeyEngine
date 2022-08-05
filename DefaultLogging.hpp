
#include "ame_Enviroment.hpp"

#if defined(DISABLE_DefaultLogging)
	#define DefaultLogging_hpp
#endif

#ifndef DefaultLogging_hpp
#define DefaultLogging_hpp
#define DefaultLogging_AVAILABLE

#ifndef ame_Enviroment_Defined

#endif

#ifdef ame_Windows

#endif

#ifdef ame_ArduinoIDE
	#include "Arduino.h"
#endif

#include "Logger.hpp"
#include "Logging.hpp"
#include "List.hpp"
#include "PrimitiveList.hpp"

namespace ame{

class DefaultLogging : public Logging{
	public:
		DefaultLogging(Stream *p){
			this->port = p;
			this->ClassList = new PrimitiveList<Note>();
			this->MethodList = new PrimitiveList<Note>();
		}
		DefaultLogging(Stream *p, bool classA, bool methodA){
			this->port = p;
			this->ClassList = new PrimitiveList<Note>();
			this->MethodList = new PrimitiveList<Note>();
			classActivation = classA;
			methodActivation = methodA;
			// Serial.println("contructor");
		}
		
		virtual ~DefaultLogging(){
			delete this->ClassList;
			delete this->MethodList;
		}
		
		virtual void StaticLog(Note className, Note methodName, Note type, Note mns){
			if(this->port == nullptr){
				// Serial.println("this->port == nullptr");
				return;
			}
			// Serial.println("StaticLog");
			if(classActivation){
				if(!this->ClassList->containByLValue(className)){
					return;
				}
			}
			// Serial.println("StaticLog");
			if(methodActivation){
				if(!this->MethodList->containByLValue(methodName)){
					return;
				}
			}
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
			// yield();
		}
		
		virtual void addClass(Note className){
			this->ClassList->addLValue(className);
		}
		virtual void addMethod(Note methodName){
			this->MethodList->addLValue(methodName);
		}
		
		virtual void removeClass(Note className){
			this->ClassList->removeDeleteByLValue(className);
		}
		virtual void removeMethod(Note methodName){
			this->MethodList->removeDeleteByLValue(methodName);
		}
		
	protected:
		List<Note>* ClassList = nullptr;
		List<Note>* MethodList = nullptr;
		bool classActivation = true;
		bool methodActivation = false;
};

}

#endif