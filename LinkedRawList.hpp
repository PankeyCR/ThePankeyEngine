
#ifndef LinkedRawList_hpp
#define LinkedRawList_hpp
#define LinkedRawList_AVAILABLE

#include "RawList.hpp"
#include "LinkedRawPointerList.hpp"
#include "LinkedListNode.hpp"
#include "LinkedIterator.hpp"

#ifdef LinkedRawList_LogApp
	#include "ame_Logger_config.hpp"
	#include "ame_Logger.hpp"

	#define LinkedRawListLog(location,method,type,mns) ame_Log(this,location,"LinkedRawList",method,type,mns)
	#define const_LinkedRawListLog(location,method,type,mns)
#else
	#ifdef LinkedRawList_LogDebugApp
		#include "ame_Logger_config.hpp"
		#include "ame_Logger.hpp"

		#define LinkedRawListLog(location,method,type,mns) ame_LogDebug(this,location,"LinkedRawList",method,type)
		#define const_LinkedRawListLog(location,method,type,mns)
	#else
		#define LinkedRawListLog(location,method,type,mns)
		#define const_LinkedRawListLog(location,method,type,mns)
	#endif
#endif

namespace ame{

template<class T>
class LinkedRawList : public LinkedRawPointerList<T>, virtual public RawList<T>{
	public:
		LinkedRawList<T>(){}
		
		LinkedRawList<T>(const LinkedRawList<T>& c_list){
			LinkedListNode<T>* c_node = c_list.getStartNode();
			if(c_node == nullptr){
				return;
			}
			for(int x=0; x < c_list.getPosition(); x++){
				T* f_value = c_node->get();
				if(f_value == nullptr){
					c_node = c_list.getNextNode(c_node);
					continue;
				}
				this->addLValue(*f_value);
				c_node = c_list.getNextNode(c_node);
			}
		}
		
		virtual ~LinkedRawList<T>(){}
		
		virtual LinkedListNode<T>* getNodeByLValue(T key) const{
			const_LinkedRawListLog(ame_Log_StartMethod, "getNodeByLValue", "println", "");
			LinkedListNode<T>* node = this->getStartNode();
			for(int count = 0; node != nullptr; count++){
				T* i_value = node->get();
				if(i_value == nullptr){
					node = this->getNextNode(node);
					continue;
				}
				if(key == *i_value){
					return node;
				}
				node = this->getNextNode(node);
			}
			const_LinkedRawListLog(ame_Log_EndMethod, "getNodeByLValue", "println", "");
			return nullptr;
		}
		
		virtual LinkedListNode<T>* getNodeByLValueI(T key) const{
			const_LinkedRawListLog(ame_Log_StartMethod, "getNodeByLValueI", "println", "");
			LinkedListNode<T>* node = this->getEndNode();
			for(int count = 0; node != nullptr; count++){
				T* i_value = node->get();
				if(i_value == nullptr){
					node = this->getLastNode(node);
					continue;
				}
				if(key == *i_value){
					return node;
				}
				node = this->getLastNode(node);
			}
			const_LinkedRawListLog(ame_Log_EndMethod, "getNodeByLValueI", "println", "");
			return nullptr;
		}

		virtual T* addLValue(T a_value){
			LinkedRawListLog(ame_Log_StartMethod, "addLValue", "println", "");
			T* i_value = new T();
			*i_value = a_value;
			LinkedRawListLog(ame_Log_EndMethod, "addLValue", "println", "");
			return this->addPointerToEndNode(i_value);
		}

		virtual T* setLValue(int a_position, T a_value){
			LinkedRawListLog(ame_Log_StartMethod, "setLValue", "println", "");
			T* i_value = new T();
			*i_value = a_value;
			LinkedRawListLog(ame_Log_EndMethod, "setLValue", "println", "");
			return this->setPointer(a_position, i_value);
		}
		
		virtual T* insertLValue(int a_position, T a_value){
			LinkedRawListLog(ame_Log_StartMethod, "insertLValue", "println", "");
			T* i_value = new T();
			*i_value = a_value;
			LinkedRawListLog(ame_Log_EndMethod, "insertLValue", "println", "");
			return this->insertPointer(a_position, i_value);
		}
		
