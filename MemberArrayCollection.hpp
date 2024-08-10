
#ifndef MemberArrayCollection_hpp
	#define MemberArrayCollection_hpp

	#include "Collection.hpp"
	#include "MemberArrayStorage.hpp"
	#include "Member.hpp"

	#ifdef MemberArrayCollection_LogApp
		#include "higgs_Logger.hpp"
		#define MemberArrayCollectionLog(location,method,type,mns) higgs_Log((void*)this,location,"MemberArrayCollection",method,type,mns)
	#else
		#define MemberArrayCollectionLog(location,method,type,mns)
	#endif

	namespace higgs{

		template<class H, class M>
		class MemberArrayCollection : public Collection<H,M>{
			public:
				MemberArrayCollection(){
					MemberArrayCollectionLog(higgs_Log_StartMethod, "Constructor", "println", "");
					MemberArrayCollectionLog(higgs_Log_EndMethod, "Constructor", "println", "");
				}

				virtual ~MemberArrayCollection(){
					MemberArrayCollectionLog(higgs_Log_StartMethod, "Destructor", "println", "");
					MemberArrayCollectionLog(higgs_Log_EndMethod, "Destructor", "println", "");
				}
				
				virtual bool isEmpty()const{
					MemberArrayCollectionLog(higgs_Log_StartMethod, "isEmpty", "println", "");
					MemberArrayCollectionLog(higgs_Log_EndMethod, "isEmpty", "println", "");
					return this->m_storage.isNull() || this->m_storage.getSize() <= 0 || this->m_length <= 0;
				}

				virtual int length()const{
					MemberArrayCollectionLog(higgs_Log_StartMethod, "length", "println", "");
					MemberArrayCollectionLog(higgs_Log_EndMethod, "length", "println", "");
					return this->m_length;
				}
				
				virtual int getSize()const{
					MemberArrayCollectionLog(higgs_Log_StartMethod, "getSize", "println", "");
					MemberArrayCollectionLog(higgs_Log_EndMethod, "getSize", "println", "");
					return this->m_storage.getSize();
				}

				virtual bool replace(int a_index_1, int a_index_2){
					MemberArrayCollectionLog(higgs_Log_StartMethod, "replace", "println", "");
					MemberArrayCollectionLog(higgs_Log_EndMethod, "replace", "println", "");
					return this->m_storage.replace(a_index_1, a_index_2);
				}

				virtual Member<H,M> get(const Member<H,M>& a_value)const{
					MemberArrayCollectionLog(higgs_Log_StartMethod, "get", "println", "");
					if(!this->m_storage.contain(a_value)){
						MemberArrayCollectionLog(higgs_Log_Statement, "get", "println", "!this->m_storage.contain(a_value)");
						return Member<H,M>();
					}
					MemberArrayCollectionLog(higgs_Log_EndMethod, "get", "println", "");
					return a_value;
				}

				virtual Member<H,M> get(int x)const{
					MemberArrayCollectionLog(higgs_Log_StartMethod, "get", "println", "");
					MemberArrayCollectionLog(higgs_Log_EndMethod, "get", "println", "");
					return this->m_storage.get(x);
				}

				virtual bool contain(const Member<H,M>& a_value)const{
					MemberArrayCollectionLog(higgs_Log_StartMethod, "contain", "println", "");
					MemberArrayCollectionLog(higgs_Log_EndMethod, "contain", "println", "");
					return this->m_storage.contain(a_value);
				}
				
				virtual int getIndex(const Member<H,M>& a_value)const{
					MemberArrayCollectionLog(higgs_Log_StartMethod, "getIndex", "println", "");
					MemberArrayCollectionLog(higgs_Log_EndMethod, "getIndex", "println", "");
					return this->m_storage.getIndex(a_value);
				}
				
				virtual bool remove(const Member<H,M>& a_value){
					MemberArrayCollectionLog(higgs_Log_StartMethod, "remove", "println", "");
					int i_index = this->m_storage.getIndex(a_value);
					if(i_index == -1){
						MemberArrayCollectionLog(higgs_Log_EndMethod, "remove", "println", "");
						return false;
					}
					MemberArrayCollectionLog(higgs_Log_Statement, "remove", "println", "index that is been removed:");
					MemberArrayCollectionLog(higgs_Log_Statement, "remove", "println", i_index);
					this->m_storage.removeByIndex(i_index);
					this->m_storage.reorder(i_index, this->length());
					MemberArrayCollectionLog(higgs_Log_EndMethod, "remove", "println", "");
					return true;
				}
				
				virtual Member<H,M> remove(int a_index){
					MemberArrayCollectionLog(higgs_Log_StartMethod, "remove", "println", "");
					if(a_index < 0 || this->isEmpty() || a_index >= this->length()){
						MemberArrayCollectionLog(higgs_Log_EndMethod, "remove", "println", "");
						return Member<H,M>();
					}
					Member<H,M> i_pointer = this->m_storage.removeByIndex(a_index);
					this->m_storage.reorder(a_index, this->length());
					this->decrementPosition();
					MemberArrayCollectionLog(higgs_Log_EndMethod, "remove", "println", "");
					return i_pointer;
				}
				
				virtual bool removeFirstIndex(int a_amount){
					MemberArrayCollectionLog(higgs_Log_StartMethod, "removeFirstIndex", "println", "");
					if(this->m_storage.removeFirstIndex(this->m_length, a_amount)){
						this->m_storage.reorder(0, this->length(), a_amount);
						this->decrementPosition(a_amount);
						MemberArrayCollectionLog(higgs_Log_EndMethod, "removeFirstIndex", "println", "");
						return true;
					}
					MemberArrayCollectionLog(higgs_Log_EndMethod, "removeFirstIndex", "println", "");
					return false;
				}

				virtual bool removeLastIndex(int a_amount){
					MemberArrayCollectionLog(higgs_Log_StartMethod, "removeLastIndex", "println", "");
					if(this->m_storage.removeLastIndex(this->m_length, a_amount)){
						this->decrementPosition(a_amount);
						MemberArrayCollectionLog(higgs_Log_EndMethod, "removeLastIndex", "println", "");
						return true;
					}
					MemberArrayCollectionLog(higgs_Log_EndMethod, "removeLastIndex", "println", "");
					return false;
				}

				virtual bool removePart(int a_index, int a_amount){
					MemberArrayCollectionLog(higgs_Log_StartMethod, "removePart", "println", "");
					if(this->m_storage.removePart(a_index, this->m_length, a_amount)){
						this->m_storage.reorder(a_index, this->length(), a_amount);
						this->decrementPosition(a_amount);
						MemberArrayCollectionLog(higgs_Log_EndMethod, "removePart", "println", "");
						return true;
					}
					MemberArrayCollectionLog(higgs_Log_EndMethod, "removePart", "println", "");
					return false;
				}
				
				virtual bool removeFirst(){
					MemberArrayCollectionLog(higgs_Log_StartMethod, "removeFirst", "println", "");
					if(this->m_storage.removeFirst()){
						this->m_storage.reorder(0, this->length());
						this->decrementPosition();
						MemberArrayCollectionLog(higgs_Log_EndMethod, "removeFirst", "println", "true");
						return true;
					}
					MemberArrayCollectionLog(higgs_Log_EndMethod, "removeFirst", "println", "false");
					return false;
				}

				virtual bool removeLast(){
					MemberArrayCollectionLog(higgs_Log_StartMethod, "removeLast", "println", "");
					if(this->isEmpty()){
						MemberArrayCollectionLog(higgs_Log_EndMethod, "removeLast", "println", "");
						return false;
					}
					Member<H,M> i_pointer = this->m_storage.removeByIndex(this->length() - 1);
					this->m_storage.reorder(this->length() - 1, this->length());
					this->decrementPosition();
					MemberArrayCollectionLog(higgs_Log_EndMethod, "removeLast", "println", "");
					return true;
				}
				
				virtual bool clear(){
					MemberArrayCollectionLog(higgs_Log_StartMethod, "clear", "println", "");
					this->m_length = 0;
					if(this->m_storage.clear()){
						this->m_length = 0;
						MemberArrayCollectionLog(higgs_Log_EndMethod, "clear", "println", "");
						return true;
					}
					MemberArrayCollectionLog(higgs_Log_EndMethod, "clear", "println", "");
					return false;
				}

				virtual bool isInOrder()const{
					MemberArrayCollectionLog(higgs_Log_StartMethod, "isInOrder", "println", "");
					MemberArrayCollectionLog(higgs_Log_EndMethod, "isInOrder", "println", "");
					return this->m_reorder;
				}

				virtual void setReorder(bool a_reorder){
					MemberArrayCollectionLog(higgs_Log_StartMethod, "setReorder", "println", "");
					if(a_reorder != this->m_reorder){
						MemberArrayCollectionLog(higgs_Log_EndMethod, "setReorder", "println", "");
						return;
					}
					this->m_reorder = a_reorder;
					reorder();
					MemberArrayCollectionLog(higgs_Log_EndMethod, "setReorder", "println", "");
				}
				
				virtual void reorder(){
					MemberArrayCollectionLog(higgs_Log_StartMethod, "reorder", "println", "");
					if(!this->m_reorder){
						MemberArrayCollectionLog(higgs_Log_Statement, "reorder", "println", "this->m_reorder || this->m_storage == nullptr");
						return;
					}
					this->m_storage.reorder();
					MemberArrayCollectionLog(higgs_Log_EndMethod, "reorder", "println", "");
				}
				
				virtual void move(MemberArrayCollection<H,M>& a_MemberArrayCollection){
					MemberArrayCollectionLog(higgs_Log_StartMethod, "move", "println", "");
					MemberArrayCollectionLog(higgs_Log_EndMethod, "move", "println", "");
				}
				
				virtual void duplicate(const MemberArrayCollection<H,M>& a_MemberArrayCollection){
					MemberArrayCollectionLog(higgs_Log_StartMethod, "duplicate", "println", "");
					MemberArrayCollectionLog(higgs_Log_EndMethod, "duplicate", "println", "");
				}
				
			protected:
				
				virtual void incrementPosition(){
					MemberArrayCollectionLog(higgs_Log_StartMethod, "incrementPosition", "println", "");
					this->m_length++;
					MemberArrayCollectionLog(higgs_Log_EndMethod, "incrementPosition", "println", "");
				}
				virtual void decrementPosition(){
					MemberArrayCollectionLog(higgs_Log_StartMethod, "decrementPosition", "println", "");
					this->m_length--;
					if(this->m_length < 0){
						this->m_length = 0;
					}
					MemberArrayCollectionLog(higgs_Log_EndMethod, "decrementPosition", "println", "");
				}
				
				virtual void incrementPosition(int a_size){
					MemberArrayCollectionLog(higgs_Log_StartMethod, "incrementPosition", "println", "");
					this->m_length += a_size;
					MemberArrayCollectionLog(higgs_Log_EndMethod, "incrementPosition", "println", "");
				}
				virtual void decrementPosition(int a_size){
					MemberArrayCollectionLog(higgs_Log_StartMethod, "decrementPosition", "println", "");
					this->m_length -= a_size;
					if(this->m_length < 0){
						this->m_length = 0;
					}
					MemberArrayCollectionLog(higgs_Log_EndMethod, "decrementPosition", "println", "");
				}

			public:
			
				virtual bool operator<(int x) const{
					MemberArrayCollectionLog(higgs_Log_StartMethod, "operator<", "println", "");
					MemberArrayCollectionLog(higgs_Log_EndMethod, "operator<", "println", "");
					return this->length() < x;
				}
				
				virtual bool operator>(int x) const{
					MemberArrayCollectionLog(higgs_Log_StartMethod, "operator>", "println", "");
					MemberArrayCollectionLog(higgs_Log_EndMethod, "operator>", "println", "");
					return this->length() > x;
				}
				
				virtual bool operator<=(int x) const{
					MemberArrayCollectionLog(higgs_Log_StartMethod, "operator<=", "println", "");
					MemberArrayCollectionLog(higgs_Log_EndMethod, "operator<=", "println", "");
					return this->length() <= x;
				}
				
				virtual bool operator>=(int x) const{
					MemberArrayCollectionLog(higgs_Log_StartMethod, "operator>=", "println", "");
					MemberArrayCollectionLog(higgs_Log_EndMethod, "operator>=", "println", "");
					return this->length() >= x;
				}
				
				virtual bool operator==(int x) const{
					MemberArrayCollectionLog(higgs_Log_StartMethod, "operator==", "println", "");
					MemberArrayCollectionLog(higgs_Log_EndMethod, "operator==", "println", "");
					return this->length() == x;
				}
				
				virtual bool operator!=(int x) const{
					MemberArrayCollectionLog(higgs_Log_StartMethod, "operator!=", "println", "");
					MemberArrayCollectionLog(higgs_Log_EndMethod, "operator!=", "println", "");
					return this->length() != x;
				}
			
			protected:
				MemberArrayStorage<H,M> m_storage;
				int m_length = 0;
				bool m_reorder = true;
		};

	}

#endif