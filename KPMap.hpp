
#ifndef KPMap_hpp
#define KPMap_hpp
#define KPMap_AVAILABLE 

#include "Map.hpp"
#include "Class.hpp"

#ifdef KPMap_LogApp
	#include "ame_Logger_config.hpp"
	#include "ame_Logger.hpp"

	#define KPMapLog(location,method,type,mns) ame_Log((void*)this,location,"KPMap",method,type,mns)
	#define const_KPMapLog(location,method,type,mns)
#else
	#ifdef KPMap_LogDebugApp
		#include "ame_Logger_config.hpp"
		#include "ame_Logger.hpp"

		#define KPMapLog(location,method,type,mns) ame_LogDebug((void*)this,location,"KPMap",method,type)
		#define const_KPMapLog(location,method,type,mns)
	#else
		#define KPMapLog(location,method,type,mns)
		#define const_KPMapLog(location,method,type,mns)
	#endif
#endif

namespace ame{

template <class K,class P,int size = 20>
class KPMap : public Map<K,P>{
	
    public:
		bool owner = false;
		P *values[size];
		K keys[size];
		
		KPMap(){
			KPMapLog(ame_Log_StartMethod, "Constructor", "println", "");
			KPMapLog(ame_Log_EndMethod, "Constructor", "println", "");
		}
		
		KPMap(const KPMap& m_map){
			KPMapLog(ame_Log_StartMethod, "Constructor", "println", "");
			owner = m_map.owner;
			for(int x = 0; x < m_map.getPosition(); x++){
				K k = *m_map.getKeyByPosition(x);
				P v = *m_map.getByPosition(x);
				this->addLValues(k,v);
			}
			KPMapLog(ame_Log_EndMethod, "Constructor", "println", "");
		}
		
		KPMap(bool own){
			KPMapLog(ame_Log_StartMethod, "Constructor", "println", "");
			owner = own;
			pos=0;
			KPMapLog(ame_Log_EndMethod, "Constructor", "println", "");
		}
		
		virtual ~KPMap(){
			KPMapLog(ame_Log_StartMethod, "Destructor", "println", "");
			if(owner){
				for(int x=0; x < pos; x++){
					delete values[x];
				}
			}
			KPMapLog(ame_Log_EndMethod, "Destructor", "println", "");
		}
		
		virtual bool isEmpty()const{
			KPMapLog(ame_Log_StartMethod, "isEmpty", "println", "");
			KPMapLog(ame_Log_EndMethod, "isEmpty", "println", "");
			return this->pos==0;
		}
		
		virtual void addPointers(K *key, P *value){
			KPMapLog(ame_Log_StartMethod, "addPointers", "println", "");
			if(size < pos){
				KPMapLog(ame_Log_EndMethod, "addPointers", "println", "");
				return;
			}
			if(key == nullptr || value == nullptr){
				KPMapLog(ame_Log_EndMethod, "addPointers", "println", "");
				return;
			}
			keys[pos] = *key;
			values[pos] = value;
			pos++;
			delete key;
			KPMapLog(ame_Log_EndMethod, "addPointers", "println", "");
		}
		
		virtual void addLValues(K key, P value){
			KPMapLog(ame_Log_StartMethod, "addLValues", "println", "");
			if(size < pos){
				KPMapLog(ame_Log_EndMethod, "addLValues", "println", "");
				return;
			}
			keys[pos] = key;
			values[pos] = new P();
			*values[pos] = value;
			pos++;
			KPMapLog(ame_Log_EndMethod, "addLValues", "println", "");
		}
		
		virtual void addPointer(K key, P *value){
			KPMapLog(ame_Log_StartMethod, "addPointer", "println", "");
			if(size < pos){
				KPMapLog(ame_Log_EndMethod, "addPointer", "println", "");
				return;
			}
			keys[pos] = key;
			values[pos] = value;
			pos++;
			KPMapLog(ame_Log_EndMethod, "addPointer", "println", "");
		}
		
