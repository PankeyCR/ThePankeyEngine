
#ifndef DefaultLogging_h
#define DefaultLogging_h

#include "Arduino.h"
#include "Logger.h"
#include "Logging.h"
#include "List.h"
#include "PrimitiveList.h"

namespace ame{

class DefaultLogging : public Logging{
	public:
		DefaultLogging(Stream *p){
			this->port = p;
			this->ClassList = new PrimitiveList<String>();
			this->MethodList = new PrimitiveList<String>();
		}
		DefaultLogging(Stream *p, bool classA, bool methodA){
			this->port = p;
			this->ClassList = new PrimitiveList<String>();
			this->MethodList = new PrimitiveList<String>();
			classActivation = classA;
			methodActivation = methodA;
			// Serial.println("contructor");
		}
		
		virtual ~DefaultLogging(){
			delete this->ClassList;
			delete this->MethodList;
		}
		
		virtual void StaticLog(String className, String methodName, String type, String mns){
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
			yield();
		}
		
		virtual void addClass(String className){
			this->ClassList->addLValue(className);
		}
		virtual void addMethod(String methodName){
			this->MethodList->addLValue(methodName);
		}
		
		virtual void removeClass(String className){
			this->ClassList->removeDeleteByLValue(className);
		}
		virtual void removeMethod(String methodName){
			this->MethodList->removeDeleteByLValue(methodName);
		}
		
	protected:
		List<String>* ClassList = nullptr;
		List<String>* MethodList = nullptr;
		bool classActivation = true;
		bool methodActivation = false;
};

}
#endif 