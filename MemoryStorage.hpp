
#ifndef MemoryStorage_hpp
	#define MemoryStorage_hpp

	#include "MemoryHolder.hpp"

	#ifdef MemoryStorage_LogApp
		#include "pankey_Logger.hpp"
		#define MemoryStorageLog(location,method,type,mns) pankey_Log((void*)this,location,"MemoryStorage",method,type,mns)
	#else
		#define MemoryStorageLog(location,method,type,mns)
	#endif

	namespace pankey{

		template<class H>
		class MemoryStorage{
			public:

                using MANAGER_TYPE = typename MemoryHolder<H>::MANAGER_TYPE;
                using VOID_TYPE = typename MemoryHolder<H>::VOID_TYPE;
                using HOLDER_TYPE = typename MemoryHolder<H>::HOLDER_TYPE;
                using HOLDER_ARRAY_TYPE = H**;

				virtual ~MemoryStorage(){
					MemoryStorageLog(pankey_Log_StartMethod, "Destructor", "println", "");
					MemoryStorageLog(pankey_Log_EndMethod, "Destructor", "println", "");
				}
				
				virtual void setManager(MANAGER_TYPE a_Manager)=0;
				virtual MANAGER_TYPE getManager()const=0;
				
				virtual bool isNull()const=0;
				
				virtual bool isNull(int a_index)const=0;
				
				virtual int getSize() const {return this->m_size;}
				
				virtual bool replace(int a_index_1, int a_index_2)=0;
				
				virtual bool set(int a_position, MemoryHolder<H>& a_value)=0;
				
				virtual bool add(int a_position, MemoryHolder<H>& a_value)=0;

				virtual bool contain(const MemoryHolder<H>& a_value)const=0;
				
				virtual int getIndex(const MemoryHolder<H>& a_value)const=0;
				
				virtual VOID_TYPE getRawPointer(int a_position)const=0;
				
				virtual HOLDER_TYPE getHolder(int a_position)const=0;

				virtual bool removeByPointer(const MemoryHolder<H>& a_value)=0;

				virtual bool removeFirstIndex(int a_length, int a_amount)=0;

				virtual bool removeLastIndex(int a_length, int a_amount)=0;

				virtual bool removePart(int a_index, int a_length, int a_amount)=0;

				virtual bool removeFirst()=0;

				virtual bool removeLast()=0;

				virtual bool clear()=0;

				virtual int reorder()=0;

				virtual int reorder(int a_index, int a_length, int a_amount)=0;

				virtual int reorder(int a_index, int a_length)=0;

				//inserts space on the array, moves the variables from the index to the size specified
				virtual int insert(int a_index, int a_length, int a_size)=0;//return a_index + a_size - 1

				virtual bool expand(int a_adding_size)=0;
				
				virtual bool shrink(int a_amount)=0;
				
				virtual bool destroy()=0;
				
				template<class IM>
				void forEach(IM a_iteration_method){
					MemoryStorageLog(pankey_Log_StartMethod, "forEach", "println", "");
					if(this->isNull() || this->getSize() <= 0){
						MemoryStorageLog(pankey_Log_EndMethod, "forEach", "println", "this->isNull() || this->getSize() <= 0");
						return;
					}
					for(int x = 0; x < this->getSize(); x++){
						HOLDER_TYPE f_pointer = this->getHolder(x);
						a_iteration_method(x, this->getSize(), f_pointer);
					}
					MemoryStorageLog(pankey_Log_EndMethod, "forEach", "println", "");
				}
				
				template<class IM>
				void forEachNotNull(IM a_iteration_method){
					MemoryStorageLog(pankey_Log_StartMethod, "forEachNotNull", "println", "");
					if(this->isNull() || this->getSize() <= 0){
						MemoryStorageLog(pankey_Log_EndMethod, "forEachNotNull", "println", "this->isNull() || this->getSize() <= 0");
						return;
					}
					for(int x = 0; x < this->getSize(); x++){
						HOLDER_TYPE f_pointer = this->getHolder(x);
						if(f_pointer == nullptr){
							MemoryStorageLog(pankey_Log_Statement, "forEachNotNull", "println", "f_pointer == nullptr");
							continue;
						}
						a_iteration_method(x, this->getSize(), f_pointer);
					}
					MemoryStorageLog(pankey_Log_EndMethod, "forEachNotNull", "println", "");
				}
				
			protected:
				int m_size = 0;
		};

	}

#endif