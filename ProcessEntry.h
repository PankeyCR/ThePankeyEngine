

#ifndef ProcessEntry_hpp
#define ProcessEntry_hpp

#include "Processing.hpp"

namespace ame{

template<class P, class V>
class ProcessEntry{
	public:
		ProcessEntry(P key, Processing<V>* value);
		virtual ~ProcessEntry();
		
		virtual P getKey();
		virtual Processing<V>* getValue();
		
	protected:
		P key;
		Processing<V>* value;
};

}

#endif 
