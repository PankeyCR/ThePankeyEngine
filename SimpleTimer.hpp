
#include "ame_Enviroment.hpp"

#if defined(DISABLE_TimeControl) || defined(DISABLE_SimpleTimer)
	#define SimpleTimer_hpp
#endif

#ifndef SimpleTimer_hpp
#define SimpleTimer_hpp
#define SimpleTimer_AVAILABLE

#ifndef ame_Enviroment_Defined

#endif

#ifdef ame_Windows

#endif

#ifdef ame_ArduinoIDE
	#include "Arduino.h"
#endif

#include "TimeControl.hpp"
#include "TimeElapsed.hpp"
#include "List.hpp"
#include "Note.hpp"
#include "PrimitiveList.hpp"
#include "cppObjectClass.hpp"
#include "PrivateClass.hpp"


#if defined(ARDUINO_ARCH_AVR)
	#include <avr/interrupt.h>
	#include <avr/io.h>

#elif defined(ARDUINO_ARCH_SAM)
  // SAM-specific code
#else
  // generic, non-platform specific code
#endif

#ifdef SimpleTimerLoopLogApp
	#include "Logger.hpp"
	#define SimpleTimerLoopLog(name,method,type,mns) Log(name,method,type,mns)
#else
	#define SimpleTimerLoopLog(name,method,type,mns)
#endif

#ifdef SimpleTimerLogApp
	#include "Logger.hpp"
	#define SimpleTimerLog(name,method,type,mns) Log(name,method,type,mns)
#else
	#define SimpleTimerLog(name,method,type,mns)
#endif

namespace ame{

class Application;
#define RESOLUTION 65536

class SimpleTimer : public TimeControl{
    public:
		unsigned char clockSelectBits;
		char oldSREG;

		virtual ~SimpleTimer();

		static TimeControl* getInstance();

		virtual TimeControl* initialize(long timeperiod);
		virtual TimeControl* setPeriod(long timeperiod);

		TimeControl* attachInterrupt();
		TimeControl* detachInterrupt();
		TimeControl* startInterrupt();
		TimeControl* stopInterrupt();
		TimeControl* resumeInterrupt();

		
		virtual cppObjectClass* getClass(){
			return PrivateClass<TimeControl>::classType;
		}
		
		virtual bool instanceof(cppObjectClass* cls){
			return cls == Class<TimeControl>::classType;
		}

	private:
		static TimeControl *instance;

		SimpleTimer();

		#if defined(ame_GENERIC_ESP32)
		hw_timer_t * timer = nullptr;
		#endif
};

	TimeControl* SimpleTimer::instance = nullptr;

		TimeControl *SimpleTimer::getInstance(){
			SimpleTimerLog("SimpleTimer", "getInstance",  "println", "");
			if (instance == nullptr){
				SimpleTimerLog("SimpleTimer", "getInstance",  "println", "instance == nullptr");
				instance = new SimpleTimer();
			}
			return instance;
		}

		// SimpleTimer::SimpleTimer(){
			// this->timeList = new PrimitiveList<TimeElapsed>();
		// }

		// SimpleTimer::~SimpleTimer(){
			// delete this->timeList;
			// this->timeList = nullptr;
		// }

	#if defined(__AVR_ATmega2560__)
	#define TIMER1_RESOLUTION 32768
		ISR(TIMER1_OVF_vect){
			SimpleTimerLoopLog("SimpleTimer", "ISR",  "println", "__AVR_ATmega2560__");
			for(int x = 0; x < ((SimpleTimer*)SimpleTimer::getInstance())->timeList->getPosition(); x++){
				((SimpleTimer*)SimpleTimer::getInstance())->timeList->getByPosition(x)->Play(SimpleTimer::getInstance());
			}
			((SimpleTimer*)SimpleTimer::getInstance())->time+=1;
		}

		SimpleTimer::SimpleTimer(){
			SimpleTimerLog("SimpleTimer", "Constructor",  "println", "__AVR_ATmega2560__");
			this->timeList = new PrimitiveList<TimeElapsed>();
			Serial.println("AVR_ATmega2560");
		}

		SimpleTimer::~SimpleTimer(){
			SimpleTimerLog("SimpleTimer", "Destructor",  "println", "__AVR_ATmega2560__");
			delete this->timeList;
			this->timeList = nullptr;
		}

