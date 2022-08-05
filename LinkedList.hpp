
#if defined(DISABLE_LinkedList)
	#define LinkedList_hpp
#endif

#ifndef LinkedList_hpp
#define LinkedList_hpp
#define LinkedList_AVAILABLE

#include "LinkedListNode.hpp"
#include "cppObjectClass.hpp"
#include "LinkedIterator.hpp"
#include "List.hpp"

#ifdef LinkedList_LogApp
	#include "ame_Logger_config.hpp"
	#include "ame_Logger.hpp"
	
	#define LinkedListLog(location,method,type,mns) ame_Log(this,location,"LinkedList",method,type,mns)
#else
	#ifdef LinkedList_LogDebugApp
		#include "ame_Logger_config.hpp"
		#include "ame_Logger.hpp"
		
		#define LinkedListLog(location,method,type,mns) ame_LogDebug(this,location,"LinkedList",method,type)
	#else
		#define LinkedListLog(location,method,type,mns) 
	#endif
#endif

namespace ame{

template<class T>
class LinkedList : public List<T>{
	protected:
		int m_pos = 0;
		int m_size = 0;
		bool m_owner = true;
	public:
		LinkedListNode<T>* m_start = nullptr;
		LinkedListNode<T>* m_end = nullptr;
		LinkedListNode<T>* m_node = nullptr;
		
		LinkedList<T>(){
			LinkedListLog(ame_Log_StartMethod, "Constructor", "println", "");
			LinkedListLog(ame_Log_Statement, "Constructor", "println", "Default Constructor");
			LinkedListLog(ame_Log_EndMethod, "Constructor", "println", "");
		}
		
		LinkedList<T>(const LinkedList<T>& c_list){
			LinkedListLog(ame_Log_StartMethod, "Constructor", "println", "");
			LinkedListNode<T>* c_node = c_list.getStartNode();
			if(c_node == nullptr){
				return;
			}
			for(int x=0; x < c_list.getPosition(); x++){
				this->addLValue(*c_node->get());
				c_node = c_list.getNextNode(c_node);
			}
			LinkedListLog(ame_Log_EndMethod, "Constructor", "println", "");
		}
		
		LinkedList<T>(bool own){
			LinkedListLog(ame_Log_StartMethod, "Constructor", "println", "");
			m_owner = own;
			LinkedListLog(ame_Log_EndMethod, "Constructor", "println", "");
		}
		
		virtual ~LinkedList<T>(){
			LinkedListLog(ame_Log_StartMethod, "Destructor", "println", "");
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
			m_pos = 0;
			m_size = 0;
			LinkedListLog(ame_Log_EndMethod, "Destructor", "println", "");
		}
		
		protected:
		
		virtual LinkedListNode<T>* getNextNode(LinkedListNode<T>* a_node) const{
			if(a_node == nullptr){
				return nullptr;
			}
			return a_node->next;
		}
		
		virtual LinkedListNode<T>* getLastNode(LinkedListNode<T>* a_node) const{
			if(a_node == nullptr){
				return nullptr;
			}
			return a_node->last;
		}
		
		virtual LinkedListNode<T>* setNode(LinkedListNode<T>* a_node){
			m_node = a_node;
			return m_node;
		}
		
		virtual LinkedListNode<T>* initNodes(T* a_value){
			LinkedListNode<T>* s_node = this->getStartNode();
			LinkedListNode<T>* e_node = this->getEndNode();
			LinkedListNode<T>* i_node = this->getNode();
			if(s_node == nullptr && e_node == nullptr && i_node == nullptr){
				LinkedListLog(ame_Log_Statement, "initNodes", "println", "s_node == nullptr && e_node == nullptr && i_node == nullptr");
				i_node = new LinkedListNode<T>();
				m_node = i_node;
				m_start = i_node;
				m_end = i_node;
				i_node->set(a_value);
				m_pos = 1;
				m_size = 1;
				return i_node;
			}
			return nullptr;
		}

