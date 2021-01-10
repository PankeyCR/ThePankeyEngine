
#ifndef ArrayList_h
#define ArrayList_h

#include "cppObject.h"
#include "List.h"

template <class T,int size=20>
class ArrayList : public List<T>{
	private:

	public:
	int pos;
	T values[size];

	ArrayList<T,size>(){
		pos=0;
	}

	ArrayList<T,size>(T t[],int s){
		pos=0;
		for(int x=0; x<s; x++){
			this->addLValue(t[x]);
		}
	}

	bool isEmpty(){
		return pos==0;
	}

	void setPosition(int p){
		pos=p;
	}

	int getPosition(){
		return pos;
	}

	int getSize(){
		return size;
	}

	T *getByPosition(int x){
		if(x >= pos){
			return nullptr;
		}
		return &values[x];
	}

	void addList(List<T> *list){
		if(list == nullptr){
			return;
		}
		for(int x=0; x < list->getPosition() ; x++){
			values[pos] = *list->getByPosition(x);
			pos++;
		}
	}
	
	template<class... args>
	void addPack(args... x){
		T array[] = {x...};
		//for(const T &a : array){
		for(T a : array){
			addLValue(a);
		}
	}

	template<class... Args>
	T* addParameters(Args... args){
		if(pos >= size){
			return nullptr;
		}
		values[pos] = T(args...);
		pos++;
		return &values[pos-1];
	}

	T* addPointer(T *value){
		if(pos >= size){
			delete value;
			return nullptr;
		}
		values[pos] = *value;
		delete value;
		pos++;
		return &values[pos-1];
	}

	T* addLValue(T value){
		if(pos >= size){
			return nullptr;
		}
		values[pos] = value;
		pos++;
		return &values[pos-1];
	}

	T* setLValue(int position,T value){
		if(position >= size){
			return nullptr;
		}
		values[position] = value;
		return &values[position];
	}

	T* setPointer(int position,T* value){
		if(position >= size){
			return nullptr;
		}
		if(value == nullptr){
			return nullptr;
		}
		values[position] = *value;
		delete value;
		return &values[position];
	}

	T* insertLValue(int position, T value){
		if(position >= size){
			return nullptr;
		}
		if(position >= pos+1){
			return nullptr;
		}
		T nVaule;
		T rVaule = value;
		for(int x = 0; x <= pos; x++){
			if(x >= position){
				nVaule = values[x];
				values[x] = rVaule;
				rVaule = nVaule;
			}
		}
		return &values[position];
	}

	T* insertPointer(int position, T* value){
		if(position >= size){
			return nullptr;
		}
		if(position >= pos+1){
			return nullptr;
		}
		if(value == nullptr){
			return nullptr;
		}
		T nVaule;
		T rVaule = *value;
		for(int x = 0; x <= pos; x++){
			if(x >= position){
				nVaule = values[x];
				values[x] = rVaule;
				rVaule = nVaule;
			}
		}
		return &values[position];
	}

	T *getByPointer(T *key){
		for(int x=0; x < pos; x++){
			if(values[x] == *key ){
				return &values[x];
			}
		}
		return nullptr;
	}

	T* getByLValue(T key){
		for(int x=0; x < pos; x++){
			if(values[x] == key ){
				return &values[x];
			}
		}
		return nullptr;
	}

	bool containByPointer(T* key){
		for(int x=0; x < pos; x++){
			if(values[x] == *key ){
				return true;
			}
		}
		return false;
	}

	bool containByLValue(T key){
		for(int x=0; x < pos; x++){
			if(values[x] == key ){
				return true;
			}
		}
		return false;
	}

	int getIndexByPointer(T* key){
		for(int x=0; x < pos; x++){
			if(values[x] == *key ){
				return x;
			}
		}
		return -1;
	}

	int getIndexByLValue(T key){
		for(int x=0; x < pos; x++){
			if(values[x] == key ){
				return x;
			}
		}
		return -1;
	}

	void reset(){
		pos=0;
	}

	void resetDelete(){
		pos=0;
	}

