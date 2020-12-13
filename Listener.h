

#ifndef Listener_h
#define Listener_h

class Application;
#include "Arduino.h"
#include "cppObject.h"
#include "ListenerEvent.h"
#include "PrimitiveList.h"
#include "PrimitiveMap.h"
#include "Trio.h"

static PrimitiveMap<int,volatile bool>* SafeBool_m = nullptr;
static PrimitiveList<void (*)()>* ThreadMap_m = nullptr;
static PrimitiveList<void (*)()>* LoopMap_m = nullptr;
static PrimitiveMap<int,Trio<int,bool,PrimitiveList<ListenerEvent>>>* ListenerEventMap_m = nullptr;

template<int interrupt>
void Interrupt(){
	Trio<int,bool,PrimitiveList<ListenerEvent>>* trio = ListenerEventMap_m->get(interrupt);
	if(trio == nullptr){
		return;
	}
	if(trio->bot == nullptr || trio->top == nullptr || trio->mid == nullptr){
		return;
	}
	*trio->mid = !(*trio->mid);
	// Serial.println("inicio interrupt");
	iterate(trio->bot){
		trio->bot->getPointer()->event(interrupt,*trio->top,*trio->mid);
	}
	// Serial.println("fin interrupt");
}
template<int interrupt>
void ThreadInterrupt(){
	volatile bool* safe = SafeBool_m->get(interrupt);
	if(safe == nullptr){
		return;
	}
	if(*safe){
		Interrupt<interrupt>();
	}else{
		if(ThreadMap_m != nullptr){
			ThreadMap_m->add(&Interrupt<interrupt>);
		}
	}
}

template<int interrupt>
void LoopInterrupt(){
	Trio<int,bool,PrimitiveList<ListenerEvent>>* trio = ListenerEventMap_m->get(interrupt);
	if(trio == nullptr){
		return;
	}
	if(trio->bot == nullptr || trio->top == nullptr || trio->mid == nullptr){
		return;
	}
	if(*trio->mid != digitalRead(*trio->top)){
		*trio->mid = !(*trio->mid);
		for(int x = 0; x < trio->bot->getPos(); x++){
			trio->bot->getByPos(x)->event(interrupt,*trio->top,*trio->mid);
		}
	}
}

template<int interrupt>
void Interrupt(bool state){
	Trio<int,bool,PrimitiveList<ListenerEvent>>* trio = ListenerEventMap_m->get(interrupt);
	if(trio == nullptr){
		return;
	}
	if(trio->bot == nullptr || trio->top == nullptr || trio->mid == nullptr){
		return;
	}
	//*trio->mid = state;
	// Serial.println("inicio interrupt");
	for(int x = 0; x < trio->bot->getPos(); x++){
		trio->bot->getByPos(x)->event(interrupt,*trio->top,state);
	}
	// Serial.println("fin interrupt");
}

class Listener : public cppObject{
    public:
		typedef void (*Method)();
		Listener(){
			if(ListenerEventMap_m == nullptr){
				ListenerEventMap_m = new PrimitiveMap<int,Trio<int,bool,PrimitiveList<ListenerEvent>>>();
				ThreadMap_m = new PrimitiveList<void (*)()>();
				LoopMap_m = new PrimitiveList<void (*)()>();
				SafeBool_m = new PrimitiveMap<int,volatile bool>();
			}
		}
		virtual ~Listener(){
			delete ListenerEventMap_m;
			ListenerEventMap_m = nullptr;
			delete ThreadMap_m;
			ThreadMap_m = nullptr;
			delete LoopMap_m;
			LoopMap_m = nullptr;
			delete SafeBool_m;
			SafeBool_m = nullptr;
		}
		
