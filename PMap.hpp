
#ifndef PMap_hpp
#define PMap_hpp
#define PMap_AVAILABLE 

#include "Map.hpp"
#include "Class.hpp"

#ifdef PMap_LogApp
	#include "ame_Logger_config.hpp"
	#include "ame_Logger.hpp"

	#define PMapLog(location,method,type,mns) ame_Log((void*)this,location,"PMap",method,type,mns)
	#define const_PMapLog(location,method,type,mns)
#else
	#ifdef PMap_LogDebugApp
		#include "ame_Logger_config.hpp"
		#include "ame_Logger.hpp"

		#define PMapLog(location,method,type,mns) ame_LogDebug((void*)this,location,"PMap",method,type)
		#define const_PMapLog(location,method,type,mns)
	#else
		#define PMapLog(location,method,type,mns)
		#define const_PMapLog(location,method,type,mns)
	#endif
#endif

namespace ame{

template <class K,class P,int size>
class PMap : public Map<K,P>{
	
    public:
		PMap(){
			PMapLog(ame_Log_StartMethod, "Constructor", "println", "");
			PMapLog(ame_Log_EndMethod, "Constructor", "println", "");
		}
		
		PMap(const PMap<K,P,size>& c_map){
			PMapLog(ame_Log_StartMethod, "Constructor", "println", "");
			this->setOwner(c_map.isOwner());
			
			for(int x = 0; x < c_map.getPosition(); x++){
				K* k = c_map.getKeyByPosition(x);
				P* v = c_map.getValueByPosition(x);
				if(k != nullptr && v != nullptr){
					this->addLValues(*k,*v);
				}
				if(k != nullptr && v == nullptr){
					this->addPointer(*k,v);
				}
			}
			PMapLog(ame_Log_EndMethod, "Constructor", "println", "");
		}
		
		PMap(const bool& own){
			PMapLog(ame_Log_StartMethod, "Constructor", "println", "");
			this->setOwner(own);
			PMapLog(ame_Log_EndMethod, "Constructor", "println", "");
		}
		
		virtual ~PMap(){
			PMapLog(ame_Log_StartMethod, "Destructor", "println", "");
			if(this->isOwner()){
				for(int x=0; x < this->getPosition(); x++){
					delete keys[x];
					delete values[x];
				}
			}
			PMapLog(ame_Log_EndMethod, "Destructor", "println", "");
		}
		
		virtual void addPointers(K *key, P *value){
			PMapLog(ame_Log_StartMethod, "addPointers", "println", "");
			if(!this->hasAvailableSize()){
				return;
			}
			keys[pos] = key;
			values[pos] = value;
			pos++;
			PMapLog(ame_Log_EndMethod, "addPointers", "println", "");
		}
		
		virtual void addLValues(K key, P value){
			PMapLog(ame_Log_StartMethod, "addLValues", "println", "");
			if(!this->hasAvailableSize()){
				PMapLog(ame_Log_EndMethod, "addLValues", "println", "");
				return;
			}
			keys[pos] = new K();
			values[pos] = new P();
			*keys[pos] = key;
			*values[pos] = value;
			pos++;
			PMapLog(ame_Log_EndMethod, "addLValues", "println", "");
		}
		
		virtual void addPointer(K key, P *value){
			PMapLog(ame_Log_StartMethod, "addPointer", "println", "");
			if(size < pos){
				PMapLog(ame_Log_EndMethod, "addPointer", "println", "");
				return;
			}
			keys[pos] = new K();
			*keys[pos] = key;
			values[pos] = value;
			pos++;
			PMapLog(ame_Log_EndMethod, "addPointer", "println", "");
		}
		
		virtual void add(K key, P value){
			PMapLog(ame_Log_StartMethod, "add", "println", "");
			if(size < pos){
				PMapLog(ame_Log_EndMethod, "add", "println", "");
				return;
			}
			keys[pos] = new K();
			values[pos] = new P();
			*keys[pos] = key;
			*values[pos] = value;
			pos++;
			PMapLog(ame_Log_EndMethod, "add", "println", "");
		}
		
