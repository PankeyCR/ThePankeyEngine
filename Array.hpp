
#include "ame_Enviroment.hpp"

#ifndef Array_hpp
#define Array_hpp
#define Array_AVAILABLE

#ifndef ame_Enviroment_Defined

#endif

#ifdef ame_Windows

#endif

#ifdef ame_ArduinoIDE
	#include "Arduino.h"
	
#endif

#include "ArrayIterator.hpp"

#include "Memory.hpp"

#include "cppObject.hpp"

#include "RawList.hpp"
#include "PrimitiveRawList.hpp"
#include "RawMap.hpp"
#include "PrimitiveRawMap.hpp"

#ifdef Array_LogApp
	#include "ame_Logger_config.hpp"
	#include "ame_Logger.hpp"
	
	#define ArrayLog(location,method,type,mns) ame_Log((void*)this,location,"Array",method,type,mns)
	#define const_ArrayLog(location,method,type,mns) 
	#define StaticArrayLog(pointer,location,method,type,mns) ame_Log(pointer,location,"Array",method,type,mns)
#else
	#ifdef Array_LogDebugApp
		#include "ame_Logger_config.hpp"
		#include "ame_Logger.hpp"
		
		#define ArrayLog(location,method,type,mns) ame_LogDebug((void*)this,location,"Array",method,type)
		#define const_ArrayLog(location,method,type,mns) 
		#define StaticArrayLog(pointer,location,method,type,mns) ame_LogDebug(pointer,location,"Array",method,type)
	#else
		#define ArrayLog(location,method,type,mns) 
		#define const_ArrayLog(location,method,type,mns) 
		#define StaticArrayLog(pointer,location,method,type,mns) 
	#endif
#endif


namespace ame{
	
template<class T>
class Array : public Printable, public cppObject{

	protected:
		T* m_t_value = nullptr;
		int m_pos = 0;
		int m_size = 0;
		int m_expandSize = 0;

    public:
		Array(){
			ArrayLog(ame_Log_StartMethod, "Constructor", "println", "");
			ArrayLog(ame_Log_Statement, "Constructor", "println", "Default Constructor");
			ArrayLog(ame_Log_EndMethod, "Constructor", "println", "");
		}
		
		template<class... args>
		Array(args... xs){
			ArrayLog(ame_Log_StartMethod, "Constructor", "println", "args... xs");
			
			T array1[] = {xs...};
			int size = 0;
			for(const T& a : array1){
			  size++;
			}
			if(size != 0){
				ArrayLog(ame_Log_Statement, "Constructor", "println", size);
				m_pos = size;
				m_size = getAvailableSize(m_pos);
				ArrayLog(ame_Log_Statement, "Constructor", "println", m_size);
				m_t_value = create(m_size);
				int c = 0;
				if(m_t_value != nullptr){
					for(const T& a : array1){
						m_t_value[c] = a;
						// ArrayLog(ame_Log_Statement, "Constructor", "println", a);
						c++;
					}
				}
			}
			ArrayLog(ame_Log_EndMethod, "Constructor", "println", "");
		}

		Array(const Array<T>& source){
			ArrayLog(ame_Log_StartMethod, "Constructor", "println", "");
			ArrayLog(ame_Log_Statement, "Constructor", "println", "const Array& val");
			int n_size = source.getPosition();
			if(n_size > 0){
				ArrayLog(ame_Log_Statement, "Constructor", "println", n_size);
				m_size = getAvailableSize(n_size);
				ArrayLog(ame_Log_Statement, "Constructor", "println", m_size);
				m_t_value = create(m_size);
				copy(source.m_t_value, n_size);
				ArrayLog(ame_Log_Statement, "Constructor", "println", m_t_value);
			}
			ArrayLog(ame_Log_EndMethod, "Constructor", "println", "");
		}