		virtual void add(K key, P value){
			KPMapLog(ame_Log_StartMethod, "add", "println", "");
			if(size < pos){
				KPMapLog(ame_Log_EndMethod, "add", "println", "");
				return;
			}
			keys[pos] = key;
			values[pos] = new P();
			*values[pos] = value;
			pos++;
			KPMapLog(ame_Log_EndMethod, "add", "println", "");
		}
		
		virtual void addCopy(RawMap<K,P>* r_map){
			KPMapLog(ame_Log_StartMethod, "addCopy", "println", "");
			for(int x = 0; x < r_map->getPosition(); x++){
				K* k = this->getKeyByPosition(x);
				P* v = this->getByPosition(x);
				this->addLValues(*k, *v);
			}
			KPMapLog(ame_Log_EndMethod, "addCopy", "println", "");
		}
		
		virtual void addMove(RawMap<K,P>* r_map){
			KPMapLog(ame_Log_StartMethod, "addMove", "println", "");
			for(int x = 0; x < r_map->getPosition(); x++){
				K* k = this->getKeyByPosition(x);
				P* v = this->getByPosition(x);
				if(this->isOwner()){
					this->addLValues(*k, *v);
				}else{
					this->addPointer(*k, v);
				}
			}
			KPMapLog(ame_Log_EndMethod, "addMove", "println", "");
		}
		
		virtual void setPointers(K *key, P *value){
			KPMapLog(ame_Log_StartMethod, "setPointers", "println", "");
			if(size < pos){
				KPMapLog(ame_Log_EndMethod, "setPointers", "println", "");
				return;
			}
			for(int x=0; x < pos; x++){
				if(keys[x] == *key ){
					values[x] = value;
				}
			}
			KPMapLog(ame_Log_EndMethod, "setPointers", "println", "");
		}
		
		virtual void setLValues(K key, P value){
			KPMapLog(ame_Log_StartMethod, "setLValues", "println", "");
			if(size < pos){
				KPMapLog(ame_Log_EndMethod, "setLValues", "println", "");
				return;
			}
			for(int x=0; x < pos; x++){
				if(keys[x] == key ){
					*values[x] = value;
				}
			}
			KPMapLog(ame_Log_EndMethod, "setLValues", "println", "");
		}
		
		virtual void setPointer(K key, P *value){
			KPMapLog(ame_Log_StartMethod, "setPointer", "println", "");
			if(size < pos){
				KPMapLog(ame_Log_EndMethod, "setPointer", "println", "");
				return;
			}
			for(int x=0; x < pos; x++){
				if(keys[x] == key ){
					values[x] = value;
				}
			}
			KPMapLog(ame_Log_EndMethod, "setPointer", "println", "");
		}
		
		virtual void setKeyLValueByPosition(int p, K key){
			KPMapLog(ame_Log_StartMethod, "setKeyLValueByPosition", "println", "");
			if(size < p){
				KPMapLog(ame_Log_EndMethod, "setKeyLValueByPosition", "println", "");
				return;
			}
			keys[p] = key;
			KPMapLog(ame_Log_EndMethod, "setKeyLValueByPosition", "println", "");
		}
		
		virtual void setKeyPointerByPosition(int p, K *key){
			KPMapLog(ame_Log_StartMethod, "setKeyPointerByPosition", "println", "");
			if(size < p){
				KPMapLog(ame_Log_EndMethod, "setKeyPointerByPosition", "println", "");
				return;
			}
			keys[p] = *key;
			KPMapLog(ame_Log_EndMethod, "setKeyPointerByPosition", "println", "");
		}
		
		virtual void setValueByPosition(int p, P value){
			KPMapLog(ame_Log_StartMethod, "setValueByPosition", "println", "");
			if(size < p){
				KPMapLog(ame_Log_EndMethod, "setValueByPosition", "println", "");
				return;
			}
			*values[p] = value;
			KPMapLog(ame_Log_EndMethod, "setValueByPosition", "println", "");
		}
		
