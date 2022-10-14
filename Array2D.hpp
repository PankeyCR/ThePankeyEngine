
#include "ame_Enviroment.hpp"

#ifndef Array2D_hpp
#define Array2D_hpp
#define Array2D_AVAILABLE

#ifndef ame_Enviroment_Defined

#endif

#ifdef ame_Windows

#endif

#ifdef ame_ArduinoIDE
	#include "Arduino.h"
	
#endif

#include "Array2DIterator.hpp"

#include "Memory.hpp"

#include "cppObject.hpp"

#include "RawList.hpp"
#include "PrimitiveRawList.hpp"
#include "RawMap.hpp"
#include "PrimitiveRawMap.hpp"

#ifdef Array2D_LogApp
	#include "ame_Logger_config.hpp"
	#include "ame_Logger.hpp"
	
	#define Array2DLog(location,method,type,mns) ame_Log((void*)this,location,"Array2D",method,type,mns)
	#define const_Array2DLog(location,method,type,mns) 
	#define StaticArray2DLog(pointer,location,method,type,mns) ame_Log(pointer,location,"Array2D",method,type,mns)
#else
	#ifdef Array2D_LogDebugApp
		#include "ame_Logger_config.hpp"
		#include "ame_Logger.hpp"
		
		#define Array2DLog(location,method,type,mns) ame_LogDebug((void*)this,location,"Array2D",method,type)
		#define const_Array2DLog(location,method,type,mns) 
		#define StaticArray2DLog(pointer,location,method,type,mns) ame_LogDebug(pointer,location,"Array2D",method,type)
	#else
		#define Array2DLog(location,method,type,mns) 
		#define const_Array2DLog(location,method,type,mns) 
		#define StaticArray2DLog(pointer,location,method,type,mns) 
	#endif
#endif


namespace ame{
	
template<class T>
class Array2D : public Printable, public cppObject{

	protected:
		T** m_t_value = nullptr;
		
		int m_size_X = 0;
		int m_size_Y = 0;
		
		virtual T** create(int a_size_x, int a_size_y){
			T** a = new T*[a_size_y];
			for(int i = 0; i < a_size_y; ++i){
				a[i] = new T[a_size_x];
			}
			return a;
		}

    public:
		Array2D(){
			Array2DLog(ame_Log_StartMethod, "Constructor", "println", "");
			Array2DLog(ame_Log_Statement, "Constructor", "println", "Default Constructor");
			Array2DLog(ame_Log_EndMethod, "Constructor", "println", "");
		}

		Array2D(int c_x, int c_y){
			Array2DLog(ame_Log_StartMethod, "Constructor", "println", "");
			if(c_x > 0 || c_y > 0){
				m_size_X = c_x;
				m_size_Y = c_y;
				m_t_value = create(m_size_X, m_size_Y);
				Array2DLog(ame_Log_Statement, "Constructor", "println", p_size);
			}
			Array2DLog(ame_Log_EndMethod, "Constructor", "println", "");
		}

		Array2D(const Array2D<T>& source){
			Array2DLog(ame_Log_StartMethod, "Constructor", "println", "");
			Array2DLog(ame_Log_Statement, "Constructor", "println", "const Array2D& val");
			m_size_X = source.getSizeX();
			m_size_Y = source.getSizeY();
			if(m_size_X > 0 && m_size_Y > 0){
				Array2DLog(ame_Log_Statement, "Constructor", "println", "copy");
				m_t_value = create(m_size_X, m_size_Y);
				copy(source.m_t_value, m_size_X, m_size_Y);
			}
			Array2DLog(ame_Log_EndMethod, "Constructor", "println", "");
		}

