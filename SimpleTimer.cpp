
#ifndef SimpleTimer_cpp
#define SimpleTimer_cpp

#include "SimpleTimer.h"

TimeControl* SimpleTimer::instance = nullptr;



	TimeControl *SimpleTimer::getInstance(){
		if (instance == nullptr){
			instance = new SimpleTimer();
		}
		return instance;
	}
	
	SimpleTimer::SimpleTimer(){
		this->timeList = new PrimitiveList<TimeElapsed>();
		Log("println","SimpleTimer: new instance of this class");
	}
	
	SimpleTimer::~SimpleTimer(){
		delete this->timeList;
		this->timeList = nullptr;
		Log("println","SimpleTimer: delete instance of this class");
	}
	
#if defined(ARDUINO_ARCH_AVR)
	ISR(TIMER1_OVF_vect){
		iterate(((SimpleTimer*)SimpleTimer::getInstance())->timeList){
			((SimpleTimer*)SimpleTimer::getInstance())->timeList->getPointer()->Play(SimpleTimer::getInstance());
		}
		((SimpleTimer*)SimpleTimer::getInstance())->time+=1;
	}

	TimeControl* SimpleTimer::initialize(long timeperiod){
		TCCR1A = 0;
		TCCR1B = _BV(WGM13);
		setPeriod(timeperiod);
		return this;
	}

	TimeControl* SimpleTimer::setPeriod(long timeperiod){
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
		TIMSK1 = _BV(TOIE1);                                     // sets the timer overflow interrupt enable bit
		// might be running with interrupts disabled (eg inside an ISR), so don't touch the global state
		//  sei();
		resumeInterrupt();	
		return this;											
	}

	TimeControl* SimpleTimer::detachInterrupt(){
		TIMSK1 &= ~_BV(TOIE1);                                   // clears the timer overflow interrupt enable bit 
																// timer continues to count without calling the isr
		return this;
	}

	TimeControl* SimpleTimer::startInterrupt(){
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
		TCCR1B &= ~(_BV(CS10) | _BV(CS11) | _BV(CS12));          // clears all clock selects bits
		return this;
	}

	TimeControl* SimpleTimer::resumeInterrupt(){ 
		TCCR1B |= clockSelectBits;
		return this;
	}
	

#elif defined(ARDUINO_ARCH_SAM)
  // SAM-specific code
#elif defined(ARDUINO_ARCH_ESP8266)
	
	void ICACHE_RAM_ATTR onTime() {
		iterate(((SimpleTimer*)SimpleTimer::getInstance())->timeList){
			((SimpleTimer*)SimpleTimer::getInstance())->timeList->getPointer()->Play(SimpleTimer::getInstance());
		}
		((SimpleTimer*)SimpleTimer::getInstance())->time+=1;
	}

	TimeControl* SimpleTimer::initialize(long timeperiod){
		timer1_isr_init();
		setPeriod(timeperiod);
		return this;
	}

	TimeControl* SimpleTimer::setPeriod(long timeperiod){
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

	TimeControl* SimpleTimer::attachInterrupt(){
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
		
		return this;
	}

	TimeControl* SimpleTimer::startInterrupt(){
		
		return this;
	}

	TimeControl* SimpleTimer::stopInterrupt(){
		
		return this;
	}

	TimeControl* SimpleTimer::resumeInterrupt(){ 
	
		return this;
	}
	
#elif defined(ARDUINO_SAMD_ZERO)

	TimeControl* SimpleTimer::initialize(long timeperiod){
		
		setPeriod(timeperiod);
		return this;
	}

	TimeControl* SimpleTimer::setPeriod(long timeperiod){
		return this;
	}

	TimeControl* SimpleTimer::attachInterrupt(){
		
		return this;
	}

	TimeControl* SimpleTimer::detachInterrupt(){
		
		return this;
	}

	TimeControl* SimpleTimer::startInterrupt(){
		
		return this;
	}

	TimeControl* SimpleTimer::stopInterrupt(){
		
		return this;
	}

	TimeControl* SimpleTimer::resumeInterrupt(){ 
	
		return this;
	}
#else

	TimeControl* SimpleTimer::initialize(long timeperiod){
		
		setPeriod(timeperiod);
		return this;
	}

	TimeControl* SimpleTimer::setPeriod(long timeperiod){
		return this;
	}

	TimeControl* SimpleTimer::attachInterrupt(){
		
		return this;
	}

	TimeControl* SimpleTimer::detachInterrupt(){
		
		return this;
	}

	TimeControl* SimpleTimer::startInterrupt(){
		
		return this;
	}

	TimeControl* SimpleTimer::stopInterrupt(){
		
		return this;
	}

	TimeControl* SimpleTimer::resumeInterrupt(){ 
	
		return this;
	}
#endif
	
	String SimpleTimer::toString() {
		return "SimpleTimer";
	}
	
	String SimpleTimer::getClassName() {
		return "SimpleTimer";
	}
	

#endif
