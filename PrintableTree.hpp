
#ifndef PrintableTree_hpp
#define PrintableTree_hpp
#define PrintableTree_AVAILABLE

#ifdef pankey_Windows
	#include "pankey_Printable.hpp"
	#include "pankey_Print.hpp"
#endif

#ifdef pankey_ArduinoIDE
	#include "Arduino.h"
	#include "Printable.h"
#endif

#include "cppObject.hpp"
#include "Tree.hpp"
#include "Class.hpp"

#ifdef PrintableTree_LogApp
	#include "pankey_Logger_config.hpp"
	#include "pankey_Logger.hpp"

	#define PrintableTreeLog(location,method,type,mns) pankey_Log(this,location,"PrintableTree",method,type,mns)
	#define const_PrintableTreeLog(location,method,type,mns)
#else
	#ifdef PrintableTree_LogDebugApp
		#include "pankey_Logger_config.hpp"
		#include "pankey_Logger.hpp"

		#define PrintableTreeLog(location,method,type,mns) pankey_LogDebug(this,location,"PrintableTree",method,type)
		#define const_PrintableTreeLog(location,method,type,mns)
	#else
		#define PrintableTreeLog(location,method,type,mns)
		#define const_PrintableTreeLog(location,method,type,mns)
	#endif
#endif

namespace pankey{

/*
*	Class Configuration:
*	DISABLE_IMPLEMENTING_cppObject
*/
template <class T>
class PrintableTree : public Printable {	
	public:
	PrintableTree(Tree<T>& c_tree) : m_tree(c_tree){
	}
	virtual ~PrintableTree(){}

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
		Tree<T>& m_tree;
};

}

#endif