
#ifndef PrintableGraph_hpp
#define PrintableGraph_hpp
#define PrintableGraph_AVAILABLE

#ifdef ame_Windows
	#include "ame_Printable.hpp"
	#include "ame_Print.hpp"
#endif

#ifdef ame_ArduinoIDE
	#include "Arduino.h"
	#include "Printable.h"
#endif

#include "cppObject.hpp"
#include "Graph.hpp"
#include "Class.hpp"

#ifdef PrintableGraph_LogApp
	#include "ame_Logger_config.hpp"
	#include "ame_Logger.hpp"

	#define PrintableGraphLog(location,method,type,mns) ame_Log(this,location,"PrintableGraph",method,type,mns)
	#define const_PrintableGraphLog(location,method,type,mns)
#else
	#ifdef PrintableGraph_LogDebugApp
		#include "ame_Logger_config.hpp"
		#include "ame_Logger.hpp"

		#define PrintableGraphLog(location,method,type,mns) ame_LogDebug(this,location,"PrintableGraph",method,type)
		#define const_PrintableGraphLog(location,method,type,mns)
	#else
		#define PrintableGraphLog(location,method,type,mns)
		#define const_PrintableGraphLog(location,method,type,mns)
	#endif
#endif

namespace ame{

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