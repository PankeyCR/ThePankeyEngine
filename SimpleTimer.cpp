
#ifndef SimpleTimer_cpp
#define SimpleTimer_cpp

#include "SimpleTimer.h"

TimeControl* SimpleTimer::instance = nullptr;

	ISR(TIMER1_OVF_vect){
		iterate(((SimpleTimer*)SimpleTimer::getInstance())->timeList){
			((SimpleTimer*)SimpleTimer::getInstance())->timeList->getPointer()->Play(SimpleTimer::getInstance());
		}
	}
	TimeControl *SimpleTimer::getInstance(){
		if (instance == nullptr){
			instance = new SimpleTimer();
		}
		return instance;
	}
	
	SimpleTimer::SimpleTimer(){
		this->time = new MonkeyTime();
		this->timeList = new PList<TimeElapsed,10>();
	}
	
	SimpleTimer::~SimpleTimer(){
		delete this->time;
		this->timeList->onDelete();
		delete this->timeList;
	}

	void SimpleTimer::initialize(long microseconds){
		TCCR1A = 0;
		TCCR1B = _BV(WGM13);
		setPeriod(microseconds);
	}

	void SimpleTimer::setPeriod(long microseconds){
		long cycles = (F_CPU / 2000000) * microseconds;                                // the counter runs backwards after TOP, interrupt is at BOTTOM so divide microseconds by 2
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
	}

	void SimpleTimer::attachInterrupt(){
		TIMSK1 = _BV(TOIE1);                                     // sets the timer overflow interrupt enable bit
		// might be running with interrupts disabled (eg inside an ISR), so don't touch the global state
		//  sei();
		resumeInterrupt();												
	}

	void SimpleTimer::detachInterrupt(){
		TIMSK1 &= ~_BV(TOIE1);                                   // clears the timer overflow interrupt enable bit 
																// timer continues to count without calling the isr
	}

	void SimpleTimer::startInterrupt(){
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
	}

	void SimpleTimer::stopInterrupt(){
		TCCR1B &= ~(_BV(CS10) | _BV(CS11) | _BV(CS12));          // clears all clock selects bits
	}

	void SimpleTimer::resumeInterrupt(){ 
		TCCR1B |= clockSelectBits;
	}
	
	TimeElapsed *SimpleTimer::add(TimeElapsed *t){
		this->timeList->add(t);
		return t;
	}
	
	TimeElapsed *SimpleTimer::remove(TimeElapsed *t){
		return this->timeList->remove(t);
	}
	
	TimeElapsed *SimpleTimer::removeByPos(int pos){
		return this->timeList->removeByPos(pos);
	}
		
	List<TimeElapsed> *SimpleTimer::getTimeElapsedList(){
		return this->timeList;
	}
	
	TimeElapsed *SimpleTimer::getTimeElapsed(int pos){
		return this->timeList->getByPos(pos);
	}
	
	TimeElapsed *SimpleTimer::getTimeElapsed(TimeElapsed *t){
		return this->timeList->get(t);
	}
	
	String SimpleTimer::toString() {
		return "SimpleTimer";
	}
	
	String SimpleTimer::getClassName() {
		return "SimpleTimer";
	}
	

#endif
