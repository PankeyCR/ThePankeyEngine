
#ifndef ObjectList_hpp
	#define ObjectList_hpp
	
	#include "MemberArrayCollection.hpp"
	#include "ClassCount.hpp"
	#include "Object.hpp"

	#ifdef ObjectList_LogApp
		#include "pankey_Logger.hpp"
		#define ObjectListLog(location,method,type,mns) pankey_Log((void*)this,location,"ObjectList",method,type,mns)
	#else
		#define ObjectListLog(location,method,type,mns) 
	#endif

	namespace pankey{

		template<class O, class H, class M>
		class ObjectList : public MemberArrayCollection<H,M>{
			public:
				ObjectList(){
					ObjectListLog(pankey_Log_StartMethod, "Constructor", "println", "");
					ObjectListLog(pankey_Log_EndMethod, "Constructor", "println", "");
				}
				virtual ~ObjectList(){
					ObjectListLog(pankey_Log_StartMethod, "Destructor", "println", "");
					ObjectListLog(pankey_Log_EndMethod, "Destructor", "println", "");
				}

				virtual long getBaseType()const{
                    ObjectListLog(pankey_Log_StartMethod, "getBaseType", "println","");
                    ObjectListLog(pankey_Log_Statement, "getBaseType", "println", ClassCount<O>::get());
                    ObjectListLog(pankey_Log_EndMethod, "getBaseType", "println","");
					return ClassCount<O>::get();
				}

				virtual bool sameBaseType(long a_type)const{
                    ObjectListLog(pankey_Log_StartMethod, "sameBaseType", "println","");
                    if(a_type == -1){
                        ObjectListLog(pankey_Log_Error, "sameBaseType", "println","The variable cheching has no type");
                        ObjectListLog(pankey_Log_EndMethod, "sameBaseType", "println","");
                        return false;
                    }
                    long i_type = this->getBaseType();
                    if(i_type != a_type && i_type != -1){
                        ObjectListLog(pankey_Log_Error, "sameBaseType", "println","Not a memeber because it has diferent types");
                        ObjectListLog(pankey_Log_EndMethod, "sameBaseType", "println","");
                        return false;
                    }
                    ObjectListLog(pankey_Log_EndMethod, "sameBaseType", "println","");
                    return true;
				}

				virtual Member<H,M> add(Member<H,M>& a_pointer){
					ObjectListLog(pankey_Log_StartMethod, "add", "println", "Member<H,M>");
                    if(!this->sameBaseType(a_pointer.getBaseType())){
                        ObjectListLog(pankey_Log_Error, "add", "println", "Variable is not Member of Variable");
                        ObjectListLog(pankey_Log_EndMethod, "add", "println","");
                        return a_pointer;
                    }
					if(this->m_storage.add(this->m_length, a_pointer)){
						ObjectListLog(pankey_Log_Statement, "add", "println", "element added and know incrementing position");
						this->incrementPosition();
					}
					ObjectListLog(pankey_Log_EndMethod, "add", "println", "");
					return a_pointer;
				}

				virtual Object<O,H,M> add(Object<O,H,M>& a_pointer){
					ObjectListLog(pankey_Log_StartMethod, "add", "println", "Object<O,H,M>");
					ObjectListLog(pankey_Log_Statement, "add", "println", "is the pointer null:");
					ObjectListLog(pankey_Log_Statement, "add", "println", a_pointer.isNull());
					if(this->m_storage.add(this->m_length, a_pointer)){
						ObjectListLog(pankey_Log_Statement, "add", "println", "element added and know incrementing position");
						this->incrementPosition();
					}
					ObjectListLog(pankey_Log_EndMethod, "add", "println", "");
					return a_pointer;
				}
				
				virtual Member<H,M> put(Member<H,M>& a_pointer){
					ObjectListLog(pankey_Log_StartMethod, "put", "println", "Member<H,M>");
                    if(!this->sameBaseType(a_pointer.getBaseType())){
                        ObjectListLog(pankey_Log_Error, "put", "println", "Variable is not Member of Variable");
                        ObjectListLog(pankey_Log_EndMethod, "put", "println","");
                        return a_pointer;
                    }
					if(this->m_storage.containByPointer(a_pointer)){
						return a_pointer;
					}
					ObjectListLog(pankey_Log_EndMethod, "put", "println", "");
					return this->add(a_pointer);
				}
				
				virtual Object<O,H,M> put(Object<O,H,M>& a_pointer){
					ObjectListLog(pankey_Log_StartMethod, "put", "println", "Object<O,H,M>");
					if(this->m_storage.containByPointer(a_pointer)){
						return a_pointer;
					}
					ObjectListLog(pankey_Log_EndMethod, "put", "println", "");
					return this->add(a_pointer);
				}

				virtual Member<H,M> set(int a_position, Member<H,M>& a_pointer){
					ObjectListLog(pankey_Log_StartMethod, "set", "println", "Member<H,M>");
                    if(!this->sameBaseType(a_pointer.getBaseType())){
                        ObjectListLog(pankey_Log_Error, "set", "println", "Variable is not Member of Variable");
                        ObjectListLog(pankey_Log_EndMethod, "set", "println","");
                        return a_pointer;
                    }
					if(a_position >= this->getSize()){
						return a_pointer;
					}
					ObjectListLog(pankey_Log_EndMethod, "set", "println", "");
					this->m_storage.set(a_position, a_pointer);
					return a_pointer;
				}

				virtual Object<O,H,M> set(int a_position, Object<O,H,M>& a_pointer){
					ObjectListLog(pankey_Log_StartMethod, "set", "println", "Object<O,H,M>");
					if(a_position >= this->getSize()){
						return a_pointer;
					}
					this->m_storage.set(a_position, a_pointer);
					ObjectListLog(pankey_Log_EndMethod, "set", "println", "");
					return a_pointer;
				}

				virtual Member<H,M> insert(int a_position, Member<H,M>& a_pointer){
					ObjectListLog(pankey_Log_StartMethod, "insert", "println", "Member<H,M>");
                    if(!this->sameBaseType(a_pointer.getBaseType())){
                        ObjectListLog(pankey_Log_Error, "insert", "println", "Variable is not Member of Variable");
                        ObjectListLog(pankey_Log_EndMethod, "insert", "println","");
                        return a_pointer;
                    }
					this->m_storage.insert(a_position, this->length(), 1);
					this->m_storage.set(a_position, a_pointer);
					this->incrementPosition();
					ObjectListLog(pankey_Log_EndMethod, "insert", "println", "");
					return a_pointer;
				}

				virtual Object<O,H,M> insert(int a_position, Object<O,H,M>& a_pointer){
					ObjectListLog(pankey_Log_StartMethod, "insert", "println", "Object<O,H,M>");
					this->m_storage.insert(a_position, this->length(), 1);
					this->m_storage.set(a_position, a_pointer);
					this->incrementPosition();
					ObjectListLog(pankey_Log_EndMethod, "insert", "println", "");
					return a_pointer;
				}
		
				virtual ObjectList<O,H,M>& operator=(const ObjectList<O,H,M>& a_list){
					ObjectListLog(pankey_Log_StartMethod, "operator=", "println", "");
					for(int x = 0; x < a_list.length(); x++){
						auto f_value = a_list.get(x);
						this->add(f_value);
					}
					ObjectListLog(pankey_Log_EndMethod, "operator=", "println", "");
					return *this;
				}
		
				virtual bool operator==(const ObjectList<O,H,M>& a_list){
					ObjectListLog(pankey_Log_StartMethod, "operator=", "println", "");
					if(this->length() != a_list.length()){
						return false;
					}
					for(int x = 0; x < a_list.length(); x++){
						auto f_value_1 = a_list.get(x);
						auto f_value_2 = this->get(x);
						if(f_value_1 != f_value_2){
							return false;
						}
					}
					ObjectListLog(pankey_Log_EndMethod, "operator=", "println", "");
					return true;
				}
		
				virtual bool operator!=(const ObjectList<O,H,M>& a_list){
					ObjectListLog(pankey_Log_StartMethod, "operator=", "println", "");
					if(this->length() != a_list.length()){
						return true;
					}
					for(int x = 0; x < a_list.length(); x++){
						auto f_value_1 = a_list.get(x);
						auto f_value_2 = this->get(x);
						if(f_value_1 == f_value_2){
							return false;
						}
					}
					ObjectListLog(pankey_Log_EndMethod, "operator=", "println", "");
					return true;
				}
		};

	}

#endif