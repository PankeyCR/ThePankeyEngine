
#ifndef SerialConnection_h
#define SerialConnection_h

#include "Arduino.h"
#include "List.h"

class SerialConnection {
    private:
	
    public:
		virtual bool available(){}
		virtual void setPort(Stream *port){}
		virtual Stream *getPort(){}
 		virtual String getString(){}
		virtual String getStringln(){}
		virtual String getStringUntil(char end){}
		virtual String getStringUntil(char start,char end){}
		virtual String safeReceive(char start,char end){}
		virtual String safeReceive(List<String> *list,String responce,
														char start,char end){}
		virtual char read(){}
		virtual void print(String Send){}
   		virtual void println(String Send){}
		virtual void print(int Send){}
		virtual void println(int Send){}
		virtual void write(char Send){}
		virtual void write(int Send){}
		virtual void writeln(String Send){}
		virtual void writeln(int Send){}
};

#endif 
