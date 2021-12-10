
#ifndef TimeElapsed_hpp
#define TimeElapsed_hpp

namespace ame{

class TimeControl;

class TimeElapsed {
    public:
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
