
#ifndef iterateFor

#define iterateFor

#define iterate(list) for(list->setIteration(0) ; list->getIteration() < list->getIterationSize(); list->next())
#define iterateN(list) for(list->setIteration(list->getIterationSize()-1) ; list->getIteration() >= 0; list->last())

#define iterateLength(list,start,end) for(list->setIteration(start) ; list->getIteration() < end; list->next())
#define iterateNLength(list,start,end) for(list->setIteration(start-1) ; list->getIteration() >= end; list->last())

#define iterateV(list) for(list.setIteration(0) ; list.getIteration() < list.getIterationSize(); list.next())
#define iterateVN(list) for(list.setIteration(list.getIterationSize()-1) ; list.getIteration() >= 0; list.last())

#define iterateVLength(list,start,end) for(list.setIteration(start) ; list.getIteration() < end; list.next())
#define iterateVNLength(list,start,end) for(list.setIteration(start-1) ; list.getIteration() >= end; list.last())

#define fun(method) {IteratorFuntion funtion = method;funtion();}

#endif


#ifndef Iterator_h
#define Iterator_h

typedef void (*IteratorFuntion)();

class Iterator{
	public:
		Iterator();
		virtual ~Iterator();
		virtual void setIteration(int iter);
		virtual int getIteration();
		virtual int getIterationSize();
		virtual void last();
		virtual void next();
	protected:
		int iterateCount = 0;
};

#endif 
