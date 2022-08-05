
#include "ame_Enviroment.hpp"

#if defined(DISABLE_Pair)
	#define Pair_hpp
#endif

#ifndef Pair_hpp
#define Pair_hpp
#define Pair_AVAILABLE

#ifndef ame_Enviroment_Defined

#endif

#ifdef ame_Windows

#endif

#ifdef ame_ArduinoIDE
	#include "Arduino.h"
#endif

namespace ame{

template<class K,class V>
class Pair{
    public:
		K* key=nullptr;
		V* value=nullptr;
		Pair(){}
		Pair(bool own){
			owner = own;
		}
		Pair(K k,V v){
			key = new K(k);
			value = new V(v);
			owner = true;
		}
		Pair(K* k,V* v){
			key = k;
			value = v;
		}
		Pair(K* k,V* v, bool own){
			key = k;
			value = v;
			owner = own;
		}
		~Pair(){
			if(owner){
				delete key;
				delete value;
			}
		}
		virtual void operator=(Pair b){
			key = b.key;
			value = b.value;
		}
		virtual bool operator==(Pair b){
			return key == b.key && value == b.value;
		}
		virtual bool operator!=(Pair b){
			return key != b.key && value != b.value;
		}
	protected:
		bool owner = false;
};

}

#endif