


#ifndef LinkedIterator_h
#define LinkedIterator_h
/*
#include "Arduino.h"
#include "LinkedListNode.h"
#include "LinkedList.h"
#include "Iterator.h"

template<class T>
class LinkedIterator{
// class LinkedIterator : public Iterator{
	public:
	
		LinkedIterator(LinkedIterator* i){
			this->iR = i;
			this->iterateCount = 0;
			this->iterateSize = i->iterateSize;
		}
		LinkedIterator(LinkedListNode<T>* i, int count, int size){
			iteratorNode = i;
			start = i;
			this->iterateCount = count;
			this->iterateSize = size;
		}
		LinkedIterator(const LinkedIterator<T>& i){
			iteratorNode = i.iteratorNode;
			start = i.iteratorNode;
		}
		LinkedIterator(const LinkedList<T>& i){
			iteratorNode = i.start;
			start = i.start;
			this->iterateCount = 0;
			this->iterateSize = i.getSize();
		}
		virtual ~LinkedIterator(){}
		
		virtual void setIteration(int iter){
			this->iterateCount = iter;
			
			LinkedListNode<T>* n = iteratorNode;
			LinkedListNode<T>* nn = nullptr;
			for(int x = 0; x < this->iterateSize; x++){
				if(x == iter){
					iteratorNode = n;
					return;
				}
				if(n->next != nullptr){
					nn = n->next;
					n = nn;
				}
			}
		}
		
		virtual bool last(){
			if(Iterator::last()){
				LinkedListNode<T>* lst = iteratorNode->last;
				iteratorNode = lst;
				return true;
			}
			return false;
		}
		
		virtual bool next(){
			if(Iterator::next()){
				LinkedListNode<T>* nxt = iteratorNode->next;
				iteratorNode = nxt;
				return true;
			}
			return false;
		}
		
		virtual LinkedIterator<T> begin(){
			return LinkedIterator<T>(this);
		}
		virtual LinkedIterator<T> end(){
			return LinkedIterator<T>(this);
		}
		virtual LinkedIterator<T> operator *(){
			return LinkedIterator<T>(this->getIteration(),this->getIterationSize());
		}
	
		void operator ++(){
			this->next();
		}
		
		bool operator !=(LinkedIterator<T> i){
			if(this->getIteration() < i.getIterationSize()){
				return true;
			}
			return false;
		}
		virtual LinkedIterator<T>& operator =(const LinkedIterator<T>& i){
			this->iR = i.iR;
			this->iterateCount = i.iterateCount;
			this->iterateSize = i.iterateSize;
			return *this;
		}
		
		virtual T getLValue(){
			return *iteratorNode->actual;
		}
		virtual T* getPointer(){
			return iteratorNode->actual;
		}
		virtual void setLValue(T t){
			*iteratorNode->actual = t;
		}
		virtual void setPointer(T* t){
			iteratorNode->actual = t;
		}
	protected:
		LinkedListNode<T>* start = nullptr;
		LinkedListNode<T>* iteratorNode = nullptr;
		int iterateCount = 0;
		int iterateSize = 0;
		Iterator* iR = nullptr;
};*/

#endif 
