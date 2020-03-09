

#ifndef SerialController_cpp
#define SerialController_cpp

#include "SerialController.h"


ArrayList<char,100>* SerialController::validChars = 0;


	SerialController::SerialController() {
	}
	
	SerialController::~SerialController() {
		validChars->onDelete();
	}
	
	void SerialController::setPort(Stream *serial) {
		port = serial;
	}
	
	Stream *SerialController::getPort() {
		if(this->port == NULL){
			return NULL;			
		}
		return port;
	}
	
	bool SerialController::available() {
		if(this->port == NULL){
			return false;			
		}
		return port->available();
	}
	
	String SerialController::getString(){
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
	
	String SerialController::getStringln(){
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
	
	String SerialController::getStringUntil(char end){
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
	
	String SerialController::getStringUntil(char startChar,char endChar){
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
	
	String SerialController::safeReceive(char start,char end){
		String mns="";
		if(this->port == NULL){
			return mns;			
		}
		char read = (char)port->read();
		if(end == read){
			mns = message;
			message = "";
			receive=false;
		}
		if(receive && isValidChar(read)){
			message.concat(read);
		}
		if(start == read){
			message = "";
			receive=true;
		}
		
		return mns;
    }
	
	String SerialController::safeReceive(List<String> *list,String responce,char start,char end){
		String mns="";
		if(this->port == NULL){
			return mns;			
		}
		char read = (char)port->read();
		if(end == read){
			mns = message;
			message = "";
			receive=false;
			if(list->contain(mns)){
				println(responce);
			}
		}
		if(start == read){
			message = "";
			receive=true;
		}
		if(receive && isValidChar(read)){
			message.concat(read);
		}
		
		return mns;
    }
	
	char SerialController::read(){
        return (char)port->read();
    }
	
	void SerialController::print(String sendd){
        port->print(sendd);
    }
	
	void SerialController::println(String sendd){
        port->println(sendd);
    }
	
	void SerialController::println(int sendd){
        port->println(String(sendd));
    }
	
	void SerialController::print(int sendd){ 
        port->print(String(sendd));
    }
	
	void SerialController::write(char sendd){
        port->write(sendd);
    }
	
	void SerialController::write(int sendd){
        port->write(sendd);
    }
	
	void SerialController::writeln(String sendd){
		int sendd_len = sendd.length() + 1; 
		char sendd_array[sendd_len];
		sendd.toCharArray(sendd_array, sendd_len);
        port->write(sendd_array);
        port->write('\r');
        port->write('\n');
    }
	
	void SerialController::writeln(int sendd){ 
        port->write(sendd);
        port->write('\r');
        port->write('\n');
    }
	
	bool SerialController::isValidChar(char chr){
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
	
	// void SerialController::onDelete(){
		// validChars->onDelete();
		// delete this;
	// }
	
	String SerialController::getClassName(){
		return "SerialController";
	}
	
	String SerialController::toString(){
		return "SerialController";
	}
	
	SerialController *SerialController::clone(){
		SerialController *serialc = new SerialController();
		serialc->port = this->port;
		serialc->message = this->message;
		serialc->receive = this->receive;
		return serialc;
	}
  
	String SerialController::Split(String divide,int parte, char limiter){     
        String return_1="";     
        int delimiter=0;  
        int respuesta_len = divide.length() + 1; 
        char respuesta_array[respuesta_len];
        divide.toCharArray(respuesta_array, respuesta_len);
        for(int i=0; i < respuesta_len; i++){
      if(respuesta_array[i] == limiter){                   
                delimiter++;  
            }
            if((parte == delimiter) && (respuesta_array[i] != limiter)){
                return_1=return_1+respuesta_array[i];
            }
        }
        return return_1;
    }
  
	int SerialController::SplitLenght(String divide,int parte, char limiter){     
        String return_1="";     
        int delimiter=0;  
        int respuesta_len = divide.length() + 1; 
        char respuesta_array[respuesta_len];
        divide.toCharArray(respuesta_array, respuesta_len);
        for(int i=0; i < respuesta_len; i++){
      if(respuesta_array[i] == limiter){                   
                delimiter++;  
            }
        }
        return delimiter;
    }
  
	String SerialController::Split(String divide,int parte, char limiter, char fin){     
        String return_1="";     
        int delimiter=0;  
        int respuesta_len = divide.length() + 1; 
        char respuesta_array[respuesta_len];
        divide.toCharArray(respuesta_array, respuesta_len);
        for(int i=0; i < respuesta_len; i++){
            if(respuesta_array[i] == limiter){                   
                delimiter++;  
            }
            if((parte == delimiter) && (respuesta_array[i] == fin)){                   
                delimiter++;  
            }
            if((parte == delimiter) && (respuesta_array[i] != limiter)){
                return_1=return_1+respuesta_array[i];
            }
        }
        return return_1;
	}
	

#endif 