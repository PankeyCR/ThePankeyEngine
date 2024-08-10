
#ifndef WIFIWebPage_hpp
	#define WIFIWebPage_hpp

	#include "InvokeMethod.hpp"
	#include "UpdateFunctionListManager.hpp"
	#include "StateListManager.hpp"
	#include "BaseAppState.hpp"
	#include "Application.hpp"
	#include "Note.hpp"
	#include "System.hpp"
	#include <WiFi.h>

	#ifdef WIFIWebPage_LogApp
		#include "higgs_Logger.hpp"
		#define WIFIWebPageLog(location,method,type,mns) higgs_Log((void*)this,location,"WIFIWebPage",method,type,mns)
	#else
		#define WIFIWebPageLog(location,method,type,mns) 
	#endif

	namespace higgs{

		class WIFIWebPage : public BaseAppState<Application>{
			public:
				WIFIWebPage():server(80){}
				WIFIWebPage(const Note& a_responce, const Note& a_js):server(80){
					m_http_responce_name = a_responce;
					m_web_page_name = a_js;
				}
				virtual ~WIFIWebPage(){}

				virtual void initializeState(Application& a_app){
					WIFIWebPageLog(higgs_Log_StartMethod, "initialize", "println", "");
					server.begin();
					WIFIWebPageLog(higgs_Log_EndMethod, "initialize", "println", "");
				}
				
				virtual void updateState(Application& a_app){
					// WIFIWebPageLog(higgs_Log_StartMethod, "updateState", "println", "");

					WiFiClient client = server.available();

					if (client) {
						WIFIWebPageLog(higgs_Log_Statement, "updateState", "println", "connecting to client...");
						currentTime = millis();
						previousTime = currentTime;
						Note currentLine = "";
						while (client.connected() && currentTime - previousTime <= timeoutTime) {
							WIFIWebPageLog(higgs_Log_Statement, "updateState", "println", "connected to client");
							currentTime = millis();
      						if (client.available()) {
								WIFIWebPageLog(higgs_Log_Statement, "updateState", "println", "client available");
								char c = client.read();
								m_header.addLocalValue(c); 
								if (c == '\n') {
									WIFIWebPageLog(higgs_Log_Statement, "updateState", "println", "client end of line");
									if (currentLine.length() == 0) {
										header_event.update(m_header);
										header_state_event.update(m_header);

										auto& i_settings = a_app.getSettings();
										Note i_http_responce;
										if(m_http_responce_name.isEmpty()){
											i_http_responce = getDefaultHTTPResponce();
										}else{
											i_http_responce = i_settings.getNote(m_http_responce_name);
										}

										Note i_web_page_pre_parser = i_settings.getNote(m_web_page_name);
										
										Note i_web_page_js = parser(i_web_page_pre_parser);

										client.println(i_http_responce);
										client.println();
										WIFIWebPageLog(higgs_Log_Statement, "updateState", "println", "printing page");
										client.println(i_web_page_js);
										client.println();
									}else{
										currentLine.clear();
										WIFIWebPageLog(higgs_Log_Statement, "updateState", "println", "clearing currentLine");
									}
								}else if(c != '\r'){
									currentLine.addLocalValue(c); 
								}
							}
						}
						client.stop();
						m_header.clear();
					}
					// WIFIWebPageLog(higgs_Log_EndMethod, "updateState", "println", "");
  				}

				virtual Note getDefaultHTTPResponce(){
					return  "HTTP/1.1 200 OK\n"
							"Content-type:text/html\n"
							"Connection: close\n";
				}

				virtual void setHTTPResponce(const Note& a_responce){
					m_http_responce_name = a_responce;
				}

				virtual void setJavaScriptPage(const Note& a_js){
					m_web_page_name = a_js;
				}

				virtual Note parser(const Note& a_text){
					return m_parser(a_text);
				}

				virtual void setParser(InvokeMethodReturn<Note,const Note&> a_parser){
					m_parser = a_parser;
				}

			public:
				UpdateFunctionListManager<const Note&> header_event;
				StateListManager<const Note&> header_state_event;

			protected:
				unsigned long currentTime = millis();
				unsigned long previousTime = 0; 
				long timeoutTime = 2000;
				
				Note m_header;
				
				Note m_http_responce_name;
				Note m_web_page_name = "web_page";

				WiFiServer server;

				InvokeMethodReturn<Note,const Note&> m_parser;
		};

	}

#endif
