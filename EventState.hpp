
#ifndef EventState_hpp
#define EventState_hpp
#define EventState_AVAILABLE

#ifdef ame_ArduinoIDE
	#include "Arduino.h"
#endif

#include "BaseAppState.hpp"
#include "PrimitiveList.hpp"
#include "PrimitiveMap.hpp"
#include "Class.hpp"

#ifdef EventState_LogApp
	#include "ame_Logger_config.hpp"
	#include "ame_Logger.hpp"
	
	#define EventStateLog(location,method,type,mns) ame_Log(this,location,"EventState",method,type,mns)
	#define const_EventStateLog(location,method,type,mns) 
	#define StaticEventStateLog(pointer,location,method,type,mns) ame_Log(pointer,location,"EventState",method,type,mns)
#else
	#ifdef EventState_LogDebugApp
		#include "ame_Logger_config.hpp"
		#include "ame_Logger.hpp"
		
		#define EventStateLog(location,method,type,mns) ame_LogDebug(this,location,"EventState",method,type)
		#define const_EventStateLog(location,method,type,mns) 
		#define StaticEventStateLog(pointer,location,method,type,mns) ame_LogDebug(pointer,location,"EventState",method,type)
	#else
		#define EventStateLog(location,method,type,mns) 
		#define const_EventStateLog(location,method,type,mns) 
		#define StaticEventStateLog(pointer,location,method,type,mns) 
	#endif
#endif

namespace ame{

	using InterruptEventMethod = void (*)(int,long,bool);//interrupt,millis,state

	struct Interrupt
	{
		bool inverted;
		int pin;
		float state;

		void operator=(const Interrupt& o_i_events){
			inverted = o_i_events.inverted;
			pin = o_i_events.pin;
			state = o_i_events.state;
		}
		bool operator==(const Interrupt& o_i_events){
			return inverted == o_i_events.inverted || pin == o_i_events.pin || state == o_i_events.state;
		}
		bool operator!=(const Interrupt& o_i_events){
			return inverted != o_i_events.inverted || pin != o_i_events.pin || state != o_i_events.state;
		}
	};

	class InterruptAction{
		protected:
			long m_millis = 0;
			bool m_state = false;
			bool m_run = false;
		public:
			InterruptAction(){}
			virtual ~InterruptAction(){}

			virtual void setMillis(long a_mills){
				m_millis = a_mills;
			}

			virtual long getMillis(){
				return m_millis;
			}

			virtual float getTpc(long a_mills){
				return ((float)(a_mills - m_millis)) / 1000.0f;
			}

			virtual void setRunningEvents(bool a_run){
				m_run = a_run;
			}

			virtual bool runEvents(){
				return false;
			}

			virtual void setState(bool a_state){
				m_state = a_state;
			}

			virtual bool getState(){
				return m_state;
			}

			virtual void update(float tpc){

			}

			void operator=(const InterruptAction& o_i_events){}
			bool operator==(const InterruptAction& o_i_events){return false;}
			bool operator!=(const InterruptAction& o_i_events){return true;}
	};

	class InterruptEvent{
		public:
		InterruptAction* action = nullptr;
		PrimitiveList<InterruptEventMethod> events;

		InterruptEvent(){}
		virtual ~InterruptEvent(){}

		void operator=(const InterruptEvent& o_i_events){}
		bool operator==(const InterruptEvent& o_i_events){return false;}
		bool operator!=(const InterruptEvent& o_i_events){return true;}
	};

	template<int interrupt>
	struct Interrupt_List{
		static PrimitiveList<InterruptEvent> m_interrupts;
	};

	template<int interrupt> PrimitiveList<InterruptEvent>  Interrupt_List<interrupt>::m_interrupts;

