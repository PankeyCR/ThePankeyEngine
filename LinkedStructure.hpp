
#ifndef LinkedStructure_hpp
	#define LinkedStructure_hpp

	#include "MemoryStructure.hpp"
	#include "LinkedListNode.hpp" 

	#ifdef LinkedStructure_LogApp
		#include "pankey_Logger.hpp"
		#define LinkedStructureLog(location,method,type,mns) pankey_Log((void*)this,location,"LinkedStructure",method,type,mns)
	#else
		#define LinkedStructureLog(location,method,type,mns)
	#endif

	namespace pankey{

		template<class T>
		class LinkedStructure : public MemoryStructure<T>{
			public:
				LinkedListNode<T>* m_start = nullptr;
				LinkedListNode<T>* m_end = nullptr;
				LinkedListNode<T>* m_node = nullptr;
				
				LinkedStructure<T>(){
					LinkedStructureLog(pankey_Log_StartMethod, "Constructor", "println", "");
					LinkedStructureLog(pankey_Log_EndMethod, "Constructor", "println", "");
				}
				
				LinkedStructure<T>(const LinkedStructure<T>& c_list){
					LinkedStructureLog(pankey_Log_StartMethod, "Constructor", "println", "");
					LinkedListNode<T>* c_node = c_list.getStartNode();
					if(c_node == nullptr){
						return;
					}
					for(int x=0; x < c_list.getPosition(); x++){
						this->addPointer(c_node->get());
						c_node = c_list.getNextNode(c_node);
					}
					LinkedStructureLog(pankey_Log_EndMethod, "Constructor", "println", "");
				}
				
				virtual ~LinkedStructure<T>(){
					LinkedStructureLog(pankey_Log_StartMethod, "Destructor", "println", "");
					LinkedStructureLog(pankey_Log_StartMethod, "Destructor", "println", "Position:");
					LinkedStructureLog(pankey_Log_StartMethod, "Destructor", "println", this->getPosition());
					LinkedStructureLog(pankey_Log_StartMethod, "Destructor", "println", "Size:");
					LinkedStructureLog(pankey_Log_StartMethod, "Destructor", "println", this->getSize());
					LinkedListNode<T>* node = this->getStartNode();
					this->deleteListNode(node);
					m_start = nullptr;
					m_end = nullptr;
					m_node = nullptr;
					this->setPosition(0);
					this->setSize(0);
					LinkedStructureLog(pankey_Log_EndMethod, "Destructor", "println", "");
				}
				
				virtual bool deleteListNode(LinkedListNode<T>* a_node){
					LinkedStructureLog(pankey_Log_StartMethod, "deleteListNode", "println", "");
					if(a_node == nullptr){
						return false;
					}
					LinkedListNode<T>* node = a_node;
					LinkedListNode<T>* nextNode = nullptr;
					for(int x = 0; node != nullptr; x++){
						LinkedStructureLog(pankey_Log_Statement, "deleteListNode", "println", "node != nullptr:");
						LinkedStructureLog(pankey_Log_Statement, "deleteListNode", "println", node != nullptr);
						LinkedStructureLog(pankey_Log_Statement, "deleteListNode", "println", "iteration index:");
						LinkedStructureLog(pankey_Log_Statement, "deleteListNode", "println", x);
						nextNode = node->next;
						if(this->isOwner() && node->value != nullptr){
							LinkedStructureLog(pankey_Log_Statement, "deleteListNode", "println", "this->isOwner() && node->get() != nullptr");
							delete node->value;
						}
						LinkedStructureLog(pankey_Log_Statement, "deleteListNode", "println", "deleting node");
						delete node;
						node = nullptr;
						if(nextNode == nullptr){
							LinkedStructureLog(pankey_Log_Statement, "deleteListNode", "println", "nextNode == nullptr");
							break;
						}
						LinkedStructureLog(pankey_Log_Statement, "deleteListNode", "println", "nextNode->last = nullptr");
						nextNode->last = nullptr;
						node = nextNode;
						LinkedStructureLog(pankey_Log_Statement, "deleteListNode", "println", "end of iteration");
					}
					LinkedStructureLog(pankey_Log_EndMethod, "deleteListNode", "println", "");
					return true;
				}
				
				virtual LinkedListNode<T>* getNextNode(LinkedListNode<T>* a_node) const{
					LinkedStructureLog(pankey_Log_StartMethod, "getNextNode", "println", "");
					if(a_node == nullptr){
						return nullptr;
					}
					LinkedStructureLog(pankey_Log_EndMethod, "getNextNode", "println", "");
					return a_node->next;
				}
				
				virtual LinkedListNode<T>* getLastNode(LinkedListNode<T>* a_node) const{
					LinkedStructureLog(pankey_Log_StartMethod, "getLastNode", "println", "");
					if(a_node == nullptr){
						return nullptr;
					}
					LinkedStructureLog(pankey_Log_EndMethod, "getLastNode", "println", "");
					return a_node->last;
				}
				
				virtual LinkedListNode<T>* setNode(LinkedListNode<T>* a_node){
					LinkedStructureLog(pankey_Log_StartMethod, "setNode", "println", "");
					m_node = a_node;
					LinkedStructureLog(pankey_Log_EndMethod, "setNode", "println", "");
					return m_node;
				}
				
				virtual LinkedListNode<T>* initNodes(T* a_value){
					LinkedStructureLog(pankey_Log_StartMethod, "initNodes", "println", "");
					LinkedListNode<T>* s_node = this->getStartNode();
					LinkedListNode<T>* e_node = this->getEndNode();
					LinkedListNode<T>* i_node = this->getNode();
					if(s_node == nullptr && e_node == nullptr && i_node == nullptr){
						i_node = new LinkedListNode<T>();
						m_node = i_node;
						m_start = i_node;
						m_end = i_node;
						i_node->set(a_value);
						this->setPosition(1);
						this->setSize(1);
						return i_node;
					}
					LinkedStructureLog(pankey_Log_EndMethod, "initNodes", "println", "");
					return nullptr;
				}

				/*
					a_node = origin node
					a_value = pointer added to the new node added next to a_node
					if a_node dont have a next node, the new node is the next node
					if a_node has a next node, the new node is added in between a_node and the next node, making it he next node
				*/
				virtual LinkedListNode<T>* addPointerToNextNode(LinkedListNode<T>* a_node, T* a_value){
					LinkedStructureLog(pankey_Log_StartMethod, "addPointerToNextNode", "println", "");
					if(a_node == nullptr){
						LinkedStructureLog(pankey_Log_EndMethod, "addPointerToNextNode", "println", "a_node == nullptr");
						return nullptr;
					}
					LinkedListNode<T>* nextNode = a_node->next;
					if(nextNode == nullptr){
						nextNode = new LinkedListNode<T>();
						nextNode->set(a_value);
						a_node->next = nextNode;
						nextNode->last = a_node;
						LinkedStructureLog(pankey_Log_EndMethod, "addPointerToNextNode", "println", "nextNode == nullptr");
						return nextNode;
					}
					LinkedListNode<T>* n_Node = new LinkedListNode<T>();
					a_node->next = n_Node;
					nextNode->last = n_Node;
					n_Node->next = nextNode;
					n_Node->last = a_node;
					n_Node->set(a_value);
					LinkedStructureLog(pankey_Log_EndMethod, "addPointerToNextNode", "println", "");
					return n_Node;
				}
				
				virtual LinkedListNode<T>* addPointerToLastNode(LinkedListNode<T>* a_node, T* a_value){
					LinkedStructureLog(pankey_Log_StartMethod, "addPointerToLastNode", "println", "");
					if(a_node == nullptr){
						return nullptr;
					}
					LinkedListNode<T>* lastNode = a_node->last;
					if(lastNode == nullptr){
						lastNode = new LinkedListNode<T>();
						lastNode->set(a_value);
						a_node->last = lastNode;
						lastNode->next = a_node;
						return lastNode;
					}
					LinkedListNode<T>* n_Node = new LinkedListNode<T>();
					a_node->last = n_Node;
					lastNode->next = n_Node;
					n_Node->last = lastNode;
					n_Node->next = a_node;
					n_Node->set(a_value);
					LinkedStructureLog(pankey_Log_EndMethod, "addPointerToLastNode", "println", "");
					return n_Node;
				}
				
				virtual T* removeByNode(LinkedListNode<T>* a_node){
					LinkedStructureLog(pankey_Log_StartMethod, "removeByPointer", "println", "");
					if(a_node == nullptr){
						return nullptr;
					}
					T* i_value = a_node->get();
					a_node->set(nullptr);
					if(a_node == m_start && a_node == m_end && a_node == m_node){
						delete a_node;
						m_start = nullptr;
						m_end = nullptr;
						m_node = nullptr;
						this->setPosition(0);
						this->setSize(0);
						return i_value;
					}
					if(!this->isInOrder()){
						LinkedStructureLog(pankey_Log_EndMethod, "removeByPointer", "println", "!this->isInOrder()");
						return i_value;
					}
					if(a_node == m_start){
						m_start = a_node->next;
					}
					if(a_node == m_end){
						m_end = a_node->last;
					}
					a_node->removeNode();
					delete a_node;
					this->decrementPosition();
					this->decrementSize();
					LinkedStructureLog(pankey_Log_EndMethod, "removeByPointer", "println", "");
					return i_value;
				}
				
				virtual LinkedListNode<T>* getNode() const{
					LinkedStructureLog(pankey_Log_StartMethod, "getNode", "println", "");
					LinkedStructureLog(pankey_Log_EndMethod, "getNode", "println", "");
					return m_node;
				}
				
				virtual LinkedListNode<T>* getStartNode() const{
					LinkedStructureLog(pankey_Log_StartMethod, "getStartNode", "println", "");
					LinkedStructureLog(pankey_Log_EndMethod, "getStartNode", "println", "");
					return m_start;
				}
				
				virtual LinkedListNode<T>* getEndNode() const{
					LinkedStructureLog(pankey_Log_StartMethod, "getEndNode", "println", "");
					LinkedStructureLog(pankey_Log_EndMethod, "getEndNode", "println", "");
					return m_end;
				}
				
				virtual LinkedListNode<T>* getNode(int x) const{
					LinkedStructureLog(pankey_Log_StartMethod, "getNode", "println", "");
					if(this->isEmpty()){
						return nullptr;
					}
					if(x == 0){
						return this->getStartNode();
					}
					if(x == this->getPosition() - 1){
						return this->getEndNode();
					}
					LinkedListNode<T>* node = getStartNode();
					for(int count = 0; node != nullptr; count++){
						if(x == count){
							return node;
						}
						node = getNextNode(node);
					}
					LinkedStructureLog(pankey_Log_EndMethod, "getNode", "println", "");
					return nullptr;
				}
				
				virtual LinkedListNode<T>* getNodeI(int x) const{
					LinkedStructureLog(pankey_Log_StartMethod, "getNodeI", "println", "");
					if(this->isEmpty()){
						return nullptr;
					}
					if(x == 0){
						return this->getEndNode();
					}
					if(x == this->getPosition() - 1){
						return this->getStartNode();
					}
					LinkedListNode<T>* node = getEndNode();
					for(int count = 0; node != nullptr; count++){
						if(x == count){
							return node;
						}
						node = getLastNode(node);
					}
					LinkedStructureLog(pankey_Log_EndMethod, "getNodeI", "println", "");
					return nullptr;
				}
				
				virtual LinkedListNode<T>* getNodeByPointer(T* key) const{
					LinkedStructureLog(pankey_Log_StartMethod, "getNodeByPointer", "println", "");
					LinkedListNode<T>* node = getStartNode();
					for(int count = 0; node != nullptr; count++){
						T* i_value = node->get();
						if(key == i_value){
							return node;
						}
						node = getNextNode(node);
					}
					LinkedStructureLog(pankey_Log_EndMethod, "getNodeByPointer", "println", "");
					return nullptr;
				}
				
				virtual LinkedListNode<T>* getNodeByPointerI(T* key) const{
					LinkedStructureLog(pankey_Log_StartMethod, "getNodeByPointerI", "println", "");
					LinkedListNode<T>* node = getEndNode();
					for(int count = 0; node != nullptr; count++){
						T* i_value = node->get();
						if(key == i_value){
							return node;
						}
						node = getLastNode(node);
					}
					LinkedStructureLog(pankey_Log_EndMethod, "getNodeByPointerI", "println", "");
					return nullptr;
				}
				
				virtual bool nextNode(){
					LinkedStructureLog(pankey_Log_StartMethod, "nextNode", "println", "");
					if(m_node == nullptr){
						return false;
					}
					LinkedListNode<T>* node = m_node->next;
					if(node == nullptr){
						return false;
					}
					m_node = node;
					LinkedStructureLog(pankey_Log_EndMethod, "nextNode", "println", "");
					return true;
				}
				
				virtual bool lastNode(){
					LinkedStructureLog(pankey_Log_StartMethod, "lastNode", "println", "");
					if(m_node == nullptr){
						return false;
					}
					LinkedListNode<T>* node = m_node->last;
					if(node == nullptr){
						return false;
					}
					m_node = node;
					LinkedStructureLog(pankey_Log_EndMethod, "lastNode", "println", "");
					return true;
				}

				virtual bool isEmpty()const{
					LinkedStructureLog(pankey_Log_StartMethod, "isEmpty", "println", "");
					LinkedStructureLog(pankey_Log_EndMethod, "isEmpty", "println", "");
					return m_node == nullptr || m_start == nullptr || m_end == nullptr || this->getSize() == 0;
				}
				
				virtual void setNodePosition(int a_position){
					LinkedStructureLog(pankey_Log_StartMethod, "setPosition", "println", "");
					if(a_position >= this->getSize()){
						return;
					}
					this->setPosition(a_position);
					LinkedListNode<T>* i_node = getNode(a_position);
					setNode(i_node);
					LinkedStructureLog(pankey_Log_EndMethod, "setPosition", "println", "");
				}
				
				virtual bool replace(int i, int j){
					LinkedStructureLog(pankey_Log_StartMethod, "replace", "println", "");
					if(i >= this->getPosition() || j >= this->getPosition() || i == j){
						return false;
					}
					LinkedListNode<T>* node = getStartNode();
					LinkedListNode<T>* node_i = nullptr;
					LinkedListNode<T>* node_j = nullptr;
					for(int count = 0; node != nullptr; count++){
						T* i_value = node->get();
						if(i == count){
							node_i = node;
						}
						if(j == count){
							node_j = node;
						}
						if(node_i != nullptr && node_j != nullptr){
							T* i_value = node_i->get();
							T* j_value = node_j->get();
							node_i->set(j_value);
							node_j->set(i_value);
							return true;
						}
						node = getNextNode(node);
					}
					LinkedStructureLog(pankey_Log_EndMethod, "replace", "println", "");
					return true;
				}
				
				virtual T* addPointerToNode(T* a_value){
					LinkedStructureLog(pankey_Log_StartMethod, "addPointerToNode", "println", "");
					LinkedListNode<T>* i_node = this->getNode();
					
					if(i_node == nullptr){
						LinkedListNode<T>* ii_node = this->initNodes(a_value);
						if(ii_node == nullptr){
							return nullptr;
						}
						return ii_node->get();
					}
					
					m_node = this->addPointerToNextNode(i_node, a_value);
					this->incrementPosition();
					this->incrementSize();
					
					if(i_node == this->getEndNode()){
						m_end = m_node;
					}
					LinkedStructureLog(pankey_Log_EndMethod, "addPointerToNode", "println", "");
					return a_value;
				}
				
				virtual T* addPointerToStartNode(T* a_value){
					LinkedStructureLog(pankey_Log_StartMethod, "addPointerToStartNode", "println", "");
					LinkedListNode<T>* i_node = this->getStartNode();
					
					if(i_node == nullptr){
						LinkedListNode<T>* ii_node = this->initNodes(a_value);
						if(ii_node == nullptr){
							return nullptr;
						}
						return ii_node->get();
					}
					
					m_start = this->addPointerToLastNode(i_node, a_value);
					this->incrementPosition();
					this->incrementSize();
					LinkedStructureLog(pankey_Log_EndMethod, "addPointerToStartNode", "println", "");
					return a_value;
				}
				
				virtual T* addPointerToEndNode(T* a_value){
					LinkedStructureLog(pankey_Log_StartMethod, "addPointerToEndNode", "println", "");
					LinkedListNode<T>* i_node = this->getEndNode();
					
					if(i_node == nullptr){
						LinkedListNode<T>* ii_node = this->initNodes(a_value);
						if(ii_node == nullptr){
							return nullptr;
						}
						return ii_node->get();
					}
					
					m_end = this->addPointerToNextNode(i_node, a_value);
					this->incrementPosition();
					this->incrementSize();
					LinkedStructureLog(pankey_Log_EndMethod, "addPointerToEndNode", "println", "");
					return a_value;
				}
				
				virtual T* addPointer(T* a_value){
					LinkedStructureLog(pankey_Log_StartMethod, "addPointer", "println", "");
					LinkedStructureLog(pankey_Log_EndMethod, "addPointer", "println", "");
					return this->addPointerToEndNode(a_value);
				}
				
				virtual T* setPointer(int a_position, T* a_value){
					LinkedStructureLog(pankey_Log_StartMethod, "setPointer", "println", "");
					if(a_position >= this->getSize()){
						LinkedStructureLog(pankey_Log_Statement, "setPointer", "println", "expanding:");
						LinkedStructureLog(pankey_Log_Statement, "setPointer", "println", a_position - this->getSize() + this->m_expandSize);
						this->expand(a_position - this->getSize() + this->m_expandSize);
					}
					LinkedListNode<T>* i_node = getNode(a_position);
					if(i_node == nullptr){
						if(a_value != nullptr && this->isOwner()){
							delete a_value;
						}
						return nullptr;
					}
					T* i_value = i_node->get();
					if(i_value == a_value){
						return a_value;
					}
					if(this->isOwner() && i_value != nullptr){
						delete i_value;
					}
					i_node->set(a_value);
					if(a_position > this->getPosition()){
						this->setPosition(a_position + 1);
					}
					
					LinkedStructureLog(pankey_Log_EndMethod, "setPointer", "println", "");
					return a_value;
				}
				
				virtual T* insertPointer(int a_position, T* a_value){
					LinkedStructureLog(pankey_Log_StartMethod, "insertPointer", "println", "");
					if(a_position == 0){
						return this->addPointerToStartNode(a_value);
					}
					if(a_position < this->getPosition()){
						LinkedListNode<T>* i_node = getNode(a_position);
						if(i_node == nullptr){
							return nullptr;
						}
						this->incrementPosition();
						this->incrementSize();
						i_node = this->addPointerToLastNode(i_node, a_value);
						return a_value;
					}
					LinkedStructureLog(pankey_Log_EndMethod, "insertPointer", "println", "");
					return this->addPointer(a_value);
				}
				
				virtual T* getByPointer(T* key){
					LinkedStructureLog(pankey_Log_StartMethod, "getByPointer", "println", "");
					LinkedListNode<T>* i_node = this->getNodeByPointer(key);
					if(i_node == nullptr){
						return nullptr;
					}
					LinkedStructureLog(pankey_Log_EndMethod, "getByPointer", "println", "");
					return i_node->get();
				}
				
				virtual T* getByPosition(int a_position)const{
					LinkedStructureLog(pankey_Log_StartMethod, "getByPosition", "println", "");
					LinkedListNode<T>* i_node = this->getNode(a_position);
					if(i_node == nullptr){
						return nullptr;
					}
					LinkedStructureLog(pankey_Log_EndMethod, "getByPosition", "println", "");
					return i_node->get();
				}
				
				virtual bool containByPointer(T* key){
					LinkedStructureLog(pankey_Log_StartMethod, "containByPointer", "println", "");
					LinkedListNode<T>* i_node = this->getNodeByPointer(key);
					if(i_node == nullptr){
						return false;
					}
					LinkedStructureLog(pankey_Log_EndMethod, "containByPointer", "println", "");
					return true;
				}
				
				virtual int getIndexByPointer(T* key){
					LinkedStructureLog(pankey_Log_StartMethod, "getIndexByPointer", "println", "");
					LinkedListNode<T>* node = getStartNode();
					for(int count = 0; node != nullptr; count++){
						T* i_value = node->get();
						if(key == i_value){
							return count;
						}
						node = getNextNode(node);
					}
					LinkedStructureLog(pankey_Log_EndMethod, "getIndexByPointer", "println", "");
					return -1;
				}
				
				virtual void reset(){
					LinkedStructureLog(pankey_Log_StartMethod, "reset", "println", "");
					LinkedListNode<T>* node = getStartNode();
					LinkedListNode<T>* nextNode = nullptr;
					for(int x = 0; node != nullptr; x++){
						nextNode = node->next;
						delete node;
						node = nullptr;
						if(nextNode == nullptr){
							continue;
						}
						nextNode->last = nullptr;
						node = nextNode;
					}
					m_start = nullptr;
					m_end = nullptr;
					m_node = nullptr;
					this->setPosition(0);
					this->setSize(0);
					LinkedStructureLog(pankey_Log_EndMethod, "reset", "println", "");
				}
				
				virtual void resetDelete(){
					LinkedStructureLog(pankey_Log_StartMethod, "resetDelete", "println", "");
					LinkedListNode<T>* node = getStartNode();
					LinkedListNode<T>* nextNode = nullptr;
					for(int x = 0; node != nullptr; x++){
						nextNode = node->next;
						if(this->isOwner() && node->get() != nullptr){
							delete node->value;
						}
						delete node;
						node = nullptr;
						if(nextNode == nullptr){
							continue;
						}
						nextNode->last = nullptr;
						node = nextNode;
					}
					m_start = nullptr;
					m_end = nullptr;
					m_node = nullptr;
					this->setPosition(0);
					this->setSize(0);
					LinkedStructureLog(pankey_Log_EndMethod, "resetDelete", "println", "");
				}
				
				virtual T* removeByPointer(T* key){
					LinkedStructureLog(pankey_Log_StartMethod, "removeByPointer", "println", "");
					LinkedListNode<T>* i_node = this->getNodeByPointer(key);
					if(i_node == nullptr){
						return nullptr;
					}
					T* i_value = this->removeByNode(i_node);
					LinkedStructureLog(pankey_Log_EndMethod, "removeByPointer", "println", "");
					return i_value;
				}
				
				virtual T* removeByPosition(int x){
					LinkedStructureLog(pankey_Log_StartMethod, "removeByPosition", "println", "");
					LinkedListNode<T>* i_node = this->getNode(x);
					if(i_node == nullptr){
						return nullptr;
					}
					T* i_value = this->removeByNode(i_node);
					LinkedStructureLog(pankey_Log_EndMethod, "removeByPosition", "println", "");
					return i_value;
				}
				
				//special removes
				
				//cuts the list in 2 parts, it removes all nodes before the position a_position
				virtual LinkedListNode<T>* cutBefore(int a_position){
					LinkedStructureLog(pankey_Log_StartMethod, "cutBefore", "println", "");
					if(this->isEmpty() || a_position <= 0){
						LinkedStructureLog(pankey_Log_EndMethod, "cutBefore", "println", "this->isEmpty() || a_position == 0");
						return nullptr;
					}
					if(!this->isInOrder()){
						LinkedStructureLog(pankey_Log_Statement, "cutBefore", "println", "!this->isInOrder()");
						LinkedListNode<T>* node = this->getNode(a_position);
						LinkedListNode<T>* lastNode = nullptr;
						for(int x = 0; node != nullptr; x++){
							lastNode = node->last;
							node->value = nullptr;
							node = nullptr;
							if(lastNode == nullptr){
								break;
							}
							node = lastNode;
						}
						LinkedStructureLog(pankey_Log_EndMethod, "cutBefore", "println", "");
						return nullptr;
					}
					if(a_position == this->getPosition() - 1){
						LinkedStructureLog(pankey_Log_StartMethod, "cutBefore", "println", "a_position == this->getPosition() - 1");
						LinkedListNode<T>* b_node = this->m_end;
						this->m_end = b_node->last;
						this->m_end->next = nullptr;
						this->m_node = this->m_end;
						this->decrementPosition(a_position);
						this->decrementSize(a_position);
						return b_node;
					}
					LinkedListNode<T>* b_node = this->getNode(a_position);
					if(b_node == nullptr){
						LinkedStructureLog(pankey_Log_StartMethod, "cutBefore", "println", "b_node == nullptr");
						return nullptr;
					}
					LinkedStructureLog(pankey_Log_StartMethod, "cutBefore", "println", "cutting regular node");
					b_node->cutLastNode();
					this->decrementPosition(a_position);
					this->decrementSize(a_position);
					LinkedListNode<T>* stating_node = this->getStartNode();
					m_start = b_node;
					LinkedStructureLog(pankey_Log_EndMethod, "cutBefore", "println", "");
					return stating_node;
				}
				
				virtual bool cutDeleteBefore(int a_position){
					LinkedStructureLog(pankey_Log_StartMethod, "cutDeleteBefore", "println", "");
					LinkedListNode<T>* node = cutBefore(a_position);
					if(node == nullptr){
						return false;
					}
					this->deleteListNode(node);
					LinkedStructureLog(pankey_Log_EndMethod, "cutDeleteBefore", "println", "");
					return true;
				}
				
				//splits the Nodes in 2, it removes and returns the nodes after the position a_position
				virtual LinkedListNode<T>* cutAfter(int a_position){
					LinkedStructureLog(pankey_Log_StartMethod, "cutAfter", "println", "");
					if(this->isEmpty() || a_position == this->getPosition() - 1){
						LinkedStructureLog(pankey_Log_StartMethod, "cutAfter", "println", "this->isEmpty()");
						return nullptr;
					}
					if(!this->isInOrder()){
						LinkedStructureLog(pankey_Log_Statement, "cutBefore", "println", "!this->isInOrder()");
						LinkedListNode<T>* node = this->getNode(a_position);
						LinkedListNode<T>* nextNode = nullptr;
						for(int x = 0; node != nullptr; x++){
							nextNode = node->next;
							node->value = nullptr;
							node = nullptr;
							if(nextNode == nullptr){
								break;
							}
							node = nextNode;
						}
						LinkedStructureLog(pankey_Log_EndMethod, "cutBefore", "println", "");
						return nullptr;
					}
					if(a_position == 0){
						LinkedStructureLog(pankey_Log_StartMethod, "cutAfter", "println", "a_position == 0");
						LinkedListNode<T>* b_node = this->m_start;
						this->m_start = nullptr;
						this->m_end = nullptr;
						this->m_node = nullptr;
						this->setPosition(0);
						this->setSize(0);
						return b_node;
					}
					LinkedListNode<T>* b_node = this->getNode(a_position);
					if(b_node == nullptr){
						LinkedStructureLog(pankey_Log_StartMethod, "cutAfter", "println", "b_node == nullptr");
						return nullptr;
					}
					LinkedStructureLog(pankey_Log_StartMethod, "cutAfter", "println", "cutting regular node");
					m_end = b_node->last;
					b_node->cutLastNode();
					this->decrementPosition(a_position + 1);
					this->decrementSize(a_position + 1);
					LinkedStructureLog(pankey_Log_EndMethod, "cutAfter", "println", "");
					return b_node;
				}
				virtual bool cutDeleteAfter(int a_position){
					LinkedStructureLog(pankey_Log_StartMethod, "cutDeleteAfter", "println", "");
					LinkedListNode<T>* node = cutAfter(a_position);
					if(node == nullptr){
						return false;
					}
					this->deleteListNode(node);
					LinkedStructureLog(pankey_Log_EndMethod, "cutDeleteAfter", "println", "");
					return false;
				}
				
				virtual bool removeFirstIndex(int a_amount){
					LinkedStructureLog(pankey_Log_StartMethod, "removeFirstIndex", "println", "");
					LinkedStructureLog(pankey_Log_EndMethod, "removeFirstIndex", "println", "");
					return this->cutDeleteBefore(a_amount);
				}
				virtual bool removeLastIndex(int a_amount){
					LinkedStructureLog(pankey_Log_StartMethod, "removeLastIndex", "println", "");
					LinkedStructureLog(pankey_Log_EndMethod, "removeLastIndex", "println", "");
					return this->cutDeleteAfter(this->getPosition() - a_amount);
				}

                virtual void expand(int a_size){
					LinkedStructureLog(pankey_Log_StartMethod, "expand", "println", "");
					LinkedListNode<T>* i_node = this->getNode();
					
					if(i_node == nullptr){
						i_node = this->initNodes(nullptr);
						if(i_node == nullptr){
							return;
						}
					}

					for(int x = 0; x < a_size; x++){
						m_node = this->addPointerToNextNode(i_node, nullptr);
					}
					this->incrementSize(a_size);
					
					if(i_node == this->getEndNode()){
						m_end = m_node;
					}
					LinkedStructureLog(pankey_Log_EndMethod, "expand", "println", "");
				}
				
			protected:
				int m_expandSize = 5;
		};

	}

#endif