		TimeControl* SimpleTimer::initialize(long microseconds){
			SimpleTimerLog("SimpleTimer", "initialize",  "println", "__AVR_ATmega2560__");
			SimpleTimerLog("SimpleTimer", "initialize",  "println", Note("microseconds ") + Note(microseconds));
			TCCR1B = _BV(WGM13);        // set mode as phase and frequency correct pwm, stop the timer
			TCCR1A = 0;                 // clear control register A
			setPeriod(microseconds);
			return this;
		}

		TimeControl* SimpleTimer::setPeriod(long microseconds){
			SimpleTimerLog("SimpleTimer", "setPeriod",  "println", "__AVR_ATmega2560__");
			SimpleTimerLog("SimpleTimer", "setPeriod",  "println", Note("microseconds ") + Note(microseconds));
			const unsigned long cycles = ((F_CPU/100000 * microseconds) / 20);
			if (cycles < TIMER1_RESOLUTION) {
				clockSelectBits = _BV(CS10);
				// pwmPeriod = cycles;
			} else
			if (cycles < TIMER1_RESOLUTION * 8) {
				clockSelectBits = _BV(CS11);
				// pwmPeriod = cycles / 8;
			} else
			if (cycles < TIMER1_RESOLUTION * 64) {
				clockSelectBits = _BV(CS11) | _BV(CS10);
				// pwmPeriod = cycles / 64;
			} else
			if (cycles < TIMER1_RESOLUTION * 256) {
				clockSelectBits = _BV(CS12);
				// pwmPeriod = cycles / 256;
			} else
			if (cycles < TIMER1_RESOLUTION * 1024) {
				clockSelectBits = _BV(CS12) | _BV(CS10);
				// pwmPeriod = cycles / 1024;
			} else {
				clockSelectBits = _BV(CS12) | _BV(CS10);
				// pwmPeriod = TIMER1_RESOLUTION - 1;
			}
			ICR1 = cycles;
			TCCR1B = _BV(WGM13) | clockSelectBits;                     // reset clock select register, and starts the clock
			return this;
		}

		TimeControl* SimpleTimer::attachInterrupt(){
			SimpleTimerLog("SimpleTimer", "attachInterrupt",  "println", "__AVR_ATmega2560__");
			TIMSK1 = _BV(TOIE1);                                     // sets the timer overflow interrupt enable bit
			// might be running with interrupts disabled (eg inside an ISR), so don't touch the global state
			//  sei();
			resumeInterrupt();
			return this;
		}

		TimeControl* SimpleTimer::detachInterrupt(){
			SimpleTimerLog("SimpleTimer", "detachInterrupt",  "println", "__AVR_ATmega2560__");
			TIMSK1 = 0;
			return this;
		}

		TimeControl* SimpleTimer::startInterrupt(){
			SimpleTimerLog("SimpleTimer", "startInterrupt",  "println", "__AVR_ATmega2560__");
			TCCR1B = 0;
			TCNT1 = 0;		// TODO: does this cause an undesired interrupt?
			resumeInterrupt();
			return this;
		}

		TimeControl* SimpleTimer::stopInterrupt(){
			SimpleTimerLog("SimpleTimer", "stopInterrupt",  "println", "__AVR_ATmega2560__");
			TCCR1B = _BV(WGM13);
			return this;
		}

		TimeControl* SimpleTimer::resumeInterrupt(){
			SimpleTimerLog("SimpleTimer", "resumeInterrupt",  "println", "__AVR_ATmega2560__");
			TCCR1B = _BV(WGM13) | clockSelectBits;
			return this;
		}


	#elif defined(ARDUINO_ARCH_AVR)
		ISR(TIMER1_OVF_vect){
			SimpleTimerLoopLog("SimpleTimer", "ISR",  "println", "ARDUINO_ARCH_AVR");
			for(int x = 0; x < ((SimpleTimer*)SimpleTimer::getInstance())->timeList->getPosition(); x++){
				((SimpleTimer*)SimpleTimer::getInstance())->timeList->getByPosition(x)->Play(SimpleTimer::getInstance());
			}
			((SimpleTimer*)SimpleTimer::getInstance())->time+=1;
		}

		SimpleTimer::SimpleTimer(){
			SimpleTimerLog("SimpleTimer", "Constructor",  "println", "ARDUINO_ARCH_AVR");
			this->timeList = new PrimitiveList<TimeElapsed>();
			Serial.println("ARDUINO_ARCH_AVR");
		}

