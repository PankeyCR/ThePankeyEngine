
#ifndef ArrayTableStorage_hpp
	#define ArrayTableStorage_hpp

	#include "TableStorage.hpp"
	#include "MemoryHolderManager.hpp"

	#ifdef ArrayTableStorage_LogApp
		#include "pankey_Logger.hpp"
		#define ArrayTableStorageLog(location,method,type,mns) pankey_Log((void*)this,location,"ArrayTableStorage",method,type,mns)
	#else
		#define ArrayTableStorageLog(location,method,type,mns)
	#endif

	namespace pankey{

		template<class H>
		class ArrayTableStorage : virtual public TableStorage<H>{
			public:
                using MANAGER_TYPE = typename TableStorage<H>::MANAGER_TYPE;
                using VOID_TYPE = typename TableStorage<H>::VOID_TYPE;
                using HOLDER_TYPE = typename TableStorage<H>::HOLDER_TYPE;

				ArrayTableStorage(){
					ArrayTableStorageLog(pankey_Log_StartMethod, "Constructor", "println", "");
					ArrayTableStorageLog(pankey_Log_EndMethod, "Constructor", "println", "");
				}

				virtual ~ArrayTableStorage(){
					ArrayTableStorageLog(pankey_Log_StartMethod, "Destructor", "println", "");
					ArrayTableStorageLog(pankey_Log_EndMethod, "Destructor", "println", "");
				}
				
				virtual bool isNull()const{
					ArrayTableStorageLog(pankey_Log_StartMethod, "isNull", "println", "");
					ArrayTableStorageLog(pankey_Log_EndMethod, "isNull", "println", this->m_keys == nullptr || this->m_values == nullptr);
					return this->m_keys == nullptr || this->m_values == nullptr;
				}
				
				virtual bool isNull(int a_index)const{
					ArrayTableStorageLog(pankey_Log_StartMethod, "isNull", "println", "");
					ArrayTableStorageLog(pankey_Log_Statement, "isNull", "println", "Index:");
					ArrayTableStorageLog(pankey_Log_Statement, "isNull", "println", a_index);
					if(this->m_keys == nullptr || this->m_values == nullptr){
						ArrayTableStorageLog(pankey_Log_EndMethod, "isNull", "println", "this->m_values == nullptr");
						return true;
					}
					if(this->getSize() <= 0){
						ArrayTableStorageLog(pankey_Log_EndMethod, "isNull", "println", "this->getSize() < 0");
						return true;
					}
					if(this->m_keys[a_index] == nullptr || this->m_values[a_index] == nullptr){
						ArrayTableStorageLog(pankey_Log_EndMethod, "isNull", "println", "this->m_values[a_index] == nullptr");
						return true;
					}
					ArrayTableStorageLog(pankey_Log_EndMethod, "isNull", "println", "");
					return false;
				}
				
				virtual bool isKeyNull(int a_index)const{
					ArrayTableStorageLog(pankey_Log_StartMethod, "isKeyNull", "println", "");
					ArrayTableStorageLog(pankey_Log_Statement, "isKeyNull", "println", "Index:");
					ArrayTableStorageLog(pankey_Log_Statement, "isKeyNull", "println", a_index);
					if(this->m_keys == nullptr){
						ArrayTableStorageLog(pankey_Log_EndMethod, "isKeyNull", "println", "this->m_values == nullptr");
						return true;
					}
					if(this->getSize() <= 0){
						ArrayTableStorageLog(pankey_Log_EndMethod, "isKeyNull", "println", "this->getSize() < 0");
						return true;
					}
					if(this->m_keys[a_index] == nullptr){
						ArrayTableStorageLog(pankey_Log_EndMethod, "isKeyNull", "println", "this->m_values[a_index] == nullptr");
						return true;
					}
					ArrayTableStorageLog(pankey_Log_EndMethod, "isKeyNull", "println", "");
					return false;
				}
				
				virtual bool isValueNull(int a_index)const{
					ArrayTableStorageLog(pankey_Log_StartMethod, "isValueNull", "println", "");
					ArrayTableStorageLog(pankey_Log_Statement, "isValueNull", "println", "Index:");
					ArrayTableStorageLog(pankey_Log_Statement, "isValueNull", "println", a_index);
					if(this->m_values == nullptr){
						ArrayTableStorageLog(pankey_Log_EndMethod, "isValueNull", "println", "this->m_values == nullptr");
						return true;
					}
					if(this->getSize() <= 0){
						ArrayTableStorageLog(pankey_Log_EndMethod, "isValueNull", "println", "this->getSize() < 0");
						return true;
					}
					if(this->m_values[a_index] == nullptr){
						ArrayTableStorageLog(pankey_Log_EndMethod, "isValueNull", "println", "this->m_values[a_index] == nullptr");
						return true;
					}
					ArrayTableStorageLog(pankey_Log_EndMethod, "isValueNull", "println", "");
					return false;
				}

				virtual bool set(int a_position, const MemoryHolder<H>& a_key, const MemoryHolder<H>& a_value){
					// ArrayTableStorageLog(pankey_Log_StartMethod, "set", "println", "");
					// ArrayTableStorageLog(pankey_Log_Statement, "set", "println", "Position: ");
					// ArrayTableStorageLog(pankey_Log_Statement, "set", "println", a_position);

					// if(this->isNull() || a_position >= this->getSize() || a_position < 0){
					// 	ArrayTableStorageLog(pankey_Log_EndMethod, "set", "println", "this->isNull() || a_position >= this->getSize() || a_position < 0");
					// 	return false;
					// }

					// HOLDER_TYPE i_key_holder = a_key.getHolder();
					// HOLDER_TYPE i_value_holder = a_key.getHolder();

					// ArrayTableStorageLog(pankey_Log_Statement, "set", "println", "Is Key Holder == nullptr");
					// ArrayTableStorageLog(pankey_Log_Statement, "set", "println", i_key_holder == nullptr);

					// ArrayTableStorageLog(pankey_Log_Statement, "set", "println", "Is Value Holder == nullptr");
					// ArrayTableStorageLog(pankey_Log_Statement, "set", "println", i_value_holder == nullptr);

					// if(i_key_holder == this->m_keys[a_position] && i_value_holder == this->m_values[a_position]){
					// 	ArrayTableStorageLog(pankey_Log_EndMethod, "set", "println", "i_holder == this->m_values[a_position]");
					// 	return true;
					// }

					// MemoryHolderManager<H>::add(this->getManager(), i_key_holder);
					// MemoryHolderManager<H>::remove(this->getManager(), this->m_keys[a_position]);

					// MemoryHolderManager<H>::add(this->getManager(), i_value_holder);
					// MemoryHolderManager<H>::remove(this->getManager(), this->m_values[a_position]);
					
					// this->m_keys[a_position] = i_key_holder;
					// this->m_values[a_position] = i_value_holder;

					// ArrayTableStorageLog(pankey_Log_EndMethod, "set", "println", "");
					return true;
				}

				virtual bool add(int a_position, const MemoryHolder<H>& a_key, const MemoryHolder<H>& a_value){
					ArrayTableStorageLog(pankey_Log_StartMethod, "add", "println", "");
					ArrayTableStorageLog(pankey_Log_Statement, "add", "println", "Position: ");
					ArrayTableStorageLog(pankey_Log_Statement, "add", "println", a_position);

					if(this->isNull() || a_position >= this->getSize() || a_position < 0){
						ArrayTableStorageLog(pankey_Log_Statement, "add", "println", "this->isNull() || a_position >= this->getSize() || a_position < 0");
						this->expand(a_position - this->getSize() + this->expandRate);
					}
					ArrayTableStorageLog(pankey_Log_EndMethod, "add", "println", "");
					return this->set(a_position, a_key, a_value);
				}

				virtual bool contain(const MemoryHolder<H>& a_value)const{
					ArrayTableStorageLog(pankey_Log_StartMethod, "contain", "println", "");
					if(this->isNull()){
						ArrayTableStorageLog(pankey_Log_Statement, "contain", "println", "this->isNull()");
						ArrayTableStorageLog(pankey_Log_EndMethod, "contain", "println", "return false");
						return false;
					}

					// VOID_TYPE i_pointer_1 = a_value.getRawPointer();

					// for(int x = 0; x < this->getSize(); x++){
					// 	VOID_TYPE f_pointer_2 = MemoryHolderManager<H>::get(this->getManager(), this->m_values[x]);;
					// 	if(i_pointer_1 == f_pointer_2){
					// 		ArrayTableStorageLog(pankey_Log_Statement, "contain", "println", "a_value == this->m_values[x]");
					// 		ArrayTableStorageLog(pankey_Log_EndMethod, "contain", "println", "return true");
					// 		return true;
					// 	}
					// }

					ArrayTableStorageLog(pankey_Log_EndMethod, "contain", "println", "");
					return false;
				}
				
				virtual int getIndex(const MemoryHolder<H>& a_value)const{
					ArrayTableStorageLog(pankey_Log_StartMethod, "getIndex", "println", "");
					if(this->isNull()){
						ArrayTableStorageLog(pankey_Log_EndMethod, "getIndex", "println", "this->isNull()");
						return -1;
					}

					// VOID_TYPE i_pointer_1 = a_value.getRawPointer();

					// for(int x = 0; x < this->getSize(); x++){
					// 	VOID_TYPE f_pointer_2 = MemoryHolderManager<H>::get(this->getManager(), this->m_values[x]);;
					// 	if(i_pointer_1 == f_pointer_2){
					// 		ArrayTableStorageLog(pankey_Log_EndMethod, "getIndex", "println", "a_value == this->m_values[x]");
					// 		return x;
					// 	}
					// }

					ArrayTableStorageLog(pankey_Log_EndMethod, "getIndex", "println", "");
					return -1;
				}
				
				virtual VOID_TYPE getKeyRawPointer(int a_position)const{
					ArrayTableStorageLog(pankey_Log_StartMethod, "getRawPointer", "println", "");

					// if(this->isNull() || a_position >= this->getSize() || a_position < 0){
					// 	ArrayTableStorageLog(pankey_Log_EndMethod, "getRawPointer", "println", "");
					// 	return nullptr;
					// }

					// ArrayTableStorageLog(pankey_Log_EndMethod, "getRawPointer", "println", "");
					// return MemoryHolderManager<H>::get(this->getManager(), this->m_values[a_position]);
					return nullptr;
				}
				
				virtual VOID_TYPE getValueRawPointer(int a_position)const{
					ArrayTableStorageLog(pankey_Log_StartMethod, "getValueRawPointer", "println", "");

					// if(this->isNull() || a_position >= this->getSize() || a_position < 0){
					// 	ArrayTableStorageLog(pankey_Log_EndMethod, "getRawPointer", "println", "");
					// 	return nullptr;
					// }

					// ArrayTableStorageLog(pankey_Log_EndMethod, "getValueRawPointer", "println", "");
					// return MemoryHolderManager<H>::get(this->getManager(), this->m_values[a_position]);
					return nullptr;
				}
				
				virtual HOLDER_TYPE getKeyHolder(int a_position)const{
					ArrayTableStorageLog(pankey_Log_StartMethod, "get", "println", "");

					// if(this->isNull() || a_position >= this->getSize() || a_position < 0){
					// 	ArrayTableStorageLog(pankey_Log_EndMethod, "get", "println", "");
					// 	return nullptr;
					// }

					// ArrayTableStorageLog(pankey_Log_EndMethod, "get", "println", "");
					// return this->m_values[a_position];
					return nullptr;
				}
				
				virtual HOLDER_TYPE getValueHolder(int a_position)const{
					ArrayTableStorageLog(pankey_Log_StartMethod, "getValueHolder", "println", "");

					// if(this->isNull() || a_position >= this->getSize() || a_position < 0){
					// 	ArrayTableStorageLog(pankey_Log_EndMethod, "getValueHolder", "println", "");
					// 	return nullptr;
					// }

					// ArrayTableStorageLog(pankey_Log_EndMethod, "getValueHolder", "println", "");
					// return this->m_values[a_position];
					return nullptr;
				}

				virtual bool removeByPointer(const MemoryHolder<H>& a_value){
					ArrayTableStorageLog(pankey_Log_StartMethod, "removeByPointer", "println", "");

					// int i_position = this->getIndex(a_value);

					// ArrayTableStorageLog(pankey_Log_Statement, "removeByPointer", "println", "removed position: ");
					// ArrayTableStorageLog(pankey_Log_Statement, "removeByPointer", "println", i_position);

					// if(this->isNull() || i_position >= this->getSize() || i_position < 0){
					// 	ArrayTableStorageLog(pankey_Log_EndMethod, "removeByPointer", "println", "");
					// 	return false;
					// }
					
					// MemoryHolderManager<H>::remove(this->getManager(), this->m_values[i_position]);

					// ArrayTableStorageLog(pankey_Log_EndMethod, "removeByPointer", "println", "");
					return true;
				}

				virtual bool removeFirstIndex(int a_length, int a_amount){
					ArrayTableStorageLog(pankey_Log_StartMethod, "removeFirstIndex", "println", "");

					// if(this->isNull() || a_amount <= 0){
					// 	ArrayTableStorageLog(pankey_Log_EndMethod, "removeFirstIndex", "println", "");
					// 	return false;
					// }

					// if(a_amount > a_length){
					// 	ArrayTableStorageLog(pankey_Log_Statement, "removeFirstIndex", "println", "a_amount > this->getSize()");
					// 	a_amount = a_length;
					// }

					// for(int x = 0; x < a_amount; x++){
					// 	ArrayTableStorageLog(pankey_Log_Statement, "removeFirstIndex", "println", "for loop index");
					// 	ArrayTableStorageLog(pankey_Log_Statement, "removeFirstIndex", "println", x);
					// 	MemoryHolderManager<H>::remove(this->getManager(), this->m_values[x]);
					// }

					// ArrayTableStorageLog(pankey_Log_EndMethod, "removeFirstIndex", "println", "");
					return true;
				}

				virtual bool removeLastIndex(int a_length, int a_amount){
					ArrayTableStorageLog(pankey_Log_StartMethod, "removeLastIndex", "println", "");

					// if(this->isNull() || a_amount < 0){
					// 	ArrayTableStorageLog(pankey_Log_EndMethod, "removeLastIndex", "println", "");
					// 	return false;
					// }

					// if(a_amount > a_length){
					// 	ArrayTableStorageLog(pankey_Log_Statement, "removeFirstIndex", "println", "a_amount > this->getSize()");
					// 	a_amount = a_length;
					// }

					// for(int x = a_length - 1; x >= a_length - a_amount; x--){
					// 	ArrayTableStorageLog(pankey_Log_Statement, "removeLastIndex", "println", "for loop index");
					// 	ArrayTableStorageLog(pankey_Log_Statement, "removeLastIndex", "println", x);
					// 	MemoryHolderManager<H>::remove(this->getManager(), this->m_values[x]);
					// }

					// ArrayTableStorageLog(pankey_Log_EndMethod, "removeLastIndex", "println", "");
					return true;
				}

				virtual bool removePart(int a_index, int a_length, int a_amount){
					ArrayTableStorageLog(pankey_Log_StartMethod, "removePart", "println", "");

					// if(this->isNull() || a_index < 0 || a_amount <= 0){
					// 	ArrayTableStorageLog(pankey_Log_EndMethod, "removePart", "println", "this->isNull() || a_index <= 0 || a_amount <= 0");
					// 	return false;
					// }

					// if(a_index + a_amount > a_length){
					// 	ArrayTableStorageLog(pankey_Log_Statement, "removePart", "println", "a_index + a_amount > a_length");
					// 	ArrayTableStorageLog(pankey_Log_Statement, "removePart", "println", a_index + a_amount);
					// 	a_amount = a_length - a_index;
					// }

					// for(int x = a_index; x < a_index + a_amount; x++){
					// 	ArrayTableStorageLog(pankey_Log_Statement, "removePart", "println", "for loop index");
					// 	ArrayTableStorageLog(pankey_Log_Statement, "removePart", "println", x);
					// 	MemoryHolderManager<H>::remove(this->getManager(), this->m_values[x]);
					// }

					// ArrayTableStorageLog(pankey_Log_EndMethod, "removePart", "println", "");
					return true;
				}

				virtual bool removeFirst(){
					ArrayTableStorageLog(pankey_Log_StartMethod, "removeFirst", "println", "");

					// if(this->isNull() || this->getSize() < 1){
					// 	ArrayTableStorageLog(pankey_Log_EndMethod, "removeFirst", "println", "");
					// 	return false;
					// }
					
					// MemoryHolderManager<H>::remove(this->getManager(), this->m_values[0]);

					// ArrayTableStorageLog(pankey_Log_EndMethod, "removeFirst", "println", "");
					return true;
				}

				virtual bool removeLast(){
					ArrayTableStorageLog(pankey_Log_StartMethod, "removeLast", "println", "");
					// ArrayTableStorageLog(pankey_Log_Statement, "removeLast", "println", "removing index");
					// ArrayTableStorageLog(pankey_Log_Statement, "removeLast", "println", this->getSize() - 1);

					// if(this->isNull() || this->getSize() < 1){
					// 	ArrayTableStorageLog(pankey_Log_EndMethod, "removeLast", "println", "");
					// 	return false;
					// }
					
					// MemoryHolderManager<H>::remove(this->getManager(), this->m_values[this->getSize() - 1]);
					
					// ArrayTableStorageLog(pankey_Log_EndMethod, "removeLast", "println", "");
					return true;
				}

				virtual bool clear(){
					ArrayTableStorageLog(pankey_Log_StartMethod, "clear", "println", "");

					// if(this->isNull()){
					// 	ArrayTableStorageLog(pankey_Log_EndMethod, "clear", "println", "this->isNull()");
					// 	return false;
					// }

					// for(int x = 0; x < this->getSize(); x++){
					// 	ArrayTableStorageLog(pankey_Log_Statement, "clear", "println", "for loop index");
					// 	ArrayTableStorageLog(pankey_Log_Statement, "clear", "println", x);
					// 	MemoryHolderManager<H>::remove(this->getManager(), this->m_values[x]);
					// }

					// ArrayTableStorageLog(pankey_Log_EndMethod, "clear", "println", "");
					return true;
				}

				virtual int reorder(){
					ArrayTableStorageLog(pankey_Log_StartMethod, "reorder", "println", "");

					// if(this->isNull()){
					// 	ArrayTableStorageLog(pankey_Log_EndMethod, "reorder", "println", "this->isNull()");
					// 	return -1;
					// }

					int i_offset = 0;

					// for(int x = 0; x < this->getSize(); x++){
					// 	ArrayTableStorageLog(pankey_Log_Statement, "reorder", "println", "for loop index");
					// 	ArrayTableStorageLog(pankey_Log_Statement, "reorder", "println", x);
					// 	ArrayTableStorageLog(pankey_Log_Statement, "reorder", "println", "for loop i_offset");
					// 	ArrayTableStorageLog(pankey_Log_Statement, "reorder", "println", i_offset);

					// 	HOLDER_TYPE f_value = this->m_values[x];

					// 	if(f_value == nullptr){
					// 		ArrayTableStorageLog(pankey_Log_Statement, "reorder", "println", "f_value == nullptr");
					// 		continue;
					// 	}
						
					// 	if(i_offset != x){
					// 		ArrayTableStorageLog(pankey_Log_Statement, "reorder", "println", "i_offset != x");
					// 		this->m_values[i_offset] = f_value;
					// 		this->m_values[x] = nullptr;
					// 	}

					// 	ArrayTableStorageLog(pankey_Log_Statement, "reorder", "println", "this->m_values[i_offset] = f_value");
					// 	i_offset++;
					// }

					// ArrayTableStorageLog(pankey_Log_EndMethod, "reorder", "println", "");
					return i_offset;
				}

				virtual int reorder(int a_index, int a_length, int a_amount){
					ArrayTableStorageLog(pankey_Log_StartMethod, "reorder", "println", "");

					if(this->isNull()){
						ArrayTableStorageLog(pankey_Log_EndMethod, "reorder", "println", "this->isNull()");
						return -1;
					}

					int i_offset = a_index;

					// if(this->getSize() - a_length < a_amount && a_length < a_index + a_amount){
					// 	ArrayTableStorageLog(pankey_Log_Statement, "reorder", "println", "this->getSize() - a_length < a_amount && a_length < a_index + a_amount");
					// 	ArrayTableStorageLog(pankey_Log_Statement, "reorder", "println", "this->getSize() - a_length");
					// 	ArrayTableStorageLog(pankey_Log_Statement, "reorder", "println", this->getSize() - a_length);
					// 	ArrayTableStorageLog(pankey_Log_Statement, "reorder", "println", "a_amount");
					// 	ArrayTableStorageLog(pankey_Log_Statement, "reorder", "println", a_amount);
					// 	ArrayTableStorageLog(pankey_Log_Statement, "reorder", "println", "a_length");
					// 	ArrayTableStorageLog(pankey_Log_Statement, "reorder", "println", a_length);
					// 	ArrayTableStorageLog(pankey_Log_Statement, "reorder", "println", "a_index + a_amount");
					// 	ArrayTableStorageLog(pankey_Log_Statement, "reorder", "println", a_index + a_amount);
					// 	return -1;
					// }

					// if(a_index + a_amount > a_length){
					// 	ArrayTableStorageLog(pankey_Log_Statement, "reorder", "println", "a_index + a_amount > a_length");
					// 	ArrayTableStorageLog(pankey_Log_Statement, "reorder", "println", a_index + a_amount);
					// 	a_amount = a_length - a_index;
					// }

					// for(int x = a_index + a_amount; x < a_length; x++){
					// 	ArrayTableStorageLog(pankey_Log_Statement, "reorder", "println", "for loop index");
					// 	ArrayTableStorageLog(pankey_Log_Statement, "reorder", "println", x);
					// 	ArrayTableStorageLog(pankey_Log_Statement, "reorder", "println", "for loop i_offset");
					// 	ArrayTableStorageLog(pankey_Log_Statement, "reorder", "println", i_offset);

					// 	HOLDER_TYPE f_value = this->m_values[x];
						
					// 	if(i_offset != x){
					// 		ArrayTableStorageLog(pankey_Log_Statement, "reorder", "println", "i_offset != x");
					// 		this->m_values[i_offset] = f_value;
					// 		this->m_values[x] = nullptr;
					// 	}

					// 	ArrayTableStorageLog(pankey_Log_Statement, "reorder", "println", "this->m_values[i_offset] = f_value");
					// 	i_offset++;
					// }

					// ArrayTableStorageLog(pankey_Log_EndMethod, "reorder", "println", "");
					return i_offset;
				}

				virtual int reorder(int a_index, int a_length){
					return this->reorder(a_index, a_length, 1);
				}

				virtual int insert(int a_index, int a_length, int a_size){
					ArrayTableStorageLog(pankey_Log_StartMethod, "insert", "println", "");

					if(this->isNull()){
						ArrayTableStorageLog(pankey_Log_EndMethod, "insert", "println", "this->isNull()");
						return -1;
					}

					int i_offset = a_size + a_length - 1;
					// int i_size = a_size + a_length;

					// if(i_offset > this->getSize()){
					// 	i_offset = this->getSize() - 1;
					// }

					// ArrayTableStorageLog(pankey_Log_Statement, "insert", "println", "a_index");
					// ArrayTableStorageLog(pankey_Log_Statement, "insert", "println", a_index);

					// ArrayTableStorageLog(pankey_Log_Statement, "insert", "println", "a_length");
					// ArrayTableStorageLog(pankey_Log_Statement, "insert", "println", a_length);

					// ArrayTableStorageLog(pankey_Log_Statement, "insert", "println", "a_size");
					// ArrayTableStorageLog(pankey_Log_Statement, "insert", "println", a_size);

					// ArrayTableStorageLog(pankey_Log_Statement, "insert", "println", "i_offset");
					// ArrayTableStorageLog(pankey_Log_Statement, "insert", "println", i_offset);

					// ArrayTableStorageLog(pankey_Log_Statement, "insert", "println", "i_size");
					// ArrayTableStorageLog(pankey_Log_Statement, "insert", "println", i_size);

					// if(i_size > this->getSize()){
					// 	ArrayTableStorageLog(pankey_Log_EndMethod, "insert", "println", "i_size > this->getSize()");
					// 	this->expand(i_size - this->getSize() + this->expandRate);
					// }

					// for(int x = a_length - 1; x >= a_index; x--){
					// 	ArrayTableStorageLog(pankey_Log_Statement, "insert", "println", "for loop index");
					// 	ArrayTableStorageLog(pankey_Log_Statement, "insert", "println", x);
					// 	ArrayTableStorageLog(pankey_Log_Statement, "insert", "println", "for loop offset");
					// 	ArrayTableStorageLog(pankey_Log_Statement, "insert", "println", i_offset);
					// 	HOLDER_TYPE f_value = this->m_values[x];

					// 	if(i_offset != x){
					// 		ArrayTableStorageLog(pankey_Log_Statement, "reorder", "println", "i_offset != x");
					// 		this->m_values[i_offset] = f_value;
					// 		this->m_values[x] = nullptr;
					// 	}
						
					// 	i_offset--;
					// }
					
					// ArrayTableStorageLog(pankey_Log_EndMethod, "insert", "println", "");
					return i_offset;
				}

				virtual bool expand(int a_size){
					ArrayTableStorageLog(pankey_Log_StartMethod, "expand", "println", "");
					
					int i_size = this->getArraySize() + a_size;
					ArrayTableStorageLog(pankey_Log_Statement, "expand", "println", "List Size:");
					ArrayTableStorageLog(pankey_Log_Statement, "expand", "println", this->getSize());	
					ArrayTableStorageLog(pankey_Log_Statement, "expand", "println", "List extra size added:");
					ArrayTableStorageLog(pankey_Log_Statement, "expand", "println", a_size);
					ArrayTableStorageLog(pankey_Log_Statement, "expand", "println", "List new size:");
					ArrayTableStorageLog(pankey_Log_Statement, "expand", "println", i_size);
					if(i_size <= 1){
						ArrayTableStorageLog(pankey_Log_EndMethod, "expand", "println", "new size is too small");
						return false;
					}
					HOLDER_TYPE** nT = nullptr;
					nT = new HOLDER_TYPE*[i_size];
					if(nT == nullptr){
						ArrayTableStorageLog(pankey_Log_EndMethod, "expand", "println", "new array is null");
						return false;
					}

					// ArrayTableStorageLog(pankey_Log_Statement, "expand", "println", "starting transfer iteration:");

					// if(this->m_values != nullptr){
					// 	ArrayTableStorageLog(pankey_Log_Statement, "expand", "println", "this->m_values != nullptr");
					// 	for(int x = 0; x < this->getSize(); x++){
					// 		ArrayTableStorageLog(pankey_Log_Statement, "expand", "println", "iteration:");
					// 		ArrayTableStorageLog(pankey_Log_Statement, "expand", "println", x);
					// 		nT[x] = this->m_values[x];
					// 	}
					// 	MemoryHolderManager<H>::removeHolderArray(this->getManager(), this->m_values);
					// }

					// ArrayTableStorageLog(pankey_Log_Statement, "expand", "println", "starting null iteration:");

					// for(int x = this->getSize(); x < i_size; x++){
					// 	ArrayTableStorageLog(pankey_Log_Statement, "expand", "println", "iteration:");
					// 	ArrayTableStorageLog(pankey_Log_Statement, "expand", "println", x);
					// 	nT[x] = nullptr;
					// }
					// this->m_values = nT;
					// this->m_size = i_size;
					
					// ArrayTableStorageLog(pankey_Log_Statement, "expand", "println", "List Size:");
					// ArrayTableStorageLog(pankey_Log_Statement, "expand", "println", this->getSize());	
					// ArrayTableStorageLog(pankey_Log_EndMethod, "expand", "println", "");
					return true;
				}

				virtual bool shrink(int a_amount){
					ArrayTableStorageLog(pankey_Log_StartMethod, "shrink", "println", "");
					// if(this->m_values == nullptr || this->getSize() == 0){
					// 	ArrayTableStorageLog(pankey_Log_EndMethod, "shrink", "println", "this->m_values == nullptr || this->getSize() == 0");
					// 	return false;
					// }
					// ArrayTableStorageLog(pankey_Log_Statement, "shrink", "println", "initial m_size:");
					// ArrayTableStorageLog(pankey_Log_Statement, "shrink", "println", this->m_size);
					// ArrayTableStorageLog(pankey_Log_Statement, "shrink", "println", "a_amount that is going to remove:");
					// ArrayTableStorageLog(pankey_Log_Statement, "shrink", "println", a_amount);

					// for(int x = this->getSize() - 1; x >= this->getSize() - a_amount && x >= 0; x--){
					// 	ArrayTableStorageLog(pankey_Log_Statement, "shrink", "println", "index:");
					// 	ArrayTableStorageLog(pankey_Log_Statement, "shrink", "println", x);
					// 	MemoryHolderManager<H>::remove(this->getManager(), this->m_values[x]);
					// }

					// this->m_size -= a_amount;
					// ArrayTableStorageLog(pankey_Log_Statement, "shrink", "println", "last m_size:");
					// ArrayTableStorageLog(pankey_Log_Statement, "shrink", "println", this->m_size);

					// ArrayTableStorageLog(pankey_Log_EndMethod, "shrink", "println", "");
					return true;
				}

				virtual bool destroy(){
					ArrayTableStorageLog(pankey_Log_StartMethod, "destroy", "println", "");
					// this->shrink(this->getSize());
					// MemoryHolderManager<H>::removeHolderArray(this->getManager(), this->m_values);
					// ArrayTableStorageLog(pankey_Log_EndMethod, "destroy", "println", "");
					return true;
				}

				virtual void setExpansionRate(int a_rate){
					this->expandRate = a_rate;
				}

				virtual int getExpansionRate(){
					return this->expandRate;
				}
			
			protected:
				HOLDER_TYPE** m_keys = nullptr;
				HOLDER_TYPE** m_values = nullptr;
				int expandRate = 5;
		};

	}

#endif