		virtual LinkedListNode<T>* addPointerToNextNode(LinkedListNode<T>* a_node, T* a_value){
			if(a_node == nullptr){
				LinkedListLog(ame_Log_Statement, "addPointerToNextNode", "println", "a_node == nullptr");
				return nullptr;
			}
			LinkedListNode<T>* nextNode = a_node->next;
			if(nextNode == nullptr){
				LinkedListLog(ame_Log_Statement, "addPointerToNextNode", "println", "nextNode == nullptr");
				nextNode = new LinkedListNode<T>();
				nextNode->set(a_value);
				a_node->next = nextNode;
				nextNode->last = a_node;
				return nextNode;
			}
			LinkedListNode<T>* n_Node = new LinkedListNode<T>();
			LinkedListLog(ame_Log_Statement, "addPointerToNextNode", "println", "inserting the node next to a_anode");
			a_node->next = n_Node;
			nextNode->last = n_Node;
			n_Node->next = nextNode;
			n_Node->last = a_node;
			n_Node->set(a_value);
			return n_Node;
		}
		
		virtual LinkedListNode<T>* addPointerToLastNode(LinkedListNode<T>* a_node, T* a_value){
			if(a_node == nullptr){
				LinkedListLog(ame_Log_Statement, "addPointerToLastNode", "println", "a_node == nullptr");
				return nullptr;
			}
			LinkedListNode<T>* lastNode = a_node->last;
			if(lastNode == nullptr){
				LinkedListLog(ame_Log_Statement, "addPointerToLastNode", "println", "lastNode == nullptr");
				lastNode = new LinkedListNode<T>();
				lastNode->set(a_value);
				a_node->last = lastNode;
				lastNode->next = a_node;
				return lastNode;
			}
			LinkedListNode<T>* n_Node = new LinkedListNode<T>();
			LinkedListLog(ame_Log_Statement, "addPointerToLastNode", "println", "inserting the node last to a_anode");
			a_node->last = n_Node;
			lastNode->next = n_Node;
			n_Node->last = lastNode;
			n_Node->next = a_node;
			n_Node->set(a_value);
			return n_Node;
		}
		
		public:
		
		virtual LinkedListNode<T>* getNode() const{
			return m_node;
		}
		
		virtual LinkedListNode<T>* getStartNode() const{
			return m_start;
		}
		
		virtual LinkedListNode<T>* getEndNode() const{
			return m_end;
		}
		
		virtual LinkedListNode<T>* getNode(int x) const{
			LinkedListNode<T>* node = getStartNode();
			for(int count = 0; node != nullptr; count++){
				if(x == count){
					return node;
				}
				node = getNextNode(node);
			}
			return nullptr;
		}
		
		virtual LinkedListNode<T>* getNodeI(int x) const{
			LinkedListNode<T>* node = getEndNode();
			for(int count = 0; node != nullptr; count++){
				if(x == count){
					return node;
				}
				node = getLastNode(node);
			}
			return nullptr;
		}
		
		virtual LinkedListNode<T>* getNodeByPointer(T* key) const{
			LinkedListNode<T>* node = getStartNode();
			for(int count = 0; node != nullptr; count++){
				T* i_value = node->get();
				if(key == i_value){
					return node;
				}
				node = getNextNode(node);
			}
			return nullptr;
		}
		
		virtual LinkedListNode<T>* getNodeByPointerI(T* key) const{
			LinkedListNode<T>* node = getEndNode();
			for(int count = 0; node != nullptr; count++){
				T* i_value = node->get();
				if(key == i_value){
					return node;
				}
				node = getLastNode(node);
			}
			return nullptr;
		}
		
		virtual LinkedListNode<T>* getNodeByLValue(T key) const{
			LinkedListNode<T>* node = getStartNode();
			for(int count = 0; node != nullptr; count++){
				T* i_value = node->get();
				if(i_value == nullptr){
					continue;
				}
				if(key == *i_value){
					return node;
				}
				node = getNextNode(node);
			}
			return nullptr;
		}
		
		virtual LinkedListNode<T>* getNodeByLValueI(T key) const{
			LinkedListNode<T>* node = getEndNode();
			for(int count = 0; node != nullptr; count++){
				T* i_value = node->get();
				if(i_value == nullptr){
					continue;
				}
				if(key == *i_value){
					return node;
				}
				node = getLastNode(node);
			}
			return nullptr;
		}
		
