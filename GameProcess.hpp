
#include "ame_Level.hpp"

#if defined(ame_untilLevel_7)

#ifndef GameProcess_hpp
#define GameProcess_hpp

#include "Processing.hpp"

namespace ame{
	
template<class P, class V>
class GameProcess{
	public:
		GameProcess();
		virtual ~GameProcess();
		
		virtual void addProcess(ProcessEntry<P,V>* p);
		virtual Map<P,Processing<V>> getProcessMap();
		
		virtual GameProcess<P,V>* Process(P key,GameProcess<P,V>* gameProcess);
		virtual GameProcess<P,V>* Process(P key,GameProcess<P,V>* gameProcess,GameProcess<P,V>* gameProcess2);
		virtual GameProcess<P,V>* Process(P key,V value2);
		virtual GameProcess<P,V>* Process(P key,V value1,V value2);

		virtual V getValue();
		virtual void setValue(V set);

		
	protected:
		P key;
		Processing<V>* value;
};

}

#endif 

#endif 
