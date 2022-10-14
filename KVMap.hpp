
#ifndef KVMap_h
#define KVMap_h
#define KVMap_AVAILABLE 

#include "Map.hpp"
#include "Class.hpp"

#ifdef KVMap_LogApp
	#include "ame_Logger_config.hpp"
	#include "ame_Logger.hpp"

	#define KVMapLog(location,method,type,mns) ame_Log((void*)this,location,"KVMap",method,type,mns)
	#define const_KVMapLog(location,method,type,mns)
#else
	#ifdef KVMap_LogDebugApp
		#include "ame_Logger_config.hpp"
		#include "ame_Logger.hpp"

		#define KVMapLog(location,method,type,mns) ame_LogDebug((void*)this,location,"KVMap",method,type)
		#define const_KVMapLog(location,method,type,mns)
	#else
		#define KVMapLog(location,method,type,mns)
		#define const_KVMapLog(location,method,type,mns)
	#endif
#endif

namespace ame{

template <class K,class P,int size>
class KVMap : public Map<K,P>{
	
    public:
		int pos=0;
		P values[size];
		K keys[size];
		
		KVMap(){
			KVMapLog(ame_Log_StartMethod, "Constructor", "println", "");
			KVMapLog(ame_Log_EndMethod, "Constructor", "println", "");
		}
		
		KVMap(const KVMap& c_map){
			KVMapLog(ame_Log_StartMethod, "Constructor", "println", "");
			for(int x = 0; x < c_map.getPosition(); x++){
				K k = *c_map.getKeyByPosition(x);
				P v = *c_map.getByPosition(x);
				this->addLValues(k,v);
			}
			KVMapLog(ame_Log_EndMethod, "Constructor", "println", "");
		}
		
		virtual ~KVMap(){
			KVMapLog(ame_Log_StartMethod, "Destructor", "println", "");
			KVMapLog(ame_Log_EndMethod, "Destructor", "println", "");
		}
		
		virtual void addPointers(K *key, P *value){
			KVMapLog(ame_Log_StartMethod, "addPointers", "println", "");
			if(size < this->pos){
				KVMapLog(ame_Log_EndMethod, "addPointers", "println", "");
				return;
			}
			this->keys[pos] = *key;
			this->values[pos] = *value;
			this->pos++;
			delete key;
			delete value;
			KVMapLog(ame_Log_EndMethod, "addPointers", "println", "");
		}
		
		virtual void addLValues(K key, P value){
			KVMapLog(ame_Log_StartMethod, "addLValues", "println", "");
			if(size < this->pos){
				KVMapLog(ame_Log_EndMethod, "addLValues", "println", "");
				return;
			}
			this->keys[pos] = key;
			this->values[pos] = value;
			this->pos++;
			KVMapLog(ame_Log_EndMethod, "addLValues", "println", "");
		}
		
		virtual void addPointer(K key, P *value){
			KVMapLog(ame_Log_StartMethod, "addPointer", "println", "");
			if(size < this->pos){
				KVMapLog(ame_Log_EndMethod, "addPointer", "println", "");
				return;
			}
			this->keys[pos] = key;
			this->values[pos] = *value;
			this->pos++;
			delete value;
			KVMapLog(ame_Log_EndMethod, "addPointer", "println", "");
		}
		
		virtual void add(K key, P value){
			KVMapLog(ame_Log_StartMethod, "add", "println", "");
			if(size < pos){
				KVMapLog(ame_Log_EndMethod, "add", "println", "");
				return;
			}
			keys[pos] = key;
			values[pos] = value;
			pos++;
			KVMapLog(ame_Log_EndMethod, "add", "println", "");
		}
		
		virtual void addCopy(RawMap<K,P>* r_map){
			KVMapLog(ame_Log_StartMethod, "addCopy", "println", "");
			for(int x = 0; x < r_map->getPosition(); x++){
				K* k = this->getKeyByPosition(x);
				P* v = this->getByPosition(x);
				this->addLValues(*k, *v);
			}
			KVMapLog(ame_Log_EndMethod, "addCopy", "println", "");
		}
		