		virtual bool nextNode(){
			if(m_node == nullptr){
				return false;
			}
			LinkedListNode<T>* node = m_node->next;
			if(node == nullptr){
				return false;
			}
			m_node = node;
			return true;
		}
		
		virtual bool lastNode(){
			if(m_node == nullptr){
				return false;
			}
			LinkedListNode<T>* node = m_node->last;
			if(node == nullptr){
				return false;
			}
			m_node = node;
			return true;
		}

		virtual bool isEmpty()const{
			return m_node == nullptr || m_start == nullptr || m_end == nullptr || m_size == 0;
		}

		virtual bool isOwner()const{
			return m_owner;
		}
		
		virtual void setPosition(int p){
			if(p >= m_size){
				return;
			}
			m_pos = p;
			LinkedListNode<T>* i_node = getNode(p);
			setNode(i_node);
		}
		
		virtual int getPosition()const{
			return m_pos;
		}
		
		virtual int getSize()const{
			return m_size;
		}
	
		virtual bool replace(int i, int j){
			if(i >= m_pos || j >= m_pos){
				return false;
			}
			T* it = getByPosition(i);
			T* jt = getByPosition(j);
			setPointer(i, jt);
			setPointer(j, it);
			return true;
		}
	
		template<class... args>
		void addPack(args... x){
			T array[] = {x...};
			for(T a : array){
				addLValue(a);
			}
		}
		
		virtual T* addPointerToNode(T* a_value){
			LinkedListNode<T>* i_node = this->getNode();
			
			if(i_node == nullptr){
				LinkedListLog(ame_Log_Statement, "addPointerToNode", "println", "i_node == nullptr");
				LinkedListNode<T>* ii_node = this->initNodes(a_value);
				if(ii_node == nullptr){
					return nullptr;
				}
				return ii_node->get();
			}
			
			m_node = this->addPointerToNextNode(i_node, a_value);
			m_pos++;
			m_size++;
			
			if(i_node == this->getEndNode()){
				m_end = m_node;
			}
			
			return a_value;
		}
		
		virtual T* addPointerToStartNode(T* a_value){
			LinkedListNode<T>* i_node = this->getStartNode();
			
			if(i_node == nullptr){
				LinkedListLog(ame_Log_Statement, "addPointerToStartNode", "println", "i_node == nullptr");
				LinkedListNode<T>* ii_node = this->initNodes(a_value);
				if(ii_node == nullptr){
					return nullptr;
				}
				return ii_node->get();
			}
			
			m_start = this->addPointerToLastNode(i_node, a_value);
			m_pos++;
			m_size++;
			
			return a_value;
		}
		
		virtual T* addPointerToEndNode(T* a_value){
			LinkedListNode<T>* i_node = this->getEndNode();
			
			if(i_node == nullptr){
				LinkedListLog(ame_Log_Statement, "addPointerToEndNode", "println", "i_node == nullptr");
				LinkedListNode<T>* ii_node = this->initNodes(a_value);
				if(ii_node == nullptr){
					return nullptr;
				}
				return ii_node->get();
			}
			
			m_end = this->addPointerToNextNode(i_node, a_value);
			m_pos++;
			m_size++;
			
			return a_value;
		}
		
		template<class... Args>
		T* addParameters(Args... args){
			T* i_value = new T(args...);
			return this->addPointer(i_value);
		}
		
		virtual T* addPointer(T* a_value){
			return this->addPointerToEndNode(a_value);
		}
		
		virtual T* addLValue(T v_value){
			T* i_value = new T();
			*i_value = v_value;
			return this->addPointerToEndNode(i_value);
		}
		
		virtual T* setLValue(int position,T a_value){
			LinkedListNode<T>* i_node = getNode(position);
			if(i_node == nullptr){
				return nullptr;
			}
			T* i_value = i_node->get();
			if(i_value != nullptr){
				*i_value = a_value;
			}
			return i_value;
		}
		
