

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
			if(list->containByLValue(mns)){
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
		//	validChars->addLValue('¡');
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
	

#endif 