		virtual void addCopy(RawMap<K,P>* r_map){
			PMapLog(ame_Log_StartMethod, "addCopy", "println", "");
			for(int x = 0; x < r_map->getPosition(); x++){
				K* k = this->getKeyByPosition(x);
				P* v = this->getByPosition(x);
				this->addLValues(*k, *v);
			}
			PMapLog(ame_Log_EndMethod, "addCopy", "println", "");
		}
		
		virtual void addMove(RawMap<K,P>* r_map){
			PMapLog(ame_Log_StartMethod, "addMove", "println", "");
			for(int x = 0; x < r_map->getPosition(); x++){
				K* k = this->getKeyByPosition(x);
				P* v = this->getByPosition(x);
				if(this->isOwner()){
					this->addLValues(*k, *v);
				}else{
					this->addPointers(k, v);
				}
			}
			PMapLog(ame_Log_EndMethod, "addMove", "println", "");
		}
		
		virtual void setPointers(K *key, P *value){
			PMapLog(ame_Log_StartMethod, "setPointers", "println", "");
			if(size < pos){
				PMapLog(ame_Log_EndMethod, "setPointers", "println", "");
				return;
			}
			for(int x=0; x < pos; x++){
				if(keys[x] == key ){
					values[x] = value;
				}
			}
			PMapLog(ame_Log_EndMethod, "setPointers", "println", "");
		}
		
		virtual void setLValues(K key, P value){
			PMapLog(ame_Log_StartMethod, "setLValues", "println", "");
			if(size < pos){
				PMapLog(ame_Log_EndMethod, "setLValues", "println", "");
				return;
			}
			for(int x=0; x < pos; x++){
				if(*keys[x] == key ){
					*values[x] = value;
				}
			}
			PMapLog(ame_Log_EndMethod, "setLValues", "println", "");
		}
		
		virtual void setPointer(K key, P *value){
			PMapLog(ame_Log_StartMethod, "setPointer", "println", "");
			if(size < pos){
				PMapLog(ame_Log_EndMethod, "setPointer", "println", "");
				return;
			}
			for(int x=0; x < pos; x++){
				if(*keys[x] == key ){
					values[x] = value;
				}
			}
			PMapLog(ame_Log_EndMethod, "setPointer", "println", "");
		}
		
		virtual void setKeyLValueByPosition(int p, K key){
			PMapLog(ame_Log_StartMethod, "setKeyLValueByPosition", "println", "");
			if(size < p){
				PMapLog(ame_Log_EndMethod, "setKeyLValueByPosition", "println", "");
				return;
			}
			*keys[p] = key;
			PMapLog(ame_Log_EndMethod, "setKeyLValueByPosition", "println", "");
		}
		
		virtual void setKeyPointerByPosition(int p, K *key){
			PMapLog(ame_Log_StartMethod, "setKeyPointerByPosition", "println", "");
			if(size < p){
				PMapLog(ame_Log_EndMethod, "setKeyPointerByPosition", "println", "");
				return;
			}
			keys[p] = key;
			PMapLog(ame_Log_EndMethod, "setKeyPointerByPosition", "println", "");
		}
		
		virtual void setValueByPosition(int p, P value){
			PMapLog(ame_Log_StartMethod, "setValueByPosition", "println", "");
			if(size < p){
				PMapLog(ame_Log_EndMethod, "setValueByPosition", "println", "");
				return;
			}
			*values[p] = value;
			PMapLog(ame_Log_EndMethod, "setValueByPosition", "println", "");
		}
		
		virtual void setValuePointerByPosition(int p, P *value){
			PMapLog(ame_Log_StartMethod, "setValuePointerByPosition", "println", "");
			if(size < p){
				PMapLog(ame_Log_EndMethod, "setValuePointerByPosition", "println", "");
				return;
			}
			values[p] = value;
			PMapLog(ame_Log_EndMethod, "setValuePointerByPosition", "println", "");
		}
		
