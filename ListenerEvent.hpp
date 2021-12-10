

#ifndef ListenerEvent_hpp
#define ListenerEvent_hpp

namespace ame{

class ListenerEvent{
    public:
		ListenerEvent(){}
		virtual ~ListenerEvent(){}
		virtual void enable(){enable_m = true;}
		virtual void disable(){enable_m = false;}
		virtual bool isEnable(){return enable_m;}
		
		virtual void event(int interrupt, long milli, bool state){}
		
		virtual void operator=(ListenerEvent b){}
		virtual bool operator==(ListenerEvent b){return true;}
		virtual bool operator!=(ListenerEvent b){return true;}
	protected:
		bool enable_m = true;
};

}

#endif 
