
#ifndef DefaultSerialConnection_h
#define DefaultSerialConnection_h

#include "SerialConnection.h"
#include "Arduino.h"
#include "ArrayList.h"
#include "PList.h"
#include "List.h"

class DefaultSerialConnection : public SerialConnection{		
    private:
		Stream *port=NULL;
		String message="";
		bool receive=false;
		static ArrayList<char,100> *validChars;
		
    public:
		DefaultSerialConnection();
		~DefaultSerialConnection();
		void setPort(Stream *port);
		Stream *getPort();
		bool available();
		String getString();
		String getStringln();
		String getStringUntil(char end);
		String getStringUntil(char start,char end);
		String safeReceive(char start,char end);
		String safeReceive(List<String> *list,String responce,char start,char end);
		char read();
		void print(String Send);
		void println(String Send);
		void print(int Send);
		void println(int Send);
		void write(char Send);
		void write(int Send);
		void writeln(String Send);
		void writeln(int Send);
		static bool isValidChar(char chr);
		
};

#endif 
