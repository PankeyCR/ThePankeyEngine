
#ifndef cppObjectList_hpp
#define cppObjectList_hpp
#define cppObjectList_AVAILABLE

#include "PrimitiveList.hpp"

#ifdef cppObjectList_LogApp
	#include "ame_Logger_config.hpp"
	#include "ame_Logger.hpp"
	
	#define cppObjectListLog(location,method,type,mns) ame_Log(this,location,"cppObjectList",method,type,mns)
#else
	#ifdef PrimitiveList_LogDebugApp
		#include "ame_Logger_config.hpp"
		#include "ame_Logger.hpp"
		
		#define cppObjectListLog(location,method,type,mns) ame_LogDebug(this,location,"cppObjectList",method,type)
	#else
		#define cppObjectListLog(location,method,type,mns)  
	#endif
#endif

namespace ame{

template<class T>
class cppObjectList : public PrimitiveList<T>{
	public:
		
		cppObjectList() : PrimitiveList<T>(){}
		
		cppObjectList(int c_size) : PrimitiveList<T>(c_size){}
		
		cppObjectList(int c_size, bool c_own, int c_reordering) : PrimitiveList<T>(c_size, c_own, c_reordering){}
		
		cppObjectList(int c_size, bool c_own, int c_reordering, bool c_obj_add) : PrimitiveList<T>(c_size, c_own, c_reordering){
			m_obj_adding = c_obj_add;
		}
		
		virtual ~cppObjectList(){}
		
		virtual T* addPointer(T* a_value){
			cppObjectListLog(ame_Log_StartMethod, "addPointer", "println", "");
			if(this->m_values == nullptr){
				this->expandLocal(this->m_expandSize);
			}
			if(this->getPosition() >= this->getSize()){
				this->expandLocal(this->m_expandSize);
			}
			if(this->getPosition() >= this->getSize()){
				return nullptr;
			}
			this->m_values[this->getPosition()] = a_value;
			this->incrementPosition();
			this->addObjectTo(a_value);
			cppObjectListLog(ame_Log_EndMethod, "addPointer", "println", "");
			return this->m_values[this->getPosition()-1];
		}
		
		virtual T* addLValue(T a_value){
			cppObjectListLog(ame_Log_StartMethod, "addLValue", "println", "");
			if(this->m_values == nullptr){
				this->expandLocal(this->m_expandSize);
			}
			if(this->getPosition() >= this->getSize()){
				this->expandLocal(this->m_expandSize);
			}
			if(this->getPosition() >= this->getSize()){
				return nullptr;
			}
			this->m_values[this->getPosition()] = new T();
			*this->m_values[this->getPosition()] = a_value;
			this->incrementPosition();
			this->m_values[this->getPosition()]->addObject();
			addObjectTo(this->m_values[this->getPosition()]);
			cppObjectListLog(ame_Log_EndMethod, "addLValue", "println", "");
			return this->m_values[this->getPosition()-1];
		}
		
		virtual T* setLValue(int a_position, T a_value){
			cppObjectListLog(ame_Log_StartMethod, "setLValue", "println", "");
			if(a_position >= this->getPosition()){
				return nullptr;			
			}
			if(this->m_values[a_position] == nullptr){
				this->m_values[a_position] = new T();
				addObjectTo(this->m_values[a_position]);
			}
			*this->m_values[a_position] = a_value;
			cppObjectListLog(ame_Log_EndMethod, "setLValue", "println", "");
			return this->m_values[a_position];
		}
		
		virtual T* setPointer(int a_position, T* a_value){
			cppObjectListLog(ame_Log_StartMethod, "setPointer", "println", "");
			if(a_position >= this->getPosition()){
				return nullptr;			
			}
			if(a_value == nullptr){
				return nullptr;
			}
			if(this->m_values[a_position] != nullptr && this->m_values[a_position] != a_value && this->m_owner){
				delete this->m_values[a_position];
			}
			this->m_values[a_position] = a_value;
			this->addObjectTo(a_value);
			cppObjectListLog(ame_Log_EndMethod, "setPointer", "println", "");
			return a_value;
		}
		
		virtual T* insertLValue(int a_position, T a_value){
			cppObjectListLog(ame_Log_StartMethod, "insertLValue", "println", "");
            if(a_position >= this->getPosition() + 1){
				return nullptr;
            }
			if(this->getSize() == this->getPosition()){
				this->expandLocal(this->m_expandSize);
			}
			T* nValue;
			T* rValue = new T();
			addObjectTo(rValue);
			*rValue = a_value;
			for(int x = a_position; x <= this->getPosition(); x++){
				nValue = this->m_values[x];
				this->m_values[x] = rValue;
				rValue = nValue;
			}
			this->incrementPosition();
			cppObjectListLog(ame_Log_EndMethod, "insertLValue", "println", "");
			return this->m_values[a_position];
		}
		