		virtual void setValuePointerByPosition(int p, P *value){
			KPMapLog(ame_Log_StartMethod, "setValuePointerByPosition", "println", "");
			if(size < p){
				KPMapLog(ame_Log_EndMethod, "setValuePointerByPosition", "println", "");
				return;
			}
			values[p] = value;
			KPMapLog(ame_Log_EndMethod, "setValuePointerByPosition", "println", "");
		}
		
		virtual void set(K key, P value){
			KPMapLog(ame_Log_StartMethod, "set", "println", "");
			if(size < pos){
				KPMapLog(ame_Log_EndMethod, "set", "println", "");
				return;
			}
			for(int x=0; x < pos; x++){
				if(keys[x] == key ){
					*values[x] = value;
				}
			}
			KPMapLog(ame_Log_EndMethod, "set", "println", "");
		}
		
		virtual bool containKeyByPointer(K *key){
			KPMapLog(ame_Log_StartMethod, "containKeyByPointer", "println", "");
			for(int x=0; x < pos; x++){
				if(keys[x] == *key ){
					KPMapLog(ame_Log_EndMethod, "containKeyByPointer", "println", "");
					return true;
				}
			}
			KPMapLog(ame_Log_EndMethod, "containKeyByPointer", "println", "");
			return false;
		}
		
		virtual bool containKeyByLValue(K key){
			KPMapLog(ame_Log_StartMethod, "containKeyByLValue", "println", "");
			for(int x=0; x < pos; x++){
				if(keys[x] == key ){
					KPMapLog(ame_Log_EndMethod, "containKeyByLValue", "println", "");
					return true;
				}
			}
			KPMapLog(ame_Log_EndMethod, "containKeyByLValue", "println", "");
			return false;
		}
		
		virtual bool containValueByPointer(P *value){
			KPMapLog(ame_Log_StartMethod, "containValueByPointer", "println", "");
			for(int x=0; x < pos; x++){
				if(values[x] == value ){
					KPMapLog(ame_Log_EndMethod, "containValueByPointer", "println", "");
					return true;
				}
			}
			KPMapLog(ame_Log_EndMethod, "containValueByPointer", "println", "");
			return false;
		}
		
		virtual bool containValueByLValue(P value){
			KPMapLog(ame_Log_StartMethod, "containValueByLValue", "println", "");
			for(int x=0; x < pos; x++){
				if(*values[x] == value ){
					KPMapLog(ame_Log_EndMethod, "containValueByLValue", "println", "");
					return true;
				}
			}
			KPMapLog(ame_Log_EndMethod, "containValueByLValue", "println", "");
			return false;
		}
		
		virtual P *getByPointer(K *key){
			KPMapLog(ame_Log_StartMethod, "getByPointer", "println", "");
			for(int x=0; x < pos; x++){
				if(keys[x] == *key ){
					KPMapLog(ame_Log_EndMethod, "getByPointer", "println", "");
					return values[x];
				}
			}
			KPMapLog(ame_Log_EndMethod, "getByPointer", "println", "");
			return nullptr;
		}
		
		virtual P *getByLValue(K key){
			KPMapLog(ame_Log_StartMethod, "getByLValue", "println", "");
			for(int x=0; x < pos; x++){
				if(keys[x] == key ){
					KPMapLog(ame_Log_EndMethod, "getByLValue", "println", "");
					return values[x];
				}
			}
			KPMapLog(ame_Log_EndMethod, "getByLValue", "println", "");
			return nullptr;
		}
		
		virtual P *getByPosition(int p) const {
			KPMapLog(ame_Log_StartMethod, "getByPosition", "println", "");
			for(int x=0; x < pos; x++){
				if(x == p){
					KPMapLog(ame_Log_EndMethod, "getByPosition", "println", "");
					return values[x];
				}
			}
			KPMapLog(ame_Log_EndMethod, "getByPosition", "println", "");
			return nullptr;
		}
		
		virtual K *getKeyByPosition(int p) const{
			KPMapLog(ame_Log_StartMethod, "getKeyByPosition", "println", "");
			for(int x=0; x < pos; x++){
				if(x == p ){
					KPMapLog(ame_Log_EndMethod, "getKeyByPosition", "println", "");
					return (K*)&keys[x];
				}
			}
			KPMapLog(ame_Log_EndMethod, "getKeyByPosition", "println", "");
			return nullptr;
		}
		
