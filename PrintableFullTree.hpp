
#ifndef PrintableFullTree_hpp
#define PrintableFullTree_hpp
#define PrintableFullTree_AVAILABLE

#ifdef ame_Windows
	#include "ame_Printable.hpp"
	#include "ame_Print.hpp"
#endif

#ifdef ame_ArduinoIDE
	#include "Arduino.h"
	#include "Printable.h"
#endif

#include "cppObject.hpp"
#include "cppObject.hpp"
#include "Class.hpp"

#ifdef PrintableFullTree_LogApp
	#include "ame_Logger_config.hpp"
	#include "ame_Logger.hpp"

	#define PrintableFullTreeLog(location,method,type,mns) ame_Log(this,location,"PrintableFullTree",method,type,mns)
	#define const_PrintableFullTreeLog(location,method,type,mns)
#else
	#ifdef PrintableFullTree_LogDebugApp
		#include "ame_Logger_config.hpp"
		#include "ame_Logger.hpp"

		#define PrintableFullTreeLog(location,method,type,mns) ame_LogDebug(this,location,"PrintableFullTree",method,type)
		#define const_PrintableFullTreeLog(location,method,type,mns)
	#else
		#define PrintableFullTreeLog(location,method,type,mns)
		#define const_PrintableFullTreeLog(location,method,type,mns)
	#endif
#endif

namespace ame{

/*
*	Class Configuration:
*	DISABLE_IMPLEMENTING_cppObject
*/
template <class T>
class PrintableFullTree : public Printable {	
	public:
	PrintableFullTree(FullTree<T>& c_tree) : m_tree(c_tree){
	}
	virtual ~PrintableFullTree(){}

	virtual size_t printTo(Print& p) const{/*
		if(this->m_tree.isEmpty()){
			return 0;
		}*/
		size_t i_size = 0;/*
		for(int x = 0; x < this->m_list.getPosition(); x++){
			V* f_value = this->m_list.getByPosition(x);
			if(f_value == nullptr){
				continue;
			}
			if(x == this->m_list.getPosition() - 1){
				i_size += p.print(*f_value);
			}else{
				i_size += p.println(*f_value);
			}
		}*/
		return i_size;
	}
	
	protected:
		FullTree<T>& m_tree;
};

}

#endif