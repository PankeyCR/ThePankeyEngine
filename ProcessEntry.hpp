
#ifndef ProcessEntry_hpp
#define ProcessEntry_hpp

#include "Processing.hpp"

namespace pankey{

template<class P, class V>
class ProcessEntry{
	public:
		ProcessEntry(P key, Processing<V>* value){
			this->key = key;
			this->value = value;
		}
		
		virtual ~ProcessEntry(){
			
		}
			
		
		virtual P getKey(){
			return this->key;
		}
		
		virtual Processing<V>* getValue(){
			return this->value;
		}
		
	protected:
		P key;
		Processing<V>* value;
};

}

#endif