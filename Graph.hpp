
#ifndef Graph_hpp
#define Graph_hpp
#define Graph_AVAILABLE

#include "Tree.hpp"
#include "RawGraph.hpp"
#include "LinkedList.hpp"

namespace ame{

template<class T>
class Graph : virtual public RawGraph<T>, virtual public Tree<T>{
	public:
		Graph(){}

		Graph(const Graph<T>& c_Graph){}

		virtual ~Graph(){}
/*
		virtual List<T>* getChildsListPointer(){return nullptr;}
		virtual Graph getChildByIndex(int a_index){return nullptr;}
		virtual Graph* getChildPointerByIndex(int a_index){return nullptr;}
*/
		virtual void operator=(const Graph<T>& c_Graph){}
		virtual bool operator==(Graph<T> b){return false;}
		virtual bool operator!=(Graph<T> b){return false;}

			
		#if defined(cppObject_AVAILABLE) && defined(cppObjectClass_AVAILABLE) && defined(Class_AVAILABLE)
		virtual cppObjectClass* getClass(){return Class<Graph<T>>::getClass();}
		virtual bool instanceof(cppObjectClass* cls){return cls == Class<Graph<T>>::getClass();}
		#endif
	
	protected:
};

}

#endif