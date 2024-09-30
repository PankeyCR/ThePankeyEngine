
#ifndef Member_hpp
	#define Member_hpp

    #include "MemoryHolder.hpp"
    #include "StaticManagerInstance.hpp"

    #ifdef Member_LogApp
        #include "pankey_Logger.hpp"
        #define MemberLog(location,method,type,mns) pankey_Log(nullptr,location,"Member",method,type,mns)
    #else
        #define MemberLog(location,method,type,mns)
    #endif

	namespace pankey{

        template<class H, class M>
        class Member : public MemoryHolder<H>{
            public:
            
                using MANAGER_TYPE = typename MemoryHolder<H>::MANAGER_TYPE;

                Member(){
                    MemberLog(pankey_Log_StartMethod, "Constructor", "println","");
                    MemberLog(pankey_Log_EndMethod, "Constructor", "println","");
                }

                Member(const MemoryHolder<H>& a_holder){
                    MemberLog(pankey_Log_StartMethod, "Constructor", "println","const MemoryHolder<H>& a_holder");
                    if(!a_holder.shareManager(this->getManager())){
                        MemberLog(pankey_Log_EndMethod, "Constructor", "println","!a_holder.shareManager(this->getManager())");
                        return;
                    }
                    this->setHolder(a_holder.getHolder());
                    MemberLog(pankey_Log_EndMethod, "Constructor", "println","");
                }

                Member(const Member<H,M>& a_holder){
                    MemberLog(pankey_Log_StartMethod, "Constructor", "println","const Member<H,M>& a_holder");
                    this->setHolder(a_holder.getHolder());
                    MemberLog(pankey_Log_EndMethod, "Constructor", "println","");
                }
                
                virtual ~Member(){
                    MemberLog(pankey_Log_StartMethod, "Destructor", "println","");
					this->remove();
                    MemberLog(pankey_Log_EndMethod, "Destructor", "println","");
                }

                virtual MANAGER_TYPE getManager()const{
                    MemberLog(pankey_Log_StartMethod, "getManager", "println","");
                    MemberLog(pankey_Log_Statement, "getManager", "println","Is Null?");
                    MemberLog(pankey_Log_Statement, "getManager", "println",(StaticManagerInstance<H,M>::getManager() == nullptr));
                    MemberLog(pankey_Log_EndMethod, "getManager", "println","");
                    return StaticManagerInstance<H,M>::getManager();
                }

                virtual void copyMemoryHolder(const MemoryHolder<H>& a_holder){
                    MemoryHolderLog(pankey_Log_StartMethod, "copyMemoryHolder", "println","");
                    if(!this->shareManager(a_holder)){
                        MemberLog(pankey_Log_EndMethod, "copyMemoryHolder", "println","");
                        return;
                    }
                    this->setHolder(a_holder.getHolder());
                    MemoryHolderLog(pankey_Log_EndMethod, "copyMemoryHolder", "println","");
                }

                virtual void copyMember(const Member<H,M>& a_holder){
                    MemberLog(pankey_Log_StartMethod, "copyMember", "println","");
                    this->setHolder(a_holder.getHolder());
                    MemberLog(pankey_Log_EndMethod, "copyMember", "println","");
                }

                virtual Member<H,M> getMember(){
                    MemberLog(pankey_Log_StartMethod, "getMember", "println","");
                    MemberLog(pankey_Log_EndMethod, "getMember", "println","");
                    Member<H,M> i_member;
                    i_member.setHolder(this->getHolder());
                    return i_member;
                }

                virtual void operator=(const Member<H,M>& a_holder){
                    MemberLog(pankey_Log_StartMethod, "operator=", "println","");
                    this->setHolder(a_holder.getHolder());
                    MemberLog(pankey_Log_EndMethod, "operator=", "println","");
                }

            
        };

	}

#endif