
	#ifndef SimpleTimer_cpp
	#define SimpleTimer_cpp

	#include "SimpleTimer.h"

	ame::TimeControl* ame::SimpleTimer::instance = nullptr;



		ame::TimeControl *ame::SimpleTimer::getInstance(){
			if (instance == nullptr){
				instance = new ame::SimpleTimer();
			}
			return instance;
		}
		
		// ame::SimpleTimer::SimpleTimer(){
			// this->timeList = new PrimitiveList<TimeElapsed>();
		// }
		
		// ame::SimpleTimer::~SimpleTimer(){
			// delete this->timeList;
			// this->timeList = nullptr;
		// }
		
	#if defined(__AVR_ATmega2560__)
	#define TIMER1_RESOLUTION 32768
		ISR(TIMER1_OVF_vect){
			for(int x = 0; x < ((ame::SimpleTimer*)ame::SimpleTimer::getInstance())->timeList->getPosition(); x++){
				((ame::SimpleTimer*)ame::SimpleTimer::getInstance())->timeList->getByPosition(x)->Play(ame::SimpleTimer::getInstance());
			}
			((ame::SimpleTimer*)ame::SimpleTimer::getInstance())->time+=1;
		}
		
		ame::SimpleTimer::SimpleTimer(){
			this->timeList = new PrimitiveList<TimeElapsed>();
			Serial.println("AVR_ATmega2560");
		}
		
		ame::SimpleTimer::~SimpleTimer(){
			delete this->timeList;
			this->timeList = nullptr;
		}

		ame::TimeControl* ame::SimpleTimer::initialize(long microseconds){
			TCCR1B = _BV(WGM13);        // set mode as phase and frequency correct pwm, stop the timer
			TCCR1A = 0;                 // clear control register A 
			setPeriod(microseconds);
			return this;
		}

		ame::TimeControl* ame::SimpleTimer::setPeriod(long microseconds){
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

		ame::TimeControl* ame::SimpleTimer::attachInterrupt(){
			TIMSK1 = _BV(TOIE1);                                     // sets the timer overflow interrupt enable bit
			// might be running with interrupts disabled (eg inside an ISR), so don't touch the global state
			//  sei();
			resumeInterrupt();	
			return this;											
		}

		ame::TimeControl* ame::SimpleTimer::detachInterrupt(){
			TIMSK1 = 0;
			return this;
		}

		ame::TimeControl* ame::SimpleTimer::startInterrupt(){
			TCCR1B = 0;
			TCNT1 = 0;		// TODO: does this cause an undesired interrupt?
			resumeInterrupt();
			return this;
		}

		ame::TimeControl* ame::SimpleTimer::stopInterrupt(){
			TCCR1B = _BV(WGM13);
			return this;
		}

		ame::TimeControl* ame::SimpleTimer::resumeInterrupt(){ 
			TCCR1B = _BV(WGM13) | clockSelectBits;
			return this;
		}
		

	#elif defined(ARDUINO_ARCH_AVR)
		ISR(TIMER1_OVF_vect){
			for(int x = 0; x < ((ame::SimpleTimer*)ame::SimpleTimer::getInstance())->timeList->getPosition(); x++){
				((ame::SimpleTimer*)ame::SimpleTimer::getInstance())->timeList->getByPosition(x)->Play(ame::SimpleTimer::getInstance());
			}
			((ame::SimpleTimer*)ame::SimpleTimer::getInstance())->time+=1;
		}
		
		ame::SimpleTimer::SimpleTimer(){
			this->timeList = new PrimitiveList<TimeElapsed>();
			Serial.println("ARDUINO_ARCH_AVR");
		}
		
		ame::SimpleTimer::~SimpleTimer(){
			delete this->timeList;
			this->timeList = nullptr;
		}

		ame::TimeControl* ame::SimpleTimer::initialize(long timeperiod){
			// TCCR1A = 0;
			// TCCR1B = _BV(WGM13);
			// setPeriod(timeperiod);
			Serial.println("taotaottttttttttttttttttttttttttttttttttttttttttttttttt");
			return this;
		}

		ame::TimeControl* ame::SimpleTimer::setPeriod(long timeperiod){
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

		ame::TimeControl* ame::SimpleTimer::attachInterrupt(){
			TIMSK1 = _BV(TOIE1);                                     // sets the timer overflow interrupt enable bit
			// might be running with interrupts disabled (eg inside an ISR), so don't touch the global state
			//  sei();
			resumeInterrupt();	
			return this;											
		}

		ame::TimeControl* ame::SimpleTimer::detachInterrupt(){
			TIMSK1 &= ~_BV(TOIE1);                                   // clears the timer overflow interrupt enable bit 
																	// timer continues to count without calling the isr
			return this;
		}

		ame::TimeControl* ame::SimpleTimer::startInterrupt(){
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

		ame::TimeControl* ame::SimpleTimer::stopInterrupt(){
			TCCR1B &= ~(_BV(CS10) | _BV(CS11) | _BV(CS12));          // clears all clock selects bits
			return this;
		}

		ame::TimeControl* ame::SimpleTimer::resumeInterrupt(){ 
			TCCR1B |= clockSelectBits;
			return this;
		}
		

	#elif defined(ARDUINO_ARCH_SAM)
		
		ame::SimpleTimer::SimpleTimer(){
			this->timeList = new PrimitiveList<TimeElapsed>();
			Serial.println("ARDUINO_ARCH_SAM");
		}
		
		ame::SimpleTimer::~SimpleTimer(){
			delete this->timeList;
			this->timeList = nullptr;
		}
		
	  // SAM-specific code
	#elif defined(ARDUINO_ARCH_ESP8266)
		
		void ICACHE_RAM_ATTR onTime() {
			for(int x = 0; x < ((ame::SimpleTimer*)ame::SimpleTimer::getInstance())->timeList->getPosition(); x++){
				((ame::SimpleTimer*)ame::SimpleTimer::getInstance())->timeList->getByPosition(x)->Play(ame::SimpleTimer::getInstance());
			}
			((ame::SimpleTimer*)ame::SimpleTimer::getInstance())->time+=1;
		}
		
		ame::SimpleTimer::SimpleTimer(){
			this->timeList = new PrimitiveList<TimeElapsed>();
			Serial.println("ARDUINO_ARCH_ESP8266");
		}
		
		ame::SimpleTimer::~SimpleTimer(){
			delete this->timeList;
			this->timeList = nullptr;
		}

		ame::TimeControl* ame::SimpleTimer::initialize(long timeperiod){
			timer1_isr_init();
			setPeriod(timeperiod);
			return this;
		}

		ame::TimeControl* ame::SimpleTimer::setPeriod(long timeperiod){
			//timer1_write(100000000);//5 ticks per us from TIM_DIV16
			//timer1_write((long)((timeperiod) * 80));//5 ticks per us from TIM_DIV1
			//timer1_write((long)((timeperiod) * 5));//5 ticks per us from TIM_DIV16
			timer1_write((long)((timeperiod) * 0.312500f));//1 ticks per 3.2us from TIM_DIV256
			// Arm the Timer for our 0.5s Interval
			//timer1_write(2500000); // 2500000 / 5 ticks per us from TIM_DIV16 == 500,000 us interval 	
			//Set up ESP watchdog
			// ESP.wdtDisable();
			// ESP.wdtEnable(WDTO_8S);
			return this;
		}

		ame::TimeControl* ame::SimpleTimer::attachInterrupt(){
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

		ame::TimeControl* ame::SimpleTimer::detachInterrupt(){
			
			return this;
		}

		ame::TimeControl* ame::SimpleTimer::startInterrupt(){
			
			return this;
		}

		ame::TimeControl* ame::SimpleTimer::stopInterrupt(){
			
			return this;
		}

		ame::TimeControl* ame::SimpleTimer::resumeInterrupt(){ 
		
			return this;
		}
	//esp32
	#elif defined(ARDUINO_ESP32_DEV)

		void IRAM_ATTR onTime(){
			for(int x = 0; x < ((ame::SimpleTimer*)ame::SimpleTimer::getInstance())->timeList->getPosition(); x++){
				((ame::SimpleTimer*)ame::SimpleTimer::getInstance())->timeList->getByPosition(x)->Play(ame::SimpleTimer::getInstance());
			}
			((ame::SimpleTimer*)ame::SimpleTimer::getInstance())->time+=1;
		}
		
		ame::SimpleTimer::SimpleTimer(){
			this->timeList = new PrimitiveList<TimeElapsed>();
			timer = timerBegin(0, 80, true);  
			Serial.println("ARDUINO_ESP32_DEV");
		}
		
		ame::SimpleTimer::~SimpleTimer(){
			delete this->timeList;
			this->timeList = nullptr;
		}
		
		ame::TimeControl* ame::SimpleTimer::initialize(long timeperiod){
			
			setPeriod(timeperiod);
			return this;
		}

		ame::TimeControl* ame::SimpleTimer::setPeriod(long timeperiod){//microseconds
			//12.5ns *80 = 1000ns = 1 us             
			if(timer == nullptr){
				return this;
			}
			timerAlarmWrite(timer, timeperiod, true);           
			timerAlarmEnable(timer);
			return this;
		}

		ame::TimeControl* ame::SimpleTimer::attachInterrupt(){
			if(timer == nullptr){
				return this;
			}
			timerAttachInterrupt(timer, &onTime, true);   
			return this;
		}

		ame::TimeControl* ame::SimpleTimer::detachInterrupt(){
			
			return this;
		}

		ame::TimeControl* ame::SimpleTimer::startInterrupt(){
			
			return this;
		}

		ame::TimeControl* ame::SimpleTimer::stopInterrupt(){
			
			return this;
		}

		ame::TimeControl* ame::SimpleTimer::resumeInterrupt(){
			
			return this;
		}
	//feather m0
	#elif defined(ARDUINO_SAMD_ZERO)

		
		ame::SimpleTimer::SimpleTimer(){
			this->timeList = new PrimitiveList<TimeElapsed>();
			Serial.println("ARDUINO_SAMD_ZERO");
		}
		
		ame::SimpleTimer::~SimpleTimer(){
			delete this->timeList;
			this->timeList = nullptr;
		}
		
		ame::TimeControl* ame::SimpleTimer::initialize(long timeperiod){
			
			setPeriod(timeperiod);
			return this;
		}

		ame::TimeControl* ame::SimpleTimer::setPeriod(long timeperiod){
			return this;
		}

		ame::TimeControl* ame::SimpleTimer::attachInterrupt(){
			
			return this;
		}

		ame::TimeControl* ame::SimpleTimer::detachInterrupt(){
			
			return this;
		}

		ame::TimeControl* ame::SimpleTimer::startInterrupt(){
			
			return this;
		}

		ame::TimeControl* ame::SimpleTimer::stopInterrupt(){
			
			return this;
		}

		ame::TimeControl* ame::SimpleTimer::resumeInterrupt(){ 
		
			return this;
		}
	#else

		
		ame::SimpleTimer::SimpleTimer(){
			this->timeList = new PrimitiveList<TimeElapsed>();
			Serial.println("else");
		}
		
		ame::SimpleTimer::~SimpleTimer(){
			delete this->timeList;
			this->timeList = nullptr;
		}
		
		ame::TimeControl* ame::SimpleTimer::initialize(long timeperiod){
			
			setPeriod(timeperiod);
			return this;
		}

		ame::TimeControl* ame::SimpleTimer::setPeriod(long timeperiod){
			return this;
		}

		ame::TimeControl* ame::SimpleTimer::attachInterrupt(){
			
			return this;
		}

		ame::TimeControl* ame::SimpleTimer::detachInterrupt(){
			
			return this;
		}

		ame::TimeControl* ame::SimpleTimer::startInterrupt(){
			
			return this;
		}

		ame::TimeControl* ame::SimpleTimer::stopInterrupt(){
			
			return this;
		}

		ame::TimeControl* ame::SimpleTimer::resumeInterrupt(){ 
		
			return this;
		}
	#endif
		
		String ame::SimpleTimer::toString() {
			return "SimpleTimer";
		}
		
		ame::cppObjectClass* ame::SimpleTimer::getClass() {
			return ame::Class<ame::SimpleTimer>::classType;
		}
		

	#endif
