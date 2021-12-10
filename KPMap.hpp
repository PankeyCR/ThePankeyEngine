
#ifndef KPMap_hpp
#define KPMap_hpp

#include "ame_Level.hpp"

#if defined(ame_untilLevel_1)

#include "cppObject.hpp"
#include "Map.hpp"

namespace ame{

template <class K,class P,int size = 20>
class KPMap : public Map<K,P>{
	
    public:
		bool owner = false;
		P *values[size];
		K keys[size];
		
		KPMap(){
			pos=0;
		}
		
		KPMap(const KPMap& m_map){
			owner = m_map.owner;
			for(int x = 0; x < m_map.getPosition(); x++){
				K k = *m_map.getKeyByPosition(x);
				P v = *m_map.getByPosition(x);
				this->addLValues(k,v);
			}
		}
		
		KPMap(bool own){
			owner = own;
			pos=0;
		}
		
		~KPMap(){
			if(owner){
				for(int x=0; x < pos; x++){
					delete values[x];
				}
			}
		}

		virtual void setOwner(bool b){
			this->owner = b;
		}

		virtual bool isOwner()const{
			return this->owner;
		}

		virtual bool isEmpty()const{
			return this->pos==0;
		}
		
		void setPosition(int p){
			pos = p;
		}
		
		int getPosition()const{
			return pos;
		}
		
		int getSize()const{
			return size;
		}
		
		void addPointers(K *key, P *value){
			if(size < pos){
				return;
			}
			if(key == nullptr || value == nullptr){
				return;
			}
			keys[pos] = *key;
			values[pos] = value;
			pos++;
			delete key;
		}
		
		void addLValues(K key, P value){
			if(size < pos){
				return;
			}
			keys[pos] = key;
			values[pos] = new P();
			*values[pos] = value;
			pos++;
		}
		
		void addPointer(K key, P *value){
			if(size < pos){
				return;
			}
			keys[pos] = key;
			values[pos] = value;
			pos++;
		}
		