		Array(Array&& source){
			ArrayLog(ame_Log_StartMethod, "Constructor", "println", "start");
			ArrayLog(ame_Log_Statement, "Constructor", "println", "Array&& source");
			int n_size = source.getPosition();
			if(n_size > 0){
				m_pos = source.m_pos;
				m_size = source.m_size;
				m_t_value = source.m_t_value;
				source.m_t_value = nullptr;
				source.m_pos = 0;
				source.m_size = 0;
				ArrayLog(ame_Log_Statement, "Constructor", "println", m_pos);
				ArrayLog(ame_Log_Statement, "Constructor", "println", m_size);
				ArrayLog(ame_Log_Statement, "Constructor", "println", m_t_value);
			}
			ArrayLog(ame_Log_EndMethod, "Constructor", "println", "");
		}

		virtual ~Array(){
			ArrayLog(ame_Log_StartMethod, "Destructor", "println", "");
			ArrayLog(ame_Log_Statement, "Destructor", "println", "~Array");
			ArrayLog(ame_Log_Statement, "Destructor", "println", m_pos);
			ArrayLog(ame_Log_Statement, "Destructor", "println", m_size);
			fix();
			erase();
			ArrayLog(ame_Log_EndMethod, "Destructor", "println", "");
		}

		virtual size_t printTo(Print& p) const{
			if(m_t_value == nullptr || m_pos == 0){
				return 0;
			}
			size_t i_size = 0;
			for(int x = 0; x < m_pos; x++){
				i_size += p.print(m_t_value[x]);
			}
			return i_size;
		}

		virtual size_t printTo(Print& p, int a_index) const{
			if(m_t_value == nullptr){
				return 0;
			}
			size_t i_size = 0;
			for(int x = 0; x < m_pos; x++){
				i_size += p.print(m_t_value[x]);
			}
			return i_size;
		}
		
		virtual void expandLocal(int a_size){
			ArrayLog(ame_Log_StartMethod, "expandLocal", "println", "");
			int nsize = m_size + a_size;
			T *nT = new T[nsize];
			for(int x = 0; x < m_pos; x++){
				nT[x] = m_t_value[x];
			}
			delete[] m_t_value;
			m_t_value = nT;
			m_size = nsize;
			ArrayLog(ame_Log_EndMethod, "expandLocal", "println", "");
		}
		
		virtual void fix(){
			
		}
		
		virtual void erase(){
			if(m_t_value == nullptr){
				m_pos = 0;
				m_size = 0;
				return;
			}
			delete[] m_t_value;
			m_t_value = nullptr;
			m_pos = 0;
			m_size = 0;
		}
		
		virtual T* create(int a_size){
			return new T[a_size];
		}
		
		virtual void fill(T a_fill){
			if(m_t_value == nullptr){
				return;
			}
			for(int x = 0; x < m_pos; x++){
				m_t_value[x] = a_fill;
			}
		}
		
		virtual void clear(){
			if(m_t_value == nullptr){
				m_pos = 0;
				m_size = 0;
				return;
			}
			delete[] m_t_value;
			m_t_value = nullptr;
			m_pos = 0;
			m_size = 0;
		}
		
		virtual void copy(T* a_copy, int a_size){
			if(m_t_value == nullptr || a_copy == nullptr ){
				return;
			}
			if(a_size + m_pos > m_size){
				return;
			}
			for(int x = 0; x < a_size; x++){
				m_t_value[m_pos] = a_copy[x];
				m_pos++;
			}
		}
		
		virtual void copy(const T& a_value){
			if(m_t_value == nullptr){
				return;
			}
			if(m_pos + 1 > m_size){
				return;
			}
			m_t_value[m_pos] = a_value;
			m_pos++;
		}
		
		virtual int getAvailableSize(int a_pos){
			return a_pos;
		}

		virtual T* pointer(){
			ArrayLog(ame_Log_StartMethod, "pointer", "println", "");
			ArrayLog(ame_Log_EndMethod, "pointer", "println", "");
			return m_t_value;
		}

		virtual int length() const{
			return m_pos;
		}

		virtual int getPosition() const{
			return m_pos;
		}

		virtual int getSize() const{
			return m_size;
		}

		virtual bool isEmpty() const{
			return m_pos == 0 || m_t_value == nullptr;
		}
		
