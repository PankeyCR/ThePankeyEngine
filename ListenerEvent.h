

#ifndef ListenerEvent_h
#define ListenerEvent_h

class ListenerEvent{
    public:
		ListenerEvent(){}
		virtual ~ListenerEvent(){}
		
		virtual void event(int interrupt, int pin, bool state){}
		
		virtual void operator=(ListenerEvent b){}
		virtual bool operator==(ListenerEvent b){return true;}
		virtual bool operator!=(ListenerEvent b){return true;}
	protected:
};

#endif 
