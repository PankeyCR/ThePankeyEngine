	
#include "ame_Enviroment.hpp"

#if defined(DISABLE_PMap)
	#define PMap_hpp
#endif

#ifndef PMap_hpp
#define PMap_hpp
#define PMap_AVAILABLE

#ifndef ame_Enviroment_Defined

#endif

#ifdef ame_Windows

#endif

#ifdef ame_ArduinoIDE
	#include "Arduino.h"
	#include "Printable.h"
#endif
#include "cppObject.hpp"
#include "Class.hpp"
#include "RawMap.hpp"
#include "Map.hpp"
#include "MapIterator.hpp"

namespace ame{

template <class K,class P,int size>
class PMap : public Map<K,P>{
	
    public:
		P *values[size];
		K *keys[size];
		
		PMap(){
			pos=0;
		}
		
		PMap(const PMap& m_map){
			owner = m_map.owner;
			pos=0;
			for(int x = 0; x < m_map.getPosition(); x++){
				K k = *m_map.getKeyByPosition(x);
				P v = *m_map.getByPosition(x);
				this->addLValues(k,v);
			}
		}
		
		PMap(const bool& own){
			owner = own;
			pos=0;
		}
		
		virtual ~PMap(){
			if(owner){
				for(int x=0; x < pos; x++){
					delete keys[x];
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
		
		virtual void setPosition(int p){
			pos = p;
		}
		
		virtual int getPosition()const{
			return pos;
		}
		
		virtual int getSize()const{
			return size;
		}
		
		// virtual void addEntry(MapIterator<K,P> entry){
			// if(size < pos){
				// return;
			// }
			// keys[pos] = entry.key;
			// values[pos] = entry.value;
			// pos++;
		// }
		
		virtual void addPointers(K *key, P *value){
			if(size < pos){
				return;
			}
			keys[pos] = key;
			values[pos] = value;
			pos++;
		}
		
		virtual void addLValues(K key, P value){
			if(size < pos){
				return;
			}
			keys[pos] = new K();
			values[pos] = new P();
			*keys[pos] = key;
			*values[pos] = value;
			pos++;
		}
		
		virtual void addPointer(K key, P *value){
			if(size < pos){
				return;
			}
			keys[pos] = new K();
			*keys[pos] = key;
			values[pos] = value;
			pos++;
		}
		
		virtual void add(K key, P value){
			if(size < pos){
				return;
			}
			keys[pos] = new K();
			values[pos] = new P();
			*keys[pos] = key;
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
					this->addPointers(k, v);
				}
			}
		}
		
		// virtual void setEntry(MapIterator<K,P> entry){
			// if(size < pos){
				// return;
			// }
			// for(int x=0; x < pos; x++){
				// if(keys[x] == entry.key ){
					// values[x] = entry.value;
				// }
			// }
		// }
		
		virtual void setPointers(K *key, P *value){
			if(size < pos){
				return;
			}
			for(int x=0; x < pos; x++){
				if(keys[x] == key ){
					values[x] = value;
				}
			}
		}
		
		virtual void setLValues(K key, P value){
			if(size < pos){
				return;
			}
			for(int x=0; x < pos; x++){
				if(*keys[x] == key ){
					*values[x] = value;
				}
			}
		}
		
		virtual void setPointer(K key, P *value){
			if(size < pos){
				return;
			}
			for(int x=0; x < pos; x++){
				if(*keys[x] == key ){
					values[x] = value;
				}
			}
		}
		
		virtual void setKeyLValueByPosition(int p, K key){
			if(size < p){
				return;
			}
			*keys[p] = key;
		}
		
		virtual void setKeyPointerByPosition(int p, K *key){
			if(size < p){
				return;
			}
			keys[p] = key;
		}
		
		virtual void setValueByPosition(int p, P value){
			if(size < p){
				return;
			}
			*values[p] = value;
		}
		
		virtual void setValuePointerByPosition(int p, P *value){
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
				if(*keys[x] == key ){
					*values[x] = value;
				}
			}
		}
		
		// virtual bool containEntry(MapIterator<K,P> entry){
			// for(int x=0; x < pos; x++){
				// if(keys[x] == entry.key && values[x] == entry.value){
					// return true;
				// }
			// }
			// return false;
		// }
		
