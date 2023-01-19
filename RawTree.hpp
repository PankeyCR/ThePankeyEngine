
#ifndef RawTree_hpp
#define RawTree_hpp
#define RawTree_AVAILABLE

#include "RawPointerTree.hpp"

namespace ame{

template<class T>
class RawTree : virtual public RawPointerTree<T>{
	public:
		RawTree(){}

		RawTree(const RawTree<T>& c_RawTree){}

		virtual ~RawTree(){}

		virtual void operator=(const RawTree<T>& c_RawTree){}
		virtual bool operator==(RawTree<T> b){return false;}
		virtual bool operator!=(RawTree<T> b){return false;}
	
	protected:
};

}

#endif