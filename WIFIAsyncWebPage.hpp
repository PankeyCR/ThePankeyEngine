
#ifndef WIFIAsyncWebPage_hpp
	#define WIFIAsyncWebPage_hpp

	#include "InvokeMethod.hpp"
	#include "UpdateFunctionListManager.hpp"
	#include "StateListManager.hpp"
	#include "BaseAppState.hpp"
	#include "Application.hpp"
	#include "Note.hpp"
	#include "System.hpp"
	#include <WiFi.h>
	#include <ESPAsyncWebServer.h>

	#ifdef WIFIAsyncWebPage_LogApp
		#include "higgs_Logger.hpp"
		#define WIFIAsyncWebPageLog(location,method,type,mns) higgs_Log((void*)this,location,"WIFIAsyncWebPage",method,type,mns)
	#else
		#define WIFIAsyncWebPageLog(location,method,type,mns) 
	#endif

	namespace higgs{

		class WIFIAsyncWebPage : public BaseAppState<Application>{
			public:
				WIFIAsyncWebPage():server(80){}
				WIFIAsyncWebPage(const Note& a_js):server(80){
					m_web_page_name = a_js;
				}
				virtual ~WIFIAsyncWebPage(){}

				virtual void initializeState(Application& a_app){
					WIFIAsyncWebPageLog(higgs_Log_StartMethod, "initialize", "println", "");

					auto& i_settings = a_app.getSettings();

					Note i_web_page_pre_parser = i_settings.getNote(m_web_page_name);
					
					Note i_web_page_js = parser(i_web_page_pre_parser);
  
					// server.on("/", HTTP_GET, [](AsyncWebServerRequest *request){
					// 	System::console.println("sending page");
					// 	//request->send(200, "text/html;text/css", i_web_page_js.pointer());
					// });

					server.begin();
					WIFIAsyncWebPageLog(higgs_Log_EndMethod, "initialize", "println", "");
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
				AsyncWebServer server;

			protected:
				Note m_web_page_name = "web_page";

				InvokeMethodReturn<Note,const Note&> m_parser;
		};

	}

#endif