		virtual void set(K key, P value){
			PMapLog(ame_Log_StartMethod, "set", "println", "");
			if(size < pos){
				PMapLog(ame_Log_EndMethod, "set", "println", "");
				return;
			}
			for(int x=0; x < pos; x++){
				if(*keys[x] == key ){
					*values[x] = value;
				}
			}
			PMapLog(ame_Log_EndMethod, "set", "println", "");
		}
		
		virtual bool containKeyByPointer(K *key){
			PMapLog(ame_Log_StartMethod, "containKeyByPointer", "println", "");
			for(int x=0; x < pos; x++){
				if(keys[x] == key ){
					PMapLog(ame_Log_EndMethod, "containKeyByPointer", "println", "");
					return true;
				}
			}
			PMapLog(ame_Log_EndMethod, "containKeyByPointer", "println", "");
			return false;
		}
		
		virtual bool containKeyByLValue(K key){
			PMapLog(ame_Log_StartMethod, "containKeyByLValue", "println", "");
			for(int x=0; x < pos; x++){
				if(*keys[x] == key ){
					PMapLog(ame_Log_EndMethod, "containKeyByLValue", "println", "");
					return true;
				}
			}
			PMapLog(ame_Log_EndMethod, "containKeyByLValue", "println", "");
			return false;
		}
		
		virtual bool containValueByPointer(P *value){
			PMapLog(ame_Log_StartMethod, "containValueByPointer", "println", "");
			for(int x=0; x < pos; x++){
				if(values[x] == value ){
					PMapLog(ame_Log_EndMethod, "containValueByPointer", "println", "");
					return true;
				}
			}
			PMapLog(ame_Log_EndMethod, "containValueByPointer", "println", "");
			return false;
		}
		
		virtual bool containValueByLValue(P value){
			PMapLog(ame_Log_StartMethod, "containValueByLValue", "println", "");
			for(int x=0; x < pos; x++){
				if(*values[x] == value ){
					PMapLog(ame_Log_EndMethod, "containValueByLValue", "println", "");
					return true;
				}
			}
			PMapLog(ame_Log_EndMethod, "containValueByLValue", "println", "");
			return false;
		}
		
		virtual P *getByPointer(K *key){
			PMapLog(ame_Log_StartMethod, "getByPointer", "println", "");
			for(int x=0; x < pos; x++){
				if(keys[x] == key ){
					PMapLog(ame_Log_EndMethod, "getByPointer", "println", "");
					return values[x];
				}
			}
			PMapLog(ame_Log_EndMethod, "getByPointer", "println", "");
			return nullptr;
		}
		
		virtual P *getByLValue(K key){
			PMapLog(ame_Log_StartMethod, "getByLValue", "println", "");
			for(int x=0; x < pos; x++){
				if(*keys[x] == key ){
					PMapLog(ame_Log_EndMethod, "getByLValue", "println", "");
					return values[x];
				}
			}
			PMapLog(ame_Log_EndMethod, "getByLValue", "println", "");
			return nullptr;
		}
		
		virtual P *getByPosition(int p) const{
			PMapLog(ame_Log_StartMethod, "getByPosition", "println", "");
			for(int x=0; x < pos; x++){
				if(x == p){
					PMapLog(ame_Log_EndMethod, "getByPosition", "println", "");
					return values[x];
				}
			}
			PMapLog(ame_Log_EndMethod, "getByPosition", "println", "");
			return nullptr;
		}
		
		virtual K *getKeyByPosition(int p) const{
			PMapLog(ame_Log_StartMethod, "getKeyByPosition", "println", "");
			for(int x=0; x < pos; x++){
				if(x == p ){
					PMapLog(ame_Log_EndMethod, "getKeyByPosition", "println", "");
					return keys[x];
				}
			}
			PMapLog(ame_Log_EndMethod, "getKeyByPosition", "println", "");
			return nullptr;
		}
		
