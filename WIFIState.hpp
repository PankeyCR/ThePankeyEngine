
#ifndef WIFIState_hpp
	#define WIFIState_hpp

	#include "Application.hpp"
	#include "WIFIConnection.hpp"
	#include "BaseAppState.hpp"

	#ifdef WIFIState_LogApp
		#include "pankey_Logger.hpp"
		#define WIFIStateLog(location,method,type,mns) pankey_Log(this,location,"WIFIState",method,type,mns)
	#else
		#define WIFIStateLog(location,method,type,mns)
	#endif

	namespace pankey{

		class WIFIState : BaseAppState<Application,float> {
			public:
				WIFIState(){}
				virtual ~WIFIState(){}
			
				virtual void initializeState(Application& a_app){
					auto i_events = a_app.getEventManager();
					i_events.add<WIFIState>("initializeWIFI", this, initializeWIFI);
				}

				virtual void initializeWIFI(Application& a_app){
					if(hasWifiLAN()){
						disconnectWIFI();
					}
					auto i_settings = a_app.getSettings();
					Note i_mac = i_settings.getNote(m_mac_name);
					Note i_ip = i_settings.getNote(m_ip_name);
					Note i_gateway = i_settings.getNote(m_gateway_name);
					Note i_subnet = i_settings.getNote(m_subnet_name);
					Note i_dns = i_settings.getNote(m_dns_name);
					Note i_router = i_settings.getNote(m_router_name);
					Note i_password = i_settings.getNote(m_password_name);

					if(i_mac.isEmpty() || i_ip.isEmpty() || i_gateway.isEmpty() || i_subnet.isEmpty() || i_dns.isEmpty() || i_router.isEmpty() || i_password.isEmpty()){
						return;
					}

					initializeWIFI(i_mac, i_ip, i_gateway, i_subnet, i_dns, i_router, i_password);
				}

			protected:

				Note m_mac_name = "wifi_mac";
				Note m_ip_name = "wifi_ip";
				Note m_gateway_name = "wifi_gateway";
				Note m_subnet_name = "wifi_subnet";
				Note m_dns_name = "wifi_dns";
				Note m_router_name = "wifi_name";
				Note m_password_name = "wifi_password";
		};

	}

#endif