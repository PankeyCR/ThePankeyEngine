
#ifndef ValueArrayMapCollection_hpp
	#define ValueArrayMapCollection_hpp

	#include "Collection.hpp"
	#include "MemberArrayMapCollection.hpp"
	#include "DuoMember.hpp"
	#include "ValueMapCollection.hpp"

	#ifdef ValueArrayMapCollection_LogApp
		#include "pankey_Logger.hpp"
		#define ValueArrayMapCollectionLog(location,method,type,mns) pankey_Log((void*)this,location,"ValueArrayMapCollection",method,type,mns)
	#else
		#define ValueArrayMapCollectionLog(location,method,type,mns)
	#endif

	namespace pankey{

		template<class T, class H>
		bool ValueArrayMapCollection_FromPointer(void* a_pointer_1, void* a_pointer_2){
			if(a_pointer_1 == nullptr || a_pointer_2 == nullptr){
				return false;
			}
			T* i_pointer_1 = (T*)a_pointer_1;
			T* i_pointer_2 = (T*)a_pointer_2;
			return (*i_pointer_1) == (*i_pointer_2);
		}

		template<class K, class V, class H, class M>
		class ValueArrayMapCollection : public MemberArrayMapCollection<H,M>, virtual public ValueMapCollection<K,V,H,M>{
			public:
				ValueArrayMapCollection(){
					ValueArrayMapCollectionLog(pankey_Log_StartMethod, "Constructor", "println", "");
					ValueArrayMapCollectionLog(pankey_Log_EndMethod, "Constructor", "println", "");
				}

				virtual ~ValueArrayMapCollection(){
					ValueArrayMapCollectionLog(pankey_Log_StartMethod, "Destructor", "println", "");
					ValueArrayMapCollectionLog(pankey_Log_EndMethod, "Destructor", "println", "");
				}

				virtual Member<H,M> getKeyByValue(const Member<H,M>& a_value)const{
					ValueArrayMapCollectionLog(pankey_Log_StartMethod, "getKeyByValue", "println", "");
					int i_index = this->m_values.getIndex(ValueArrayMapCollection_FromPointer<K,H>, a_value);
					if(i_index == -1){
						ValueArrayMapCollectionLog(pankey_Log_Statement, "getKeyByValue", "println", "i_index == -1");
						return Member<H,M>();
					}
					ValueArrayMapCollectionLog(pankey_Log_EndMethod, "getKeyByValue", "println", "");
					return this->m_keys.get(i_index);
				}

				virtual Member<H,M> getValueByValue(const Member<H,M>& a_value)const{
					ValueArrayMapCollectionLog(pankey_Log_StartMethod, "getValueByValue", "println", "");
					int i_index = this->m_keys.getIndex(ValueArrayMapCollection_FromPointer<K,H>, a_value);
					if(i_index == -1){
						ValueArrayMapCollectionLog(pankey_Log_EndMethod, "getValueByValue", "println", "i_index == -1");
						return Member<H,M>();
					}
					ValueArrayMapCollectionLog(pankey_Log_EndMethod, "getValueByValue", "println", "");
					return this->m_values.get(i_index);
				}

				virtual bool containByValue(const Member<H,M>& a_value)const{
					ValueArrayMapCollectionLog(pankey_Log_StartMethod, "containByValue", "println", "");
					ValueArrayMapCollectionLog(pankey_Log_EndMethod, "containByValue", "println", "");
					return true;
				}
				
				virtual int getIndexByValue(const Member<H,M>& a_value)const{
					ValueArrayMapCollectionLog(pankey_Log_StartMethod, "getIndexByValue", "println", "");
					ValueArrayMapCollectionLog(pankey_Log_EndMethod, "getIndexByValue", "println", "");
					return 1;
				}
				
				virtual bool removeByValue(const Member<H,M>& a_value){
					ValueArrayMapCollectionLog(pankey_Log_StartMethod, "removeByValue", "println", "");
					ValueArrayMapCollectionLog(pankey_Log_EndMethod, "removeByValue", "println", "");
					return true;
				}
		};

	}

#endif