	T* removeByPointer(T* key){
		T *t = nullptr;
		bool is=false;
		for(int x=0; x < pos; x++){
			if(values[x] == *key ){
				is = true;
			}
		}
		if(is){
			int nv =0;
			for(int x=0; x < pos; x++){
				if(values[x] != *key ){
					values[nv] = values[x];
					nv++;
				}else{
					t = &values[x];
				}
			}
			pos = nv;
		}
		return t;
	}

	T* removeByLValue(T key){
		T *t = nullptr;
		bool is=false;
		for(int x=0; x < pos; x++){
			if(values[x] == key ){
				is = true;
			}
		}
		if(is){
			int nv =0;
			for(int x=0; x < pos; x++){
				if(values[x] != key ){
					values[nv] = values[x];
					nv++;
				}else{
					t = &values[x];
				}
			}
			pos = nv;
		}
		return t;
	}

	T* removeByPosition(int p){
		if(p >= pos){
			return nullptr;
		}
		T* t = nullptr;
		for(int x=0; x < pos; x++){
			if(x == p ){
				t = &values[x];
			}
			if(x > p ){
				values[x-1] = values[x];
			}
		}
		pos--;
		return t;
	}

	void removeDeleteByPointer(T* key){
		bool is=false;
		for(int x=0; x < pos; x++){
			if(values[x] == *key ){
				is = true;
			}
		}
		if(is){
			int nv =0;
			for(int x=0; x < pos; x++){
				if(values[x] != *key ){
					values[nv] = values[x];
					nv++;
				}
			}
			pos = nv;
		}
	}

	void removeDeleteByLValue(T key){
		bool is=false;
		for(int x=0; x < pos; x++){
			if(values[x] == key ){
				is = true;
			}
		}
		if(is){
			int nv =0;
			for(int x=0; x < pos; x++){
				if(values[x] != key ){
					values[nv] = values[x];
					nv++;
				}
			}
			pos = nv;
		}
	}

	void removeDeleteByPosition(int p){
		if(p >= pos){
			return;
		}
		for(int x=0; x < pos; x++){
			if(x > p ){
				values[x-1] = values[x];
			}
		}
		pos--;
	}

	T& operator[](int x){
		if(x >= size){
			return values[size-1];
		}
		if(pos == x){
			pos++;
		}
		return values[x];
	}

	String getClassName(){
		return "ArrayList";
	}

	int getIterationSize(){
		return pos;
	}

	T getLValue(Iterator iterate){
		return *this->getByPosition(iterate.getIteration());
	}

	T* getPointer(Iterator iterate){
		return this->getByPosition(iterate.getIteration());
	}

	T* setLValue(Iterator iterate, T s){
		return this->setLValue(iterate.getIteration() , s);
	}

	T* setPointer(Iterator iterate, T* s){
		return this->setPointer(iterate.getIteration() , s);
	}

	T* insertLValue(Iterator& iterate, T s){
		int p = iterate.getIteration();
		iterate.next();
		return this->insertLValue(p , s);
	}

	T* insertPointer(Iterator& iterate, T* s){
		int p = iterate.getIteration();
		iterate.next();
		return this->insertPointer(p , s);
	}

	T* remove(Iterator& iterate){
		int p = iterate.getIteration();
		iterate.last();
		return this->removeByPosition(p);
	}

	void removeDelete(Iterator& iterate){
		int p = iterate.getIteration();
		iterate.last();
		this->removeDeleteByPosition(p);
	}

	List<T>* clone(){
		List<T>* list = new ArrayList<T,size>();
		for(int xl=0; xl < this->pos; xl++){
			list->addLValue(values[xl]);
		}
		return list;
	}

	List<T>* clone(bool owningMemory){
		List<T>* list = new ArrayList<T,size>();
		for(int xl=0; xl < this->pos; xl++){
			list->addLValue(values[xl]);
		}
		return list;
	}

	void operator =(ArrayList<T,size> t){
		for(int xtst=0; xtst<size; xtst++){
			values[xtst] == *t.getPointerByPos(xtst);
		}
	}

	void operator =(const T a[size]){
		for(int xtst=0; xtst<size; xtst++){
			values[xtst] == a[xtst];
		}
	}

	bool operator ==(ArrayList<T,size> t){
		return this->getClassName() == t.getClassName();
	}

	bool operator !=(ArrayList<T,size> t){
		return this->getClassName() != t.getClassName();
	}
};

#endif 