		SimpleTimer::~SimpleTimer(){
			SimpleTimerLog("SimpleTimer", "Destructor",  "println", "ARDUINO_ARCH_AVR");
			delete this->timeList;
			this->timeList = nullptr;
		}

		TimeControl* SimpleTimer::initialize(long timeperiod){
			SimpleTimerLog("SimpleTimer", "initialize",  "println", "ARDUINO_ARCH_AVR");
			SimpleTimerLog("SimpleTimer", "initialize",  "println", Note("microseconds ") + Note(microseconds));
			// TCCR1A = 0;
			// TCCR1B = _BV(WGM13);
			// setPeriod(timeperiod);
			return this;
		}

		TimeControl* SimpleTimer::setPeriod(long microseconds){
			SimpleTimerLog("SimpleTimer", "setPeriod",  "println", "ARDUINO_ARCH_AVR");
			SimpleTimerLog("SimpleTimer", "setPeriod",  "println", Note("microseconds ") + Note(microseconds));
			this->period = timeperiod;
			long cycles = (F_CPU / 2000000) * timeperiod;        // the counter runs backwards after TOP, interrupt is at BOTTOM so divide microseconds by 2
			if(cycles < RESOLUTION)              clockSelectBits = _BV(CS10);              // no prescale, full xtal
			else if((cycles >>= 3) < RESOLUTION) clockSelectBits = _BV(CS11);              // prescale by /8
			else if((cycles >>= 3) < RESOLUTION) clockSelectBits = _BV(CS11) | _BV(CS10);  // prescale by /64
			else if((cycles >>= 2) < RESOLUTION) clockSelectBits = _BV(CS12);              // prescale by /256
			else if((cycles >>= 2) < RESOLUTION) clockSelectBits = _BV(CS12) | _BV(CS10);  // prescale by /1024
			else        cycles = RESOLUTION - 1, clockSelectBits = _BV(CS12) | _BV(CS10);  // request was out of bounds, set as maximum

			oldSREG = SREG;
			cli();							// Disable interrupts for 16 bit register access
			ICR1 = cycles;                                          // ICR1 is TOP in p & f correct pwm mode
			SREG = oldSREG;

			TCCR1B &= ~(_BV(CS10) | _BV(CS11) | _BV(CS12));
			TCCR1B |= clockSelectBits;                                          // reset clock select register, and starts the clock
			return this;
		}

		TimeControl* SimpleTimer::attachInterrupt(){
			SimpleTimerLog("SimpleTimer", "attachInterrupt",  "println", "ARDUINO_ARCH_AVR");
			TIMSK1 = _BV(TOIE1);                                     // sets the timer overflow interrupt enable bit
			// might be running with interrupts disabled (eg inside an ISR), so don't touch the global state
			//  sei();
			resumeInterrupt();
			return this;
		}

		TimeControl* SimpleTimer::detachInterrupt(){
			SimpleTimerLog("SimpleTimer", "detachInterrupt",  "println", "ARDUINO_ARCH_AVR");
			TIMSK1 &= ~_BV(TOIE1);                                   // clears the timer overflow interrupt enable bit
																	// timer continues to count without calling the isr
			return this;
		}

		TimeControl* SimpleTimer::startInterrupt(){
			SimpleTimerLog("SimpleTimer", "startInterrupt",  "println", "ARDUINO_ARCH_AVR");
			unsigned int tcnt1;

			TIMSK1 &= ~_BV(TOIE1);        // AR added
			GTCCR |= _BV(PSRSYNC);   		// AR added - reset prescaler (NB: shared with all 16 bit timers);

			oldSREG = SREG;				// AR - save status register
			cli();						// AR - Disable interrupts
			TCNT1 = 0;
			SREG = oldSREG;          		// AR - Restore status register
			resumeInterrupt();
			do {	// Nothing -- wait until timer moved on from zero - otherwise get a phantom interrupt
				oldSREG = SREG;
				cli();
				tcnt1 = TCNT1;
				SREG = oldSREG;
			} while (tcnt1==0);

			//  TIFR1 = 0xff;              		// AR - Clear interrupt flags
			//  TIMSK1 = _BV(TOIE1);              // sets the timer overflow interrupt enable bit
			return this;
		}

		TimeControl* SimpleTimer::stopInterrupt(){
			SimpleTimerLog("SimpleTimer", "stopInterrupt",  "println", "ARDUINO_ARCH_AVR");
			TCCR1B &= ~(_BV(CS10) | _BV(CS11) | _BV(CS12));          // clears all clock selects bits
			return this;
		}

