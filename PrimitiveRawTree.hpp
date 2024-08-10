
#ifndef PrimitiveRawTree_hpp
	#define PrimitiveRawTree_hpp

	#include "RawTree.hpp"
	#include "PrimitiveRawList.hpp"

	#ifdef PrimitiveRawTree_LogApp
		#include "higgs_Logger.hpp"
		#define PrimitiveRawTreeLog(location,method,type,mns) higgs_Log((void*)this,location,"PrimitiveRawTree",method,type,mns)
	#else
		#define PrimitiveRawTreeLog(location,method,type,mns)
	#endif

	namespace higgs{

		template<class T>
		class PrimitiveRawTree : public PrimitiveRawList<RawPointerTree<T>>, virtual public RawTree<T>{
			public:
				PrimitiveRawTree(){
					PrimitiveRawTreeLog(higgs_Log_StartMethod, "Constructor", "println", "");
					PrimitiveRawTreeLog(higgs_Log_EndMethod, "Constructor", "println", "");
				}
				
				PrimitiveRawTree(const PrimitiveRawTree<T>& a_list){
					PrimitiveRawTreeLog(higgs_Log_StartMethod, "Constructor", "println", "");
					this->expandLocal(a_list.getSize());
					for(int x = 0; x < a_list.getPosition(); x++){
						this->addPointer(a_list.getByPosition(x));
					}
					PrimitiveRawTreeLog(higgs_Log_EndMethod, "Constructor", "println", "");
				}
				
				PrimitiveRawTree(int c_size, bool c_own, bool c_reordering){
					PrimitiveRawTreeLog(higgs_Log_StartMethod, "Constructor", "println", "");
					// this->m_owner = c_own;
					// this->m_reorder = c_reordering;
					// this->expandLocal(c_size);
					PrimitiveRawTreeLog(higgs_Log_EndMethod, "Constructor", "println", "");
				}
				
				virtual ~PrimitiveRawTree(){
					PrimitiveRawTreeLog(higgs_Log_StartMethod, "Destructor", "println", "");
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
					PrimitiveRawTreeLog(higgs_Log_EndMethod, "Destructor", "println", "");
				}

			protected:
                T* m_var = nullptr;
		};

	}

#endif