		virtual bool containKeyByPointer(K *key){
			for(int x=0; x < pos; x++){
				if(keys[x] == key ){
					return true;
				}
			}
			return false;
		}
		
		virtual bool containKeyByLValue(K key){
			for(int x=0; x < pos; x++){
				if(*keys[x] == key ){
					return true;
				}
			}
			return false;
		}
		
		virtual bool containValueByPointer(P *value){
			for(int x=0; x < pos; x++){
				if(values[x] == value ){
					return true;
				}
			}
			return false;
		}
		
		virtual bool containValueByLValue(P value){
			for(int x=0; x < pos; x++){
				if(*values[x] == value ){
					return true;
				}
			}
			return false;
		}
		
		virtual P *getByPointer(K *key){
			for(int x=0; x < pos; x++){
				if(keys[x] == key ){
					return values[x];
				}
			}
			return nullptr;
		}
		
		virtual P *getByLValue(K key){
			for(int x=0; x < pos; x++){
				if(*keys[x] == key ){
					return values[x];
				}
			}
			return nullptr;
		}
		
		virtual P *getByPosition(int p) const{
			for(int x=0; x < pos; x++){
				if(x == p){
					return values[x];
				}
			}
			return nullptr;
		}
		
		virtual K *getKeyByPosition(int p) const{
			for(int x=0; x < pos; x++){
				if(x == p ){
					return keys[x];
				}
			}
			return nullptr;
		}
		
		virtual K *getKeyByPointer(P *value){
			for(int x=0; x < pos; x++){
				if(values[x] == value ){
					return keys[x];
				}
			}
			return nullptr;
		}
		
		virtual K *getKeyByLValue(P value){
			for(int x=0; x < pos; x++){
				if(*values[x] == value ){
					return keys[x];
				}
			}
			return nullptr;
		}
		
		virtual P get(K key){
			for(int x=0; x < pos; x++){
				if(*keys[x] == key ){
					if(values[x] == nullptr){
						return P();
					}
					return *values[x];
				}
			}
			return P();
		}
		
