
#include "ame_Level.hpp"

#if defined(ame_untilLevel_6)

#ifndef DataBaseWebProtocol_hpp
#define DataBaseWebProtocol_hpp

#include "Application.hpp"
#include "ServerProtocol.hpp"
#include "SerialPort.hpp"
#include "Message.hpp"
#include "SerialMessageState.hpp"
#include "MemoryRam.hpp"

#ifdef DataBaseWebProtocolLogApp
	#include "Logger.hpp"
	#define DataBaseWebProtocolLog(name,method,type,mns) Log(name,method,type,mns)
#else
	#define DataBaseWebProtocolLog(name,method,type,mns) 
#endif

namespace ame{

class DataBaseWebProtocol : public ServerProtocol{	
    public:
		DataBaseWebProtocol(){}
		virtual ~DataBaseWebProtocol(){}
		
		virtual SerialPort* getUpdateSerialPort(SerialServer* server){
			if(this->serialState == nullptr){
				DataBaseWebProtocolLog("DataBaseWebProtocol", "getUpdateSerialPort",  "println", "this->serialState == nullptr");
				return nullptr;
			}
			SerialPort* port = server->available();
			if(port == nullptr){
				return nullptr;
			}
			DataBaseWebProtocolLog("DataBaseWebProtocol", "getUpdateSerialPort",  "println", port->getName());
			
            port->println(WebPage);
			
			port->stop();
			delete port;
			// DataBaseWebProtocolLog("DataBaseWebProtocol", "getUpdateSerialPort",  "println", String("ram: ") + String(getRamSize()));
			return nullptr;
		}
		
		virtual void UpdateSerialPort(SerialPort* port){
		}
		
		virtual void update(SerialServer* server, float tpc){
			server->handleClient();
		}
		
	protected:
		String WebPage =   "<!DOCTYPE html>\
							<!DOCTYPE html>\
							<html lang=\"en\">\
							<head>\
							<meta charset=\"utf-8\" />\
							\
							<title>Tuts+ Chat Application</title>\
							<meta name=\"description\" content=\"Tuts+ Chat Application\" />\
							<link rel=\"stylesheet\" href=\"style.css\" />\
							</head>\
							<body>\
							<div id=\"wrapper\">\
							<div id=\"menu\">\
							<p class=\"welcome\">Welcome, <b></b></p>\
							<p class=\"logout\"><a id=\"exit\" href=\"#\">Exit Chat</a></p>\
							</div>\
							\
							<div id=\"chatbox\"></div>\
							\
							<form name=\"message\" action="">\
							<input name=\"usermsg\" type=\"text\" id=\"usermsg\" />\
							<input name=\"submitmsg\" type=\"submit\" id=\"submitmsg\" value=\"Send\" /></form>\
							</div>\
							<script type=\"text/javascript\" src=\"https://cdnjs.cloudflare.com/ajax/libs/jquery/3.5.1/jquery.min.js\"></script><script type=\"text/javascript\">\
							</script>\
							</body>\
							</html>";
};

}

#endif 

#endif 
