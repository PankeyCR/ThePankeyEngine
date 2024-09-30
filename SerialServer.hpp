
#ifndef SerialServer_hpp
	#define SerialServer_hpp

	#include "pankey.hpp"

	#include "SerialPort.hpp"
	#include "Note.hpp"

	namespace pankey{

		class SerialServer{
			public:
				SerialServer(){}
				virtual ~SerialServer(){}

				virtual void setName(Note name){m_name = name;}
				virtual Note getName(){return m_name;}

				virtual void setPort(Note a_port){m_port = a_port;}
				virtual Note getPort(){return m_port;}

				virtual void setTimeOut(float t){m_timeout = t;}
				virtual float getTimeOut(){return m_timeout;}

				virtual void begin(){}
				
				virtual void stop(){}

				virtual obj<SerialPort> accept(){return nullptr;}

				virtual obj<SerialPort> available(){return nullptr;}

				virtual void send(int t, Note txt, Note a_message){}

				virtual void send(Note a_message){}

				virtual void send(Note a_port, Note a_message){}

				virtual void handleClient(){}

				virtual void operator=(SerialServer b){}
				virtual bool operator==(SerialServer b){return this->getName()==b.getName();}
				virtual bool operator!=(SerialServer b){return this->getName()!=b.getName();}

			protected:
				float m_timeout = -1.0;
				Note m_name = "";
				Note m_port = "";
		};

	}

#endif