		virtual void addMove(RawMap<K,P>* r_map){
			KVMapLog(ame_Log_StartMethod, "addMove", "println", "");
			for(int x = 0; x < r_map->getPosition(); x++){
				K* k = this->getKeyByPosition(x);
				P* v = this->getByPosition(x);
				if(this->isOwner()){
					this->addLValues(*k, *v);
				}else{
					this->addLValues(*k, *v);
				}
			}
			KVMapLog(ame_Log_EndMethod, "addMove", "println", "");
		}
		
		virtual void setPointers(K *key, P *value){
			KVMapLog(ame_Log_StartMethod, "setPointers", "println", "");
			if(size < this->pos){
				KVMapLog(ame_Log_EndMethod, "setPointers", "println", "");
				return;
			}
			for(int x=0; x < pos; x++){
				if(this->keys[x] == *key ){
					this->values[x] = *value;
				}
			}
			KVMapLog(ame_Log_EndMethod, "setPointers", "println", "");
		}
		
		virtual void setLValues(K key, P value){
			KVMapLog(ame_Log_StartMethod, "setLValues", "println", "");
			if(size < this->pos){
				KVMapLog(ame_Log_EndMethod, "setLValues", "println", "");
				return;
			}
			for(int x=0; x < this->pos; x++){
				if(this->keys[x] == key ){
					this->values[x] = value;
				}
			}
			KVMapLog(ame_Log_EndMethod, "setLValues", "println", "");
		}
		
		virtual void setPointer(K key, P *value){
			KVMapLog(ame_Log_StartMethod, "setPointer", "println", "");
			if(size < pos){
				KVMapLog(ame_Log_EndMethod, "setPointer", "println", "");
				return;
			}
			for(int x=0; x < pos; x++){
				if(this->keys[x] == key ){
					this->values[x] = *value;
				}
			}
			KVMapLog(ame_Log_EndMethod, "setPointer", "println", "");
		}
		
		virtual void setKeyLValueByPosition(int p, K key){
			KVMapLog(ame_Log_StartMethod, "setKeyLValueByPosition", "println", "");
			if(size < p){
				KVMapLog(ame_Log_EndMethod, "setKeyLValueByPosition", "println", "");
				return;
			}
			keys[p] = key;
			KVMapLog(ame_Log_EndMethod, "setKeyLValueByPosition", "println", "");
		}
		
		virtual void setKeyPointerByPosition(int p, K *key){
			KVMapLog(ame_Log_StartMethod, "setKeyPointerByPosition", "println", "");
			if(size < p){
				KVMapLog(ame_Log_EndMethod, "setKeyPointerByPosition", "println", "");
				return;
			}
			keys[p] = *key;
			KVMapLog(ame_Log_EndMethod, "setKeyPointerByPosition", "println", "");
		}
		
		virtual void setValueByPosition(int p, P value){
			KVMapLog(ame_Log_StartMethod, "setValueByPosition", "println", "");
			if(size < p){
				KVMapLog(ame_Log_EndMethod, "setValueByPosition", "println", "");
				return;
			}
			values[p] = value;
			KVMapLog(ame_Log_EndMethod, "setValueByPosition", "println", "");
		}
		
		virtual void setValuePointerByPosition(int p, P *value){
			KVMapLog(ame_Log_StartMethod, "setValuePointerByPosition", "println", "");
			if(size < p){
				KVMapLog(ame_Log_EndMethod, "setValuePointerByPosition", "println", "");
				return;
			}
			values[p] = *value;
			KVMapLog(ame_Log_EndMethod, "setValuePointerByPosition", "println", "");
		}
		
