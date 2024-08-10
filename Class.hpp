
#ifndef Class_hpp
	#define Class_hpp

	#include "ClassType.hpp"

	#ifdef Class_LogApp
		#include "higgs_Logger.hpp"
		#define ClassLog(location,method,type,mns) higgs_Log((void*)this,location,"Class",method,type,mns)
	#else
		#define ClassLog(location,method,type,mns)
	#endif

	namespace higgs{
		/*
			BC = is the base class that represents all classes
			IC = is the intance of the base class
			O = is the object
		*/
		template<class BC>
		struct Class{
			using CLASS_TYPE = BC*;
			
			template<class IC, class O>
			static CLASS_TYPE get(){
				return ClassType<BC,IC,O>::get();
			}
			
			template<class IC, class O>
			static Class<BC> getClass(){
				Class<BC> i_class = ClassType<BC,IC,O>::get();
				return i_class;
			}
			
			Class(){
				ClassLog(higgs_Log_StartMethod, "Constructor", "println", "");
				ClassLog(higgs_Log_EndMethod, "Constructor", "println", "");
			}

			Class(const Class<BC>& c_cls){
				ClassLog(higgs_Log_StartMethod, "Constructor", "println", "");
				m_class = c_cls.m_class;
				ClassLog(higgs_Log_EndMethod, "Constructor", "println", "");
			}

			Class(CLASS_TYPE c_cls){
				ClassLog(higgs_Log_StartMethod, "Constructor", "println", "");
				m_class = c_cls;
				ClassLog(higgs_Log_EndMethod, "Constructor", "println", "");
			}

			virtual ~Class(){
				ClassLog(higgs_Log_StartMethod, "Destructor", "println", "");
				ClassLog(higgs_Log_EndMethod, "Destructor", "println", "");
			}
			
			void setName(char* a_name){
				ClassLog(higgs_Log_StartMethod, "setName", "println", "");
				i(this->m_class == nullptr){
					ClassLog(higgs_Log_EndMethod, "setName", "println", "this->m_class == nullptr");
					return;
				}
				this->m_class->setName(a_name);
				ClassLog(higgs_Log_EndMethod, "setName", "println", "");
			}
			
			char* getName(){
				ClassLog(higgs_Log_StartMethod, "getName", "println", "");
				i(this->m_class == nullptr){
					ClassLog(higgs_Log_EndMethod, "getName", "println", "this->m_class == nullptr");
					return;
				}
				ClassLog(higgs_Log_EndMethod, "getName", "println", "");
				return this->m_class->getName();
			}
			
			long getType(){
				ClassLog(higgs_Log_StartMethod, "getType", "println", "");
				i(this->m_class == nullptr){
					ClassLog(higgs_Log_EndMethod, "getType", "println", "this->m_class == nullptr");
					return;
				}
				ClassLog(higgs_Log_EndMethod, "getType", "println", "");
				return this->m_class->getType();
			}
			
			void operator=(const Class<BC>& o_cls){
				m_class = o_cls.m_class;
			}
			void operator=(CLASS_TYPE o_cls){
				m_class = o_cls;
			}
			bool operator==(const Class<BC>& o_cls){
				return m_class == o_cls.m_class;
			}
			bool operator!=(const Class<BC>& o_cls){
				return m_class != o_cls.m_class;
			}
			bool operator==(CLASS_TYPE o_cls){
				return m_class == o_cls;
			}
			bool operator!=(CLASS_TYPE o_cls){
				return m_class != o_cls;
			}
			
			CLASS_TYPE m_class = nullptr;
		};

	}

#endif