		virtual void attach(Application* a){
			app = a;
		}
		virtual String getClassName(){return "Listener";}
		virtual bool instanceof(String name){
			return name == "Listener" || cppObject::instanceof(name);
		}
		virtual void Secure(){
			for(int x = 0; x < SafeBool_m->getPos(); x++){
				SafeBool_m->set(*SafeBool_m->getKeyByPos(x), true);
			}
		}
		virtual void UnSecure(){
			for(int x = 0; x < SafeBool_m->getPos(); x++){
				SafeBool_m->set(*SafeBool_m->getKeyByPos(x), false);
			}
		}
		virtual void InterruptEvent(){
			for(int x = 0; x < LoopMap_m->getPos(); x++){
				(*LoopMap_m->getByPos(x))();
			}
			for(int x = 0; x < ThreadMap_m->getPos(); x++){
				(*ThreadMap_m->getByPos(x))();
			}
			//ThreadMap_m->reset();
			ThreadMap_m->resetDelete();
		}
		
		template<int interrupt>
		void addEvent(int pin,bool state, ListenerEvent* e){
			addEvent<interrupt>(Interrupt<interrupt>, pin,state, e);
		}
		
		template<int interrupt>
		void addThreadEvent(int pin,bool state, ListenerEvent* e){
			addEvent<interrupt>(ThreadInterrupt<interrupt>, pin,state, e);
		}
		
		template<int interrupt>
		void addLoopEvent(int pin,bool state, ListenerEvent* e){
			LoopMap_m->add(LoopInterrupt<interrupt>);
			Trio<int,bool,PrimitiveList<ListenerEvent>>* trio = ListenerEventMap_m->get(interrupt);
			volatile bool* safe = SafeBool_m->get(interrupt);
			if(safe == nullptr){
				safe = new volatile bool();
				*safe = false;
				SafeBool_m->add(interrupt, safe);
			}
			if(trio == nullptr){
				//Serial.print("trio nullptr");
				trio = new Trio<int,bool,PrimitiveList<ListenerEvent>>(true);
				trio->top = new int(pin);
				trio->mid = new bool(state);
				trio->bot = new PrimitiveList<ListenerEvent>();
				ListenerEventMap_m->add(interrupt, trio);
				pinMode(pin,INPUT);
				//attachInterrupt(digitalPinToInterrupt(pin), method, CHANGE);
			}else{
				if(trio->mid == nullptr){
					trio->mid = new bool(state);
				}else{
					if(state != *trio->mid){
						//*trio->mid = false;
						*trio->mid = false;
					}
				}
				if(trio->top == nullptr){
					//Serial.print("top nullptr");
					trio->top = new int(pin);
					pinMode(pin,INPUT);
					//attachInterrupt(digitalPinToInterrupt(pin), method, CHANGE);
				}else{
					if(pin != *trio->top){
						//Serial.print("pin ");Serial.println(pin);
						//Serial.print("top ");Serial.println(*trio->top);
						pinMode(pin,INPUT);
						//detachInterrupt(digitalPinToInterrupt(*trio->top));
						*trio->top = pin;
						//attachInterrupt(digitalPinToInterrupt(pin), method, CHANGE);
					}
				}
				if(trio->bot == nullptr){
					trio->bot = new PrimitiveList<ListenerEvent>();
				}
			}
			if(trio->bot->contain(e)){
				return;
			}
			trio->bot->add(e);
		}
		template<int interrupt>
		void addEvent(Method method, int pin,bool state, ListenerEvent* e){
			//Serial.println("addEvent ");
			Trio<int,bool,PrimitiveList<ListenerEvent>>* trio = ListenerEventMap_m->get(interrupt);
			volatile bool* safe = SafeBool_m->get(interrupt);
			if(safe == nullptr){
				safe = new volatile bool();
				*safe = false;
				SafeBool_m->add(interrupt, safe);
			}
			if(trio == nullptr){
				//Serial.print("trio nullptr");
				trio = new Trio<int,bool,PrimitiveList<ListenerEvent>>(true);
				trio->top = new int(pin);
				trio->mid = new bool(state);
				trio->bot = new PrimitiveList<ListenerEvent>();
				ListenerEventMap_m->add(interrupt, trio);
				pinMode(pin,INPUT);
				attachInterrupt(digitalPinToInterrupt(pin), method, CHANGE);
			}else{
				if(trio->mid == nullptr){
					trio->mid = new bool(state);
				}else{
					if(state != *trio->mid){
						//*trio->mid = false;
						*trio->mid = false;
					}
				}
				if(trio->top == nullptr){
					//Serial.print("top nullptr");
					trio->top = new int(pin);
					pinMode(pin,INPUT);
					attachInterrupt(digitalPinToInterrupt(pin), method, CHANGE);
				}else{
					if(pin != *trio->top){
						//Serial.print("pin ");Serial.println(pin);
						//Serial.print("top ");Serial.println(*trio->top);
						pinMode(pin,INPUT);
						//detachInterrupt(digitalPinToInterrupt(*trio->top));
						*trio->top = pin;
						attachInterrupt(digitalPinToInterrupt(pin), method, CHANGE);
					}
				}
				if(trio->bot == nullptr){
					trio->bot = new PrimitiveList<ListenerEvent>();
				}
			}
			if(trio->bot->contain(e)){
				return;
			}
			trio->bot->add(e);
		}
		
