
#ifndef RawGraph_hpp
#define RawGraph_hpp
#define RawGraph_AVAILABLE

#include "RawTree.hpp"
#include "RawPointerGraph.hpp"

namespace ame{

template<class T>
class RawGraph : virtual public RawPointerGraph<T>, virtual public RawTree<T>{
	public:
		RawGraph(){}

		RawGraph(const RawGraph<T>& c_RawGraph){}

		virtual ~RawGraph(){}

		virtual void operator=(const RawGraph<T>& c_RawGraph){}
		virtual bool operator==(RawGraph<T> b){return false;}
		virtual bool operator!=(RawGraph<T> b){return false;}
	
	protected:
};

}

#endif