		virtual void set(K key, P value){
			KVMapLog(ame_Log_StartMethod, "set", "println", "");
			if(size < pos){
				KVMapLog(ame_Log_EndMethod, "set", "println", "");
				return;
			}
			for(int x=0; x < pos; x++){
				if(keys[x] == key ){
					values[x] = value;
				}
			}
			KVMapLog(ame_Log_EndMethod, "set", "println", "");
		}
		
		virtual bool containKeyByPointer(K *key){
			KVMapLog(ame_Log_StartMethod, "containKeyByPointer", "println", "");
			for(int x=0; x < this->pos; x++){
				if(this->keys[x] == *key ){
					KVMapLog(ame_Log_EndMethod, "containKeyByPointer", "println", "");
					return true;
				}
			}
			KVMapLog(ame_Log_EndMethod, "containKeyByPointer", "println", "");
			return false;
		}
		
		virtual bool containKeyByLValue(K key){
			KVMapLog(ame_Log_StartMethod, "containKeyByLValue", "println", "");
			for(int x=0; x < this->pos; x++){
				if(this->keys[x] == key ){
					KVMapLog(ame_Log_EndMethod, "containKeyByLValue", "println", "");
					return true;
				}
			}
			KVMapLog(ame_Log_EndMethod, "containKeyByLValue", "println", "");
			return false;
		}
		
		virtual bool containValueByPointer(P *value){
			KVMapLog(ame_Log_StartMethod, "containValueByPointer", "println", "");
			for(int x=0; x < this->pos; x++){
				if(this->values[x] == *value ){
					KVMapLog(ame_Log_EndMethod, "containValueByPointer", "println", "");
					return true;
				}
			}
			KVMapLog(ame_Log_EndMethod, "containValueByPointer", "println", "");
			return false;
		}
		
		virtual bool containValueByLValue(P value){
			KVMapLog(ame_Log_StartMethod, "containValueByLValue", "println", "");
			for(int x=0; x < this->pos; x++){
				if(this->values[x] == value ){
					KVMapLog(ame_Log_EndMethod, "containValueByLValue", "println", "");
					return true;
				}
			}
			KVMapLog(ame_Log_EndMethod, "containValueByLValue", "println", "");
			return false;
		}
		
		virtual P *getByPointer(K *key){
			KVMapLog(ame_Log_StartMethod, "getByPointer", "println", "");
			for(int x=0; x < this->pos; x++){
				if(this->keys[x] == *key ){
					KVMapLog(ame_Log_EndMethod, "getByPointer", "println", "");
					return &this->values[x];
				}
			}
			KVMapLog(ame_Log_EndMethod, "getByPointer", "println", "");
			return nullptr;
		}
		
		virtual P *getByLValue(K key){
			KVMapLog(ame_Log_StartMethod, "getByLValue", "println", "");
			for(int x=0; x < this->pos; x++){
				if(this->keys[x] == key ){
					KVMapLog(ame_Log_EndMethod, "getByLValue", "println", "");
					return &this->values[x];
				}
			}
			KVMapLog(ame_Log_EndMethod, "getByLValue", "println", "");
			return nullptr;
		}
		
		virtual P *getByPosition(int p) const{
			KVMapLog(ame_Log_StartMethod, "getByPosition", "println", "");
			for(int x=0; x < this->pos; x++){
				if(x == p){
					KVMapLog(ame_Log_EndMethod, "getByPosition", "println", "");
					return (P*)&this->values[x];
				}
			}
			KVMapLog(ame_Log_EndMethod, "getByPosition", "println", "");
			return nullptr;
		}
		
		virtual K *getKeyByPosition(int p) const{
			KVMapLog(ame_Log_StartMethod, "getKeyByPosition", "println", "");
			for(int x=0; x < this->pos; x++){
				if(x == p ){
					KVMapLog(ame_Log_EndMethod, "getKeyByPosition", "println", "");
					return (K*)&this->keys[x];
				}
			}
			KVMapLog(ame_Log_EndMethod, "getKeyByPosition", "println", "");
			return nullptr;
		}
		