	void runInterrupt(int a_interrupt, InterruptAction* a_action, PrimitiveList<InterruptEventMethod>& a_events, long a_millis, float a_tpc){
		a_action->setMillis(a_millis);

		a_action->update(a_tpc);

		if(a_action->runEvents()){
			for(int y = 0; y < a_events.getPosition(); y++){
				InterruptEventMethod* f_event_method = a_events.getByPosition(y);
				(**f_event_method)(a_interrupt, a_millis, a_action->getState());
			}
		}
	}
	
	template<int interrupt>
	void updateInterrupt(){
		long i_millis = millis();
		PrimitiveList<InterruptEvent>& i_interrupts = Interrupt_List<interrupt>::m_interrupts;
		for(int x = 0; x < i_interrupts.getPosition(); x++){
			InterruptEvent* f_i_event = i_interrupts.getByPosition(x);
			if(f_i_event == nullptr){
				return;
			}
			InterruptAction* f_action = f_i_event->action;
			PrimitiveList<InterruptEventMethod>& f_events = f_i_event->events;
			if(f_action == nullptr){
				return;
			}
			
			runInterrupt(interrupt, f_action, f_events, i_millis, f_action->getTpc(i_millis));
		}
	}
	
	template<int interrupt>
	InterruptEvent* createInterruptEvent(){
		PrimitiveList<InterruptEvent>& i_interrupts = Interrupt_List<interrupt>::m_interrupts;
		return i_interrupts.addPointer(new InterruptEvent());
	}
	
	template<int interrupt, class... Args>
	InterruptEvent* createInterruptEvent(InterruptAction* a_action, Args... a_args){
		PrimitiveList<InterruptEvent>& i_interrupts = Interrupt_List<interrupt>::m_interrupts;
		InterruptEvent* i_event = new InterruptEvent();
		i_event->action = a_action;
		i_event->events.addPack(a_args...);
		return i_event;
	}
	
	template<int interrupt>
	void attachInterruptEvent(int a_pin){
		pinMode(a_pin,INPUT_PULLUP);
		attachInterrupt(digitalPinToInterrupt(a_pin), updateInterrupt<interrupt>, CHANGE);
	}

class EventState IMPLEMENTATION_BaseAppState {
    public:
		EventState(){}
		virtual ~EventState(){}
			
		#if defined(cppObject_AVAILABLE) && defined(cppObjectClass_AVAILABLE) && defined(Class_AVAILABLE)
		virtual cppObjectClass* getClass(){
			return Class<EventState>::classType;
		}
		
		virtual bool instanceof(cppObjectClass* cls){
			return cls == Class<EventState>::getClass()
			#if defined(BaseAppState_AVAILABLE)
			|| BaseAppState::instanceof(cls)
			#endif
			;
		}
		#endif
		
		virtual void createInterrupt(int a_interrupt){
			m_update_interrupts.putPointer(a_interrupt, new InterruptEvent());
		}
		
		virtual void addEvent(int a_interrupt, InterruptEventMethod a_events){
			InterruptEvent* i_events = m_update_interrupts.getValueByLValue(a_interrupt);
			if(i_events == nullptr){
				return;
			}
			
			i_events->events.add(a_events);
		}
		
		virtual void addAction(int a_interrupt, InterruptAction* a_runner){
			InterruptEvent* i_events = m_update_interrupts.getValueByLValue(a_interrupt);
			if(i_events == nullptr){
				return;
			}

			i_events->action = a_runner;
		}
		
		virtual void updateState(float tpc){
			long i_millis = millis();
			for(auto f_entry : m_update_interrupts){
				int f_interrupt = f_entry.getKey();
				InterruptEvent* f_i_event = f_entry.getValuePointer();
				if(f_i_event == nullptr){
					return;
				}
				PrimitiveList<InterruptEventMethod>& f_events = f_i_event->events;
				InterruptAction* f_action = f_i_event->action;
				if(f_action == nullptr){
					return;
				}

				runInterrupt(f_interrupt, f_action, f_events, i_millis, tpc);
			}
		}
		
	protected:
		PrimitiveMap<int,InterruptEvent> m_update_interrupts;
};

}

#endif