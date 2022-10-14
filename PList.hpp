
#ifndef PList_hpp
#define PList_hpp
#define PList_AVAILABLE

#include "ListIterator.hpp"
#include "cppObject.hpp"
#include "Class.hpp"
#include "List.hpp"

#ifdef PList_LogApp
	#include "ame_Logger_config.hpp"
	#include "ame_Logger.hpp"

	#define PListLog(location,method,type,mns) ame_Log(this,location,"PList",method,type,mns)
	#define const_PListLog(location,method,type,mns)
#else
	#ifdef PList_LogDebugApp
		#include "ame_Logger_config.hpp"
		#include "ame_Logger.hpp"

		#define PListLog(location,method,type,mns) ame_LogDebug(this,location,"PList",method,type)
		#define const_PListLog(location,method,type,mns)
	#else
		#define PListLog(location,method,type,mns)
		#define const_PListLog(location,method,type,mns)
	#endif
#endif

namespace ame{

template <class T,int t_size>
class PList : public List<T>{
	private:
		int m_pos = 0;	
		bool m_owner = false;
    public:
		
		T* m_values[t_size];
		
		PList(){}
		
		PList(bool c_own){
			this->setOwner(c_own);
		}
		
		virtual ~PList(){
			if(this->isOwner()){
				for(int x = 0; x < this->getPosition() ; x++){
					if(this->m_values[x] != nullptr){
						delete this->m_values[x];
					}
				}
			}
		}

		virtual bool isEmpty()const{
			return this->getPosition() == 0;
		}
	
		virtual bool replace(int i, int j){
			if(i >= this->getPosition() || j >= this->getPosition()){
				return false;
			}
			T* it = this->m_values[i];
			T* jt = this->m_values[j];
			this->m_values[i] = jt;
			this->m_values[j] = it;
			return true;
		}
		
		virtual T* addPointer(T* a_a_value){
            if(this->getPosition() >= t_size){
				return nullptr;
            }
			this->m_values[this->getPosition()] = a_a_value;
			this->incrementPosition();
			return a_a_value;
		}
		
		virtual T* setPointer(int a_position, T* a_value){
            if(a_position >= t_size){
				return nullptr;
            }
			if(this->m_values[a_position] != nullptr && this->m_values[a_position] != a_value && this->isOwner()){
				delete this->m_values[a_position];
			}
			this->m_values[a_position] = a_value;
			return a_value;
		}
		
		virtual T* insertPointer(int a_position, T* a_value){
            if(a_value == nullptr || this->m_values[a_position] == a_value){
				return nullptr;
            }
            if(a_position >= t_size){
				return nullptr;
            }
            if(a_position >= this->getPosition() + 1){
				return nullptr;
            }
			T* nVaule;
			T* rVaule = a_value;
			if(this->isOwner()){
				for(int x = 0; x <= this->getPosition(); x++){
					if(x == t_size && nVaule != nullptr){
						delete nVaule;
					}
					if(x >= a_position && x != t_size){
						nVaule = this->m_values[x];
						this->m_values[x] = rVaule;
						rVaule = nVaule;
					}
				}
			}else{
				for(int x = 0; x <= this->getPosition(); x++){
					if(x >= a_position){
						nVaule = this->m_values[x];
						this->m_values[x] = rVaule;
						rVaule = nVaule;
					}
				}
			}
			if(this->getPosition() < t_size){
				this->incrementPosition();
			}
			return this->m_values[a_position];
		}
		
		virtual T* getByPointer(T* key){
			for(int x=0; x < this->getPosition(); x++){
				if(this->m_values[x] == key ){
					return this->m_values[x];
				}
			}
			return nullptr;
		}
		
		virtual T* getByPosition(int x)const{
			if(x >= this->getPosition()){
				return nullptr;
			}
			return this->m_values[x];
		}
		
		virtual bool containByPointer(T *key){
			for(int x=0; x < this->getPosition(); x++){
				if(this->m_values[x] == key ){
					return true;
				}
			}
			return false;
		}
		
