
#ifndef SerialNetwork_hpp
	#define SerialNetwork_hpp

	#include "Application.hpp"
	#include "BaseAppState.hpp"
	#include "Note.hpp"
	
	#include "InvokeCommandList.hpp"
	#include "InvokeRawList.hpp"

	#ifdef SerialNetwork_LogApp
		#include "pankey_Logger.hpp"
		#define SerialNetworkLog(location,method,type,mns) pankey_Log((void*)this,location,"SerialNetwork",method,type,mns)
	#else
		#define SerialNetworkLog(location,method,type,mns) 
	#endif

	namespace pankey{

		class SerialNetwork : public BaseAppState<Application,float>{	
			public:	
				SerialNetwork(){}
				virtual ~SerialNetwork(){}
				
				virtual void setIP(Note a_ip){m_ip = a_ip;}
				virtual void setMAC(Note a_mac){m_mac = a_mac;}

				virtual Note getIP(){return this->m_ip;}
				virtual Note getMAC(){return this->m_mac;}
				
				virtual void instantSend(Note a_message){}

				virtual void instantSend(Note a_name, Note a_message){}
				
				virtual void send(Note a_message){}

				virtual void send(Note a_name, Note a_message){}
				
				virtual bool isConnected(Note a_name){return false;}
			
				virtual void connect() {}
				
				virtual void connect(Note a_name) {}
					
				virtual void disconect() {}
				
				virtual void disconect(Note a_name) {}
				
				virtual bool ping(Note a_name){
					return false;
				}
				
				virtual void addDelivery(command<const Note&> a_command){
					SerialNetworkLog(pankey_Log_StartMethod, "addDelivery",  "println", "command<const Note&>");
					m_commands.add(a_command);
					SerialNetworkLog(pankey_Log_EndMethod, "addDelivery",  "println", "");
				}
				
				virtual void addDelivery(InvokeMethod<const Note&> a_command){
					SerialNetworkLog(pankey_Log_StartMethod, "addDelivery",  "println", "InvokeMethod<const Note&>");
					m_methods.add(a_command);
					SerialNetworkLog(pankey_Log_EndMethod, "addDelivery",  "println", "");
				}
				
				virtual void addDelivery(command<Application&> a_command){
					SerialNetworkLog(pankey_Log_StartMethod, "addDelivery",  "println", "command<const Note&>");
					m_app_commands.add(a_command);
					SerialNetworkLog(pankey_Log_EndMethod, "addDelivery",  "println", "");
				}
				
				virtual void addDelivery(InvokeMethod<Application&,const Note&> a_command){
					SerialNetworkLog(pankey_Log_StartMethod, "addDelivery",  "println", "InvokeMethod<Application&,const Note&>");
					m_app_methods.add(a_command);
					SerialNetworkLog(pankey_Log_EndMethod, "addDelivery",  "println", "");
				}
				
				virtual void DeliverMessage(Application& a_app, Note& a_message){
					SerialNetworkLog(pankey_Log_StartMethod, "DeliverMessage",  "println", "");
					SerialNetworkLog(pankey_Log_Statement, "DeliverMessage",  "println", "incoming message:");
					SerialNetworkLog(pankey_Log_Statement, "DeliverMessage",  "println", a_message);
					if(a_message.isEmpty()){
						SerialNetworkLog(pankey_Log_Statement, "DeliverMessage",  "println", "a_message.isEmpty()");
						return;
					}
					invokeAll<const Note&>(m_commands, a_message);
					invokeAll<const Note&>(m_methods, a_message);
					invokeAll<Application&>(m_app_commands, a_app);
					invokeAll<Application&,const Note&>(m_app_methods, a_app, a_message);
					SerialNetworkLog(pankey_Log_EndMethod, "DeliverMessage",  "println", "");
				}
				
			protected:
				Note m_ip = "150.1.0.0";
				Note m_mac = "0.0.0.0.0.0";

				CommandList<const Note&> m_commands;
				MethodList<const Note&> m_methods;
				CommandList<Application&> m_app_commands;
				MethodList<Application&,const Note&> m_app_methods;
		};

	}

#endif