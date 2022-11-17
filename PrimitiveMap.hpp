
#ifndef PrimitiveMap_hpp
#define PrimitiveMap_hpp
#define PrimitiveMap_AVAILABLE

#include "PrimitiveRawMap.hpp"
#include "Map.hpp"
#include "Class.hpp"

#ifdef PrimitiveMap_LogApp
	#include "ame_Logger_config.hpp"
	#include "ame_Logger.hpp"

	#define PrimitiveMapLog(location,method,type,mns) ame_Log(this,location,"PrimitiveMap",method,type,mns)
	#define const_PrimitiveMapLog(location,method,type,mns)
#else
	#ifdef PrimitiveMap_LogDebugApp
		#include "ame_Logger_config.hpp"
		#include "ame_Logger.hpp"

		#define PrimitiveMapLog(location,method,type,mns) ame_LogDebug(this,location,"PrimitiveMap",method,type)
		#define const_PrimitiveMapLog(location,method,type,mns)
	#else
		#define PrimitiveMapLog(location,method,type,mns)
		#define const_PrimitiveMapLog(location,method,type,mns)
	#endif
#endif

namespace ame{

template <class K,class V>
class PrimitiveMap : public PrimitiveRawMap<K,V> , public Map<K,V>{
    public:

		PrimitiveMap(){
			PrimitiveMapLog(ame_Log_StartMethod, "Constructor", "println", "");
			PrimitiveMapLog(ame_Log_EndMethod, "Constructor", "println", "");
		}

		PrimitiveMap(const PrimitiveMap& c_map){
			PrimitiveMapLog(ame_Log_StartMethod, "Constructor", "println", "const PrimitiveMap& c_map");
			this->setOwner(c_map.m_owner);
			this->expandLocal(c_map.getPosition());
			for(int x = 0; x < c_map.getPosition(); x++){
				K* k = c_map.getKeyByPosition(x);
				V* v = c_map.getValueByPosition(x);
				if(k != nullptr && v != nullptr){
					this->addLValues(*k,*v);
				}
				if(k != nullptr && v == nullptr){
					this->addPointer(*k,nullptr);
				}
			}
			PrimitiveMapLog(ame_Log_EndMethod, "Constructor", "println", "");
		}

		PrimitiveMap(int c_size) : PrimitiveRawMap<K,V>(c_size){
			PrimitiveMapLog(ame_Log_StartMethod, "Constructor", "println", "int c_size");
			PrimitiveMapLog(ame_Log_EndMethod, "Constructor", "println", "");
		}

		PrimitiveMap(int c_size, bool c_key_own, bool c_value_own, bool c_reorder) : PrimitiveRawMap<K,V>(c_size, c_key_own, c_value_own, c_reorder){
			PrimitiveMapLog(ame_Log_StartMethod, "Constructor", "println", "int c_size, bool c_own");
			PrimitiveMapLog(ame_Log_EndMethod, "Constructor", "println", "");
		}

		virtual ~PrimitiveMap(){
			PrimitiveMapLog(ame_Log_StartMethod, "Destructor", "println", "");
			PrimitiveMapLog(ame_Log_EndMethod, "Destructor", "println", "");
		}

		virtual PrimitiveMap& operator=(const PrimitiveMap& a_map){
			PrimitiveMapLog(ame_Log_StartMethod, "Constructor", "println", "");
			this->resetDelete();
			for(int x = 0; x < a_map.getPosition(); x++){
				K* k = a_map.getKeyByPosition(x);
				V* v = a_map.getValueByPosition(x);
				if(k != nullptr && v != nullptr){
					this->addLValues(*k,*v);
					continue;
				}
				if(k != nullptr && v == nullptr){
					this->addPointer(*k,nullptr);
					continue;
				}
			}
			PrimitiveMapLog(ame_Log_EndMethod, "Constructor", "println", "");
			return *this;
		}
		
		virtual bool operator==(const PrimitiveMap& a_map){
			if(a_map.getPosition() != this->getPosition()){
				return false;
			}
			for(int x = 0; x < a_map.getPosition(); x++){
				K* k_1 = this->getKeyByPosition(x);
				V* v_1 = this->getValueByPosition(x);
				
				K* k_2 = a_map.getKeyByPosition(x);
				V* v_2 = a_map.getValueByPosition(x);
				
				if(!this->isEqualKey(k_1, k_2)){
					return false;
				}
				if(!this->isEqualValue(v_1, v_2)){
					return false;
				}
			}
			return true;
		}
		
		virtual bool operator!=(const PrimitiveMap& a_map){
			if(a_map.getPosition() != this->getPosition()){
				return true;
			}
			for(int x = 0; x < a_map.getPosition(); x++){
				K* k_1 = this->getKeyByPosition(x);
				V* v_1 = this->getValueByPosition(x);
				
				K* k_2 = a_map.getKeyByPosition(x);
				V* v_2 = a_map.getValueByPosition(x);
				
				if(!this->isEqualKey(k_1, k_2)){
					return true;
				}
				if(!this->isEqualValue(v_1, v_2)){
					return true;
				}
			}
			return false;
		}


	protected:
};

}

#endif