		virtual int getIndexByPointer(T *key){
			for(int x=0; x < this->getPosition(); x++){
				if(this->m_values[x] == key ){
					return x;
				}
			}
			return -1;
		}
		
		virtual void reset(){
			this->setPosition(0);
			for(int x=0; x < this->getPosition(); x++){
				this->m_values[x] = nullptr;
			}
		}
		
		virtual void resetDelete(){
			for(int x=0; x < this->getPosition(); x++){
				if(this->m_values[x] != nullptr && this->isOwner()){
					delete this->m_values[x];
				}
				this->m_values[x] = nullptr;
			}
			this->setPosition(0);
		}
		
		virtual T* removeByPointer(T* key){
			T *t = nullptr;
			bool is=false;
			for(int x=0; x < this->getPosition(); x++){
				if(this->m_values[x] == key ){
					is = true;
				}
			}
			if(is){
				int nv =0;
				for(int x=0; x < this->getPosition(); x++){
					if(this->m_values[x] != key ){
						this->m_values[nv] = this->m_values[x];
						nv++;
					}else{
						t = this->m_values[x];
					}
				}
				this->setPosition(nv);
			}
			return t;
		}
		
		virtual T* removeByPosition(int p){
			if(p >= this->getPosition()){
				return nullptr;
			}
			T* t = nullptr;
			for(int x=0; x < this->getPosition(); x++){
				if(x == p ){
					t = this->m_values[x];
				}
				if(x > p ){
					this->m_values[x-1] = this->m_values[x];
				}
			}
			this->decrementPosition();
			return t;
		}
		
		virtual bool removeFirstIndex(int a_amount){
			return false;
		}
	
		virtual bool removeLastIndex(int a_amount){
			return false;
		}
		
		virtual T* addLValue(T a_a_value){
            if(this->getPosition() >= t_size){
				return nullptr;
            }
			this->m_values[this->getPosition()] = new T();
			*this->m_values[this->getPosition()] = a_a_value;
			this->incrementPosition();
			return this->m_values[this->getPosition() - 1];
		}
		
		virtual T* setLValue(int a_position, T a_value){
            if(a_position >= t_size){
				return nullptr;
            }
			if(this->m_values[a_position] == nullptr){
				this->m_values[a_position] = new T();
			}
			*this->m_values[a_position] = a_value;
			return this->m_values[a_position];
		}
		
		virtual T* insertLValue(int a_position, T a_value){
            if(a_position >= t_size){
				return nullptr;
            }
            if(a_position >= this->getPosition() + 1){
				return nullptr;
            }
			T* nVaule = nullptr;
			T* rVaule = new T();
			*rVaule = a_value;
			if(this->isOwner()){
				for(int x = 0; x <= t_size; x++){
					if(x == t_size && nVaule != nullptr){
						delete nVaule;
					}
					if(x >= a_position && x != t_size){
						nVaule = this->m_values[x];
						this->m_values[x] = rVaule;
						rVaule = nVaule;
					}
				}
			}else{
				for(int x = 0; x <= this->getPosition(); x++){
					if(x >= a_position){
						nVaule = this->m_values[x];
						this->m_values[x] = rVaule;
						rVaule = nVaule;
					}
				}
			}
			if(this->getPosition() < t_size){
				this->incrementPosition();
			}
			return this->m_values[a_position];
		}
		
		virtual T* getByLValue(T key){
			for(int x=0; x < this->getPosition(); x++){
				if(*this->m_values[x] == key ){
					return this->m_values[x];
				}
			}
			return nullptr;
		}
		
		virtual bool containByLValue(T key){
			for(int x=0; x < this->getPosition(); x++){
				if(*this->m_values[x] == key ){
					return true;
				}
			}
			return false;
		}
		
		virtual int getIndexByLValue(T key){
			for(int x=0; x < this->getPosition(); x++){
				if(*this->m_values[x] == key ){
					return x;
				}
			}
			return -1;
		}
		