		virtual K *getKeyByPointer(P *value){
			KVMapLog(ame_Log_StartMethod, "getKeyByPointer", "println", "");
			for(int x=0; x < this->pos; x++){
				if(this->values[x] == *value ){
					KVMapLog(ame_Log_EndMethod, "getKeyByPointer", "println", "");
					return &this->keys[x];
				}
			}
			KVMapLog(ame_Log_EndMethod, "getKeyByPointer", "println", "");
			return nullptr;
		}
	
		virtual K *getKeyByLValue(P value){
			KVMapLog(ame_Log_StartMethod, "getKeyByLValue", "println", "");
			for(int x=0; x < this->pos; x++){
				if(this->values[x] == value ){
					KVMapLog(ame_Log_EndMethod, "getKeyByLValue", "println", "");
					return &this->keys[x];
				}
			}
			KVMapLog(ame_Log_EndMethod, "getKeyByLValue", "println", "");
			return nullptr;
		}
		
		virtual P get(K key){
			KVMapLog(ame_Log_StartMethod, "get", "println", "");
			for(int x=0; x < pos; x++){
				if(keys[x] == key ){
					KVMapLog(ame_Log_EndMethod, "get", "println", "");
					return values[x];
				}
			}
			KVMapLog(ame_Log_EndMethod, "get", "println", "");
			return P();
		}
		
		virtual K getKey(int p){
			KVMapLog(ame_Log_StartMethod, "getKey", "println", "");
			for(int x=0; x < pos; x++){
				if(x == p ){
					KVMapLog(ame_Log_EndMethod, "getKey", "println", "");
					return keys[x];
				}
			}
			KVMapLog(ame_Log_EndMethod, "getKey", "println", "");
			return K();
		}
		
		virtual P getValue(int p){
			KVMapLog(ame_Log_StartMethod, "getValue", "println", "");
			for(int x=0; x < pos; x++){
				if(x == p ){
					KVMapLog(ame_Log_EndMethod, "getValue", "println", "");
					return values[x];
				}
			}
			KVMapLog(ame_Log_EndMethod, "getValue", "println", "");
			return P();
		}
		
		virtual void reset(){
			KVMapLog(ame_Log_StartMethod, "reset", "println", "");
			this->pos=0;
			KVMapLog(ame_Log_EndMethod, "reset", "println", "");
		}
		
		virtual void resetDelete(){
			KVMapLog(ame_Log_StartMethod, "resetDelete", "println", "");
			this->pos=0;
			KVMapLog(ame_Log_EndMethod, "resetDelete", "println", "");
		}
		
		virtual void resetDeleteKey(){
			KVMapLog(ame_Log_StartMethod, "resetDeleteKey", "println", "");
			this->pos=0;
			KVMapLog(ame_Log_EndMethod, "resetDeleteKey", "println", "");
		}
		
		virtual void resetDeleteValue(){
			KVMapLog(ame_Log_StartMethod, "resetDeleteValue", "println", "");
			this->pos=0;
			KVMapLog(ame_Log_EndMethod, "resetDeleteValue", "println", "");
		}
		
		virtual P *removeByPointer(K *key){
			KVMapLog(ame_Log_StartMethod, "removeByPointer", "println", "");
			P *p =nullptr;
			bool is=false;
			for(int x=0; x < this->pos; x++){
				if(this->keys[x] == *key ){
					is = true;
				}
			}
			if(is){
				int nv =0;
				for(int x=0; x < this->pos; x++){
					if(this->keys[x] != *key ){
						this->keys[nv] = keys[x];
						this->values[nv] = values[x];
						nv++;
					}else{
						p=&this->values[x];
					}
				}
				this->pos = nv;
			}
			KVMapLog(ame_Log_EndMethod, "removeByPointer", "println", "");
			return p;
		}
		
