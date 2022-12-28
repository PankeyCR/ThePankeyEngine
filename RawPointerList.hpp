
#ifndef RawPointerList_hpp
#define RawPointerList_hpp
#define RawPointerList_AVAILABLE 

#ifdef RawPointerList_LogApp
	#include "ame_Logger_config.hpp"
	#include "ame_Logger.hpp"

	#define RawPointerListLog(location,method,type,mns) ame_Log((void*)this,location,"RawPointerList",method,type,mns)
	#define const_RawPointerListLog(location,method,type,mns)
#else
	#ifdef RawPointerList_LogDebugApp
		#include "ame_Logger_config.hpp"
		#include "ame_Logger.hpp"

		#define RawPointerListLog(location,method,type,mns) ame_LogDebug((void*)this,location,"RawPointerList",method,type)
		#define const_RawPointerListLog(location,method,type,mns)
	#else
		#define RawPointerListLog(location,method,type,mns)
		#define const_RawPointerListLog(location,method,type,mns)
	#endif
#endif

namespace ame{

template <class T>
class RawPointerList{
	protected:
	
	public:
		virtual ~RawPointerList(){
			RawPointerListLog(ame_Log_StartMethod, "Destructor", "println", "");
			RawPointerListLog(ame_Log_EndMethod, "Destructor", "println", "");
		}
		
		virtual bool isEmpty()const=0;
		
		virtual void setOwner(bool a_owning){
			RawPointerListLog(ame_Log_StartMethod, "isOwner", "println", "");
			this->m_owner = a_owning;
			RawPointerListLog(ame_Log_EndMethod, "isOwner", "println", "");
		}
		virtual bool isOwner()const{
			const_RawPointerListLog(ame_Log_StartMethod, "isOwner", "println", "");
			const_RawPointerListLog(ame_Log_EndMethod, "isOwner", "println", "");
			return this->m_owner;
		}
		virtual void setPosition(int a_position){
			RawPointerListLog(ame_Log_StartMethod, "setPosition", "println", "");
			this->m_position = a_position;
			RawPointerListLog(ame_Log_EndMethod, "setPosition", "println", "");
		}
		virtual int getPosition()const{
			const_RawPointerListLog(ame_Log_StartMethod, "getPosition", "println", "");
			const_RawPointerListLog(ame_Log_EndMethod, "getPosition", "println", "");
			return this->m_position;
		}
		
		virtual void setSize(int a_size){
			RawPointerListLog(ame_Log_StartMethod, "setSize", "println", "");
			this->m_size = a_size;
			RawPointerListLog(ame_Log_EndMethod, "setSize", "println", "");
		}
		virtual int getSize()const{
			const_RawPointerListLog(ame_Log_StartMethod, "getSize", "println", "");
			const_RawPointerListLog(ame_Log_EndMethod, "getSize", "println", "");
			return this->m_size;
		}

		virtual bool replace(int i, int j)=0;
		
		virtual void addMove(RawPointerList<T>* a_list){
			RawPointerListLog(ame_Log_StartMethod, "addMove", "println", "");
			for(int x = 0; x < a_list->getPosition(); x++){
				T* f_value = a_list->getByPosition(x);
				this->addPointer(f_value);
			}
			a_list->resetDelete();
			RawPointerListLog(ame_Log_EndMethod, "addMove", "println", "");
		}
		
		virtual void addDuplicate(RawPointerList<T>* a_list){
			RawPointerListLog(ame_Log_StartMethod, "addDuplicate", "println", "");
			for(int x = 0; x < a_list->getPosition(); x++){
				T* f_value = a_list->getByPosition(x);
				this->addPointer(f_value);
			}
			RawPointerListLog(ame_Log_EndMethod, "addDuplicate", "println", "");
		}

		virtual T* addPointer(T* a_value)=0;
		
		virtual T* putPointer(T* a_value){
			RawPointerListLog(ame_Log_StartMethod, "putPointer", "println", "");
			if(this->containByPointer(a_value)){
				return nullptr;
			}
			RawPointerListLog(ame_Log_EndMethod, "putPointer", "println", "");
			return this->addPointer(a_value);
		}

		virtual T* setPointer(int a_position, T* a_value)=0;

		virtual T* insertPointer(int a_position, T* a_value)=0;

		virtual T* getByPointer(T* a_value)=0;
		virtual T* getByPosition(int x)const=0;

		virtual bool containByPointer(T* a_value)=0;
		
		virtual int getIndexByPointer(T* a_value)=0;

		virtual void reset()=0;
		virtual void resetDelete()=0;

		virtual T* removeByPointer(T* a_value)=0;

		virtual T* removeByPosition(int a_position)=0;

		virtual bool removeDeleteByPointer(T* a_value){
			RawPointerListLog(ame_Log_StartMethod, "removeDeleteByPointer", "println", "");
			T* t = this->removeByPointer(a_value);
			bool removed = t != nullptr;
			if(removed && isOwner()){
				delete t;
			}
			RawPointerListLog(ame_Log_EndMethod, "removeDeleteByPointer", "println", "");
			return removed;
		}