		Array2D(Array2D&& source){
			Array2DLog(ame_Log_StartMethod, "Constructor", "println", "start");
			Array2DLog(ame_Log_Statement, "Constructor", "println", "Array2D&& source");
			m_size_X = source.getSizeX();
			m_size_Y = source.getSizeY();
			if(m_size_X > 0 && m_size_Y > 0){
				m_size_X = source.m_size_X;
				m_size_Y = source.m_size_Y;
				m_t_value = source.m_t_value;
				source.m_t_value = nullptr;
				source.m_size_X = 0;
				source.m_size_Y = 0;
				Array2DLog(ame_Log_Statement, "Constructor", "println", m_pos);
				Array2DLog(ame_Log_Statement, "Constructor", "println", m_size);
			}
			Array2DLog(ame_Log_EndMethod, "Constructor", "println", "");
		}

		virtual ~Array2D(){
			Array2DLog(ame_Log_StartMethod, "Destructor", "println", "");
			Array2DLog(ame_Log_Statement, "Destructor", "println", "~Array2D");
			Array2DLog(ame_Log_Statement, "Destructor", "println", m_pos);
			Array2DLog(ame_Log_Statement, "Destructor", "println", m_size);
			fix();
			erase();
			Array2DLog(ame_Log_EndMethod, "Destructor", "println", "");
		}

		virtual size_t printTo(Print& p) const{
			if(isEmpty()){
				return 0;
			}
			size_t i_size = 0;
			for(int y = 0; y < m_size_Y; y++){
				for(int x = 0; x < m_size_X; x++){
					i_size += p.print(m_t_value[y][x]);
				}
			}
			return i_size;
		}

		virtual void createArray(int c_x, int c_y){
			Array2DLog(ame_Log_StartMethod, "Constructor", "println", "");
			fix();
			erase();
			if(c_x > 0 || c_y > 0){
				m_size_X = c_x;
				m_size_Y = c_y;
				m_t_value = create(m_size_X, m_size_Y);
				Array2DLog(ame_Log_Statement, "Constructor", "println", p_size);
			}
			Array2DLog(ame_Log_EndMethod, "Constructor", "println", "");
		}
		
		virtual void fix(){
			
		}
		
		virtual void erase(){
			if(m_t_value == nullptr){
				m_size_X = 0;
				m_size_Y = 0;
				return;
			}
			for(int i = 0; i < m_size_Y; ++i) {
				delete [] m_t_value[i];
			}
			delete [] m_t_value;
			m_t_value = nullptr;
			m_size_X = 0;
			m_size_Y = 0;
		}
		
		virtual void fill(T a_fill){
			if(m_t_value == nullptr){
				return;
			}
			for(int y = 0; y < m_size_Y; y++){
				for(int x = 0; x < m_size_X; x++){
					m_t_value[y][x] = a_fill;
				}
			}
		}
		
		virtual void copy(T** a_copy, int a_size_x, int a_size_y){
			if(m_t_value == nullptr || a_copy == nullptr ){
				return;
			}
			if(a_size_x > m_size_X || a_size_y > m_size_Y){
				return;
			}
			for(int y = 0; y < a_size_y; y++){
				for(int x = 0; x < a_size_x; x++){
					m_t_value[y][x] = a_copy[y][x];
				}
			}
		}

		virtual T** pointer(){
			Array2DLog(ame_Log_StartMethod, "pointer", "println", "");
			Array2DLog(ame_Log_EndMethod, "pointer", "println", "");
			return m_t_value;
		}

		virtual int length() const{
			return m_size_X * m_size_Y;
		}

		virtual int getSizeX() const{
			return m_size_X;
		}

		virtual int getSizeY() const{
			return m_size_Y;
		}

		virtual bool isEmpty() const{
			return m_size_X == 0 || m_size_Y == 0 || m_t_value == nullptr;
		}
		
		virtual T get(int x, int y) const{
			if(m_t_value == nullptr){
				return T();
			}
			if(x >= m_size_X || y >= m_size_Y){
				return T();
			}
			return m_t_value[y][x];
		}
		
		virtual void set(int x, int y, T a_value){
			if(m_t_value == nullptr){
				return;
			}
			if(x >= m_size_X || y >= m_size_Y){
				return;
			}
			m_t_value[y][x] = a_value;
		}