		virtual K *getKeyByPointer(P *value){
			KPMapLog(ame_Log_StartMethod, "getKeyByPointer", "println", "");
			for(int x=0; x < pos; x++){
				if(values[x] == value ){
					KPMapLog(ame_Log_EndMethod, "getKeyByPointer", "println", "");
					return &keys[x];
				}
			}
			KPMapLog(ame_Log_EndMethod, "getKeyByPointer", "println", "");
			return nullptr;
		}
		
		virtual K *getKeyByLValue(P value){
			KPMapLog(ame_Log_StartMethod, "getKeyByLValue", "println", "");
			for(int x=0; x < pos; x++){
				if(*values[x] == value ){
					KPMapLog(ame_Log_EndMethod, "getKeyByLValue", "println", "");
					return &keys[x];
				}
			}
			KPMapLog(ame_Log_EndMethod, "getKeyByLValue", "println", "");
			return nullptr;
		}
		
		virtual P get(K key){
			KPMapLog(ame_Log_StartMethod, "get", "println", "");
			for(int x=0; x < pos; x++){
				if(keys[x] == key ){
					if(values[x] == nullptr){
						KPMapLog(ame_Log_EndMethod, "get", "println", "");
						return P();
					}
					KPMapLog(ame_Log_EndMethod, "get", "println", "");
					return *values[x];
				}
			}
			KPMapLog(ame_Log_EndMethod, "get", "println", "");
			return P();
		}
		
		virtual K getKey(int p){
			KPMapLog(ame_Log_StartMethod, "getKey", "println", "");
			for(int x=0; x < pos; x++){
				if(x == p ){
					KPMapLog(ame_Log_EndMethod, "getKey", "println", "");
					return keys[x];
				}
			}
			KPMapLog(ame_Log_EndMethod, "getKey", "println", "");
			return K();
		}
		
		virtual P getValue(int p){
			KPMapLog(ame_Log_StartMethod, "getValue", "println", "");
			for(int x=0; x < pos; x++){
				if(x == p ){
					if(values[x] == nullptr){
						KPMapLog(ame_Log_EndMethod, "getValue", "println", "");
						return P();
					}
					KPMapLog(ame_Log_EndMethod, "getValue", "println", "");
					return *values[x];
				}
			}
			KPMapLog(ame_Log_EndMethod, "getValue", "println", "");
			return P();
		}
		
		virtual void reset(){
			KPMapLog(ame_Log_StartMethod, "reset", "println", "");
			pos=0;
			KPMapLog(ame_Log_EndMethod, "reset", "println", "");
		}
		
		virtual void resetDelete(){
			KPMapLog(ame_Log_StartMethod, "resetDelete", "println", "");
			if(owner){
				for(int x=0; x < pos; x++){
					delete values[x];
				}
			}
			pos=0;
			KPMapLog(ame_Log_EndMethod, "resetDelete", "println", "");
		}
		
		virtual void resetDeleteKey(){
			KPMapLog(ame_Log_StartMethod, "resetDeleteKey", "println", "");
			pos=0;
			KPMapLog(ame_Log_EndMethod, "resetDeleteKey", "println", "");
		}
		
		virtual void resetDeleteValue(){
			KPMapLog(ame_Log_StartMethod, "resetDeleteValue", "println", "");
			if(owner){
				for(int x=0; x < pos; x++){
					delete values[x];
				}
			}
			pos=0;
			KPMapLog(ame_Log_EndMethod, "resetDeleteValue", "println", "");
		}
		
		virtual P *removeByPointer(K *key){
			KPMapLog(ame_Log_StartMethod, "removeByPointer", "println", "");
			P *p = nullptr;
			bool is=false;
			for(int x=0; x < pos; x++){
				if(keys[x] == *key ){
					is = true;
				}
			}
			if(is){
				int nv =0;
				for(int x=0; x < pos; x++){
					if(keys[x] != *key ){
						keys[nv] = keys[x];
						values[nv] = values[x];
						nv++;
					}else{
						p=values[x];
					}
				}
				pos = nv;
			}
			KPMapLog(ame_Log_EndMethod, "removeByPointer", "println", "");
			return p;
		}
		
