
#ifndef SerialPort_hpp
	#define SerialPort_hpp

	#include "pankey.hpp"

	#include "Note.hpp"
	#include "PointerSize.hpp"

	#ifdef pankey_Windows
		#include "pankey_Stream.hpp"
	#endif

	#ifdef pankey_ArduinoIDE
		#include "Arduino.h"
		#include "Stream.h"
		#include "IPAddress.h"
	#endif

	namespace pankey{

		class SerialPort : public Stream{
			public:
				virtual ~SerialPort(){}
				
				virtual void setName(Note name){m_name = name;}
				virtual Note getName(){return m_name;}

				virtual void setIP(Note a_ip){m_ip = a_ip;}
				virtual Note getIP(){return m_ip;}
				
				virtual int status(){return 0;}
				virtual int available(){return 0;}

				virtual int read(){return -1;}
				virtual Note readln(float a_time){return "";}

				virtual int peek(){return -1;}

				virtual pointer_size write(int chr){return 0;}

				virtual bool connected(){return false;}
				virtual bool connect(const Note& a_address){return connect(a_address,-1);}
				virtual bool connect(const Note& a_address, int port){return false;}

				virtual void stop(){}

				virtual void flush(){}
			
				virtual pointer_size print(Note s){return 0;}
				virtual pointer_size println(Note s){return 0;}

				virtual operator bool(){return false;}
				virtual void operator=(const SerialPort& a_serial){}
				virtual bool operator==(const SerialPort& a_serial){return false;}
				virtual bool operator!=(const SerialPort& a_serial){return true;}
				
			protected:
				Note m_name = "Default";
				Note m_ip = "150.1.0.0";
		};

	}

#endif