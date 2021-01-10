
#ifndef LinkedList_h
#define LinkedList_h

#include "LinkedListNode.h"
#include "List.h"

template<class T>
class LinkedList : public List<T>{
	protected:
		int pos;
		int size;
		bool owner = true;
    public:
		
		LinkedListNode<T>* start = nullptr;
		LinkedListNode<T>* node = nullptr;
		// LinkedListNode<T>* iteratorNode = nullptr;
		
		LinkedList<T>(){
			start = new LinkedListNode<T>();
			node = start;
			pos=0;
			size=0;
		}
		
		LinkedList<T>(bool own){
			start = new LinkedListNode<T>();
			node = start;
			pos=0;
			size=0;
			owner=own;
		}
		
		~LinkedList<T>(){
			LinkedListNode<T>* n = start;
			LinkedListNode<T>* nn = nullptr;
			for(int x=0; x < size+1; x++){
				if(n->next != nullptr){
					nn = n->next;
					n->next = nullptr;
				}
				if(n != nullptr){
					n->last = nullptr;
					if(n->actual != nullptr && owner){
						delete n->actual;
					}
					delete n;
				}
				if(nn != nullptr){
					n = nn;
				}
			}
			start = nullptr;
			node = nullptr;
		}

		bool isEmpty(){
			return pos==0;
		}
		
		void setPosition(int p){
			pos=p;
		}
		
		int getPosition(){
			return pos;
		}
		
		int getSize(){
			return size;
		}
		
		void addList(List<T> *list){
            if(list == nullptr){
				return;
            }
			for(int x=0; x<list->getPosition();x++){
				this->addPointer(list->getByPosition(x));
			}
		}
	
		template<class... args>
		void addPack(args... x){
			T array[] = {x...};
			//for(const T &a : array){
			for(T a : array){
				addLValue(a);
			}
		}
		
		template<class... Args>
		T* addParameters(Args... args){
			node->actual = new T(args...);
			LinkedListNode<T>* n;
			T* rturn =  node->actual;
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
			return rturn;
		}
		
		T* addPointer(T* value){
			if(value == nullptr){
				return nullptr;
			}
			node->actual = value;
			LinkedListNode<T>* n;
			T* rturn =  value;
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
			return rturn;
		}
		
		T* addLValue(T value){
			node->actual = new T();
			*node->actual = value;
			LinkedListNode<T>* n;
			T* rturn =  node->actual;
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
			return rturn;
		}
		
		T* setLValue(int position,T value){
			LinkedListNode<T>* n = start;
			LinkedListNode<T>* nn = nullptr;
			for(int x=0; x<size; x++){
				if(x == position){
					if(n->actual == nullptr){
						n->actual = new T();
					}
					*n->actual = value;
					return n->actual;
				}
				if(n->next != nullptr){
					nn = n->next;
					n = nn;
				}
			}
			return nullptr;
		}
		
		T* setPointer(int position, T* value){
			if(value == nullptr){
				return nullptr;
			}
			LinkedListNode<T>* n = start;
			LinkedListNode<T>* nn = nullptr;
			for(int x=0; x<size; x++){
				if(x == position){
					if(n->actual != nullptr && n->actual != value){
						delete n->actual;
					}
					n->actual = value;
				}
				if(n->next != nullptr){
					nn = n->next;
					n = nn;
				}
			}
			return nullptr;
		}
		
		T* insertLValue(int position, T value){
            if(position >= size){
				return nullptr;
            }
            if(position >= pos+1){
				return nullptr;
            }
			T* nVaule;
			T* rVaule = new T();
			*rVaule = value;
			T* rturn = rVaule;
			LinkedListNode<T>* n = start;
			LinkedListNode<T>* nn = nullptr;
			for(int x=0; x<= pos; x++){
				if(x >= position){
					nVaule = n->actual;
					n->actual = rVaule;
					rVaule = nVaule;
				}
				if(n->next != nullptr){
					nn = n->next;
					n = nn;
				}
			}
			LinkedListNode<T>* adding = new LinkedListNode<T>();
			node->next = adding;
			adding->last = node;
			node = adding;
			size++;
			pos++;
			return rturn;
		}
		
