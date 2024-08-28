
#ifndef TypeList_hpp
	#define TypeList_hpp
	
	#include "MemberArrayCollection.hpp"
	#include "ClassCount.hpp"

	#ifdef TypeList_LogApp
		#include "pankey_Logger.hpp"
		#define TypeListLog(location,method,type,mns) pankey_Log((void*)this,location,"TypeList",method,type,mns)
	#else
		#define TypeListLog(location,method,type,mns) 
	#endif

	namespace pankey{

		template<class P, class H, class A>
		class TypeList : public MemberArrayCollection<H,A>{
			public:
				TypeList(){
					TypeListLog(pankey_Log_StartMethod, "Constructor", "println", "");
					TypeListLog(pankey_Log_EndMethod, "Constructor", "println", "");
				}
				virtual ~TypeList(){
					TypeListLog(pankey_Log_StartMethod, "Destructor", "println", "");
					TypeListLog(pankey_Log_EndMethod, "Destructor", "println", "");
				}

				virtual long getType()const{
                    TypeListLog(pankey_Log_StartMethod, "getType", "println","");
                    TypeListLog(pankey_Log_Statement, "getType", "println", ClassCount<P>::get());
                    TypeListLog(pankey_Log_EndMethod, "getType", "println","");
					return ClassCount<P>::get();
				}

				virtual bool sameType(long a_type)const{
                    TypeListLog(pankey_Log_StartMethod, "sameType", "println","");
                    if(a_type == -1){
                        TypeListLog(pankey_Log_Error, "sameType", "println","The variable cheching has no type");
                        TypeListLog(pankey_Log_EndMethod, "sameType", "println","");
                        return false;
                    }
                    long i_type = this->getType();
                    if(i_type != a_type){
                        TypeListLog(pankey_Log_Error, "sameType", "println","Not a memeber because it has diferent types");
                        TypeListLog(pankey_Log_EndMethod, "sameType", "println","");
                        return false;
                    }
                    TypeListLog(pankey_Log_EndMethod, "sameType", "println","");
                    return true;
				}

				virtual Member<H,A> add(Member<H,A>& a_pointer){
					TypeListLog(pankey_Log_StartMethod, "add", "println", "");
                    if(!this->sameType(a_pointer.getType())){
                        TypeListLog(pankey_Log_Error, "add", "println", "Variable is not Member of Variable");
                        TypeListLog(pankey_Log_EndMethod, "add", "println","");
                        return a_pointer;
                    }
					if(this->m_storage.add(this->m_length, a_pointer)){
						this->incrementPosition();
					}
					TypeListLog(pankey_Log_EndMethod, "add", "println", "");
					return a_pointer;
				}

				virtual Pointer<P,H,A> add(Pointer<P,H,A>& a_pointer){
					TypeListLog(pankey_Log_StartMethod, "add", "println", "");
					if(this->m_storage.add(this->m_length, a_pointer)){
						this->incrementPosition();
					}
					TypeListLog(pankey_Log_EndMethod, "add", "println", "");
					return a_pointer;
				}
				
				virtual Member<H,A> put(Member<H,A>& a_pointer){
					TypeListLog(pankey_Log_StartMethod, "put", "println", "");
                    if(!this->sameType(a_pointer.getType())){
                        TypeListLog(pankey_Log_Error, "put", "println", "Variable is not Member of Variable");
                        TypeListLog(pankey_Log_EndMethod, "put", "println","");
                        return a_pointer;
                    }
					if(this->m_storage.contain(a_pointer)){
						return a_pointer;
					}
					TypeListLog(pankey_Log_EndMethod, "put", "println", "");
					return this->add(a_pointer);
				}
				
				virtual Pointer<P,H,A> put(Pointer<P,H,A>& a_pointer){
					TypeListLog(pankey_Log_StartMethod, "put", "println", "");
					if(this->m_storage.contain(a_pointer)){
						return a_pointer;
					}
					TypeListLog(pankey_Log_EndMethod, "put", "println", "");
					return this->add(a_pointer);
				}

				virtual Member<H,A> set(int a_position, Member<H,A>& a_pointer){
					TypeListLog(pankey_Log_StartMethod, "set", "println", "");
                    if(!this->sameType(a_pointer.getType())){
                        TypeListLog(pankey_Log_Error, "set", "println", "Variable is not Member of Variable");
                        TypeListLog(pankey_Log_EndMethod, "set", "println","");
                        return a_pointer;
                    }
					if(a_position >= this->getSize()){
						return a_pointer;
					}
					TypeListLog(pankey_Log_EndMethod, "set", "println", "");
					this->m_storage.set(a_position, a_pointer);
					return a_pointer;
				}

				virtual Pointer<P,H,A> set(int a_position, Pointer<P,H,A>& a_pointer){
					TypeListLog(pankey_Log_StartMethod, "set", "println", "");
					if(a_position >= this->getSize()){
						return a_pointer;
					}
					this->m_storage.set(a_position, a_pointer);
					TypeListLog(pankey_Log_EndMethod, "set", "println", "");
					return a_pointer;
				}

				virtual Member<H,A> insert(int a_position, Member<H,A>& a_pointer){
					TypeListLog(pankey_Log_StartMethod, "insert", "println", "");
                    if(!this->sameType(a_pointer.getType())){
                        TypeListLog(pankey_Log_Error, "insert", "println", "Variable is not Member of Variable");
                        TypeListLog(pankey_Log_EndMethod, "insert", "println","");
                        return a_pointer;
                    }
					this->m_storage.insert(a_position, this->length(), 1);
					this->m_storage.set(a_position, a_pointer);
					this->incrementPosition();
					TypeListLog(pankey_Log_EndMethod, "insert", "println", "");
					return a_pointer;
				}

				virtual Pointer<P,H,A> insert(int a_position, Pointer<P,H,A>& a_pointer){
					TypeListLog(pankey_Log_StartMethod, "insert", "println", "");
					this->m_storage.insert(a_position, this->length(), 1);
					this->m_storage.set(a_position, a_pointer);
					this->incrementPosition();
					TypeListLog(pankey_Log_EndMethod, "insert", "println", "");
					return a_pointer;
				}
				
				virtual void move(Collection<H,A>& a_collection){
					TypeListLog(pankey_Log_StartMethod, "move", "println", "");
					for(int x = 0; x < a_collection.length(); x++){
						Member<H,A> f_value = a_collection.get(x);
						this->add(f_value);
					}
					a_collection.clear();
					TypeListLog(pankey_Log_EndMethod, "move", "println", "");
				}
				
				virtual void duplicate(const Collection<H,A>& a_collection){
					TypeListLog(pankey_Log_StartMethod, "duplicate", "println", "");
					for(int x = 0; x < a_collection.length(); x++){
						Member<H,A> f_value = a_collection.get(x);
						this->add(f_value);
					}
					TypeListLog(pankey_Log_EndMethod, "duplicate", "println", "");
				}
		};

	}

#endif