		TimeControl* SimpleTimer::resumeInterrupt(){
			SimpleTimerLog("SimpleTimer", "resumeInterrupt",  "println", "ARDUINO_ARCH_AVR");
			TCCR1B |= clockSelectBits;
			return this;
		}


	#elif defined(ARDUINO_ARCH_SAM)

		SimpleTimer::SimpleTimer(){
			SimpleTimerLog("SimpleTimer", "Constructor",  "println", "ARDUINO_ARCH_AVR");
			this->timeList = new PrimitiveList<TimeElapsed>();
			Serial.println("ARDUINO_ARCH_SAM");
		}

		SimpleTimer::~SimpleTimer(){
			SimpleTimerLog("SimpleTimer", "Destructor",  "println", "ARDUINO_ARCH_AVR");
			delete this->timeList;
			this->timeList = nullptr;
		}

	  // SAM-specific code
	#elif defined(ARDUINO_ARCH_ESP8266)

		void ICACHE_RAM_ATTR onTime() {
			SimpleTimerLoopLog("SimpleTimer", "ICACHE_RAM_ATTR",  "println", "ARDUINO_ARCH_ESP8266");
			for(int x = 0; x < ((SimpleTimer*)SimpleTimer::getInstance())->timeList->getPosition(); x++){
				((SimpleTimer*)SimpleTimer::getInstance())->timeList->getByPosition(x)->Play(SimpleTimer::getInstance());
			}
			((SimpleTimer*)SimpleTimer::getInstance())->time+=1;
		}

		SimpleTimer::SimpleTimer(){
			SimpleTimerLog("SimpleTimer", "Constructor",  "println", "ARDUINO_ARCH_ESP8266");
			this->timeList = new PrimitiveList<TimeElapsed>();
		}

		SimpleTimer::~SimpleTimer(){
			SimpleTimerLog("SimpleTimer", "Destructor",  "println", "ARDUINO_ARCH_ESP8266");
			delete this->timeList;
			this->timeList = nullptr;
		}

		TimeControl* SimpleTimer::initialize(long microseconds){
			SimpleTimerLog("SimpleTimer", "initialize",  "println", "ARDUINO_ARCH_ESP8266");
			SimpleTimerLog("SimpleTimer", "initialize",  "println", Note("microseconds ") + Note(microseconds));
			timer1_isr_init();
			setPeriod(microseconds);
			return this;
		}

		TimeControl* SimpleTimer::setPeriod(long microseconds){
			SimpleTimerLog("SimpleTimer", "setPeriod",  "println", "ARDUINO_ARCH_ESP8266");
			SimpleTimerLog("SimpleTimer", "setPeriod",  "println", Note("microseconds ") + Note(microseconds));
			//timer1_write(100000000);//5 ticks per us from TIM_DIV16
			//timer1_write((long)((microseconds) * 80));//5 ticks per us from TIM_DIV1
			//timer1_write((long)((microseconds) * 5));//5 ticks per us from TIM_DIV16
			timer1_write((long)((microseconds) * 0.312500f));//1 ticks per 3.2us from TIM_DIV256
			// Arm the Timer for our 0.5s Interval
			//timer1_write(2500000); // 2500000 / 5 ticks per us from TIM_DIV16 == 500,000 us interval
			//Set up ESP watchdog
			// ESP.wdtDisable();
			// ESP.wdtEnable(WDTO_8S);
			return this;
		}

		TimeControl* SimpleTimer::attachInterrupt(){
			SimpleTimerLog("SimpleTimer", "attachInterrupt",  "println", "ARDUINO_ARCH_ESP8266");
			timer1_attachInterrupt(onTime);
			//timer1_enable(TIM_DIV1, TIM_EDGE, TIM_LOOP);
			//timer1_enable(TIM_DIV16, TIM_EDGE, TIM_LOOP);
			timer1_enable(TIM_DIV256, TIM_EDGE, TIM_LOOP);
			/* Dividers:
				TIM_DIV1 = 0,   //80MHz (80 ticks/us - 104857.588 us max)
				TIM_DIV16 = 1,  //5MHz (5 ticks/us - 1677721.4 us max)
				TIM_DIV256 = 3  //312.5Khz (1 tick = 3.2us - 26843542.4 us max)
			Reloads:
				TIM_SINGLE	0 //on interrupt routine you need to write a new value to start the timer again
				TIM_LOOP	1 //on interrupt the counter will start with the same value again
			*/
			// Arm the Timer for our 0.5s Interval
			//timer1_write(2500000); // 2500000 / 5 ticks per us from TIM_DIV16 == 500,000 us interval
			return this;
		}

