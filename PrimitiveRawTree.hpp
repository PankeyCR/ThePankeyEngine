
#ifndef PrimitiveRawTree_hpp
	#define PrimitiveRawTree_hpp

	#include "RawTree.hpp"
	#include "PrimitiveRawList.hpp"

	#ifdef PrimitiveRawTree_LogApp
		#include "pankey_Logger.hpp"
		#define PrimitiveRawTreeLog(location,method,type,mns) pankey_Log((void*)this,location,"PrimitiveRawTree",method,type,mns)
	#else
		#define PrimitiveRawTreeLog(location,method,type,mns)
	#endif

	namespace pankey{

		template<class T>
		class PrimitiveRawTree : public PrimitiveRawList<RawPointerTree<T>>, virtual public RawTree<T>{
			public:
				PrimitiveRawTree(){
					PrimitiveRawTreeLog(pankey_Log_StartMethod, "Constructor", "println", "");
					PrimitiveRawTreeLog(pankey_Log_EndMethod, "Constructor", "println", "");
				}
				
				PrimitiveRawTree(const PrimitiveRawTree<T>& a_list){
					PrimitiveRawTreeLog(pankey_Log_StartMethod, "Constructor", "println", "");
					this->expandLocal(a_list.getSize());
					for(int x = 0; x < a_list.getPosition(); x++){
						this->addPointer(a_list.getByPosition(x));
					}
					PrimitiveRawTreeLog(pankey_Log_EndMethod, "Constructor", "println", "");
				}
				
				PrimitiveRawTree(int c_size, bool c_own, bool c_reordering){
					PrimitiveRawTreeLog(pankey_Log_StartMethod, "Constructor", "println", "");
					// this->m_owner = c_own;
					// this->m_reorder = c_reordering;
					// this->expandLocal(c_size);
					PrimitiveRawTreeLog(pankey_Log_EndMethod, "Constructor", "println", "");
				}
				
				virtual ~PrimitiveRawTree(){
					PrimitiveRawTreeLog(pankey_Log_StartMethod, "Destructor", "println", "");
					// if(this->m_values != nullptr){
					// 	if(this->m_owner){
					// 		for(int x=0; x < this->getPosition() ; x++){
					// 			delete this->m_values[x];
					// 		}
					// 	}
					// 	this->setPosition(0);
					// 	this->setSize(0);
					// 	delete[] this->m_values;
					// 	this->m_values = nullptr;
					// }
					PrimitiveRawTreeLog(pankey_Log_EndMethod, "Destructor", "println", "");
				}

			protected:
                T* m_var = nullptr;
		};

	}

#endif