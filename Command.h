
#ifndef Command_h
#define Command_h

template<class C>
class Command {
    private:
	
    public:
		virtual void execute(C c)=0;
};
#endif 
