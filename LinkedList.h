
#ifndef LinkedList_h
#define LinkedList_h

#include "LinkedListNode.h"
#include "List.h"

template<class T>
class LinkedList : public List<T>{
	private:
		int pos;
		int size;
    public:
		
		LinkedListNode<T>* start = nullptr;
		LinkedListNode<T>* node = nullptr;
		LinkedListNode<T>* iteratorNode = nullptr;
		
		LinkedList<T>(){
			start = new LinkedListNode<T>();
			node = start;
			pos=0;
			size=0;
		}
		
		~LinkedList<T>(){
			LinkedListNode<T>* n = start;
			LinkedListNode<T>* nn = nullptr;
			for(int x=0; x < size+1; x++){
				if(n->next != nullptr){
					nn = n->next;
				}
				if(n != nullptr){
					n->last = nullptr;
					delete n;
				}
				if(nn != nullptr){
					n = nn;
				}
			}
			start = nullptr;
			node = nullptr;
		}
		
		void setPos(int p){
			pos=p;
		}
		
		int getPos(){
			return pos;
		}
		
		int getSize(){
			return size;
		}
		
		void add(List<T> *list){
            if(list == nullptr){
				return;
            }
			for(int x=0; x<list->getPos();x++){
				this->add(list->getByPos(x));
			}
		}
		
		void add(T *value){
			node->actual = value;
			LinkedListNode<T>* n;
			if(node->next == nullptr){
				n = new LinkedListNode<T>();
				node->next = n;
				n->last = node;
				node = n;
			}else{
				n = node->next;
				n->last = node;
				node = n;
			}
			pos++;
			size++;
		}
		
		void add(T value){
			node->actual = new T();
			*node->actual = value;
			LinkedListNode<T>* n;
			if(node->next == nullptr){
				n = new LinkedListNode<T>();
				node->next = n;
				n->last = node;
				node = n;
			}else{
				n = node->next;
				n->last = node;
				node = n;
			}
			pos++;
			size++;
		}
		
		void set(int posIn,T value){
			LinkedListNode<T>* n = start;
			LinkedListNode<T>* nn = nullptr;
			for(int x=0; x<size; x++){
				if(x == posIn){
					*n->actual = value;
				}
				if(n->next != nullptr){
					nn = n->next;
					n = nn;
				}
			}
		}
		
		void set(int posIn,T *value){
			LinkedListNode<T>* n = start;
			LinkedListNode<T>* nn = nullptr;
			for(int x=0; x<size; x++){
				if(x == posIn){
					n->actual = value;
				}
				if(n->next != nullptr){
					nn = n->next;
					n = nn;
				}
			}
		}
		
		T *get(T *key){
			LinkedListNode<T>* n = start;
			LinkedListNode<T>* nn = nullptr;
			for(int x=0; x<size; x++){
				if(key == n->actual){
					return n->actual;
				}
				if(n->next != nullptr){
					nn = n->next;
					n = nn;
				}
			}
			return nullptr;
		}
		
		T *get(T key){
			LinkedListNode<T>* n = start;
			LinkedListNode<T>* nn = nullptr;
			for(int x=0; x<size; x++){
				if(key == *n->actual){
					return n->actual;
				}
				if(n->next != nullptr){
					nn = n->next;
					n = nn;
				}
			}
			return nullptr;
		}
		
		T *getByPos(int p){
			if(p >= size){
				return nullptr;
			}
			LinkedListNode<T>* n = start;
			LinkedListNode<T>* nn = nullptr;
			for(int x=0; x<size; x++){
				if(x == p){
					return n->actual;
				}
				if(n->next != nullptr){
					nn = n->next;
					n = nn;
				}
			}
			return nullptr;
		}
		
		bool contain(T *key){
			LinkedListNode<T>* n = start;
			LinkedListNode<T>* nn = nullptr;
			for(int x=0; x<size; x++){
				if(key == n->actual){
					return true;
				}
				if(n->next != nullptr){
					nn = n->next;
					n = nn;
				}
			}
			return false;
		}
		
		bool contain(T key){
			LinkedListNode<T>* n = start;
			LinkedListNode<T>* nn = nullptr;
			for(int x=0; x<size; x++){
				if(key == *n->actual){
					return true;
				}
				if(n->next != nullptr){
					nn = n->next;
					n = nn;
				}
			}
			return false;
		}
		
		void reset(){
			pos=0;
			size = 0;
			node = start;
		}
		
		void resetDelete(){
			LinkedListNode<T>* n = start;
			LinkedListNode<T>* nn = nullptr;
			for(int x=0; x<size; x++){
				if(n->next != nullptr){
					nn = n->next;
				}
				if(n != nullptr){
					delete n;
				}
				if(nn != nullptr){
					n = nn;
				}
			}
			start = new LinkedListNode<T>();
			node = start;
			pos = 0;
			size = 0;
		}
		