		virtual T* getByLValue(T a_value){
			LinkedRawListLog(ame_Log_StartMethod, "getByLValue", "println", "");
			LinkedListNode<T>* i_node = this->getNodeByLValue(a_value);
			if(i_node == nullptr){
				return nullptr;
			}
			LinkedRawListLog(ame_Log_EndMethod, "getByLValue", "println", "");
			return i_node->get();
		}
		
		virtual bool containByLValue(T a_value){
			LinkedRawListLog(ame_Log_StartMethod, "containByLValue", "println", "");
			LinkedListNode<T>* i_node = this->getNodeByLValue(a_value);
			if(i_node == nullptr){
				return false;
			}
			LinkedRawPointerListLog(ame_Log_EndMethod, "containByLValue", "println", "");
			return true;
		}
		
		virtual int getIndexByLValue(T a_value){
			LinkedRawListLog(ame_Log_StartMethod, "getIndexByLValue", "println", "");
			LinkedListNode<T>* node = this->getStartNode();
			for(int count = 0; node != nullptr; count++){
				T* i_value = node->get();
				if(i_value == nullptr){
					node = this->getNextNode(node);
					continue;
				}
				if(a_value == *i_value){
					return count;
				}
				node = this->getNextNode(node);
			}
			LinkedRawListLog(ame_Log_EndMethod, "getIndexByLValue", "println", "");
			return -1;
		}

		virtual T* removeByLValue(T a_value){
			LinkedRawListLog(ame_Log_StartMethod, "removeByLValue", "println", "");
			LinkedListNode<T>* i_node = this->getNodeByLValue(a_value);
			if(i_node == nullptr){
				return nullptr;
			}
			i_node->removeNode();
			T* i_value = i_node->get();
			delete i_node;
			LinkedRawListLog(ame_Log_EndMethod, "removeByLValue", "println", "");
			return i_value;
		}
		
		virtual bool removeAll(T a_value){
			LinkedRawListLog(ame_Log_StartMethod, "removeAll", "println", "");
			LinkedListNode<T>* node = this->getStartNode();
			for(int count = 0; node != nullptr; count++){
				T* i_value = node->get();
				if(i_value == nullptr){
					node = this->getNextNode(node);
					continue;
				}
				if(a_value == *i_value){
					node->removeNode();
					if(this->isOwner()){
						delete i_value;
					}
					delete node;
				}
				node = this->getNextNode(node);
			}
			LinkedRawListLog(ame_Log_EndMethod, "removeAll", "println", "");
			return -1;
		}
		
		virtual bool removeFirst(T a_value){
			LinkedRawListLog(ame_Log_StartMethod, "removeFirst", "println", "");
			LinkedRawListLog(ame_Log_EndMethod, "removeFirst", "println", "");
			return this->removeDeleteByLValue(a_value);
		}
		
		virtual bool removeLast(T a_value){
			LinkedRawListLog(ame_Log_StartMethod, "removeLast", "println", "");
			LinkedListNode<T>* i_node = this->getNodeByLValueI(a_value);
			if(i_node == nullptr){
				return false;
			}
			i_node->removeNode();
			T* i_value = i_node->get();
			delete i_value;
			delete i_node;
			LinkedRawListLog(ame_Log_EndMethod, "removeLast", "println", "");
			return true;
		}
		
		virtual T& operator[](int x){
			LinkedRawListLog(ame_Log_StartMethod, "operator[]", "println", "");
			LinkedRawListLog(ame_Log_EndMethod, "operator[]", "println", "");
			return *this->getByPosition(x);
		}
		
		virtual LinkedIterator<T> begin(){
			LinkedRawListLog(ame_Log_StartMethod, "begin", "println", "");
			LinkedRawListLog(ame_Log_EndMethod, "begin", "println", "");
			return LinkedIterator<T>(this->getStartNode(),0);
		}
		virtual LinkedIterator<T> end(){
			LinkedRawListLog(ame_Log_StartMethod, "end", "println", "");
			LinkedRawListLog(ame_Log_EndMethod, "end", "println", this->getPosition());
			return LinkedIterator<T>(this->getStartNode(), this->getPosition());
		}
};

}

#endif