		virtual P *removeByLValue(K key){
			KVMapLog(ame_Log_StartMethod, "removeByLValue", "println", "");
			P *p =nullptr;
			bool is=false;
			for(int x=0; x < this->pos; x++){
				if(this->keys[x] == key ){
					is = true;
				}
			}
			if(is){
				int nv =0;
				for(int x=0; x < this->pos; x++){
					if(this->keys[x] != key ){
						this->keys[nv] = keys[x];
						this->values[nv] = values[x];
						nv++;
					}else{
						p=&this->values[x];
					}
				}
				this->pos = nv;
			}
			KVMapLog(ame_Log_EndMethod, "removeByLValue", "println", "");
			return p;
		}
		
		virtual P *removeByPosition(int ps){
			KVMapLog(ame_Log_StartMethod, "removeByPosition", "println", "");
			P *p = nullptr;
			bool is=false;
			for(int x=0; x < this->pos; x++){
				if(x == ps ){
					is = true;
				}
			}
			if(is){
				int nv =0;
				for(int x=0; x < this->pos; x++){
					if(x != ps ){
						this->keys[nv] = keys[x];
						this->values[nv] = values[x];
						nv++;
					}else{
						p=&this->values[x];
					}
				}
				this->pos = nv;
			}
			KVMapLog(ame_Log_EndMethod, "removeByPosition", "println", "");
			return p;
		}
		
		virtual void removeDeleteByPointer(K *key){
			KVMapLog(ame_Log_StartMethod, "removeDeleteByPointer", "println", "");
			bool is=false;
			for(int x=0; x < this->pos; x++){
				if(this->keys[x] == *key ){
					is = true;
				}
			}
			if(is){
				int nv =0;
				for(int x=0; x < this->pos; x++){
					if(this->keys[x] != *key ){
						this->keys[nv] = keys[x];
						this->values[nv] = values[x];
						nv++;
					}
				}
				this->pos = nv;
			}
			KVMapLog(ame_Log_EndMethod, "removeDeleteByPointer", "println", "");
		}
		
		virtual void removeDeleteByLValue(K key){
			KVMapLog(ame_Log_StartMethod, "removeDeleteByLValue", "println", "");
			bool is=false;
			for(int x=0; x < this->pos; x++){
				if(this->keys[x] == key ){
					is = true;
				}
			}
			if(is){
				int nv =0;
				for(int x=0; x < this->pos; x++){
					if(this->keys[x] != key ){
						this->keys[nv] = keys[x];
						this->values[nv] = values[x];
						nv++;
					}
				}
				this->pos = nv;
			}
			KVMapLog(ame_Log_EndMethod, "removeDeleteByLValue", "println", "");
		}
		
		virtual void removeDeleteByPosition(int ps){
			KVMapLog(ame_Log_StartMethod, "removeDeleteByPosition", "println", "");
			bool is=false;
			for(int x=0; x < this->pos; x++){
				if(x == ps ){
					is = true;
				}
			}
			if(is){
				int nv =0;
				for(int x=0; x < this->pos; x++){
					if(x != ps ){
						this->keys[nv] = keys[x];
						this->values[nv] = values[x];
						nv++;
					}
				}
				this->pos = nv;
			}
			KVMapLog(ame_Log_EndMethod, "removeDeleteByPosition", "println", "");
		}
		
		virtual P remove(K key){
			KVMapLog(ame_Log_StartMethod, "remove", "println", "");
			int nv =0;
			P v;
			for(int x=0; x < pos; x++){
				if(keys[x] == key ){
					v = values[x];
				}else{
					keys[nv] = keys[x];
					values[nv] = values[x];
					nv++;
				}
			}
			pos = nv;
			KVMapLog(ame_Log_EndMethod, "remove", "println", "");
			return v;
		}
		
