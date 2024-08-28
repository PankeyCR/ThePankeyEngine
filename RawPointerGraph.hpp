
#ifndef RawPointerGraph_hpp
#define RawPointerGraph_hpp
#define RawPointerGraph_AVAILABLE

#include "RawPointerTree.hpp"

namespace pankey{

template<class T>
class RawPointerGraph : virtual public RawPointerTree<T>{
	public:
		RawPointerGraph(){}

		RawPointerGraph(const RawPointerGraph<T>& c_RawPointerGraph){}

		virtual ~RawPointerGraph(){}

		virtual void operator=(const RawPointerGraph<T>& c_RawPointerGraph){}
		virtual bool operator==(RawPointerGraph<T> b){return false;}
		virtual bool operator!=(RawPointerGraph<T> b){return false;}
	
	protected:
};

}

#endif