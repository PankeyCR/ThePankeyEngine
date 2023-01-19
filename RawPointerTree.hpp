
#ifndef RawPointerTree_hpp
#define RawPointerTree_hpp
#define RawPointerTree_AVAILABLE

#include "MemoryAllocator.hpp"

#ifdef RawPointerTree_LogApp
	#include "ame_Logger_config.hpp"
	#include "ame_Logger.hpp"

	#define RawPointerTreeLog(location,method,type,mns) ame_Log((void*)this,location,"RawPointerTree",method,type,mns)
	#define const_RawPointerTreeLog(location,method,type,mns)
#else
	#ifdef RawPointerTree_LogDebugApp
		#include "ame_Logger_config.hpp"
		#include "ame_Logger.hpp"

		#define RawPointerTreeLog(location,method,type,mns) ame_LogDebug((void*)this,location,"RawPointerTree",method,type)
		#define const_RawPointerTreeLog(location,method,type,mns)
	#else
		#define RawPointerTreeLog(location,method,type,mns)
		#define const_RawPointerTreeLog(location,method,type,mns)
	#endif
#endif

namespace ame{

template<class T>
class RawPointerTree{
	public:
		RawPointerTree(){}

		RawPointerTree(const RawPointerTree<T>& c_RawPointerTree){
			this->m_allocator = c_RawPointerTree.cloneAllocator();
		}

		virtual ~RawPointerTree(){}
		
		virtual void addMoveTree(RawPointerTree<T>* a_list){
			RawPointerTreeLog(ame_Log_StartMethod, "addMove", "println", "");
			MemoryAllocator<T>* i_allocator = this->getTreeAllocator();
			if(i_allocator == nullptr){
				return;
			}
			for(int x = 0; x < i_allocator->getPosition(); x++){
				T* f_value = a_list->getByBranchPosition(x);
				this->addBranchPointer(f_value);
			}
			i_allocator->clear();
			RawPointerTreeLog(ame_Log_EndMethod, "addMove", "println", "");
		}
		
		virtual void addDuplicateTree(RawPointerTree<T>* a_list){
			RawPointerTreeLog(ame_Log_StartMethod, "addDuplicate", "println", "");
			MemoryAllocator<T>* i_allocator = this->getTreeAllocator();
			if(i_allocator == nullptr){
				return;
			}
			for(int x = 0; x < i_allocator->getPosition(); x++){
				T* f_value = a_list->getByBranchPosition(x);
				this->addBranchPointer(f_value);
			}
			RawPointerTreeLog(ame_Log_EndMethod, "addDuplicate", "println", "");
		}

		virtual T* addBranchPointer(T* a_value){
			RawPointerTreeLog(ame_Log_StartMethod, "addTreePointer", "println", "");
			MemoryAllocator<T>* i_allocator = this->getTreeAllocator();
			if(i_allocator == nullptr){
				return;
			}
			RawPointerTreeLog(ame_Log_EndMethod, "addTreePointer", "println", "");
			return i_allocator->addPointer(a_value);
		}
		
		virtual T* putBranchPointer(T* a_value){
			RawPointerTreeLog(ame_Log_StartMethod, "putPointer", "println", "");
			MemoryAllocator<T>* i_allocator = this->getTreeAllocator();
			if(i_allocator == nullptr){
				return;
			}
			if(i_allocator->containByPointer(a_value)){
				return nullptr;
			}
			RawPointerTreeLog(ame_Log_EndMethod, "putPointer", "println", "");
			return i_allocator->addPointer(a_value);
		}

		virtual T* setBranchPointer(int a_position, T* a_value){
			RawPointerTreeLog(ame_Log_StartMethod, "setBranchPointer", "println", "");
			MemoryAllocator<T>* i_allocator = this->getTreeAllocator();
			if(i_allocator == nullptr){
				return;
			}
			if(i_allocator->containByPointer(a_value)){
				return nullptr;
			}
			RawPointerTreeLog(ame_Log_EndMethod, "setBranchPointer", "println", "");
			return i_allocator->setPointer(a_position, a_value);
		}

		virtual T* insertBranchPointer(int a_position, T* a_value){
			RawPointerTreeLog(ame_Log_StartMethod, "setBranchPointer", "println", "");
			MemoryAllocator<T>* i_allocator = this->getTreeAllocator();
			if(i_allocator == nullptr){
				return;
			}
			if(i_allocator->containByPointer(a_value)){
				return nullptr;
			}
			RawPointerTreeLog(ame_Log_EndMethod, "setBranchPointer", "println", "");
			return i_allocator->setPointer(a_position, a_value);
		}

		virtual T* getByBranchPointer(T* a_value){
			RawPointerTreeLog(ame_Log_StartMethod, "setBranchPointer", "println", "");
			MemoryAllocator<T>* i_allocator = this->getTreeAllocator();
			if(i_allocator == nullptr){
				return;
			}
			if(i_allocator->containByPointer(a_value)){
				return nullptr;
			}
			RawPointerTreeLog(ame_Log_EndMethod, "setBranchPointer", "println", "");
			return i_allocator->setPointer(a_position, a_value);
		}

		virtual T* getByBranchPosition(int x)const{
			RawPointerTreeLog(ame_Log_StartMethod, "setBranchPointer", "println", "");
			MemoryAllocator<T>* i_allocator = this->getTreeAllocator();
			if(i_allocator == nullptr){
				return;
			}
			if(i_allocator->containByPointer(a_value)){
				return nullptr;
			}
			RawPointerTreeLog(ame_Log_EndMethod, "setBranchPointer", "println", "");
			return i_allocator->setPointer(a_position, a_value);
		}

