
#ifndef DefaultLogging_h
#define DefaultLogging_h

#include "Logging.h"
#include "List.h"
#include "PrimitiveList.h"

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
		}
		
		virtual ~DefaultLogging(){
			delete this->ClassList;
			delete this->MethodList;
		}
		
		virtual void StaticLog(String className, String methodName, String type, String mns){
			if(this->port == nullptr){
				return;
			}
			if(classActivation){
				if(!this->ClassList->contain(className)){
					return;
				}
			}
			if(methodActivation){
				if(!this->MethodList->contain(className)){
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
			this->ClassList->add(className);
		}
		virtual void addMethod(String methodName){
			this->MethodList->removeDelete(methodName);
		}
		
		virtual void removeClass(String className){
			this->ClassList->add(className);
		}
		virtual void removeMethod(String methodName){
			this->MethodList->removeDelete(methodName);
		}
		
	protected:
		List<String>* ClassList = nullptr;
		List<String>* MethodList = nullptr;
		bool classActivation = true;
		bool methodActivation = false;
};
#endif 