		virtual T* removeByLValue(T key){
			T *t = nullptr;
			bool is=false;
			for(int x=0; x < this->getPosition(); x++){
				if(*this->m_values[x] == key ){
					is = true;
				}
			}
			if(is){
				int nv =0;
				for(int x=0; x < this->getPosition(); x++){
					if(*this->m_values[x] != key ){
						this->m_values[nv] = this->m_values[x];
						nv++;
					}else{
						t = this->m_values[x];
					}
				}
				this->setPosition(nv);
			}
			return t;
		}
		////////////////////////////////////////////special removes part///////////////////////////////////////////////
		virtual bool removeAll(T a_value){
			bool r_val = false;
			int p_x = 0;
			for(int x = 0; x < this->getPosition(); x++){
				if(a_value == *this->m_values[x]){
					if(this->isOwner()){
						delete this->m_values[x];
					}
					r_val = true;
				}else{
					this->m_values[p_x] = this->m_values[x];
					p_x++;
				}
			}
			this->setPosition(p_x);
			return r_val;
		}
		
		virtual bool removeFirst(T a_value){
			bool r_val = false;
			bool r_once = true;
			int p_x = 0;
			for(int x = 0; x < this->getPosition(); x++){
				if(a_value == *this->m_values[x] && r_once){
					if(this->isOwner()){
						delete this->m_values[x];
					}
					r_once = false;
					r_val = true;
				}else{
					this->m_values[p_x] = this->m_values[x];
					p_x++;
				}
			}
			this->setPosition(p_x);
			return r_val;
			// return false;
		}
		
		virtual bool removeLast(T a_value){
			int r_pos = this->getPosition();
			for(int x = this->getPosition() - 1; x >= 0; x--){
				if(a_value == *this->m_values[x]){
					r_pos = x;
					break;
				}
			}
			
			bool r_val = false;
			bool r_once = true;
			int p_x = r_pos;
			for(int x = p_x; x < this->getPosition(); x++){
				if(a_value == *this->m_values[x] && r_once){
					if(this->isOwner()){
						delete this->m_values[x];
					}
					r_once = false;
					r_val = true;
				}else{
					this->m_values[p_x] = this->m_values[x];
					p_x++;
				}
			}
			this->setPosition(p_x);
			return r_val;
			// return false;
		}
		
		virtual T& operator[](int x){
			if(x >= t_size){
				return *this->m_values[t_size - 1];
			}
			if(this->getPosition() == x){
				this->incrementPosition();
			}
			this->m_values[x] = new T();
			return *this->m_values[x];
		}
		
		////////////////////////////////////////////operator part///////////////////////////////////////////////
	
		virtual void onDelete(){
			for(int x=0; x < this->getPosition(); x++){
				if(this->m_values[x] != nullptr && this->isOwner()){
					delete this->m_values[x];
				}
				this->m_values[x] = nullptr;
			}
			this->setPosition(0);
		}
		
		virtual cppObjectClass* getClass(){
			return Class<PList<T,t_size>>::getClass();
		}
		
		virtual List<T>* clone(){
			List<T>* list = new PList<T,t_size>(true);
			for(int xl = 0; xl < this->getPosition(); xl++){
				list->addLValue(*this->m_values[xl]);
			}
			return list;
		}
		
		virtual List<T>* clone(bool owningMemory){
			List<T>* list = new PList<T,t_size>(owningMemory);
			for(int xl=0; xl < this->getPosition(); xl++){
				list->addLValue(*this->m_values[xl]);
			}
			return list;
		}
		
        virtual void operator =(const PList<T,t_size>& t){
			
		}
		
        virtual bool operator ==(PList<T,t_size> t){
			return false;
		}
		
        virtual bool operator !=(PList<T,t_size> t){
			return false;
		}
	
		////////////////////////////////////////////Iterator part///////////////////////////////////////////////
		
		ListIterator<T> begin(){
		  return ListIterator<T>(this, 0, this->getPosition());
		}
		
		ListIterator<T> end(){
		  return ListIterator<T>(this, this->getPosition(), this->getPosition());
		}
};

}

#endif