		virtual T* insertPointer(int a_position, T* a_value){
			cppObjectListLog(ame_Log_StartMethod, "insertPointer", "println", "");
            if(this->m_values[a_position] == a_value){
				return a_value;
            }
            if(a_position >= this->getPosition()+1){
				return nullptr;
            }
			if(this->getSize() == this->getPosition()){
				this->expandLocal(this->m_expandSize);
			}
			T* nVaule;
			T* rVaule = a_value;
			this->addObjectTo(a_value);
			for(int x = a_position; x <= this->getPosition(); x++){
				nVaule = this->m_values[x];
				this->m_values[x] = rVaule;
				rVaule = nVaule;
			}
			this->incrementPosition();
			cppObjectListLog(ame_Log_EndMethod, "insertPointer", "println", "");
			return this->m_values[a_position];
		}
		
		virtual T* removeByPosition(int a_position){
			cppObjectListLog(ame_Log_StartMethod, "removeByPosition", "println", "");
			if(a_position >= this->getPosition() || this->m_values == nullptr){
				return nullptr;
			}
			T* i_value = this->m_values[a_position];
			this->m_values[a_position] = nullptr;
			int i_iteration = this->getPosition();
			removeObjectTo(i_value);
			this->decrementPosition();
			if(this->getPosition() < 0){
				this->setPosition(0);
			}
			if(!this->m_reorder){
				return i_value;
			}
			for(int x = a_position + 1; x < i_iteration; x++){
				this->m_values[x - 1] = this->m_values[x];
			}
			cppObjectListLog(ame_Log_EndMethod, "removeByPosition", "println", "");
			return i_value;
		}

		virtual cppObjectList<T>* clone(){
			cppObjectListLog(ame_Log_StartMethod, "clone", "println", "");
			cppObjectList<T>* list = new cppObjectList<T>(this->getSize());
			for(int xl = 0; xl < this->getPosition(); xl++){
				T* i_obj = this->m_values[xl];
				list->addPointer(i_obj->clone());
			}
			cppObjectListLog(ame_Log_EndMethod, "clone", "println", "");
			return list;
		}

		virtual cppObjectList<T>* clone(bool owningMemory){
			cppObjectListLog(ame_Log_StartMethod, "clone", "println", "");
			cppObjectList<T>* list = new cppObjectList<T>(this->getSize(), owningMemory, this->m_reorder, this->m_obj_adding);
			for(int xl = 0; xl < this->getPosition(); xl++){
				T* i_obj = this->m_values[xl];
				list->addPointer(i_obj->clone());
			}
			cppObjectListLog(ame_Log_EndMethod, "clone", "println", "");
			return list;
		}
	
		////////////////////////////////////////////special removes part///////////////////////////////////////////////
		virtual bool removeAll(T a_value){
			cppObjectListLog(ame_Log_StartMethod, "removeAll", "println", "");
			bool r_val = false;
			int p_x = 0;
			for(int x = 0; x < this->getPosition(); x++){
				T* i_obj = this->m_values[x];
				if(a_value == *i_obj){
					if(this->m_owner){
						delete i_obj;
					}
					r_val = true;
					removeObjectTo(i_obj);
				}else{
					this->m_values[p_x] = i_obj;
					p_x++;
				}
			}
			this->setPosition(p_x);
			cppObjectListLog(ame_Log_EndMethod, "removeAll", "println", "");
			return r_val;
		}
		
		virtual bool removeFirst(T a_value){
			cppObjectListLog(ame_Log_StartMethod, "removeFirst", "println", "");
			bool r_val = false;
			bool r_once = true;
			int p_x = 0;
			for(int x = 0; x < this->getPosition(); x++){
				T* i_obj = this->m_values[x];
				if(a_value == *i_obj && r_once){
					if(this->m_owner){
						delete i_obj;
					}
					r_once = false;
					r_val = true;
					removeObjectTo(i_obj);
				}else{
					this->m_values[p_x] = i_obj;
					p_x++;
				}
			}
			this->setPosition(p_x);
			cppObjectListLog(ame_Log_EndMethod, "removeFirst", "println", "");
			return r_val;
		}
		
		virtual bool removeLast(T a_value){
			cppObjectListLog(ame_Log_StartMethod, "removeLast", "println", "");
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
				T* i_obj = this->m_values[x];
				if(a_value == *i_obj && r_once){
					if(this->m_owner){
						delete i_obj;
					}
					r_once = false;
					r_val = true;
					removeObjectTo(i_obj);
				}else{
					this->m_values[p_x] = i_obj;
					p_x++;
				}
			}
			this->setPosition(p_x);
			cppObjectListLog(ame_Log_EndMethod, "removeLast", "println", "");
			return r_val;
		}
	protected:
		void addObjectTo(cppObject* a_obj){
			if(m_obj_adding && a_obj != nullptr){
				a_obj->addObject();
			}
		}
		void removeObjectTo(cppObject* a_obj){
			if(m_obj_adding && a_obj != nullptr){
				a_obj->removeObject();
			}
		}
		bool m_obj_adding = true;
};

}

#endif