		virtual P removeIndex(int ps){
			KVMapLog(ame_Log_StartMethod, "removeIndex", "println", "");
			int nv =0;
			P v;
			for(int x=0; x < pos; x++){
				if(x == ps){
					v = values[x];
				}else{
					keys[nv] = keys[x];
					values[nv] = values[x];
					nv++;
				}
			}
			pos = nv;
			KVMapLog(ame_Log_EndMethod, "removeIndex", "println", "");
			return v;
		}
		
		virtual void putPointers(K* key, P* value){
			KVMapLog(ame_Log_StartMethod, "putPointers", "println", "");
			if(key == nullptr || value == nullptr){
				return;
			}
			for(int x=0; x < pos; x++){
				if(*key == keys[x]){
					values[x] = *value;
					return;
				}
			}
			if(size < pos){
				return;
			}
			keys[pos] = *key;
			values[pos] = *value;
			pos++;
			KVMapLog(ame_Log_EndMethod, "putPointers", "println", "");
		}
		
		virtual void putLValues(K key, P value){
			KVMapLog(ame_Log_StartMethod, "putLValues", "println", "");
			for(int x=0; x < pos; x++){
				if(key == keys[x]){
					values[x] = value;
					return;
				}
			}
			if(size < pos){
				KVMapLog(ame_Log_EndMethod, "putLValues", "println", "");
				return;
			}
			keys[pos] = key;
			values[pos] = value;
			pos++;
			KVMapLog(ame_Log_EndMethod, "putLValues", "println", "");
		}
		
		virtual void putPointer(K key, P* value){
			KVMapLog(ame_Log_StartMethod, "putPointer", "println", "");
			if(value == nullptr){
				KVMapLog(ame_Log_EndMethod, "putPointer", "println", "");
				return;
			}
			for(int x=0; x < pos; x++){
				if(key == keys[x]){
					values[x] = *value;
					KVMapLog(ame_Log_EndMethod, "putPointer", "println", "");
					return;
				}
			}
			if(size < pos){
				KVMapLog(ame_Log_EndMethod, "putPointer", "println", "");
				return;
			}
			keys[pos] = key;
			values[pos] = *value;
			pos++;
			KVMapLog(ame_Log_EndMethod, "putPointer", "println", "");
		}
		
		virtual void put(K key, P value){
			KVMapLog(ame_Log_StartMethod, "put", "println", "");
			for(int x=0; x < pos; x++){
				if(key == keys[x]){
					values[x] = value;
					KVMapLog(ame_Log_EndMethod, "put", "println", "");
					return;
				}
			}
			if(size < pos){
				KVMapLog(ame_Log_EndMethod, "put", "println", "");
				return;
			}
			keys[pos] = key;
			values[pos] = value;
			pos++;
			KVMapLog(ame_Log_EndMethod, "put", "println", "");
		}
		
		virtual int getKeyIndexByPointer(K* key){
			KVMapLog(ame_Log_StartMethod, "getKeyIndexByPointer", "println", "");
			for(int x=0; x < pos; x++){
				if(*key == keys[x]){
					KVMapLog(ame_Log_EndMethod, "getKeyIndexByPointer", "println", "");
					return x;
				}
			}
			KVMapLog(ame_Log_EndMethod, "getKeyIndexByPointer", "println", "");
			return -1;
		}
		
		virtual int getKeyIndexByLValue(K key){
			KVMapLog(ame_Log_StartMethod, "getKeyIndexByLValue", "println", "");
			for(int x=0; x < pos; x++){
				if(key == keys[x]){
					KVMapLog(ame_Log_EndMethod, "getKeyIndexByLValue", "println", "");
					return x;
				}
			}
			KVMapLog(ame_Log_EndMethod, "getKeyIndexByLValue", "println", "");
			return -1;
		}
		
