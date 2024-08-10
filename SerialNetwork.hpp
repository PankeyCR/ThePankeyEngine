
#ifndef SerialNetwork_hpp
	#define SerialNetwork_hpp

	#include "State.hpp"
	#include "Note.hpp"
	
	#include "InvokeCommandList.hpp"
	#include "InvokeRawList.hpp"

	#ifdef SerialNetwork_LogApp
		#include "higgs_Logger.hpp"
		#define SerialNetworkLog(location,method,type,mns) higgs_Log((void*)this,location,"SerialNetwork",method,type,mns)
	#else
		#define SerialNetworkLog(location,method,type,mns) 
	#endif

	namespace higgs{

		class SerialNetwork : public State<>{	
			public:	
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
				
				virtual void addDelivery(command<const Note&>& a_command){
					m_commands.add(a_command);
				}
				
				virtual void addDelivery(const InvokeMethod<const Note&>& a_command){
					m_methods.add(a_command);
				}
				
				virtual void DeliverMessage(const Note& a_mns){
					if(a_mns.isEmpty()){
						return;
					}
					invokeAll<const Note&>(m_commands, a_mns);
					invokeAll<const Note&>(m_methods, a_mns);
				}
				
			protected:
				Note m_ip = "150.1.0.0";
				Note m_mac = "0.0.0.0.0.0";

				CommandList<const Note&> m_commands;
				MethodList<const Note&> m_methods;
		};

	}

#endif