
#ifndef PointerArrayStorage_hpp
	#define PointerArrayStorage_hpp

	#include "MemoryStorage.hpp"

	#ifdef PointerArrayStorage_LogApp
		#include "pankey_Logger.hpp"
		#define PointerArrayStorageLog(location,method,type,mns) pankey_Log((void*)this,location,"PointerArrayStorage",method,type,mns)
	#else
		#define PointerArrayStorageLog(location,method,type,mns)
	#endif

	namespace pankey{

		template<class P, class H, class A>
		class PointerArrayStorage : public MemoryStorage<P,H,A>{
			public:
				using INSTANCE_TYPE = typename MemoryStorage<P,H,A>::INSTANCE_TYPE;
                using ALLOCATOR_TYPE = typename MemoryStorage<P,H,A>::ALLOCATOR_TYPE;
                using POINTER_TYPE = typename MemoryStorage<P,H,A>::POINTER_TYPE;
                using HOLDER_TYPE = typename MemoryStorage<P,H,A>::HOLDER_TYPE;
                using HOLDER_ARRAY_TYPE = typename MemoryStorage<P,H,A>::HOLDER_ARRAY_TYPE;

				PointerArrayStorage(){
					PointerArrayStorageLog(pankey_Log_StartMethod, "Constructor", "println", "");
					PointerArrayStorageLog(pankey_Log_EndMethod, "Constructor", "println", "");
				}

				virtual ~PointerArrayStorage(){
					PointerArrayStorageLog(pankey_Log_StartMethod, "Destructor", "println", "");
					this->destroy();
					PointerArrayStorageLog(pankey_Log_EndMethod, "Destructor", "println", "");
				}
				
				virtual bool isNull()const{
					PointerArrayStorageLog(pankey_Log_StartMethod, "isNull", "println", "");
					PointerArrayStorageLog(pankey_Log_EndMethod, "isNull", "println", this->m_values == nullptr);
					return this->m_values == nullptr;
				}
				
				virtual bool isNull(int a_index)const{
					PointerArrayStorageLog(pankey_Log_StartMethod, "isNull", "println", "");
					PointerArrayStorageLog(pankey_Log_Statement, "isNull", "println", "Index:");
					PointerArrayStorageLog(pankey_Log_Statement, "isNull", "println", a_index);
					if(this->m_values == nullptr){
						PointerArrayStorageLog(pankey_Log_EndMethod, "isNull", "println", "this->m_values == nullptr");
						return true;
					}
					if(this->m_values[a_index] == nullptr){
						PointerArrayStorageLog(pankey_Log_EndMethod, "isNull", "println", "this->m_values[a_index] == nullptr");
						return true;
					}
					PointerArrayStorageLog(pankey_Log_EndMethod, "isNull", "println", "");
					return false;
				}

				virtual bool replace(int a_index_1, int a_index_2){
					PointerArrayStorageLog(pankey_Log_StartMethod, "replace", "println", "");
					PointerArrayStorageLog(pankey_Log_Statement, "replace", "println", "Position 1: ");
					PointerArrayStorageLog(pankey_Log_Statement, "replace", "println", a_index_1);
					PointerArrayStorageLog(pankey_Log_Statement, "replace", "println", "Position 2: ");
					PointerArrayStorageLog(pankey_Log_Statement, "replace", "println", a_index_2);

					if(this->isNull() || a_index_1 >= this->getSize() || a_index_2 >= this->getSize() || a_index_1 < 0 || a_index_2 < 0){
						PointerArrayStorageLog(pankey_Log_EndMethod, "replace", "println", "this->isNull()");
						return false;
					}

					if(a_index_1 == a_index_2){
						PointerArrayStorageLog(pankey_Log_EndMethod, "replace", "println", "a_index_1 == a_index_2");
						return true;
					}
					HOLDER_TYPE i_holder_1 = this->m_values[a_index_1];
					HOLDER_TYPE i_holder_2 = this->m_values[a_index_2];
					this->m_values[a_index_1] = i_holder_2;
					this->m_values[a_index_2] = i_holder_1;

					PointerArrayStorageLog(pankey_Log_EndMethod, "replace", "println", "");
					return true;
				}

				virtual bool set(int a_position, const Pointer<P,H,A>& a_pointer){
					PointerArrayStorageLog(pankey_Log_StartMethod, "set", "println", "");
					PointerArrayStorageLog(pankey_Log_Statement, "set", "println", "Position: ");
					PointerArrayStorageLog(pankey_Log_Statement, "set", "println", a_position);

					if(this->isNull() || a_position >= this->getSize() || a_position < 0){
						PointerArrayStorageLog(pankey_Log_EndMethod, "set", "println", "this->isNull()");
						return false;
					}

					HOLDER_TYPE i_holder = a_pointer.getHolder();

					PointerArrayStorageLog(pankey_Log_Statement, "set", "println", "Is Holder == nullptr");
					PointerArrayStorageLog(pankey_Log_Statement, "set", "println", i_holder == nullptr);

					AllocatorManager<H,A>::add(i_holder);
					AllocatorManager<H,A>::remove(this->m_values[a_position]);
					this->m_values[a_position] = i_holder;

					PointerArrayStorageLog(pankey_Log_EndMethod, "set", "println", "");
					return true;
				}

				virtual bool add(int a_position, const Pointer<P,H,A>& a_pointer){
					PointerArrayStorageLog(pankey_Log_StartMethod, "add", "println", "");
					PointerArrayStorageLog(pankey_Log_Statement, "add", "println", "Position: ");
					PointerArrayStorageLog(pankey_Log_Statement, "add", "println", a_position);

					if(this->isNull() || a_position >= this->getSize() || a_position < 0){
						PointerArrayStorageLog(pankey_Log_Statement, "add", "println", "this->isNull() || a_position >= this->getSize() || a_position < 0");
						this->expand(a_position - this->getSize() + 5);
					}
					PointerArrayStorageLog(pankey_Log_EndMethod, "add", "println", "");
					return this->set(a_position, a_pointer);
				}
				
				virtual Pointer<P,H,A> get(int a_position)const{
					PointerArrayStorageLog(pankey_Log_StartMethod, "get", "println", "");
					if(this->isNull() || a_position >= this->getSize() || a_position < 0){
						PointerArrayStorageLog(pankey_Log_EndMethod, "get", "println", "");
						return Pointer<P,H,A>();
					}

					Pointer<P,H,A> i_pointer;
					i_pointer.setHolder(this->m_values[a_position]);

					PointerArrayStorageLog(pankey_Log_EndMethod, "get", "println", "");
					return i_pointer;
				}
				
				virtual P* getRawPointer(int a_position)const{
					PointerArrayStorageLog(pankey_Log_StartMethod, "getRawPointer", "println", "");
					if(this->isNull() || a_position >= this->getSize() || a_position < 0){
						PointerArrayStorageLog(pankey_Log_EndMethod, "getRawPointer", "println", "");
						return nullptr;
					}
					PointerArrayStorageLog(pankey_Log_EndMethod, "getRawPointer", "println", "");
					return AllocatorManager<H,A>::get(this->m_values[a_position]);
				}

				virtual bool contain(const Pointer<P,H,A>& a_value){
					PointerArrayStorageLog(pankey_Log_StartMethod, "contain", "println", "");
					if(this->isNull()){
						PointerArrayStorageLog(pankey_Log_Statement, "contain", "println", "this->isNull()");
						PointerArrayStorageLog(pankey_Log_EndMethod, "contain", "println", "return false");
						return false;
					}
					POINTER_TYPE i_pointer_1 = a_value.get();
					for(int x = 0; x < this->getSize(); x++){
						POINTER_TYPE f_pointer_2 = AllocatorManager<H,A>::get(this->m_values[x]);;
						if(i_pointer_1 == f_pointer_2){
							PointerArrayStorageLog(pankey_Log_Statement, "contain", "println", "a_value == this->m_values[x]");
							PointerArrayStorageLog(pankey_Log_EndMethod, "contain", "println", "return true");
							return true;
						}
					}
					PointerArrayStorageLog(pankey_Log_EndMethod, "contain", "println", "");
					return false;
				}
				
				virtual int getIndex(const Pointer<P,H,A>& a_value){
					PointerArrayStorageLog(pankey_Log_StartMethod, "getIndex", "println", "");
					if(this->isNull()){
						PointerArrayStorageLog(pankey_Log_EndMethod, "getIndex", "println", "this->isNull()");
						return -1;
					}
					POINTER_TYPE i_pointer_1 = a_value.get();
					for(int x = 0; x < this->getSize(); x++){
						POINTER_TYPE f_pointer_2 = AllocatorManager<H,A>::get(this->m_values[x]);;
						if(i_pointer_1 == f_pointer_2){
							PointerArrayStorageLog(pankey_Log_EndMethod, "getIndex", "println", "a_value == this->m_values[x]");
							return x;
						}
					}
					PointerArrayStorageLog(pankey_Log_EndMethod, "getIndex", "println", "");
					return -1;
				}

				virtual bool clear(){
					PointerArrayStorageLog(pankey_Log_StartMethod, "clear", "println", "");
					if(this->isNull()){
						PointerArrayStorageLog(pankey_Log_EndMethod, "clear", "println", "this->isNull()");
						return false;
					}
					for(int x = 0; x < this->getSize(); x++){
						AllocatorManager<H,A>::remove(this->m_values[x]);
					}
					PointerArrayStorageLog(pankey_Log_EndMethod, "clear", "println", "");
					return true;
				}

				virtual bool removeByPointer(const Pointer<P,H,A>& a_value){
					PointerArrayStorageLog(pankey_Log_StartMethod, "removeByPointer", "println", "");
					int i_position = this->getIndex(a_value);
					PointerArrayStorageLog(pankey_Log_Statement, "removeByPointer", "println", "removed position: ");
					PointerArrayStorageLog(pankey_Log_Statement, "removeByPointer", "println", i_position);
					if(this->isNull() || i_position >= this->getSize() || i_position < 0){
						PointerArrayStorageLog(pankey_Log_EndMethod, "removeByPointer", "println", "");
						return false;
					}
					this->removeByPosition(i_position);
					PointerArrayStorageLog(pankey_Log_EndMethod, "removeByPointer", "println", "");
					return true;
				}

				virtual Pointer<P,H,A> removeByPosition(int a_position){
					PointerArrayStorageLog(pankey_Log_StartMethod, "removeByPosition", "println", "");
					if(this->isNull() || a_position >= this->getSize() || a_position < 0){
						PointerArrayStorageLog(pankey_Log_EndMethod, "removeByPosition", "println", "");
						return Pointer<P,H,A>();
					}
					HOLDER_TYPE i_holder = this->m_values[a_position];
					Pointer<P,H,A> i_pointer;
					i_pointer.setHolder(i_holder);
					AllocatorManager<H,A>::remove(i_holder);
					PointerArrayStorageLog(pankey_Log_EndMethod, "removeByPosition", "println", "");
					return i_pointer;
				}

				virtual bool removeFirstIndex(int a_amount){
					PointerArrayStorageLog(pankey_Log_StartMethod, "removeFirstIndex", "println", "");
					if(this->isNull() || a_amount <= 0){
						PointerArrayStorageLog(pankey_Log_EndMethod, "removeFirstIndex", "println", "");
						return false;
					}
					if(a_amount > this->getSize()){
						PointerArrayStorageLog(pankey_Log_Statement, "removeFirstIndex", "println", "a_amount > this->getSize()");
						a_amount = this->getSize();
					}
					for(int x = 0; x < a_amount; x++){
						HOLDER_TYPE i_holder = this->m_values[x];
						AllocatorManager<H,A>::remove(i_holder);
					}
					PointerArrayStorageLog(pankey_Log_EndMethod, "removeFirstIndex", "println", "");
					return true;
				}

				virtual bool removeLastIndex(int a_amount){
					PointerArrayStorageLog(pankey_Log_StartMethod, "removeLastIndex", "println", "");
					if(this->isNull() || a_amount < 0){
						PointerArrayStorageLog(pankey_Log_EndMethod, "removeLastIndex", "println", "");
						return false;
					}
					if(a_amount > this->getSize()){
						PointerArrayStorageLog(pankey_Log_Statement, "removeFirstIndex", "println", "a_amount > this->getSize()");
						a_amount = this->getSize();
					}
					for(int x = this->getSize() - 1; x >= this->getSize() - a_amount; x++){
						HOLDER_TYPE i_holder = this->m_values[x];
						AllocatorManager<H,A>::remove(i_holder);
					}
					PointerArrayStorageLog(pankey_Log_EndMethod, "removeLastIndex", "println", "");
					return true;
				}

				virtual bool removePart(int a_index, int a_amount){
					PointerArrayStorageLog(pankey_Log_StartMethod, "removePart", "println", "");
					if(this->isNull() || a_index <= 0 || a_amount <= 0){
						PointerArrayStorageLog(pankey_Log_EndMethod, "removePart", "println", "");
						return false;
					}
					if(a_index + a_amount > this->getSize()){
						PointerArrayStorageLog(pankey_Log_Statement, "removePart", "println", "a_amount > this->getSize()");
						a_amount = this->getSize() - a_index;
					}
					for(int x = a_index; x < a_amount; x++){
						HOLDER_TYPE i_holder = this->m_values[x];
						AllocatorManager<H,A>::remove(i_holder);
					}
					PointerArrayStorageLog(pankey_Log_EndMethod, "removePart", "println", "");
					return true;
				}

				virtual bool removeFirst(){
					PointerArrayStorageLog(pankey_Log_StartMethod, "removeFirst", "println", "");
					PointerArrayStorageLog(pankey_Log_EndMethod, "removeFirst", "println", "");
					return this->removeByPosition(0);
				}

				virtual bool removeLast(){
					PointerArrayStorageLog(pankey_Log_StartMethod, "removeLast", "println", "");
					PointerArrayStorageLog(pankey_Log_EndMethod, "removeLast", "println", "");
					return this->removeByPosition(this->getSize());
				}

				virtual int reorder(){
					PointerArrayStorageLog(pankey_Log_StartMethod, "reorder", "println", "");
					if(this->isNull()){
						PointerArrayStorageLog(pankey_Log_EndMethod, "reorder", "println", "this->isNull()");
						return -1;
					}
					int i_offset = 0;
					for(int x = 0; x < this->getSize(); x++){
						HOLDER_TYPE f_value = this->m_values[x];
						if(f_value == nullptr){
							continue;
						}
						this->m_values[i_offset] = f_value;
						i_offset++;
					}
					PointerArrayStorageLog(pankey_Log_EndMethod, "reorder", "println", "");
					return i_offset;
				}

				virtual int reorder(int a_index, int a_size){
					PointerArrayStorageLog(pankey_Log_StartMethod, "reorder", "println", "");
					if(this->isNull()){
						PointerArrayStorageLog(pankey_Log_EndMethod, "reorder", "println", "this->isNull()");
						return -1;
					}
					int i_offset = a_index + a_size;
					for(int x = a_index; x < this->getSize() - a_size - 1 + a_index; x++){
						HOLDER_TYPE f_value = this->m_values[x];
						this->m_values[i_offset] = f_value;
						i_offset++;
					}
					PointerArrayStorageLog(pankey_Log_EndMethod, "reorder", "println", "");
					return i_offset;
				}

				virtual int insert(int a_index, int a_size){
					PointerArrayStorageLog(pankey_Log_StartMethod, "insert", "println", "");
					if(this->isNull()){
						PointerArrayStorageLog(pankey_Log_EndMethod, "insert", "println", "this->isNull()");
						return -1;
					}
					int i_offset = a_index + a_size;
					for(int x = a_index; x < this->getSize() - a_size - 1 + a_index; x++){
						HOLDER_TYPE f_value = this->m_values[x];
						this->m_values[i_offset] = f_value;
						i_offset++;
					}
					PointerArrayStorageLog(pankey_Log_EndMethod, "insert", "println", "");
					return i_offset;
				}

				virtual bool expand(int a_size){
					PointerArrayStorageLog(pankey_Log_StartMethod, "expand", "println", "");
					
					int i_size = this->getSize() + a_size;
					PointerArrayStorageLog(pankey_Log_Statement, "expand", "println", "List Size:");
					PointerArrayStorageLog(pankey_Log_Statement, "expand", "println", this->getSize());	
					PointerArrayStorageLog(pankey_Log_Statement, "expand", "println", "List extra size added:");
					PointerArrayStorageLog(pankey_Log_Statement, "expand", "println", a_size);
					PointerArrayStorageLog(pankey_Log_Statement, "expand", "println", "List new size:");
					PointerArrayStorageLog(pankey_Log_Statement, "expand", "println", i_size);
					if(i_size <= 1){
						PointerArrayStorageLog(pankey_Log_EndMethod, "expand", "println", "new size is too small");
						return false;
					}
					HOLDER_ARRAY_TYPE nT;
					nT = AllocatorManager<H,A>::newHolderArray(i_size);
					if(this->m_values != nullptr){
						PointerArrayStorageLog(pankey_Log_Statement, "expand", "println", "this->m_values != nullptr");
						for(int x = 0; x < this->getSize(); x++){
							PointerArrayStorageLog(pankey_Log_Statement, "expand", "println", "iteration:");
							PointerArrayStorageLog(pankey_Log_Statement, "expand", "println", x);
							nT[x] = this->m_values[x];
						}
						AllocatorManager<H,A>::removeHolderArray(this->m_values);
					}
					for(int x = this->getSize(); x < i_size; x++){
						PointerArrayStorageLog(pankey_Log_Statement, "expand", "println", "iteration:");
						PointerArrayStorageLog(pankey_Log_Statement, "expand", "println", x);
						nT[x] = nullptr;
					}
					this->m_values = nT;
					this->m_size = i_size;
					
					PointerArrayStorageLog(pankey_Log_Statement, "expand", "println", "List Size:");
					PointerArrayStorageLog(pankey_Log_Statement, "expand", "println", this->getSize());	
					PointerArrayStorageLog(pankey_Log_EndMethod, "expand", "println", "");
					return true;
				}

				virtual bool shrink(int a_amount){
					PointerArrayStorageLog(pankey_Log_StartMethod, "shrink", "println", "");
					if(this->m_values == nullptr || this->getSize() == 0){
						PointerArrayStorageLog(pankey_Log_EndMethod, "shrink", "println", "");
						return false;
					}
					for(int x = this->getSize() - 1; x >= this->getSize() - a_amount && x >= 0; x--){
						AllocatorManager<H,A>::remove(this->m_values[x]);
					}
					this->m_size -= a_amount;

					PointerArrayStorageLog(pankey_Log_EndMethod, "shrink", "println", "");
					return true;
				}

				virtual bool destroy(){
					PointerArrayStorageLog(pankey_Log_StartMethod, "destroy", "println", "");
					this->shrink(this->getSize());
					AllocatorManager<H,A>::removeHolderArray(this->m_values);
					PointerArrayStorageLog(pankey_Log_EndMethod, "destroy", "println", "");
					return true;
				}
			
			protected:
				HOLDER_ARRAY_TYPE m_values = nullptr;
		};

	}

#endif