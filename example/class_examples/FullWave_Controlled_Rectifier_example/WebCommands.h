

#ifndef WebCommands_h
#define WebCommands_h

#include "Arduino.h"
#include "WebPageState.h"
#include "Command.h"

#if defined(ARDUINO_ARCH_AVR)

#elif defined(ARDUINO_ARCH_SAM)
  // SAM-specific code
#else
	#include <ESP8266WiFi.h>
#endif

class WebCommands : public Command<WebPageState>{
    public:
		WebCommands(){
		}
		~WebCommands(){}
    
		virtual void execute(WebPageState* w){
  		#if defined(ARDUINO_ARCH_AVR)
  			
  		#else// turns the GPIOs on and off      
//        if(w->containHeader("GET /5/on")){
//          output5State = "on";
//          digitalWrite(output5, HIGH);
//        } else if (w->containHeader("GET /5/off")) {
//          output5State = "off";
//          digitalWrite(output5, LOW);
//        } else if (w->containHeader("GET /4/on")) {
//          output4State = "on";
//          digitalWrite(output4, HIGH);
//        } else if (w->containHeader("GET /4/off")) {
//          output4State = "off";
//          digitalWrite(output4, LOW);
//        }
        
        // Display the HTML web page
        w->println("<!DOCTYPE html><html>");
        w->println("<head><meta name=\"viewport\" content=\"width=device-width, initial-scale=1\">");
        w->println("<link rel=\"icon\" href=\"data:,\">");
        // CSS to style the on/off buttons 
        // Feel free to change the background-color and font-size attributes to fit your preferences
        w->println("<style>html { font-family: Helvetica; display: inline-block; margin: 0px auto; text-align: center;}");
        w->println(".button { background-color: #195B6A; border: none; color: white; padding: 16px 40px;");
        w->println("text-decoration: none; font-size: 30px; margin: 2px; cursor: pointer;}");
        w->println(".button2 {background-color: #77878A;}</style></head>");
        
        // Web Page Heading
        w->println("<body><h1>ESP8266 Web Server</h1>");
        
        // Display current state, and ON/OFF buttons for GPIO 5  
//        w->println("<p>GPIO 5 - State " + output5State + "</p>");
        // If the output5State is off, it displays the ON button       
//        if (output5State=="off") {
//          w->println("<p><a href=\"/5/on\"><button class=\"button\">ON</button></a></p>");
//        } else {
//          w->println("<p><a href=\"/5/off\"><button class=\"button button2\">OFF</button></a></p>");
//        } 
           
        // Display current state, and ON/OFF buttons for GPIO 4  
//        w->println("<p>GPIO 4 - State " + output4State + "</p>");
//        // If the output4State is off, it displays the ON button       
//        if (output4State=="off") {
//          w->println("<p><a href=\"/4/on\"><button class=\"button\">ON</button></a></p>");
//        } else {
//          w->println("<p><a href=\"/4/off\"><button class=\"button button2\">OFF</button></a></p>");
//        }
        w->println("</body></html>");
        
        // The HTTP response ends with another blank line
        w->println("");
  		#endif
		}
	
};

#endif 
