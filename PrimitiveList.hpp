
#ifndef PrimitiveList_hpp
	#define PrimitiveList_hpp

	#include "higgs_ErrorWarning.hpp"
	#include "PrimitiveRawList.hpp"
	#include "ListIterator.hpp"

	#ifdef PrimitiveList_LogApp
		#include "higgs_Logger.hpp"
		#define PrimitiveListLog(location,method,type,mns) ame_Log((void*)this,location,"PrimitiveList",method,type,mns)
	#else
		#define PrimitiveListLog(location,method,type,mns) 
	#endif

	namespace higgs{

		template<class T>
		class PrimitiveList : protected PrimitiveRawList<T>, public SafeList<T>{
			public:
				PrimitiveList(){}
				
				PrimitiveList(const PrimitiveList<T>& a_list){
					this->m_values = new T*[a_list.getSize()];
					this->m_size = a_list.getSize();
					for(int x = 0; x < a_list.getPosition(); x++){
						T* f_value = a_list.getByPosition(x);
						if(f_value == nullptr){
							this->addPointer(nullptr);
							continue;
						}
						this->addLValue(*f_value);
					}
				}
				
				PrimitiveList(int c_size, bool c_own, bool c_reordering) : PrimitiveRawList<T>(c_size, c_own, c_reordering){}
				
				virtual ~PrimitiveList(){}















				
				virtual PrimitiveList<T>& operator=(const PrimitiveList<T>& a_list){
					this->resetDelete();
					for(int x = 0; x < a_list.getPosition(); x++){
						T* f_list_value = a_list.getByPosition(x);
						if(f_list_value == nullptr){
							this->addPointer(nullptr);
							continue;
						}
						this->addLValue(*a_list.getByPosition(x));
					}
					return *this;
				}
				
				virtual bool operator==(const PrimitiveList<T>& a_list){
					if(this->getPosition() != a_list.getPosition()){
						return false;
					}
					for(int x = 0; x < a_list.getPosition(); x++){
						T* f_list_value = a_list.getByPosition(x);
						T* f_value = this->getByPosition(x);
						if(f_list_value == nullptr && f_value == nullptr){
							continue;
						}
						if(f_list_value == nullptr || f_value == nullptr){
							return false;
						}
						if(*f_list_value != *f_value){
							return false;
						}
					}
					return true;
				}

				virtual bool operator!=(const PrimitiveList<T>& a_list){
					if(this->getPosition() != a_list.getPosition()){
						return true;
					}
					for(int x = 0; x < a_list.getPosition(); x++){
						T* f_list_value = a_list.getByPosition(x);
						T* f_value = this->getByPosition(x);
						if(f_list_value == nullptr && f_value == nullptr){
							continue;
						}
						if(f_list_value == nullptr || f_value == nullptr){
							return true;
						}
						if(*f_list_value != *f_value){
							return true;
						}
					}
					return false;
				}
				
			protected:
		};

	}

#endif