		virtual T get(int x) const{
			if(m_t_value == nullptr){
				return T();
			}
			if(x >= m_pos && m_pos > 0){
				return m_t_value[m_pos - 1];
			}
			if(x < m_pos && x >= 0){
				return m_t_value[x];
			}
			return T();
		}
		
		virtual T& operator[](int x){
			if(x > m_pos && m_pos > 0){
				return m_t_value[m_pos - 1];
			}
			if(x < m_pos && x >= 0){
				return m_t_value[x];
			}
			if(x >= m_size){
				expandLocal((x - m_size + 1) + m_expandSize);
			}
			if(m_pos == x){
				m_pos++;
			}
			return m_t_value[x];
		}
		
		virtual T operator[](int x) const{
			if(m_t_value == nullptr){
				return T();
			}
			if(x >= m_pos && m_pos > 0){
				return m_t_value[m_pos - 1];
			}
			if(x < m_pos && x >= 0){
				return m_t_value[x];
			}
			return T();
		}
		
		virtual Array<T> add(const T& a_value){
			Array<T> i_array = *this;
			i_array.addLocal(a_value);
			return i_array;
		}
		
		virtual Array<T> addLocal(const T& a_value){
			if(m_t_value == nullptr){
				m_pos = 1;
				m_size = getAvailableSize(1);
				m_t_value = create(m_size);
				m_t_value[0] = a_value;
				return *this;
			}
			if(m_size - m_pos < 1){
				expandLocal(1 + m_expandSize);
			}
			m_t_value[m_pos] = a_value;
			m_pos++;
			return *this;
		}

		virtual ArrayIterator<T> begin(){
			ArrayLog(ame_Log_StartMethod, "begin", "println", "");
			ArrayLog(ame_Log_EndMethod, "begin", "println", "");
			return ArrayIterator<T>(m_t_value,0);
		}
		virtual ArrayIterator<T> end(){
			ArrayLog(ame_Log_StartMethod, "end", "println", "");
			ArrayLog(ame_Log_EndMethod, "end", "println", "");
			return ArrayIterator<T>(m_t_value, m_pos);
		}

		virtual bool contain(const T& a_value){
			ArrayLog(ame_Log_StartMethod, "contain", "println", "");
			if(m_t_value == nullptr || m_pos == 0){
				return false;
			}
			for(int x = 0; x < m_pos; x++){
				if(m_t_value[x] == a_value){
					return true;
				}
			}
			ArrayLog(ame_Log_EndMethod, "contain", "println", "");
			return false;
		}
		
		virtual int getFirstIndex(const T& a_value){
			ArrayLog(ame_Log_StartMethod, "contain", "println", "");
			for(int x = 0; x < m_pos; x++){
				if(m_t_value[x] == a_value){
					return x;
				}
			}
			return -1;
			ArrayLog(ame_Log_EndMethod, "contain", "println", "");
		}
		
		virtual int getLastIndex(const T& a_value){
			ArrayLog(ame_Log_StartMethod, "contain", "println", "");
			for(int x = m_pos - 1; x >= 0; x--){
				if(m_t_value[x] == a_value){
					return x;
				}
			}
			return -1;
			ArrayLog(ame_Log_EndMethod, "contain", "println", "");
		}

		virtual void remove(int a_index){
			ArrayLog(ame_Log_StartMethod, "removeFirst", "println", "");
			if(a_index == -1 || a_index >= m_pos){
				return;
			}
			int i_pos = m_pos - 1;
			int i_size = getAvailableSize(i_pos);
			T* i_copy = create(i_size);
			int x_count = 0;
			for(int x = 0; x < m_pos; x++){
				if(a_index != x){
					i_copy[x_count] = m_t_value[x];
					x_count++;
				}
			}
			fix();
			erase();
			m_pos = i_pos;
			m_size = i_size;
			m_t_value = i_copy;
			ArrayLog(ame_Log_EndMethod, "removeFirst", "println", "");
		}

		virtual void removeFirst(const T& a_value){
			ArrayLog(ame_Log_StartMethod, "removeFirst", "println", "");
			int index = getFirstIndex(a_value);
			if(index == -1){
				return;
			}
			remove(index);
			ArrayLog(ame_Log_EndMethod, "removeFirst", "println", "");
		}

