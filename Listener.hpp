

#ifndef Listener_hpp
#define Listener_hpp

#define ListenerInput 0
#define ListenerDebounceInput 1
#define ListenerDebounceInterrupt 2
#define ListenerDebounceInterruptEvent 3
#define ListenerDebounceInterruptClassEvent 4
#define ListenerDebounceLoopInterrupt 5
#define ListenerInterrupt 6
#define ListenerThreadInterrupt 7
#define ListenerOutput 8
#define ListenerOutputInterrupt 9
#define ListenerOutputEvent 10
#define ListenerInputEvent 11
#define ListenerDebounceMultiInterruptEvent 12
#define ListenerDebounceMultiMultiInterruptEvent 13
#define ListenerDebounceMultiMultiInterruptEvent_v2 14
#define ListenerDebounceMultiMultiInterruptEvent_v3 15
#define ListenerAnalogInput 15

#ifndef ame_Enviroment_Defined
	#include "Arduino.h"
#endif

#ifdef ame_Windows

#endif

#ifdef ame_ArduinoIDE
	#include "Arduino.h"
#endif

#include "cppObject.hpp"
#include "ListenerEvent.hpp"
#include "ListenerAnalogEvent.hpp"
#include "PrimitiveList.hpp"
#include "PrimitiveMap.hpp"
#include "MonkeyExporter.hpp"
#include "MonkeyImporter.hpp"

#ifdef ListenerLogApp
	#include "Logger.hpp"
	#define ListenerLog(name,method,type,mns) Log(name,method,type,mns)
#else
	#define ListenerLog(name,method,type,mns)
#endif