		virtual P *removeByLValue(K key){
			KPMapLog(ame_Log_StartMethod, "removeByLValue", "println", "");
			P *p = nullptr;
			bool is=false;
			for(int x=0; x < pos; x++){
				if(keys[x] == key ){
					is = true;
				}
			}
			if(is){
				int nv =0;
				for(int x=0; x < pos; x++){
					if(keys[x] != key ){
						keys[nv] = keys[x];
						values[nv] = values[x];
						nv++;
					}else{
						p=values[x];
					}
				}
				pos = nv;
			}
			KPMapLog(ame_Log_EndMethod, "removeByLValue", "println", "");
			return p;
		}
		
		virtual P *removeByPosition(int ps){
			KPMapLog(ame_Log_StartMethod, "removeByPosition", "println", "");
			P *p = nullptr;
			bool is=false;
			for(int x=0; x < pos; x++){
				if(x == ps ){
					is = true;
				}
			}
			if(is){
				int nv =0;
				for(int x=0; x < pos; x++){
					if(x != ps ){
						keys[nv] = keys[x];
						values[nv] = values[x];
						nv++;
					}else{
						p=values[x];
					}
				}
				pos = nv;
			}
			KPMapLog(ame_Log_EndMethod, "removeByPosition", "println", "");
			return p;
		}
		
		virtual void removeDeleteByPointer(K *key){
			KPMapLog(ame_Log_StartMethod, "removeDeleteByPointer", "println", "");
			P *p = nullptr;
			bool is=false;
			for(int x=0; x < pos; x++){
				if(keys[x] == *key ){
					is = true;
				}
			}
			if(is){
				int nv =0;
				for(int x=0; x < pos; x++){
					if(keys[x] != *key ){
						keys[nv] = keys[x];
						values[nv] = values[x];
						nv++;
					}else{
						p=values[x];
						if(owner){
							delete p;
						}
					}
				}
				pos = nv;
			}
			KPMapLog(ame_Log_EndMethod, "removeDeleteByPointer", "println", "");
		}
		
		virtual void removeDeleteByLValue(K key){
			KPMapLog(ame_Log_StartMethod, "removeDeleteByLValue", "println", "");
			P *p = nullptr;
			bool is=false;
			for(int x=0; x < pos; x++){
				if(keys[x] == key ){
					is = true;
				}
			}
			if(is){
				int nv =0;
				for(int x=0; x < pos; x++){
					if(keys[x] != key ){
						keys[nv] = keys[x];
						values[nv] = values[x];
						nv++;
					}else{
						p=values[x];
						if(owner){
							delete p;
						}
					}
				}
				pos = nv;
			}
			KPMapLog(ame_Log_EndMethod, "removeDeleteByLValue", "println", "");
		}
		
		virtual void removeDeleteByPosition(int ps){
			KPMapLog(ame_Log_StartMethod, "removeDeleteByPosition", "println", "");
			P *p = nullptr;
			bool is=false;
			for(int x=0; x < pos; x++){
				if(x == ps ){
					is = true;
				}
			}
			if(is){
				int nv =0;
				for(int x=0; x < pos; x++){
					if(x != ps ){
						keys[nv] = keys[x];
						values[nv] = values[x];
						nv++;
					}else{
						p=values[x];
						if(owner){
							delete p;
						}
					}
				}
				pos = nv;
			}
			KPMapLog(ame_Log_EndMethod, "removeDeleteByPosition", "println", "");
		}
		