		virtual void removeLast(const T& a_value){
			ArrayLog(ame_Log_StartMethod, "removeLast", "println", "");
			int index = getLastIndex(a_value);
			if(index == -1){
				return;
			}
			remove(index);
			ArrayLog(ame_Log_EndMethod, "removeLast", "println", "");
		}
/*
		Array<Array<T>> split(const T& divide){
			
		}
		
		Array<T> split(const T& divide, int parte){
			
		}
		
		int splitLenght(const T& divide){
			
		}*/

		Array<T>& operator=(const Array<T>& source){
			ArrayLog(ame_Log_StartMethod, "operator=", "println", "operator= const Array<T>&");
			fix();
			erase();
				
			if(source.isEmpty()){
				ArrayLog(ame_Log_EndMethod, "operator=", "println", "source.isEmpty()");
				return *this;
			}
			m_size = getAvailableSize(source.m_pos);
			m_t_value = create(m_size);
			copy(source.m_t_value, source.m_pos);
			ArrayLog(ame_Log_EndMethod, "operator=", "println", "");
			return *this;
		}
		
		Array<T> operator=(const T& a_value){
			ArrayLog(ame_Log_StartMethod, "operator=", "println", "operator= const T&");
			fix();
			erase();
			m_size = getAvailableSize(1);
			m_t_value = create(m_size);
			copy(a_value);
			//ArrayLog(ame_Log_Statement, "operator=", "println", a_value);
			ArrayLog(ame_Log_EndMethod, "operator=", "println", "");
			return *this;
		}
/*
		Array<T> operator+(const Array<T>& a_value){
			ArrayLog(ame_Log_StartMethod, "operator+", "println", "");
			ArrayLog(ame_Log_Statement, "operator+", "println", "~Array");
			
			ArrayLog(ame_Log_EndMethod, "operator+", "println", "");
			return m_Array;
		}
		
		Array<T> operator+=(const Array<T>& a_value){
			ArrayLog(ame_Log_StartMethod, "operator+=", "println", "");
			ArrayLog(ame_Log_Statement, "operator+=", "println", "~Array");
			
			ArrayLog(ame_Log_EndMethod, "operator+=", "println", "");
			return *this;
		}
		Array<T> operator+(const T& a_value){
			ArrayLog(ame_Log_StartMethod, "operator+", "println", "");
			ArrayLog(ame_Log_Statement, "operator+", "println", "~Array");
			
			ArrayLog(ame_Log_EndMethod, "operator+", "println", "");
			return m_Array;
		}
		
		Array<T> operator+=(const T& a_value){
			ArrayLog(ame_Log_StartMethod, "operator+=", "println", "");
			ArrayLog(ame_Log_Statement, "operator+=", "println", "~Array");
			
			ArrayLog(ame_Log_EndMethod, "operator+=", "println", "");
			return *this;
		}

		bool operator==(const Array<T>& a_value){
			ArrayLog(ame_Log_StartMethod, "operator==", "println", "");
			ArrayLog(ame_Log_Statement, "operator==", "println", "~Array");
			
			ArrayLog(ame_Log_EndMethod, "operator==", "println", "");
			return true;
		}
		bool operator!=(const Array<T>& a_value){
			ArrayLog(ame_Log_StartMethod, "operator!=", "println", "");
			ArrayLog(ame_Log_Statement, "operator!=", "println", "~Array");
			
			ArrayLog(ame_Log_EndMethod, "operator!=", "println", "");
			return false;
		}

		bool operator==(const T& a_value){
			ArrayLog(ame_Log_StartMethod, "operator==", "println", "");
			ArrayLog(ame_Log_Statement, "operator==", "println", "~Array");
			
			ArrayLog(ame_Log_EndMethod, "operator==", "println", "");
			return true;
		}
		bool operator!=(const T& a_value){
			ArrayLog(ame_Log_StartMethod, "operator!=", "println", "");
			ArrayLog(ame_Log_Statement, "operator!=", "println", "~Array");
			
			ArrayLog(ame_Log_EndMethod, "operator!=", "println", "");
			return false;
		}
		
		void replace(Array a_search, Array a_change){
			ArrayLog(ame_Log_StartMethod, "replace", "println", "");
			ArrayLog(ame_Log_Statement, "replace", "println", "");
			Array i_Array;
			Array i_search;
			int i_search_index = 0;
			
			if(isEmpty()){
				return;
			}
			
			ArrayLog(ame_Log_Statement, "replace", "println", "start for");
			for(int x = 0; x < m_pos; x++){
				ArrayLog(ame_Log_Statement, "replace", "println", ame_String("iteration ") + ame_String(x));
				char cr = charAt(x);
				char schr = a_search.charAt(i_search_index);
				ArrayLog(ame_Log_Statement, "replace", "println", ame_String("Arrays char: ") + ame_String((char)cr));
				ArrayLog(ame_Log_Statement, "replace", "println", ame_String("searche char: ") + ame_String((char)schr));
				if(schr == cr){
					ArrayLog(ame_Log_Statement, "replace", "println", "schr == cr");
					i_search_index++;
					i_search += schr;
				}else{
					ArrayLog(ame_Log_Statement, "replace", "println", "schr != cr");
					if(i_search_index > 0){
						ArrayLog(ame_Log_Statement, "replace", "println", "i_search_index > 0");
						i_search_index = 0;
						i_Array += i_search;
						i_search = "";
					}
					i_Array += cr;
				}
				if(i_search_index == a_search.getPosition()){
					ArrayLog(ame_Log_Statement, "replace", "println", "i_search_index == a_search.getPosition() - 1");
					i_search_index = 0;
					i_search = "";
					i_Array += a_change;
				}
			}
			ArrayLog(ame_Log_Statement, "replace", "println", "end for");
			
			fix(m_t_value, m_pos, m_size);
			erase(m_t_value);
			m_t_value = i_Array.m_t_value;
			m_pos = i_Array.m_pos;
			m_size = i_Array.m_size;
			i_Array.m_t_value = nullptr;
			i_Array.m_pos = 0;
			i_Array.m_size = 0;
			return;
		}
*/
		virtual cppObjectClass* getClass(){return Class<Array<T>>::classType;}
		virtual bool instanceof(cppObjectClass* cls){
			return cls == Class<Array<T>>::classType;
		}
	