		virtual K *getKeyByPointer(P *value){
			PMapLog(ame_Log_StartMethod, "getKeyByPointer", "println", "");
			for(int x=0; x < pos; x++){
				if(values[x] == value ){
					PMapLog(ame_Log_EndMethod, "getKeyByPointer", "println", "");
					return keys[x];
				}
			}
			PMapLog(ame_Log_EndMethod, "getKeyByPointer", "println", "");
			return nullptr;
		}
		
		virtual K *getKeyByLValue(P value){
			PMapLog(ame_Log_StartMethod, "getKeyByLValue", "println", "");
			for(int x=0; x < pos; x++){
				if(*values[x] == value ){
					PMapLog(ame_Log_EndMethod, "getKeyByLValue", "println", "");
					return keys[x];
				}
			}
			PMapLog(ame_Log_EndMethod, "getKeyByLValue", "println", "");
			return nullptr;
		}
		
		virtual P get(K key){
			PMapLog(ame_Log_StartMethod, "get", "println", "");
			for(int x=0; x < pos; x++){
				if(*keys[x] == key ){
					if(values[x] == nullptr){
						PMapLog(ame_Log_EndMethod, "get", "println", "");
						return P();
					}
					PMapLog(ame_Log_EndMethod, "get", "println", "");
					return *values[x];
				}
			}
			PMapLog(ame_Log_EndMethod, "get", "println", "");
			return P();
		}
		
		virtual K getKey(int p){
			PMapLog(ame_Log_StartMethod, "getKey", "println", "");
			K key;
			for(int x=0; x < pos; x++){
				if(x == p ){
					if(keys[x] == nullptr){
						PMapLog(ame_Log_EndMethod, "getKey", "println", "");
						return key;
					}
					key = *keys[x];
					PMapLog(ame_Log_EndMethod, "getKey", "println", "");
					return key;
				}
			}
			PMapLog(ame_Log_EndMethod, "getKey", "println", "");
			return key;
		}
		
		virtual P getValue(int p){
			PMapLog(ame_Log_StartMethod, "getValue", "println", "");
			for(int x=0; x < pos; x++){
				if(x == p ){
					if(values[x] == nullptr){
						PMapLog(ame_Log_EndMethod, "getValue", "println", "");
						return P();
					}
					PMapLog(ame_Log_EndMethod, "getValue", "println", "");
					return *values[x];
				}
			}
			PMapLog(ame_Log_EndMethod, "getValue", "println", "");
			return P();
		}
		
		virtual void reset(){
			PMapLog(ame_Log_StartMethod, "reset", "println", "");
			pos=0;
			PMapLog(ame_Log_EndMethod, "reset", "println", "");
		}
		
		virtual void resetDelete(){
			PMapLog(ame_Log_StartMethod, "resetDelete", "println", "");
			if(owner){
				for(int x=0; x < pos; x++){
					delete keys[x];
					delete values[x];
				}
			}
			pos=0;
			PMapLog(ame_Log_EndMethod, "resetDelete", "println", "");
		}
		
		virtual void resetDeleteKey(){
			PMapLog(ame_Log_StartMethod, "resetDeleteKey", "println", "");
			if(owner){
				for(int x=0; x < pos; x++){
					delete keys[x];
				}
			}
			pos=0;
			PMapLog(ame_Log_EndMethod, "resetDeleteKey", "println", "");
		}
		
		virtual void resetDeleteValue(){
			PMapLog(ame_Log_StartMethod, "resetDeleteValue", "println", "");
			if(owner){
				for(int x=0; x < pos; x++){
					delete values[x];
				}
			}
			pos=0;
			PMapLog(ame_Log_EndMethod, "resetDeleteValue", "println", "");
		}
		
		virtual P *removeByPointer(K *key){
			PMapLog(ame_Log_StartMethod, "removeByPointer", "println", "");
			P *p = nullptr;
			int nv =0;
			for(int x=0; x < pos; x++){
				if(keys[x] != key ){
					keys[nv] = keys[x];
					values[nv] = values[x];
					nv++;
				}else{
					p = values[x];
				}
			}
			pos = nv;
			PMapLog(ame_Log_EndMethod, "removeByPointer", "println", "");
			return p;
		}
		
