
#ifndef LinkedListNode_h
#define LinkedListNode_h

template <class T>
class LinkedListNode{
	private:
	
    public:
		LinkedListNode* last = nullptr;
		T* actual = nullptr;
		LinkedListNode* next = nullptr;
		
		LinkedListNode<T>(){
		}
		
		~LinkedListNode<T>(){
			if(actual != nullptr){
				delete actual;
				actual = nullptr;
			}
			last = nullptr;
			next = nullptr;
		}
};

#endif 