		TimeControl* SimpleTimer::detachInterrupt(){
			SimpleTimerLog("SimpleTimer", "detachInterrupt",  "println", "ARDUINO_ARCH_ESP8266");

			return this;
		}

		TimeControl* SimpleTimer::startInterrupt(){
			SimpleTimerLog("SimpleTimer", "startInterrupt",  "println", "ARDUINO_ARCH_ESP8266");

			return this;
		}

		TimeControl* SimpleTimer::stopInterrupt(){
			SimpleTimerLog("SimpleTimer", "stopInterrupt",  "println", "ARDUINO_ARCH_ESP8266");

			return this;
		}

		TimeControl* SimpleTimer::resumeInterrupt(){
			SimpleTimerLog("SimpleTimer", "resumeInterrupt",  "println", "ARDUINO_ARCH_ESP8266");

			return this;
		}
	//esp32
	#elif defined(ame_GENERIC_ESP32)
		
		#include "esp_task_wdt.h"

		void IRAM_ATTR onTime(){// IRAM_ATTR  ARDUINO_ISR_ATTR
			SimpleTimerLoopLog("SimpleTimer", "IRAM_ATTR",  "println", "ARDUINO_ESP32_DEV");
			for(int x = 0; x < ((SimpleTimer*)SimpleTimer::getInstance())->timeList->getPosition(); x++){
				((SimpleTimer*)SimpleTimer::getInstance())->timeList->getByPosition(x)->Play(SimpleTimer::getInstance());
				// esp_task_wdt_reset();
				// yield();
			}
			((SimpleTimer*)SimpleTimer::getInstance())->time+=1;
		}

		SimpleTimer::SimpleTimer(){
			SimpleTimerLog("SimpleTimer", "Constructor",  "println", "ARDUINO_ESP32_DEV");
			this->timeList = new PrimitiveList<TimeElapsed>();
			timer = timerBegin(0, 80, true);
		}

		SimpleTimer::~SimpleTimer(){
			SimpleTimerLog("SimpleTimer", "Destructor",  "println", "ARDUINO_ESP32_DEV");
			delete this->timeList;
			this->timeList = nullptr;
		}

		TimeControl* SimpleTimer::initialize(long microseconds){
			SimpleTimerLog("SimpleTimer", "attachInterrupt",  "println", "ARDUINO_ESP32_DEV");
			SimpleTimerLog("SimpleTimer", "initialize",  "println", Note("microseconds ") + Note(microseconds));
			setPeriod(microseconds);
			return this;
		}

		TimeControl* SimpleTimer::setPeriod(long microseconds){//microseconds
			SimpleTimerLog("SimpleTimer", "attachInterrupt",  "println", "ARDUINO_ESP32_DEV");
			SimpleTimerLog("SimpleTimer", "setPeriod",  "println", Note("microseconds ") + Note(microseconds));
			//12.5ns *80 = 1000ns = 1 us
			if(timer == nullptr){
				return this;
			}
			
			timerAlarmWrite(timer, microseconds, true);
			timerAlarmEnable(timer);
			return this;
		}

		TimeControl* SimpleTimer::attachInterrupt(){
			SimpleTimerLog("SimpleTimer", "attachInterrupt",  "println", "ARDUINO_ESP32_DEV");
			if(timer == nullptr){
				return this;
			}
			timerAttachInterrupt(timer, &onTime, true);
			return this;
		}

		TimeControl* SimpleTimer::detachInterrupt(){
			SimpleTimerLog("SimpleTimer", "detachInterrupt",  "println", "ARDUINO_ESP32_DEV");

			return this;
		}

		TimeControl* SimpleTimer::startInterrupt(){
			SimpleTimerLog("SimpleTimer", "startInterrupt",  "println", "ARDUINO_ESP32_DEV");
			timerStart(timer);
			return this;
		}

		TimeControl* SimpleTimer::stopInterrupt(){
			SimpleTimerLog("SimpleTimer", "stopInterrupt",  "println", "ARDUINO_ESP32_DEV");
			timerStop(timer);
			return this;
		}

