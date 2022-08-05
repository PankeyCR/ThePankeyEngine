
#if defined(DISABLE_LinkedListNode)
	#define LinkedListNode_hpp
#endif

#ifndef LinkedListNode_hpp
#define LinkedListNode_hpp
#define LinkedListNode_AVAILABLE

namespace ame{

template <class T>
class LinkedListNode{
	private:
	
    public:
		LinkedListNode* last = nullptr;
		T* value = nullptr;
		LinkedListNode* next = nullptr;
		
		LinkedListNode<T>(){}
		
		virtual ~LinkedListNode<T>(){}
		
		virtual T* set(T* t){
			value = t;
			return value;
		}
		
		virtual T* get(){return value;}
		
		virtual void removeNode(){
			if(last != nullptr){
				last->next = next;
			}
			if(next != nullptr){
				next->last = last;
			}
		}
		
		virtual void removeLastNode(){
			last = nullptr;
		}
		
		virtual void removeNextNode(){
			next = nullptr;
		}
};

}

#endif