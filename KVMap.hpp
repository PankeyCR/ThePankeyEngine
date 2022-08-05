
#include "ame_Enviroment.hpp"

#if defined(DISABLE_KVMap)
	#define KVMap_hpp
#endif

#ifndef KVMap_h
#define KVMap_h
#define KVMap_AVAILABLE

#ifndef ame_Enviroment_Defined

#endif

#ifdef ame_Windows

#endif

#ifdef ame_ArduinoIDE
	#include "Arduino.h"
#endif

#include "cppObject.hpp"
#include "Class.hpp"
#include "Map.hpp"

namespace ame{

template <class K,class P,int size>
class KVMap : public Map<K,P>{
	
    public:
		int pos=0;
		P values[size];
		K keys[size];
		
		KVMap(){
			
		}
		
		KVMap(const KVMap& m_map){
			for(int x = 0; x < m_map.getPosition(); x++){
				K k = *m_map.getKeyByPosition(x);
				P v = *m_map.getByPosition(x);
				this->addLValues(k,v);
			}
		}
		
		virtual ~KVMap(){
			
		}
		virtual void setOwner(bool b){}
		virtual bool isOwner()const{return false;}

		virtual bool isEmpty()const{
			return this->pos==0;
		}
		
		void setPosition(int p){
			this->pos = p;
		}
		
		int getPosition()const{
			return this->pos;
		}
		
		int getSize()const{
			return size;
		}
		
		void addPointers(K *key, P *value){
			if(size < this->pos){
				return;
			}
			this->keys[pos] = *key;
			this->values[pos] = *value;
			this->pos++;
			delete key;
			delete value;
		}
		
		void addLValues(K key, P value){
			if(size < this->pos){
				return;
			}
			this->keys[pos] = key;
			this->values[pos] = value;
			this->pos++;
		}
		
		void addPointer(K key, P *value){
			if(size < this->pos){
				return;
			}
			this->keys[pos] = key;
			this->values[pos] = *value;
			this->pos++;
			delete value;
		}
		
		virtual void add(K key, P value){
			if(size < pos){
				return;
			}
			keys[pos] = key;
			values[pos] = value;
			pos++;
		}
		
		virtual void addCopy(RawMap<K,P>* r_map){
			for(int x = 0; x < r_map->getPosition(); x++){
				K* k = this->getKeyByPosition(x);
				P* v = this->getByPosition(x);
				this->addLValues(*k, *v);
			}
		}
		
		virtual void addMove(RawMap<K,P>* r_map){
			for(int x = 0; x < r_map->getPosition(); x++){
				K* k = this->getKeyByPosition(x);
				P* v = this->getByPosition(x);
				if(this->isOwner()){
					this->addLValues(*k, *v);
				}else{
					this->addLValues(*k, *v);
				}
			}
		}
		
		void setPointers(K *key, P *value){
			if(size < this->pos){
				return;
			}
			for(int x=0; x < pos; x++){
				if(this->keys[x] == *key ){
					this->values[x] = *value;
				}
			}
		}
		
		void setLValues(K key, P value){
			if(size < this->pos){
				return;
			}
			for(int x=0; x < this->pos; x++){
				if(this->keys[x] == key ){
					this->values[x] = value;
				}
			}
		}
		
		void setPointer(K key, P *value){
			if(size < pos){
				return;
			}
			for(int x=0; x < pos; x++){
				if(this->keys[x] == key ){
					this->values[x] = *value;
				}
			}
		}
		
		void setKeyLValueByPosition(int p, K key){
			if(size < p){
				return;
			}
			keys[p] = key;
		}
		
		void setKeyPointerByPosition(int p, K *key){
			if(size < p){
				return;
			}
			keys[p] = *key;
		}
		
		void setValueByPosition(int p, P value){
			if(size < p){
				return;
			}
			values[p] = value;
		}
		
		void setValuePointerByPosition(int p, P *value){
			if(size < p){
				return;
			}
			values[p] = *value;
		}
		
		virtual void set(K key, P value){
			if(size < pos){
				return;
			}
			for(int x=0; x < pos; x++){
				if(keys[x] == key ){
					values[x] = value;
				}
			}
		}
		
		bool containKeyByPointer(K *key){
			for(int x=0; x < this->pos; x++){
				if(this->keys[x] == *key ){
					return true;
				}
			}
			return false;
		}
		
		bool containKeyByLValue(K key){
			for(int x=0; x < this->pos; x++){
				if(this->keys[x] == key ){
					return true;
				}
			}
			return false;
		}
		
		bool containValueByPointer(P *value){
			for(int x=0; x < this->pos; x++){
				if(this->values[x] == *value ){
					return true;
				}
			}
			return false;
		}
		
		bool containValueByLValue(P value){
			for(int x=0; x < this->pos; x++){
				if(this->values[x] == value ){
					return true;
				}
			}
			return false;
		}
		
		P *getByPointer(K *key){
			for(int x=0; x < this->pos; x++){
				if(this->keys[x] == *key ){
					return &this->values[x];
				}
			}
			return nullptr;
		}
		
		P *getByLValue(K key){
			for(int x=0; x < this->pos; x++){
				if(this->keys[x] == key ){
					return &this->values[x];
				}
			}
			return nullptr;
		}
		
		P *getByPosition(int p) const{
			for(int x=0; x < this->pos; x++){
				if(x == p){
					return (P*)&this->values[x];
				}
			}
			return nullptr;
		}
		
