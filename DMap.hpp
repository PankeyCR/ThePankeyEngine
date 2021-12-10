
#include "ame_Level.hpp"

#if defined(ame_untilLevel_7)

#ifndef DMap_hpp
#define DMap_hpp

namespace ame{

template <class T>
class DMap {
	public:
		virtual void vector(int dimention,int pos);
		virtual void add(T t);
		virtual void remove();
		virtual T get();
		virtual int getDPos(int dimention);
		virtual int size();
	private:
};

}

#endif 

#endif 
