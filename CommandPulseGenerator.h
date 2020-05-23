
#ifndef CommandPulseGenerator_h
#define CommandPulseGenerator_h

#include "TimeControl.h"
#include "MonkeyTime.h"

class CommandPulseGenerator : public TimeElapsed, public Command<int>{
    public:
		CommandPulseGenerator();
		virtual ~CommandPulseGenerator();
		
		virtual void Play(TimeControl *t);
		virtual void setPulseTime(long t);
		virtual long getPulseTime();
		virtual MonkeyTime* getMonkeyTime();
		virtual void setCommand(Command<CommandPulseGenerator>* cmd);
		virtual void enable(bool e);
		
	protected:
		Command<CommandPulseGenerator>* command = nullptr;
		MonkeyTime *timer;
		long timepulse = 0;
		long newtimepulse = 0;
		bool en = true;
};

#endif 