		K *getKeyByPosition(int p) const{
			for(int x=0; x < this->pos; x++){
				if(x == p ){
					return (K*)&this->keys[x];
				}
			}
			return nullptr;
		}
		
		K *getKeyByPointer(P *value){
			for(int x=0; x < this->pos; x++){
				if(this->values[x] == *value ){
					return &this->keys[x];
				}
			}
			return nullptr;
		}
	
		K *getKeyByLValue(P value){
			for(int x=0; x < this->pos; x++){
				if(this->values[x] == value ){
					return &this->keys[x];
				}
			}
			return nullptr;
		}
		
		virtual P get(K key){
			for(int x=0; x < pos; x++){
				if(keys[x] == key ){
					return values[x];
				}
			}
			return P();
		}
		
		K getKey(int p){
			for(int x=0; x < pos; x++){
				if(x == p ){
					return keys[x];
				}
			}
			return K();
		}
		
		virtual P getValue(int p){
			for(int x=0; x < pos; x++){
				if(x == p ){
					return values[x];
				}
			}
			return P();
		}
		
		void reset(){
			this->pos=0;
		}
		
		void resetDelete(){
			this->pos=0;
		}
		
		void resetDeleteKey(){
			this->pos=0;
		}
		
		void resetDeleteValue(){
			this->pos=0;
		}
		
		P *removeByPointer(K *key){
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
			return p;
		}
		
		P *removeByLValue(K key){
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
			return p;
		}
		
		P *removeByPosition(int ps){
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
			return p;
		}
		
		void removeDeleteByPointer(K *key){
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
		}
		
		void removeDeleteByLValue(K key){
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
		}
		
		void removeDeleteByPosition(int ps){
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
		}
		
		P remove(K key){
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
			return v;
		}
		
		P removeIndex(int ps){
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
			return v;
		}
		
		void putPointers(K* key, P* value){
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
		}
		
		void putLValues(K key, P value){
			for(int x=0; x < pos; x++){
				if(key == keys[x]){
					values[x] = value;
					return;
				}
			}
			if(size < pos){
				return;
			}
			keys[pos] = key;
			values[pos] = value;
			pos++;
		}
		
		void putPointer(K key, P* value){
			if(value == nullptr){
				return;
			}
			for(int x=0; x < pos; x++){
				if(key == keys[x]){
					values[x] = *value;
					return;
				}
			}
			if(size < pos){
				return;
			}
			keys[pos] = key;
			values[pos] = *value;
			pos++;
		}
		
		void put(K key, P value){
			for(int x=0; x < pos; x++){
				if(key == keys[x]){
					values[x] = value;
					return;
				}
			}
			if(size < pos){
				return;
			}
			keys[pos] = key;
			values[pos] = value;
			pos++;
		}
		
		int getKeyIndexByPointer(K* key){
			for(int x=0; x < pos; x++){
				if(*key == keys[x]){
					return x;
				}
			}
			return -1;
		}
		
		int getKeyIndexByLValue(K key){
			for(int x=0; x < pos; x++){
				if(key == keys[x]){
					return x;
				}
			}
			return -1;
		}
		
		int getIndexByPointer(P* v){
			if(v == nullptr){
				return -1;
			}
			for(int x=0; x < pos; x++){
				if(*v == values[x]){
					return x;
				}
			}
			return -1;
		}
		
		int getIndexByLValue(P v){
			for(int x=0; x < pos; x++){
				if(v == values[x]){
					return x;
				}
			}
			return -1;
		}
		
		void onDelete(){
			
		}
		
		cppObjectClass* getClass(){
			return Class<KVMap>::classType;
		}
		
		Map<K,P>* clone(void){
			Map<K,P>* cloneMap = new KVMap<K,P,size>();
			for(int cm = 0; cm < this->pos; cm++){
				cloneMap->addLValues(keys[cm], values[cm]);
			}
			return cloneMap;
		}
		
		Map<K,P>* clone(bool owningMemory){
			Map<K,P>* cloneMap = new KVMap<K,P,size>();
			for(int cm = 0; cm < this->pos; cm++){
				cloneMap->addLValues(keys[cm], values[cm]);
			}
			return cloneMap;
		}
		
        KVMap<K,P,size>& operator =(const KVMap<K,P,size>& m_map){
			resetDelete();
			for(int x = 0; x < m_map.getPosition(); x++){
				K k = *m_map.getKeyByPosition(x);
				P v = *m_map.getByPosition(x);
				this->addLValues(k,v);
			}
			return *this;
		}
		
        bool operator ==(const KVMap<K,P,size>& m_map){
			for(int x = 0; x < pos; x++){
				K k = m_map.keys[x];
				P v = m_map.values[x];
				if(keys[x] != k || values[x] != v){
					return false;
				}
			}
			return true;
		}
		
        bool operator !=(const KVMap<K,P,size>& m_map){
			for(int x = 0; x < pos; x++){
				K k = m_map.keys[x];
				P v = m_map.values[x];
				if(keys[x] == k || values[x] == v){
					return false;
				}
			}
			return true;
		}
		
		virtual MapIterator<K,P> getIterator(int p){
			for(int x=0; x < pos; x++){
				if(x == p ){
					return MapIterator<K,P>(this,p,pos);
				}
			}
			return MapIterator<K,P>(nullptr,0,0);
		}
	
		
	private:
};

}

#endif