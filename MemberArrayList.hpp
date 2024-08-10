
#ifndef MemberArrayList_hpp
	#define MemberArrayList_hpp
	
	#include "MemberArrayCollection.hpp"

	#ifdef MemberArrayList_LogApp
		#include "higgs_Logger.hpp"
		#define MemberArrayListLog(location,method,type,mns) higgs_Log((void*)this,location,"MemberArrayList",method,type,mns)
	#else
		#define MemberArrayListLog(location,method,type,mns) 
	#endif

	namespace higgs{

		template<class H, class A>
		class MemberArrayList : public MemberArrayCollection<H,A>{
			public:
				MemberArrayList(){
					MemberArrayListLog(higgs_Log_StartMethod, "Constructor", "println", "");
					MemberArrayListLog(higgs_Log_EndMethod, "Constructor", "println", "");
				}
				virtual ~MemberArrayList(){
					MemberArrayListLog(higgs_Log_StartMethod, "Destructor", "println", "");
					MemberArrayListLog(higgs_Log_EndMethod, "Destructor", "println", "");
				}

				virtual Member<H,A> add(Member<H,A>& a_pointer){
					MemberArrayListLog(higgs_Log_StartMethod, "add", "println", "");
					if(this->m_storage.add(this->m_length, a_pointer)){
						this->incrementPosition();
					}
					MemberArrayListLog(higgs_Log_EndMethod, "add", "println", "");
					return a_pointer;
				}
				
				virtual Member<H,A> put(Member<H,A>& a_pointer){
					MemberArrayListLog(higgs_Log_StartMethod, "put", "println", "");
					if(this->m_storage.contain(a_pointer)){
						return Member<H,A>();
					}
					MemberArrayListLog(higgs_Log_EndMethod, "put", "println", "");
					return this->add(a_pointer);
				}

				virtual Member<H,A> set(int a_position, Member<H,A>& a_value){
					MemberArrayListLog(higgs_Log_StartMethod, "set", "println", "");
					MemberArrayListLog(higgs_Log_EndMethod, "set", "println", "");
					return this->set(a_position, a_value);
				}

				virtual Member<H,A> insert(int a_position, Member<H,A>& a_value){
					MemberArrayListLog(higgs_Log_StartMethod, "insert", "println", "");
					MemberArrayListLog(higgs_Log_EndMethod, "insert", "println", "");
					return this->insert(a_position, a_value);
				}
				
				virtual void move(Collection<H,A>& a_collection){
					CollectionLog(higgs_Log_StartMethod, "move", "println", "");
					for(int x = 0; x < a_collection.length(); x++){
						Member<H,A> f_value = a_collection.get(x);
						this->add(f_value);
					}
					a_collection.clear();
					CollectionLog(higgs_Log_EndMethod, "move", "println", "");
				}
				
				virtual void duplicate(const Collection<H,A>& a_collection){
					CollectionLog(higgs_Log_StartMethod, "duplicate", "println", "");
					for(int x = 0; x < a_collection.length(); x++){
						Member<H,A> f_value = a_collection.get(x);
						this->add(f_value);
					}
					CollectionLog(higgs_Log_EndMethod, "duplicate", "println", "");
				}
		};

	}

#endif