		virtual P *removeByLValue(K key){
			PMapLog(ame_Log_StartMethod, "removeByLValue", "println", "");
			P *p = nullptr;
			int nv =0;
			for(int x=0; x < pos; x++){
				if(*keys[x] == key ){
					p = values[x];
				}else{
					keys[nv] = keys[x];
					values[nv] = values[x];
					nv++;
				}
			}
			pos = nv;
			PMapLog(ame_Log_EndMethod, "removeByLValue", "println", "");
			return p;
		}
		
		virtual P *removeByPosition(int ps){
			PMapLog(ame_Log_StartMethod, "removeByPosition", "println", "");
			P *p = nullptr;
			int nv =0;
			for(int x=0; x < pos; x++){
				if(x == ps ){
					p = values[x];
				}else{
					keys[nv] = keys[x];
					values[nv] = values[x];
					nv++;
				}
			}
			pos = nv;
			PMapLog(ame_Log_EndMethod, "removeByPosition", "println", "");
			return p;
		}
		
		virtual void removeDeleteByPointer(K *key){
			PMapLog(ame_Log_StartMethod, "removeDeleteByPointer", "println", "");
			int nv =0;
			for(int x=0; x < pos; x++){
				if(keys[x] == key ){
					if(keys[x] != nullptr){
						delete keys[x];
					}
					if(values[x] != nullptr){
						delete values[x];
					}
				}else{
					keys[nv] = keys[x];
					values[nv] = values[x];
					nv++;
				}
			}
			pos = nv;
			PMapLog(ame_Log_EndMethod, "removeDeleteByPointer", "println", "");
		}
		
		virtual void removeDeleteByLValue(K key){
			PMapLog(ame_Log_StartMethod, "removeDeleteByLValue", "println", "");
			int nv =0;
			for(int x=0; x < pos; x++){
				if(*keys[x] == key ){
					if(keys[x] != nullptr){
						delete keys[x];
					}
					if(values[x] != nullptr){
						delete values[x];
					}
				}else{
					keys[nv] = keys[x];
					values[nv] = values[x];
					nv++;
				}
			}
			pos = nv;
			PMapLog(ame_Log_EndMethod, "removeDeleteByLValue", "println", "");
		}
		
		virtual void removeDeleteByPosition(int ps){
			PMapLog(ame_Log_StartMethod, "removeDeleteByPosition", "println", "");
			int nv =0;
			for(int x=0; x < pos; x++){
				if(x == ps){
					if(keys[x] != nullptr){
						delete keys[x];
					}
					if(values[x] != nullptr){
						delete values[x];
					}
				}else{
					keys[nv] = keys[x];
					values[nv] = values[x];
					nv++;
				}
			}
			pos = nv;
			PMapLog(ame_Log_EndMethod, "removeDeleteByPosition", "println", "");
		}
		
		virtual P remove(K key){
			PMapLog(ame_Log_StartMethod, "remove", "println", "");
			int nv =0;
			P v;
			for(int x=0; x < pos; x++){
				if(*keys[x] == key ){
					if(values[x] != nullptr){
						v = *values[x];
					}
					if(!owner){
						continue;
					}
					delete keys[x];
					if(values[x] != nullptr){
						delete values[x];
					}
				}else{
					keys[nv] = keys[x];
					values[nv] = values[x];
					nv++;
				}
			}
			pos = nv;
			PMapLog(ame_Log_EndMethod, "remove", "println", "");
			return v;
		}
		
		virtual P removeIndex(int ps){
			PMapLog(ame_Log_StartMethod, "removeIndex", "println", "");
			int nv =0;
			P v;
			for(int x=0; x < pos; x++){
				if(x == ps){
					if(values[x] != nullptr){
						v = *values[x];
					}
					if(!owner){
						continue;
					}
					delete keys[x];
					if(values[x] != nullptr){
						delete values[x];
					}
				}else{
					keys[nv] = keys[x];
					values[nv] = values[x];
					nv++;
				}
			}
			pos = nv;
			PMapLog(ame_Log_EndMethod, "removeIndex", "println", "");
			return v;
		}
		
