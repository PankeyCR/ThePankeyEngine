
#ifndef TypeArrayMap_hpp
	#define TypeArrayMap_hpp
	
	#include "ValueArrayMapCollection.hpp"
	#include "DuoTypeMember.hpp"
	#include "Pointer.hpp"
	#include "ClassCount.hpp"

	#ifdef TypeArrayMap_LogApp
		#include "pankey_Logger.hpp"
		#define TypeArrayMapLog(location,method,type,mns) pankey_Log((void*)this,location,"TypeArrayMap",method,type,mns)
	#else
		#define TypeArrayMapLog(location,method,type,mns) 
	#endif

	namespace pankey{

		template<class K, class V, class H, class M>
		class TypeArrayMap : public ValueArrayMapCollection<K,V,H,M>{
			public:
				TypeArrayMap(){
					TypeArrayMapLog(pankey_Log_StartMethod, "Constructor", "println", "");
					TypeArrayMapLog(pankey_Log_EndMethod, "Constructor", "println", "");
				}
		
				TypeArrayMap(const TypeArrayMap<K,V,H,M>& a_map){
					TypeArrayMapLog(pankey_Log_StartMethod, "operator=", "println", "const TypeArrayMap<K,V,H,M>&");
					for(int x = 0; x < a_map.length(); x++){
						auto f_key = a_map.getKey(x);
						auto f_value = a_map.getValue(x);
						this->add(f_key, f_value);
					}
					TypeArrayMapLog(pankey_Log_EndMethod, "operator=", "println", "");
				}

				virtual ~TypeArrayMap(){
					TypeArrayMapLog(pankey_Log_StartMethod, "Destructor", "println", "");
					TypeArrayMapLog(pankey_Log_EndMethod, "Destructor", "println", "");
				}

				virtual long getKeyType()const{
                    TypeArrayMapLog(pankey_Log_StartMethod, "getKeyType", "println","");
                    TypeArrayMapLog(pankey_Log_Statement, "getKeyType", "println", ClassCount<K>::get());
                    TypeArrayMapLog(pankey_Log_EndMethod, "getKeyType", "println","");
					return ClassCount<K>::get();
				}

				virtual long getValueType()const{
                    TypeArrayMapLog(pankey_Log_StartMethod, "getValueType", "println","");
                    TypeArrayMapLog(pankey_Log_Statement, "getValueType", "println", ClassCount<V>::get());
                    TypeArrayMapLog(pankey_Log_EndMethod, "getValueType", "println","");
					return ClassCount<V>::get();
				}

				virtual DuoTypeMember<K,V,H,M> add(Member<H,M>& a_key, Member<H,M>& a_value){
					TypeArrayMapLog(pankey_Log_StartMethod, "add", "println", "");
					if(a_key.getType() != this->getKeyType() || a_value.getType() != this->getValueType()){
						TypeArrayMapLog(pankey_Log_EndMethod, "add", "println", "Not a type");
						return DuoTypeMember<K,V,H,M>();
					}
					if(this->m_keys.add(this->m_length, a_key) && this->m_values.add(this->m_length, a_value)){
						TypeArrayMapLog(pankey_Log_Statement, "add", "println", "adding type members");
						this->incrementPosition();
					}
					TypeArrayMapLog(pankey_Log_EndMethod, "add", "println", "");
					return DuoTypeMember<K,V,H,M>(a_key, a_value);
				}

				virtual DuoTypeMember<K,V,H,M> add(DuoTypeMember<K,V,H,M>& a_duo){
					TypeArrayMapLog(pankey_Log_StartMethod, "add", "println", "");
					Member<H,M> i_member = a_duo.getMember();
					Member<H,M> i_duo_member = a_duo.getDuoTypeMember();
					TypeArrayMapLog(pankey_Log_EndMethod, "add", "println", "");
					return this->add(i_member, i_duo_member);
				}
				
				virtual DuoTypeMember<K,V,H,M> put(DuoTypeMember<K,V,H,M>& a_duo){
					TypeArrayMapLog(pankey_Log_StartMethod, "put", "println", "");
					if(this->m_keys.containByPointer(a_duo.getMember())){
						return a_duo;
					}
					TypeArrayMapLog(pankey_Log_EndMethod, "put", "println", "");
					return this->add(a_duo);
				}
				
				virtual DuoTypeMember<K,V,H,M> put(Member<H,M>& a_key, Member<H,M>& a_value){
					TypeArrayMapLog(pankey_Log_StartMethod, "put", "println", "");
					if(this->m_keys.containByPointer(a_key)){
						return DuoTypeMember<K,V,H,M>(a_key, a_value);
					}
					TypeArrayMapLog(pankey_Log_EndMethod, "put", "println", "");
					return this->add(a_key, a_value);
				}
		
				virtual TypeArrayMap<K,V,H,M>& operator=(const TypeArrayMap<K,V,H,M>& a_map){
					TypeArrayMapLog(pankey_Log_StartMethod, "operator=", "println", "const TypeArrayMap<K,V,H,M>&");
					for(int x = 0; x < a_map.length(); x++){
						auto f_key = a_map.getKey(x);
						auto f_value = a_map.getValue(x);
						this->add(f_key, f_value);
					}
					TypeArrayMapLog(pankey_Log_EndMethod, "operator=", "println", "");
					return *this;
				}
		
				virtual bool operator==(const TypeArrayMap<K,V,H,M>& a_map){
					TypeArrayMapLog(pankey_Log_StartMethod, "operator=", "println", "const TypeArrayMap<K,V,H,M>&");
					if(this->length() != a_map.length()){
						return false;
					}
					for(int x = 0; x < a_map.length(); x++){
						auto f_key_1 = this->getKey(x);
						auto f_value_1 = this->getValue(x);
						auto f_key_2 = a_map.getKey(x);
						auto f_value_2 = a_map.getValue(x);
						if(f_key_1 != f_key_2 || f_value_1 != f_value_2){
							return false;
						}
					}
					TypeArrayMapLog(pankey_Log_EndMethod, "operator=", "println", "");
					return true;
				}
		
				virtual bool operator!=(const TypeArrayMap<K,V,H,M>& a_map){
					TypeArrayMapLog(pankey_Log_StartMethod, "operator=", "println", "const TypeArrayMap<K,V,H,M>&");
					if(this->length() != a_map.length()){
						return true;
					}
					for(int x = 0; x < a_map.length(); x++){
						auto f_key_1 = this->getKey(x);
						auto f_value_1 = this->getValue(x);
						auto f_key_2 = a_map.getKey(x);
						auto f_value_2 = a_map.getValue(x);
						if(f_key_1 != f_key_2 || f_value_1 != f_value_2){
							return true;
						}
					}
					TypeArrayMapLog(pankey_Log_EndMethod, "operator=", "println", "");
					return false;
				}
		};

	}

#endif