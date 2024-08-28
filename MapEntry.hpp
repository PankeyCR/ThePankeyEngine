
#ifndef MapEntry_hpp
	#define MapEntry_hpp

	#include "MemberMapEntry.hpp"

	#ifdef MapEntry_LogApp
		#include "pankey_Logger.hpp"
		#define MapEntryLog(location,method,type,mns) pankey_Log((void*)this,location,"MapEntry",method,type,mns)
	#else
		#define MapEntryLog(location,method,type,mns)
	#endif

	namespace pankey{

		template <class K,class V, class H, class M>
		class MapEntry : public MemberMapEntry<H,M>{
			public:

                using MANAGER_TYPE = typename MemoryHolder<H>::MANAGER_TYPE;
                using POINTER_TYPE = typename MemoryHolder<H>::POINTER_TYPE;
                using HOLDER_TYPE = typename MemoryHolder<H>::HOLDER_TYPE;
                using HOLDER_ARRAY_TYPE = typename MemoryHolder<H>::HOLDER_ARRAY_TYPE;

				MapEntry(){
					MapEntryLog(pankey_Log_StartMethod, "Constructor", "println", "");
					MapEntryLog(pankey_Log_EndMethod, "Constructor", "println", "");
				}
				
				MapEntry(Pointer<K,H,M> c_key, Pointer<V,H,M> c_value){
					MapEntryLog(pankey_Log_StartMethod, "Constructor", "println", "");
					m_key = c_key;
					m_value = c_value;
					MapEntryLog(pankey_Log_EndMethod, "Constructor", "println", "");
				}
				
				MapEntry(const MapEntry<K,V,H,M>& c_map_entry){
					MapEntryLog(pankey_Log_StartMethod, "Constructor", "println", "");
					m_key = c_map_entry.m_key;
					m_value = c_map_entry.m_value;
					MapEntryLog(pankey_Log_EndMethod, "Constructor", "println", "");
				}
				
				virtual ~MapEntry(){
					MapEntryLog(pankey_Log_StartMethod, "Destructor", "println", "");
					MapEntryLog(pankey_Log_EndMethod, "Destructor", "println", "");
				}
				
				virtual Pointer<K,H,M> getKey()const{
					MapEntryLog(pankey_Log_StartMethod, "getKey", "println", "");
					MapEntryLog(pankey_Log_EndMethod, "getKey", "println", "");
					return this->m_key;
				}
				virtual Pointer<V,H,M> getValue()const{
					MapEntryLog(pankey_Log_StartMethod, "getValue", "println", "");
					MapEntryLog(pankey_Log_EndMethod, "getValue", "println", "");
					return this->m_value;
				}

                virtual void remove(){
                    MemoryHolderLog(pankey_Log_StartMethod, "remove", "println","");
                    MemoryHolderManager<H>::remove(this->getManager(), this->m_holder);
                    MemoryHolderManager<H>::remove(this->getManager(), this->m_key_holder);
                    MemoryHolderLog(pankey_Log_EndMethod, "remove", "println","");
                }

                virtual void destroy(){
                    MemoryHolderLog(pankey_Log_StartMethod, "destroy", "println","");
                    MemoryHolderManager<H>::destroy(this->getManager(), this->m_holder);
                    MemoryHolderManager<H>::destroy(this->getManager(), this->m_key_holder);
                    MemoryHolderLog(pankey_Log_EndMethod, "destroy", "println","");
                }
                    
                //unsafe method
                virtual void setHolder(HOLDER_TYPE a_holder){
                    MemoryHolderLog(pankey_Log_StartMethod, "setHolder", "println","Shouldnt be used");
                    MemoryHolderLog(pankey_Log_Error, "setHolder", "println","This method shouldnt be used");
                    MemoryHolderLog(pankey_Log_EndMethod, "setHolder", "println","");
                }
                    
                //unsafe method
                virtual void setKeyHolder(HOLDER_TYPE a_holder){
                    MemoryHolderLog(pankey_Log_StartMethod, "setHolder", "println","");
					MemoryHolderManager<H>::add(this->getManager(), a_holder);
					MemoryHolderManager<H>::remove(this->getManager(), this->m_key_holder);
					this->m_key_holder = a_holder;
                    MemoryHolderLog(pankey_Log_EndMethod, "setHolder", "println","");
                }
                    
                //unsafe method
                virtual void setValueHolder(HOLDER_TYPE a_holder){
                    MemoryHolderLog(pankey_Log_StartMethod, "setHolder", "println","");
					MemoryHolderManager<H>::add(this->getManager(), a_holder);
					MemoryHolderManager<H>::remove(this->getManager(), this->m_holder);
					this->m_holder = a_holder;
                    MemoryHolderLog(pankey_Log_EndMethod, "setHolder", "println","");
                }

                //unsafe method
                virtual HOLDER_TYPE getHolder()const{
                    MemoryHolderLog(pankey_Log_StartMethod, "getHolder", "println","");
                    MemoryHolderLog(pankey_Log_Error, "getHolder", "println","This method shouldnt be used");
                    MemoryHolderLog(pankey_Log_EndMethod, "getHolder", "println","");
                    return nullptr;
                }

                //unsafe method
                virtual HOLDER_TYPE getKeyHolder()const{
                    return this->m_key_holder;
                }

                //unsafe method
                virtual HOLDER_TYPE getValueHolder()const{
                    return this->m_holder;
                }

                virtual HOLDER_TYPE& getHolderReference(){
                    return m_holder;
                }

                virtual bool isHolderNull()const{
                    return m_holder == nullptr;
                }
                    
                virtual void setManager(MANAGER_TYPE a_llocator){
                    MemoryHolderLog(pankey_Log_StartMethod, "setManager", "println","");
                    MemoryHolderLog(pankey_Log_EndMethod, "setManager", "println","");
                }

                virtual MANAGER_TYPE getManager()const=0;

                virtual bool isManagerNull()const{
                    return this->getManager() == nullptr;
                }

                virtual void copyMemoryHolder(const MemoryHolder<H>& a_holder){
                    MemoryHolderLog(pankey_Log_StartMethod, "copyMemoryHolder", "println","");
                    if(!this->isMember(a_holder)){
                        MemoryHolderLog(pankey_Log_Error, "copyMemoryHolder", "println", "Variable is not Member of Variable");
                        MemoryHolderLog(pankey_Log_EndMethod, "copyMemoryHolder", "println","");
                        return;
                    }
                    this->setHolder(a_holder.getHolder());
                    MemoryHolderLog(pankey_Log_EndMethod, "copyMemoryHolder", "println","");
                }

				virtual bool shareManager(MANAGER_TYPE a_manager)const{
                    MemoryHolderLog(pankey_Log_StartMethod, "shareManager", "println","");
                    if(a_manager == nullptr){
                        MemoryHolderLog(pankey_Log_Error, "shareManager", "println","The variable cheching has no Manager");
                        MemoryHolderLog(pankey_Log_EndMethod, "shareManager", "println","");
                        return false;
                    }
                    auto i_manager = this->getManager();
                    if(i_manager != a_manager && i_manager != nullptr){
                        MemoryHolderLog(pankey_Log_Error, "shareManager", "println","Not a memeber because it has diferent Manager");
                        MemoryHolderLog(pankey_Log_EndMethod, "shareManager", "println","");
                        return false;
                    }
                    MemoryHolderLog(pankey_Log_EndMethod, "shareManager", "println","");
                    return true;
				}

				virtual bool sameType(long a_type)const{
                    MemoryHolderLog(pankey_Log_StartMethod, "sameType", "println","");
                    if(a_type == -1){
                        MemoryHolderLog(pankey_Log_Error, "sameType", "println","The variable cheching has no type");
                        MemoryHolderLog(pankey_Log_EndMethod, "sameType", "println","");
                        return false;
                    }
                    long i_type = this->getType();
                    if(i_type != a_type && i_type != -1){
                        MemoryHolderLog(pankey_Log_Error, "sameType", "println","Not a memeber because it has diferent types");
                        MemoryHolderLog(pankey_Log_EndMethod, "sameType", "println","");
                        return false;
                    }
                    MemoryHolderLog(pankey_Log_EndMethod, "sameType", "println","");
                    return true;
				}

				virtual bool sameBaseType(long a_type)const{
                    MemoryHolderLog(pankey_Log_StartMethod, "sameBaseType", "println","");
                    if(a_type == -1){
                        MemoryHolderLog(pankey_Log_Error, "sameBaseType", "println","The variable cheching has no type");
                        MemoryHolderLog(pankey_Log_EndMethod, "sameBaseType", "println","");
                        return false;
                    }
                    long i_type = this->getBaseType();
                    if(i_type != a_type && i_type != -1){
                        MemoryHolderLog(pankey_Log_Error, "sameBaseType", "println","Not a memeber because it has diferent types");
                        MemoryHolderLog(pankey_Log_EndMethod, "sameBaseType", "println","");
                        return false;
                    }
                    MemoryHolderLog(pankey_Log_EndMethod, "sameBaseType", "println","");
                    return true;
				}

				virtual bool isMember(MANAGER_TYPE a_manager, long a_type)const{
                    MemoryHolderLog(pankey_Log_StartMethod, "isMember", "println","");
                    MemoryHolderLog(pankey_Log_EndMethod, "isMember", "println","");
                    return this->shareManager(a_manager) && this->sameType(a_type);
				}

				virtual bool isMember(HOLDER_TYPE a_holder, MANAGER_TYPE a_manager)const{
                    MemoryHolderLog(pankey_Log_StartMethod, "isMember", "println","");
                    auto i_type = MemoryHolderManager<H>::getType(a_manager, a_holder);
                    MemoryHolderLog(pankey_Log_EndMethod, "isMember", "println","");
                    return this->isMember(a_manager, i_type);
                }

				virtual bool isMember(HOLDER_TYPE a_holder)const{
                    MemoryHolderLog(pankey_Log_StartMethod, "isMember", "println","");
                    auto i_manager = MemoryHolderManager<H>::getManager(this->getManager(), a_holder);
                    MemoryHolderLog(pankey_Log_EndMethod, "isMember", "println","");
                    return this->isMember(a_holder, i_manager);
                }

				virtual bool isMember(const MemoryHolder<H>& a_holder)const{
                    MemoryHolderLog(pankey_Log_StartMethod, "isMember", "println","");
                    auto i_manager = a_holder.getManager();
                    auto i_type = a_holder.getType();
                    MemoryHolderLog(pankey_Log_EndMethod, "isMember", "println","");
                    return this->isMember(i_manager, i_type);
                }

				virtual void setType(long a_type){
                    MemoryHolderLog(pankey_Log_StartMethod, "setType", "println","");
					MemoryHolderManager<H>::setType(this->getManager(), this->m_holder, a_type);
                    MemoryHolderLog(pankey_Log_EndMethod, "setType", "println","");
				}

				virtual long getType()const{
                    MemoryHolderLog(pankey_Log_StartMethod, "getType", "println","");
                    MemoryHolderLog(pankey_Log_EndMethod, "getType", "println","");
					return MemoryHolderManager<H>::getType(this->getManager(), this->m_holder);
				}

				virtual void setBaseType(long a_type){
                    MemoryHolderLog(pankey_Log_StartMethod, "setBaseType", "println","");
					MemoryHolderManager<H>::setBaseType(this->getManager(), this->m_holder, a_type);
                    MemoryHolderLog(pankey_Log_EndMethod, "setBaseType", "println","");
				}

				virtual long getBaseType()const{
                    MemoryHolderLog(pankey_Log_StartMethod, "getBaseType", "println","");
                    MemoryHolderLog(pankey_Log_EndMethod, "getBaseType", "println","");
					return MemoryHolderManager<H>::getBaseType(this->getManager(), this->m_holder);
				}

				virtual bool isNull(){
					MemoryHolderLog(pankey_Log_StartMethod, "isNull", "println","");
					if(m_holder == nullptr){
						MemoryHolderLog(pankey_Log_EndMethod, "isNull", "println","m_holder == nullptr");
						return true;
					}
					POINTER_TYPE i_pointer = MemoryHolderManager<H>::get(this->getManager(), m_holder);
					MemoryHolderLog(pankey_Log_Statement, "isNull", "println", "isNull: ");
					MemoryHolderLog(pankey_Log_Statement, "isNull", "println", i_pointer == nullptr);
					MemoryHolderLog(pankey_Log_EndMethod, "isNull", "println","");
					return i_pointer == nullptr;
				}

				//unsafe method
				virtual POINTER_TYPE getRawPointer()const{
                    MemoryHolderLog(pankey_Log_StartMethod, "getRawPointer", "println","");
					POINTER_TYPE i_pointer = MemoryHolderManager<H>::get(this->getManager(), m_holder);
					MemoryHolderLog(pankey_Log_Statement, "getRawPointer", "println","POINTER_TYPE is null?");
					MemoryHolderLog(pankey_Log_Statement, "getRawPointer", "println", i_pointer == nullptr);
					MemoryHolderLog(pankey_Log_EndMethod, "getRawPointer", "println","");
					return i_pointer;
				}

                virtual void operator=(const MemoryHolder<H>& a_holder){
                    MemoryHolderLog(pankey_Log_StartMethod, "operator=", "println","");
                    if(!this->isMember(a_holder)){
                        MemoryHolderLog(pankey_Log_Error, "operator=", "println", "MemoryHolder is not Member of Variable");
                        MemoryHolderLog(pankey_Log_EndMethod, "operator=", "println","");
                        return;
                    }
                    this->setHolder(a_holder.getHolder());
                    MemoryHolderLog(pankey_Log_EndMethod, "operator=", "println","");
                }

                virtual bool operator==(const MemoryHolder<H>& a_holder){
                    MemoryHolderLog(pankey_Log_StartMethod, "operator==", "println","");
                    MemoryHolderLog(pankey_Log_EndMethod, "operator==", "println", this->getHolder() == a_holder.getHolder());
                    return this->getHolder() == a_holder.getHolder();
                }

                virtual bool operator!=(const MemoryHolder<H>& a_holder){
                    MemoryHolderLog(pankey_Log_StartMethod, "operator!=", "println","");
                    MemoryHolderLog(pankey_Log_EndMethod, "operator!=", "println", this->getHolder() != a_holder.getHolder());
                    return this->getHolder() != a_holder.getHolder();
                }
				
				virtual MapEntry& operator=(const MapEntry<K,V,H,M>& a_map_entry){
					MapEntryLog(pankey_Log_StartMethod, "operator=", "println", "");
					m_key = a_map_entry.m_key;
					m_value = a_map_entry.m_value;
					MapEntryLog(pankey_Log_EndMethod, "operator=", "println", "");
					return *this;
				}
				
				virtual const MapEntry& operator=(MapEntry<K,V,H,M>&& a_map_entry){
					MapEntryLog(pankey_Log_StartMethod, "operator=", "println", "");
					m_key = a_map_entry.m_key;
					m_value = a_map_entry.m_value;
					a_map_entry.m_key = nullptr;
					a_map_entry.m_value = nullptr;
					MapEntryLog(pankey_Log_EndMethod, "operator=", "println", "");
					return *this;
				}
				
				virtual bool operator!=(const MapEntry<K,V,H,M>& a_map_entry){
					MapEntryLog(pankey_Log_StartMethod, "operator!=", "println", "");
					MapEntryLog(pankey_Log_EndMethod, "operator!=", "println", "");
					return m_key != a_map_entry.m_key && m_value != a_map_entry.m_value;
				}
				
				virtual bool operator==(const MapEntry<K,V,H,M>& a_map_entry){
					MapEntryLog(pankey_Log_StartMethod, "operator==", "println", "");
					MapEntryLog(pankey_Log_EndMethod, "operator==", "println", "");
					return m_key == a_map_entry.m_key && m_value == a_map_entry.m_value;
				}
				
				virtual bool isNull()const{
					MapEntryLog(pankey_Log_StartMethod, "isNull", "println", "");
					MapEntryLog(pankey_Log_EndMethod, "isNull", "println", "");
					return m_key.isNull() && m_value.isNull();
				}
			
			protected:

                HOLDER_TYPE m_key_holder = nullptr;
		};

	}

#endif