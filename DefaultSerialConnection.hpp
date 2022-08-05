
#include "ame_Enviroment.hpp"

#if defined(DISABLE_DefaultSerialConnection)
	#define DefaultSerialConnection_hpp
#endif

#ifndef DefaultSerialConnection_hpp
#define DefaultSerialConnection_hpp
#define DefaultSerialConnection_AVAILABLE

#ifndef ame_Enviroment_Defined

#endif

#ifdef ame_Windows

#endif

#ifdef ame_ArduinoIDE
	#include "Arduino.h"
	#include "Printable.h"
#endif

#include "SerialConnection.hpp"
#include "ArrayList.hpp"
#include "PList.hpp"
#include "List.hpp"

namespace ame{

class DefaultSerialConnection : public SerialConnection{		
    private:
		Stream *port=NULL;
		Note message="";
		bool receive=false;
		static ArrayList<char,100> *validChars;
		
    public:
		DefaultSerialConnection(){}
		virtual ~DefaultSerialConnection(){
			validChars->onDelete();
		}
		void setPort(Stream *port){
			port = serial;
		}
		Stream* getPort(){
			if(this->port == nullptr){
				return nullptr;			
			}
			return port;
		}
		
		bool available(){
			if(this->port == nullptr){
				return false;			
			}
			return port->available();
		}
		
		Note getNote(){
			if(this->port == NULL){
				return "";			
			}
			Note mns="";
			while(port->available()){
				char inputChar = (char)port->read();
				if(isValidChar(inputChar)){
					mns.concat(inputChar);
				}
			}
			port->flush();
			return mns;
		}
		
		Note getNoteln(){
			if(this->port == nullptr){
				return "";			
			}
			Note mns="";
			while(port->available()){
				char inputChar = (char)port->read();
				if(inputChar == '\n'){
					break;
				}
				if(isValidChar(inputChar)){
					mns.concat(inputChar);
				}
			}
			port->flush();
			return mns;
		}
		
		Note getNoteUntil(char end){
			if(this->port == NULL){
				return "";			
			}
			Note mns="";
			while(port->available()){
				char inputChar = (char)port->read();
				if(inputChar == end){
					break;
				}
				if(isValidChar(inputChar)){
					mns.concat(inputChar);
				}
			}
			port->flush();
			return mns;
		}
	
		Note getNoteUntil(char start,char end){
			if(this->port == NULL){
				return "";			
			}
			bool start=false;
			Note mns="";
			while(port->available()){
				char inputChar = (char)port->read();
				if(inputChar == startChar){
					start = true;
				}
				if(inputChar == endChar){
					break;
				}
				if(isValidChar(inputChar) && start){
					mns.concat(inputChar);
				}
			}
			port->flush();
			return mns;
		}
		
		Note safeReceive(char start,char end){
			char read = (char)port->read();
			Note mns="";
			if(receive && isValidChar(read)){
				message.concat(read);
			}
			if(start == read){
				message = "";
				receive=true;
			}
			if(end == read){
				mns = message;
				message = "";
				receive=false;
			}
			
			return mns;
		}
	
		Note safeReceive(List<Note> *list,Note responce,char start,char end){
			char read = (char)port->read();
			Note mns="";
			if(start == read){
				message = "";
				receive=true;
			}
			if(receive && isValidChar(read)){
				message.concat(read);
			}
			if(end == read){
				mns = message;
				message = "";
				receive=false;
				if(list->containByLValue(mns)){
					println(responce);
				}
			}
			
			return mns;
		}
	
		char read(){
			return (char)port->read();
		}
	
		void print(Note Send){
			port->print(sendd);	
		}
		
		void println(Note Send){
			port->println(sendd);
		}
		
		void print(int Send){
			port->println(Note(
		}
		
		void println(int Send){ 
			port->print(Note(sendd));
		}
	
		void write(char Send){
			port->write(sendd);
		}
	
		void write(int Send){
			port->write(sendd);
		}
	
		void writeln(Note Send){
			int sendd_len = sendd.length() + 1; 
			char sendd_array[sendd_len];
			sendd.toCharArray(sendd_array, sendd_len);
			port->write(sendd_array);
			port->write('\r');
			port->write('\n');
		}
	
		void writeln(int Send){ 
			port->write(sendd);
			port->write('\r');
			port->write('\n');
		}
		static bool isValidChar(char chr){
			if(validChars == 0){
				validChars = new ame::ArrayList<char,100>();
				validChars->addLValue('a');
				validChars->addLValue('A');
				validChars->addLValue('b');
				validChars->addLValue('B');
				validChars->addLValue('c');
				validChars->addLValue('C');
				validChars->addLValue('d');
				validChars->addLValue('D');
				validChars->addLValue('e');
				validChars->addLValue('E');
				validChars->addLValue('f');
				validChars->addLValue('F');
				validChars->addLValue('g');
				validChars->addLValue('G');
				validChars->addLValue('h');
				validChars->addLValue('H');
				validChars->addLValue('i');
				validChars->addLValue('I');
				validChars->addLValue('j');
				validChars->addLValue('J');
				validChars->addLValue('k');
				validChars->addLValue('K');
				validChars->addLValue('l');
				validChars->addLValue('L');
				validChars->addLValue('m');
				validChars->addLValue('M');
				validChars->addLValue('n');
				validChars->addLValue('N');
				validChars->addLValue('o');
				validChars->addLValue('O');
				validChars->addLValue('p');
				validChars->addLValue('P');
				validChars->addLValue('q');
				validChars->addLValue('Q');
				validChars->addLValue('r');
				validChars->addLValue('R');
				validChars->addLValue('s');
				validChars->addLValue('S');
				validChars->addLValue('t');
				validChars->addLValue('T');
				validChars->addLValue('u');
				validChars->addLValue('U');
				validChars->addLValue('v');
				validChars->addLValue('V');
				validChars->addLValue('w');
				validChars->addLValue('W');
				validChars->addLValue('x');
				validChars->addLValue('X');
				validChars->addLValue('y');
				validChars->addLValue('Y');
				validChars->addLValue('z');
				validChars->addLValue('Z');
				validChars->addLValue('/');
				validChars->addLValue('*');
				validChars->addLValue('-');
				validChars->addLValue('+');
				validChars->addLValue('!');
				validChars->addLValue('=');
				validChars->addLValue('?');
			//	validChars->addLValue('ยก');
				validChars->addLValue(')');
				validChars->addLValue('(');
				validChars->addLValue('<');
				validChars->addLValue('>');
				validChars->addLValue(':');
				validChars->addLValue(';');
				validChars->addLValue('.');
				validChars->addLValue(',');
				validChars->addLValue('\n');
				validChars->addLValue('\r');
				validChars->addLValue(' ');
				validChars->addLValue('0');
				validChars->addLValue('1');
				validChars->addLValue('2');
				validChars->addLValue('3');
				validChars->addLValue('4');
				validChars->addLValue('5');
				validChars->addLValue('6');
				validChars->addLValue('7');
				validChars->addLValue('8');
				validChars->addLValue('9');
			}
			
			return validChars->containByLValue(chr);
		}
};

ArrayList<char,100>* DefaultSerialConnection::validChars = nullptr;

}

#endif