		virtual bool equal(cppObject *obj){
			if(obj == nullptr){
				return false;
			}
			if(!obj->instanceof(getClass())){
				return false;
			}
			Array<T>* e_array = (Array<T>*)obj;
			if(e_array->getPosition() != this->getPosition()){
				return false;
			}
			for(int x = 0; x < this->getPosition(); x++){
				if(e_array->get(x) != this->get(x)){
					return false;
				}
			}
			return true;
		}
		
		virtual bool copy(cppObject* obj){
			if(obj == nullptr){
				return false;
			}
			if(!obj->instanceof(getClass())){
				return false;
			}
			Array<T>* source = (Array<T>*)obj;
			fix();
			erase();
			if(source->isEmpty()){
				ArrayLog(ame_Log_EndMethod, "operator=", "println", "source.isEmpty()");
				return true;
			}
			m_size = getAvailableSize(source->m_pos);
			m_t_value = create(m_size);
			copy(source->m_t_value, source->m_pos);
			return true;
		}
		
		virtual bool move(cppObject* obj){
			if(obj == nullptr){
				return false;
			}
			if(!obj->instanceof(getClass())){
				return false;
			}
			Array<T>* source = (Array<T>*)obj;
			fix();
			erase();
			if(source->isEmpty()){
				ArrayLog(ame_Log_EndMethod, "operator=", "println", "source.isEmpty()");
				return true;
			}
			m_pos = source->m_pos;
			m_size = source->m_size;
			m_t_value = source->m_t_value;
			source->m_t_value = nullptr;
			source->m_pos = 0;
			source->m_size = 0;
			return true;
		}
		
		virtual Array<T>* clone(){
			Array<T>* array = new Array<T>(*this);
			array->copy(this);
			return array;
		}
};

}

#endif

	






