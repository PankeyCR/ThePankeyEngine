
#ifndef Class_hpp
	#define Class_hpp

	#include "ClassName.hpp"
	#include "ClassTYPE.hpp"
	#include "ClassCount.hpp"

	#ifdef Class_LogApp
		#include "pankey_Logger.hpp"
		#define ClassLog(location,method,type,mns) pankey_Log((void*)this,location,"Class",method,type,mns)
	#else
		#define ClassLog(location,method,type,mns)
	#endif

	namespace pankey{
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
				return ClassTYPE<BC,IC,O>::get();
			}
			
			template<class IC, class O>
			static Class<BC> getDerivedClass(){
				Class<BC> i_class = Class<BC>(ClassTYPE<BC,IC,O>::get(), ClassName<O>::get(), ClassCount<O>::get());
				return i_class;
			}
			
			template<class O>
			static Class<BC> getClass(){
				Class<BC> i_class = Class<BC>(ClassTYPE<BC,BC,O>::get(), ClassName<O>::get(), ClassCount<O>::get());
				return i_class;
			}
			
			Class(){
				ClassLog(pankey_Log_StartMethod, "Constructor", "println", "");
				ClassLog(pankey_Log_EndMethod, "Constructor", "println", "");
			}

			Class(const Class<BC>& c_cls){
				ClassLog(pankey_Log_StartMethod, "Constructor", "println", "");
				m_class = c_cls.m_class;
				m_name = c_cls.m_name;
				m_type = c_cls.m_type;
				ClassLog(pankey_Log_EndMethod, "Constructor", "println", "");
			}

			Class(CLASS_TYPE c_cls, CharArray c_name, long c_type){
				ClassLog(pankey_Log_StartMethod, "Constructor", "println", "");
				m_class = c_cls;
				m_name = c_name;
				m_type = c_type;
				ClassLog(pankey_Log_EndMethod, "Constructor", "println", "");
			}

			virtual ~Class(){
				ClassLog(pankey_Log_StartMethod, "Destructor", "println", "");
				ClassLog(pankey_Log_EndMethod, "Destructor", "println", "");
			}
			
			CharArray getName(){
				ClassLog(pankey_Log_StartMethod, "getName", "println", "");
				ClassLog(pankey_Log_EndMethod, "getName", "println", "");
				return m_name;
			}
			
			long getType(){
				ClassLog(pankey_Log_StartMethod, "getType", "println", "");
				ClassLog(pankey_Log_EndMethod, "getType", "println", "");
				return m_type;
			}
			
			bool isNull(){
				ClassLog(pankey_Log_StartMethod, "isNull", "println", "");
				if(m_class == nullptr){
					ClassLog(pankey_Log_EndMethod, "isNull", "println", "m_class == nullptr");
					return true;
				}
				ClassLog(pankey_Log_EndMethod, "isNull", "println", "");
				return false;
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
			CharArray m_name = "Default";
			long m_type = -1;
		};

	}

#endif