
#ifndef LinkedList_hpp
#define LinkedList_hpp

#include "LinkedListNode.hpp"
#include "cppObjectClass.hpp"
#include "LinkedIterator.hpp"
#include "List.hpp"

namespace ame{

template<class T>
class LinkedList : public List<T>{
	protected:
		int pos;
		int size;
		bool owner = true;
    public:
		
		LinkedListNode<T>* start = nullptr;
		LinkedListNode<T>* node = nullptr;
		
		LinkedList<T>(const LinkedList<T>& l){
			start = new LinkedListNode<T>();
			node = start;
			pos=0;
			size=0;
			for(int x=0; x < l.getPosition(); x++){
				this->addLValue(*l.getByPosition(x));
			}
		}
		
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

		bool isEmpty()const{
			return pos==0;
		}
		
		void setPosition(int p){
			pos=p;
		}
		
		int getPosition()const{
			return pos;
		}
		
		int getSize()const{
			return size;
		}
	
		virtual bool replace(int i, int j){
			if(i >= pos || j >= pos){
				return false;
			}
			T* it = getByPosition(i);
			T* jt = getByPosition(j);
			// setPointer(i, jt);
			// setPointer(j, it);
			// return true;
			return false;
		}
		
		void addList(RawList<T> *list){
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
		
		T* getByPosition(int p)const{
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
		
		cppObjectClass* getClass(){
			return Class<LinkedList>::classType;
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
		
        void operator =(const LinkedList<T>& l){
			this->resetDelete();
			for(int x = 0; x < l.getPosition(); x++){
				this->addLValue(*l.getByPosition(x));
			}
		}
		
        bool operator ==(LinkedList<T> l){
			if(l.getPosition() != this->getPosition()){
				return false;
			}
			for(int x = 0; x < l.getPosition(); x++){
				this->addLValue(*l.getByPosition(x));
				if(*l.getByPosition(x) != *this->getByPosition(x)){
					return false;
				}
			}
			return true;
		}
		
        bool operator !=(LinkedList<T> l){
			if(l.getPosition() == this->getPosition()){
				return false;
			}
			for(int x = 0; x < l.getPosition(); x++){
				this->addLValue(*l.getByPosition(x));
				if(*l.getByPosition(x) == *this->getByPosition(x)){
					return false;
				}
			}
			return true;
		}
		
		virtual void cutLinkedList(int start, int end){
			
		}
		
		virtual LinkedIterator<T> begin(){
			return LinkedIterator<T>(start,0);
		}
		virtual LinkedIterator<T> end(){
			return LinkedIterator<T>(start, this->getSize());
		}
};

}

#endif 