		template<int interrupt>
		void addEvent(int pin, bool state){
			addEvent<interrupt>(Interrupt<interrupt>, pin, state);
		}
		template<int interrupt>
		void addThreadEvent(int pin, bool state){
			addEvent<interrupt>(ThreadInterrupt<interrupt>, pin, state);
		}
		template<int interrupt>
		void addLoopEvent(int pin, bool state){
			LoopMap_m->add(LoopInterrupt<interrupt>);
			Trio<int,bool,PrimitiveList<ListenerEvent>>* trio = ListenerEventMap_m->get(interrupt);
			volatile bool* safe = SafeBool_m->get(interrupt);
			if(safe == nullptr){
				safe = new volatile bool();
				*safe = false;
				SafeBool_m->add(interrupt, safe);
			}
			if(trio == nullptr){
				//Serial.print("trio nullptr");
				trio = new Trio<int,bool,PrimitiveList<ListenerEvent>>(true);
				trio->top = new int(pin);
				trio->mid = new bool(state);
				trio->bot = new PrimitiveList<ListenerEvent>();
				ListenerEventMap_m->add(interrupt, trio);
				pinMode(pin,INPUT);
				//attachInterrupt(digitalPinToInterrupt(pin), method, CHANGE);
			}else{
				if(trio->mid == nullptr){
					trio->mid = new bool(state);
				}else{
					if(state != *trio->mid){
						//*trio->mid = false;
						*trio->mid = false;
					}
				}
				if(trio->top == nullptr){
					//Serial.print("top nullptr");
					trio->top = new int(pin);
					pinMode(pin,INPUT);
					//(digitalPinToInterrupt(pin), method, CHANGE);
				}else{
					if(pin != *trio->top){
						//Serial.print("pin ");Serial.println(pin);
						//Serial.print("top ");Serial.println(*trio->top);
						pinMode(pin,INPUT);
						//detachInterrupt(digitalPinToInterrupt(*trio->top));
						*trio->top = pin;
						//attachInterrupt(digitalPinToInterrupt(pin), method, CHANGE);
					}
				}
			}
		}
		template<int interrupt>
		void addEvent(Method method, int pin, bool state){
			Trio<int,bool,PrimitiveList<ListenerEvent>>* trio = ListenerEventMap_m->get(interrupt);
			volatile bool* safe = SafeBool_m->get(interrupt);
			if(safe == nullptr){
				safe = new volatile bool();
				*safe = false;
				SafeBool_m->add(interrupt, safe);
			}
			if(trio == nullptr){
				//Serial.print("trio nullptr");
				trio = new Trio<int,bool,PrimitiveList<ListenerEvent>>(true);
				trio->top = new int(pin);
				trio->mid = new bool(state);
				trio->bot = new PrimitiveList<ListenerEvent>();
				ListenerEventMap_m->add(interrupt, trio);
				pinMode(pin,INPUT);
				attachInterrupt(digitalPinToInterrupt(pin), method, CHANGE);
			}else{
				if(trio->mid == nullptr){
					trio->mid = new bool(state);
				}else{
					if(state != *trio->mid){
						//*trio->mid = false;
						*trio->mid = false;
					}
				}
				if(trio->top == nullptr){
					//Serial.print("top nullptr");
					trio->top = new int(pin);
					pinMode(pin,INPUT);
					attachInterrupt(digitalPinToInterrupt(pin), method, CHANGE);
				}else{
					if(pin != *trio->top){
						//Serial.print("pin ");Serial.println(pin);
						//Serial.print("top ");Serial.println(*trio->top);
						pinMode(pin,INPUT);
						//detachInterrupt(digitalPinToInterrupt(*trio->top));
						*trio->top = pin;
						attachInterrupt(digitalPinToInterrupt(pin), method, CHANGE);
					}
				}
			}
		}
		
