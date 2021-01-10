

#ifndef Listener_h
#define Listener_h

#define ListenerInput 0
#define ListenerDebounceInput 1
#define ListenerDebounceInterrupt 2
#define ListenerInterrupt 3
#define ListenerThreadInterrupt 4
#define ListenerOutput 5
#define ListenerOutputInterrupt 6
#define ListenerOutputEvent 7
#define ListenerInputEvent 8

class Application;
#include "Arduino.h"
#include "cppObject.h"
#include "ListenerEvent.h"
#include "PrimitiveList.h"

#ifdef ListenerLogApp
	#define ListenerLog(name,method,type,mns) Log(name,method,type,mns)
#else
	#define ListenerLog(name,method,type,mns)
#endif

static PrimitiveList<void (*)()>* ThreadMap_m = nullptr;
static PrimitiveList<void (*)(float)>* LoopMap_m = nullptr;
static PrimitiveList<void (*)()>* OutputMap_m = nullptr;

template<int interrupt>
struct IO_Set{
	static int m_pin;
	static int m_type;
	static bool m_state;
	static bool m_safe;
	static float m_time;
	static float m_timelimit;
	static PrimitiveList<ListenerEvent>* m_events;
	
};
template<int interrupt> int IO_Set<interrupt>::m_pin = -1;
template<int interrupt> int  IO_Set<interrupt>::m_type = -1;
template<int interrupt> bool  IO_Set<interrupt>::m_state = false;
template<int interrupt> bool  IO_Set<interrupt>::m_safe = false;
template<int interrupt> float  IO_Set<interrupt>::m_time = 0.0f;
template<int interrupt> float  IO_Set<interrupt>::m_timelimit = 0.1f;
template<int interrupt> PrimitiveList<ListenerEvent>*  IO_Set<interrupt>::m_events = nullptr;


template<int interrupt>
void Input(float tpc){
	ListenerLog("Listener", "Input",  "println", "");
	if(IO_Set<interrupt>::m_pin == -1){
		ListenerLog("Listener", "Input",  "println", "pin == -1");
		return;
	}
	IO_Set<interrupt>::m_state = digitalRead(IO_Set<interrupt>::m_pin);
	ListenerLog("Listener", "Input",  "println", String("pin: ") + String(IO_Set<interrupt>::m_pin));
	ListenerLog("Listener", "Input",  "println", String("state: ") + String(IO_Set<interrupt>::m_state));
}

template<int interrupt>
void DebounceInput(float tpc){
	ListenerLog("Listener", "DebounceInput",  "println", "");
	int pin = IO_Set<interrupt>::m_pin;
	IO_Set<interrupt>::m_time += tpc;
	if(pin == -1){
		ListenerLog("Listener", "DebounceInput",  "println", "pin == -1");
		return;
	}
	if(IO_Set<interrupt>::m_time < IO_Set<interrupt>::m_timelimit){
		ListenerLog("Listener", "DebounceInput",  "println", "IO_Set<interrupt>::m_time < IO_Set<interrupt>::m_timelimit");
		return;
	}
	bool state = digitalRead(pin);
	if(state == IO_Set<interrupt>::m_state){
		ListenerLog("Listener", "DebounceInput",  "println", "state == IO_Set<interrupt>::m_state");
		return;
	}
	IO_Set<interrupt>::m_time = 0.0f;
	IO_Set<interrupt>::m_state = state;
	ListenerLog("Listener", "DebounceInput",  "println", String("state: ") + String(IO_Set<interrupt>::m_state));
}

template<int interrupt>
void DebounceInterrupt(float tpc){
	ListenerLog("Listener", "DebounceInterrupt",  "println", "");
	int pin = IO_Set<interrupt>::m_pin;
	IO_Set<interrupt>::m_time += tpc;
	List<ListenerEvent>* events = IO_Set<interrupt>::m_events;
	if(pin == -1 || events == nullptr){
		ListenerLog("Listener", "DebounceInterrupt",  "println", "pin == -1 || events == nullptr");
		return;
	}
	if(IO_Set<interrupt>::m_time < IO_Set<interrupt>::m_timelimit){
		ListenerLog("Listener", "DebounceInterrupt",  "println", "IO_Set<interrupt>::m_time < IO_Set<interrupt>::m_timelimit");
		return;
	}
	bool state = digitalRead(pin);
	if(state == IO_Set<interrupt>::m_state){
		ListenerLog("Listener", "DebounceInterrupt",  "println", "state == IO_Set<interrupt>::m_state");
		return;
	}
	IO_Set<interrupt>::m_time = 0.0f;
	IO_Set<interrupt>::m_state = state;
	ListenerLog("Listener", "DebounceInterrupt",  "println", "start interrupt");
	for(int x = 0; x < events->getPosition(); x++){
		events->getByPosition(x)->event(interrupt, pin, state);
	}
	ListenerLog("Listener", "DebounceInterrupt",  "println", "end interrupt");
}

