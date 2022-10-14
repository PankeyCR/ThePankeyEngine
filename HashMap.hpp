
#ifndef HashMap_hpp
#define HashMap_hpp
#define HashMap_AVAILABLE 

#include "Map.hpp"
#include "PrimitiveMap.hpp"

#ifdef HashMap_LogApp
	#include "ame_Logger_config.hpp"
	#include "ame_Logger.hpp"

	#define HashMapLog(location,method,type,mns) ame_Log((void*)this,location,"HashMap",method,type,mns)
	#define const_HashMapLog(location,method,type,mns)
#else
	#ifdef HashMap_LogDebugApp
		#include "ame_Logger_config.hpp"
		#include "ame_Logger.hpp"

		#define HashMapLog(location,method,type,mns) ame_LogDebug((void*)this,location,"HashMap",method,type)
		#define const_HashMapLog(location,method,type,mns)
	#else
		#define HashMapLog(location,method,type,mns)
		#define const_HashMapLog(location,method,type,mns)
	#endif
#endif

namespace ame{

template <class K,class V>
class HashMap : public PrimitiveMap<K,V>{	
    public:
		
		HashMap(){
			HashMapLog(ame_Log_StartMethod, "Constructor", "println", "");
			HashMapLog(ame_Log_EndMethod, "Constructor", "println", "");
		}
		
		HashMap(const HashMap<K,V>& map){
			this->owner = map.owner;
			this->keys = new K*[map.getSize()];
			this->values = new V*[map.getSize()];
			for(int x = 0; x < map.getPosition(); x++){
				K k = *map.getKeyByPosition(x);
				V v = *map.getByPosition(x);
				this->addLValues(k,v);
			}
		}
		
		HashMap(int msize){
			
		}
		
		HashMap(bool own, int msize){
			
		}
		
		virtual ~HashMap(){
			
		}
		
	protected:
		
};

}

#endif