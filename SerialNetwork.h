
#ifndef SerialNetwork_h
#define SerialNetwork_h

#include "SerialPort.h"
#include "PortProtocol.h"
#include "cppObject.h"

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
		virtual bool operator==(SerialNetwork b){return this->getClassName()==b.getClassName();}
		virtual bool operator!=(SerialNetwork b){return this->getClassName()!=b.getClassName();}
		
		virtual String getClassName(){return "SerialNetwork";}
		virtual String toString(){return "SerialNetwork";}
		virtual bool instanceof(String name){
			return name == "SerialNetwork" || name == "cppObject";
		}
		
	protected:
		String m_name = "";
		
		List<SerialPort>* ports = nullptr;
		List<PortProtocol>* portProtocols = nullptr;
};
#endif 