		template<int interrupt>
		void setState(bool state){
			Trio<int,bool,PrimitiveList<ListenerEvent>>* trio = ListenerEventMap_m->get(interrupt);
			if(trio == nullptr){
				return;
			}
			volatile bool* safe = SafeBool_m->get(interrupt);
			if(safe == nullptr){
				safe = new volatile bool();
				*safe = false;
				SafeBool_m->add(interrupt, safe);
			}
			if(trio->mid == nullptr){
				trio->mid = new bool(state);
			}else{
				if(state != *trio->mid){
					*trio->mid = state;
				}
			}
		}
		
		template<int interrupt>
		void addEvent(ListenerEvent* e){
			Trio<int,bool,PrimitiveList<ListenerEvent>>* trio = ListenerEventMap_m->get(interrupt);
			if(trio == nullptr){
				return;
			}
			volatile bool* safe = SafeBool_m->get(interrupt);
			if(safe == nullptr){
				safe = new volatile bool();
				*safe = false;
				SafeBool_m->add(interrupt, safe);
			}
			if(trio->bot == nullptr){
				trio->bot = new PrimitiveList<ListenerEvent>();
			}
			if(trio->bot->contain(e)){
				return;
			}
			trio->bot->add(e);
		}
		
		template<int interrupt>
		bool containEvent(ListenerEvent* e){
			Trio<int,bool,PrimitiveList<ListenerEvent>>* trio = ListenerEventMap_m->get(interrupt);
			if(trio == nullptr){
				return false;
			}
			if(trio->bot == nullptr){
				return false;
			}
			return trio->bot->contain(e);
		}
		
		void addEvent(int interrupt, int pin, bool state, ListenerEvent* e){
			Trio<int,bool,PrimitiveList<ListenerEvent>>* trio = ListenerEventMap_m->get(interrupt);
			if(trio == nullptr){
				return;
			}
			volatile bool* safe = SafeBool_m->get(interrupt);
			if(safe == nullptr){
				safe = new volatile bool();
				*safe = false;
				SafeBool_m->add(interrupt, safe);
			}
			if(trio->top == nullptr){
				trio->top = new int(pin);
			}else{
				if(pin != *trio->top){
					*trio->top = pin;
				}
			}
			if(trio->mid == nullptr){
				trio->mid = new bool(state);
			}else{
				if(state != *trio->mid){
					//*trio->mid = false;
					*trio->mid = false;
				}
			}
			if(trio->bot == nullptr){
				trio->bot = new PrimitiveList<ListenerEvent>();
			}
			if(trio->bot->contain(e)){
				return;
			}
			trio->bot->add(e);
		}
		
		template<int interrupt>
		ListenerEvent* removeEvent(ListenerEvent* e){
			Trio<int,bool,PrimitiveList<ListenerEvent>>* trio = ListenerEventMap_m->get(interrupt);
			if(trio == nullptr){
				return nullptr;
			}
			ListenerEvent* method = trio->bot->remove(e);
			return method;
		}
		
		ListenerEvent* removeEvent(int interrupt, ListenerEvent* e){
			Trio<int,bool,PrimitiveList<ListenerEvent>>* trio = ListenerEventMap_m->get(interrupt);
			if(trio == nullptr){
				return nullptr;
			}
			ListenerEvent* method = trio->bot->remove(e);
			return method;
		}
		
		void deleteEvent(int interrupt){
			ListenerEventMap_m->removeDelete(interrupt);
			//detachInterrupt(digitalPinToInterrupt(interrupt));
		}
		
	protected:
	Application* app = nullptr;
};

#endif 
