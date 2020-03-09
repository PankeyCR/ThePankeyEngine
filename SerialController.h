
#ifndef SerialController_h
#define SerialController_h

#include "SerialConnection.h"
#include "GameObject.h"
#include "Arduino.h"
#include "ArrayList.h"
#include "PList.h"
#include "List.h"

class SerialController : public SerialConnection , public GameObject{		
    private:
		Stream *port=nullptr;
		String message="";
		bool receive=false;
		static ArrayList<char,100> *validChars;
		
    public:
		SerialController();
		~SerialController();
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
		String getClassName();
		String toString();
		SerialController *clone();
		String Split(String divide,int parte, char limiter);
		int SplitLenght(String divide,int parte, char limiter);
		String Split(String divide,int parte, char limiter, char fin);
		
};

#endif 