		TimeControl* SimpleTimer::resumeInterrupt(){
			SimpleTimerLog("SimpleTimer", "resumeInterrupt",  "println", "ARDUINO_ESP32_DEV");

			return this;
		}
	//feather m0
	#elif defined(ame_GENERIC_ADAFRUIT_FEATHER)


		SimpleTimer::SimpleTimer(){
			SimpleTimerLog("SimpleTimer", "Constructor",  "println", "ARDUINO_SAMD_ZERO");
			this->timeList = new PrimitiveList<TimeElapsed>();
			Serial.println("ARDUINO_SAMD_ZERO");
		}

		SimpleTimer::~SimpleTimer(){
			SimpleTimerLog("SimpleTimer", "Destructor",  "println", "ARDUINO_SAMD_ZERO");
			delete this->timeList;
			this->timeList = nullptr;
		}

		TimeControl* SimpleTimer::initialize(long microseconds){
			SimpleTimerLog("SimpleTimer", "initialize",  "println", "ARDUINO_SAMD_ZERO");
			SimpleTimerLog("SimpleTimer", "initialize",  "println", Note("microseconds ") + Note(microseconds));
			
			setPeriod(microseconds);
			return this;
		}

		TimeControl* SimpleTimer::setPeriod(long microseconds){
			SimpleTimerLog("SimpleTimer", "setPeriod",  "println", "ARDUINO_SAMD_ZERO");
			SimpleTimerLog("SimpleTimer", "setPeriod",  "println", Note("microseconds ") + Note(microseconds));
			return this;
		}

		TimeControl* SimpleTimer::attachInterrupt(){
			SimpleTimerLog("SimpleTimer", "attachInterrupt",  "println", "ARDUINO_SAMD_ZERO");

			return this;
		}

		TimeControl* SimpleTimer::detachInterrupt(){
			SimpleTimerLog("SimpleTimer", "detachInterrupt",  "println", "ARDUINO_SAMD_ZERO");

			return this;
		}

		TimeControl* SimpleTimer::startInterrupt(){
			SimpleTimerLog("SimpleTimer", "startInterrupt",  "println", "ARDUINO_SAMD_ZERO");

			return this;
		}

		TimeControl* SimpleTimer::stopInterrupt(){
			SimpleTimerLog("SimpleTimer", "stopInterrupt",  "println", "ARDUINO_SAMD_ZERO");

			return this;
		}

		TimeControl* SimpleTimer::resumeInterrupt(){
			SimpleTimerLog("SimpleTimer", "resumeInterrupt",  "println", "ARDUINO_SAMD_ZERO");

			return this;
		}
	#else


		SimpleTimer::SimpleTimer(){
			SimpleTimerLog("SimpleTimer", "Constructor",  "println", "");
			this->timeList = new PrimitiveList<TimeElapsed>();
			//Serial.println("else");
		}

		SimpleTimer::~SimpleTimer(){
			SimpleTimerLog("SimpleTimer", "Destructor",  "println", "");
			delete this->timeList;
			this->timeList = nullptr;
		}

		TimeControl* SimpleTimer::initialize(long microseconds){
			SimpleTimerLog("SimpleTimer", "initialize",  "println", Note("microseconds ") + Note(microseconds));
			
			setPeriod(microseconds);
			return this;
		}

		TimeControl* SimpleTimer::setPeriod(long microseconds){
			SimpleTimerLog("SimpleTimer", "initialize",  "println", Note("microseconds ") + Note(microseconds));
			return this;
		}

		TimeControl* SimpleTimer::attachInterrupt(){
			SimpleTimerLog("SimpleTimer", "attachInterrupt",  "println", "");

			return this;
		}

		TimeControl* SimpleTimer::detachInterrupt(){
			SimpleTimerLog("SimpleTimer", "detachInterrupt",  "println", "");

			return this;
		}

		TimeControl* SimpleTimer::startInterrupt(){
			SimpleTimerLog("SimpleTimer", "startInterrupt",  "println", "");

			return this;
		}

		TimeControl* SimpleTimer::stopInterrupt(){
			SimpleTimerLog("SimpleTimer", "stopInterrupt",  "println", "");

			return this;
		}

		TimeControl* SimpleTimer::resumeInterrupt(){
			SimpleTimerLog("SimpleTimer", "resumeInterrupt",  "println", "");

			return this;
		}
	#endif
}

#endif