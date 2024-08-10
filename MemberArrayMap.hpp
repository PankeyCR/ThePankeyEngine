
#ifndef MemberArrayMap_hpp
	#define MemberArrayMap_hpp
	
	#include "MemberArrayMapCollection.hpp"
	#include "DuoMember.hpp"
	#include "ClassCount.hpp"

	#ifdef MemberArrayMap_LogApp
		#include "higgs_Logger.hpp"
		#define MemberArrayMapLog(location,method,type,mns) higgs_Log((void*)this,location,"MemberArrayMap",method,type,mns)
	#else
		#define MemberArrayMapLog(location,method,type,mns) 
	#endif

	namespace higgs{

		template<class H, class M>
		class MemberArrayMap : public MemberArrayMapCollection<H,M>{
			public:
				MemberArrayMap(){
					MemberArrayMapLog(higgs_Log_StartMethod, "Constructor", "println", "");
					MemberArrayMapLog(higgs_Log_EndMethod, "Constructor", "println", "");
				}
				virtual ~MemberArrayMap(){
					MemberArrayMapLog(higgs_Log_StartMethod, "Destructor", "println", "");
					MemberArrayMapLog(higgs_Log_EndMethod, "Destructor", "println", "");
				}

				virtual DuoMember<H,M> add(Member<H,M>& a_key, Member<H,M>& a_value){
					MemberArrayListLog(higgs_Log_StartMethod, "add", "println", "");
					if(this->m_keys.add(this->m_length, a_key) && this->m_values.add(this->m_length, a_value)){
						this->incrementPosition();
					}
					MemberArrayListLog(higgs_Log_EndMethod, "add", "println", "");
					return DuoMember<H,M>(a_key, a_value);
				}

				virtual DuoMember<H,M> add(DuoMember<H,M>& a_duo){
					MemberArrayListLog(higgs_Log_StartMethod, "add", "println", "");
					Member<H,M> i_member = a_duo.getMember();
					Member<H,M> i_duo_member = a_duo.getDuoMember();
					if(this->m_keys.add(this->m_length, i_member) && this->m_values.add(this->m_length, i_duo_member)){
						this->incrementPosition();
					}
					MemberArrayListLog(higgs_Log_EndMethod, "add", "println", "");
					return a_duo;
				}
				
				virtual DuoMember<H,M> put(DuoMember<H,M>& a_duo){
					MemberArrayMapLog(higgs_Log_StartMethod, "put", "println", "");
					if(this->m_keys.contain(a_duo.getMember())){
						return a_duo.getDuoMember();
					}
					MemberArrayMapLog(higgs_Log_EndMethod, "put", "println", "");
					return this->add(a_duo);
				}
				
				virtual DuoMember<H,M> put(Member<H,M>& a_key, Member<H,M>& a_value){
					MemberArrayMapLog(higgs_Log_StartMethod, "put", "println", "");
					if(this->m_keys.contain(a_key)){
						return DuoMember<H,M>(a_key, a_value);
					}
					MemberArrayMapLog(higgs_Log_EndMethod, "put", "println", "");
					return this->add(a_key, a_value);
				}

				virtual DuoMember<H,M> getDuoMember(const Member<H,M>& a_value)const{
					MemberArrayMapLog(higgs_Log_StartMethod, "getDuoMember", "println", "");
					int i_index = this->m_keys.getIndex(a_value);
					if(i_index == -1){
						MemberArrayMapLog(higgs_Log_EndMethod, "getDuoMember", "println", "i_index == -1");
						return DuoMember<H,M>();
					}
					MemberArrayMapLog(higgs_Log_EndMethod, "getDuoMember", "println", "");
					return DuoMember<H,M>(this->m_keys.get(i_index), this->m_values.get(i_index));
				}

				virtual bool contain(const Member<H,M>& a_value)const{
					MemberArrayMapLog(higgs_Log_StartMethod, "contain", "println", "");
					MemberArrayMapLog(higgs_Log_EndMethod, "contain", "println", "");
					return this->m_keys.contain(a_value) || this->m_values.contain(a_value);
				}

				virtual bool contain(DuoMember<H,M>& a_duo)const{
					MemberArrayMapLog(higgs_Log_StartMethod, "contain", "println", "");
					Member<H,M> i_member = a_duo.getMember();
					Member<H,M> i_duo_member = a_duo.getDuoMember();
					MemberArrayMapLog(higgs_Log_EndMethod, "contain", "println", "");
					return this->m_keys.contain(i_member) || this->m_values.contain(i_duo_member);
				}
				
				virtual void move(Collection<H,M>& a_collection){
					MemberArrayMapLog(higgs_Log_StartMethod, "move", "println", "");
					// for(int x = 0; x < a_collection.length(); x++){
					// 	Member<H,M> f_value = a_collection.get(x);
					// 	this->add(f_value);
					// }
					// a_collection.clear();
					MemberArrayMapLog(higgs_Log_EndMethod, "move", "println", "");
				}
				
				virtual void duplicate(const Collection<H,M>& a_collection){
					MemberArrayMapLog(higgs_Log_StartMethod, "duplicate", "println", "");
					// for(int x = 0; x < a_collection.length(); x++){
					// 	Member<H,M> f_value = a_collection.get(x);
					// 	this->add(f_value);
					// }
					MemberArrayMapLog(higgs_Log_EndMethod, "duplicate", "println", "");
				}
		};

	}

#endif