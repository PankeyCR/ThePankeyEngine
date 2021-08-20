

#ifndef ThreadControl_h
#define ThreadControl_h

namespace ame{

class ThreadControl{
    public:
		ThreadControl(){}
		virtual ~ThreadControl(){}
		
		virtual void initialize(){}
		
		virtual void update(){}
};

}

#endif 
