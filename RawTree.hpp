
#ifndef RawTree_hpp
#define RawTree_hpp
#define RawTree_AVAILABLE

#include "RawPointerTree.hpp"
#include "RawList.hpp"

namespace pankey{

template<class T>
class RawTree : virtual public RawPointerTree<T>, virtual public RawList<RawTree<T>>{
	public:
		virtual ~RawTree(){}
	
	protected:
};

}

#endif