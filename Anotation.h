

#ifndef Anotation_h
#define Anotation_h

#define invoke(cls,anott,pt) iterate(cls->getMethodAnotations()){ if(cls->getMethodAnotations()->getValue() == anott){( cls->**cls->getMethodAnotations()->getKeyPointer())(pt);}}

#define parameter2(p1,p2) p1,p2
#define parameter3(p1,p2,p3) p1,p2,p3
#define parameter4(p1,p2,p3,p4) p1,p2,p3,p4
#define parameter5(p1,p2,p3,p4,p5) p1,p2,p3,p4,p5
#define parameter6(p1,p2,p3,p4,p5,p6) p1,p2,p3,p4,p5,p6
#define parameter7(p1,p2,p3,p4,p5,p6,p7) p1,p2,p3,p4,p5,p6,p7


#include "Map.h"
#include "List.h"

template<class T,class A>
class Anotation {
	public:
		virtual List<A>* getClassAnotations();
		virtual Map<T,A>* getMethodAnotations();
	private:
};

#endif 
