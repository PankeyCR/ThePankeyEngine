
#ifndef MemberArrayMapCollection_hpp
	#define MemberArrayMapCollection_hpp

	#include "Collection.hpp"
	#include "MemberArrayStorage.hpp"
	#include "DuoMember.hpp"
	#include "Member.hpp"

	#ifdef MemberArrayMapCollection_LogApp
		#include "pankey_Logger.hpp"
		#define MemberArrayMapCollectionLog(location,method,type,mns) pankey_Log((void*)this,location,"MemberArrayMapCollection",method,type,mns)
	#else
		#define MemberArrayMapCollectionLog(location,method,type,mns)
	#endif

	namespace pankey{

		template<class H, class M>
		class MemberArrayMapCollection : public Collection<H,M>{
			public:
				MemberArrayMapCollection(){
					MemberArrayMapCollectionLog(pankey_Log_StartMethod, "Constructor", "println", "");
					MemberArrayMapCollectionLog(pankey_Log_EndMethod, "Constructor", "println", "");
				}

				virtual ~MemberArrayMapCollection(){
					MemberArrayMapCollectionLog(pankey_Log_StartMethod, "Destructor", "println", "");
					MemberArrayMapCollectionLog(pankey_Log_EndMethod, "Destructor", "println", "");
				}
				
				virtual bool isEmpty()const{
					MemberArrayMapCollectionLog(pankey_Log_StartMethod, "isEmpty", "println", "");
					MemberArrayMapCollectionLog(pankey_Log_EndMethod, "isEmpty", "println", "");
					return this->m_keys.isNull() || this->m_keys.getSize() <= 0 || this->m_length <= 0;
				}

				virtual int length()const{
					MemberArrayMapCollectionLog(pankey_Log_StartMethod, "length", "println", "");
					MemberArrayMapCollectionLog(pankey_Log_EndMethod, "length", "println", "");
					return this->m_length;
				}
				
				virtual int getSize()const{
					MemberArrayMapCollectionLog(pankey_Log_StartMethod, "getSize", "println", "");
					MemberArrayMapCollectionLog(pankey_Log_EndMethod, "getSize", "println", "");
					return this->m_keys.getSize();
				}

				virtual bool replace(int a_index_1, int a_index_2){
					MemberArrayMapCollectionLog(pankey_Log_StartMethod, "replace", "println", "");
					bool i_key_r = this->m_keys.replace(a_index_1, a_index_2);
					bool i_value_r = this->m_values.replace(a_index_1, a_index_2);
					MemberArrayMapCollectionLog(pankey_Log_EndMethod, "replace", "println", "");
					return i_key_r && i_value_r;
				}

				virtual Member<H,M> get(const Member<H,M>& a_value)const{
					MemberArrayMapCollectionLog(pankey_Log_StartMethod, "get", "println", "");
					int i_index = this->m_keys.getIndex(a_value);
					if(i_index == -1){
						MemberArrayMapCollectionLog(pankey_Log_Statement, "get", "println", "i_index == -1");
						return Member<H,M>();
					}
					MemberArrayMapCollectionLog(pankey_Log_EndMethod, "get", "println", "");
					return this->m_values.get(i_index);
				}

				virtual Member<H,M> get(int x)const{
					MemberArrayMapCollectionLog(pankey_Log_StartMethod, "get", "println", "");
					MemberArrayMapCollectionLog(pankey_Log_EndMethod, "get", "println", "");
					return this->m_values.get(x);
				}

				virtual bool contain(const Member<H,M>& a_value)const{
					MemberArrayMapCollectionLog(pankey_Log_StartMethod, "contain", "println", "");
					MemberArrayMapCollectionLog(pankey_Log_EndMethod, "contain", "println", "");
					return this->m_keys.contain(a_value) || this->m_values.contain(a_value);
				}
				
				virtual int getIndex(const Member<H,M>& a_value)const{
					MemberArrayMapCollectionLog(pankey_Log_StartMethod, "getIndex", "println", "");
					int i_index = this->m_keys.getIndex(a_value);
					if(i_index == -1){
						MemberArrayMapCollectionLog(pankey_Log_Statement, "getIndex", "println", "i_index == -1");
						return this->m_values.getIndex(a_value);
					}
					MemberArrayMapCollectionLog(pankey_Log_EndMethod, "getIndex", "println", "");
					return i_index;
				}
				
				virtual bool remove(const Member<H,M>& a_value){
					MemberArrayMapCollectionLog(pankey_Log_StartMethod, "remove", "println", "");
					int i_index = this->m_keys.getIndex(a_value);
					if(i_index == -1){
						MemberArrayMapCollectionLog(pankey_Log_EndMethod, "remove", "println", "");
						return false;
					}
					MemberArrayMapCollectionLog(pankey_Log_Statement, "remove", "println", "index that is been removed:");
					MemberArrayMapCollectionLog(pankey_Log_Statement, "remove", "println", i_index);
					this->m_keys.removeByIndex(i_index);
					this->m_values.removeByIndex(i_index);
					this->m_keys.reorder(i_index, this->length());
					this->m_values.reorder(i_index, this->length());
					this->decrementPosition();
					MemberArrayMapCollectionLog(pankey_Log_EndMethod, "remove", "println", "");
					return true;
				}
				
				virtual Member<H,M> remove(int a_index){
					MemberArrayMapCollectionLog(pankey_Log_StartMethod, "remove", "println", "");
					if(a_index < 0 || this->isEmpty() || a_index >= this->length()){
						MemberArrayMapCollectionLog(pankey_Log_EndMethod, "remove", "println", "");
						return Member<H,M>();
					}
					Member<H,M> i_key_pointer = this->m_keys.removeByIndex(a_index);
					Member<H,M> i_value_pointer = this->m_values.removeByIndex(a_index);
					this->m_keys.reorder(a_index, this->length());
					this->m_values.reorder(a_index, this->length());
					this->decrementPosition();
					MemberArrayMapCollectionLog(pankey_Log_EndMethod, "remove", "println", "");
					return i_value_pointer;
					// return DuoMember<H,M>(i_key_pointer, i_value_pointer);
				}
				
				virtual bool removeFirstIndex(int a_amount){
					MemberArrayMapCollectionLog(pankey_Log_StartMethod, "removeFirstIndex", "println", "");
					bool i_key_remove = this->m_keys.removeFirstIndex(this->m_length, a_amount);
					bool i_value_remove = this->m_values.removeFirstIndex(this->m_length, a_amount);
					if(i_key_remove && i_key_remove){
						MemberArrayMapCollectionLog(pankey_Log_Statement, "removeFirstIndex", "println", "i_key_remove && i_key_remove");
						this->m_keys.reorder(0, this->length(), a_amount);
						this->m_values.reorder(0, this->length(), a_amount);
						this->decrementPosition(a_amount);
						MemberArrayMapCollectionLog(pankey_Log_EndMethod, "removeFirstIndex", "println", "");
						return true;
					}
					MemberArrayMapCollectionLog(pankey_Log_EndMethod, "removeFirstIndex", "println", "");
					return false;
				}

				virtual bool removeLastIndex(int a_amount){
					MemberArrayMapCollectionLog(pankey_Log_StartMethod, "removeLastIndex", "println", "");
					bool i_key_remove = this->m_keys.removeLastIndex(this->m_length, a_amount);
					bool i_value_remove = this->m_values.removeLastIndex(this->m_length, a_amount);
					if(i_key_remove && i_key_remove){
						MemberArrayMapCollectionLog(pankey_Log_Statement, "removeLastIndex", "println", "i_key_remove && i_key_remove");
						this->decrementPosition(a_amount);
						MemberArrayMapCollectionLog(pankey_Log_EndMethod, "removeLastIndex", "println", "");
						return true;
					}
					MemberArrayMapCollectionLog(pankey_Log_EndMethod, "removeLastIndex", "println", "");
					return false;
				}

				virtual bool removePart(int a_index, int a_amount){
					MemberArrayMapCollectionLog(pankey_Log_StartMethod, "removePart", "println", "");
					bool i_key_remove = this->m_keys.removePart(a_index, this->m_length, a_amount);
					bool i_value_remove = this->m_values.removePart(a_index, this->m_length, a_amount);
					if(i_key_remove && i_key_remove){
						MemberArrayMapCollectionLog(pankey_Log_Statement, "removePart", "println", "i_key_remove && i_key_remove");
						this->m_keys.reorder(a_index, this->length(), a_amount);
						this->m_values.reorder(a_index, this->length(), a_amount);
						this->decrementPosition(a_amount);
						MemberArrayMapCollectionLog(pankey_Log_EndMethod, "removePart", "println", "");
						return true;
					}
					MemberArrayMapCollectionLog(pankey_Log_EndMethod, "removePart", "println", "");
					return false;
				}
				
				virtual bool removeFirst(){
					MemberArrayMapCollectionLog(pankey_Log_StartMethod, "removeFirst", "println", "");
					if(this->isEmpty()){
						MemberArrayMapCollectionLog(pankey_Log_EndMethod, "removeFirst", "println", "");
						return false;
					}
					bool i_key_remove = this->m_keys.removeFirst();
					bool i_value_remove = this->m_values.removeFirst();
					if(i_key_remove && i_key_remove){
						MemberArrayMapCollectionLog(pankey_Log_Statement, "removeFirst", "println", "i_key_remove && i_key_remove");
						this->m_keys.reorder(0, this->length());
						this->m_values.reorder(0, this->length());
						this->decrementPosition();
						MemberArrayMapCollectionLog(pankey_Log_EndMethod, "removeFirst", "println", "true");
						return true;
					}
					MemberArrayMapCollectionLog(pankey_Log_EndMethod, "removeFirst", "println", "false");
					return false;
				}

				virtual bool removeLast(){
					MemberArrayMapCollectionLog(pankey_Log_StartMethod, "removeLast", "println", "");
					if(this->isEmpty()){
						MemberArrayMapCollectionLog(pankey_Log_EndMethod, "removeLast", "println", "");
						return false;
					}
					Member<H,M> i_key_pointer = this->m_keys.removeByIndex(this->length() - 1);
					Member<H,M> i_value_pointer = this->m_values.removeByIndex(this->length() - 1);
					this->m_keys.reorder(this->length() - 1, this->length());
					this->m_values.reorder(this->length() - 1, this->length());
					this->decrementPosition();
					MemberArrayMapCollectionLog(pankey_Log_EndMethod, "removeLast", "println", "");
					return true;
				}
				
				virtual bool clear(){
					MemberArrayMapCollectionLog(pankey_Log_StartMethod, "clear", "println", "");
					this->m_length = 0;
					bool i_key_clear = this->m_keys.clear();
					bool i_value_clear = this->m_values.clear();
					if(i_key_clear && i_value_clear){
						this->m_length = 0;
						MemberArrayMapCollectionLog(pankey_Log_EndMethod, "clear", "println", "");
						return true;
					}
					MemberArrayMapCollectionLog(pankey_Log_EndMethod, "clear", "println", "");
					return false;
				}

				virtual bool isInOrder()const{
					MemberArrayMapCollectionLog(pankey_Log_StartMethod, "isInOrder", "println", "");
					MemberArrayMapCollectionLog(pankey_Log_EndMethod, "isInOrder", "println", "");
					return this->m_reorder;
				}

				virtual void setReorder(bool a_reorder){
					MemberArrayMapCollectionLog(pankey_Log_StartMethod, "setReorder", "println", "");
					if(a_reorder != this->m_reorder){
						MemberArrayMapCollectionLog(pankey_Log_EndMethod, "setReorder", "println", "");
						return;
					}
					this->m_reorder = a_reorder;
					reorder();
					MemberArrayMapCollectionLog(pankey_Log_EndMethod, "setReorder", "println", "");
				}
				
				virtual void reorder(){
					MemberArrayMapCollectionLog(pankey_Log_StartMethod, "reorder", "println", "");
					if(!this->m_reorder){
						MemberArrayMapCollectionLog(pankey_Log_Statement, "reorder", "println", "this->m_reorder || this->m_values == nullptr");
						return;
					}
					this->m_keys.reorder();
					this->m_values.reorder();
					MemberArrayMapCollectionLog(pankey_Log_EndMethod, "reorder", "println", "");
				}
				
				virtual void move(MemberArrayMapCollection<H,M>& a_MemberArrayMapCollection){
					MemberArrayMapCollectionLog(pankey_Log_StartMethod, "move", "println", "");
					MemberArrayMapCollectionLog(pankey_Log_EndMethod, "move", "println", "");
				}
				
				virtual void duplicate(const MemberArrayMapCollection<H,M>& a_MemberArrayMapCollection){
					MemberArrayMapCollectionLog(pankey_Log_StartMethod, "duplicate", "println", "");
					MemberArrayMapCollectionLog(pankey_Log_EndMethod, "duplicate", "println", "");
				}
				
			protected:
				
				virtual void incrementPosition(){
					MemberArrayMapCollectionLog(pankey_Log_StartMethod, "incrementPosition", "println", "");
					this->m_length++;
					MemberArrayMapCollectionLog(pankey_Log_EndMethod, "incrementPosition", "println", "");
				}
				virtual void decrementPosition(){
					MemberArrayMapCollectionLog(pankey_Log_StartMethod, "decrementPosition", "println", "");
					this->m_length--;
					if(this->m_length < 0){
						this->m_length = 0;
					}
					MemberArrayMapCollectionLog(pankey_Log_EndMethod, "decrementPosition", "println", "");
				}
				
				virtual void incrementPosition(int a_size){
					MemberArrayMapCollectionLog(pankey_Log_StartMethod, "incrementPosition", "println", "");
					this->m_length += a_size;
					MemberArrayMapCollectionLog(pankey_Log_EndMethod, "incrementPosition", "println", "");
				}
				virtual void decrementPosition(int a_size){
					MemberArrayMapCollectionLog(pankey_Log_StartMethod, "decrementPosition", "println", "");
					this->m_length -= a_size;
					if(this->m_length < 0){
						this->m_length = 0;
					}
					MemberArrayMapCollectionLog(pankey_Log_EndMethod, "decrementPosition", "println", "");
				}

			public:
			
				virtual bool operator<(int x) const{
					MemberArrayMapCollectionLog(pankey_Log_StartMethod, "operator<", "println", "");
					MemberArrayMapCollectionLog(pankey_Log_EndMethod, "operator<", "println", "");
					return this->length() < x;
				}
				
				virtual bool operator>(int x) const{
					MemberArrayMapCollectionLog(pankey_Log_StartMethod, "operator>", "println", "");
					MemberArrayMapCollectionLog(pankey_Log_EndMethod, "operator>", "println", "");
					return this->length() > x;
				}
				
				virtual bool operator<=(int x) const{
					MemberArrayMapCollectionLog(pankey_Log_StartMethod, "operator<=", "println", "");
					MemberArrayMapCollectionLog(pankey_Log_EndMethod, "operator<=", "println", "");
					return this->length() <= x;
				}
				
				virtual bool operator>=(int x) const{
					MemberArrayMapCollectionLog(pankey_Log_StartMethod, "operator>=", "println", "");
					MemberArrayMapCollectionLog(pankey_Log_EndMethod, "operator>=", "println", "");
					return this->length() >= x;
				}
				
				virtual bool operator==(int x) const{
					MemberArrayMapCollectionLog(pankey_Log_StartMethod, "operator==", "println", "");
					MemberArrayMapCollectionLog(pankey_Log_EndMethod, "operator==", "println", "");
					return this->length() == x;
				}
				
				virtual bool operator!=(int x) const{
					MemberArrayMapCollectionLog(pankey_Log_StartMethod, "operator!=", "println", "");
					MemberArrayMapCollectionLog(pankey_Log_EndMethod, "operator!=", "println", "");
					return this->length() != x;
				}
			
			protected:
				MemberArrayStorage<H,M> m_keys;
				MemberArrayStorage<H,M> m_values;
				bool m_reorder = true;
		};

	}

#endif