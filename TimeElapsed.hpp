
#ifndef TimeElapsed_hpp
#define TimeElapsed_hpp
#define TimeElapsed_AVAILABLE

namespace ame{

class TimeElapsed {
    public:
		virtual ~TimeElapsed(){}
		virtual void Play(TimeControl *t){}
		virtual void operator=(TimeElapsed a){}
		virtual bool operator==(TimeElapsed a){
				return true;
		}
		virtual bool operator!=(TimeElapsed a){
				return true;
		}
	private:	
};

}

#endif