		virtual Array2DIterator<T> begin(){
			Array2DLog(ame_Log_StartMethod, "begin", "println", "");
			Array2DLog(ame_Log_EndMethod, "begin", "println", "");
			return Array2DIterator<T>(m_t_value,0,0,m_size_X,m_size_Y);
		}
		virtual Array2DIterator<T> end(){
			Array2DLog(ame_Log_StartMethod, "end", "println", "");
			Array2DLog(ame_Log_EndMethod, "end", "println", "");
			return Array2DIterator<T>(m_t_value,m_size_X,m_size_Y,m_size_X,m_size_Y);
		}

		virtual bool contain(const T& a_value){
			Array2DLog(ame_Log_StartMethod, "contain", "println", "");
			if(m_t_value == nullptr || m_size_X == 0 || m_size_Y == 0){
				return false;
			}
			for(int y = 0; y < m_size_X; y++){
				for(int x = 0; x < m_size_X; x++){
					if(m_t_value[y][x] == a_value){
						return true;
					}
				}
			}
			Array2DLog(ame_Log_EndMethod, "contain", "println", "");
			return false;
		}

		Array2D<T>& operator=(const Array2D<T>& source){
			Array2DLog(ame_Log_StartMethod, "operator=", "println", "operator= const Array2D<T>&");
			fix();
			erase();
				
			if(source.isEmpty()){
				Array2DLog(ame_Log_EndMethod, "operator=", "println", "source.isEmpty()");
				return *this;
			}
			m_size_X = source.getSizeX();
			m_size_Y = source.getSizeY();
			m_t_value = create(m_size_X,m_size_Y);
			copy(source.m_t_value, source.m_size_X,source.m_size_Y);
			Array2DLog(ame_Log_EndMethod, "operator=", "println", "");
			return *this;
		}
		
		
		virtual cppObjectClass* getClass(){return Class<Array2D<T>>::classType;}
		virtual bool instanceof(cppObjectClass* cls){
			return cls == Class<Array2D<T>>::classType;
		}
	
		virtual bool equal(cppObject *obj){
			if(obj == nullptr){
				return false;
			}
			if(!obj->instanceof(getClass())){
				return false;
			}
			Array2D<T>* e_Array2D = (Array2D<T>*)obj;
			if(e_Array2D->getSizeX() != this->getSizeX() || e_Array2D->getSizeY() != this->getSizeY()){
				return false;
			}
			for(int y = 0; y < m_size_X; y++){
				for(int x = 0; x < m_size_X; x++){
					if(m_t_value[y][x] != e_Array2D->m_t_value[y][x]){
						return false;
					}
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
			Array2D<T>* source = (Array2D<T>*)obj;
			fix();
			erase();
			if(source->isEmpty()){
				Array2DLog(ame_Log_EndMethod, "copy", "println", "source.isEmpty()");
				return true;
			}
			m_size_X = source->getSizeX();
			m_size_Y = source->getSizeY();
			if(m_size_X > 0 && m_size_Y > 0){
				Array2DLog(ame_Log_Statement, "copy", "println", "copy");
				m_t_value = create(m_size_X, m_size_Y);
				copy(source->m_t_value, m_size_X, m_size_Y);
			}
			return true;
		}
		
		virtual bool move(cppObject* obj){
			if(obj == nullptr){
				return false;
			}
			if(!obj->instanceof(getClass())){
				return false;
			}
			Array2D<T>* source = (Array2D<T>*)obj;
			fix();
			erase();
			if(source->isEmpty()){
				Array2DLog(ame_Log_EndMethod, "operator=", "println", "source.isEmpty()");
				return true;
			}
			m_size_X = source->m_size_X;
			m_size_Y = source->m_size_Y;
			m_t_value = source->m_t_value;
			source->m_t_value = nullptr;
			source->m_size_X = 0;
			source->m_size_Y = 0;
			return true;
		}
		
		virtual Array2D<T>* clone(){
			Array2D<T>* i_array = new Array2D<T>(this->getSizeX(), this->getSizeY());
			i_array->copy(this->m_t_value, this->getSizeX(), this->getSizeY());
			return i_array;
		}
};

}

#endif

	






