
#ifndef SerialNetwork_h
#define SerialNetwork_h

#include "SerialPort.h"
#include "PortProtocol.h"
#include "cppObject.h"

namespace ame{

class SerialNetwork : public cppObject{	
    public:
		SerialNetwork(){
		}
		virtual ~SerialNetwork(){
		}
		
		virtual void setName(String name){
			m_name = name;
		}
		
		virtual String getName(){
			return m_name;
		}
		virtual void operator=(SerialNetwork b){}
		virtual bool operator==(SerialNetwork b){return this->getClass()==b.getClass();}
		virtual bool operator!=(SerialNetwork b){return this->getClass()!=b.getClass();}
		
		virtual cppObjectClass* getClass(){return Class<SerialNetwork>::classType;}
		virtual String toString(){return "SerialNetwork";}
		virtual bool instanceof(cppObjectClass* cls){
			return cls == Class<SerialNetwork>::classType || cppObject::instanceof(cls);
		}
		
	protected:
		String m_name = "";
		
		List<SerialPort>* ports = nullptr;
		List<PortProtocol>* portProtocols = nullptr;
};

}

#endif 