		virtual T* setPointer(int position, T* a_value){
			LinkedListNode<T>* i_node = getNode(position);
			if(i_node == nullptr){
				return nullptr;
			}
			T* i_value = i_node->get();
			if(isOwner() && i_value != nullptr){
				delete i_value;
			}
			i_node->set(a_value);
			return a_value;
		}
		
		virtual T* insertLValue(int position, T a_value){
			if(position == 0){
				T* i_value = new T();
				*i_value = a_value;
				return this->addPointerToStartNode(i_value);
			}
			if(position < this->getPosition()){
				LinkedListNode<T>* i_node = getNode(position);
				if(i_node == nullptr){
					return nullptr;
				}
				T* i_value = new T();
				*i_value = a_value;
				m_pos++;
				m_pos++;
				i_node = this->addPointerToLastNode(i_node, i_value);
				return i_value;
			}
			return nullptr;
		}
		
		virtual T* insertPointer(int position, T* a_value){
			if(position == 0){
				return this->addPointerToStartNode(a_value);
			}
			if(position < this->getPosition()){
				LinkedListNode<T>* i_node = getNode(position);
				if(i_node == nullptr){
					return nullptr;
				}
				m_pos++;
				m_pos++;
				i_node = this->addPointerToLastNode(i_node, a_value);
				return a_value;
			}
			return nullptr;
		}
		
		virtual T* getByPointer(T* key){
			LinkedListNode<T>* i_node = this->getNodeByPointer(key);
			if(i_node == nullptr){
				return nullptr;
			}
			return i_node->get();
		}
		
		virtual T* getByLValue(T key){
			LinkedListNode<T>* i_node = this->getNodeByLValue(key);
			if(i_node == nullptr){
				return nullptr;
			}
			return i_node->get();
		}
		
		virtual T* getByPosition(int p)const{
			LinkedListNode<T>* i_node = this->getNode(p);
			if(i_node == nullptr){
				return nullptr;
			}
			return i_node->get();
		}
		
		virtual bool containByPointer(T* key){
			LinkedListNode<T>* i_node = this->getNodeByPointer(key);
			if(i_node == nullptr){
				return false;
			}
			return true;
		}
		
		virtual bool containByLValue(T key){
			LinkedListNode<T>* i_node = this->getNodeByLValue(key);
			if(i_node == nullptr){
				return false;
			}
			return true;
		}
		
		virtual int getIndexByPointer(T* key){
			LinkedListNode<T>* node = getStartNode();
			for(int count = 0; node != nullptr; count++){
				T* i_value = node->get();
				if(key == i_value){
					return count;
				}
				node = getNextNode(node);
			}
			return -1;
		}
		
		virtual int getIndexByLValue(T key){
			LinkedListNode<T>* node = getStartNode();
			for(int count = 0; node != nullptr; count++){
				T* i_value = node->get();
				if(i_value == nullptr){
					continue;
				}
				if(key == *i_value){
					return count;
				}
				node = getNextNode(node);
			}
			return -1;
		}
		
		virtual void reset(){
			LinkedListLog(ame_Log_StartMethod, "reset", "println", "");
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
			m_pos = 0;
			m_size = 0;
			LinkedListLog(ame_Log_EndMethod, "reset", "println", "");
		}
		
		virtual void resetDelete(){
			LinkedListLog(ame_Log_StartMethod, "reset", "println", "");
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
			m_pos = 0;
			m_size = 0;
			LinkedListLog(ame_Log_EndMethod, "reset", "println", "");
		}
		
		virtual T* removeByPointer(T* key){
			LinkedListNode<T>* i_node = this->getNodeByPointer(key);
			if(i_node == nullptr){
				return nullptr;
			}
			i_node->removeNode();
			T* i_value = i_node->get();
			delete i_node;
			return i_value;
		}
		
		virtual T* removeByLValue(T key){
			LinkedListNode<T>* i_node = this->getNodeByLValue(key);
			if(i_node == nullptr){
				return nullptr;
			}
			i_node->removeNode();
			T* i_value = i_node->get();
			delete i_node;
			return i_value;
		}
		
		virtual T* removeByPosition(int x){
			LinkedListNode<T>* i_node = this->getNode(x);
			if(i_node == nullptr){
				return nullptr;
			}
			i_node->removeNode();
			T* i_value = i_node->get();
			delete i_node;
			return i_value;
		}
		