		virtual P remove(K key){
			KPMapLog(ame_Log_StartMethod, "remove", "println", "");
			int nv =0;
			P v;
			for(int x=0; x < pos; x++){
				if(keys[x] == key ){
					if(values[x] != nullptr){
						v = *values[x];
					}
					if(!owner){
						continue;
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
			KPMapLog(ame_Log_EndMethod, "remove", "println", "");
			return v;
		}
		
		virtual P removeIndex(int ps){
			KPMapLog(ame_Log_StartMethod, "removeIndex", "println", "");
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
			KPMapLog(ame_Log_EndMethod, "removeIndex", "println", "");
			return v;
		}
		
		virtual void putPointers(K* key, P* value){
			KPMapLog(ame_Log_StartMethod, "putPointers", "println", "");
			if(key == nullptr){
				return;
			}
			for(int x=0; x < pos; x++){
				if(*key == keys[x]){
					if(values[x] != value){
						if(owner && values[x] != nullptr){
							delete values[x];
						}
						values[x] = value;
					}
					KPMapLog(ame_Log_EndMethod, "putPointers", "println", "");
					return;
				}
			}
			if(size < pos){
				KPMapLog(ame_Log_EndMethod, "putPointers", "println", "");
				return;
			}
			keys[pos] = *key;
			values[pos] = value;
			pos++;
			KPMapLog(ame_Log_EndMethod, "putPointers", "println", "");
		}
		
		virtual void putLValues(K key, P value){
			KPMapLog(ame_Log_StartMethod, "putLValues", "println", "");
			for(int x=0; x < pos; x++){
				if(key == keys[x]){
					if(values[x] == nullptr){
						values[x] = new P();
					}
					*values[x] = value;
					KPMapLog(ame_Log_EndMethod, "putLValues", "println", "");
					return;
				}
			}
			if(size < pos){
				KPMapLog(ame_Log_EndMethod, "putLValues", "println", "");
				return;
			}
			values[pos] = new P();
			keys[pos] = key;
			*values[pos] = value;
			pos++;
			KPMapLog(ame_Log_EndMethod, "putLValues", "println", "");
		}
		
		virtual void putPointer(K key, P* value){
			KPMapLog(ame_Log_StartMethod, "putPointer", "println", "");
			for(int x=0; x < pos; x++){
				if(key == keys[x]){
					if(values[x] != value){
						if(owner && values[x] != nullptr){
							delete values[x];
						}
						values[x] = value;
					}
					KPMapLog(ame_Log_EndMethod, "putPointer", "println", "");
					return;
				}
			}
			if(size < pos){
				KPMapLog(ame_Log_EndMethod, "putPointer", "println", "");
				return;
			}
			keys[pos] = key;
			values[pos] = value;
			pos++;
			KPMapLog(ame_Log_EndMethod, "putPointer", "println", "");
		}
		
		virtual void put(K key, P value){
			KPMapLog(ame_Log_StartMethod, "put", "println", "");
			for(int x=0; x < pos; x++){
				if(key == keys[x]){
					if(values[x] == nullptr){
						values[x] = new P();
					}
					*values[x] = value;
					KPMapLog(ame_Log_EndMethod, "put", "println", "");
					return;
				}
			}
			if(size < pos){
				KPMapLog(ame_Log_EndMethod, "put", "println", "");
				return;
			}
			values[pos] = new P();
			keys[pos] = key;
			*values[pos] = value;
			pos++;
			KPMapLog(ame_Log_EndMethod, "put", "println", "");
		}
		
		virtual int getKeyIndexByPointer(K* key){
			KPMapLog(ame_Log_StartMethod, "getKeyIndexByPointer", "println", "");
			for(int x=0; x < pos; x++){
				if(*key == keys[x]){
					KPMapLog(ame_Log_EndMethod, "getKeyIndexByPointer", "println", "");
					return x;
				}
			}
			KPMapLog(ame_Log_EndMethod, "getKeyIndexByPointer", "println", "");
			return -1;
		}
		
		virtual int getKeyIndexByLValue(K key){
			KPMapLog(ame_Log_StartMethod, "getKeyIndexByLValue", "println", "");
			for(int x=0; x < pos; x++){
				if(key == keys[x]){
					KPMapLog(ame_Log_EndMethod, "getKeyIndexByLValue", "println", "");
					return x;
				}
			}
			KPMapLog(ame_Log_EndMethod, "getKeyIndexByLValue", "println", "");
			return -1;
		}
		
		virtual int getIndexByPointer(P* v){
			KPMapLog(ame_Log_StartMethod, "getIndexByPointer", "println", "");
			for(int x=0; x < pos; x++){
				if(v == values[x]){
					KPMapLog(ame_Log_EndMethod, "getIndexByPointer", "println", "");
					return x;
				}
			}
			KPMapLog(ame_Log_EndMethod, "getIndexByPointer", "println", "");
			return -1;
		}
		
		virtual int getIndexByLValue(P v){
			KPMapLog(ame_Log_StartMethod, "getIndexByLValue", "println", "");
			for(int x=0; x < pos; x++){
				if(values[x] == nullptr){
					continue;
				}
				if(v == *values[x]){
					KPMapLog(ame_Log_EndMethod, "getIndexByLValue", "println", "");
					return x;
				}
			}
			KPMapLog(ame_Log_EndMethod, "getIndexByLValue", "println", "");
			return -1;
		}
		
		virtual void onDelete(){
			KPMapLog(ame_Log_StartMethod, "onDelete", "println", "");
			if(owner){
				for(int x=0; x < pos; x++){
					delete values[x];
				}
			}
			KPMapLog(ame_Log_EndMethod, "onDelete", "println", "");
		}
		
		virtual cppObjectClass* getClass(){
			KPMapLog(ame_Log_StartMethod, "getClass", "println", "");
			KPMapLog(ame_Log_EndMethod, "getClass", "println", "");
			return Class<KPMap>::classType;
		}
		
		virtual Map<K,P>* clone(){
			KPMapLog(ame_Log_StartMethod, "clone", "println", "");
			Map<K,P>* cloneMap = new KPMap<K,P,size>(true);
			for(int cm = 0; cm < this->pos; cm++){
				cloneMap->addLValues(keys[cm], *values[cm]);
			}
			KPMapLog(ame_Log_EndMethod, "clone", "println", "");
			return cloneMap;
		}
		
		virtual Map<K,P>* clone(bool owningMemory){
			KPMapLog(ame_Log_StartMethod, "clone", "println", "");
			Map<K,P>* cloneMap = new KPMap<K,P,size>(owningMemory);
			for(int cm = 0; cm < this->pos; cm++){
				cloneMap->addLValues(keys[cm], *values[cm]);
			}
			KPMapLog(ame_Log_EndMethod, "clone", "println", "");
			return cloneMap;
		}
		
        virtual KPMap<K,P,size>& operator=(const KPMap<K,P,size>& m_map){
			KPMapLog(ame_Log_StartMethod, "operator=", "println", "");
			resetDelete();
			owner = m_map.owner;
			for(int x = 0; x < m_map.getPosition(); x++){
				K k = *m_map.getKeyByPosition(x);
				P v = *m_map.getByPosition(x);
				this->addLValues(k,v);
			}
			KPMapLog(ame_Log_EndMethod, "operator=", "println", "");
			return *this;
		}
		
        virtual bool operator ==(const KPMap<K,P,size>& m_map){
			KPMapLog(ame_Log_StartMethod, "operator ==", "println", "");
			for(int x = 0; x < pos; x++){
				K k = m_map.keys[x];
				P v = *m_map.values[x];
				if(keys[x] != k || *values[x] != v){
					KPMapLog(ame_Log_EndMethod, "operator ==", "println", "");
					return false;
				}
			}
			KPMapLog(ame_Log_EndMethod, "operator ==", "println", "");
			return true;
		}
		
        virtual bool operator !=(const KPMap<K,P,size>& m_map){
			KPMapLog(ame_Log_StartMethod, "operator !=", "println", "");
			for(int x = 0; x < pos; x++){
				K k = m_map.keys[x];
				P v = *m_map.values[x];
				if(keys[x] == k || *values[x] == v){
					KPMapLog(ame_Log_EndMethod, "operator !=", "println", "");
					return false;
				}
			}
			KPMapLog(ame_Log_EndMethod, "operator !=", "println", "");
			return true;
		}
		
	protected:
		int pos;
};

}

#endif