template<int interrupt>
void OutputInterrupt(){
	ListenerLog("Listener", "OutputInterrupt",  "println", "");
	int pin = IO_Set<interrupt>::m_pin;
	List<ListenerEvent>* events = IO_Set<interrupt>::m_events;
	if(pin == -1 || events == nullptr){
		ListenerLog("Listener", "OutputInterrupt",  "println", "pin == -1 || events == nullptr");
		return;
	}
	ListenerLog("Listener", "OutputInterrupt",  "println", "start interrupt");
	for(int x = 0; x < events->getPosition(); x++){
		events->getByPosition(x)->event(interrupt, pin, IO_Set<interrupt>::m_state);
	}
	ListenerLog("Listener", "OutputInterrupt",  "println", "end interrupt");
}

#ifdef ARDUINO_ARCH_ESP8266

template<int interrupt>
void ICACHE_RAM_ATTR Interrupt(){
	
#elif defined(ARDUINO_ARCH_SAM)

template<int interrupt>
void Interrupt(){
	
#elif defined(ARDUINO_ARCH_AVR)

template<int interrupt>
void Interrupt(){

#elif defined(ARDUINO_SAMD_ZERO)

template<int interrupt>
void Interrupt(){

#else

template<int interrupt>
void Interrupt(){
	
#endif
	ListenerLog("Listener", "Interrupt",  "println", "");
	int pin = IO_Set<interrupt>::m_pin;
	bool state = IO_Set<interrupt>::m_state;
	List<ListenerEvent>* events = IO_Set<interrupt>::m_events;
	if(pin == -1 || events == nullptr){
		ListenerLog("Listener", "Interrupt",  "println", "pin == -1 || events == nullptr");
		return;
	}
	IO_Set<interrupt>::m_state = !(state);
	ListenerLog("Listener", "Interrupt",  "println", "start interrupt");
	for(int x = 0; x < events->getPosition(); x++){
		events->getByPosition(x)->event(interrupt, pin, IO_Set<interrupt>::m_state);
	}
	ListenerLog("Listener", "Interrupt",  "println", "end interrupt");
}

#ifdef ARDUINO_ARCH_ESP8266

template<int interrupt>
void ICACHE_RAM_ATTR ThreadInterrupt(){
	
#elif defined(ARDUINO_ARCH_SAM)

template<int interrupt>
void ThreadInterrupt(){
	
#elif defined(ARDUINO_ARCH_AVR)

template<int interrupt>
void ThreadInterrupt(){

#elif defined(ARDUINO_SAMD_ZERO)

template<int interrupt>
void ThreadInterrupt(){

#else

template<int interrupt>
void ThreadInterrupt(){
	
#endif
	ListenerLog("Listener", "ThreadInterrupt",  "println", "");
	if(IO_Set<interrupt>::m_safe){
		ListenerLog("Listener", "ThreadInterrupt",  "println", "safe interrupt");
		Interrupt<interrupt>();
	}else{
		if(ThreadMap_m != nullptr){
			ListenerLog("Listener", "ThreadInterrupt",  "println", "adding unsafe interrupt");
			ThreadMap_m->addLValue(&Interrupt<interrupt>);
		}
	}
}

template<int interrupt>
void Interrupt(bool state){
	ListenerLog("Listener", "Interrupt",  "println", "with parameter");
	int pin = IO_Set<interrupt>::m_pin;
	List<ListenerEvent>* events = IO_Set<interrupt>::m_events;
	if(pin == -1 || events == nullptr){
		ListenerLog("Listener", "Interrupt",  "println", "pin == -1 || events == nullptr");
		return;
	}
	ListenerLog("Listener", "Interrupt",  "println", "start interrupt");
	for(int x = 0; x < events->getPosition(); x++){
		events->getByPosition(x)->event(interrupt, pin, state);
	}
	ListenerLog("Listener", "Interrupt",  "println", "end interrupt");
}

class Listener : public cppObject{
    public:
		typedef void (*Method)();
		Listener(){
			if(ThreadMap_m == nullptr){
				ThreadMap_m = new PrimitiveList<void (*)()>();
			}
			if(LoopMap_m == nullptr){
				LoopMap_m = new PrimitiveList<void (*)(float)>();
			}
			if(OutputMap_m == nullptr){
				OutputMap_m = new PrimitiveList<void (*)()>();
			}
		}
		virtual ~Listener(){
			if(ThreadMap_m != nullptr){
				delete ThreadMap_m;
			}
			if(LoopMap_m != nullptr){
				delete LoopMap_m;
			}
			if(OutputMap_m != nullptr){
				delete OutputMap_m;
			}
		}
		
		virtual void attach(Application* a){
			app = a;
		}
		virtual String getClassName(){return "Listener";}
		virtual bool instanceof(String name){return name == "Listener" || cppObject::instanceof(name);}
		
		template<int interrupt>
		void Secure(){
			IO_Set<interrupt>::m_safe = true;
		}
		
		template<int interrupt>
		void UnSecure(){
			IO_Set<interrupt>::m_safe = false;
		}
		virtual void InterruptEvent(float tpc){
			for(int x = 0; x < LoopMap_m->getPosition(); x++){
				(*LoopMap_m->getByPosition(x))(tpc);
			}
			for(int x = 0; x < ThreadMap_m->getPosition(); x++){
				(*ThreadMap_m->getByPosition(x))();
			}
			for(int x = 0; x < OutputMap_m->getPosition(); x++){
				(*OutputMap_m->getByPosition(x))();
			}
			OutputMap_m->resetDelete();
			ThreadMap_m->resetDelete();
		}
		
		template<int interrupt>
		void createInput(int pin, bool state){
			IO_Set<interrupt>::m_pin = pin;
			IO_Set<interrupt>::m_type = ListenerInput;
			IO_Set<interrupt>::m_state = state;
			IO_Set<interrupt>::m_safe = true;
			IO_Set<interrupt>::m_events = nullptr;
			pinMode(pin,INPUT);
			LoopMap_m->addLValue(&Input<interrupt>);
		}
		
		template<int interrupt>
		void createDebounceInput(float l, int pin, bool state){
			IO_Set<interrupt>::m_pin = pin;
			IO_Set<interrupt>::m_type = ListenerDebounceInput;
			IO_Set<interrupt>::m_state = state;
			IO_Set<interrupt>::m_timelimit = l;
			IO_Set<interrupt>::m_safe = true;
			IO_Set<interrupt>::m_events = nullptr;
			pinMode(pin,INPUT);
			LoopMap_m->addLValue(&DebounceInput<interrupt>);
		}
		
		template<int interrupt>
		void createDebounceInput(float l, int pin){
			createDebounceInput<interrupt>(l, pin, false);
		}
		
		template<int interrupt>
		void createDebounceInput(int pin){
			createDebounceInput<interrupt>(0.1f, pin, false);
		}
		
		template<int interrupt>
		void createDebounceInput(int pin, bool state){
			createDebounceInput<interrupt>(0.1f, pin, state);
		}
		
		template<int interrupt>
		void createDebounceInterrupt(float l, int pin, bool state, bool owner){
			IO_Set<interrupt>::m_pin = pin;
			IO_Set<interrupt>::m_type = ListenerDebounceInput;
			IO_Set<interrupt>::m_state = state;
			IO_Set<interrupt>::m_safe = true;
			IO_Set<interrupt>::m_timelimit = l;
			IO_Set<interrupt>::m_events = nullptr;
			if(IO_Set<interrupt>::m_events == nullptr){
				IO_Set<interrupt>::m_events = new PrimitiveList<ListenerEvent>(owner);
			}
			pinMode(pin,INPUT);
			LoopMap_m->addLValue(&DebounceInterrupt<interrupt>);
		}
		
		template<int interrupt>
		void createDebounceInterrupt(float l, int pin){
			createDebounceInterrupt<interrupt>(l, pin, false, true);
		}
		
		template<int interrupt>
		void createDebounceInterrupt(int pin){
			createDebounceInterrupt<interrupt>(0.1f, pin, false, true);
		}
		
		template<int interrupt>
		void createDebounceInterrupt(int pin, bool state){
			createDebounceInterrupt<interrupt>(0.1f, pin, state, true);
		}
		
		template<int interrupt>
		void createDebounceInterrupt(float l, int pin, bool state){
			createDebounceInterrupt<interrupt>(l, pin, state, true);
		}
		
		template<int interrupt>
		void createInterrupt(int pin, bool state, bool owner){
			IO_Set<interrupt>::m_pin = pin;
			IO_Set<interrupt>::m_type = ListenerInterrupt;
			IO_Set<interrupt>::m_state = state;
			IO_Set<interrupt>::m_safe = true;
			if(IO_Set<interrupt>::m_events == nullptr){
				IO_Set<interrupt>::m_events = new PrimitiveList<ListenerEvent>(owner);
			}
			pinMode(pin,INPUT_PULLUP);
			attachInterrupt(digitalPinToInterrupt(pin), Interrupt<interrupt>, CHANGE);
		}
		
		template<int interrupt>
		void createInterrupt(int pin, bool state){
			createInterrupt<interrupt>(pin, state, true);
		}
		
		template<int interrupt>
		void createThreadInterrupt(int pin, bool state, bool owner){
			IO_Set<interrupt>::m_pin = pin;
			IO_Set<interrupt>::m_type = ListenerThreadInterrupt;
			IO_Set<interrupt>::m_state = state;
			IO_Set<interrupt>::m_safe = true;
			if(IO_Set<interrupt>::m_events == nullptr){
				IO_Set<interrupt>::m_events = new PrimitiveList<ListenerEvent>(owner);
			}
			pinMode(pin,INPUT);
			attachInterrupt(digitalPinToInterrupt(pin), ThreadInterrupt<interrupt>, CHANGE);
		}
		
		template<int interrupt>
		void createThreadInterrupt(int pin, bool state){
			createThreadInterrupt<interrupt>(pin, state, true);
		}
		
		template<int interrupt>
		void createOutput(int pin, bool state){
			IO_Set<interrupt>::m_pin = pin;
			IO_Set<interrupt>::m_type = ListenerOutput;
			IO_Set<interrupt>::m_state = state;
			IO_Set<interrupt>::m_safe = true;
			IO_Set<interrupt>::m_events = nullptr;
			pinMode(pin,OUTPUT);
		}
		
		template<int interrupt>
		void createOutput(int pin){
			createOutput<interrupt>(pin, false);
		}
		
		template<int interrupt>
		void createOutputInterrupt(int pin){
			createOutputInterrupt<interrupt>(pin, false, true);
		}
		
		template<int interrupt>
		void createOutputInterrupt(int pin, bool state){
			createOutputInterrupt<interrupt>(pin, state, true);
		}
		
		template<int interrupt>
		void createOutputInterrupt(int pin, bool state, bool owner){
			IO_Set<interrupt>::m_pin = pin;
			IO_Set<interrupt>::m_type = ListenerOutputInterrupt;
			IO_Set<interrupt>::m_state = state;
			IO_Set<interrupt>::m_safe = true;
			if(IO_Set<interrupt>::m_events == nullptr){
				IO_Set<interrupt>::m_events = new PrimitiveList<ListenerEvent>(owner);
			}
			pinMode(pin,OUTPUT);
		}
		
		template<int interrupt>
		void createOutputEvent(int pin, bool state, bool owner){
			IO_Set<interrupt>::m_pin = pin;
			IO_Set<interrupt>::m_type = ListenerOutputEvent;
			IO_Set<interrupt>::m_state = state;
			IO_Set<interrupt>::m_safe = true;
			if(IO_Set<interrupt>::m_events == nullptr){
				IO_Set<interrupt>::m_events = new PrimitiveList<ListenerEvent>(owner);
			}
			pinMode(pin,OUTPUT);
		}
		
		template<int interrupt>
		void createOutputEvent(int pin, bool state){
			createOutputEvent<interrupt>(pin, state, true);
		}
		
		template<int interrupt>
		int Type(){
			return IO_Set<interrupt>::m_type;
		}
		
		template<int interrupt>
		int Pin(){
			return IO_Set<interrupt>::m_pin;
		}
		
		template<int interrupt>
		void setPin(int pin){
			if(IO_Set<interrupt>::m_type == -1){
				return;
			}
			if(IO_Set<interrupt>::m_type == ListenerInput){
				pinMode(pin,INPUT);
			}
			if(IO_Set<interrupt>::m_type == ListenerInputEvent){
				pinMode(pin,INPUT);
			}
			if(IO_Set<interrupt>::m_type == ListenerDebounceInput){
				pinMode(pin,INPUT);
			}
			if(IO_Set<interrupt>::m_type == ListenerDebounceInterrupt){
				pinMode(pin,INPUT);
			}
			if(IO_Set<interrupt>::m_type == ListenerInterrupt){
				pinMode(pin,INPUT);
				attachInterrupt(digitalPinToInterrupt(pin), Interrupt<interrupt>, CHANGE);
			}
			if(IO_Set<interrupt>::m_type == ListenerThreadInterrupt){
				pinMode(pin,INPUT);
				attachInterrupt(digitalPinToInterrupt(pin), ThreadInterrupt<interrupt>, CHANGE);
			}
			if(IO_Set<interrupt>::m_type == ListenerOutput){
				pinMode(pin,OUTPUT);
			}
			if(IO_Set<interrupt>::m_type == ListenerOutputInterrupt){
				pinMode(pin,OUTPUT);
			}
			if(IO_Set<interrupt>::m_type == ListenerOutputEvent){
				pinMode(pin,OUTPUT);
			}
			IO_Set<interrupt>::m_pin = pin;
		}
		
		template<int interrupt>
		void setTimeLimit(float t){
			IO_Set<interrupt>::m_timelimit = t;
		}
		
		template<int interrupt>
		int TimeLimit(){
			return IO_Set<interrupt>::m_timelimit;
		}
		
		template<int interrupt>
		bool PinState(){
			return IO_Set<interrupt>::m_state;
		}
		
		template<int interrupt>
		void setPinState(bool state){
			IO_Set<interrupt>::m_state = state;
			if(IO_Set<interrupt>::m_type == ListenerOutput){
				digitalWrite(IO_Set<interrupt>::m_pin, state);
			}
			if(IO_Set<interrupt>::m_type == ListenerOutputInterrupt){
				digitalWrite(IO_Set<interrupt>::m_pin, state);
				OutputMap_m->addLValue(&OutputInterrupt<interrupt>);
			}
			if(IO_Set<interrupt>::m_type == ListenerOutputEvent){
				digitalWrite(IO_Set<interrupt>::m_pin, state);
				OutputInterrupt<interrupt>();
			}
		}
		
		template<int interrupt>
		bool PinSafe(){
			return IO_Set<interrupt>::m_safe;
		}
		
		template<int interrupt>
		void addEvent(ListenerEvent* e, bool owner){
			if(IO_Set<interrupt>::m_events == nullptr){
				IO_Set<interrupt>::m_events = new PrimitiveList<ListenerEvent>(owner);
			}
			IO_Set<interrupt>::m_events->addPointer(e);
		}
		
		template<int interrupt>
		void addEvent(ListenerEvent* e){
			if(IO_Set<interrupt>::m_events == nullptr){
				IO_Set<interrupt>::m_events = new PrimitiveList<ListenerEvent>();
			}
			IO_Set<interrupt>::m_events->addPointer(e);
		}
		
		template<int interrupt>
		bool containEvent(ListenerEvent* e){
			if(IO_Set<interrupt>::m_events == nullptr){
				return false;
			}
			return IO_Set<interrupt>::m_events->containByPointer(e);
		}
		
		template<int interrupt>
		ListenerEvent* removeEvent(ListenerEvent* e){
			if(IO_Set<interrupt>::m_events == nullptr){
				return nullptr;
			}
			return IO_Set<interrupt>::m_events->removeByPointer(e);
		}
		
		template<int interrupt>
		void deleteEvent(ListenerEvent* e){
			if(IO_Set<interrupt>::m_events == nullptr){
				return;
			}
			IO_Set<interrupt>::m_events->removeDeleteByPointer(e);
		}
		
	protected:
	Application* app = nullptr;
};

#endif 
