
#ifndef PrintableGraph_hpp
#define PrintableGraph_hpp
#define PrintableGraph_AVAILABLE

#ifdef pankey_Windows
	#include "pankey_Printable.hpp"
	#include "pankey_Print.hpp"
#endif

#ifdef pankey_ArduinoIDE
	#include "Arduino.h"
	#include "Printable.h"
#endif

#include "cppObject.hpp"
#include "Graph.hpp"
#include "Class.hpp"

#ifdef PrintableGraph_LogApp
	#include "pankey_Logger_config.hpp"
	#include "pankey_Logger.hpp"

	#define PrintableGraphLog(location,method,type,mns) pankey_Log(this,location,"PrintableGraph",method,type,mns)
	#define const_PrintableGraphLog(location,method,type,mns)
#else
	#ifdef PrintableGraph_LogDebugApp
		#include "pankey_Logger_config.hpp"
		#include "pankey_Logger.hpp"

		#define PrintableGraphLog(location,method,type,mns) pankey_LogDebug(this,location,"PrintableGraph",method,type)
		#define const_PrintableGraphLog(location,method,type,mns)
	#else
		#define PrintableGraphLog(location,method,type,mns)
		#define const_PrintableGraphLog(location,method,type,mns)
	#endif
#endif

namespace pankey{

/*
*	Class Configuration:
*	DISABLE_IMPLEMENTING_cppObject
*/
template <class T>
class PrintableGraph : public Printable {	
	public:
	PrintableGraph(Graph<T>& c_graph) : m_graph(c_graph){
	}
	virtual ~PrintableGraph(){}

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
		Graph<T>& m_graph;
};

}

#endif