		virtual bool removeDeleteByPointer(T* key){
			T* i_value = this->removeByPointer(key);
			if(i_value == nullptr){
				return false;
			}
			if(isOwner()){
				delete i_value;
			}
			return true;
		}
		
		virtual bool removeDeleteByLValue(T key){
			T* i_value = this->removeByLValue(key);
			if(i_value == nullptr){
				return false;
			}
			if(isOwner()){
				delete i_value;
			}
			return true;
		}
		
		virtual bool removeDeleteByPosition(int x){
			T* i_value = this->removeByPosition(x);
			if(i_value == nullptr){
				return false;
			}
			if(isOwner()){
				delete i_value;
			}
			return true;
		}
	
		virtual void onDelete(){
			this->resetDelete();
		}
	
		////////////////////////////////////////////special removes part///////////////////////////////////////////////
		virtual bool removeAll(T a_value){
			LinkedListNode<T>* node = getStartNode();
			bool i_return = false;
			for(int count = 0; node != nullptr; count++){
				T* i_value = node->get();
				if(i_value == nullptr){
					continue;
				}
				if(a_value == *i_value){
					i_return = true;
					node->removeNode();
					delete node;
				}
				node = getNextNode(node);
			}
			return i_return;
		}
		
		virtual bool removeFirst(T key){
			T* i_value = this->removeByLValue(key);
			if(i_value == nullptr){
				return false;
			}
			if(isOwner()){
				delete i_value;
			}
			return true;
		}
		
		virtual bool removeLast(T key){
			LinkedListNode<T>* i_node = this->getNodeByLValueI(key);
			if(i_node == nullptr){
				return false;
			}
			T* i_value = i_node->get();
			i_node->removeNode();
			delete i_node;
			if(i_value == nullptr){
				return false;
			}
			if(isOwner()){
				delete i_value;
			}
			return true;
		}
	
		////////////////////////////////////////////operator part///////////////////////////////////////////////
		
		
		virtual T& operator[](int x){
			LinkedListLog(ame_Log_StartMethod, "operator[]", "println", "");
			T* i_value = this->getByPosition(x);
			if(i_value == nullptr){
				LinkedListLog(ame_Log_Statement, "operator[]", "println", "ERROR");
			}
			LinkedListLog(ame_Log_EndMethod, "operator[]", "println", "");
			return *i_value;
		}
		
		virtual T operator[](int x) const{
			T* i_value = this->getByPosition(x);
			if(i_value == nullptr){
				return T();
			}
			return *i_value;
		}
		
		//cpObject part
		
		virtual bool copy(cppObject* obj){
			if(obj == nullptr){
				return false;
			}
			if(obj->instanceof(getClass())){
				LinkedList<T>* o_list = (LinkedList<T>*)obj;
				this->resetDelete();
				if(o_list->isEmpty()){
					return true;
				}
				LinkedListNode<T>* i_node = o_list->getStartNode();
				for(int count = 0; i_node != nullptr; count++){
					T* i_value = nullptr;
					T* i_value_2 = i_node->get();
					if(i_value_2 != nullptr){
						i_value = new T();
						*i_value = *i_value_2;
					}
					this->addPointerToEndNode(i_value);
					i_node = o_list->getNextNode(i_node);
				}
				return true;
			}
			return false;
		}
		
		virtual bool move(cppObject* obj){
			if(obj == nullptr){
				return false;
			}
			if(obj->instanceof(getClass())){
				LinkedList<T>* o_list = (LinkedList<T>*)obj;
				this->resetDelete();
				if(o_list->isEmpty()){
					return true;
				}
				LinkedListNode<T>* i_node = o_list->getStartNode();
				for(int count = 0; i_node != nullptr; count++){
					T* i_value = i_node->get();
					this->addPointerToEndNode(i_value);
					i_node->set(nullptr);
					i_node = o_list->getNextNode(i_node);
				}
				o_list->reset();
				return true;
			}
			return false;
		}
		
