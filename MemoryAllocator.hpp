
#ifndef MemoryAllocator_hpp
#define MemoryAllocator_hpp
#define MemoryAllocator_AVAILABLE

#ifdef MemoryAllocator_LogApp
	#include "ame_Logger_config.hpp"
	#include "ame_Logger.hpp"

	#define MemoryAllocatorLog(location,method,type,mns) ame_Log((void*)this,location,"MemoryAllocator",method,type,mns)
	#define const_MemoryAllocatorLog(location,method,type,mns)
#else
	#ifdef MemoryAllocator_LogDebugApp
		#include "ame_Logger_config.hpp"
		#include "ame_Logger.hpp"

		#define MemoryAllocatorLog(location,method,type,mns) ame_LogDebug((void*)this,location,"MemoryAllocator",method,type)
		#define const_MemoryAllocatorLog(location,method,type,mns)
	#else
		#define MemoryAllocatorLog(location,method,type,mns)
		#define const_MemoryAllocatorLog(location,method,type,mns)
	#endif
#endif

namespace ame{

template<class T>
class MemoryAllocator{
	public:
		MemoryAllocator(){}
		virtual ~MemoryAllocator(){}
		
		virtual bool isEmpty()const=0;
		
		virtual void setOwner(bool a_owning){
			MemoryAllocatorLog(ame_Log_StartMethod, "isOwner", "println", "");
			this->m_owner = a_owning;
			MemoryAllocatorLog(ame_Log_EndMethod, "isOwner", "println", "");
		}
		virtual bool isOwner()const{
			const_MemoryAllocatorLog(ame_Log_StartMethod, "isOwner", "println", "");
			const_MemoryAllocatorLog(ame_Log_EndMethod, "isOwner", "println", "");
			return this->m_owner;
		}
		virtual void setPosition(int a_position){
			MemoryAllocatorLog(ame_Log_StartMethod, "setPosition", "println", "");
			this->m_position = a_position;
			MemoryAllocatorLog(ame_Log_EndMethod, "setPosition", "println", "");
		}
		virtual int getPosition()const{
			const_MemoryAllocatorLog(ame_Log_StartMethod, "getPosition", "println", "");
			const_MemoryAllocatorLog(ame_Log_EndMethod, "getPosition", "println", "");
			return this->m_position;
		}
		
		virtual void setSize(int a_size){
			MemoryAllocatorLog(ame_Log_StartMethod, "setSize", "println", "");
			this->m_size = a_size;
			MemoryAllocatorLog(ame_Log_EndMethod, "setSize", "println", "");
		}
		virtual int getSize()const{
			const_MemoryAllocatorLog(ame_Log_StartMethod, "getSize", "println", "");
			const_MemoryAllocatorLog(ame_Log_EndMethod, "getSize", "println", "");
			return this->m_size;
		}
		
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

		virtual bool replace(int i, int j)=0;

		virtual T* addPointer(T* a_value)=0;
		
		virtual T* putPointer(T* a_value){
			MemoryAllocatorLog(ame_Log_StartMethod, "putPointer", "println", "");
			if(this->containByPointer(a_value)){
				return nullptr;
			}
			MemoryAllocatorLog(ame_Log_EndMethod, "putPointer", "println", "");
			return this->addPointer(a_value);
		}

		virtual T* setPointer(int a_position, T* a_value)=0;

		virtual T* insertPointer(int a_position, T* a_value)=0;

		virtual T* getByPointer(T* a_value)=0;
		virtual T* getByPosition(int x)const=0;

		virtual bool containByPointer(T* a_value)=0;
		
		virtual int getIndexByPointer(T* a_value)=0;

		virtual void clear()=0;

		virtual T* removeByPointer(T* a_value)=0;

		virtual T* removeByPosition(int a_position)=0;

		//special removes
		virtual bool removeFirstIndex(int a_amount)=0;
		virtual bool removeLastIndex(int a_amount)=0;

		virtual bool isInOrder(){return this->m_reorder;}
		virtual void setReorder(bool a_reorder){this->m_reorder = a_reorder;}
		virtual void reorder(){}


		virtual MemoryAllocator<T>* clone()=0;

		virtual void operator=(const MemoryAllocator<T>& c_MemoryAllocator){}
		virtual bool operator==(MemoryAllocator<T> b){return false;}
		virtual bool operator!=(MemoryAllocator<T> b){return false;}
	
	protected:
		bool m_reorder = true;
		bool m_owner = true;
		int m_position = 0;
		int m_size = 0;
};

}

#endif