		virtual int getIndexByPointer(P* v){
			KVMapLog(ame_Log_StartMethod, "getIndexByPointer", "println", "");
			if(v == nullptr){
				KVMapLog(ame_Log_EndMethod, "getIndexByPointer", "println", "");
				return -1;
			}
			for(int x=0; x < pos; x++){
				if(*v == values[x]){
					KVMapLog(ame_Log_EndMethod, "getIndexByPointer", "println", "");
					return x;
				}
			}
			KVMapLog(ame_Log_EndMethod, "getIndexByPointer", "println", "");
			return -1;
		}
		
		virtual int getIndexByLValue(P v){
			KVMapLog(ame_Log_StartMethod, "getIndexByLValue", "println", "");
			for(int x=0; x < pos; x++){
				if(v == values[x]){
					KVMapLog(ame_Log_EndMethod, "getIndexByLValue", "println", "");
					return x;
				}
			}
			KVMapLog(ame_Log_EndMethod, "getIndexByLValue", "println", "");
			return -1;
		}
		
		virtual void onDelete(){
			KVMapLog(ame_Log_StartMethod, "onDelete", "println", "");
			KVMapLog(ame_Log_EndMethod, "onDelete", "println", "");
		}
		
		virtual cppObjectClass* getClass(){
			KVMapLog(ame_Log_StartMethod, "getClass", "println", "");
			KVMapLog(ame_Log_EndMethod, "getClass", "println", "");
			return Class<KVMap>::classType;
		}
		
		virtual Map<K,P>* clone(void){
			KVMapLog(ame_Log_StartMethod, "clone", "println", "");
			Map<K,P>* cloneMap = new KVMap<K,P,size>();
			for(int cm = 0; cm < this->pos; cm++){
				cloneMap->addLValues(keys[cm], values[cm]);
			}
			KVMapLog(ame_Log_EndMethod, "clone", "println", "");
			return cloneMap;
		}
		
		virtual Map<K,P>* clone(bool owningMemory){
			KVMapLog(ame_Log_StartMethod, "clone", "println", "");
			Map<K,P>* cloneMap = new KVMap<K,P,size>();
			for(int cm = 0; cm < this->pos; cm++){
				cloneMap->addLValues(keys[cm], values[cm]);
			}
			KVMapLog(ame_Log_EndMethod, "clone", "println", "");
			return cloneMap;
		}
		
        virtual KVMap<K,P,size>& operator =(const KVMap<K,P,size>& m_map){
			KVMapLog(ame_Log_StartMethod, "operator =", "println", "");
			resetDelete();
			for(int x = 0; x < m_map.getPosition(); x++){
				K k = *m_map.getKeyByPosition(x);
				P v = *m_map.getByPosition(x);
				this->addLValues(k,v);
			}
			KVMapLog(ame_Log_EndMethod, "operator =", "println", "");
			return *this;
		}
		
        virtual bool operator ==(const KVMap<K,P,size>& m_map){
			KVMapLog(ame_Log_StartMethod, "operator ==", "println", "");
			for(int x = 0; x < pos; x++){
				K k = m_map.keys[x];
				P v = m_map.values[x];
				if(keys[x] != k || values[x] != v){
					KVMapLog(ame_Log_EndMethod, "operator ==", "println", "");
					return false;
				}
			}
			KVMapLog(ame_Log_EndMethod, "operator ==", "println", "");
			return true;
		}
		
        virtual bool operator !=(const KVMap<K,P,size>& m_map){
			KVMapLog(ame_Log_StartMethod, "operator !=", "println", "");
			for(int x = 0; x < pos; x++){
				K k = m_map.keys[x];
				P v = m_map.values[x];
				if(keys[x] == k || values[x] == v){
					KVMapLog(ame_Log_EndMethod, "operator !=", "println", "");
					return false;
				}
			}
			KVMapLog(ame_Log_EndMethod, "operator !=", "println", "");
			return true;
		}
		
	protected:
};

}

#endif