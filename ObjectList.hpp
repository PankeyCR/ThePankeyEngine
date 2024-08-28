
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

		template<class O, class H, class A>
		class ObjectList : public MemberArrayCollection<H,A>{
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

				virtual Member<H,A> add(Member<H,A>& a_pointer){
					ObjectListLog(pankey_Log_StartMethod, "add", "println", "Member<H,A>");
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

				virtual Object<O,H,A> add(Object<O,H,A>& a_pointer){
					ObjectListLog(pankey_Log_StartMethod, "add", "println", "Object<O,H,A>");
					if(this->m_storage.add(this->m_length, a_pointer)){
						ObjectListLog(pankey_Log_Statement, "add", "println", "element added and know incrementing position");
						this->incrementPosition();
					}
					ObjectListLog(pankey_Log_EndMethod, "add", "println", "");
					return a_pointer;
				}
				
				virtual Member<H,A> put(Member<H,A>& a_pointer){
					ObjectListLog(pankey_Log_StartMethod, "put", "println", "Member<H,A>");
                    if(!this->sameBaseType(a_pointer.getBaseType())){
                        ObjectListLog(pankey_Log_Error, "put", "println", "Variable is not Member of Variable");
                        ObjectListLog(pankey_Log_EndMethod, "put", "println","");
                        return a_pointer;
                    }
					if(this->m_storage.contain(a_pointer)){
						return a_pointer;
					}
					ObjectListLog(pankey_Log_EndMethod, "put", "println", "");
					return this->add(a_pointer);
				}
				
				virtual Object<O,H,A> put(Object<O,H,A>& a_pointer){
					ObjectListLog(pankey_Log_StartMethod, "put", "println", "Object<O,H,A>");
					if(this->m_storage.contain(a_pointer)){
						return a_pointer;
					}
					ObjectListLog(pankey_Log_EndMethod, "put", "println", "");
					return this->add(a_pointer);
				}

				virtual Member<H,A> set(int a_position, Member<H,A>& a_pointer){
					ObjectListLog(pankey_Log_StartMethod, "set", "println", "Member<H,A>");
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

				virtual Object<O,H,A> set(int a_position, Object<O,H,A>& a_pointer){
					ObjectListLog(pankey_Log_StartMethod, "set", "println", "Object<O,H,A>");
					if(a_position >= this->getSize()){
						return a_pointer;
					}
					this->m_storage.set(a_position, a_pointer);
					ObjectListLog(pankey_Log_EndMethod, "set", "println", "");
					return a_pointer;
				}

				virtual Member<H,A> insert(int a_position, Member<H,A>& a_pointer){
					ObjectListLog(pankey_Log_StartMethod, "insert", "println", "Member<H,A>");
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

				virtual Object<O,H,A> insert(int a_position, Object<O,H,A>& a_pointer){
					ObjectListLog(pankey_Log_StartMethod, "insert", "println", "Object<O,H,A>");
					this->m_storage.insert(a_position, this->length(), 1);
					this->m_storage.set(a_position, a_pointer);
					this->incrementPosition();
					ObjectListLog(pankey_Log_EndMethod, "insert", "println", "");
					return a_pointer;
				}
				
				virtual void move(Collection<H,A>& a_collection){
					ObjectListLog(pankey_Log_StartMethod, "move", "println", "");
					for(int x = 0; x < a_collection.length(); x++){
						Member<H,A> f_value = a_collection.get(x);
						this->add(f_value);
					}
					a_collection.clear();
					ObjectListLog(pankey_Log_EndMethod, "move", "println", "");
				}
				
				virtual void duplicate(const Collection<H,A>& a_collection){
					ObjectListLog(pankey_Log_StartMethod, "duplicate", "println", "");
					for(int x = 0; x < a_collection.length(); x++){
						Member<H,A> f_value = a_collection.get(x);
						this->add(f_value);
					}
					ObjectListLog(pankey_Log_EndMethod, "duplicate", "println", "");
				}
		};

	}

#endif