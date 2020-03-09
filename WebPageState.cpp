

#ifndef WebPageState_cpp
#define WebPageState_cpp

#include "WebPageState.h"

	WebPageState::WebPageState(const char* ssid,const char* pass){
		this->ssid = ssid;
		this->password = pass;
		this->id = new String("WebPage");
		this->commands = new PrimitiveList<Command<WebPageState>>();
		#if defined(ARDUINO_ARCH_AVR)

		#elif defined(ARDUINO_ARCH_SAM)
		  // SAM-specific code
		#else
		this->server = new WiFiServer(80);
		#endif
	}
	
	WebPageState::WebPageState(String id, const char* ssid,const char* pass){
		this->ssid = ssid;
		this->password = pass;
		this->id = new String(id);
		this->commands = new PrimitiveList<Command<WebPageState>>();
		#if defined(ARDUINO_ARCH_AVR)

		#elif defined(ARDUINO_ARCH_SAM)
		  // SAM-specific code
		#else
		this->server = new WiFiServer(80);
		#endif
	}
	
	WebPageState::~WebPageState(){
		delete this->id;
		delete this->commands;
		#if defined(ARDUINO_ARCH_AVR)

		#elif defined(ARDUINO_ARCH_SAM)
		  // SAM-specific code
		#else
		delete this->server;
		#endif
	}
	
	void WebPageState::initialize(Application *app){
		Log("print","Connecting to ");Log("println",String(ssid));
		#if defined(ARDUINO_ARCH_AVR)

		#elif defined(ARDUINO_ARCH_SAM)
		  // SAM-specific code
		#else
		WiFi.begin(ssid, password);
		#endif
	}
	     
	void WebPageState::update(){
		#if defined(ARDUINO_ARCH_AVR)

		#elif defined(ARDUINO_ARCH_SAM)
		  // SAM-specific code
		#else
	    if(WiFi.status() != WL_CONNECTED){
			Log("println","wifi status: not connected ");
			return;
		}
		if(this->initServer){
			this->initServer = false;
			server->begin();
			Log("println","initialize Server");
			Log("print","Local Ip ");Log("println",this->getLocalIP());
		}
		this->client = server->available();

		Log("println","is server available");
		if (client) {
			Log("println","server on");
			String currentLine = ""; 
			Log("println","Checking if theres connection ");
			while(client.connected()) {
				Log("println","Client Connected");
				if(client.available()) {
					yield();
					char c = client.read();
					Log("print",String(c));
					header += c;
					if (c == '\n') {
						if (currentLine.length() == 0) {
						// HTTP headers always start with a response code (e.g. HTTP/1.1 200 OK)
						// and a content-type so the client knows what's coming, then a blank line:
						client.println("HTTP/1.1 200 OK");
						client.println("Content-type:text/html");
						client.println("Connection: close");
						client.println();
						
						Log("println","start commands");
						iterate(this->commands){
							Log("print","command: ");Log("println",String(this->commands->getIteration()));
							this->commands->getPointer()->execute(this);
						}
						break;
						} else { // if you got a newline, then clear currentLine
							currentLine = "";
						}
					} else if (c != '\r') {  // if you got anything else but a carriage return character,
						currentLine += c;      // add it to the end of the currentLine
					}
				}
			}
			// Clear the header variable
			header = "";
			// Close the connection
			client.stop();
			Log("println","Client disconnected.");
			Log("println","");
		}
		#endif
	}
	     
	void WebPageState::addCommand(Command<WebPageState>* cmd){
	    this->commands->add(cmd);
	}
	     
	void WebPageState::removeCommand(int index){
	    Command<WebPageState>* c = this->commands->removeByPos(index);
		if(c != nullptr){
			delete c;
		}
	}
	     
	void WebPageState::clearCommands(){
		this->commands->resetDelete();
	}
	     
	const char* WebPageState::getSSID(){
		return this->ssid;
	}
	     
	const char* WebPageState::getPassWord(){
		return this->password;
	}
	     
	String WebPageState::getHeader(){
		return this->header;
	}
	     
	String WebPageState::getLocalIP(){   
		#if defined(ARDUINO_ARCH_AVR)
		return "";
		#elif defined(ARDUINO_ARCH_SAM)
		  // SAM-specific code
		#else
		return WiFi.localIP().toString();
		#endif
	}
	     
	// bool WebPageState::isServerAvailable(){   
		// #if defined(ARDUINO_ARCH_AVR)
		// return false;
		// #elif defined(ARDUINO_ARCH_SAM)
		//  SAM-specific code
		// #else
		// if(this->server == nullptr){
			// return false;
		// }
		// if(this->server->available()){
			// return true;
		// }else{
			// return false;
		// }
		// #endif
	// }
	     
	// bool WebPageState::isClientAvailable(){   
		// #if defined(ARDUINO_ARCH_AVR)
		// return false;
		// #elif defined(ARDUINO_ARCH_SAM)
		//  SAM-specific code
		// #else
		// if(this->server == nullptr){
			// return false;
		// }
		// if(this->server->available()){
			// if(this->client.available()){
				// return true;
			// }else{
				// return false;
			// }
		// }else{
			// return false;
		// }
		// #endif
	// }
	     
	// bool WebPageState::isClientConnected(){   
		// #if defined(ARDUINO_ARCH_AVR)
		// return false;
		// #elif defined(ARDUINO_ARCH_SAM)
		//  SAM-specific code
		// #else
		// if(this->server == nullptr){
			// return false;
		// }
		// if(this->server->available()){
			// if(this->client.connected()){
				// return true;
			// }else{
				// return false;
			// }
		// }else{
			// return false;
		// }
		// #endif
	// }
	     
	bool WebPageState::containHeader(String ch){   
		#if defined(ARDUINO_ARCH_AVR)
		return false;
		#elif defined(ARDUINO_ARCH_SAM)
		  // SAM-specific code
		#else
		if(this->header.indexOf(ch) >= 0){
			return true;
		}else{
			return false;
		}
		#endif
	}
	     
	void WebPageState::println(String ch){   
		#if defined(ARDUINO_ARCH_AVR)
		
		#elif defined(ARDUINO_ARCH_SAM)
		  // SAM-specific code
		#else
		client.println(ch);
		#endif
	}
	     
	#if defined(ARDUINO_ARCH_AVR)

	#elif defined(ARDUINO_ARCH_SAM)
	  // SAM-specific code
	#else
	WiFiClient WebPageState::getClient(){
		return this->client;
	}
	#endif

#endif 
