
#ifndef LinkedList_h
#define LinkedList_h

#include "LinkedListNode.h"
#include "List.h"

template<class T>
class LinkedList : public List<T>{
	private:
		int pos;
		int size;
		bool owner = true;
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
	
		template<class... args>
		void addPack(args... x){
			T array[] = {x...};
			for(const T &a : array){
				add(a);
			}
		}
		
		template<class... Args>
		T* add(Args... args){
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
		
		T* add(T* value){
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
		
		T* add(T value){
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
		
		T* set(int position,T value){
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
		
		T* set(int position, T* value){
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
		
		T* insert(int position, T value){
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
		
		T* insert(int position, T* value){
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
		
		T *get(T* key){
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
		
		T* get(T key){
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
		
		T* getByPos(int p){
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
		
		bool contain(T* key){
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
			pos = 0;
			size = 0;
		}
		
		T* remove(T* key){
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
		
		T* remove(T key){
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
		
		T* removeByPos(int p){
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
	
		void removeDelete(T* key){
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
	
		void removeDelete(T key){
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
		
		void removeDeleteByPos(int p){
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
		
		T* set(T s){
			return this->set(this->getIteration() , s);
		}
		
		T* set(T* s){
			return this->set(this->getIteration() , s);
		}
		
		T* insert(T s){
			int p = this->iterateCount;
			this->next();
			return this->insert(p , s);
		}
		
		T* insert(T* s){
			int p = this->iterateCount;
			this->next();
			return this->insert(p , s);
		}
		
		T* remove(){
			int p = this->iterateCount;
			this->last();
			return this->removeByPos(p);
		}
		
		void removeDelete(){
			int p = this->iterateCount;
			this->last();
			this->removeDeleteByPos(p);
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