		virtual bool removeDeleteByPosition(int a_position){
			RawPointerListLog(ame_Log_StartMethod, "removeDeleteByPosition", "println", "");
			T* t = this->removeByPosition(a_position);
			bool removed = t != nullptr;
			if(removed && isOwner()){
				delete t;
			}
			RawPointerListLog(ame_Log_EndMethod, "removeDeleteByPosition", "println", "");
			return removed;
		}

		//special removes
		virtual bool removeFirstIndex(int a_amount)=0;
		virtual bool removeLastIndex(int a_amount)=0;
		
		virtual bool removeFirst(){
			RawPointerListLog(ame_Log_StartMethod, "removeFirst", "println", "");
			if(this->isEmpty()){
				return false;
			}
			RawPointerListLog(ame_Log_EndMethod, "removeFirst", "println", "");
			return this->removeDeleteByPosition(0);
		}

		virtual bool removeLast(){
			RawPointerListLog(ame_Log_StartMethod, "removeLast", "println", "");
			if(this->isEmpty()){
				return false;
			}
			RawPointerListLog(ame_Log_EndMethod, "removeLast", "println", "");
			return this->removeDeleteByPosition(this->getPosition() - 1);
		}

		virtual bool isInOrder(){return this->m_reorder;}
		virtual void setReorder(bool a_reorder){this->m_reorder = a_reorder;}
		virtual void reorder(){}
		
	protected:
		
		virtual void incrementPosition(){
			RawPointerListLog(ame_Log_StartMethod, "incrementPosition", "println", "");
			this->m_position++;
			RawPointerListLog(ame_Log_EndMethod, "incrementPosition", "println", "");
		}
		virtual void decrementPosition(){
			RawPointerListLog(ame_Log_StartMethod, "decrementPosition", "println", "");
			this->m_position--;
			if(this->m_position < 0){
				this->m_position = 0;
			}
			RawPointerListLog(ame_Log_EndMethod, "decrementPosition", "println", "");
		}
		
		virtual void incrementPosition(int a_size){
			RawPointerListLog(ame_Log_StartMethod, "incrementPosition", "println", "");
			this->m_position += a_size;
			RawPointerListLog(ame_Log_EndMethod, "incrementPosition", "println", "");
		}
		virtual void decrementPosition(int a_size){
			RawPointerListLog(ame_Log_StartMethod, "decrementPosition", "println", "");
			this->m_position -= a_size;
			if(this->m_position < 0){
				this->m_position = 0;
			}
			RawPointerListLog(ame_Log_EndMethod, "decrementPosition", "println", "");
		}
		
		virtual void incrementSize(){
			RawPointerListLog(ame_Log_StartMethod, "incrementSize", "println", "");
			this->m_size++;
			RawPointerListLog(ame_Log_EndMethod, "incrementSize", "println", "");
		}
		virtual void decrementSize(){
			RawPointerListLog(ame_Log_StartMethod, "decrementSize", "println", "");
			this->m_size--;
			if(this->m_size < 0){
				this->m_size = 0;
			}
			RawPointerListLog(ame_Log_EndMethod, "decrementSize", "println", "");
		}
		
		virtual void incrementSize(int a_size){
			RawPointerListLog(ame_Log_StartMethod, "incrementSize", "println", "");
			this->m_size += a_size;
			RawPointerListLog(ame_Log_EndMethod, "incrementSize", "println", "");
		}
		virtual void decrementSize(int a_size){
			RawPointerListLog(ame_Log_StartMethod, "decrementSize", "println", "");
			this->m_size -= a_size;
			if(this->m_size < 0){
				this->m_size = 0;
			}
			RawPointerListLog(ame_Log_EndMethod, "decrementSize", "println", "");
		}

	public:
	
		virtual bool operator<(int x) const{
			const_RawPointerListLog(ame_Log_StartMethod, "operator<", "println", "");
			const_RawPointerListLog(ame_Log_EndMethod, "operator<", "println", "");
			return this->getPosition() < x;
		}
		
		virtual bool operator>(int x) const{
			const_RawPointerListLog(ame_Log_StartMethod, "operator>", "println", "");
			const_RawPointerListLog(ame_Log_EndMethod, "operator>", "println", "");
			return this->getPosition() > x;
		}
		
		virtual bool operator<=(int x) const{
			const_RawPointerListLog(ame_Log_StartMethod, "operator<=", "println", "");
			const_RawPointerListLog(ame_Log_EndMethod, "operator<=", "println", "");
			return this->getPosition() <= x;
		}
		
		virtual bool operator>=(int x) const{
			const_RawPointerListLog(ame_Log_StartMethod, "operator>=", "println", "");
			const_RawPointerListLog(ame_Log_EndMethod, "operator>=", "println", "");
			return this->getPosition() >= x;
		}
		
		virtual bool operator==(int x) const{
			const_RawPointerListLog(ame_Log_StartMethod, "operator==", "println", "");
			const_RawPointerListLog(ame_Log_EndMethod, "operator==", "println", "");
			return this->getPosition() == x;
		}
		
		virtual bool operator!=(int x) const{
			const_RawPointerListLog(ame_Log_StartMethod, "operator!=", "println", "");
			const_RawPointerListLog(ame_Log_EndMethod, "operator!=", "println", "");
			return this->getPosition() != x;
		}

	protected:
		bool m_reorder = true;
		bool m_owner = true;
		int m_position = 0;
		int m_size = 0;
};

}

#endif