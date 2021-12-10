
#ifndef GridIncrementor_hpp
#define GridIncrementor_hpp
/*
#include "cppObject.hpp"
#include "Order.hpp"
#include "Position.hpp"

template<class T, class... args>
class GridIncrementor : public cppObject{
public:
GridIncrementor(){}
GridIncrementor(const Order<T,args...>& o){
	order = o;
}
virtual ~GridIncrementor(){}

virtual void setOrder(Order<T,args...> o){
	order = o;
}
virtual Order<T,args..> getOrder(){
	return order;
}

virtual void setPosition(Position pos);
virtual void setPosition(int... pos);
virtual int getPosition(int array,FixVector vec);
virtual int getPosition(FixVector vec);
virtual Position getPosition();

virtual void setSize(int... size);
virtual int getSize(FixVector vec);

virtual int getAbsolutePosition();
virtual int getAbsoluteSize();

virtual void increment();
virtual void decrement();
virtual void resetAll();
virtual void resetPosition();
virtual void resetAbsolutePosition();

protected:
Order<T,args...> order;
};
*/
#endif