		T *remove(T *key){
			LinkedListNode<T>* n = start;
			LinkedListNode<T>* nn = nullptr;
			for(int x=0; x<size; x++){
				if(key == n->actual){
					LinkedListNode<T>* lst = n->last;
					LinkedListNode<T>* nxt = n->next;
					lst->next = nxt;
					nxt->last = lst;
					return n->actual;
				}
				if(n->next != nullptr){
					nn = n->next;
					n = nn;
				}
			}
		}
		
		T *remove(T key){
			LinkedListNode<T>* n = start;
			LinkedListNode<T>* nn = nullptr;
			for(int x=0; x<size; x++){
				if(key == *n->actual){
					LinkedListNode<T>* lst = n->last;
					LinkedListNode<T>* nxt = n->next;
					lst->next = nxt;
					nxt->last = lst;
					return n->actual;
				}
				if(n->next != nullptr){
					nn = n->next;
					n = nn;
				}
			}
		}
		
		T *removeByPos(int p){
			LinkedListNode<T>* n = start;
			LinkedListNode<T>* nn = nullptr;
			for(int x=0; x<size; x++){
				if(x == p){
					LinkedListNode<T>* lst = n->last;
					LinkedListNode<T>* nxt = n->next;
					lst->next = nxt;
					nxt->last = lst;
					return n->actual;
				}
				if(n->next != nullptr){
					nn = n->next;
					n = nn;
				}
			}
		}
	
		void removeDelete(T *key){
			LinkedListNode<T>* n = start;
			LinkedListNode<T>* nn = nullptr;
			for(int x=0; x<size; x++){
				if(key == n->actual){
					LinkedListNode<T>* lst = n->last;
					LinkedListNode<T>* nxt = n->next;
					delete n;
					lst->next = nxt;
					nxt->last = lst;
					return;
				}
				if(n->next != nullptr){
					nn = n->next;
					n = nn;
				}
			}
		}
	
		void removeDelete(T key){
			LinkedListNode<T>* n = start;
			LinkedListNode<T>* nn = nullptr;
			for(int x=0; x<size; x++){
				if(key == *n->actual){
					LinkedListNode<T>* lst = n->last;
					LinkedListNode<T>* nxt = n->next;
					delete n;
					lst->next = nxt;
					nxt->last = lst;
					return;
				}
				if(n->next != nullptr){
					nn = n->next;
					n = nn;
				}
			}
		}
		
		void removeDeleteByPos(int p){
			LinkedListNode<T>* n = start;
			LinkedListNode<T>* nn = nullptr;
			for(int x=0; x<size; x++){
				if(x == p){
					LinkedListNode<T>* lst = n->last;
					LinkedListNode<T>* nxt = n->next;
					delete n;
					lst->next = nxt;
					nxt->last = lst;
					return;
				}
				if(n->next != nullptr){
					nn = n->next;
					n = nn;
				}
			}
		}
	
		void onDelete(){
			LinkedListNode<T>* n = start;
			LinkedListNode<T>* nn = nullptr;
			for(int x=0; x<size; x++){
				if(n->next != nullptr){
					nn = n->next;
				}
				if(n != nullptr){
					delete n;
				}
				if(nn != nullptr){
					n = nn;
				}
			}
			start = new LinkedListNode<T>();
			node = start;
		}
		
		String getClassName(){
			return "LinkedList";
		}
		void setIteration(int iter){
			this->iterateCount = iter;
			
			LinkedListNode<T>* n = start;
			LinkedListNode<T>* nn = nullptr;
			for(int x=0; x<size; x++){
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
		
		int getIterationSize(){
			return size;
		}
		
		void last(){
			LinkedListNode<T>* lst = iteratorNode->last;
			iteratorNode = lst;
			this->iterateCount--;
		}
		
		void next(){
			LinkedListNode<T>* nxt = iteratorNode->next;
			iteratorNode = nxt;
			this->iterateCount++;
		}
		
		T getValue(){
			return *iteratorNode->actual;
		}
		
		T *getPointer(){
			return iteratorNode->actual;
		}
		
		LinkedList<T>* clone(){
			LinkedList<T>* l = new LinkedList<T>();
			LinkedListNode<T>* n = start;
			LinkedListNode<T>* nn = nullptr;
			for(int x=0; x<size; x++){
				l->add(*n->actual);
				if(n->next != nullptr){
					nn = n->next;
					n = nn;
				}
			}
			return l;
		}
		
        void operator =(LinkedList<T> t){
			
		}
		
        bool operator ==(LinkedList<T> t){
			return this->getClassName() == t.getClassName();
		}
		
        bool operator !=(LinkedList<T> t){
			return this->getClassName() != t.getClassName();
		}
};

#endif 
