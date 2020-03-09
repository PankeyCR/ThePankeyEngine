

#ifndef WebPageState_h
#define WebPageState_h

#include "Arduino.h"
#include "AppState.h"
#include "Command.h"
#include "List.h"
#include "PrimitiveList.h"
#include "Logger.h"

#if defined(ARDUINO_ARCH_AVR)

#elif defined(ARDUINO_ARCH_SAM)
  // SAM-specific code
#else
	#include <ESP8266WiFi.h>
#endif

class WebPageState : public AppState{
    public:
		WebPageState(const char* ssid,const char* pass);
		WebPageState(String id, const char* ssid,const char* pass);
		~WebPageState();
		virtual void initialize(Application *app);
		virtual void update();
		virtual void addCommand(Command<WebPageState>* cmd);
		virtual void removeCommand(int index);
		virtual void clearCommands();
		virtual const char* getSSID();
		virtual const char* getPassWord();
		virtual String getLocalIP();
		virtual String getHeader();
		// virtual bool isServerAvailable();
		// virtual bool isClientConnected();
		// virtual bool isClientAvailable();
		virtual bool containHeader(String ch);
		virtual void println(String ch);
		#if defined(ARDUINO_ARCH_AVR)

		#elif defined(ARDUINO_ARCH_SAM)
		  // SAM-specific code
		#else
		virtual WiFiClient getClient();
		#endif
	protected:
		List<Command<WebPageState>>* commands = nullptr;
		const char* ssid;
		const char* password;
		String header;
		bool initServer = true;
		#if defined(ARDUINO_ARCH_AVR)

		#elif defined(ARDUINO_ARCH_SAM)
		  // SAM-specific code
		#else
		WiFiServer* server;
		WiFiClient client;
		#endif
};

#endif 
