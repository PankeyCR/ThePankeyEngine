
#include "ame_Enviroment.hpp"

#if defined(DISABLE_SerialConnection)
	#define SerialConnection_hpp
#endif

#ifndef SerialConnection_hpp
#define SerialConnection_hpp
#define SerialConnection_AVAILABLE

#ifndef ame_Enviroment_Defined

#endif

#ifdef ame_Windows

#endif

#ifdef ame_ArduinoIDE
	#include "Arduino.h"
#endif

#include "ArrayList.hpp"
#include "List.hpp"

#ifdef SerialConnectionLogApp
	#include "Logger.hpp"
	#define SerialConnectionLog(name,method,type,mns) Log(name,method,type,mns)
#else
	#define SerialConnectionLog(name,method,type,mns)
#endif

namespace ame{
	
bool SerialConnectionValidChars(char c){
	if(c > 40 && c < 126){
		return true;
	}
	if(c == 32){// enter
		return true;
	}
	return false;
}

class SerialConnection {
	using m_method = bool (*)(char);
    public:
		SerialConnection(){}
		virtual ~SerialConnection(){}

		virtual bool available(){
			if(port == nullptr){
				return false;			
			}
			return port->available();
		}
	
		virtual void setPort(Stream *serial){
			SerialConnectionLog("SerialConnection", "setPort",  "println", "");
			port = serial;
		}
		
		virtual Stream* getPort(){
			return port;
		}
	
 		virtual Note getNote(){
			SerialConnectionLog("SerialConnection", "getNote",  "println", "");
			if(port == nullptr){
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
	
		virtual Note getNoteln(){
			SerialConnectionLog("SerialConnection", "getNoteln",  "println", "");
			if(port == nullptr){
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
	
		virtual Note getNoteUntil(char end){
			SerialConnectionLog("SerialConnection", "getNoteUntil",  "println", "");
			if(port == nullptr){
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
	
		virtual Note getNoteUntil(char startChar,char endChar){
			SerialConnectionLog("SerialConnection", "getNoteUntil",  "println", "");
			if(port == nullptr){
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
	
		virtual Note safeFullReceive(char end){
			SerialConnectionLog("SerialConnection", "safeReceive",  "println", "");
			if(port == nullptr){
				return "";			
			}
			Note mns="";
			char read = ' ';
			if(port->available()){
				read = (char)port->read();
			}else{
				return mns;
			}
			if(end == read){
				mns = message + Note(end);
				message = "";
				return mns;
			}
			if(isValidChar(read)){
				message.concat(read);
			}
			return mns;
		}
	
		virtual Note safeReceive(char end){
			SerialConnectionLog("SerialConnection", "safeReceive",  "println", "");
			if(port == nullptr){
				return "";			
			}
			Note mns="";
			char read = ' ';
			if(port->available()){
				read = (char)port->read();
			}else{
				return mns;
			}
			if(end == read){
				mns = message;
				message = "";
				return mns;
			}
			if(isValidChar(read)){
				message.concat(read);
			}
			return mns;
		}
	
		virtual Note safeReceive(char start,char end){
			SerialConnectionLog("SerialConnection", "safeReceive",  "println", "");
			if(port == nullptr){
				return "";			
			}
			Note mns="";
			char read = ' ';
			if(port->available()){
				read = (char)port->read();
			}else{
				return mns;
			}
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
	
		virtual Note safeReceive(List<Note> *list,Note responce,
														char start,char end){
			SerialConnectionLog("SerialConnection", "safeReceive",  "println", "");
			if(port == nullptr){
				return "";			
			}
			Note mns="";
			char read = (char)port->read();
			if(end == read){
				mns = message;
				message = "";
				receive=false;
				if(list->containByLValue(mns)){
					Note sendingSafeResponce = "";
					sendingSafeResponce.concat(start);
					sendingSafeResponce.concat(responce);
					sendingSafeResponce.concat(end);
					print(sendingSafeResponce);
				}
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
		
		virtual char read(){
			return (char)port->read();
		}
	
		virtual void print(Note s){
			port->print(s);
		}
		
   		virtual void println(Note s){
			port->println(s);
		}
	
		virtual void print(int s){
			port->println(s);
		}
	
		virtual void println(int s){ 
			port->print(s);
		}
	
		virtual void write(char s){
			port->write(s);
		}
	
		virtual void write(int s){
			port->write(s);
		}
	
		virtual void writeln(Note s){
			int sendd_len = s.length() + 1; 
			char sendd_array[sendd_len];
			s.toCharArray(sendd_array, sendd_len);
			port->write(sendd_array);
			port->write('\r');
			port->write('\n');
		}
	
		virtual void writeln(int s){ 
			port->write(s);
			port->write('\r');
			port->write('\n');
		}
		
		Note Split(Note divide,int parte, char limiter){  
			SerialConnectionLog("SerialConnection", "Split",  "println", "");   
			Note return_1="";     
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
  
		int SplitLenght(Note divide,int parte, char limiter){
			SerialConnectionLog("SerialConnection", "SplitLenght",  "println", "");
			Note return_1="";     
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
  
		Note Split(Note divide,int parte, char limiter, char fin){
			SerialConnectionLog("SerialConnection", "Split",  "println", "");
			Note return_1="";     
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
		
		virtual void setValidCharMethod(m_method m){
			isValidChar = m;
		}
		
    protected:
		Stream* port = nullptr;
		Note message="";
		bool receive=false;
		
		m_method isValidChar = SerialConnectionValidChars;
};

}

#endif