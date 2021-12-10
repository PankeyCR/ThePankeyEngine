
#ifndef SerialConnection_hpp
#define SerialConnection_hpp

#ifndef ame_Enviroment_Defined
	#include "Arduino.h"
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
	
 		virtual String getString(){
			SerialConnectionLog("SerialConnection", "getString",  "println", "");
			if(port == nullptr){
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
	
		virtual String getStringln(){
			SerialConnectionLog("SerialConnection", "getStringln",  "println", "");
			if(port == nullptr){
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
	
		virtual String getStringUntil(char end){
			SerialConnectionLog("SerialConnection", "getStringUntil",  "println", "");
			if(port == nullptr){
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
	
		virtual String getStringUntil(char startChar,char endChar){
			SerialConnectionLog("SerialConnection", "getStringUntil",  "println", "");
			if(port == nullptr){
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
	
		virtual String safeFullReceive(char end){
			SerialConnectionLog("SerialConnection", "safeReceive",  "println", "");
			if(port == nullptr){
				return "";			
			}
			String mns="";
			char read = ' ';
			if(port->available()){
				read = (char)port->read();
			}else{
				return mns;
			}
			if(end == read){
				mns = message + String(end);
				message = "";
				return mns;
			}
			if(isValidChar(read)){
				message.concat(read);
			}
			return mns;
		}
	
		virtual String safeReceive(char end){
			SerialConnectionLog("SerialConnection", "safeReceive",  "println", "");
			if(port == nullptr){
				return "";			
			}
			String mns="";
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
	
		virtual String safeReceive(char start,char end){
			SerialConnectionLog("SerialConnection", "safeReceive",  "println", "");
			if(port == nullptr){
				return "";			
			}
			String mns="";
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
	
		virtual String safeReceive(List<String> *list,String responce,
														char start,char end){
			SerialConnectionLog("SerialConnection", "safeReceive",  "println", "");
			if(port == nullptr){
				return "";			
			}
			String mns="";
			char read = (char)port->read();
			if(end == read){
				mns = message;
				message = "";
				receive=false;
				if(list->containByLValue(mns)){
					String sendingSafeResponce = "";
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
	
		virtual void print(String s){
			port->print(s);
		}
		
   		virtual void println(String s){
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
	
		virtual void writeln(String s){
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
		
		String Split(String divide,int parte, char limiter){  
			SerialConnectionLog("SerialConnection", "Split",  "println", "");   
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
  
		int SplitLenght(String divide,int parte, char limiter){
			SerialConnectionLog("SerialConnection", "SplitLenght",  "println", "");
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
  
		String Split(String divide,int parte, char limiter, char fin){
			SerialConnectionLog("SerialConnection", "Split",  "println", "");
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
		
		virtual void setValidCharMethod(m_method m){
			isValidChar = m;
		}
		
    protected:
		Stream* port = nullptr;
		String message="";
		bool receive=false;
		
		m_method isValidChar = SerialConnectionValidChars;
};

}

#endif 
