
#ifndef HashMap_hpp
	#define HashMap_hpp
	
	#include "Collection.hpp"
	#include "MapEntry.hpp"
	#include "ClassCount.hpp"

	#ifdef HashMap_LogApp
		#include "pankey_Logger.hpp"
		#define HashMapLog(location,method,type,mns) pankey_Log((void*)this,location,"HashMap",method,type,mns)
	#else
		#define HashMapLog(location,method,type,mns) 
	#endif

	namespace pankey{

		template<class K, class V, class H, class M>
		class HashMap : public MemberArrayCollection<H,M>{
			public:
				HashMap(){
					HashMapLog(pankey_Log_StartMethod, "Constructor", "println", "");
					HashMapLog(pankey_Log_EndMethod, "Constructor", "println", "");
				}
				virtual ~HashMap(){
					HashMapLog(pankey_Log_StartMethod, "Destructor", "println", "");
					HashMapLog(pankey_Log_EndMethod, "Destructor", "println", "");
				}

				virtual long getKeyType()const{
                    HashMapLog(pankey_Log_StartMethod, "getKeyType", "println","");
                    HashMapLog(pankey_Log_Statement, "getKeyType", "println", ClassCount<K>::get());
                    HashMapLog(pankey_Log_EndMethod, "getKeyType", "println","");
					return ClassCount<K>::get();
				}

				virtual long getValueType()const{
                    HashMapLog(pankey_Log_StartMethod, "getValueType", "println","");
                    HashMapLog(pankey_Log_Statement, "getValueType", "println", ClassCount<V>::get());
                    HashMapLog(pankey_Log_EndMethod, "getValueType", "println","");
					return ClassCount<V>::get();
				}

				virtual bool sameType(long a_key_type, long a_value_type)const{
                    HashMapLog(pankey_Log_StartMethod, "sameType", "println","");
                    if(a_key_type == -1 || a_value_type != -1){
                        HashMapLog(pankey_Log_Error, "sameType", "println","The variable cheching has no type");
                        HashMapLog(pankey_Log_EndMethod, "sameType", "println","");
                        return false;
                    }
                    long i_key_type = this->getKeyType();
                    long i_value_type = this->getValueType();
                    if(i_key_type != a_key_type && i_value_type != a_value_type){
                        HashMapLog(pankey_Log_Error, "sameType", "println","Not a memeber because it has diferent types");
                        HashMapLog(pankey_Log_EndMethod, "sameType", "println","");
                        return false;
                    }
                    HashMapLog(pankey_Log_EndMethod, "sameType", "println","");
                    return true;
				}
				
				virtual Member<H,A> put(const MapEntry<K,V,H,A>& a_pointer){
					HashMapLog(pankey_Log_StartMethod, "put", "println", "");
                    if(!this->sameType(a_pointer.getType())){
                        HashMapLog(pankey_Log_Error, "put", "println", "Variable is not Member of Variable");
                        HashMapLog(pankey_Log_EndMethod, "put", "println","");
                        return a_pointer;
                    }
					if(this->m_storage.contain(a_pointer)){
						return a_pointer;
					}
					HashMapLog(pankey_Log_EndMethod, "put", "println", "");
					return this->add(a_pointer);
				}
				
				virtual Pointer<P,H,A> put(const Pointer<K,H,A>& a_key, const Pointer<K,H,A>& a_value){
					HashMapLog(pankey_Log_StartMethod, "put", "println", "");
					if(this->m_storage.contain(a_pointer)){
						return a_pointer;
					}
					MapEntry
					HashMapLog(pankey_Log_EndMethod, "put", "println", "");
					return this->m_storage.add(a_pointer);
				}

				virtual Member<H,A> get(const Member<H,A>& a_value)const{
					HashMapLog(pankey_Log_StartMethod, "get", "println", "");
					if(!this->m_storage.contain(a_value)){
						HashMapLog(pankey_Log_Statement, "get", "println", "!this->m_storage.contain(a_value)");
						return Member<H,A>();
					}
					HashMapLog(pankey_Log_EndMethod, "get", "println", "");
					return a_value;
				}

				virtual Member<H,A> getHashSet(const Member<H,A>& a_value)const{
					HashMapLog(pankey_Log_StartMethod, "get", "println", "");
					if(!this->m_storage.contain(a_value)){
						HashMapLog(pankey_Log_Statement, "get", "println", "!this->m_storage.contain(a_value)");
						return Member<H,A>();
					}
					HashMapLog(pankey_Log_EndMethod, "get", "println", "");
					return a_value;
				}

				virtual bool contain(const Member<H,A>& a_value)const{
					HashMapLog(pankey_Log_StartMethod, "contain", "println", "");
					HashMapLog(pankey_Log_EndMethod, "contain", "println", "");
					return this->m_storage.contain(a_value);
				}

				virtual bool containHashSet(const Member<H,A>& a_value)const{
					HashMapLog(pankey_Log_StartMethod, "contain", "println", "");
					HashMapLog(pankey_Log_EndMethod, "contain", "println", "");
					return this->m_storage.contain(a_value);
				}
				
				virtual bool remove(const Member<H,A>& a_value){
					HashMapLog(pankey_Log_StartMethod, "remove", "println", "");
					int i_index = this->m_storage.getIndex(a_value);
					if(i_index == -1){
						HashMapLog(pankey_Log_EndMethod, "remove", "println", "");
						return false;
					}
					HashMapLog(pankey_Log_Statement, "remove", "println", "index that is been removed:");
					HashMapLog(pankey_Log_Statement, "remove", "println", i_index);
					this->m_storage.removeByPosition(i_index);
					this->m_storage.reorder(i_index, this->length());
					HashMapLog(pankey_Log_EndMethod, "remove", "println", "");
					return true;
				}
				
				virtual void move(Collection<H,A>& a_collection){
					HashMapLog(pankey_Log_StartMethod, "move", "println", "");
					for(int x = 0; x < a_collection.length(); x++){
						Member<H,A> f_value = a_collection.get(x);
						this->add(f_value);
					}
					a_collection.clear();
					HashMapLog(pankey_Log_EndMethod, "move", "println", "");
				}
				
				virtual void duplicate(const Collection<H,A>& a_collection){
					HashMapLog(pankey_Log_StartMethod, "duplicate", "println", "");
					for(int x = 0; x < a_collection.length(); x++){
						Member<H,A> f_value = a_collection.get(x);
						this->add(f_value);
					}
					HashMapLog(pankey_Log_EndMethod, "duplicate", "println", "");
				}
		};

	}

#endif