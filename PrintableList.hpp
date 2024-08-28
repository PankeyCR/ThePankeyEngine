
#ifndef PrintableList_hpp
	#define PrintableList_hpp

	#ifdef pankey_Windows
		#include "pankey_Printable.hpp"
		#include "pankey_Print.hpp"
	#endif

	#ifdef pankey_ArduinoIDE
		#include "Arduino.h"
		#include "Printable.h"
	#endif

	#ifdef PrintableList_LogApp
		#include "pankey_Logger.hpp"
		#define PrintableListLog(location,method,type,mns) pankey_Log((void*)this,location,"PrintableList",method,type,mns)
	#else
		#define PrintableListLog(location,method,type,mns)
	#endif

	namespace pankey{

		template <class TL, class V>
		class PrintableList : public Printable {	
			public:
			PrintableList(const TL& c_list) : m_list(c_list){}
			PrintableList(const TL& c_list, bool c_println) : m_list(c_list){m_println = c_println;}
			virtual ~PrintableList(){}

			virtual size_t printTo(Print& p) const{
				if(this->m_list.isEmpty()){
					return 0;
				}
				size_t i_size = 0;
				for(int x = 0; x < this->m_list.getPosition(); x++){
					V* f_value = this->m_list.getByPosition(x);
					if(f_value == nullptr){
						continue;
					}
					if(m_println){
						if(x == this->m_list.getPosition() - 1){
							i_size += p.print(*f_value);
						}else{
							i_size += p.println(*f_value);
						}
					}else{
						i_size += p.print(*f_value);
					}
				}
				return i_size;
			}
			
			protected:
				const TL& m_list;
				bool m_println = true;
		};

	}

#endif