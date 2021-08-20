
#ifndef PMap_h
#define PMap_h

#include "cppObject.h"
#include "Map.h"

namespace ame{

template <class K,class P,int size>
class PMap : public Map<K,P>{
	
    public:
		P *values[size];
		K *keys[size];
		
		PMap(){
			pos=0;
			for(int x=0; x < size; x++){
				keys[x] = nullptr;
				values[x] = nullptr;
			}
		}
		
		PMap(bool own){
			owner = own;
			pos=0;
			for(int x=0; x < size; x++){
				keys[x] = nullptr;
				values[x] = nullptr;
			}
		}
		
		~PMap(){
			if(owner){
				for(int x=0; x < pos; x++){
					delete keys[x];
					delete values[x];
				}
			}
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
			keys[pos] = key;
			values[pos] = value;
			pos++;
		}
		
		void addLValues(K key, P value){
			if(size < pos){
				return;
			}
			if(keys[pos] == nullptr){
				keys[pos] = new K();
			}
			if(values[pos] == nullptr){
				values[pos] = new P();
			}
			*keys[pos] = key;
			*values[pos] = value;
			pos++;
		}
		
		void addPointer(K key, P *value){
			if(size < pos){
				return;
			}
			if(keys[pos] == nullptr){
				keys[pos] = new K();
			}
			*keys[pos] = key;
			values[pos] = value;
			pos++;
		}
		
		void setPointers(K *key, P *value){
			if(size < pos){
				return;
			}
			for(int x=0; x < pos; x++){
				if(keys[x] == key ){
					values[x] = value;
				}
			}
		}
		
		void setLValues(K key, P value){
			if(size < pos){
				return;
			}
			for(int x=0; x < pos; x++){
				if(*keys[x] == key ){
					*values[x] = value;
				}
			}
		}
		
		void setPointer(K key, P *value){
			if(size < pos){
				return;
			}
			for(int x=0; x < pos; x++){
				if(*keys[x] == key ){
					values[x] = value;
				}
			}
		}
		
		void setKeyLValueByPosition(int p, K key){
			if(size < p){
				return;
			}
			*keys[p] = key;
		}
		
		void setKeyPointerByPosition(int p, K *key){
			if(size < p){
				return;
			}
			keys[p] = key;
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
		
		bool containKeyByPointer(K *key){
			for(int x=0; x < pos; x++){
				if(keys[x] == key ){
					return true;
				}
			}
			return false;
		}
		
		bool containKeyByLValue(K key){
			for(int x=0; x < pos; x++){
				if(*keys[x] == key ){
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
				if(keys[x] == key ){
					return values[x];
				}
			}
			return nullptr;
		}
		
		P *getByLValue(K key){
			for(int x=0; x < pos; x++){
				if(*keys[x] == key ){
					return values[x];
				}
			}
			return nullptr;
		}
		
		P *getByPosition(int p){
			for(int x=0; x < pos; x++){
				if(x == p){
					return values[x];
				}
			}
			return nullptr;
		}
		
		K *getKeyByPosition(int p){
			for(int x=0; x < pos; x++){
				if(x == p ){
					return keys[x];
				}
			}
			return nullptr;
		}
		
		K *getKeyByPointer(P *value){
			for(int x=0; x < pos; x++){
				if(values[x] == value ){
					return keys[x];
				}
			}
			return nullptr;
		}
		
		K *getKeyByLValue(P value){
			for(int x=0; x < pos; x++){
				if(*values[x] == value ){
					return keys[x];
				}
			}
			return nullptr;
		}
		
		void reset(){
			pos=0;
		}
		
		void resetDelete(){
			if(owner){
				for(int x=0; x < pos; x++){
					delete keys[x];
					delete values[x];
				}
			}
			pos=0;
		}
		
		void resetDeleteKey(){
			if(owner){
				for(int x=0; x < pos; x++){
					delete keys[x];
				}
			}
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
		
		P *removeByLValue(K key){
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
		
		P *removeByPosition(int ps){
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
		
		void removeDeleteByPointer(K *key){
			int nv =0;
			for(int x=0; x < pos; x++){
				if(keys[x] == key ){
					delete keys[x];
					delete values[x];
				}else{
					keys[nv] = keys[x];
					values[nv] = values[x];
					nv++;
				}
			}
			pos = nv;
		}
		
		void removeDeleteByLValue(K key){
			int nv =0;
			for(int x=0; x < pos; x++){
				if(*keys[x] == key ){
					delete keys[x];
					delete values[x];
				}else{
					keys[nv] = keys[x];
					values[nv] = values[x];
					nv++;
				}
			}
			pos = nv;
		}
		
		void removeDeleteByPosition(int ps){
			int nv =0;
			for(int x=0; x < pos; x++){
				if(x == ps){
					delete keys[x];
					delete values[x];
				}else{
					keys[nv] = keys[x];
					values[nv] = values[x];
					nv++;
				}
			}
			pos = nv;
		}
		
		void onDelete(){
			if(owner){
				for(int x=0; x < pos; x++){
					delete keys[x];
					delete values[x];
				}
			}
		}
		
		cppObjectClass* getClass(){
			return Class<PMap>::classType;
		}
		
		int getIterationSize(){
			return pos;
		}
		
		P getLValue(Iterator iterate){
			return *this->getByPosition(iterate.getIteration());
		}
		
		P *getPointer(Iterator iterate){
			return this->getByPosition(iterate.getIteration());
		}
		
		K getKey(Iterator iterate){
			return *this->getKeyByPosition(iterate.getIteration());
		}
		
		K *getKeyPointer(Iterator iterate){
			return this->getKeyByPosition(iterate.getIteration());
		}
		
		Map<K,P>* clone(){
			Map<K,P>* cloneMap = new PMap<K,P,size>(true);
			for(int cm = 0; cm < pos; cm++){
				cloneMap->addLValues(*keys[cm], *values[cm]);
			}
			return cloneMap;
		}
		
		Map<K,P>* clone(bool owningMemory){
			Map<K,P>* cloneMap = new PMap<K,P,size>(owningMemory);
			for(int cm = 0; cm < pos; cm++){
				cloneMap->addLValues(*keys[cm], *values[cm]);
			}
			return cloneMap;
		}
		
        void operator =(PMap<K,P,size> t){
			
		}
		
        bool operator ==(PMap<K,P,size> t){
			return this->getClassName() == t->getClassName();
		}
		
        bool operator !=(PMap<K,P,size> t){
			return this->getClassName() != t->getClassName();
		}
		
		
		
	protected:
		int pos;
		bool owner = false;
};

}

#endif 
