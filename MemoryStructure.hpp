
#ifndef MemoryStructure_hpp
	#define MemoryStructure_hpp

	#ifdef MemoryStructure_LogApp
		#include "higgs_Logger.hpp"
		#define MemoryStructureLog(location,method,type,mns) higgs_Log((void*)this,location,"MemoryStructure",method,type,mns)
	#else
		#define MemoryStructureLog(location,method,type,mns)
	#endif

	namespace higgs{

		template<class T>
		class MemoryStructure{
			public:
				
				virtual ~MemoryStructure<T>(){
					MemoryStructureLog(higgs_Log_StartMethod, "Destructor", "println", "");
					MemoryStructureLog(higgs_Log_EndMethod, "Destructor", "println", "");
				}
                
                virtual void setOwner(bool a_owning){
                    MemoryStructureLog(higgs_Log_StartMethod, "isOwner", "println", "");
                    this->m_owner = a_owning;
                    MemoryStructureLog(higgs_Log_Statement, "isOwner", "println", "isOwner:");
                    MemoryStructureLog(higgs_Log_Statement, "isOwner", "println", this->m_owner);
                    MemoryStructureLog(higgs_Log_EndMethod, "isOwner", "println", "");
                }
                virtual bool isOwner()const{
                    MemoryStructureLog(higgs_Log_StartMethod, "isOwner", "println", "");
                    MemoryStructureLog(higgs_Log_Statement, "isOwner", "println", "isOwner:");
                    MemoryStructureLog(higgs_Log_Statement, "isOwner", "println", this->m_owner);
                    MemoryStructureLog(higgs_Log_EndMethod, "isOwner", "println", "");
                    return this->m_owner;
                }
				
				virtual bool isNull()const=0;
				
				virtual bool isNull(int a_index)const=0;
				
				virtual int getSize() const {return this->m_size;}
				
				virtual bool add(int a_position, T* a_value)=0;

				virtual bool containByPointer(T* a_value)const=0;
				
				virtual int getIndexByPointer(T* a_value)const=0;
				
				virtual T* getRawPointer(int a_index)const=0;

				virtual bool removeByPointer(T* a_value)=0;
				virtual bool removeByIndex(int a_index)=0;

				virtual bool clear()=0;

				virtual bool expand(int a_adding_size)=0;
				
				virtual bool destroy()=0;
				
			protected:
				int m_size = 0;
		};

	}

#endif