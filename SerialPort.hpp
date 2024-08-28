
#ifndef SerialPort_hpp
#define SerialPort_hpp

#include "Note.hpp"
#include "ByteArray.hpp"
#include "higgs_Byte.hpp"

#ifdef higgs_Windows
	#include "higgs_Stream.hpp"
#endif

#ifdef higgs_ArduinoIDE
	#include "Arduino.h"
	#include "Stream.h"
	#include "IPAddress.h"
#endif

namespace higgs{

class SerialPort : public Stream{

    public:
		SerialPort(){}
		virtual ~SerialPort(){}
		
		virtual uint8_t status(){return 0;}
		virtual int available(){return 0;}

		virtual int read(){return -1;}
		virtual higgs_Byte readByte(){return 255;}
		virtual Note readNote(){return "";}

		virtual int peek(){return -1;}

		virtual size_t write(uint8_t chr){return 0;}

		virtual bool connected(){return false;}
		virtual bool connect(const Note& a_address){return connect(a_address,-1);}
		virtual bool connect(const Note& a_address, int port){return false;}
		virtual bool connect(const char* a_address){return connect(a_address,-1);}
		virtual bool connect(const char* a_address, int port){return false;}

		#ifdef higgs_ArduinoIDE
		virtual bool connect(IPAddress ip, int port){return false;}
		#endif

		virtual void stop(){}
		
		virtual void send(Note s){}
		virtual void send(ByteArray array){}
		
		virtual void setName(Note name){m_name = name;}
		virtual Note getName(){return m_name;}

		virtual void setIP(Note a_ip){m_ip = a_ip;}
		virtual Note getIP(){return this->m_ip;}

		virtual void flush(){}

		virtual operator bool(){return false;}
		virtual void operator=(SerialPort b){}
		virtual bool operator==(SerialPort b){return false;}
		virtual bool operator!=(SerialPort b){return true;}
		
	protected:
		Note m_name;
		Note m_ip = "150.1.0.0";
};

}

#endif