		virtual void add(K key, P value){
			if(size < pos){
				return;
			}
			keys[pos] = key;
			values[pos] = new P();
			*values[pos] = value;
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
					this->addPointer(*k, v);
				}
			}
		}
		
		void setPointers(K *key, P *value){
			if(size < pos){
				return;
			}
			for(int x=0; x < pos; x++){
				if(keys[x] == *key ){
					values[x] = value;
				}
			}
		}
		
		void setLValues(K key, P value){
			if(size < pos){
				return;
			}
			for(int x=0; x < pos; x++){
				if(keys[x] == key ){
					*values[x] = value;
				}
			}
		}
		
		void setPointer(K key, P *value){
			if(size < pos){
				return;
			}
			for(int x=0; x < pos; x++){
				if(keys[x] == key ){
					values[x] = value;
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
			*values[p] = value;
		}
		
		void setValuePointerByPosition(int p, P *value){
			if(size < p){
				return;
			}
			values[p] = value;
		}
		
		virtual void set(K key, P value){
			if(size < pos){
				return;
			}
			for(int x=0; x < pos; x++){
				if(keys[x] == key ){
					*values[x] = value;
				}
			}
		}
		
		bool containKeyByPointer(K *key){
			for(int x=0; x < pos; x++){
				if(keys[x] == *key ){
					return true;
				}
			}
			return false;
		}
		
		bool containKeyByLValue(K key){
			for(int x=0; x < pos; x++){
				if(keys[x] == key ){
					return true;
				}
			}
			return false;
		}
		
		bool containValueByPointer(P *value){
			for(int x=0; x < pos; x++){
				if(values[x] == value ){
					return true;
				}
			}
			return false;
		}
		
		bool containValueByLValue(P value){
			for(int x=0; x < pos; x++){
				if(*values[x] == value ){
					return true;
				}
			}
			return false;
		}
		
		P *getByPointer(K *key){
			for(int x=0; x < pos; x++){
				if(keys[x] == *key ){
					return values[x];
				}
			}
			return nullptr;
		}
		
		P *getByLValue(K key){
			for(int x=0; x < pos; x++){
				if(keys[x] == key ){
					return values[x];
				}
			}
			return nullptr;
		}
		
		P *getByPosition(int p) const {
			for(int x=0; x < pos; x++){
				if(x == p){
					return values[x];
				}
			}
			return nullptr;
		}
		
		K *getKeyByPosition(int p) const{
			for(int x=0; x < pos; x++){
				if(x == p ){
					return (K*)&keys[x];
				}
			}
			return nullptr;
		}
		
		K *getKeyByPointer(P *value){
			for(int x=0; x < pos; x++){
				if(values[x] == value ){
					return &keys[x];
				}
			}
			return nullptr;
		}
		
		K *getKeyByLValue(P value){
			for(int x=0; x < pos; x++){
				if(*values[x] == value ){
					return &keys[x];
				}
			}
			return nullptr;
		}
		
		virtual P get(K key){
			for(int x=0; x < pos; x++){
				if(keys[x] == key ){
					if(values[x] == nullptr){
						return P();
					}
					return *values[x];
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
					if(values[x] == nullptr){
						return P();
					}
					return *values[x];
				}
			}
			return P();
		}
		
		void reset(){
			pos=0;
		}
		
		void resetDelete(){
			if(owner){
				for(int x=0; x < pos; x++){
					delete values[x];
				}
			}
			pos=0;
		}
		
		void resetDeleteKey(){
			pos=0;
		}
		
		void resetDeleteValue(){
			if(owner){
				for(int x=0; x < pos; x++){
					delete values[x];
				}
			}
			pos=0;
		}
		
		P *removeByPointer(K *key){
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
			return p;
		}
		
		P *removeByLValue(K key){
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
			return p;
		}
		
		P *removeByPosition(int ps){
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
			return p;
		}
		
		void removeDeleteByPointer(K *key){
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
		}
		
		void removeDeleteByLValue(K key){
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
		}
		
		void removeDeleteByPosition(int ps){
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
		}
		
		P remove(K key){
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
			return v;
		}
		
		P removeIndex(int ps){
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
			return v;
		}
		
		void putPointers(K* key, P* value){
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
					return;
				}
			}
			if(size < pos){
				return;
			}
			keys[pos] = *key;
			values[pos] = value;
			pos++;
		}
		
		void putLValues(K key, P value){
			for(int x=0; x < pos; x++){
				if(key == keys[x]){
					if(values[x] == nullptr){
						values[x] = new P();
					}
					*values[x] = value;
					return;
				}
			}
			if(size < pos){
				return;
			}
			values[pos] = new P();
			keys[pos] = key;
			*values[pos] = value;
			pos++;
		}
		
		void putPointer(K key, P* value){
			for(int x=0; x < pos; x++){
				if(key == keys[x]){
					if(values[x] != value){
						if(owner && values[x] != nullptr){
							delete values[x];
						}
						values[x] = value;
					}
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
		
		void put(K key, P value){
			for(int x=0; x < pos; x++){
				if(key == keys[x]){
					if(values[x] == nullptr){
						values[x] = new P();
					}
					*values[x] = value;
					return;
				}
			}
			if(size < pos){
				return;
			}
			values[pos] = new P();
			keys[pos] = key;
			*values[pos] = value;
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
			for(int x=0; x < pos; x++){
				if(v == values[x]){
					return x;
				}
			}
			return -1;
		}
		
		int getIndexByLValue(P v){
			for(int x=0; x < pos; x++){
				if(values[x] == nullptr){
					continue;
				}
				if(v == *values[x]){
					return x;
				}
			}
			return -1;
		}
		
		void onDelete(){
			if(owner){
				for(int x=0; x < pos; x++){
					delete values[x];
				}
			}
		}
		
		cppObjectClass* getClass(){
			return Class<KPMap>::classType;
		}
		
		Map<K,P>* clone(){
			Map<K,P>* cloneMap = new KPMap<K,P,size>(true);
			for(int cm = 0; cm < this->pos; cm++){
				cloneMap->addLValues(keys[cm], *values[cm]);
			}
			return cloneMap;
		}
		
		Map<K,P>* clone(bool owningMemory){
			Map<K,P>* cloneMap = new KPMap<K,P,size>(owningMemory);
			for(int cm = 0; cm < this->pos; cm++){
				cloneMap->addLValues(keys[cm], *values[cm]);
			}
			return cloneMap;
		}
		
        KPMap<K,P,size>& operator=(const KPMap<K,P,size>& m_map){
			resetDelete();
			owner = m_map.owner;
			for(int x = 0; x < m_map.getPosition(); x++){
				K k = *m_map.getKeyByPosition(x);
				P v = *m_map.getByPosition(x);
				this->addLValues(k,v);
			}
			return *this;
		}
		
        bool operator ==(const KPMap<K,P,size>& m_map){
			for(int x = 0; x < pos; x++){
				K k = m_map.keys[x];
				P v = *m_map.values[x];
				if(keys[x] != k || *values[x] != v){
					return false;
				}
			}
			return true;
		}
		
        bool operator !=(const KPMap<K,P,size>& m_map){
			for(int x = 0; x < pos; x++){
				K k = m_map.keys[x];
				P v = *m_map.values[x];
				if(keys[x] == k || *values[x] == v){
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
		int pos;
};

}

#endif 

#endif 