		virtual void putPointers(K* key, P* value){
			PMapLog(ame_Log_StartMethod, "putPointers", "println", "");
			if(key == nullptr){
				PMapLog(ame_Log_EndMethod, "putPointers", "println", "");
				return;
			}
			for(int x=0; x < pos; x++){
				if(key == keys[x]){
					if(values[x] != value){
						if(owner && values[x] != nullptr){
							delete values[x];
						}
						values[x] = value;
					}
					PMapLog(ame_Log_EndMethod, "putPointers", "println", "");
					return;
				}
			}
			if(size < pos){
				PMapLog(ame_Log_EndMethod, "putPointers", "println", "");
				return;
			}
			keys[pos] = key;
			values[pos] = value;
			pos++;
			PMapLog(ame_Log_EndMethod, "putPointers", "println", "");
		}
		
		virtual void putLValues(K key, P value){
			PMapLog(ame_Log_StartMethod, "putLValues", "println", "");
			for(int x=0; x < pos; x++){
				if(key == *keys[x]){
					if(values[x] == nullptr){
						values[x] = new P();
					}
					*values[x] = value;
					PMapLog(ame_Log_EndMethod, "putLValues", "println", "");
					return;
				}
			}
			if(size < pos){
				PMapLog(ame_Log_EndMethod, "putLValues", "println", "");
				return;
			}
			keys[pos] = new K();
			values[pos] = new P();
			*keys[pos] = key;
			*values[pos] = value;
			pos++;
			PMapLog(ame_Log_EndMethod, "putLValues", "println", "");
		}
		
		virtual void putPointer(K key, P* value){
			PMapLog(ame_Log_StartMethod, "putPointer", "println", "");
			for(int x=0; x < pos; x++){
				if(key == *keys[x]){
					if(values[x] != value){
						if(owner && values[x] != nullptr){
							delete values[x];
						}
						values[x] = value;
					}
					PMapLog(ame_Log_EndMethod, "putPointer", "println", "");
					return;
				}
			}
			if(size < pos){
				PMapLog(ame_Log_EndMethod, "putPointer", "println", "");
				return;
			}
			keys[pos] = new K();
			*keys[pos] = key;
			values[pos] = value;
			pos++;
			PMapLog(ame_Log_EndMethod, "putPointer", "println", "");
		}
		
		virtual void put(K key, P value){
			PMapLog(ame_Log_StartMethod, "put", "println", "");
			for(int x=0; x < pos; x++){
				if(key == *keys[x]){
					if(values[x] == nullptr){
						values[x] = new P();
					}
					*values[x] = value;
					PMapLog(ame_Log_EndMethod, "put", "println", "");
					return;
				}
			}
			if(size < pos){
				PMapLog(ame_Log_EndMethod, "put", "println", "");
				return;
			}
			keys[pos] = new K();
			values[pos] = new P();
			*keys[pos] = key;
			*values[pos] = value;
			pos++;
			PMapLog(ame_Log_EndMethod, "put", "println", "");
		}
		
		virtual int getKeyIndexByPointer(K* key){
			PMapLog(ame_Log_StartMethod, "getKeyIndexByPointer", "println", "");
			for(int x=0; x < pos; x++){
				if(key == keys[x]){
					PMapLog(ame_Log_EndMethod, "getKeyIndexByPointer", "println", "");
					return x;
				}
			}
			PMapLog(ame_Log_EndMethod, "getKeyIndexByPointer", "println", "");
			return -1;
		}
		
		virtual int getKeyIndexByLValue(K key){
			PMapLog(ame_Log_StartMethod, "getKeyIndexByLValue", "println", "");
			for(int x=0; x < pos; x++){
				if(key == *keys[x]){
					PMapLog(ame_Log_EndMethod, "getKeyIndexByLValue", "println", "");
					return x;
				}
			}
			PMapLog(ame_Log_EndMethod, "getKeyIndexByLValue", "println", "");
			return -1;
		}
		