		T* insertPointer(int position, T* value){
            if(value == nullptr){
				return nullptr;
            }
            if(position >= size){
				return nullptr;
            }
            if(position >= pos+1){
				return nullptr;
            }
			T* nVaule;
			T* rVaule = value;
			LinkedListNode<T>* n = start;
			LinkedListNode<T>* nn = nullptr;
			for(int x=0; x<= pos; x++){
				if(x == position && n->actual == value){
					return value;
				}
				if(x >= position){
					nVaule = n->actual;
					n->actual = rVaule;
					rVaule = nVaule;
				}
				if(n->next != nullptr){
					nn = n->next;
					n = nn;
				}
			}
			LinkedListNode<T>* adding = new LinkedListNode<T>();
			node->next = adding;
			adding->last = node;
			node = adding;
			size++;
			pos++;
			return value;
		}
		
		T *getByPointer(T* key){
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
		
		T* getByLValue(T key){
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
		
		T* getByPosition(int p){
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
		
		bool containByPointer(T* key){
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
		
		bool containByLValue(T key){
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
		
		int getIndexByPointer(T* key){
			LinkedListNode<T>* n = start;
			LinkedListNode<T>* nn = nullptr;
			for(int x=0; x<size; x++){
				if(key == n->actual){
					return x;
				}
				if(n->next != nullptr){
					nn = n->next;
					n = nn;
				}
			}
			return -1;
		}
		
		int getIndexByLValue(T key){
			LinkedListNode<T>* n = start;
			LinkedListNode<T>* nn = nullptr;
			for(int x=0; x<size; x++){
				if(key == *n->actual){
					return x;
				}
				if(n->next != nullptr){
					nn = n->next;
					n = nn;
				}
			}
			return -1;
		}
		
		void reset(){
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
		
		void resetDelete(){
			LinkedListNode<T>* n = start;
			LinkedListNode<T>* nn = nullptr;
			for(int x=0; x < size+1; x++){
				if(n->next != nullptr){
					nn = n->next;
				}
				if(n->actual != nullptr && owner){
					delete n->actual;
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
		
		T* removeByPointer(T* key){
			LinkedListNode<T>* n = start;
			LinkedListNode<T>* nn = nullptr;
			for(int x=0; x<size; x++){
				if(key == n->actual){
					LinkedListNode<T>* lst = n->last;
					LinkedListNode<T>* nxt = n->next;
					lst->next = nxt;
					nxt->last = lst;
					pos--;
					size--;
					return n->actual;
				}
				if(n->next != nullptr){
					nn = n->next;
					n = nn;
				}
			}
		}
		
		T* removeByLValue(T key){
			LinkedListNode<T>* n = start;
			LinkedListNode<T>* nn = nullptr;
			for(int x=0; x<size; x++){
				if(key == *n->actual){
					LinkedListNode<T>* lst = n->last;
					LinkedListNode<T>* nxt = n->next;
					lst->next = nxt;
					nxt->last = lst;
					pos--;
					size--;
					return n->actual;
				}
				if(n->next != nullptr){
					nn = n->next;
					n = nn;
				}
			}
		}
		
		T* removeByPosition(int p){
			LinkedListNode<T>* n = start;
			LinkedListNode<T>* nn = nullptr;
			for(int x=0; x<size; x++){
				if(x == p){
					LinkedListNode<T>* lst = n->last;
					LinkedListNode<T>* nxt = n->next;
					lst->next = nxt;
					nxt->last = lst;
					pos--;
					size--;
					return n->actual;
				}
				if(n->next != nullptr){
					nn = n->next;
					n = nn;
				}
			}
			return nullptr;
		}
	
		void removeDeleteByPointer(T* key){
			LinkedListNode<T>* n = start;
			LinkedListNode<T>* nn = nullptr;
			for(int x=0; x<size; x++){
				if(key == n->actual){
					LinkedListNode<T>* lst = n->last;
					LinkedListNode<T>* nxt = n->next;
					delete n;
					if(n->actual != nullptr && owner){
						delete n->actual;
					}
					lst->next = nxt;
					nxt->last = lst;
					pos--;
					size--;
					return;
				}
				if(n->next != nullptr){
					nn = n->next;
					n = nn;
				}
			}
		}
	
		void removeDeleteByLValue(T key){
			LinkedListNode<T>* n = start;
			LinkedListNode<T>* nn = nullptr;
			for(int x=0; x<size; x++){
				if(key == *n->actual){
					LinkedListNode<T>* lst = n->last;
					LinkedListNode<T>* nxt = n->next;
					delete n;
					if(n->actual != nullptr && owner){
						delete n->actual;
					}
					lst->next = nxt;
					nxt->last = lst;
					pos--;
					size--;
					return;
				}
				if(n->next != nullptr){
					nn = n->next;
					n = nn;
				}
			}
		}
		
		void removeDeleteByPosition(int p){
			LinkedListNode<T>* n = start;
			LinkedListNode<T>* nn = nullptr;
			for(int x=0; x<size; x++){
				if(x == p){
					LinkedListNode<T>* lst = n->last;
					LinkedListNode<T>* nxt = n->next;
					delete n;
					if(n->actual != nullptr && owner){
						delete n->actual;
					}
					lst->next = nxt;
					nxt->last = lst;
					pos--;
					size--;
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
				if(n->actual != nullptr && owner){
					delete n->actual;
				}
				if(nn != nullptr){
					n = nn;
				}
			}
			start = new LinkedListNode<T>();
			node = start;
		}
		
		T& operator[](int p){
			LinkedListNode<T>* n = start;
			LinkedListNode<T>* nn = nullptr;
			if(p > size && p > pos){
				return *start->actual;
			}
			if(p == size && p == pos){
				size++;
				pos++;
				nn = new LinkedListNode<T>();
				node->next = nn;
				nn->last = node;
				node = nn;
				if(node->last->actual == nullptr){
					node->last->actual = new T();
				}
				return *node->last->actual;
			}
			for(int x=0; x<size; x++){
				if(x == p){
					return *n->actual;
				}
				if(n->next != nullptr){
					nn = n->next;
					n = nn;
				}
			}
			return *start->actual;
		}
		
		String getClassName(){
			return "LinkedList";
		}
		
		// void setIteration(int iter){
			// this->iterateCount = iter;
			
			// LinkedListNode<T>* n = start;
			// LinkedListNode<T>* nn = nullptr;
			// for(int x=0; x<size; x++){
				// if(x == iter){
					// iteratorNode = n;
					// return;
				// }
				// if(n->next != nullptr){
					// nn = n->next;
					// n = nn;
				// }
			// }
		// }
		
		int getIterationSize(){
			return size;
		}
		
		// void last(){
			// LinkedListNode<T>* lst = iteratorNode->last;
			// iteratorNode = lst;
			// this->iterateCount--;
		// }
		
		// void next(){
			// LinkedListNode<T>* nxt = iteratorNode->next;
			// iteratorNode = nxt;
			// this->iterateCount++;
		// }
		
		T getLValue(Iterator iterate){
			return *this->getByPosition(iterate.getIteration());
			// return *iteratorNode->actual;
		}
		
		T *getPointer(Iterator iterate){
			return this->getByPosition(iterate.getIteration());
			// return iteratorNode->actual;
		}
		
		T* setLValue(Iterator iterate, T s){
			return this->setLValue(this->getIteration() , s);
		}
		
		T* setPointer(Iterator iterate, T* s){
			return this->setPointer(this->getIteration() , s);
		}
		
		T* insertLValue(Iterator& iterate, T s){
			int p = iterate.getIteration();
			iterate.next();
			return this->insertLValue(p , s);
		}
		
		T* insertPointer(Iterator& iterate, T* s){
			int p = iterate.getIteration();
			iterate.next();
			return this->insertPointer(p , s);
		}
		
		T* remove(Iterator& iterate){
			int p = iterate.getIteration();
			iterate.last();
			return this->removeByPosition(p);
		}
		
		void removeDelete(Iterator& iterate){
			int p = iterate.getIteration();
			iterate.last();
			this->removeDeleteByPosition(p);
		}
		
		LinkedList<T>* clone(){
			LinkedList<T>* l = new LinkedList<T>();
			LinkedListNode<T>* n = start;
			LinkedListNode<T>* nn = nullptr;
			for(int x=0; x<size; x++){
				l->addLValue(*n->actual);
				if(n->next != nullptr){
					nn = n->next;
					n = nn;
				}
			}
			return l;
		}
		
		LinkedList<T>* clone(bool owningMemory){
			LinkedList<T>* l = new LinkedList<T>(owningMemory);
			LinkedListNode<T>* n = start;
			LinkedListNode<T>* nn = nullptr;
			for(int x=0; x<size; x++){
				l->addLValue(*n->actual);
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
