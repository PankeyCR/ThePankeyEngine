

#ifndef WIFIState_h
#define WIFIState_h

#include "AppState.h"
#include "Arduino.h"
#include "BaseInvoke.h"
#include "SerialMessageState.h"
#include "List.h"
#include "PrimitiveList.h"
#include "Annotation.h"
#include "SerialMessageControlledState.h"

#if defined(ARDUINO_ARCH_ESP8266)
	#include "WiFi.h"
#elif defined(ARDUINO_ARCH_ESP32)
	#include "WiFi.h"
#endif

#ifdef WIFIStateLogApp
	#include "Logger.h"
	#define WIFIStateLog(name,method,type,mns) Log(name,method,type,mns)
#else
	#define WIFIStateLog(name,method,type,mns)
#endif


class WIFIState : public SerialMessageControlledState{
    public:
		WIFIState(){
			requests = new PrimitiveList<String>();
			events = false;
			annotation1 = false;
			annotation2 = false;
			annotation3 = false;
			
			events.addLValues("ConectWifi",&WIFIState::ConectWifi);
			events.addLValues("DisconectWifi",&WIFIState::DisconectWifi);
			events.addLValues("SendScan",&WIFIState::SendScan);
			events.addLValues("netsize",&WIFIState::SendNetworkSize);
			events.addLValues("containnet",&WIFIState::SendContainID);
			events.addLValues("wifistate",&WIFIState::WifiState);
			events.addLValues("ConectPort",&WIFIState::ConectPort);
			
			annotation3.addLValues("requestConnexionWifi",&WIFIState::requestConnexionWifi);
			annotation1.addLValues("requestDisconnexionWifi",&WIFIState::requestDisconnexionWifi);
			annotation1.addLValues("requestSendScan",&WIFIState::requestSendScan);
			annotation1.addLValues("requestSendNetworkSize",&WIFIState::requestSendNetworkSize);
			annotation2.addLValues("requestSendContainNetwork",&WIFIState::requestSendContainNetwork);
			annotation1.addLValues("requestWifiState",&WIFIState::requestWifiState);
			annotation3.addLValues("requestPortConnexion",&WIFIState::requestPortConnexion);
		}
		virtual ~WIFIState(){
			delete requests;
		}
		bool instanceof(String name){return name == "WIFIState" || SerialMessageControlledState::instanceof(name);}
		String getClassName(){return "WIFIState";}
		
		virtual bool invoke(String method){
			WIFIStateLog("WIFIState", "invoke",  "println", "invoke method without parameters");
			return annotation1.invoke(this,method);
		}
		virtual bool invoke(String method, String parameter1){
			WIFIStateLog("WIFIState", "invoke",  "println", "invoke method with 1 parameter");
			return annotation2.invoke(this,method,parameter1);
		}
		virtual bool invoke(String method, String parameter1, String parameter2){
			WIFIStateLog("WIFIState", "invoke",  "println", "invoke method with 1 parameter");
			return annotation3.invoke(this,method,parameter1,parameter2);
		}
		
		void update(float tpc){
			time += tpc;
			if(time > timeLimit){
				time = 0.0f;
				if(requests->isEmpty()){
					WIFIStateLog("WIFIState", "update",  "println", "requests->isEmpty()");
					return;
				}
				int x = 0;
				WIFIStateLog("WIFIState", "update",  "println", "start for");
				for(; x < requests->getPosition(); x++){
					String method = *requests->getByPosition(x);
					WIFIStateLog("WIFIState", "update",  "println", method);
					if(events.invoke(this, method)){
						WIFIStateLog("WIFIState", "update",  "println", "break");
						break;
					}
				}
				for(int s = 0; s < x+1; s++){
					WIFIStateLog("WIFIState", "update",  "println", "requests->removeDeleteByPosition(0)");
					requests->removeDeleteByPosition(0);
				}
			}
		}
		
		bool requestPortConnexion(String host, String port){
			connexionHost = host;
			connexionPort = port;
			requests->addLValue("ConectPort");
			return true;
		}
		
		bool requestConnexionWifi(String name, String password){
			conexionName = name;
			conexionPassword = password;
			requests->addLValue("ConectWifi");
			return true;
		}
		
		bool requestDisconnexionWifi(){
			requests->addLValue("DisconectWifi");
			return true;
		}
		
		bool requestSendScan(){
			requests->addLValue("SendScan");
			return true;
		}
		
		bool requestSendNetworkSize(){
			requests->addLValue("netsize");
			return true;
		}
		
		bool requestSendContainNetwork(String name){
			containId_S = name;
			requests->addLValue("containnet");
			return true;
		}
		
		bool requestWifiState(){
			requests->addLValue("wifistate");
			return true;
		}
	protected:
	
		bool ConectPort(){
			if(client.connect(connexionHost.c_str(), connexionPort.toInt())){
				this->send(String("clientconnected ") + connexionHost + connexionPort);
			}
			return true;
		}
		bool ConectWifi(){
			if(conexionState){
				WiFi.disconnect();
			}
			WiFi.begin(conexionName.c_str(), conexionPassword.c_str());
			conexionState = true;
			return true;
		}
		bool DisconectWifi(){
			conexionState = false;
			WiFi.disconnect();
			return true;
		}
		bool SendScan(){
			int x = this->getNetworkSize();
			this->send("sendingscan");
			for(int s = 0; s < x; s++){
				this->send(String("id ") + String(s) + String(" ") + this->getID(s));
			}
			return true;
		}
		bool SendNetworkSize(){
			int x = this->getNetworkSize();
			this->send(String("networksize ") + String(x));
			return true;
		}
		int getNetworkSize(){
			#if defined(ARDUINO_ARCH_ESP8266)
				return WiFi.scanNetworks();
			#elif defined(ARDUINO_ARCH_ESP32)
				return WiFi.scanNetworks();
			#else
				return -1;
			#endif
		}
		
		String getID(int i){
			#if defined(ARDUINO_ARCH_ESP8266)
				return WiFi.SSID(i);
			#elif defined(ARDUINO_ARCH_ESP32)
				return WiFi.SSID(i);
			#else
				return "";
			#endif
		}
		
		bool containID(String i){
			int x = getNetworkSize();
			for(int s = 0; s < x; s++){
				if(this->getID(s) == i){
					return true;
				}
			}
			return false;
		}
		
		bool SendContainID(){
			int x = getNetworkSize();
			this->send("sendingcontainid");
			for(int s = 0; s < x; s++){
				if(this->getID(s) == containId_S){
					this->send(String("containID ") + String(s) + String(" ") + containId_S);
					containId_S = "";
				}
			}
			return true;
		}
		bool WifiState(){
			this->send(String("wifistate ") + String(WiFi.status() == WL_CONNECTED));
			if(WiFi.status() == WL_CONNECTED){
				this->send(String("conectedwifiID ") + conexionName);
			}
			return true;
		}
		
		WiFiClient client;
		String connexionHost = "";
		String connexionPort = "";
		String containId_S = "";
		bool conexionState = false;
		String lastconexionName = "";
		String lastconexionPassword = "";
		String conexionName = "";
		String conexionPassword = "";
		float time = 0.0f;
		float timeLimit = 0.0f;
		Annotation<String,bool,WIFIState> events;
		List<String>* requests = nullptr;
		Annotation<String,bool,WIFIState> annotation1;
		Annotation<String,bool,WIFIState,String> annotation2;
		Annotation<String,bool,WIFIState,String,String> annotation3;
};

#endif 