		virtual K getKey(int p){
			K key;
			for(int x=0; x < pos; x++){
				if(x == p ){
					if(keys[x] == nullptr){
						return key;
					}
					key = *keys[x];
					return key;
				}
			}
			return key;
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
		
		virtual void reset(){
			pos=0;
		}
		
		virtual void resetDelete(){
			if(owner){
				for(int x=0; x < pos; x++){
					delete keys[x];
					delete values[x];
				}
			}
			pos=0;
		}
		
		virtual void resetDeleteKey(){
			if(owner){
				for(int x=0; x < pos; x++){
					delete keys[x];
				}
			}
			pos=0;
		}
		
		virtual void resetDeleteValue(){
			if(owner){
				for(int x=0; x < pos; x++){
					delete values[x];
				}
			}
			pos=0;
		}
		
		// virtual MapIterator<K,P> removeEntry(MapIterator<K,P> entry){
			// MapIterator<K,P> p;
			// int nv =0;
			// for(int x=0; x < pos; x++){
				// if(keys[x] != entry.key && values[x] != entry.value){
					// keys[nv] = keys[x];
					// values[nv] = values[x];
					// nv++;
				// }else{
					// p = MapIterator<K,P>(keys[x],values[x]);
				// }
			// }
			// pos = nv;
			// return p;
		// }
		
		virtual P *removeByPointer(K *key){
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
			return p;
		}
		
		virtual P *removeByLValue(K key){
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
			return p;
		}
		
		virtual P *removeByPosition(int ps){
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
			return p;
		}
		
		// virtual void removeDeleteEntry(MapIterator<K,P> entry){
			// int nv =0;
			// for(int x=0; x < pos; x++){
				// if(keys[x] == entry.key ){
					// if(keys[x] != nullptr){
						// delete keys[x];
					// }
					// if(values[x] != nullptr){
						// delete values[x];
					// }
				// }else{
					// keys[nv] = keys[x];
					// values[nv] = values[x];
					// nv++;
				// }
			// }
			// pos = nv;
		// }
		
		virtual void removeDeleteByPointer(K *key){
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
		}
		
		virtual void removeDeleteByLValue(K key){
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
		}
		
		virtual void removeDeleteByPosition(int ps){
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
		}
		
		virtual P remove(K key){
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
			return v;
		}
		
		virtual P removeIndex(int ps){
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
			return v;
		}
		
		// virtual void putEntry(MapIterator<K,P> entry){
			// if(entry.key == nullptr){
				// return;
			// }
			// for(int x=0; x < pos; x++){
				// if(entry.key == keys[x]){
					// if(values[x] != entry.value){
						// if(owner && values[x] != nullptr){
							// delete values[x];
						// }
						// values[x] = entry.value;
					// }
					// return;
				// }
			// }
			// if(size < pos){
				// return;
			// }
			// keys[pos] = entry.key;
			// values[pos] = entry.value;
			// pos++;
		// }
		
		virtual void putPointers(K* key, P* value){
			if(key == nullptr){
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
		
		virtual void putLValues(K key, P value){
			for(int x=0; x < pos; x++){
				if(key == *keys[x]){
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
			keys[pos] = new K();
			values[pos] = new P();
			*keys[pos] = key;
			*values[pos] = value;
			pos++;
		}
		
		virtual void putPointer(K key, P* value){
			for(int x=0; x < pos; x++){
				if(key == *keys[x]){
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
			keys[pos] = new K();
			*keys[pos] = key;
			values[pos] = value;
			pos++;
		}
		
		virtual void put(K key, P value){
			for(int x=0; x < pos; x++){
				if(key == *keys[x]){
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
			keys[pos] = new K();
			values[pos] = new P();
			*keys[pos] = key;
			*values[pos] = value;
			pos++;
		}
		
		virtual int getKeyIndexByPointer(K* key){
			for(int x=0; x < pos; x++){
				if(key == keys[x]){
					return x;
				}
			}
			return -1;
		}
		
		virtual int getKeyIndexByLValue(K key){
			for(int x=0; x < pos; x++){
				if(key == *keys[x]){
					return x;
				}
			}
			return -1;
		}
		
		virtual int getIndexByPointer(P* v){
			for(int x=0; x < pos; x++){
				if(v == values[x]){
					return x;
				}
			}
			return -1;
		}
		
		virtual int getIndexByLValue(P v){
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
		
		virtual void onDelete(){
			if(owner){
				for(int x=0; x < pos; x++){
					delete keys[x];
					delete values[x];
				}
			}
		}
		
		virtual cppObjectClass* getClass(){
			return Class<PMap>::classType;
		}
		
		virtual int getIterationSize(){
			return pos;
		}
		
		virtual Map<K,P>* clone(){
			Map<K,P>* cloneMap = new PMap<K,P,size>(true);
			for(int cm = 0; cm < pos; cm++){
				cloneMap->addLValues(*keys[cm], *values[cm]);
			}
			return cloneMap;
		}
		
		virtual Map<K,P>* clone(bool owningMemory){
			Map<K,P>* cloneMap = new PMap<K,P,size>(owningMemory);
			for(int cm = 0; cm < pos; cm++){
				cloneMap->addLValues(*keys[cm], *values[cm]);
			}
			return cloneMap;
		}
		
        virtual PMap<K,P,size>& operator =(const PMap<K,P,size>& m_map){
			resetDelete();
			owner = m_map.owner;
			for(int x = 0; x < m_map.getPosition(); x++){
				K k = *m_map.getKeyByPosition(x);
				P v = *m_map.getByPosition(x);
				this->addLValues(k,v);
			}
			return *this;
		}
		
        virtual bool operator ==(const PMap<K,P,size>& m_map){
			for(int x = 0; x < pos; x++){
				K k = *m_map.keys[x];
				P v = *m_map.values[x];
				if(*keys[x] != k || *values[x] != v){
					return false;
				}
			}
			return true;
		}
		
        virtual bool operator !=(const PMap<K,P,size>& m_map){
			for(int x = 0; x < pos; x++){
				K k = *m_map.keys[x];
				P v = *m_map.values[x];
				if(*keys[x] == k || *values[x] == v){
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
		
		
		
	protected:
		int pos;
		bool owner = false;
};

}

#endif