		virtual int getIndexByPointer(P* v){
			PMapLog(ame_Log_StartMethod, "getIndexByPointer", "println", "");
			for(int x=0; x < pos; x++){
				if(v == values[x]){
					PMapLog(ame_Log_EndMethod, "getIndexByPointer", "println", "");
					return x;
				}
			}
			PMapLog(ame_Log_EndMethod, "getIndexByPointer", "println", "");
			return -1;
		}
		
		virtual int getIndexByLValue(P v){
			PMapLog(ame_Log_StartMethod, "getIndexByLValue", "println", "");
			for(int x=0; x < pos; x++){
				if(values[x] == nullptr){
					continue;
				}
				if(v == *values[x]){
					PMapLog(ame_Log_EndMethod, "getIndexByLValue", "println", "");
					return x;
				}
			}
			PMapLog(ame_Log_EndMethod, "getIndexByLValue", "println", "");
			return -1;
		}
		
		virtual void onDelete(){
			PMapLog(ame_Log_StartMethod, "onDelete", "println", "");
			if(owner){
				for(int x=0; x < pos; x++){
					delete keys[x];
					delete values[x];
				}
			}
			PMapLog(ame_Log_EndMethod, "onDelete", "println", "");
		}
		
		virtual cppObjectClass* getClass(){
			PMapLog(ame_Log_StartMethod, "getClass", "println", "");
			PMapLog(ame_Log_EndMethod, "getClass", "println", "");
			return Class<PMap>::getClass();
		}
		
		virtual Map<K,P>* clone(){
			PMapLog(ame_Log_StartMethod, "clone", "println", "");
			Map<K,P>* cloneMap = new PMap<K,P,size>(true);
			for(int cm = 0; cm < pos; cm++){
				cloneMap->addLValues(*keys[cm], *values[cm]);
			}
			PMapLog(ame_Log_EndMethod, "clone", "println", "");
			return cloneMap;
		}
		
		virtual Map<K,P>* clone(bool owningMemory){
			PMapLog(ame_Log_StartMethod, "clone", "println", "");
			Map<K,P>* cloneMap = new PMap<K,P,size>(owningMemory);
			for(int cm = 0; cm < pos; cm++){
				cloneMap->addLValues(*keys[cm], *values[cm]);
			}
			PMapLog(ame_Log_EndMethod, "clone", "println", "");
			return cloneMap;
		}
		
        virtual PMap<K,P,size>& operator =(const PMap<K,P,size>& m_map){
			PMapLog(ame_Log_StartMethod, "operator =", "println", "");
			resetDelete();
			owner = m_map.owner;
			for(int x = 0; x < m_map.getPosition(); x++){
				K k = *m_map.getKeyByPosition(x);
				P v = *m_map.getByPosition(x);
				this->addLValues(k,v);
			}
			PMapLog(ame_Log_EndMethod, "operator =", "println", "");
			return *this;
		}
		
        virtual bool operator ==(const PMap<K,P,size>& m_map){
			PMapLog(ame_Log_StartMethod, "operator ==", "println", "");
			for(int x = 0; x < pos; x++){
				K k = *m_map.keys[x];
				P v = *m_map.values[x];
				if(*keys[x] != k || *values[x] != v){
					PMapLog(ame_Log_EndMethod, "operator ==", "println", "");
					return false;
				}
			}
			PMapLog(ame_Log_EndMethod, "operator ==", "println", "");
			return true;
		}
		
        virtual bool operator !=(const PMap<K,P,size>& m_map){
			PMapLog(ame_Log_StartMethod, "operator !=", "println", "");
			for(int x = 0; x < pos; x++){
				K k = *m_map.keys[x];
				P v = *m_map.values[x];
				if(*keys[x] == k || *values[x] == v){
					PMapLog(ame_Log_EndMethod, "operator !=", "println", "");
					return false;
				}
			}
			PMapLog(ame_Log_EndMethod, "operator !=", "println", "");
			return true;
		}
		
	protected:
		int pos;
		bool owner = false;
		
		P* values[size];
		K* keys[size];
};

}

#endif