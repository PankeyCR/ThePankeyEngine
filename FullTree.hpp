
#ifndef FullTree_hpp
#define FullTree_hpp
#define FullTree_AVAILABLE

#include "Tree.hpp"
#include "LinkedList.hpp"

namespace ame{

class FullTreeNode{
	public:
		FullTreeNode(){}

		virtual ~FullTreeNode(){}
	
	protected:
	
};

template<class T, class UniversalNode = FullTreeNode>
class FullTree : virtual public Tree{
	public:
		FullTree(){}

		FullTree(const FullTree<T>& c_FullTree){
		}

		virtual ~FullTree(){}

		virtual void operator=(const FullTree<T>& c_FullTree){
		}
		virtual bool operator==(FullTree<T> b){return false;}
		virtual bool operator!=(FullTree<T> b){return false;}

			
		#if defined(cppObject_AVAILABLE) && defined(cppObjectClass_AVAILABLE) && defined(Class_AVAILABLE)
		virtual cppObjectClass* getClass(){return Class<FullTree<T>>::getClass();}
		virtual bool instanceof(cppObjectClass* cls){return cls == Class<FullTree<T>>::getClass() || Tree<T>::instanceof(cls);}
		#endif
	
	protected:
		LinkedList<FullTree<T>> m_branches_list;
};

}

#endif