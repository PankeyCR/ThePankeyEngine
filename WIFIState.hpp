
#ifndef WIFIState_hpp
#define WIFIState_hpp
#define WIFIState_AVAILABLE

#include "BaseAppState.h"
#include "SerialMessageState.h"
#include "PrimitiveList.h"
#include "SerialMessageControlledState.h"
#include "WIFISerialPort.h"
#include "DefaultPortProtocol.h"

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

namespace higgs{

class WIFIState IMPLEMENTATION_BaseAppState {
    public:
		WIFIState(){}
		virtual ~WIFIState(){}
		bool instanceof(cppObjectClass* cls){
			return cls == Class<WIFIState>::classType || SerialMessageControlledState::instanceof(cls);
		}
		cppObjectClass* getClass(){return Class<WIFIState>::classType;}
		
		void update(float tpc){
			time += tpc;
			if(time > timeLimit){
				// WIFIStateLog("WIFIState", "update",  "println", String("Time limit: ") + String(timeLimit));
				time = 0.0f;
				if(requests->isEmpty()){
					// Serial.println(freeMemory());
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
		
		void requestPortConnexion(String host, String port){
			WIFIStateLog("WIFIState", "requestPortConnexion",  "println", String("host: ") + host);
			WIFIStateLog("WIFIState", "requestPortConnexion",  "println", String("port: ") + port);
			connexionHost = host;
			connexionPort = port;
			requests->addLValue("ConectPort");
		}
		
		void requestConnexionWifi(String name, String password){
			WIFIStateLog("WIFIState", "requestConnexionWifi",  "println", String("name: ") + name);
			WIFIStateLog("WIFIState", "requestConnexionWifi",  "println", String("password: ") + password);
			conexionName = name;
			conexionPassword = password;
			requests->addLValue("ConectWifi");
		}
		
		void requestDisconnexionWifi(){
			WIFIStateLog("WIFIState", "requestDisconnexionWifi",  "println", "");
			requests->addLValue("DisconectWifi");
		}
		
		void requestSendScan(){
			WIFIStateLog("WIFIState", "requestSendScan",  "println", "");
			requests->addLValue("SendScan");
		}
		
		void requestSendNetworkSize(){
			WIFIStateLog("WIFIState", "requestSendNetworkSize",  "println", "");
			requests->addLValue("netsize");
		}
		
		void requestSendContainNetwork(String name){
			WIFIStateLog("WIFIState", "requestSendContainNetwork",  "println", String("name: ") + name);
			containId_S = name;
			requests->addLValue("containnet");
		}
		
		void requestWifiState(){
			WIFIStateLog("WIFIState", "requestWifiState",  "println", "");
			requests->addLValue("wifistate");
		}
	protected:
	
		bool ConectPort(){
			WIFIStateLog("WIFIState", "ConectPort",  "println", "");
			WiFiClient client;
			if(client.connect(connexionHost.c_str(), connexionPort.toInt())){
				SerialMessageState* serialState = this->getSerialMessageState();
				if(serialState == nullptr){
					return false;
				}
				serialState->addSerialPort(new WIFISerialPort(client), new DefaultPortProtocol());
			}
			return true;
		}
		bool ConectWifi(){
			WIFIStateLog("WIFIState", "ConectWifi",  "println", "");
			if(conexionState){
				WiFi.disconnect();
			}
			#if defined(ARDUINO_ARCH_ESP8266)
			char mnsArray[conexionName.length()+1];
			conexionName.toCharArray(mnsArray, conexionName.length()+1);
			WiFi.begin(mnsArray, conexionPassword.c_str());
			WIFIStateLog("WIFIState", "ConectWifi",  "println", "WiFi.begin");
			#elif defined(ARDUINO_ESP32_DEV)
			WiFi.begin(conexionName.c_str(), conexionPassword.c_str());
			WIFIStateLog("WIFIState", "ConectWifi",  "println", "WiFi.begin");
			#elif defined(LILYGO_WATCH_2020_V1) || defined(LILYGO_WATCH_2020_V2) || defined(LILYGO_WATCH_2020_V3)
			WiFi.begin(conexionName.c_str(), conexionPassword.c_str());
			WIFIStateLog("WIFIState", "ConectWifi",  "println", "WiFi.begin");
			#endif 
			conexionState = true;
			WIFIStateLog("WIFIState", "ConectWifi",  "println", "connected");
			return true;
		}
		bool DisconectWifi(){
			WIFIStateLog("WIFIState", "DisconectWifi",  "println", "");
			conexionState = false;
			WiFi.disconnect();
			return true;
		}
		bool SendScan(){
			WIFIStateLog("WIFIState", "SendScan",  "println", "");
			int x = this->getNetworkSize();
			if(x == -1){
				WIFIStateLog("WIFIState", "SendScan",  "println", "no wifi networks");
				return false;
			}
			this->send("sendingscan");
			for(int s = 0; s < x; s++){
				this->send(String("id ") + String(s) + String(" ") + this->getID(s));
			}
			return true;
		}
		bool SendNetworkSize(){
			WIFIStateLog("WIFIState", "SendNetworkSize",  "println", "");
			int x = this->getNetworkSize();
			this->send(String("networksize ") + String(x));
			return true;
		}
		int getNetworkSize(){
			WIFIStateLog("WIFIState", "getNetworkSize",  "println", "");
			#if defined(ARDUINO_ARCH_ESP8266)
				WIFIStateLog("WIFIState", "getNetworkSize",  "println", "esp8266 hardware");
				return WiFi.scanNetworks();
			#elif defined(ARDUINO_ARCH_ESP32)
				WIFIStateLog("WIFIState", "getNetworkSize",  "println", "esp32 hardware");
				return WiFi.scanNetworks();
			#else
				return -1;
			#endif
		}
		
		String getID(int i){
			WIFIStateLog("WIFIState", "getID",  "println", "");
			#if defined(ARDUINO_ARCH_ESP8266)
				return WiFi.SSID(i);
			#elif defined(ARDUINO_ARCH_ESP32)
				return WiFi.SSID(i);
			#else
				return "";
			#endif
		}
		
		bool containID(String i){
			WIFIStateLog("WIFIState", "containID",  "println", "");
			int x = getNetworkSize();
			for(int s = 0; s < x; s++){
				if(this->getID(s) == i){
					return true;
				}
			}
			return false;
		}
		
		bool SendContainID(){
			WIFIStateLog("WIFIState", "SendContainID",  "println", "");
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
			WIFIStateLog("WIFIState", "WifiState",  "println", "");
			this->send(String("wifistate ") + String(WiFi.status() == WL_CONNECTED));
			if(WiFi.status() == WL_CONNECTED){
				this->send(String("conectedwifiID ") + conexionName);
			}
			return true;
		}
		
		String connexionHost = "";
		String connexionPort = "";
		String containId_S = "";
		bool conexionState = false;
		String lastconexionName = "";
		String lastconexionPassword = "";
		String conexionName = "";
		String conexionPassword = "";
		float time = 0.0f;
		float timeLimit = 5.0f;
		AnnotationMap<String,bool,WIFIState> events;
		List<String>* requests = nullptr;
};

template<class T>
void requestConnexionWifi(T* t, String n, String n2){
	t->requestConnexionWifi(n,n2);
}

template<class T>
void requestDisconnexionWifi(T* t){
	t->requestDisconnexionWifi();
}

template<class T>
void requestSendScan(T* t){
	t->requestSendScan();
}

template<class T>
void requestSendNetworkSize(T* t){
	t->requestSendNetworkSize();
}

template<class T>
void requestSendContainNetwork(T* t, String n){
	t->requestSendContainNetwork(n);
}

template<class T>
void requestWifiState(T* t){
	t->requestWifiState();
}

template<class T>
void requestPortConnexion(T* t, String n, String n2){
	t->requestPortConnexion(n,n2);
}

template<class T>
void initializeWIFIStateAnnotations(){
  ClassMethod<WIFIState<T>>::add("requestConnexionWifi");
  ClassMethod<WIFIState<T>>::add("requestDisconnexionWifi");
  ClassMethod<WIFIState<T>>::add("requestSendScan");
  ClassMethod<WIFIState<T>>::add("requestSendNetworkSize");
  ClassMethod<WIFIState<T>>::add("requestSendContainNetwork");
  ClassMethod<WIFIState<T>>::add("requestWifiState");
  ClassMethod<WIFIState<T>>::add("requestPortConnexion");
  
  StaticMethodMap<String,T*>* map = StaticInvoker<T,T*>::getMap();
  map->add("requestDisconnexionWifi",&requestDisconnexionWifi<T>);
  map->add("requestSendScan",&requestSendScan<T>);
  map->add("requestSendNetworkSize",&requestSendNetworkSize<T>);
  map->add("requestWifiState",&requestWifiState<T>);
  
  StaticMethodMap<String,T*,String>* map1 = StaticInvoker<T,T*,String>::getMap();
  map1->add("requestSendContainNetwork",&requestSendContainNetwork<T>);
  
  StaticMethodMap<String,T*,String,String>* map2 = StaticInvoker<T,T*,String,String>::getMap();
  map2->add("requestConnexionWifi",&requestConnexionWifi<T>);
  map2->add("requestPortConnexion",&requestPortConnexion<T>);
}

}

#endif