namespace ame{
using EventMethod = void (*)(int,long,bool);
using AnalogMethod = void (*)(int,float,float);

void empty(int i,long l,bool b){
	
}
void analog_empty(int i,float value,float tpc){
	
}

class Application;

static PrimitiveList<void (*)()>* ThreadMap_m = nullptr;
static PrimitiveList<void (*)(float)>* LoopMap_m = nullptr;
static PrimitiveList<void (*)()>* OutputMap_m = nullptr;

template<int interrupt>
struct Analog_Vars{
	static int m_type;
	static bool m_value;
};

template<int interrupt>
struct IO_Vars{
	static int m_type;
	static bool m_state;
	static bool m_inverted;
	static bool m_safe;
};

template<int interrupt>
struct IO_Output_State{
	static bool* m_state;
};

template<int interrupt>
struct IO_Output_Value{
	static PrimitiveMap<String,bool>* m_output_values;
};

template<int interrupt>
struct IO_Multi_State{
	static bool m_state;
};

template<int interrupt>
struct IO_Pin{
	static int m_pin;
};

template<int interrupt>
struct IO_Millis{
	static long m_millis;
};

template<int interrupt>
struct IO_Long_Times{
	static long m_time;
	static long m_timelimit;
};

template<int interrupt>
struct IO_Float_Times{
	static float m_time;
	static float m_timelimit;
};

template<int interrupt>
struct IO_Event{
	static PrimitiveList<EventMethod>* m_events;
};

template<int interrupt>
struct IO_Single_Event{
	static EventMethod m_event;
};

template<int interrupt>
struct IO_Multi_Event{
	static PrimitiveList<EventMethod>* m_events;
};

template<int interrupt>
struct IO_Single_Multi_Event{
	static EventMethod m_event;
};

template<int interrupt>
struct IO_Named_Event{
	static PrimitiveMap<String,EventMethod>* m_events;
};

template<int interrupt>
struct IO_ClassEvent{
	static PrimitiveList<ListenerEvent>* m_events;
};

template<int interrupt>
struct IO_Single_ClassEvent{
	static ListenerEvent* m_event;
};

template<int interrupt>
struct IO_Multi_ClassEvent{
	static PrimitiveList<ListenerEvent>* m_events;
};

template<int interrupt>
struct IO_Single_Multi_ClassEvent{
	static ListenerEvent* m_event;
};

template<int interrupt>
struct IO_Named_ClassEvent{
	static PrimitiveMap<String,ListenerEvent>* m_events;
};

template<int interrupt>
struct IO_AnalogEvent{
	static PrimitiveList<AnalogMethod>* m_events;
};

template<int interrupt>
struct IO_AnalogClassEvent{
	static PrimitiveList<ListenerAnalogEvent>* m_events;
};

template<int interrupt>
struct IO_Single_AnalogEvent{
	static AnalogMethod m_event;
};

template<int interrupt>
struct IO_Single_AnalogClassEvent{
	static ListenerAnalogEvent* m_event;
};

template<int interrupt> int   Analog_Vars<interrupt>::m_type = -1;
template<int interrupt> bool  Analog_Vars<interrupt>::m_value = 0.0f;

template<int interrupt> int   IO_Vars<interrupt>::m_type = -1;
template<int interrupt> bool  IO_Vars<interrupt>::m_state = false;
template<int interrupt> bool  IO_Vars<interrupt>::m_inverted = false;
template<int interrupt> bool  IO_Vars<interrupt>::m_safe = false;

template<int interrupt> bool* IO_Output_State<interrupt>::m_state = nullptr;
template<int interrupt> PrimitiveMap<String,bool>* IO_Output_Value<interrupt>::m_output_values = nullptr;

template<int interrupt> bool IO_Multi_State<interrupt>::m_state = false;

template<int interrupt> int IO_Pin<interrupt>::m_pin = -1;

template<int interrupt> long IO_Millis<interrupt>::m_millis = 0;

template<int interrupt> long IO_Long_Times<interrupt>::m_time = 0;
template<int interrupt> long IO_Long_Times<interrupt>::m_timelimit = 0;

template<int interrupt> float IO_Float_Times<interrupt>::m_time = 0.0f;
template<int interrupt> float  IO_Float_Times<interrupt>::m_timelimit = 0.1f;

template<int interrupt> PrimitiveList<EventMethod>* IO_Event<interrupt>::m_events = nullptr;

template<int interrupt> EventMethod IO_Single_Event<interrupt>::m_event = empty;

template<int interrupt> PrimitiveList<EventMethod>* IO_Multi_Event<interrupt>::m_events = nullptr;

template<int interrupt> EventMethod IO_Single_Multi_Event<interrupt>::m_event = empty;

template<int interrupt> PrimitiveMap<String,EventMethod>* IO_Named_Event<interrupt>::m_events = nullptr;

template<int interrupt> PrimitiveList<ListenerEvent>* IO_ClassEvent<interrupt>::m_events = nullptr;

template<int interrupt> ListenerEvent* IO_Single_ClassEvent<interrupt>::m_event = nullptr;

template<int interrupt> PrimitiveList<ListenerEvent>* IO_Multi_ClassEvent<interrupt>::m_events = nullptr;

template<int interrupt> ListenerEvent* IO_Single_Multi_ClassEvent<interrupt>::m_event = nullptr;

template<int interrupt> PrimitiveMap<String,ListenerEvent>* IO_Named_ClassEvent<interrupt>::m_events = nullptr;

template<int interrupt> PrimitiveList<AnalogMethod>* IO_AnalogEvent<interrupt>::m_events = nullptr;

template<int interrupt> PrimitiveList<ListenerAnalogEvent>* IO_AnalogClassEvent<interrupt>::m_events = nullptr;

template<int interrupt> AnalogMethod IO_Single_AnalogEvent<interrupt>::m_event = analog_empty;

template<int interrupt> ListenerAnalogEvent* IO_Single_AnalogClassEvent<interrupt>::m_event = nullptr;



template<int interrupt>
void AnalogInput(float tpc){
	int pin = IO_Pin<interrupt>::m_pin;
	List<AnalogMethod>* static_events = IO_AnalogEvent<interrupt>::m_events;
	List<ListenerAnalogEvent>* events = IO_AnalogClassEvent<interrupt>::m_events;
	if(pin == -1 || events == nullptr ||  static_events == nullptr){
		ListenerLog("Listener", "AnalogInput",  "println", "pin == -1");
		return;
	}
	Analog_Vars<interrupt>::m_value = analogRead(pin);
	ListenerLog("Listener", "AnalogInput",  "println", "start interrupt");
	for(int x = 0; x < static_events->getPosition(); x++){
		EventMethod event =  *static_events->getByPosition(x);
		event(interrupt, Analog_Vars<interrupt>::m_value, tpc);
	}
	for(int x = 0; x < events->getPosition(); x++){
		ListenerEvent* e =  events->getByPosition(x);
		e->event(interrupt, Analog_Vars<interrupt>::m_value, tpc);
	}
	ListenerLog("Listener", "AnalogInput",  "println", "end interrupt");
}

template<int interrupt>
void Input(float tpc){
	IO_Millis<interrupt>::m_millis = millis();
	ListenerLog("Listener", "Input",  "println", "");
	if(IO_Pin<interrupt>::m_pin == -1){
		ListenerLog("Listener", "Input",  "println", "pin == -1");
		return;
	}
	IO_Vars<interrupt>::m_state = digitalRead(IO_Pin<interrupt>::m_pin);
	ListenerLog("Listener", "Input",  "println", String("pin: ") + String(IO_Pin<interrupt>::m_pin));
	ListenerLog("Listener", "Input",  "println", String("state: ") + String(IO_Vars<interrupt>::m_state));
}

template<int interrupt>
void DebounceInput(float tpc){
	IO_Millis<interrupt>::m_millis = millis();
	ListenerLog("Listener", "DebounceInput",  "println", "");
	int pin = IO_Pin<interrupt>::m_pin;
	if(pin == -1){
		ListenerLog("Listener", "DebounceInput",  "println", "pin == -1");
		return;
	}
	bool state = digitalRead(pin);
	if(state == IO_Vars<interrupt>::m_state){
		ListenerLog("Listener", "DebounceInput",  "println", "state == IO_Vars<interrupt>::m_state");
		IO_Float_Times<interrupt>::m_time = 0.0f;
		return;
	}
	IO_Float_Times<interrupt>::m_time += tpc;
	if(IO_Float_Times<interrupt>::m_time < IO_Float_Times<interrupt>::m_timelimit){
		ListenerLog("Listener", "DebounceInput",  "println", "m_time < m_timelimit");
		return;
	}
	IO_Float_Times<interrupt>::m_time = 0.0f;
	IO_Vars<interrupt>::m_state = state;
	ListenerLog("Listener", "DebounceInput",  "println", String("state: ") + String(IO_Vars<interrupt>::m_state));
}

template<int interrupt>
void DebounceInterrupt_Event(){
	IO_Millis<interrupt>::m_millis = millis();
	ListenerLog("Listener", "DebounceInterrupt_Event",  "println", "");
	int pin = IO_Pin<interrupt>::m_pin;
	List<EventMethod>* static_events = IO_Event<interrupt>::m_events;
	if(pin == -1 || static_events == nullptr){
		ListenerLog("Listener", "DebounceInterrupt_Event",  "println", "pin == -1 || static_events == nullptr");
		return;
	}
	bool state = digitalRead(pin);
	if(state == IO_Vars<interrupt>::m_state){
		ListenerLog("Listener", "DebounceInterrupt_Event",  "println", "state == IO_Vars<interrupt>::m_state");
		return;
	}
	if( (millis() - IO_Long_Times<interrupt>::m_time) < IO_Long_Times<interrupt>::m_timelimit){
		ListenerLog("Listener", "DebounceInterrupt_Event",  "println", "time less then the limit");
		return;
	}
	IO_Long_Times<interrupt>::m_time = millis();
	IO_Vars<interrupt>::m_state = state;
	ListenerLog("Listener", "DebounceInterrupt_Event",  "println", "start interrupt");
	for(int x = 0; x < static_events->getPosition(); x++){
		EventMethod event =  *static_events->getByPosition(x);
		if(IO_Vars<interrupt>::m_inverted){
			event(interrupt, IO_Millis<interrupt>::m_millis, !IO_Vars<interrupt>::m_state);
		}else{
			event(interrupt, IO_Millis<interrupt>::m_millis, IO_Vars<interrupt>::m_state);
		}
	}
	ListenerLog("Listener", "DebounceInterrupt_Event",  "println", "end interrupt");
}

template<int interrupt>
void DebounceInterrupt_ClassEvent(){
	IO_Millis<interrupt>::m_millis = millis();
	ListenerLog("Listener", "DebounceInterrupt_ClassEvent",  "println", "");
	int pin = IO_Pin<interrupt>::m_pin;
	List<ListenerEvent>* events = IO_ClassEvent<interrupt>::m_events;
	if(pin == -1 || events == nullptr){
		ListenerLog("Listener", "DebounceInterrupt_ClassEvent",  "println", "pin == -1 || events == nullptr");
		return;
	}
	bool state = digitalRead(pin);
	if(state == IO_Vars<interrupt>::m_state){
		ListenerLog("Listener", "DebounceInterrupt_ClassEvent",  "println", "state == IO_Vars<interrupt>::m_state");
		return;
	}
	if( (millis() - IO_Long_Times<interrupt>::m_time) < IO_Long_Times<interrupt>::m_timelimit){
		ListenerLog("Listener", "DebounceInterrupt_ClassEvent",  "println", "time less then the limit");
		return;
	}
	IO_Long_Times<interrupt>::m_time = millis();
	IO_Vars<interrupt>::m_state = state;
	ListenerLog("Listener", "DebounceInterrupt_ClassEvent",  "println", "start interrupt");
	for(int x = 0; x < events->getPosition(); x++){
		ListenerEvent* e =  events->getByPosition(x);
		if(!e->isEnable()){
			continue;
		}
		if(IO_Vars<interrupt>::m_inverted){
			e->event(interrupt, IO_Millis<interrupt>::m_millis, !IO_Vars<interrupt>::m_state);
		}else{
			e->event(interrupt, IO_Millis<interrupt>::m_millis, IO_Vars<interrupt>::m_state);
		}
	}
	ListenerLog("Listener", "DebounceInterrupt_ClassEvent",  "println", "end interrupt");
}

template<int interrupt>
bool StatesChecker(bool state){
	return state == IO_Vars<interrupt>::m_state;
}

template<int interrupt, int interrupt_2, int... interrupts>
bool StatesChecker(bool state){
	return IO_Vars<interrupt>::m_state == state && StatesChecker<interrupt_2,interrupts...>(state);
}

template<int interrupt, int multiInterrupt, int... interrupts>
void DebounceMultiInterrupt(){
	IO_Millis<interrupt>::m_millis = millis();
	ListenerLog("Listener", "DebounceMultiInterrupt",  "println", "");
	int pin = IO_Pin<interrupt>::m_pin;
	List<ListenerEvent>* events = IO_ClassEvent<interrupt>::m_events;
	List<EventMethod>* static_events = IO_Event<interrupt>::m_events;
	if(pin == -1 || events == nullptr || static_events == nullptr){
		ListenerLog("Listener", "DebounceMultiInterrupt",  "println", "pin == -1 || events == nullptr || static_events == nullptr");
		return;
	}
	bool state = digitalRead(pin);
	if(state == IO_Vars<interrupt>::m_state){
		ListenerLog("Listener", "DebounceMultiInterrupt",  "println", "state == IO_Vars<interrupt>::m_state");
		return;
	}
	if( (millis() - IO_Long_Times<interrupt>::m_time) < IO_Long_Times<interrupt>::m_timelimit){
		ListenerLog("Listener", "DebounceMultiInterrupt",  "println", "time less then the limit");
		return;
	}
	IO_Long_Times<interrupt>::m_time = millis();
	IO_Vars<interrupt>::m_state = state;
	ListenerLog("Listener", "DebounceMultiInterrupt",  "println", "start interrupt");
	for(int x = 0; x < static_events->getPosition(); x++){
		EventMethod event =  *static_events->getByPosition(x);
		if(IO_Vars<interrupt>::m_inverted){
			event(interrupt, IO_Millis<interrupt>::m_millis, !IO_Vars<interrupt>::m_state);
		}else{
			event(interrupt, IO_Millis<interrupt>::m_millis, IO_Vars<interrupt>::m_state);
		}
	}
	for(int x = 0; x < events->getPosition(); x++){
		ListenerEvent* e =  events->getByPosition(x);
		if(!e->isEnable()){
			continue;
		}
		if(IO_Vars<interrupt>::m_inverted){
			e->event(interrupt, IO_Millis<interrupt>::m_millis, !IO_Vars<interrupt>::m_state);
		}else{
			e->event(interrupt, IO_Millis<interrupt>::m_millis, IO_Vars<interrupt>::m_state);
		}
	}
	//// end part 1
	List<ListenerEvent>* multi_events = IO_Multi_ClassEvent<interrupt>::m_events;
	List<EventMethod>* multi_static_events = IO_Multi_Event<interrupt>::m_events;
	if(multi_static_events == nullptr || multi_events == nullptr){
		ListenerLog("Listener", "DebounceMultiInterrupt",  "println", "multi_static_events == nullptr || multi_events == nullptr");
		return;
	}
	if(!StatesChecker<interrupt,interrupts...>(state)){
		return;
	}
	if(state == IO_Multi_State<multiInterrupt>::m_state){
		ListenerLog("Listener", "DebounceMultiInterrupt",  "println", "state == IO_Vars<interrupt>::m_state");
		return;
	}
	IO_Multi_State<multiInterrupt>::m_state = state;
	for(int x = 0; x < multi_static_events->getPosition(); x++){
		EventMethod event =  *multi_static_events->getByPosition(x);
		if(IO_Vars<interrupt>::m_inverted){
			event(interrupt, IO_Millis<interrupt>::m_millis, !IO_Vars<interrupt>::m_state);
		}else{
			event(interrupt, IO_Millis<interrupt>::m_millis, IO_Vars<interrupt>::m_state);
		}
	}
	for(int x = 0; x < multi_events->getPosition(); x++){
		ListenerEvent* e =  multi_events->getByPosition(x);
		if(!e->isEnable()){
			continue;
		}
		if(IO_Vars<interrupt>::m_inverted){
			e->event(interrupt, IO_Millis<interrupt>::m_millis, !IO_Vars<interrupt>::m_state);
		}else{
			e->event(interrupt, IO_Millis<interrupt>::m_millis, IO_Vars<interrupt>::m_state);
		}
	}
	ListenerLog("Listener", "DebounceMultiInterrupt",  "println", "end interrupt");
}

template<int interrupt, int multiInterrupt, int... interrupts>
void SingleDebounceMultiInterrupt(){
	IO_Millis<interrupt>::m_millis = millis();
	ListenerLog("Listener", "DebounceMultiInterrupt",  "println", "");
	int pin = IO_Pin<interrupt>::m_pin;
	EventMethod static_events = IO_Single_Event<interrupt>::m_event;
	if(pin == -1){
		ListenerLog("Listener", "SingleDebounceMultiInterrupt",  "println", "pin == -1 || events == nullptr || static_events == nullptr");
		return;
	}
	bool state = digitalRead(pin);
	if(state == IO_Vars<interrupt>::m_state){
		ListenerLog("Listener", "SingleDebounceMultiInterrupt",  "println", "state == IO_Vars<interrupt>::m_state");
		return;
	}
	if( (millis() - IO_Long_Times<interrupt>::m_time) < IO_Long_Times<interrupt>::m_timelimit){
		ListenerLog("Listener", "SingleDebounceMultiInterrupt",  "println", "time less then the limit");
		return;
	}
	IO_Long_Times<interrupt>::m_time = millis();
	IO_Vars<interrupt>::m_state = state;
	ListenerLog("Listener", "SingleDebounceMultiInterrupt",  "println", "start interrupt");
	if(IO_Vars<interrupt>::m_inverted){
		static_events(interrupt, IO_Millis<interrupt>::m_millis, !state);
	}else{
		static_events(interrupt, IO_Millis<interrupt>::m_millis, state);
	}
	//// end part 1
	EventMethod static_events_multi = IO_Single_Multi_Event<interrupt>::m_event;
	if(!StatesChecker<interrupt,interrupts...>(state)){
		return;
	}
	if(state == IO_Multi_State<multiInterrupt>::m_state){
		ListenerLog("Listener", "SingleDebounceMultiInterrupt",  "println", "state == IO_Vars<interrupt>::m_state");
		return;
	}
	IO_Multi_State<multiInterrupt>::m_state = state;
	if(IO_Vars<interrupt>::m_inverted){
		static_events_multi(interrupt, IO_Millis<interrupt>::m_millis, !state);
	}else{
		static_events_multi(interrupt, IO_Millis<interrupt>::m_millis, state);
	}
	ListenerLog("Listener", "SingleDebounceMultiInterrupt",  "println", "end interrupt");
}

template<int interrupt>
void DebounceInterrupt(){
	IO_Millis<interrupt>::m_millis = millis();
	ListenerLog("Listener", "DebounceInterrupt",  "println", "");
	int pin = IO_Pin<interrupt>::m_pin;
	List<ListenerEvent>* events = IO_ClassEvent<interrupt>::m_events;
	List<EventMethod>* static_events = IO_Event<interrupt>::m_events;
	if(pin == -1 || events == nullptr || static_events == nullptr){
		ListenerLog("Listener", "DebounceInterrupt",  "println", "pin == -1 || events == nullptr || static_events == nullptr");
		return;
	}
	bool state = digitalRead(pin);
	if(state == IO_Vars<interrupt>::m_state){
		ListenerLog("Listener", "DebounceInterrupt",  "println", "state == IO_Vars<interrupt>::m_state");
		return;
	}
	if( (millis() - IO_Long_Times<interrupt>::m_time) < IO_Long_Times<interrupt>::m_timelimit){
		ListenerLog("Listener", "DebounceInterrupt",  "println", "time less then the limit");
		return;
	}
	IO_Long_Times<interrupt>::m_time = millis();
	IO_Vars<interrupt>::m_state = state;
	ListenerLog("Listener", "DebounceInterrupt",  "println", "start interrupt");
	for(int x = 0; x < static_events->getPosition(); x++){
		EventMethod event =  *static_events->getByPosition(x);
		if(IO_Vars<interrupt>::m_inverted){
			event(interrupt, IO_Millis<interrupt>::m_millis, !IO_Vars<interrupt>::m_state);
		}else{
			event(interrupt, IO_Millis<interrupt>::m_millis, IO_Vars<interrupt>::m_state);
		}
	}
	for(int x = 0; x < events->getPosition(); x++){
		ListenerEvent* e =  events->getByPosition(x);
		if(!e->isEnable()){
			continue;
		}
		if(IO_Vars<interrupt>::m_inverted){
			e->event(interrupt, IO_Millis<interrupt>::m_millis, !IO_Vars<interrupt>::m_state);
		}else{
			e->event(interrupt, IO_Millis<interrupt>::m_millis, IO_Vars<interrupt>::m_state);
		}
	}
	ListenerLog("Listener", "DebounceInterrupt",  "println", "end interrupt");
}

template<int interrupt>
void DebounceLoopInterrupt(float tpc){
	IO_Millis<interrupt>::m_millis = millis();
	// ListenerLog("Listener", "DebounceLoopInterrupt",  "println", "");
	int pin = IO_Pin<interrupt>::m_pin;
	List<ListenerEvent>* events = IO_ClassEvent<interrupt>::m_events;
	List<EventMethod>* static_events = IO_Event<interrupt>::m_events;
	if(pin == -1 || events == nullptr || static_events == nullptr){
		ListenerLog("Listener", "DebounceLoopInterrupt",  "println", "pin == -1 || events == nullptr || static_events == nullptr");
		return;
	}
	bool state = digitalRead(pin);
	if(state == IO_Vars<interrupt>::m_state){
		// ListenerLog("Listener", "DebounceLoopInterrupt",  "println", "state == IO_Vars<interrupt>::m_state");
		return;
	}
	IO_Float_Times<interrupt>::m_time += tpc;
	if(IO_Float_Times<interrupt>::m_time < IO_Float_Times<interrupt>::m_timelimit){
		ListenerLog("Listener", "DebounceLoopInterrupt",  "println", "m_time < m_timelimit");
		ListenerLog("Listener", "DebounceLoopInterrupt",  "println", String("m_time ") + String(IO_Float_Times<interrupt>::m_time));
		ListenerLog("Listener", "DebounceLoopInterrupt",  "println", String("m_timelimit ") + String(IO_Float_Times<interrupt>::m_timelimit));
		ListenerLog("Listener", "DebounceLoopInterrupt",  "println", String("tpc ") + String(tpc));
		return;
	}
	IO_Float_Times<interrupt>::m_time = 0.0f;
	IO_Vars<interrupt>::m_state = state;
	ListenerLog("Listener", "DebounceLoopInterrupt",  "println", "start interrupt");
	for(int x = 0; x < static_events->getPosition(); x++){
		EventMethod event =  *static_events->getByPosition(x);
		if(IO_Vars<interrupt>::m_inverted){
			event(interrupt, IO_Millis<interrupt>::m_millis, !IO_Vars<interrupt>::m_state);
		}else{
			event(interrupt, IO_Millis<interrupt>::m_millis, IO_Vars<interrupt>::m_state);
		}
	}
	for(int x = 0; x < events->getPosition(); x++){
		ListenerEvent* e =  events->getByPosition(x);
		if(!e->isEnable()){
			continue;
		}
		if(IO_Vars<interrupt>::m_inverted){
			e->event(interrupt, IO_Millis<interrupt>::m_millis, !IO_Vars<interrupt>::m_state);
		}else{
			e->event(interrupt, IO_Millis<interrupt>::m_millis, IO_Vars<interrupt>::m_state);
		}
	}
	ListenerLog("Listener", "DebounceLoopInterrupt",  "println", "end interrupt");
}

template<int interrupt>
void OutputInterrupt(float tpc){
	IO_Millis<interrupt>::m_millis = millis();
	// ListenerLog("Listener", "OutputInterrupt",  "println", "");
	int pin = IO_Pin<interrupt>::m_pin;
	List<ListenerEvent>* events = IO_ClassEvent<interrupt>::m_events;
	List<EventMethod>* static_events = IO_Event<interrupt>::m_events;
	if(pin == -1 || events == nullptr || static_events == nullptr){
		ListenerLog("Listener", "OutputInterrupt",  "println", "pin == -1 || events == nullptr || static_events == nullptr");
		return;
	}
	if(IO_Output_State<interrupt>::m_state == nullptr){
		return;
	}
	if(IO_Vars<interrupt>::m_state == *IO_Output_State<interrupt>::m_state){
		return;
	}
	IO_Vars<interrupt>::m_state = *IO_Output_State<interrupt>::m_state;
	digitalWrite(pin, IO_Vars<interrupt>::m_state);
	ListenerLog("Listener", "OutputInterrupt",  "println", "start interrupt");
	for(int x = 0; x < static_events->getPosition(); x++){
		EventMethod event =  *static_events->getByPosition(x);
		if(IO_Vars<interrupt>::m_inverted){
			event(interrupt, IO_Millis<interrupt>::m_millis, !IO_Vars<interrupt>::m_state);
		}else{
			event(interrupt, IO_Millis<interrupt>::m_millis, IO_Vars<interrupt>::m_state);
		}
	}
	for(int x = 0; x < events->getPosition(); x++){
		ListenerEvent* e =  events->getByPosition(x);
		if(IO_Vars<interrupt>::m_inverted){
			e->event(interrupt, IO_Millis<interrupt>::m_millis, !IO_Vars<interrupt>::m_state);
		}else{
			e->event(interrupt, IO_Millis<interrupt>::m_millis, IO_Vars<interrupt>::m_state);
		}
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
	IO_Millis<interrupt>::m_millis = millis();
	using EventMethod = void (*)(int,long,bool);
	ListenerLog("Listener", "Interrupt",  "println", "");
	int pin = IO_Pin<interrupt>::m_pin;
	bool state = IO_Vars<interrupt>::m_state;
	List<ListenerEvent>* events = IO_ClassEvent<interrupt>::m_events;
	List<EventMethod>* static_events = IO_Event<interrupt>::m_events;
	if(pin == -1 || events == nullptr || static_events == nullptr){
		ListenerLog("Listener", "Interrupt",  "println", "pin == -1 || events == nullptr || static_events == nullptr");
		return;
	}
	if(IO_Vars<interrupt>::m_safe){
		IO_Vars<interrupt>::m_state = digitalRead(pin);
	}else{
		IO_Vars<interrupt>::m_state = !(state);
	}
	ListenerLog("Listener", "Interrupt",  "println", "start interrupt");
	for(int x = 0; x < static_events->getPosition(); x++){
		EventMethod event =  *static_events->getByPosition(x);
		if(IO_Vars<interrupt>::m_inverted){
			event(interrupt, IO_Millis<interrupt>::m_millis, !IO_Vars<interrupt>::m_state);
		}else{
			event(interrupt, IO_Millis<interrupt>::m_millis, IO_Vars<interrupt>::m_state);
		}
	}
	for(int x = 0; x < events->getPosition(); x++){
		ListenerEvent* e =  events->getByPosition(x);
		if(IO_Vars<interrupt>::m_inverted){
			e->event(interrupt, IO_Millis<interrupt>::m_millis, !IO_Vars<interrupt>::m_state);
		}else{
			e->event(interrupt, IO_Millis<interrupt>::m_millis, IO_Vars<interrupt>::m_state);
		}
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
	if(IO_Vars<interrupt>::m_safe){
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
	IO_Millis<interrupt>::m_millis = millis();
	using EventMethod = void (*)(int,long,bool);
	ListenerLog("Listener", "Interrupt",  "println", "with parameter");
	int pin = IO_Pin<interrupt>::m_pin;
	List<ListenerEvent>* events = IO_ClassEvent<interrupt>::m_events;
	List<EventMethod>* static_events = IO_Event<interrupt>::m_events;
	if(pin == -1 || events == nullptr || static_events == nullptr){
		ListenerLog("Listener", "Interrupt",  "println", "pin == -1 || events == nullptr || static_events == nullptr");
		return;
	}
	ListenerLog("Listener", "Interrupt",  "println", "start interrupt");
	for(int x = 0; x < static_events->getPosition(); x++){
		EventMethod event =  *static_events->getByPosition(x);
		if(IO_Vars<interrupt>::m_inverted){
			event(interrupt, IO_Millis<interrupt>::m_millis, !state);
		}else{
			event(interrupt, IO_Millis<interrupt>::m_millis, state);
		}
	}
	for(int x = 0; x < events->getPosition(); x++){
		ListenerEvent* e =  events->getByPosition(x);
		if(IO_Vars<interrupt>::m_inverted){
			e->event(interrupt, IO_Millis<interrupt>::m_millis, !state);
		}else{
			e->event(interrupt, IO_Millis<interrupt>::m_millis, state);
		}
	}
	ListenerLog("Listener", "Interrupt",  "println", "end interrupt");
}

class Listener : public cppObject{
    public:
		using EventMethod = void (*)(int,long,bool);
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
		virtual cppObjectClass* getClass(){return Class<Listener>::classType;}
		virtual bool instanceof(cppObjectClass* cls){
			return cls == Class<Listener>::classType || cppObject::instanceof(cls);
		}
		
		template<int interrupt>
		void Secure(){
			IO_Vars<interrupt>::m_safe = true;
		}
		
		template<int interrupt>
		void UnSecure(){
			IO_Vars<interrupt>::m_safe = false;
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
		void createInput(int pin, bool inv, bool state){
			IO_Pin<interrupt>::m_pin = pin;
			IO_Vars<interrupt>::m_type = ListenerInput;
			IO_Vars<interrupt>::m_state = state;
			IO_Vars<interrupt>::m_safe = true;
			IO_Vars<interrupt>::m_inverted = inv;
			pinMode(pin,INPUT);
			LoopMap_m->addLValue(&Input<interrupt>);
		}
		
		template<int interrupt>
		void createInput(int pin, bool inv){
			createInput<interrupt>(pin, inv, false);
		}
		
		template<int interrupt>
		void createInput(int pin){
			createInput<interrupt>(pin, false, false);
		}
		
		template<int interrupt>
		void createDebounceInput(float l, int pin, bool inv, bool state){
			IO_Pin<interrupt>::m_pin = pin;
			IO_Vars<interrupt>::m_type = ListenerDebounceInput;
			IO_Vars<interrupt>::m_state = state;
			IO_Float_Times<interrupt>::m_timelimit = l;
			IO_Vars<interrupt>::m_safe = true;
			IO_Vars<interrupt>::m_inverted = inv;
			pinMode(pin,INPUT);
			LoopMap_m->addLValue(&DebounceInput<interrupt>);
		}
		
		template<int interrupt>
		void createDebounceInput(float l, int pin, bool inv){
			createDebounceInput<interrupt>(l, pin, inv, false);
		}
		
		template<int interrupt>
		void createDebounceInput(float l, int pin){
			createDebounceInput<interrupt>(l, pin, false, false);
		}
		
		template<int interrupt>
		void createDebounceInput(int pin){
			createDebounceInput<interrupt>(0.1f, pin, false);
		}
		
		template<int interrupt>
		void createDebounceInput(int pin, bool inv){
			createDebounceInput<interrupt>(0.1f, pin, inv, false);
		}
		
		template<int interrupt>
		void createDebounceInterrupt(long l, int pin, bool inv, bool state, bool owner){
			IO_Pin<interrupt>::m_pin = pin;
			IO_Vars<interrupt>::m_type = ListenerDebounceInterrupt;
			IO_Vars<interrupt>::m_state = state;
			IO_Vars<interrupt>::m_safe = true;
			IO_Vars<interrupt>::m_inverted = inv;
			IO_Long_Times<interrupt>::m_timelimit = l;
			if(IO_Event<interrupt>::m_events == nullptr){
				IO_Event<interrupt>::m_events = new PrimitiveList<EventMethod>(owner);
			}
			if(IO_ClassEvent<interrupt>::m_events == nullptr){
				IO_ClassEvent<interrupt>::m_events = new PrimitiveList<ListenerEvent>(owner);
			}
			pinMode(pin,INPUT_PULLUP);
			attachInterrupt(digitalPinToInterrupt(pin), DebounceInterrupt<interrupt>, CHANGE);
		}
		
		template<int interrupt>
		void createDebounceInterrupt(long l, int pin){
			createDebounceInterrupt<interrupt>(l, pin, false, false, true);
		}
		
		template<int interrupt>
		void createDebounceInterrupt(long l, int pin, bool inv){
			createDebounceInterrupt<interrupt>(l, pin, inv, false, true);
		}
		
		template<int interrupt>
		void createDebounceInterrupt(long l, int pin, bool inv, bool state){
			createDebounceInterrupt<interrupt>(l, pin, inv, state, true);
		}
		
		template<int interrupt>
		void createDebounceInterruptEvent(long l, int pin, bool inv, bool state, bool owner){
			IO_Pin<interrupt>::m_pin = pin;
			IO_Vars<interrupt>::m_type = ListenerDebounceInterruptEvent;
			IO_Vars<interrupt>::m_state = state;
			IO_Vars<interrupt>::m_safe = true;
			IO_Vars<interrupt>::m_inverted = inv;
			IO_Long_Times<interrupt>::m_timelimit = l;
			if(IO_Event<interrupt>::m_events == nullptr){
				IO_Event<interrupt>::m_events = new PrimitiveList<EventMethod>(owner);
			}
			pinMode(pin,INPUT_PULLUP);
			attachInterrupt(digitalPinToInterrupt(pin), DebounceInterrupt_Event<interrupt>, CHANGE);
		}
		
		template<int interrupt>
		void createDebounceInterruptEvent(long l, int pin){
			createDebounceInterruptEvent<interrupt>(l, pin, false, false, true);
		}
		
		template<int interrupt>
		void createDebounceInterruptEvent(long l, int pin, bool inv, bool state){
			createDebounceInterruptEvent<interrupt>(l, pin, inv, state, true);
		}
		
		template<int interrupt>
		void createDebounceInterruptEvent(long l, int pin, bool inv){
			createDebounceInterruptEvent<interrupt>(l, pin, inv, false, true);
		}
		
		template<int interrupt>
		void createDebounceInterruptClassEvent(long l, int pin, bool inv, bool state, bool owner){
			IO_Pin<interrupt>::m_pin = pin;
			IO_Vars<interrupt>::m_type = ListenerDebounceInterruptClassEvent;
			IO_Vars<interrupt>::m_state = state;
			IO_Vars<interrupt>::m_safe = true;
			IO_Vars<interrupt>::m_inverted = inv;
			IO_Long_Times<interrupt>::m_timelimit = l;
			if(IO_ClassEvent<interrupt>::m_events == nullptr){
				IO_ClassEvent<interrupt>::m_events = new PrimitiveList<ListenerEvent>(owner);
			}
			pinMode(pin,INPUT_PULLUP);
			attachInterrupt(digitalPinToInterrupt(pin), DebounceInterrupt_ClassEvent<interrupt>, CHANGE);
		}
		
		template<int interrupt>
		void createDebounceInterruptClassEvent(long l, int pin){
			createDebounceInterruptClassEvent<interrupt>(l, pin, false, false, true);
		}
		
		template<int interrupt>
		void createDebounceInterruptClassEvent(long l, int pin, bool inv){
			createDebounceInterruptClassEvent<interrupt>(l, pin, inv, false, true);
		}
		
		template<int interrupt>
		void createDebounceInterruptClassEvent(long l, int pin, bool inv, bool state){
			createDebounceInterruptClassEvent<interrupt>(l, pin, inv, state, true);
		}
		
		template<int interrupt>
		void loadDebounceLoopInterrupt(float l, int pin,  bool inv, bool state, bool owner, MonkeyImporter* importer){
			ElementId parent = String(interrupt);
			if(importer !=  nullptr){
				IO_Pin<interrupt>::m_pin = importer->read(parent.child("pin"), pin);
				IO_Vars<interrupt>::m_type = importer->read(parent.child("type"), ListenerDebounceLoopInterrupt);
				IO_Vars<interrupt>::m_state = importer->read(parent.child("state"), state);
				IO_Vars<interrupt>::m_safe = importer->read(parent.child("safe"), true);
				IO_Vars<interrupt>::m_inverted = importer->read(parent.child("inv"), inv);
				IO_Float_Times<interrupt>::m_timelimit = importer->read(parent.child("timelimit"), l);
			}else{
				IO_Pin<interrupt>::m_pin = pin;
				IO_Vars<interrupt>::m_type = ListenerDebounceLoopInterrupt;
				IO_Vars<interrupt>::m_state = state;
				IO_Vars<interrupt>::m_safe = true;
				IO_Vars<interrupt>::m_inverted = inv;
				IO_Float_Times<interrupt>::m_timelimit = l;
			}
			if(IO_Event<interrupt>::m_events == nullptr){
				IO_Event<interrupt>::m_events = new PrimitiveList<EventMethod>(owner);
			}
			if(IO_ClassEvent<interrupt>::m_events == nullptr){
				IO_ClassEvent<interrupt>::m_events = new PrimitiveList<ListenerEvent>(owner);
			}
			pinMode(IO_Pin<interrupt>::m_pin,INPUT);
			LoopMap_m->addLValue(&DebounceLoopInterrupt<interrupt>);
			ListenerLog("Listener", "loadDebounceLoopInterrupt",  "println", String("pin: ") + String(IO_Pin<interrupt>::m_pin));
			ListenerLog("Listener", "loadDebounceLoopInterrupt",  "println", String("type: ") + String(IO_Vars<interrupt>::m_type));
			ListenerLog("Listener", "loadDebounceLoopInterrupt",  "println", String("state: ") + String(IO_Vars<interrupt>::m_state));
			ListenerLog("Listener", "loadDebounceLoopInterrupt",  "println", String("safe: ") + String(IO_Vars<interrupt>::m_safe));
			ListenerLog("Listener", "loadDebounceLoopInterrupt",  "println", String("inverted: ") + String(IO_Vars<interrupt>::m_inverted));
			ListenerLog("Listener", "loadDebounceLoopInterrupt",  "println", String("timelimit: ") + String(IO_Float_Times<interrupt>::m_timelimit));
		}
		
		template<int interrupt>
		void loadDebounceLoopInterrupt(float l, int pin, MonkeyImporter* importer){
			loadDebounceLoopInterrupt<interrupt>(l, pin, false, false, true, importer);
		}
		
		template<int interrupt>
		void loadDebounceLoopInterrupt(float l, int pin,  bool inv, MonkeyImporter* importer){
			loadDebounceLoopInterrupt<interrupt>(l, pin, inv, false, true, importer);
		}
		
		template<int interrupt>
		void loadDebounceLoopInterrupt(float l, int pin,  bool inv, bool state, MonkeyImporter* importer){
			loadDebounceLoopInterrupt<interrupt>(l, pin, inv, state, true, importer);
		}
		
		template<int interrupt>
		void saveDebounceLoopInterrupt(MonkeyExporter* exporter){
			ElementId parent = String(interrupt);
			if(exporter ==  nullptr){
				return;
			}
			exporter->write(parent.child("pin"), IO_Pin<interrupt>::m_pin);
			exporter->write(parent.child("type"), IO_Vars<interrupt>::m_type);
			exporter->write(parent.child("state"), IO_Vars<interrupt>::m_state);
			exporter->write(parent.child("safe"), IO_Vars<interrupt>::m_safe);
			exporter->write(parent.child("inv"), IO_Vars<interrupt>::m_inverted);
			exporter->write(parent.child("timelimit"), IO_Float_Times<interrupt>::m_timelimit);
			ListenerLog("Listener", "saveDebounceLoopInterrupt",  "println", String("pin: ") + String(IO_Pin<interrupt>::m_pin));
			ListenerLog("Listener", "saveDebounceLoopInterrupt",  "println", String("type: ") + String(IO_Vars<interrupt>::m_type));
			ListenerLog("Listener", "saveDebounceLoopInterrupt",  "println", String("state: ") + String(IO_Vars<interrupt>::m_state));
			ListenerLog("Listener", "saveDebounceLoopInterrupt",  "println", String("safe: ") + String(IO_Vars<interrupt>::m_safe));
			ListenerLog("Listener", "saveDebounceLoopInterrupt",  "println", String("inverted: ") + String(IO_Vars<interrupt>::m_inverted));
			ListenerLog("Listener", "saveDebounceLoopInterrupt",  "println", String("timelimit: ") + String(IO_Float_Times<interrupt>::m_timelimit));
		}
		
		template<int interrupt>
		void createDebounceLoopInterrupt(float l, int pin,  bool inv, bool state, bool owner){
			IO_Pin<interrupt>::m_pin = pin;
			IO_Vars<interrupt>::m_type = ListenerDebounceLoopInterrupt;
			IO_Vars<interrupt>::m_state = state;
			IO_Vars<interrupt>::m_safe = true;
			IO_Vars<interrupt>::m_inverted = inv;
			IO_Float_Times<interrupt>::m_timelimit = l;
			if(IO_Event<interrupt>::m_events == nullptr){
				IO_Event<interrupt>::m_events = new PrimitiveList<EventMethod>(owner);
			}
			if(IO_ClassEvent<interrupt>::m_events == nullptr){
				IO_ClassEvent<interrupt>::m_events = new PrimitiveList<ListenerEvent>(owner);
			}
			pinMode(pin,INPUT);
			LoopMap_m->addLValue(&DebounceLoopInterrupt<interrupt>);
		}
		
		template<int interrupt>
		void createDebounceLoopInterrupt(float l, int pin){
			createDebounceLoopInterrupt<interrupt>(l, pin, false, false, true);
		}
		
		template<int interrupt>
		void createDebounceLoopInterrupt(float l, int pin,  bool inv){
			createDebounceLoopInterrupt<interrupt>(l, pin, inv, false, true);
		}
		
		template<int interrupt>
		void createDebounceLoopInterrupt(float l, int pin,  bool inv, bool state){
			createDebounceLoopInterrupt<interrupt>(l, pin, inv, state, true);
		}
		
		template<int interrupt, int multiInterrupt, int... interrupts>
		void createDebounceMultiInterrupt(long l, int pin,  bool inv, bool state, bool owner){
			IO_Pin<interrupt>::m_pin = pin;
			IO_Vars<interrupt>::m_type = ListenerDebounceMultiMultiInterruptEvent_v3;
			IO_Vars<interrupt>::m_state = state;
			IO_Vars<interrupt>::m_safe = true;
			IO_Vars<interrupt>::m_inverted = inv;
			IO_Multi_State<multiInterrupt>::m_state = state;
			IO_Long_Times<interrupt>::m_timelimit = l;
			if(IO_Event<interrupt>::m_events == nullptr){
				IO_Event<interrupt>::m_events = new PrimitiveList<EventMethod>(owner);
			}
			if(IO_ClassEvent<interrupt>::m_events == nullptr){
				IO_ClassEvent<interrupt>::m_events = new PrimitiveList<ListenerEvent>(owner);
			}
			if(IO_Multi_Event<interrupt>::m_events == nullptr){
				IO_Multi_Event<interrupt>::m_events = new PrimitiveList<EventMethod>(owner);
			}
			if(IO_Multi_ClassEvent<interrupt>::m_events == nullptr){
				IO_Multi_ClassEvent<interrupt>::m_events = new PrimitiveList<ListenerEvent>(owner);
			}
			pinMode(pin,INPUT_PULLUP);
			attachInterrupt(digitalPinToInterrupt(pin), DebounceMultiInterrupt<interrupt,multiInterrupt,interrupts...>, CHANGE);
		}
		
		template<int interrupt, int multiInterrupt, int... interrupts>
		void createDebounceMultiInterrupt(float l, int pin){
			createDebounceMultiInterrupt<interrupt,multiInterrupt,interrupts...>(l, pin, false, false, true);
		}
		
		template<int interrupt>
		void createDebounceMultiInterrupt(float l, int pin,  bool inv){
			createDebounceMultiInterrupt<interrupt>(l, pin, inv, false, true);
		}
		
		template<int interrupt>
		void createDebounceMultiInterrupt(float l, int pin,  bool inv, bool state){
			createDebounceMultiInterrupt<interrupt>(l, pin, inv, state, true);
		}
		
		template<int interrupt, int multiInterrupt, int... interrupts>
		void createSingleDebounceMultiInterrupt(long l, int pin,  bool inv, bool state, bool owner){
			IO_Pin<interrupt>::m_pin = pin;
			IO_Vars<interrupt>::m_type = ListenerDebounceMultiMultiInterruptEvent_v3;
			IO_Vars<interrupt>::m_state = state;
			IO_Vars<interrupt>::m_safe = true;
			IO_Vars<interrupt>::m_inverted = inv;
			IO_Multi_State<multiInterrupt>::m_state = state;
			IO_Long_Times<interrupt>::m_timelimit = l;
			pinMode(pin,INPUT_PULLUP);
			attachInterrupt(digitalPinToInterrupt(pin), SingleDebounceMultiInterrupt<interrupt,multiInterrupt,interrupts...>, CHANGE);
		}
		
		template<int interrupt, int multiInterrupt, int... interrupts>
		void createSingleDebounceMultiInterrupt(float l, int pin){
			createSingleDebounceMultiInterrupt<interrupt,multiInterrupt,interrupts...>(l, pin, false, false, true);
		}
		
		template<int interrupt>
		void createSingleDebounceMultiInterrupt(float l, int pin,  bool inv){
			createSingleDebounceMultiInterrupt<interrupt>(l, pin, inv, false, true);
		}
		
		template<int interrupt>
		void createSingleDebounceMultiInterrupt(float l, int pin,  bool inv, bool state){
			createSingleDebounceMultiInterrupt<interrupt>(l, pin, inv, state, true);
		}
		
		template<int interrupt>
		void createInterrupt(int pin, bool state, bool safe, bool owner){
			IO_Pin<interrupt>::m_pin = pin;
			IO_Vars<interrupt>::m_type = ListenerInterrupt;
			IO_Vars<interrupt>::m_state = state;
			IO_Vars<interrupt>::m_safe = safe;
			if(IO_Event<interrupt>::m_events == nullptr){
				IO_Event<interrupt>::m_events = new PrimitiveList<EventMethod>(owner);
			}
			if(IO_ClassEvent<interrupt>::m_events == nullptr){
				IO_ClassEvent<interrupt>::m_events = new PrimitiveList<ListenerEvent>(owner);
			}
			pinMode(pin,INPUT_PULLUP);
			attachInterrupt(digitalPinToInterrupt(pin), Interrupt<interrupt>, CHANGE);
		}
		
		template<int interrupt>
		void createInterrupt(int pin, bool state, bool safe){
			createInterrupt<interrupt>(pin, state, safe, true);
		}
		
		template<int interrupt>
		void createInterrupt(int pin, bool state){
			createInterrupt<interrupt>(pin, state, true, true);
		}
		
		template<int interrupt>
		void createThreadInterrupt(int pin, bool state, bool owner){
			IO_Pin<interrupt>::m_pin = pin;
			IO_Vars<interrupt>::m_type = ListenerThreadInterrupt;
			IO_Vars<interrupt>::m_state = state;
			IO_Vars<interrupt>::m_safe = true;
			if(IO_Event<interrupt>::m_events == nullptr){
				IO_Event<interrupt>::m_events = new PrimitiveList<EventMethod>(owner);
			}
			if(IO_ClassEvent<interrupt>::m_events == nullptr){
				IO_ClassEvent<interrupt>::m_events = new PrimitiveList<ListenerEvent>(owner);
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
			IO_Pin<interrupt>::m_pin = pin;
			IO_Vars<interrupt>::m_type = ListenerOutput;
			IO_Vars<interrupt>::m_state = state;
			IO_Vars<interrupt>::m_safe = true;
			pinMode(pin,OUTPUT);
		}
		
		template<int interrupt>
		void createOutput(int pin){
			createOutput<interrupt>(pin, false);
		}
		
		template<int interrupt>
		void loadOutputInterrupt(int pin, bool state, bool owner, MonkeyImporter* importer){
			ElementId parent = String(interrupt);
			if(importer != nullptr){
				IO_Pin<interrupt>::m_pin = importer->read(parent.child("pin"), pin);
				IO_Vars<interrupt>::m_type = importer->read(parent.child("type"), ListenerOutputInterrupt);
				IO_Vars<interrupt>::m_state = importer->read(parent.child("state"), state);
				IO_Vars<interrupt>::m_safe = importer->read(parent.child("safe"), true);
			}else{
				IO_Pin<interrupt>::m_pin = pin;
				IO_Vars<interrupt>::m_type = ListenerOutputInterrupt;
				IO_Vars<interrupt>::m_state = state;
				IO_Vars<interrupt>::m_safe = true;
			}
			if(IO_Event<interrupt>::m_events == nullptr){
				IO_Event<interrupt>::m_events = new PrimitiveList<EventMethod>(owner);
			}
			if(IO_ClassEvent<interrupt>::m_events == nullptr){
				IO_ClassEvent<interrupt>::m_events = new PrimitiveList<ListenerEvent>(owner);
			}
			pinMode(IO_Pin<interrupt>::m_pin,OUTPUT);
			digitalWrite(IO_Pin<interrupt>::m_pin, IO_Vars<interrupt>::m_state);
			LoopMap_m->addLValue(&OutputInterrupt<interrupt>);
			ListenerLog("Listener", "loadOutputInterrupt",  "println", String("pin: ") + String(IO_Pin<interrupt>::m_pin));
			ListenerLog("Listener", "loadOutputInterrupt",  "println", String("type: ") + String(IO_Vars<interrupt>::m_type));
			ListenerLog("Listener", "loadOutputInterrupt",  "println", String("state: ") + String(IO_Vars<interrupt>::m_state));
			ListenerLog("Listener", "loadOutputInterrupt",  "println", String("safe: ") + String(IO_Vars<interrupt>::m_safe));
			
		}
		
		template<int interrupt>
		void loadOutputInterrupt(int pin, MonkeyImporter* importer){
			loadOutputInterrupt<interrupt>(pin, false, true, importer);
		}
		
		template<int interrupt>
		void loadOutputInterrupt(int pin, bool state, MonkeyImporter* importer){
			loadOutputInterrupt<interrupt>(pin, state, true, importer);
		}
		
		template<int interrupt>
		void saveOutputInterrupt(MonkeyExporter* exporter){
			if(exporter == nullptr){
				return;
			}
			ElementId parent = String(interrupt);
			exporter->write(parent.child("pin"), IO_Pin<interrupt>::m_pin);
			exporter->write(parent.child("type"), IO_Vars<interrupt>::m_type);
			exporter->write(parent.child("state"), IO_Vars<interrupt>::m_state);
			exporter->write(parent.child("safe"), IO_Vars<interrupt>::m_safe);
			ListenerLog("Listener", "saveOutputInterrupt",  "println", String("pin: ") + String(IO_Pin<interrupt>::m_pin));
			ListenerLog("Listener", "saveOutputInterrupt",  "println", String("type: ") + String(IO_Vars<interrupt>::m_type));
			ListenerLog("Listener", "saveOutputInterrupt",  "println", String("state: ") + String(IO_Vars<interrupt>::m_state));
			ListenerLog("Listener", "saveOutputInterrupt",  "println", String("safe: ") + String(IO_Vars<interrupt>::m_safe));
		}
		
		template<int interrupt>
		void createOutputInterrupt(int pin, bool state, bool owner){
			IO_Pin<interrupt>::m_pin = pin;
			IO_Vars<interrupt>::m_type = ListenerOutputInterrupt;
			IO_Vars<interrupt>::m_state = state;
			IO_Vars<interrupt>::m_safe = true;
			if(IO_Event<interrupt>::m_events == nullptr){
				IO_Event<interrupt>::m_events = new PrimitiveList<EventMethod>(owner);
			}
			if(IO_ClassEvent<interrupt>::m_events == nullptr){
				IO_ClassEvent<interrupt>::m_events = new PrimitiveList<ListenerEvent>(owner);
			}
			pinMode(pin,OUTPUT);
			digitalWrite(pin, state);
			LoopMap_m->addLValue(&OutputInterrupt<interrupt>);
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
		void loadOutputValue(String name, bool state, bool owner, MonkeyImporter* importer){
			if(IO_Output_Value<interrupt>::m_output_values == nullptr){
				IO_Output_Value<interrupt>::m_output_values = new PrimitiveMap<String,bool>(owner);
				ElementId parent = String(interrupt);
				*IO_Output_Value<interrupt>::m_output_values = importer->read(parent.child("output_values"), PrimitiveMap<String,bool>());
			}
			if(IO_Output_Value<interrupt>::m_output_values->containKeyByLValue(name)){
				return;
			}
			IO_Output_Value<interrupt>::m_output_values->addLValues(name,state);
			ListenerLog("Listener", "loadOutputValue",  "println", String("name: ") + name);
			ListenerLog("Listener", "loadOutputValue",  "println", String("state: ") + String(state));
		}
		
		template<int interrupt>
		void loadOutputValue(String name, bool state, MonkeyImporter* importer){
			loadOutputValue<interrupt>(name, state, true, importer);
		}
		
		template<int interrupt>
		void saveOutputValue(MonkeyExporter* exporter){
			if(IO_Output_Value<interrupt>::m_output_values == nullptr || exporter == nullptr){
				return;
			}
			ElementId parent = String(interrupt);
			exporter->write(parent.child("output_values"), *IO_Output_Value<interrupt>::m_output_values);
		}
		
		template<int interrupt>
		void createOutputValue(String name, bool state, bool owner){
			if(IO_Output_Value<interrupt>::m_output_values == nullptr){
				IO_Output_Value<interrupt>::m_output_values = new PrimitiveMap<String,bool>(owner);
			}
			IO_Output_Value<interrupt>::m_output_values->addLValues(name,state);
		}
		
		template<int interrupt>
		void createOutputValue(String name, bool state){
			createOutputValue<interrupt>(name, state, true);
		}
		
		template<int interrupt>
		void createOutputValue(String name){
			createOutputValue<interrupt>(name, false, true);
		}
		
		template<int interrupt>
		void setOutputValue(String name, bool state){
			if(IO_Output_Value<interrupt>::m_output_values == nullptr){
				return;
			}
			ListenerLog("Listener", "setOutputValue",  "println", String("name: ") + name);
			ListenerLog("Listener", "setOutputValue",  "println", String("state: ") + String(state));
			IO_Output_Value<interrupt>::m_output_values->setLValues(name, state);
		}
		
		template<int interrupt,int interrupt_2>
		void applyOutputValue(String name, bool state){
			if(IO_Output_Value<interrupt_2>::m_output_values == nullptr){
				return;
			}
			IO_Output_Value<interrupt_2>::m_output_values->setLValues(name, state);
			bool* statePointer = IO_Output_Value<interrupt_2>::m_output_values->getByLValue(name);
			if(statePointer == nullptr){
				return;
			}
			IO_Output_State<interrupt>::m_state = statePointer;
			if(IO_Vars<interrupt>::m_state == *statePointer){
				return;
			}
			IO_Vars<interrupt>::m_state = *statePointer;
			digitalWrite(IO_Pin<interrupt>::m_pin, *statePointer);
		}
		
		template<int interrupt,int interrupt_2>
		void loadLinkOutputValue(String name, MonkeyImporter* importer){
			if(IO_Output_Value<interrupt_2>::m_output_values == nullptr || importer == nullptr){
				return;
			}
			ElementId parent = String(interrupt_2);
			String loadName = importer->read(parent.child(String(interrupt)).child("output_values").child("link"), name);
			bool* state = IO_Output_Value<interrupt_2>::m_output_values->getByLValue(loadName);
			IO_Output_State<interrupt>::m_state = state;
			ListenerLog("Listener", "loadLinkOutputValue",  "println", String("loadName: ") + loadName);
		}
		
		template<int interrupt,int interrupt_2>
		void saveLinkOutputValue(String name, MonkeyExporter* exporter){
			if(IO_Output_Value<interrupt_2>::m_output_values == nullptr || exporter == nullptr){
				return;
			}
			ElementId parent = String(interrupt_2);
			exporter->write(parent.child(String(interrupt)).child("output_values").child("link"), name);
			
			bool* state = IO_Output_Value<interrupt_2>::m_output_values->getByLValue(name);
			IO_Output_State<interrupt>::m_state = state;
			ListenerLog("Listener", "saveLinkOutputValue",  "println", String("loadName: ") + name);
		}
		
		template<int interrupt,int interrupt_2>
		void linkOutputValue(String name){
			if(IO_Output_Value<interrupt_2>::m_output_values == nullptr){
				return;
			}
			bool* state = IO_Output_Value<interrupt_2>::m_output_values->getByLValue(name);
			IO_Output_State<interrupt>::m_state = state;
		}
		
		template<int interrupt,int interrupt_2>
		void syncOutputValue(String name){
			if(IO_Output_Value<interrupt_2>::m_output_values == nullptr){
				return;
			}
			bool* state = IO_Output_Value<interrupt_2>::m_output_values->getByLValue(name);
			if(state == nullptr){
				return;
			}
			IO_Output_State<interrupt>::m_state = state;
		}
		
		template<int interrupt>
		void createOutputEvent(int pin, bool state, bool owner){
			IO_Pin<interrupt>::m_pin = pin;
			IO_Vars<interrupt>::m_type = ListenerOutputEvent;
			IO_Vars<interrupt>::m_state = state;
			IO_Vars<interrupt>::m_safe = true;
			if(IO_Event<interrupt>::m_events == nullptr){
				IO_Event<interrupt>::m_events = new PrimitiveList<EventMethod>(owner);
			}
			if(IO_ClassEvent<interrupt>::m_events == nullptr){
				IO_ClassEvent<interrupt>::m_events = new PrimitiveList<ListenerEvent>(owner);
			}
			pinMode(pin,OUTPUT);
		}
		
		template<int interrupt>
		void createOutputEvent(int pin, bool state){
			createOutputEvent<interrupt>(pin, state, true);
		}
		
		template<int interrupt>
		void createAnalogInput(int pin, bool owner){
			IO_Pin<interrupt>::m_pin = pin;
			Analog_Vars<interrupt>::m_type = ListenerAnalogInput;
			if(IO_AnalogEvent<interrupt>::m_events == nullptr){
				IO_AnalogEvent<interrupt>::m_events = new PrimitiveList<AnalogMethod>(owner);
			}
			if(IO_AnalogClassEvent<interrupt>::m_events == nullptr){
				IO_AnalogClassEvent<interrupt>::m_events = new PrimitiveList<ListenerAnalogEvent>(owner);
			}
			pinMode(pin,INPUT);
		}
		
		template<int interrupt>
		void createAnalogInput(int pin){
			createAnalogInput<interrupt>(pin, true);
		}
		
		template<int interrupt>
		int Type(){
			return IO_Vars<interrupt>::m_type;
		}
		
		template<int interrupt>
		int Pin(){
			return IO_Pin<interrupt>::m_pin;
		}
		
		//template<int interrupt, int pinSize>
		//int Pin(int x){
			//if(pinSize <= x){
				//return -1;
			//}
			//return IO_Multi_Pins<interrupt>::m_pin[x];
		//}
		
		template<int interrupt>
		bool isInverted(){
			return IO_Vars<interrupt>::m_inverted;
		}
		
		template<int interrupt>
		void invert(bool s){
			IO_Vars<interrupt>::m_inverted = s;
		}
		
		template<int interrupt>
		void invert(){
			IO_Vars<interrupt>::m_inverted = !IO_Vars<interrupt>::m_inverted;
		}
		
		template<int interrupt>
		void setPin(int pin){
			if(IO_Vars<interrupt>::m_type == -1){
				return;
			}
			if(IO_Vars<interrupt>::m_type == ListenerInput){
				pinMode(pin,INPUT);
			}
			if(IO_Vars<interrupt>::m_type == ListenerInputEvent){
				pinMode(pin,INPUT);
			}
			if(IO_Vars<interrupt>::m_type == ListenerDebounceInput){
				pinMode(pin,INPUT);
			}
			if(IO_Vars<interrupt>::m_type == ListenerDebounceInterrupt){
				pinMode(pin,INPUT);
			}
			if(IO_Vars<interrupt>::m_type == ListenerInterrupt){
				pinMode(pin,INPUT);
				attachInterrupt(digitalPinToInterrupt(pin), Interrupt<interrupt>, CHANGE);
			}
			if(IO_Vars<interrupt>::m_type == ListenerThreadInterrupt){
				pinMode(pin,INPUT);
				attachInterrupt(digitalPinToInterrupt(pin), ThreadInterrupt<interrupt>, CHANGE);
			}
			if(IO_Vars<interrupt>::m_type == ListenerOutput){
				pinMode(pin,OUTPUT);
			}
			if(IO_Vars<interrupt>::m_type == ListenerOutputInterrupt){
				pinMode(pin,OUTPUT);
			}
			if(IO_Vars<interrupt>::m_type == ListenerOutputEvent){
				pinMode(pin,OUTPUT);
			}
			IO_Pin<interrupt>::m_pin = pin;
		}
		
		template<int interrupt>
		void setTimeLimit(float t){
			IO_Vars<interrupt>::m_timelimit = t;
		}
		
		template<int interrupt>
		int TimeLimit(){
			return IO_Vars<interrupt>::m_timelimit;
		}
		
		template<int interrupt>
		long Millis(){
			return IO_Millis<interrupt>::m_millis;
		}
		
		template<int interrupt>
		bool PinState(){
			return IO_Vars<interrupt>::m_state;
		}
		
		template<int interrupt>
		void setPinState(bool state){
			IO_Vars<interrupt>::m_state = state;
			if(IO_Vars<interrupt>::m_type == ListenerOutput){
				digitalWrite(IO_Pin<interrupt>::m_pin, state);
			}
			if(IO_Vars<interrupt>::m_type == ListenerOutputInterrupt){
				digitalWrite(IO_Pin<interrupt>::m_pin, state);
				OutputMap_m->addLValue(&OutputInterrupt<interrupt>);
			}
			if(IO_Vars<interrupt>::m_type == ListenerOutputEvent){
				digitalWrite(IO_Pin<interrupt>::m_pin, state);
				OutputInterrupt<interrupt>();
			}
		}
		
		template<int interrupt>
		bool PinSafe(){
			return IO_Vars<interrupt>::m_safe;
		}
		
		//////////////////Adding single static events////////////////////////
		
		template<int interrupt>
		void addSingleEvent(EventMethod e){
			IO_Single_Event<interrupt>::m_event = e;
		}
		
		template<int interrupt>
		void addSingleMultiEvent(EventMethod e){
			IO_Single_Multi_Event<interrupt>::m_event = e;
		}
		
		template<int interrupt>
		bool containSingleEvent(EventMethod e){
			return IO_Single_Event<interrupt>::m_event == e;
		}
		
		template<int interrupt>
		void removeSingleEvent(EventMethod e){
			if(IO_Single_Event<interrupt>::m_event != e){
				return;
			}
			IO_Single_Event<interrupt>::m_event == nullptr;
		}
		
		//////////////////Adding single class events////////////////////////
		
		template<int interrupt>
		void addSingleEvent(ListenerEvent* e){
			IO_Single_ClassEvent<interrupt>::m_event = e;
		}
		
		template<int interrupt>
		void addSingleMultiEvent(ListenerEvent* e){
			IO_Single_ClassEvent<interrupt>::m_event = e;
		}
		
		template<int interrupt>
		bool containSingleEvent(ListenerEvent* e){
			return IO_Single_ClassEvent<interrupt>::m_event == e;
		}
		
		template<int interrupt>
		void removeSingleEvent(ListenerEvent* e){
			if(IO_Single_ClassEvent<interrupt>::m_event != e){
				return;
			}
			IO_Single_ClassEvent<interrupt>::m_event == nullptr;
		}
		
		template<int interrupt>
		void deleteSingleEvent(ListenerEvent* e){
			if(IO_Single_ClassEvent<interrupt>::m_event != e){
				return;
			}
			IO_Single_ClassEvent<interrupt>::m_event == nullptr;
		}
		
		//////////////////Adding static named events////////////////////////
		
		// template<int interrupt>
		// void addEventMap(String name, EventMethod e, bool owner){
			// if(IO_Named_Event<interrupt>::m_events == nullptr){
				// IO_Named_Event<interrupt>::m_events = new PrimitiveMap<String,EventMethod>(owner);
			// }
			// IO_Named_Event<interrupt>::m_events->addLValue(name, e);
		// }
		
		// template<int interrupt>
		// void addEventMap(String name, EventMethod e){
			// if(IO_Named_Event<interrupt>::m_events == nullptr){
				// IO_Named_Event<interrupt>::m_events = new PrimitiveMap<String,EventMethod>(owner);
			// }
			// IO_Named_Event<interrupt>::m_events->addLValue(name, e);
		// }
		
		// template<int interrupt>
		// void addMultiEvent(EventMethod e){
			// if(IO_Multi_Event<interrupt>::m_events == nullptr){
				// IO_Multi_Event<interrupt>::m_events = new PrimitiveList<EventMethod>();
			// }
			// IO_Multi_Event<interrupt>::m_events->addLValue(e);
		// }
		
		// template<int interrupt>
		// bool containEvent(EventMethod e){
			// if(IO_Event<interrupt>::m_events == nullptr){
				// return false;
			// }
			// return IO_Event<interrupt>::m_events->containByLValue(e);
		// }
		
		// template<int interrupt>
		// void removeEvent(EventMethod e){
			// if(IO_Event<interrupt>::m_events == nullptr){
				// return;
			// }
			// IO_Event<interrupt>::m_events->removeByLValue(e);
		// }
		
		// template<int interrupt>
		// void deleteEvent(EventMethod e){
			// if(IO_Event<interrupt>::m_events == nullptr){
				// return;
			// }
			// IO_Event<interrupt>::m_events->removeDeleteByLValue(e);
		// }
		
		//////////////////Adding static events////////////////////////
		
		template<int interrupt>
		void addEvent(EventMethod e, bool owner){
			if(IO_Event<interrupt>::m_events == nullptr){
				IO_Event<interrupt>::m_events = new PrimitiveList<EventMethod>(owner);
			}
			IO_Event<interrupt>::m_events->addLValue(e);
		}
		
		template<int interrupt>
		void addEvent(EventMethod e){
			if(IO_Event<interrupt>::m_events == nullptr){
				IO_Event<interrupt>::m_events = new PrimitiveList<EventMethod>();
			}
			IO_Event<interrupt>::m_events->addLValue(e);
		}
		
		template<int interrupt>
		void addMultiEvent(EventMethod e){
			if(IO_Multi_Event<interrupt>::m_events == nullptr){
				IO_Multi_Event<interrupt>::m_events = new PrimitiveList<EventMethod>();
			}
			IO_Multi_Event<interrupt>::m_events->addLValue(e);
		}
		
		template<int interrupt>
		bool containEvent(EventMethod e){
			if(IO_Event<interrupt>::m_events == nullptr){
				return false;
			}
			return IO_Event<interrupt>::m_events->containByLValue(e);
		}
		
		template<int interrupt>
		void removeEvent(EventMethod e){
			if(IO_Event<interrupt>::m_events == nullptr){
				return;
			}
			IO_Event<interrupt>::m_events->removeByLValue(e);
		}
		
		template<int interrupt>
		void deleteEvent(EventMethod e){
			if(IO_Event<interrupt>::m_events == nullptr){
				return;
			}
			IO_Event<interrupt>::m_events->removeDeleteByLValue(e);
		}
		
		//////////////////Adding class events////////////////////////
		
		template<int interrupt>
		void addEvent(ListenerEvent* e, bool owner){
			if(IO_ClassEvent<interrupt>::m_events == nullptr){
				IO_ClassEvent<interrupt>::m_events = new PrimitiveList<ListenerEvent>(owner);
			}
			IO_ClassEvent<interrupt>::m_events->addPointer(e);
		}
		
		template<int interrupt>
		void addEvent(ListenerEvent* e){
			if(IO_ClassEvent<interrupt>::m_events == nullptr){
				IO_ClassEvent<interrupt>::m_events = new PrimitiveList<ListenerEvent>();
			}
			IO_ClassEvent<interrupt>::m_events->addPointer(e);
		}
		
		template<int interrupt>
		bool containEvent(ListenerEvent* e){
			if(IO_ClassEvent<interrupt>::m_events == nullptr){
				return false;
			}
			return IO_ClassEvent<interrupt>::m_events->containByPointer(e);
		}
		
		template<int interrupt>
		ListenerEvent* removeEvent(ListenerEvent* e){
			if(IO_ClassEvent<interrupt>::m_events == nullptr){
				return nullptr;
			}
			return IO_ClassEvent<interrupt>::m_events->removeByPointer(e);
		}
		
		template<int interrupt>
		void deleteEvent(ListenerEvent* e){
			if(IO_ClassEvent<interrupt>::m_events == nullptr){
				return;
			}
			IO_ClassEvent<interrupt>::m_events->removeDeleteByPointer(e);
		}
		
		template<int interrupt>
		void runEvents(bool state_e){
			Interrupt<interrupt>(state_e);
		}
		
		
		//////////////////Adding static events////////////////////////
		
		template<int interrupt>
		void addEvent(AnalogMethod e, bool owner){
			if(IO_AnalogEvent<interrupt>::m_events == nullptr){
				IO_AnalogEvent<interrupt>::m_events = new PrimitiveList<AnalogMethod>(owner);
			}
			IO_AnalogEvent<interrupt>::m_events->addLValue(e);
		}
		
		template<int interrupt>
		void addEvent(AnalogMethod e){
			if(IO_AnalogEvent<interrupt>::m_events == nullptr){
				IO_AnalogEvent<interrupt>::m_events = new PrimitiveList<AnalogMethod>();
			}
			IO_AnalogEvent<interrupt>::m_events->addLValue(e);
		}
		
		template<int interrupt>
		bool containEvent(AnalogMethod e){
			if(IO_AnalogEvent<interrupt>::m_events == nullptr){
				return false;
			}
			return IO_AnalogEvent<interrupt>::m_events->containByLValue(e);
		}
		
		template<int interrupt>
		void removeEvent(AnalogMethod e){
			if(IO_AnalogEvent<interrupt>::m_events == nullptr){
				return;
			}
			IO_AnalogEvent<interrupt>::m_events->removeByLValue(e);
		}
		
		template<int interrupt>
		void deleteEvent(AnalogMethod e){
			if(IO_AnalogEvent<interrupt>::m_events == nullptr){
				return;
			}
			IO_AnalogEvent<interrupt>::m_events->removeDeleteByLValue(e);
		}
		
		//////////////////Adding class events////////////////////////
		
		template<int interrupt>
		void addEvent(ListenerAnalogEvent* e, bool owner){
			if(IO_AnalogClassEvent<interrupt>::m_events == nullptr){
				IO_AnalogClassEvent<interrupt>::m_events = new PrimitiveList<ListenerAnalogEvent>(owner);
			}
			IO_AnalogClassEvent<interrupt>::m_events->addPointer(e);
		}
		
		template<int interrupt>
		void addEvent(ListenerAnalogEvent* e){
			if(IO_AnalogClassEvent<interrupt>::m_events == nullptr){
				IO_AnalogClassEvent<interrupt>::m_events = new PrimitiveList<ListenerAnalogEvent>();
			}
			IO_AnalogClassEvent<interrupt>::m_events->addPointer(e);
		}
		
		template<int interrupt>
		bool containEvent(ListenerAnalogEvent* e){
			if(IO_AnalogClassEvent<interrupt>::m_events == nullptr){
				return false;
			}
			return IO_AnalogClassEvent<interrupt>::m_events->containByPointer(e);
		}
		
		template<int interrupt>
		ListenerAnalogEvent* removeEvent(ListenerAnalogEvent* e){
			if(IO_AnalogClassEvent<interrupt>::m_events == nullptr){
				return nullptr;
			}
			return IO_AnalogClassEvent<interrupt>::m_events->removeByPointer(e);
		}
		
		template<int interrupt>
		void deleteEvent(ListenerAnalogEvent* e){
			if(IO_AnalogClassEvent<interrupt>::m_events == nullptr){
				return;
			}
			IO_AnalogClassEvent<interrupt>::m_events->removeDeleteByPointer(e);
		}
		
	protected:
	Application* app = nullptr;
};

}

#endif 