		virtual bool equal(cppObject* obj){
			if(obj == nullptr){
				return false;
			}
			if(obj == this){
				return true;
			}
			if(obj->instanceof(getClass())){
				LinkedList<T>* o_list = (LinkedList<T>*)obj;
				if(this->getPosition() != o_list->getPosition()){
					return false;
				}
				LinkedListNode<T>* i_node_1 = getStartNode();
				LinkedListNode<T>* i_node_2 = o_list->getStartNode();
				for(int count = 0; i_node_1 != nullptr && i_node_2 != nullptr; count++){
					T* i_value_1 = i_node_1->get();
					T* i_value_2 = i_node_2->get();
					if(i_value_1 == nullptr && i_value_2 == nullptr){
						continue;
					}
					if(i_value_1 == nullptr){
						return false;
					}
					if(i_value_2 == nullptr){
						return false;
					}
					if(*i_value_1 != *i_value_2){
						return false;
					}
					i_node_1 = getNextNode(i_node_1);
					i_node_2 = getNextNode(i_node_2);
				}
				return true;
			}
			return false;
		}
		
		virtual cppObjectClass* getClass(){
			return Class<LinkedList>::classType;
		}
		virtual bool instanceof(cppObjectClass* cls){
			return cls == Class<LinkedList<T>>::getClass() || List<T>::instanceof(cls);
		}
		
		virtual LinkedList<T>* clone(){
			return new LinkedList<T>(*this);
		}
		
		virtual LinkedList<T>* clone(bool owningMemory){
			LinkedList<T>* list = new LinkedList<T>(*this);
			list->m_owner = owningMemory;
			return list;
		}
		
        virtual void operator=(const LinkedList<T>& a_list){
			this->resetDelete();
			if(a_list.isEmpty()){
				return;
			}
			LinkedListNode<T>* i_node = a_list.getStartNode();
			for(int count = 0; i_node != nullptr; count++){
				T* i_value = nullptr;
				T* i_value_2 = i_node->get();
				if(i_value_2 != nullptr){
					i_value = new T();
					*i_value = *i_value_2;
				}
				this->addPointerToEndNode(i_value);
				i_node = a_list.getNextNode(i_node);
			}
		}
		
        virtual bool operator==(LinkedList<T> a_list){
			if(this->getPosition() != a_list.getPosition()){
				return false;
			}
			LinkedListNode<T>* i_node_1 = getStartNode();
			LinkedListNode<T>* i_node_2 = a_list.getStartNode();
			for(int count = 0; i_node_1 != nullptr && i_node_2 != nullptr; count++){
				T* i_value_1 = i_node_1->get();
				T* i_value_2 = i_node_2->get();
				if(i_value_1 == nullptr && i_value_2 == nullptr){
					continue;
				}
				if(i_value_1 == nullptr){
					return false;
				}
				if(i_value_2 == nullptr){
					return false;
				}
				if(*i_value_1 != *i_value_2){
					return false;
				}
				i_node_1 = getNextNode(i_node_1);
				i_node_2 = getNextNode(i_node_2);
			}
			return true;
		}
		
        virtual bool operator!=(LinkedList<T> a_list){
			if(this->getPosition() == a_list.getPosition()){
				return true;
			}
			LinkedListNode<T>* i_node_1 = getStartNode();
			LinkedListNode<T>* i_node_2 = a_list.getStartNode();
			for(int count = 0; i_node_1 != nullptr && i_node_2 != nullptr; count++){
				T* i_value_1 = i_node_1->get();
				T* i_value_2 = i_node_2->get();
				if(i_value_1 == nullptr && i_value_2 == nullptr){
					continue;
				}
				if(i_value_1 == nullptr){
					return true;
				}
				if(i_value_2 == nullptr){
					return true;
				}
				if(*i_value_1 != *i_value_2){
					return true;
				}
				i_node_1 = getNextNode(i_node_1);
				i_node_2 = getNextNode(i_node_2);
			}
			return false;
		}
		
		virtual LinkedIterator<T> begin(){
			return LinkedIterator<T>(m_start,0);
		}
		virtual LinkedIterator<T> end(){
			return LinkedIterator<T>(m_start, this->getSize());
		}
};

}

#endif