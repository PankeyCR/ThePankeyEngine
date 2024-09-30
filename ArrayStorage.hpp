
#ifndef ArrayStorage_hpp
	#define ArrayStorage_hpp

	#include "MemoryStorage.hpp"
	#include "MemoryHolderManager.hpp"

	#ifdef ArrayStorage_LogApp
		#include "pankey_Logger.hpp"
		#define ArrayStorageLog(location,method,type,mns) pankey_Log((void*)this,location,"ArrayStorage",method,type,mns)
	#else
		#define ArrayStorageLog(location,method,type,mns)
	#endif

	namespace pankey{

		template<class H>
		class ArrayStorage : virtual public MemoryStorage<H>{
			public:
                using HOLDER_ARRAY_TYPE = typename MemoryStorage<H>::HOLDER_ARRAY_TYPE;
                using MANAGER_TYPE = typename MemoryStorage<H>::MANAGER_TYPE;
                using VOID_TYPE = typename MemoryStorage<H>::VOID_TYPE;
                using HOLDER_TYPE = typename MemoryStorage<H>::HOLDER_TYPE;

				ArrayStorage(){
					ArrayStorageLog(pankey_Log_StartMethod, "Constructor", "println", "");
					ArrayStorageLog(pankey_Log_EndMethod, "Constructor", "println", "");
				}

				virtual ~ArrayStorage(){
					ArrayStorageLog(pankey_Log_StartMethod, "Destructor", "println", "");
					ArrayStorageLog(pankey_Log_EndMethod, "Destructor", "println", "");
				}
				
				virtual bool isNull()const{
					ArrayStorageLog(pankey_Log_StartMethod, "isNull", "println", "");
					ArrayStorageLog(pankey_Log_EndMethod, "isNull", "println", this->m_values == nullptr);
					return this->m_values == nullptr;
				}
				
				virtual bool isNull(int a_index)const{
					ArrayStorageLog(pankey_Log_StartMethod, "isNull", "println", "");
					ArrayStorageLog(pankey_Log_Statement, "isNull", "println", "Index:");
					ArrayStorageLog(pankey_Log_Statement, "isNull", "println", a_index);
					if(this->m_values == nullptr){
						ArrayStorageLog(pankey_Log_EndMethod, "isNull", "println", "this->m_values == nullptr");
						return true;
					}
					if(this->getSize() <= 0){
						ArrayStorageLog(pankey_Log_EndMethod, "isNull", "println", "this->getSize() < 0");
						return true;
					}
					if(this->m_values[a_index] == nullptr){
						ArrayStorageLog(pankey_Log_EndMethod, "isNull", "println", "this->m_values[a_index] == nullptr");
						return true;
					}
					ArrayStorageLog(pankey_Log_EndMethod, "isNull", "println", "");
					return false;
				}

				virtual bool replace(int a_index_1, int a_index_2){
					ArrayStorageLog(pankey_Log_StartMethod, "replace", "println", "");
					ArrayStorageLog(pankey_Log_Statement, "replace", "println", "Position 1: ");
					ArrayStorageLog(pankey_Log_Statement, "replace", "println", a_index_1);
					ArrayStorageLog(pankey_Log_Statement, "replace", "println", "Position 2: ");
					ArrayStorageLog(pankey_Log_Statement, "replace", "println", a_index_2);

					if(this->isNull() || a_index_1 >= this->getSize() || a_index_2 >= this->getSize() || a_index_1 < 0 || a_index_2 < 0){
						ArrayStorageLog(pankey_Log_EndMethod, "replace", "println", "this->isNull()");
						return false;
					}

					if(a_index_1 == a_index_2){
						ArrayStorageLog(pankey_Log_EndMethod, "replace", "println", "a_index_1 == a_index_2");
						return true;
					}
					HOLDER_TYPE i_holder_1 = this->m_values[a_index_1];
					HOLDER_TYPE i_holder_2 = this->m_values[a_index_2];
					this->m_values[a_index_1] = i_holder_2;
					this->m_values[a_index_2] = i_holder_1;

					ArrayStorageLog(pankey_Log_EndMethod, "replace", "println", "");
					return true;
				}

				virtual bool set(int a_position, MemoryHolder<H>& a_pointer){
					ArrayStorageLog(pankey_Log_StartMethod, "set", "println", "");
					ArrayStorageLog(pankey_Log_Statement, "set", "println", "Position: ");
					ArrayStorageLog(pankey_Log_Statement, "set", "println", a_position);

					if(this->isNull() || a_position >= this->getSize() || a_position < 0){
						ArrayStorageLog(pankey_Log_EndMethod, "set", "println", "this->isNull() || a_position >= this->getSize() || a_position < 0");
						return false;
					}

					HOLDER_TYPE i_holder = a_pointer.getHolder();

					ArrayStorageLog(pankey_Log_Statement, "set", "println", "Is Holder == nullptr");
					ArrayStorageLog(pankey_Log_Statement, "set", "println", i_holder == nullptr);

					if(i_holder == this->m_values[a_position]){
						ArrayStorageLog(pankey_Log_EndMethod, "set", "println", "i_holder == this->m_values[a_position]");
						return true;
					}

					MemoryHolderManager<H>::add(this->getManager(), i_holder);
					MemoryHolderManager<H>::remove(this->getManager(), this->m_values[a_position]);
					
					this->m_values[a_position] = i_holder;

					ArrayStorageLog(pankey_Log_EndMethod, "set", "println", "");
					return true;
				}

				virtual bool add(int a_position, MemoryHolder<H>& a_pointer){
					ArrayStorageLog(pankey_Log_StartMethod, "add", "println", "");
					ArrayStorageLog(pankey_Log_Statement, "add", "println", "Position: ");
					ArrayStorageLog(pankey_Log_Statement, "add", "println", a_position);

					if(this->isNull() || a_position >= this->getSize() || a_position < 0){
						ArrayStorageLog(pankey_Log_Statement, "add", "println", "this->isNull() || a_position >= this->getSize() || a_position < 0");
						this->expand(a_position - this->getSize() + this->expandRate);
					}
					ArrayStorageLog(pankey_Log_EndMethod, "add", "println", "");
					return this->set(a_position, a_pointer);
				}

				virtual bool contain(InvokeMethodReturn<bool,VOID_TYPE,VOID_TYPE> a_method, const MemoryHolder<H>& a_value)const{
					ArrayStorageLog(pankey_Log_StartMethod, "contain", "println", "");
					if(this->isNull()){
						ArrayStorageLog(pankey_Log_Statement, "contain", "println", "this->isNull()");
						ArrayStorageLog(pankey_Log_EndMethod, "contain", "println", "return false");
						return false;
					}

					VOID_TYPE i_pointer_1 = a_value.getRawPointer();

					if(i_pointer_1 == nullptr){
						ArrayStorageLog(pankey_Log_EndMethod, "contain", "println", "i_pointer_1 == nullptr");
						return false;
					}

					for(int x = 0; x < this->getSize(); x++){
						VOID_TYPE f_pointer_2 = MemoryHolderManager<H>::get(this->getManager(), this->m_values[x]);
						if(f_pointer_2 == nullptr){
							ArrayStorageLog(pankey_Log_EndMethod, "contain", "println", "f_pointer_2 == nullptr");
							continue;
						}
						bool i_result = invoke<bool,VOID_TYPE,VOID_TYPE>(a_method, i_pointer_1, f_pointer_2);
						if(i_result){
							ArrayStorageLog(pankey_Log_Statement, "contain", "println", "a_value == this->m_values[x]");
							ArrayStorageLog(pankey_Log_EndMethod, "contain", "println", "return true");
							return true;
						}
					}

					ArrayStorageLog(pankey_Log_EndMethod, "contain", "println", "");
					return false;
				}

				virtual bool containByPointer(const MemoryHolder<H>& a_value)const{
					ArrayStorageLog(pankey_Log_StartMethod, "containByPointer", "println", "");
					if(this->isNull()){
						ArrayStorageLog(pankey_Log_Statement, "containByPointer", "println", "this->isNull()");
						ArrayStorageLog(pankey_Log_EndMethod, "containByPointer", "println", "return false");
						return false;
					}

					VOID_TYPE i_pointer_1 = a_value.getRawPointer();

					for(int x = 0; x < this->getSize(); x++){
						VOID_TYPE f_pointer_2 = MemoryHolderManager<H>::get(this->getManager(), this->m_values[x]);;
						if(i_pointer_1 == f_pointer_2){
							ArrayStorageLog(pankey_Log_Statement, "containByPointer", "println", "a_value == this->m_values[x]");
							ArrayStorageLog(pankey_Log_EndMethod, "containByPointer", "println", "return true");
							return true;
						}
					}

					ArrayStorageLog(pankey_Log_EndMethod, "containByPointer", "println", "");
					return false;
				}
				
				virtual int getIndex(InvokeMethodReturn<bool,VOID_TYPE,VOID_TYPE> a_method, const MemoryHolder<H>& a_value)const{
					ArrayStorageLog(pankey_Log_StartMethod, "getIndex", "println", "");
					if(this->isNull()){
						ArrayStorageLog(pankey_Log_EndMethod, "getIndex", "println", "this->isNull()");
						return -1;
					}

					VOID_TYPE i_pointer_1 = a_value.getRawPointer();

					if(i_pointer_1 == nullptr){
						ArrayStorageLog(pankey_Log_EndMethod, "getIndex", "println", "i_pointer_1 == nullptr");
						return -1;
					}

					for(int x = 0; x < this->getSize(); x++){
						VOID_TYPE f_pointer_2 = MemoryHolderManager<H>::get(this->getManager(), this->m_values[x]);
						if(f_pointer_2 == nullptr){
							ArrayStorageLog(pankey_Log_EndMethod, "getIndex", "println", "f_pointer_2 == nullptr");
							continue;
						}
						bool i_result = invoke<bool,VOID_TYPE,VOID_TYPE>(a_method, i_pointer_1, f_pointer_2);
						if(i_result){
							ArrayStorageLog(pankey_Log_EndMethod, "getIndex", "println", "a_value == this->m_values[x]");
							return x;
						}
					}

					ArrayStorageLog(pankey_Log_EndMethod, "getIndex", "println", "");
					return -1;
				}
				
				virtual int getIndexByPointer(const MemoryHolder<H>& a_value)const{
					ArrayStorageLog(pankey_Log_StartMethod, "getIndexByPointer", "println", "");
					if(this->isNull()){
						ArrayStorageLog(pankey_Log_EndMethod, "getIndexByPointer", "println", "this->isNull()");
						return -1;
					}

					VOID_TYPE i_pointer_1 = a_value.getRawPointer();

					for(int x = 0; x < this->getSize(); x++){
						VOID_TYPE f_pointer_2 = MemoryHolderManager<H>::get(this->getManager(), this->m_values[x]);;
						if(i_pointer_1 == f_pointer_2){
							ArrayStorageLog(pankey_Log_EndMethod, "getIndexByPointer", "println", "a_value == this->m_values[x]");
							return x;
						}
					}

					ArrayStorageLog(pankey_Log_EndMethod, "getIndexByPointer", "println", "");
					return -1;
				}
				
				virtual VOID_TYPE getRawPointer(int a_position)const{
					ArrayStorageLog(pankey_Log_StartMethod, "getRawPointer", "println", "");

					if(this->isNull() || a_position >= this->getSize() || a_position < 0){
						ArrayStorageLog(pankey_Log_EndMethod, "getRawPointer", "println", "");
						return nullptr;
					}

					ArrayStorageLog(pankey_Log_EndMethod, "getRawPointer", "println", "");
					return MemoryHolderManager<H>::get(this->getManager(), this->m_values[a_position]);
				}
				
				virtual HOLDER_TYPE getHolder(int a_position)const{
					ArrayStorageLog(pankey_Log_StartMethod, "get", "println", "");

					if(this->isNull() || a_position >= this->getSize() || a_position < 0){
						ArrayStorageLog(pankey_Log_EndMethod, "get", "println", "");
						return nullptr;
					}

					ArrayStorageLog(pankey_Log_EndMethod, "get", "println", "");
					return this->m_values[a_position];
				}

				virtual bool remove(InvokeMethodReturn<bool,VOID_TYPE,VOID_TYPE> a_method, const MemoryHolder<H>& a_value){
					ArrayStorageLog(pankey_Log_StartMethod, "remove", "println", "");

					int i_position = this->getIndex(a_method, a_value);

					ArrayStorageLog(pankey_Log_Statement, "remove", "println", "removed position: ");
					ArrayStorageLog(pankey_Log_Statement, "remove", "println", i_position);

					if(this->isNull() || i_position >= this->getSize() || i_position < 0){
						ArrayStorageLog(pankey_Log_EndMethod, "remove", "println", "");
						return false;
					}
					
					MemoryHolderManager<H>::remove(this->getManager(), this->m_values[i_position]);

					ArrayStorageLog(pankey_Log_EndMethod, "remove", "println", "");
					return true;
				}

				virtual bool removeByPointer(const MemoryHolder<H>& a_value){
					ArrayStorageLog(pankey_Log_StartMethod, "removeByPointer", "println", "");

					int i_position = this->getIndexByPointer(a_value);

					ArrayStorageLog(pankey_Log_Statement, "removeByPointer", "println", "removed position: ");
					ArrayStorageLog(pankey_Log_Statement, "removeByPointer", "println", i_position);

					if(this->isNull() || i_position >= this->getSize() || i_position < 0){
						ArrayStorageLog(pankey_Log_EndMethod, "removeByPointer", "println", "");
						return false;
					}
					
					MemoryHolderManager<H>::remove(this->getManager(), this->m_values[i_position]);

					ArrayStorageLog(pankey_Log_EndMethod, "removeByPointer", "println", "");
					return true;
				}

				virtual bool removeFirstIndex(int a_length, int a_amount){
					ArrayStorageLog(pankey_Log_StartMethod, "removeFirstIndex", "println", "");

					if(this->isNull() || a_amount <= 0){
						ArrayStorageLog(pankey_Log_EndMethod, "removeFirstIndex", "println", "");
						return false;
					}

					if(a_amount > a_length){
						ArrayStorageLog(pankey_Log_Statement, "removeFirstIndex", "println", "a_amount > this->getSize()");
						a_amount = a_length;
					}

					for(int x = 0; x < a_amount; x++){
						ArrayStorageLog(pankey_Log_Statement, "removeFirstIndex", "println", "for loop index");
						ArrayStorageLog(pankey_Log_Statement, "removeFirstIndex", "println", x);
						MemoryHolderManager<H>::remove(this->getManager(), this->m_values[x]);
					}

					ArrayStorageLog(pankey_Log_EndMethod, "removeFirstIndex", "println", "");
					return true;
				}

				virtual bool removeLastIndex(int a_length, int a_amount){
					ArrayStorageLog(pankey_Log_StartMethod, "removeLastIndex", "println", "");

					if(this->isNull() || a_amount < 0){
						ArrayStorageLog(pankey_Log_EndMethod, "removeLastIndex", "println", "");
						return false;
					}

					if(a_amount > a_length){
						ArrayStorageLog(pankey_Log_Statement, "removeFirstIndex", "println", "a_amount > this->getSize()");
						a_amount = a_length;
					}

					for(int x = a_length - 1; x >= a_length - a_amount; x--){
						ArrayStorageLog(pankey_Log_Statement, "removeLastIndex", "println", "for loop index");
						ArrayStorageLog(pankey_Log_Statement, "removeLastIndex", "println", x);
						MemoryHolderManager<H>::remove(this->getManager(), this->m_values[x]);
					}

					ArrayStorageLog(pankey_Log_EndMethod, "removeLastIndex", "println", "");
					return true;
				}

				virtual bool removePart(int a_index, int a_length, int a_amount){
					ArrayStorageLog(pankey_Log_StartMethod, "removePart", "println", "");

					if(this->isNull() || a_index < 0 || a_amount <= 0){
						ArrayStorageLog(pankey_Log_EndMethod, "removePart", "println", "this->isNull() || a_index <= 0 || a_amount <= 0");
						return false;
					}

					if(a_index + a_amount > a_length){
						ArrayStorageLog(pankey_Log_Statement, "removePart", "println", "a_index + a_amount > a_length");
						ArrayStorageLog(pankey_Log_Statement, "removePart", "println", a_index + a_amount);
						a_amount = a_length - a_index;
					}

					for(int x = a_index; x < a_index + a_amount; x++){
						ArrayStorageLog(pankey_Log_Statement, "removePart", "println", "for loop index");
						ArrayStorageLog(pankey_Log_Statement, "removePart", "println", x);
						MemoryHolderManager<H>::remove(this->getManager(), this->m_values[x]);
					}

					ArrayStorageLog(pankey_Log_EndMethod, "removePart", "println", "");
					return true;
				}

				virtual bool removeFirst(){
					ArrayStorageLog(pankey_Log_StartMethod, "removeFirst", "println", "");

					if(this->isNull() || this->getSize() < 1){
						ArrayStorageLog(pankey_Log_EndMethod, "removeFirst", "println", "");
						return false;
					}
					
					MemoryHolderManager<H>::remove(this->getManager(), this->m_values[0]);

					ArrayStorageLog(pankey_Log_EndMethod, "removeFirst", "println", "");
					return true;
				}

				virtual bool removeLast(){
					ArrayStorageLog(pankey_Log_StartMethod, "removeLast", "println", "");
					ArrayStorageLog(pankey_Log_Statement, "removeLast", "println", "removing index");
					ArrayStorageLog(pankey_Log_Statement, "removeLast", "println", this->getSize() - 1);

					if(this->isNull() || this->getSize() < 1){
						ArrayStorageLog(pankey_Log_EndMethod, "removeLast", "println", "");
						return false;
					}
					
					MemoryHolderManager<H>::remove(this->getManager(), this->m_values[this->getSize() - 1]);
					
					ArrayStorageLog(pankey_Log_EndMethod, "removeLast", "println", "");
					return true;
				}

				virtual bool clear(){
					ArrayStorageLog(pankey_Log_StartMethod, "clear", "println", "");

					if(this->isNull()){
						ArrayStorageLog(pankey_Log_EndMethod, "clear", "println", "this->isNull()");
						return false;
					}

					for(int x = 0; x < this->getSize(); x++){
						ArrayStorageLog(pankey_Log_Statement, "clear", "println", "for loop index");
						ArrayStorageLog(pankey_Log_Statement, "clear", "println", x);
						MemoryHolderManager<H>::remove(this->getManager(), this->m_values[x]);
					}

					ArrayStorageLog(pankey_Log_EndMethod, "clear", "println", "");
					return true;
				}

				virtual int reorder(){
					ArrayStorageLog(pankey_Log_StartMethod, "reorder", "println", "");

					if(this->isNull()){
						ArrayStorageLog(pankey_Log_EndMethod, "reorder", "println", "this->isNull()");
						return -1;
					}

					int i_offset = 0;

					for(int x = 0; x < this->getSize(); x++){
						ArrayStorageLog(pankey_Log_Statement, "reorder", "println", "for loop index");
						ArrayStorageLog(pankey_Log_Statement, "reorder", "println", x);
						ArrayStorageLog(pankey_Log_Statement, "reorder", "println", "for loop i_offset");
						ArrayStorageLog(pankey_Log_Statement, "reorder", "println", i_offset);

						HOLDER_TYPE f_value = this->m_values[x];

						if(f_value == nullptr){
							ArrayStorageLog(pankey_Log_Statement, "reorder", "println", "f_value == nullptr");
							continue;
						}
						
						if(i_offset != x){
							ArrayStorageLog(pankey_Log_Statement, "reorder", "println", "i_offset != x");
							this->m_values[i_offset] = f_value;
							this->m_values[x] = nullptr;
						}

						ArrayStorageLog(pankey_Log_Statement, "reorder", "println", "this->m_values[i_offset] = f_value");
						i_offset++;
					}

					ArrayStorageLog(pankey_Log_EndMethod, "reorder", "println", "");
					return i_offset;
				}

				virtual int reorder(int a_index, int a_length, int a_amount){
					ArrayStorageLog(pankey_Log_StartMethod, "reorder", "println", "");

					if(this->isNull()){
						ArrayStorageLog(pankey_Log_EndMethod, "reorder", "println", "this->isNull()");
						return -1;
					}

					int i_offset = a_index;

					if(this->getSize() - a_length < a_amount && a_length < a_index + a_amount){
						ArrayStorageLog(pankey_Log_Statement, "reorder", "println", "this->getSize() - a_length < a_amount && a_length < a_index + a_amount");
						ArrayStorageLog(pankey_Log_Statement, "reorder", "println", "this->getSize() - a_length");
						ArrayStorageLog(pankey_Log_Statement, "reorder", "println", this->getSize() - a_length);
						ArrayStorageLog(pankey_Log_Statement, "reorder", "println", "a_amount");
						ArrayStorageLog(pankey_Log_Statement, "reorder", "println", a_amount);
						ArrayStorageLog(pankey_Log_Statement, "reorder", "println", "a_length");
						ArrayStorageLog(pankey_Log_Statement, "reorder", "println", a_length);
						ArrayStorageLog(pankey_Log_Statement, "reorder", "println", "a_index + a_amount");
						ArrayStorageLog(pankey_Log_Statement, "reorder", "println", a_index + a_amount);
						return -1;
					}

					if(a_index + a_amount > a_length){
						ArrayStorageLog(pankey_Log_Statement, "reorder", "println", "a_index + a_amount > a_length");
						ArrayStorageLog(pankey_Log_Statement, "reorder", "println", a_index + a_amount);
						a_amount = a_length - a_index;
					}

					for(int x = a_index + a_amount; x < a_length; x++){
						ArrayStorageLog(pankey_Log_Statement, "reorder", "println", "for loop index");
						ArrayStorageLog(pankey_Log_Statement, "reorder", "println", x);
						ArrayStorageLog(pankey_Log_Statement, "reorder", "println", "for loop i_offset");
						ArrayStorageLog(pankey_Log_Statement, "reorder", "println", i_offset);

						HOLDER_TYPE f_value = this->m_values[x];
						
						if(i_offset != x){
							ArrayStorageLog(pankey_Log_Statement, "reorder", "println", "i_offset != x");
							this->m_values[i_offset] = f_value;
							this->m_values[x] = nullptr;
						}

						ArrayStorageLog(pankey_Log_Statement, "reorder", "println", "this->m_values[i_offset] = f_value");
						i_offset++;
					}

					ArrayStorageLog(pankey_Log_EndMethod, "reorder", "println", "");
					return i_offset;
				}

				virtual int reorder(int a_index, int a_length){
					return this->reorder(a_index, a_length, 1);
				}

				virtual int insert(int a_index, int a_length, int a_size){
					ArrayStorageLog(pankey_Log_StartMethod, "insert", "println", "");

					if(this->isNull()){
						ArrayStorageLog(pankey_Log_EndMethod, "insert", "println", "this->isNull()");
						return -1;
					}

					int i_offset = a_size + a_length - 1;
					int i_size = a_size + a_length;

					if(i_offset > this->getSize()){
						i_offset = this->getSize() - 1;
					}

					ArrayStorageLog(pankey_Log_Statement, "insert", "println", "a_index");
					ArrayStorageLog(pankey_Log_Statement, "insert", "println", a_index);

					ArrayStorageLog(pankey_Log_Statement, "insert", "println", "a_length");
					ArrayStorageLog(pankey_Log_Statement, "insert", "println", a_length);

					ArrayStorageLog(pankey_Log_Statement, "insert", "println", "a_size");
					ArrayStorageLog(pankey_Log_Statement, "insert", "println", a_size);

					ArrayStorageLog(pankey_Log_Statement, "insert", "println", "i_offset");
					ArrayStorageLog(pankey_Log_Statement, "insert", "println", i_offset);

					ArrayStorageLog(pankey_Log_Statement, "insert", "println", "i_size");
					ArrayStorageLog(pankey_Log_Statement, "insert", "println", i_size);

					if(i_size > this->getSize()){
						ArrayStorageLog(pankey_Log_EndMethod, "insert", "println", "i_size > this->getSize()");
						this->expand(i_size - this->getSize() + this->expandRate);
					}

					for(int x = a_length - 1; x >= a_index; x--){
						ArrayStorageLog(pankey_Log_Statement, "insert", "println", "for loop index");
						ArrayStorageLog(pankey_Log_Statement, "insert", "println", x);
						ArrayStorageLog(pankey_Log_Statement, "insert", "println", "for loop offset");
						ArrayStorageLog(pankey_Log_Statement, "insert", "println", i_offset);
						HOLDER_TYPE f_value = this->m_values[x];

						if(i_offset != x){
							ArrayStorageLog(pankey_Log_Statement, "reorder", "println", "i_offset != x");
							this->m_values[i_offset] = f_value;
							this->m_values[x] = nullptr;
						}
						
						i_offset--;
					}
					
					ArrayStorageLog(pankey_Log_EndMethod, "insert", "println", "");
					return i_offset;
				}

				virtual bool expand(int a_size){
					ArrayStorageLog(pankey_Log_StartMethod, "expand", "println", "");
					
					int i_size = this->getSize() + a_size;
					ArrayStorageLog(pankey_Log_Statement, "expand", "println", "List Size:");
					ArrayStorageLog(pankey_Log_Statement, "expand", "println", this->getSize());	
					ArrayStorageLog(pankey_Log_Statement, "expand", "println", "List extra size added:");
					ArrayStorageLog(pankey_Log_Statement, "expand", "println", a_size);
					ArrayStorageLog(pankey_Log_Statement, "expand", "println", "List new size:");
					ArrayStorageLog(pankey_Log_Statement, "expand", "println", i_size);
					if(i_size <= 1){
						ArrayStorageLog(pankey_Log_EndMethod, "expand", "println", "new size is too small");
						return false;
					}
					HOLDER_ARRAY_TYPE nT;
					nT = new HOLDER_TYPE[i_size];
					if(nT == nullptr){
						ArrayStorageLog(pankey_Log_EndMethod, "expand", "println", "new array is null");
						return false;
					}

					ArrayStorageLog(pankey_Log_Statement, "expand", "println", "starting transfer iteration:");

					if(this->m_values != nullptr){
						ArrayStorageLog(pankey_Log_Statement, "expand", "println", "this->m_values != nullptr");
						for(int x = 0; x < this->getSize(); x++){
							ArrayStorageLog(pankey_Log_Statement, "expand", "println", "iteration:");
							ArrayStorageLog(pankey_Log_Statement, "expand", "println", x);
							nT[x] = this->m_values[x];
						}
						delete[] this->m_values;
						this->m_values = nullptr;
					}

					ArrayStorageLog(pankey_Log_Statement, "expand", "println", "starting null iteration:");

					for(int x = this->getSize(); x < i_size; x++){
						ArrayStorageLog(pankey_Log_Statement, "expand", "println", "iteration:");
						ArrayStorageLog(pankey_Log_Statement, "expand", "println", x);
						nT[x] = nullptr;
					}
					this->m_values = nT;
					this->m_size = i_size;
					
					ArrayStorageLog(pankey_Log_Statement, "expand", "println", "List Size:");
					ArrayStorageLog(pankey_Log_Statement, "expand", "println", this->getSize());	
					ArrayStorageLog(pankey_Log_EndMethod, "expand", "println", "");
					return true;
				}

				virtual bool shrink(int a_amount){
					ArrayStorageLog(pankey_Log_StartMethod, "shrink", "println", "");
					if(this->m_values == nullptr || this->getSize() == 0){
						ArrayStorageLog(pankey_Log_EndMethod, "shrink", "println", "this->m_values == nullptr || this->getSize() == 0");
						return false;
					}
					ArrayStorageLog(pankey_Log_Statement, "shrink", "println", "initial m_size:");
					ArrayStorageLog(pankey_Log_Statement, "shrink", "println", this->m_size);
					ArrayStorageLog(pankey_Log_Statement, "shrink", "println", "a_amount that is going to remove:");
					ArrayStorageLog(pankey_Log_Statement, "shrink", "println", a_amount);

					for(int x = this->getSize() - 1; x >= this->getSize() - a_amount && x >= 0; x--){
						ArrayStorageLog(pankey_Log_Statement, "shrink", "println", "index:");
						ArrayStorageLog(pankey_Log_Statement, "shrink", "println", x);
						MemoryHolderManager<H>::remove(this->getManager(), this->m_values[x]);
					}

					this->m_size -= a_amount;
					ArrayStorageLog(pankey_Log_Statement, "shrink", "println", "last m_size:");
					ArrayStorageLog(pankey_Log_Statement, "shrink", "println", this->m_size);

					ArrayStorageLog(pankey_Log_EndMethod, "shrink", "println", "");
					return true;
				}

				virtual bool destroy(){
					ArrayStorageLog(pankey_Log_StartMethod, "destroy", "println", "");
					this->shrink(this->getSize());
					if(this->m_values == nullptr){
						return false;
					}
					delete[] this->m_values;
					this->m_values = nullptr;
					ArrayStorageLog(pankey_Log_EndMethod, "destroy", "println", "");
					return true;
				}

				virtual void setExpansionRate(int a_rate){
					this->expandRate = a_rate;
				}

				virtual int getExpansionRate(){
					return this->expandRate;
				}
			
			protected:
				HOLDER_ARRAY_TYPE m_values = nullptr;
				int expandRate = 5;
		};

	}

#endif