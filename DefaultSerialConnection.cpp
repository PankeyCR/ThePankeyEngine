

#ifndef DefaultSerialConnection_cpp
#define DefaultSerialConnection_cpp

#include "DefaultSerialConnection.h"


ArrayList<char,100>* DefaultSerialConnection::validChars = 0;


	DefaultSerialConnection::DefaultSerialConnection() {
	}
	
	DefaultSerialConnection::~DefaultSerialConnection() {
		validChars->onDelete();
	}
	
	void DefaultSerialConnection::setPort(Stream *serial) {
		port = serial;
	}
	
	Stream *DefaultSerialConnection::getPort() {
		if(this->port == NULL){
			return NULL;			
		}
		return port;
	}
	
	bool DefaultSerialConnection::available() {
		if(this->port == NULL){
			return false;			
		}
		return port->available();
	}
	
	String DefaultSerialConnection::getString(){
		if(this->port == NULL){
			return "";			
		}
		String mns="";
		while(port->available()){
			char inputChar = (char)port->read();
			if(isValidChar(inputChar)){
				mns.concat(inputChar);
			}
		}
		port->flush();
        return mns;
    }
	
	String DefaultSerialConnection::getStringln(){
		if(this->port == NULL){
			return "";			
		}
		String mns="";
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
	
	String DefaultSerialConnection::getStringUntil(char end){
		if(this->port == NULL){
			return "";			
		}
		String mns="";
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
	
	String DefaultSerialConnection::getStringUntil(char startChar,char endChar){
		if(this->port == NULL){
			return "";			
		}
		bool start=false;
		String mns="";
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
	
	String DefaultSerialConnection::safeReceive(char start,char end){
		char read = (char)port->read();
		String mns="";
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
	
	String DefaultSerialConnection::safeReceive(List<String> *list,String responce,char start,char end){
		char read = (char)port->read();
		String mns="";
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
			if(list->contain(mns)){
				println(responce);
			}
		}
		
		return mns;
    }
	
	char DefaultSerialConnection::read(){
        return (char)port->read();
    }
	
	void DefaultSerialConnection::print(String sendd){
        port->print(sendd);
    }
	
	void DefaultSerialConnection::println(String sendd){
        port->println(sendd);
    }
	
	void DefaultSerialConnection::println(int sendd){
        port->println(String(sendd));
    }
	
	void DefaultSerialConnection::print(int sendd){ 
        port->print(String(sendd));
    }
	
	void DefaultSerialConnection::write(char sendd){
        port->write(sendd);
    }
	
	void DefaultSerialConnection::write(int sendd){
        port->write(sendd);
    }
	
	void DefaultSerialConnection::writeln(String sendd){
		int sendd_len = sendd.length() + 1; 
		char sendd_array[sendd_len];
		sendd.toCharArray(sendd_array, sendd_len);
        port->write(sendd_array);
        port->write('\r');
        port->write('\n');
    }
	
	void DefaultSerialConnection::writeln(int sendd){ 
        port->write(sendd);
        port->write('\r');
        port->write('\n');
    }
	
	bool DefaultSerialConnection::isValidChar(char chr){
		if(validChars == 0){
			validChars = new ArrayList<char,100>();
			validChars->add('a');
			validChars->add('A');
			validChars->add('b');
			validChars->add('B');
			validChars->add('c');
			validChars->add('C');
			validChars->add('d');
			validChars->add('D');
			validChars->add('e');
			validChars->add('E');
			validChars->add('f');
			validChars->add('F');
			validChars->add('g');
			validChars->add('G');
			validChars->add('h');
			validChars->add('H');
			validChars->add('i');
			validChars->add('I');
			validChars->add('j');
			validChars->add('J');
			validChars->add('k');
			validChars->add('K');
			validChars->add('l');
			validChars->add('L');
			validChars->add('m');
			validChars->add('M');
			validChars->add('n');
			validChars->add('N');
			validChars->add('o');
			validChars->add('O');
			validChars->add('p');
			validChars->add('P');
			validChars->add('q');
			validChars->add('Q');
			validChars->add('r');
			validChars->add('R');
			validChars->add('s');
			validChars->add('S');
			validChars->add('t');
			validChars->add('T');
			validChars->add('u');
			validChars->add('U');
			validChars->add('v');
			validChars->add('V');
			validChars->add('w');
			validChars->add('W');
			validChars->add('x');
			validChars->add('X');
			validChars->add('y');
			validChars->add('Y');
			validChars->add('z');
			validChars->add('Z');
			validChars->add('/');
			validChars->add('*');
			validChars->add('-');
			validChars->add('+');
			validChars->add('!');
			validChars->add('=');
			validChars->add('?');
		//	validChars->add('¡');
			validChars->add(')');
			validChars->add('(');
			validChars->add('<');
			validChars->add('>');
			validChars->add(':');
			validChars->add(';');
			validChars->add('.');
			validChars->add(',');
			validChars->add('\n');
			validChars->add('\r');
			validChars->add(' ');
			validChars->add('0');
			validChars->add('1');
			validChars->add('2');
			validChars->add('3');
			validChars->add('4');
			validChars->add('5');
			validChars->add('6');
			validChars->add('7');
			validChars->add('8');
			validChars->add('9');
		}
		
		return validChars->contain(chr);
	}
	

#endif 