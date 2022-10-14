
#ifndef LinkedList_hpp
#define LinkedList_hpp
#define LinkedList_AVAILABLE

#include "cppObject.hpp"
#include "List.hpp"
#include "LinkedRawList.hpp"
#include "LinkedListNode.hpp"
#include "LinkedIterator.hpp"
#include "TemplateClass.hpp"

#ifdef LinkedList_LogApp
	#include "ame_Logger_config.hpp"
	#include "ame_Logger.hpp"

	#define LinkedListLog(location,method,type,mns) ame_Log(this,location,"LinkedList",method,type,mns)
	#define const_LinkedListLog(location,method,type,mns)
#else
	#ifdef LinkedList_LogDebugApp
		#include "ame_Logger_config.hpp"
		#include "ame_Logger.hpp"

		#define LinkedListLog(location,method,type,mns) ame_LogDebug(this,location,"LinkedList",method,type)
		#define const_LinkedListLog(location,method,type,mns)
	#else
		#define LinkedListLog(location,method,type,mns)
		#define const_LinkedListLog(location,method,type,mns)
	#endif
#endif

namespace ame{

template<class T>
class LinkedList : public LinkedRawList<T>, public List<T>{
	protected:
		static cppObjectClass* m_linked_list_class;
		
	public:
		LinkedList<T>(){
			LinkedListLog(ame_Log_StartMethod, "addFirst", "println", "");
			LinkedListLog(ame_Log_EndMethod, "addFirst", "println", "");
		}
		
		LinkedList<T>(const LinkedList<T>& c_list){
			LinkedListLog(ame_Log_StartMethod, "addFirst", "println", "");
			LinkedListLog(ame_Log_EndMethod, "addFirst", "println", "");
			LinkedListNode<T>* c_node = c_list.getStartNode();
			if(c_node == nullptr){
				return;
			}
			for(int x=0; x < c_list.getPosition(); x++){
				this->addLValue(*c_node->get());
				c_node = c_list.getNextNode(c_node);
			}
		}
		
		// template<class... args>
		// LinkedList<T>(args... x){
			// LinkedListLog(ame_Log_StartMethod, "addFirst", "println", "");
			// LinkedListLog(ame_Log_EndMethod, "addFirst", "println", "");
			
		// }
		
		virtual ~LinkedList<T>(){
			LinkedListLog(ame_Log_StartMethod, "addFirst", "println", "");
			LinkedListLog(ame_Log_EndMethod, "addFirst", "println", "");
		}
		
	
		//cpObject part
		
		virtual bool copy(cppObject* obj){
			LinkedListLog(ame_Log_StartMethod, "copy", "println", "");
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
			LinkedListLog(ame_Log_EndMethod, "copy", "println", "");
			return false;
		}
		
		virtual bool move(cppObject* obj){
			LinkedListLog(ame_Log_StartMethod, "move", "println", "");
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
			LinkedListLog(ame_Log_EndMethod, "move", "println", "");
			return false;
		}
		
		virtual bool equal(cppObject* obj){
			LinkedListLog(ame_Log_StartMethod, "equal", "println", "");
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
				LinkedListNode<T>* i_node_1 = this->getStartNode();
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
					i_node_1 = this->getNextNode(i_node_1);
					i_node_2 = this->getNextNode(i_node_2);
				}
				return true;
			}
			LinkedListLog(ame_Log_EndMethod, "equal", "println", "");
			return false;
		}
		
		virtual cppObjectClass* getClass(){
			LinkedListLog(ame_Log_StartMethod, "getClass", "println", "");
			LinkedListLog(ame_Log_EndMethod, "getClass", "println", "");
			return m_linked_list_class;
		}
		virtual bool instanceof(cppObjectClass* cls){
			LinkedListLog(ame_Log_StartMethod, "instanceof", "println", "");
			LinkedListLog(ame_Log_EndMethod, "instanceof", "println", "");
			return cls == m_linked_list_class || List<T>::instanceof(cls);
		}
		
		virtual LinkedList<T>* clone(){
			LinkedListLog(ame_Log_StartMethod, "clone", "println", "");
			LinkedListLog(ame_Log_EndMethod, "clone", "println", "");
			return new LinkedList<T>(*this);
		}
		
		virtual LinkedList<T>* clone(bool owningMemory){
			LinkedListLog(ame_Log_StartMethod, "clone", "println", "");
			LinkedList<T>* list = new LinkedList<T>(*this);
			list->m_owner = owningMemory;
			LinkedListLog(ame_Log_EndMethod, "clone", "println", "");
			return list;
		}
		
        virtual void operator=(const LinkedList<T>& a_list){
			LinkedListLog(ame_Log_StartMethod, "operator=", "println", "");
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
			LinkedListLog(ame_Log_EndMethod, "operator=", "println", "");
		}
		
        virtual bool operator==(LinkedList<T> a_list){
			LinkedListLog(ame_Log_StartMethod, "operator==", "println", "");
			if(this->getPosition() != a_list.getPosition()){
				return false;
			}
			LinkedListNode<T>* i_node_1 = this->getStartNode();
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
				i_node_1 = this->getNextNode(i_node_1);
				i_node_2 = this->getNextNode(i_node_2);
			}
			LinkedListLog(ame_Log_EndMethod, "operator==", "println", "");
			return true;
		}
		
        virtual bool operator!=(LinkedList<T> a_list){
			LinkedListLog(ame_Log_StartMethod, "operator!=", "println", "");
			if(this->getPosition() == a_list.getPosition()){
				return true;
			}
			LinkedListNode<T>* i_node_1 = this->getStartNode();
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
				i_node_1 = this->getNextNode(i_node_1);
				i_node_2 = this->getNextNode(i_node_2);
			}
			LinkedListLog(ame_Log_EndMethod, "operator!=", "println", "");
			return false;
		}
};

template<class T>
cppObjectClass* LinkedList<T>::m_linked_list_class = new TemplateClass<LinkedList<T>>();

}

#endif