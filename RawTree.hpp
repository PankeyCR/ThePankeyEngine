
#ifndef RawTree_hpp
#define RawTree_hpp
#define RawTree_AVAILABLE

#include "RawPointerTree.hpp"
#include "RawList.hpp"

namespace higgs{

template<class T>
class RawTree : virtual public RawPointerTree<T>, virtual public RawList<RawTree<T>>{
	public:
		virtual ~RawTree(){}
	
	protected:
};

}

#endif