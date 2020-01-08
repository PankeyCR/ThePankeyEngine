

#ifndef TimeElapsed_h
#define TimeElapsed_h

class TimeControl;

class TimeElapsed {
    public:
		virtual void Play(TimeControl *t);
		virtual void operator=(TimeElapsed a);
		virtual bool operator==(TimeElapsed a);
		virtual bool operator!=(TimeElapsed a);
	private:	
};

#endif 