		virtual bool containByBranchPointer(T* a_value){
			RawPointerTreeLog(ame_Log_StartMethod, "setBranchPointer", "println", "");
			MemoryAllocator<T>* i_allocator = this->getTreeAllocator();
			if(i_allocator == nullptr){
				return;
			}
			if(i_allocator->containByPointer(a_value)){
				return nullptr;
			}
			RawPointerTreeLog(ame_Log_EndMethod, "setBranchPointer", "println", "");
			return i_allocator->setPointer(a_position, a_value);
		}
		
		virtual int getIndexByBranchPointer(T* a_value){
			RawPointerTreeLog(ame_Log_StartMethod, "setBranchPointer", "println", "");
			MemoryAllocator<T>* i_allocator = this->getTreeAllocator();
			if(i_allocator == nullptr){
				return;
			}
			if(i_allocator->containByPointer(a_value)){
				return nullptr;
			}
			RawPointerTreeLog(ame_Log_EndMethod, "setBranchPointer", "println", "");
			return i_allocator->setPointer(a_position, a_value);
		}

		virtual T* removeByBranchPointer(T* a_value){
			RawPointerTreeLog(ame_Log_StartMethod, "setBranchPointer", "println", "");
			MemoryAllocator<T>* i_allocator = this->getTreeAllocator();
			if(i_allocator == nullptr){
				return;
			}
			if(i_allocator->containByPointer(a_value)){
				return nullptr;
			}
			RawPointerTreeLog(ame_Log_EndMethod, "setBranchPointer", "println", "");
			return i_allocator->setPointer(a_position, a_value);
		}

		virtual T* removeByBranchPosition(int a_position){
			RawPointerTreeLog(ame_Log_StartMethod, "setBranchPointer", "println", "");
			MemoryAllocator<T>* i_allocator = this->getTreeAllocator();
			if(i_allocator == nullptr){
				return;
			}
			if(i_allocator->containByPointer(a_value)){
				return nullptr;
			}
			RawPointerTreeLog(ame_Log_EndMethod, "setBranchPointer", "println", "");
			return i_allocator->setPointer(a_position, a_value);
		}

		virtual bool removeDeleteByBranchPointer(T* a_value){
			RawPointerTreeLog(ame_Log_StartMethod, "removeDeleteByPointer", "println", "");
			T* t = this->removeByPointer(a_value);
			bool removed = t != nullptr;
			if(removed && isOwner()){
				delete t;
			}
			RawPointerTreeLog(ame_Log_EndMethod, "removeDeleteByPointer", "println", "");
			return removed;
		}

		virtual bool removeDeleteByBranchPosition(int a_position){
			RawPointerTreeLog(ame_Log_StartMethod, "removeDeleteByPosition", "println", "");
			T* t = this->removeByPosition(a_position);
			bool removed = t != nullptr;
			if(removed && isOwner()){
				delete t;
			}
			RawPointerTreeLog(ame_Log_EndMethod, "removeDeleteByPosition", "println", "");
			return removed;
		}

		//special removes
		virtual bool removeFirstBranchesByIndexAmount(int a_amount){
			RawPointerTreeLog(ame_Log_StartMethod, "setBranchPointer", "println", "");
			MemoryAllocator<T>* i_allocator = this->getTreeAllocator();
			if(i_allocator == nullptr){
				return;
			}
			if(i_allocator->containByPointer(a_value)){
				return nullptr;
			}
			RawPointerTreeLog(ame_Log_EndMethod, "setBranchPointer", "println", "");
			return i_allocator->setPointer(a_position, a_value);
		}
		virtual bool removeLastBranchesByIndexAmountx(int a_amount){
			RawPointerTreeLog(ame_Log_StartMethod, "setBranchPointer", "println", "");
			MemoryAllocator<T>* i_allocator = this->getTreeAllocator();
			if(i_allocator == nullptr){
				return;
			}
			if(i_allocator->containByPointer(a_value)){
				return nullptr;
			}
			RawPointerTreeLog(ame_Log_EndMethod, "setBranchPointer", "println", "");
			return i_allocator->setPointer(a_position, a_value);
		}
		
		virtual bool removeFirstBranch(){
			RawPointerTreeLog(ame_Log_StartMethod, "removeFirst", "println", "");
			if(this->isEmpty()){
				return false;
			}
			RawPointerTreeLog(ame_Log_EndMethod, "removeFirst", "println", "");
			return this->removeDeleteByPosition(0);
		}

		virtual bool removeLastBranch(){
			RawPointerTreeLog(ame_Log_StartMethod, "removeLast", "println", "");
			if(this->isEmpty()){
				return false;
			}
			RawPointerTreeLog(ame_Log_EndMethod, "removeLast", "println", "");
			return this->removeDeleteByPosition(this->getPosition() - 1);
		}

		virtual void setTreeAllocator(MemoryAllocator<T>* a_allocator){
			if(this->m_allocator != nullptr && a_allocator != this->m_allocator){
				delete this->m_allocator;
			}
			m_allocator = a_allocator;
		}

		virtual MemoryAllocator<T>* getTreeAllocator(){
			return m_allocator;
		}

		virtual MemoryAllocator<T>* cloneAllocator(){
			if(this->m_allocator == nullptr){
				return nullptr;
			}
			RawPointerTreeLog(ame_Log_EndMethod, "removeLast", "println", "");
			return this->m_allocator->clone();
		}

		virtual void operator=(const RawPointerTree<T>& a_tree){}

		virtual bool operator==(const RawPointerTree<T>& a_tree){
			return false;
		}

		virtual bool operator!=(const RawPointerTree<T>& a_tree){
			return false;
		}
	
	protected:
		MemoryAllocator<T>* m_allocator = nullptr;
};

}

#endif