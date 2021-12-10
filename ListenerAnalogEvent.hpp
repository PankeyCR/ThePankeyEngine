

#ifndef ListenerAnalogEvent_hpp
#define ListenerAnalogEvent_hpp

namespace ame{

class ListenerAnalogEvent{
    public:
		ListenerAnalogEvent(){}
		virtual ~ListenerAnalogEvent(){}
		
		virtual void event(int interrupt, float value, float tpc){}
		
		virtual void operator=(ListenerAnalogEvent b){}
		virtual bool operator==(ListenerAnalogEvent b){return true;}
		virtual bool operator!=(ListenerAnalogEvent b){return true;}
	protected:
};

}

#endif 
