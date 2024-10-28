
#ifndef Array_hpp
#define Array_hpp

#include "ArrayIterator.hpp"

#ifdef Array_LogApp
	#include "pankey_Logger.hpp"
	#define ArrayLog(location,method,type,mns) pankey_Log((void*)this,location,"Array",method,type,mns)
#else
	#define ArrayLog(location,method,type,mns)
#endif

#ifdef PointerArray_LogApp
	#include "pankey_Logger.hpp"
	#define PointerArrayLog(location,method,type,mns) pankey_Log((void*)this,location,"Array",method,type,mns)
#else
	#define PointerArrayLog(location,method,type,mns)
#endif


namespace pankey{

template<class T>
class Array{

	protected:
		T* m_t_value = nullptr;
		int m_pos = 0;
		int m_size = 0;
		int m_expandSize = 0;

    public:
		Array(){
			ArrayLog(pankey_Log_StartMethod, "Constructor", "println", "");
			ArrayLog(pankey_Log_Statement, "Constructor", "println", "Default Constructor");
			ArrayLog(pankey_Log_EndMethod, "Constructor", "println", "");
		}

		template<class... args>
		Array(args... xs){
			ArrayLog(pankey_Log_StartMethod, "Constructor", "println", "args... xs");
			T array1[] = {xs...};
			int i_array_length = 0;
			ArrayLog(pankey_Log_Statement, "Constructor", "println", "Array Length:");
			ArrayLog(pankey_Log_Statement, "Constructor", "println", i_array_length);
			for(const T& a : array1){
			  i_array_length++;
			}
			if(i_array_length != 0){
				T* c_pointer = this->createFilledArray(i_array_length);
				int count = 0;
				if(c_pointer != nullptr){
					for(const T& a : array1){
						c_pointer[count] = a;
						count++;
					}
				}
			}
			ArrayLog(pankey_Log_Statement, "Constructor", "println", "Array Position:");
			ArrayLog(pankey_Log_Statement, "Constructor", "println", this->getPosition());
			ArrayLog(pankey_Log_Statement, "Constructor", "println", "Array Size:");
			ArrayLog(pankey_Log_Statement, "Constructor", "println", this->getSize());

			ArrayLog(pankey_Log_EndMethod, "Constructor", "println", "");
		}

		Array(const Array<T>& c_array){
			ArrayLog(pankey_Log_StartMethod, "Constructor", "println", "");
			ArrayLog(pankey_Log_Statement, "Constructor", "println", "const Array& val");
			if(c_array.isEmpty()){
				ArrayLog(pankey_Log_EndMethod, "Constructor", "println", "c_array.isEmpty()");
				return;
			}
			int i_array_length = c_array.getPosition();
			ArrayLog(pankey_Log_Statement, "Constructor", "println", "Array Length:");
			ArrayLog(pankey_Log_Statement, "Constructor", "println", i_array_length);
			this->createArray(i_array_length);
			this->copyPointer(c_array.pointer(), i_array_length);
			this->copyEndValue();
			ArrayLog(pankey_Log_Statement, "Constructor", "println", "Array Position:");
			ArrayLog(pankey_Log_Statement, "Constructor", "println", this->getPosition());
			ArrayLog(pankey_Log_Statement, "Constructor", "println", "Array Size:");
			ArrayLog(pankey_Log_Statement, "Constructor", "println", this->getSize());

			ArrayLog(pankey_Log_EndMethod, "Constructor", "println", "");
		}

		Array(Array<T>&& c_array){
			ArrayLog(pankey_Log_StartMethod, "Constructor", "println", "start");
			ArrayLog(pankey_Log_Statement, "Constructor", "println", "Array&& c_array");
			if(c_array.isEmpty()){
				ArrayLog(pankey_Log_EndMethod, "Constructor", "println", "c_array.isEmpty()");
				return;
			}
			int i_array_length = c_array.getPosition();
			ArrayLog(pankey_Log_Statement, "Constructor", "println", "Array Length:");
			ArrayLog(pankey_Log_Statement, "Constructor", "println", i_array_length);
			this->m_pos = c_array.m_pos;
			this->m_size = c_array.m_size;
			this->m_t_value = c_array.m_t_value;
			c_array.m_t_value = nullptr;
			c_array.m_pos = 0;
			c_array.m_size = 0;
			ArrayLog(pankey_Log_Statement, "Constructor", "println", "Array Position:");
			ArrayLog(pankey_Log_Statement, "Constructor", "println", this->getPosition());
			ArrayLog(pankey_Log_Statement, "Constructor", "println", "Array Size:");
			ArrayLog(pankey_Log_Statement, "Constructor", "println", this->getSize());

			ArrayLog(pankey_Log_EndMethod, "Constructor", "println", "");
		}

		virtual ~Array(){
			ArrayLog(pankey_Log_StartMethod, "Destructor", "println", "");
			ArrayLog(pankey_Log_Statement, "Destructor", "println", "~Array");
			ArrayLog(pankey_Log_Statement, "Destructor", "println", this->getPosition());
			ArrayLog(pankey_Log_Statement, "Destructor", "println", this->getSize());
			this->fix();
			this->erase();
			ArrayLog(pankey_Log_EndMethod, "Destructor", "println", "");
		}

	protected:

		virtual void expandIfNeeded(int a_array_length){
			ArrayLog(pankey_Log_StartMethod, "expandIfNeeded", "println", "");
			ArrayLog(pankey_Log_Statement, "expandIfNeeded", "println", "Array Position:");
			ArrayLog(pankey_Log_Statement, "expandIfNeeded", "println", this->getPosition());
			ArrayLog(pankey_Log_Statement, "expandIfNeeded", "println", "Array Size:");
			ArrayLog(pankey_Log_Statement, "expandIfNeeded", "println", this->getSize());
			if(this->hasReachedFixSize()){
				return;
			}
			int i_availableSize = this->getFreeSpace();
			if(i_availableSize < a_array_length){
				this->expandLocal(a_array_length + m_expandSize);
			}
			ArrayLog(pankey_Log_Statement, "expandIfNeeded", "println", "Array Position:");
			ArrayLog(pankey_Log_Statement, "expandIfNeeded", "println", this->getPosition());
			ArrayLog(pankey_Log_Statement, "expandIfNeeded", "println", "Array Size:");
			ArrayLog(pankey_Log_Statement, "expandIfNeeded", "println", this->getSize());
			ArrayLog(pankey_Log_EndMethod, "expandIfNeeded", "println", "");
		}

		virtual bool hasEndValue()const{
			ArrayLog(pankey_Log_StartMethod, "endValue", "println", "");
			ArrayLog(pankey_Log_EndMethod, "endValue", "println", "");
			return false;
		}

		virtual T endValue()const{
			ArrayLog(pankey_Log_StartMethod, "endValue", "println", "");
			ArrayLog(pankey_Log_EndMethod, "endValue", "println", "");
			return T();
		}

		virtual void copyEndValue()const{
			ArrayLog(pankey_Log_StartMethod, "copyEndValue", "println", "");
			if(this->isEmpty() || !this->hasEndValue()){
				ArrayLog(pankey_Log_EndMethod, "copyEndValue", "println", "");
				return;
			}
			if(this->getPosition() >= this->getSize()){
				ArrayLog(pankey_Log_EndMethod, "copyEndValue", "println", "");
				return;
			}
			this->m_t_value[this->getPosition()] = this->endValue();
			ArrayLog(pankey_Log_EndMethod, "copyEndValue", "println", "");
		}

		virtual void copyEndValue(int a_position)const{
			ArrayLog(pankey_Log_StartMethod, "copyEndValue", "println", "");
			if(this->isEmpty() || !this->hasEndValue()){
				ArrayLog(pankey_Log_EndMethod, "copyEndValue", "println", "");
				return;
			}
			if(a_position >= this->getSize()){
				ArrayLog(pankey_Log_EndMethod, "copyEndValue", "println", "");
				return;
			}
			this->m_t_value[a_position] = this->endValue();
			ArrayLog(pankey_Log_EndMethod, "copyEndValue", "println", "");
		}

		virtual void copyExternEndValue(T* a_arrray, int a_position)const{
			ArrayLog(pankey_Log_StartMethod, "copyExternEndValue", "println", "");
			ArrayLog(pankey_Log_Statement, "copyExternEndValue", "println", "position ");
			ArrayLog(pankey_Log_Statement, "copyExternEndValue", "println", a_position);
			if(a_arrray == nullptr || !this->hasEndValue()){
				ArrayLog(pankey_Log_EndMethod, "copyExternEndValue", "println", "");
				return;
			}
			a_arrray[a_position] = this->endValue();
			ArrayLog(pankey_Log_EndMethod, "copyExternEndValue", "println", "");
		}

		virtual void eraseExternArrayPointer(T* a_t_value){
			ArrayLog(pankey_Log_StartMethod, "eraseExternArrayPointer", "println", "");
			if(a_t_value == nullptr){
				return;
			}
			delete[] a_t_value;
			ArrayLog(pankey_Log_EndMethod, "eraseExternArrayPointer", "println", "");
		}

		virtual T* create(int a_size)const{
			ArrayLog(pankey_Log_StartMethod, "create", "println", "");
			ArrayLog(pankey_Log_EndMethod, "create", "println", "");
			return new T[a_size];
		}

		virtual T* createFilledArray(int a_size){
			ArrayLog(pankey_Log_StartMethod, "createFilledArray", "println", "");
			this->fix();
			this->erase();
			this->m_pos = a_size;
			this->m_size = this->getAvailableSize(this->m_pos);
			this->m_t_value = this->create(this->m_size);
			PointerArrayLog(pankey_Log_EndMethod, "createFilledArray", "println", this->m_t_value);
			ArrayLog(pankey_Log_EndMethod, "createFilledArray", "println", "");
			return this->m_t_value;
		}

		virtual T* createArray(int a_size){
			ArrayLog(pankey_Log_StartMethod, "createArray", "println", "");
			this->fix();
			this->erase();
			int i_pos = a_size;
			this->m_size = this->getAvailableSize(i_pos);
			this->m_t_value = this->create(this->m_size);
			ArrayLog(pankey_Log_EndMethod, "createArray", "println", "");
			return this->m_t_value;
		}

		virtual T* createFilledArray(T* a_array, int a_position){
			ArrayLog(pankey_Log_StartMethod, "createFilledArray", "println", "");
			this->fix();
			this->erase();
			this->m_pos = a_position;
			this->m_size = this->getAvailableSize(this->m_pos);
			this->m_t_value = a_array;
			ArrayLog(pankey_Log_EndMethod, "createFilledArray", "println", "");
			return this->m_t_value;
		}

		virtual T* createArray(T* a_array, int a_size){
			ArrayLog(pankey_Log_StartMethod, "createArray", "println", "");
			this->fix();
			this->erase();
			int i_pos = a_size;
			this->m_size = this->getAvailableSize(i_pos);
			this->m_t_value = a_array;
			ArrayLog(pankey_Log_EndMethod, "createArray", "println", "");
			return this->m_t_value;
		}

		virtual T* createFilledArray(T* a_array, int a_position, int a_size){
			ArrayLog(pankey_Log_StartMethod, "createFilledArray", "println", "");
			this->fix();
			this->erase();
			this->m_pos = a_position;
			this->m_size = a_size;
			this->m_t_value = a_array;
			ArrayLog(pankey_Log_EndMethod, "createFilledArray", "println", "");
			return this->m_t_value;
		}

		virtual T* createArrayClone(int a_size)const{
			ArrayLog(pankey_Log_StartMethod, "createArrayClone", "println", "");
			int i_pos = a_size;
			int i_size = this->getAvailableSize(i_pos);
			T* i_t_value = this->create(i_size);
			ArrayLog(pankey_Log_EndMethod, "createArrayClone", "println", "");
			return i_t_value;
		}

		virtual void copyToExternPointer(T* a_array, T a_value, int a_size){
			ArrayLog(pankey_Log_StartMethod, "copyToExternPointer", "println", "");
			if(a_array == nullptr || m_t_value == nullptr){
				return;
			}
			for(int x = 0; x < a_size; x++){
				a_array[x] = a_value;
			}
			int i_full_size = a_size;
			if(this->hasEndValue()){
				i_full_size--;
			}
			if(this->getPosition() < a_size){
				i_full_size = this->getPosition();
			}
			for(int x = 0; x < i_full_size; x++){
				a_array[x] = m_t_value[x];
			}
			if(this->hasEndValue()){
				a_array[i_full_size] = this->endValue();
			}
			ArrayLog(pankey_Log_EndMethod, "copyToExternPointer", "println", "");
		}

		virtual void copyExternPointer(T* a_array, const T* a_copy, int a_size){
			ArrayLog(pankey_Log_StartMethod, "copyExternPointer", "println", "");
			if(a_array == nullptr || a_copy == nullptr ){
				return;
			}
			for(int x = 0; x < a_size; x++){
				a_array[x] = a_copy[x];
			}
			ArrayLog(pankey_Log_EndMethod, "copyExternPointer", "println", "");
		}

		//Method Functionality: utility - polimorfic - reductive - unit - contruct
		virtual void copyExternPointer(T* a_array, const T* a_copy, int a_start, int a_size){
			ArrayLog(pankey_Log_StartMethod, "copyExternPointer", "println", "");
			if(a_array == nullptr || a_copy == nullptr ){
				return;
			}
			for(int x = 0; x < a_size; x++){
				a_array[x] = a_copy[x + a_start];
			}
			ArrayLog(pankey_Log_EndMethod, "copyExternPointer", "println", "");
		}

		//Method Functionality: utility - polimorfic - reductive - unit - contruct
		virtual void copyExternPointer(T* a_array, const T* a_copy, int a_start_1, int a_start_2, int a_size){
			ArrayLog(pankey_Log_StartMethod, "copyExternPointer", "println", "");
			if(a_array == nullptr || a_copy == nullptr ){
				return;
			}
			for(int x = 0; x < a_size; x++){
				a_array[x + a_start_1] = a_copy[x + a_start_2];
			}
			ArrayLog(pankey_Log_EndMethod, "copyExternPointer", "println", "");
		}

		virtual void copyPointer(const T* a_copy, int a_size){
			ArrayLog(pankey_Log_StartMethod, "copyPointer", "println", "");
			if(this->m_t_value == nullptr || a_copy == nullptr ){
				return;
			}
			if(this->getPosition() + a_size > this->getSize()){
				ArrayLog(pankey_Log_EndMethod, "copyPointer", "println", "this->getPosition() + a_size > this->getSize()");
				return;
			}
			for(int x = 0; x < a_size; x++){
				this->m_t_value[this->m_pos] = a_copy[x];
				this->m_pos++;
			}
			ArrayLog(pankey_Log_EndMethod, "copyPointer", "println", "");
		}

		virtual void copyPointer(const T* a_copy, int a_start, int a_size){
			ArrayLog(pankey_Log_StartMethod, "copyPointer", "println", "");
			if(this->m_t_value == nullptr || a_copy == nullptr ){
				return;
			}
			if(this->getPosition() + a_size > this->getSize()){
				return;
			}
			for(int x = 0; x < a_size; x++){
				this->m_t_value[this->m_pos] = a_copy[x + a_start];
				this->m_pos++;
			}
			ArrayLog(pankey_Log_EndMethod, "copyPointer", "println", "");
		}

		virtual void copyPointer(const T* a_copy, int a_start_1, int a_start_2, int a_size){
			ArrayLog(pankey_Log_StartMethod, "copyPointer", "println", "");
			if(this->m_t_value == nullptr || a_copy == nullptr ){
				return;
			}
			if(a_size + a_start_1 > this->getSize()){
				return;
			}
			for(int x = 0; x < a_size; x++){
				this->m_t_value[x + a_start_1] = a_copy[x + a_start_2];
			}
			ArrayLog(pankey_Log_EndMethod, "copyPointer", "println", "");
		}

		//Method Functionality: utility - polimorfic - reductive - unit - contruct
		virtual void copyExternValue(T* a_array, T a_copy, int a_position){
			ArrayLog(pankey_Log_StartMethod, "copyExternValue", "println", "");
			if(a_array == nullptr){
				return;
			}
			a_array[a_position] = a_copy;
			ArrayLog(pankey_Log_EndMethod, "copyExternValue", "println", "");
		}

		virtual void copyValue(T a_value){
			ArrayLog(pankey_Log_StartMethod, "copyValue", "println", "");
			if(this->m_t_value == nullptr){
				ArrayLog(pankey_Log_EndMethod, "copyValue", "println", "this->m_t_value == nullptr");
				return;
			}
			if(!this->hasAvailableSize()){
				ArrayLog(pankey_Log_EndMethod, "copyValue", "println", "!this->hasAvailableSize()");
				return;
			}
			this->m_t_value[this->m_pos] = a_value;
			this->m_pos++;
			ArrayLog(pankey_Log_Statement, "copyValue", "println", "Position: ");
			ArrayLog(pankey_Log_Statement, "copyValue", "println", this->getPosition());
			ArrayLog(pankey_Log_Statement, "copyValue", "println", "Size: ");
			ArrayLog(pankey_Log_Statement, "copyValue", "println", this->getSize());
			// ArrayLog(pankey_Log_Statement, "copyValue", "println", "value copied");
			// ArrayLog(pankey_Log_Statement, "copyValue", "println", this->m_t_value[this->m_pos]);

			ArrayLog(pankey_Log_EndMethod, "copyValue", "println", "");
		}

		virtual int getAvailableSize(int a_pos)const{
			ArrayLog(pankey_Log_StartMethod, "getAvailableSize", "println", "");
			ArrayLog(pankey_Log_EndMethod, "getAvailableSize", "println", "");
			return a_pos;
		}

		virtual int arrayLength(const T* a_array) const{
			return this->arrayLength(a_array, this->endValue());
		}

		virtual int arrayLength(const T* a_array, T a_end) const{
			if(a_array == nullptr){
				return -1;
			}
			for(int x = 0; x < 10000; x++){
				if(a_array[x] == a_end){
					return x;
				}
			}
			return -2;
		}

		virtual void setPosition(int a_position){
			ArrayLog(pankey_Log_StartMethod, "setPosition", "println", "");
			this->m_pos = a_position;
			ArrayLog(pankey_Log_EndMethod, "setPosition", "println", "");
		}

		virtual void setSize(int a_size){
			ArrayLog(pankey_Log_StartMethod, "setSize", "println", "");
			this->m_size = a_size;
			ArrayLog(pankey_Log_EndMethod, "setSize", "println", "");
		}

	public:

		virtual int getPosition() const{
			return this->m_pos;
		}

		virtual int getSize() const{
			return this->m_size;
		}

		virtual int length(void) const{
			if(this->hasEndValue()){
				return this->m_pos - 1;
			}
			return this->m_pos;
		}

		virtual T* pointer()const{
			ArrayLog(pankey_Log_StartMethod, "pointer", "println", "");
			ArrayLog(pankey_Log_EndMethod, "pointer", "println", "");
			return this->m_t_value;
		}

		virtual T* clonePointer(){
			ArrayLog(pankey_Log_StartMethod, "clonePointer", "println", "");
			if(this->isEmpty()){
				ArrayLog(pankey_Log_EndMethod, "clonePointer", "println", "this->isEmpty()");
				return nullptr;
			}
			PointerArrayLog(pankey_Log_Statement, "clonePointer", "println", this->m_t_value);
			int n_size = this->getPosition();
			ArrayLog(pankey_Log_Statement, "clonePointer", "println", "index position ");
			ArrayLog(pankey_Log_Statement, "clonePointer", "println", n_size);
			int availableSize = this->getAvailableSize(n_size);
			ArrayLog(pankey_Log_Statement, "clonePointer", "println", "availableSize size ");
			ArrayLog(pankey_Log_Statement, "clonePointer", "println", availableSize);
			ArrayLog(pankey_Log_Statement, "clonePointer", "println", "array size ");
			ArrayLog(pankey_Log_Statement, "clonePointer", "println", this->m_size);
			T* cloneArray = this->create(availableSize);
			this->copyExternPointer(cloneArray, this->m_t_value, n_size);
			this->copyExternEndValue(cloneArray, n_size);
			PointerArrayLog(pankey_Log_Statement, "clonePointer", "println", "new pointer");
			PointerArrayLog(pankey_Log_Statement, "clonePointer", "println", cloneArray);
			ArrayLog(pankey_Log_EndMethod, "clonePointer", "println", "");
			return cloneArray;
		}

		virtual T* clonePointer(int a_start, int a_size){
			ArrayLog(pankey_Log_StartMethod, "clonePointer", "println", "start and end");
			if(a_start < 0 || a_start >= this->getPosition() || a_size < 1){
				return nullptr;
			}
			ArrayLog(pankey_Log_Statement, "clonePointer", "println", "new size: ");
			ArrayLog(pankey_Log_Statement, "clonePointer", "println", a_size);
			T* cloneArray = this->createArrayClone(a_size);
			this->copyExternPointer(cloneArray, this->m_t_value, a_start, a_size);
			return cloneArray;
		}

		virtual bool isEmpty() const{
			ArrayLog(pankey_Log_StartMethod, "isEmpty", "println", "");
			ArrayLog(pankey_Log_Statement, "isEmpty", "println", "this->m_pos == 0");
			ArrayLog(pankey_Log_Statement, "isEmpty", "println", this->m_pos == 0);
			ArrayLog(pankey_Log_Statement, "isEmpty", "println", "this->m_t_value == nullptr");
			ArrayLog(pankey_Log_Statement, "isEmpty", "println", this->m_t_value == nullptr);
			ArrayLog(pankey_Log_EndMethod, "isEmpty", "println", "");
			return this->m_pos == 0 || this->m_t_value == nullptr;
		}

		virtual bool set(int a_position, T a_value){
			ArrayLog(pankey_Log_StartMethod, "set", "println", "");
			if(this->isEmpty()){
				return false;
			}
			if(!this->hasAvailableSize(a_position)){
				return false;
			}
			this->m_t_value[a_position] = a_value;
			ArrayLog(pankey_Log_EndMethod, "set", "println", "");
			return true;
		}

		virtual T get(int x) const{
			if(this->m_t_value == nullptr){
				return T();
			}
			if(x >= this->m_pos && this->m_pos > 0){
				return this->m_t_value[this->m_pos - 1];
			}
			if(x < this->m_pos && x >= 0){
				return this->m_t_value[x];
			}
			return T();
		}

		virtual T* getPointer(int x) const{
			if(this->m_t_value == nullptr){
				return nullptr;
			}
			if(x < this->m_pos && x >= 0 && this->m_pos > 0){
				return &this->m_t_value[x];
			}
			return nullptr;
		}

		Array<T> getArrayPart(int start)const{
			ArrayLog(pankey_Log_StartMethod, "getArrayPart", "println", "");
			
			if(this->isEmpty()){
				ArrayLog(pankey_Log_StartMethod, "getArrayPart", "println", "this->isEmpty()");
				return Array<T>();
			}
			
			int t_size = this->length();
			int s_size = t_size - start;
			ArrayLog(pankey_Log_StartMethod, "getArrayPart", "println", "getArrayPart size");
			ArrayLog(pankey_Log_StartMethod, "getArrayPart", "println", s_size);
			T* buff = this->createArrayClone(s_size);
			
			T* i_arrayPointer = this->pointer();

			if(i_arrayPointer == nullptr || buff == nullptr){
				return Array<T>();
			}

			for(int x = start; x < t_size; x++){
				buff[x - start] = i_arrayPointer[x];
			}
			this->copyExternEndValue(buff, s_size);

			Array<T> i_array;
			i_array.addLocalArrayPointer(buff);
			delete[] buff;

			ArrayLog(pankey_Log_EndMethod, "getArrayPart", "println", "");
			return i_array;
		}

		Array<T> getArrayPartBySize(int a_start, int a_size){//subNote
			return this->getArrayPart(a_start, a_start + a_size);
		}

		Array<T> getArrayPartByExtraSpace(int a_start, int a_size){//subNote
			return this->getArrayPart(a_start, this->getPosition() - a_size);
		}

		Array<T> getArrayPartByLastExtraSpace(int a_size){//subNote
			return this->getArrayPart(0, this->getPosition() - a_size);
		}

		Array<T> getArrayPart(int a_start, int a_end){//subNote
			ArrayLog(pankey_Log_StartMethod, "getArrayPart", "println", "");
			
			if(this->isEmpty()){
				ArrayLog(pankey_Log_StartMethod, "getArrayPart", "println", "this->isEmpty()");
				return Array<T>();
			}
			
			// if(a_end > this->getPosition()){
			// 	ArrayLog(pankey_Log_StartMethod, "getArrayPart", "println", "this->isEmpty()");
			// 	return Array<T>();
			// }
			
			int t_size = this->getPosition();
			int s_size = t_size - a_start;
			
			if(a_end < t_size){
				s_size -= this->getPosition() - a_end;
				t_size = a_end;
			}
			
			ArrayLog(pankey_Log_StartMethod, "getArrayPart", "println", "subNote size");
			ArrayLog(pankey_Log_StartMethod, "getArrayPart", "println", s_size);
			T* buff = this->createArrayClone(s_size);
			
			T* i_arrayPointer = this->pointer();

			if(i_arrayPointer == nullptr || buff == nullptr){
				return Array<T>();
			}

			for(int x = a_start; x < t_size; x++){
				buff[x - a_start] = i_arrayPointer[x];
			}
			this->copyExternEndValue(buff, s_size);

			Array<T> i_array;
			i_array.addLocalArrayPointer(buff);
			delete[] buff;
			
			ArrayLog(pankey_Log_EndMethod, "getArrayPart", "println", "");
			return i_array;
		}

		virtual Array<T> addValue(T a_value)const{
			ArrayLog(pankey_Log_StartMethod, "addValue", "println", "const T& a_value");
			Array<T> i_array = *this;
			if(this->hasReachedFixSize()){
				return i_array;
			}
			ArrayLog(pankey_Log_EndMethod, "addValue", "println", "");
			return i_array.addLocalValue(a_value);
		}

		virtual Array<T> addLocalValue(T a_value){
			ArrayLog(pankey_Log_StartMethod, "addLocalValue", "println", "const T& a_value");
			if(this->hasReachedFixSize()){
				return *this;
			}
			ArrayLog(pankey_Log_EndMethod, "addLocalValue", "println", "");
			return this->insertLocalValue(this->getPosition(), a_value);
		}

		virtual Array<T> insertLocalValue(int a_position, T a_value){
			ArrayLog(pankey_Log_StartMethod, "insertLocalValue", "println", "const T& a_value");
			if(this->hasReachedFixSize()){
				return *this;
			}
			int i_array_length = 1;
			ArrayLog(pankey_Log_Statement, "insertLocalValue", "println", "Array Length:");
			ArrayLog(pankey_Log_Statement, "insertLocalValue", "println", i_array_length);
			ArrayLog(pankey_Log_Statement, "insertLocalValue", "println", "Array Position:");
			ArrayLog(pankey_Log_Statement, "insertLocalValue", "println", this->getPosition());
			ArrayLog(pankey_Log_Statement, "insertLocalValue", "println", "Array Size:");
			ArrayLog(pankey_Log_Statement, "insertLocalValue", "println", this->getSize());
			if(this->isEmpty()){
				ArrayLog(pankey_Log_Statement, "insertLocalValue", "println", "this->isEmpty()");
				this->createArray(i_array_length);
				this->copyValue(a_value);
				this->copyEndValue();
				ArrayLog(pankey_Log_EndMethod, "insertLocalValue", "println", "");
				return *this;
			}

			this->expandIfNeeded(i_array_length);

			if(a_position >= this->getPosition()){
				this->copyValue(a_value);
				this->copyEndValue();
				ArrayLog(pankey_Log_EndMethod, "insertLocalValue", "println", "");
				return *this;
			}

			T* i_pointer = this->createArrayClone(i_array_length + this->getPosition());

			this->copyExternPointer(i_pointer, this->pointer(), a_position);
			this->copyExternValue(i_pointer, a_value, a_position);
			this->copyExternPointer(i_pointer, this->pointer(), a_position + i_array_length, a_position, this->getPosition() - a_position);
			this->copyExternEndValue(i_pointer, this->getPosition() + i_array_length);

			this->createFilledArray(i_pointer, this->getPosition() + i_array_length);

			ArrayLog(pankey_Log_Statement, "insertLocalValue", "println", "Array Position:");
			ArrayLog(pankey_Log_Statement, "insertLocalValue", "println", this->getPosition());
			ArrayLog(pankey_Log_Statement, "insertLocalValue", "println", "Array Size:");
			ArrayLog(pankey_Log_Statement, "insertLocalValue", "println", this->getSize());

			ArrayLog(pankey_Log_EndMethod, "insertLocalValue", "println", "");
			return *this;
		}

		virtual Array<T> addArray(const Array<T>& a_array){
			ArrayLog(pankey_Log_StartMethod, "addArray", "println", "");
			if(this->hasReachedFixSize()){
				return *this;
			}
			Array<T> i_array = *this;
			ArrayLog(pankey_Log_EndMethod, "addArray", "println", "");
			return i_array.addLocalArray(a_array);
		}

		virtual Array<T> addLocalArray(const Array<T>& a_array){
			ArrayLog(pankey_Log_StartMethod, "addLocalArray", "println", "const Array<T>& a_array");
			if(this->hasReachedFixSize()){
				return *this;
			}
			ArrayLog(pankey_Log_EndMethod, "addLocalArray", "println", "");
			return this->insertLocalArray(this->getPosition(), a_array);
		}

		virtual Array<T> insertLocalArray(int a_position, const Array<T>& a_array){
			ArrayLog(pankey_Log_StartMethod, "insertLocalArray", "println", "const Array<T>& a_array");
			if(this->hasReachedFixSize()){
				return *this;
			}
			int i_array_length = a_array.getPosition();
			ArrayLog(pankey_Log_Statement, "insertLocalArray", "println", "Array Length:");
			ArrayLog(pankey_Log_Statement, "insertLocalArray", "println", i_array_length);
			ArrayLog(pankey_Log_Statement, "insertLocalArray", "println", "Array Position:");
			ArrayLog(pankey_Log_Statement, "insertLocalArray", "println", this->getPosition());
			ArrayLog(pankey_Log_Statement, "insertLocalArray", "println", "Array Size:");
			ArrayLog(pankey_Log_Statement, "insertLocalArray", "println", this->getSize());
			if(this->isEmpty()){
				this->createArray(i_array_length);
				this->copyPointer(a_array.pointer(), i_array_length);
				this->copyEndValue();
				return *this;
			}
			this->expandIfNeeded(i_array_length);

			if(a_position >= this->getPosition()){
				this->copyPointer(a_array.pointer(), i_array_length);
				this->copyEndValue();
				ArrayLog(pankey_Log_EndMethod, "insertLocalArray", "println", "");
				return *this;
			}

			T* i_pointer = this->createArrayClone(i_array_length + this->getPosition());

			this->copyExternPointer(i_pointer, this->pointer(), a_position);
			this->copyExternPointer(i_pointer, a_array.pointer(), a_position, 0, i_array_length);
			this->copyExternPointer(i_pointer, this->pointer(), a_position + i_array_length, a_position, this->getPosition() - a_position);
			this->copyExternEndValue(i_pointer, this->getPosition() + i_array_length);

			this->createFilledArray(i_pointer, this->getPosition() + i_array_length);

			ArrayLog(pankey_Log_Statement, "insertLocalArray", "println", "Array Position:");
			ArrayLog(pankey_Log_Statement, "insertLocalArray", "println", this->getPosition());
			ArrayLog(pankey_Log_Statement, "insertLocalArray", "println", "Array Size:");
			ArrayLog(pankey_Log_Statement, "insertLocalArray", "println", this->getSize());

			ArrayLog(pankey_Log_EndMethod, "insertLocalArray", "println", "");
			return *this;
		}
		
		virtual Array<T> addArrayPointer(const T* a_pointer)const{
			ArrayLog(pankey_Log_StartMethod, "addArrayPointer", "println", "const char* a_pointer");
			if(this->hasReachedFixSize()){
				return *this;
			}
			ArrayLog(pankey_Log_Statement, "addArrayPointer", "println", "Pointer Array:");
			//ArrayLog(pankey_Log_Statement, "addArrayPointer", "println", a_pointer);
			Array i_array = *this;
			ArrayLog(pankey_Log_EndMethod, "addArrayPointer", "println", "");
			return i_array.addLocalArrayPointer(a_pointer);
		}

		virtual Array<T> addLocalArrayPointer(const T* a_pointer){
			ArrayLog(pankey_Log_StartMethod, "addLocalArrayPointer", "println", "const char* a_pointer");
			if(this->hasReachedFixSize()){
				return *this;
			}
			ArrayLog(pankey_Log_Statement, "addLocalArrayPointer", "println", "Pointer Array:");
			//ArrayLog(pankey_Log_Statement, "addLocalArrayPointer", "println", a_pointer);
			ArrayLog(pankey_Log_EndMethod, "addLocalArrayPointer", "println", "");
			return this->insertLocalArrayPointer(this->getPosition(), a_pointer);
		}

		virtual Array<T> addLocalArrayPointer(const T* a_pointer, int a_size){
			ArrayLog(pankey_Log_StartMethod, "addLocalArrayPointer", "println", "const char* a_pointer");
			if(this->hasReachedFixSize()){
				return *this;
			}
			ArrayLog(pankey_Log_Statement, "addLocalArrayPointer", "println", "Pointer Array:");
			//ArrayLog(pankey_Log_Statement, "addLocalArrayPointer", "println", a_pointer);
			ArrayLog(pankey_Log_EndMethod, "addLocalArrayPointer", "println", "");
			return this->insertLocalArrayPointer(this->getPosition(), a_pointer, a_size);
		}

		virtual Array<T> insertLocalArrayPointer(int a_position, const T* a_pointer){
			ArrayLog(pankey_Log_StartMethod, "insertLocalArrayPointer", "println", "const char* a_pointer");
			if(this->hasReachedFixSize()){
				return *this;
			}
			ArrayLog(pankey_Log_EndMethod, "insertLocalArrayPointer", "println", "");
			return this->insertLocalArrayPointer(a_position, a_pointer, this->arrayLength(a_pointer));
		}

		virtual Array<T> insertLocalArrayPointer(int a_position, const T* a_pointer, int a_size){
			ArrayLog(pankey_Log_StartMethod, "insertLocalArrayPointer", "println", "const char* a_pointer");
			if(this->hasReachedFixSize()){
				return *this;
			}
			ArrayLog(pankey_Log_Statement, "insertLocalArrayPointer", "println", "Pointer Array:");
			PointerArrayLog(pankey_Log_Statement, "insertLocalArrayPointer", "println", a_pointer);
			if(a_pointer == nullptr){
				return *this;
			}
			int i_array_length = this->arrayLength(a_pointer);
			if(i_array_length > a_size){
				i_array_length = a_size;
			}
			if(i_array_length == 0){
				ArrayLog(pankey_Log_Statement, "insertLocalArrayPointer", "println", "i_array_length == 0");
				ArrayLog(pankey_Log_EndMethod, "insertLocalArrayPointer", "println", "");
				return *this;
			}
			ArrayLog(pankey_Log_Statement, "insertLocalArrayPointer", "println", "Array Length:");
			ArrayLog(pankey_Log_Statement, "insertLocalArrayPointer", "println", i_array_length);
			ArrayLog(pankey_Log_Statement, "insertLocalArrayPointer", "println", "Array Position:");
			ArrayLog(pankey_Log_Statement, "insertLocalArrayPointer", "println", this->getPosition());
			ArrayLog(pankey_Log_Statement, "insertLocalArrayPointer", "println", "Array Size:");
			ArrayLog(pankey_Log_Statement, "insertLocalArrayPointer", "println", this->getSize());
			if(this->isEmpty()){
				ArrayLog(pankey_Log_Statement, "insertLocalArrayPointer", "println", "this->isEmpty()");
				this->createArray(i_array_length);
				this->copyPointer(a_pointer, i_array_length);
				this->copyEndValue();
				ArrayLog(pankey_Log_Statement, "insertLocalArrayPointer", "println", "Array Position:");
				ArrayLog(pankey_Log_Statement, "insertLocalArrayPointer", "println", this->getPosition());
				ArrayLog(pankey_Log_Statement, "insertLocalArrayPointer", "println", "Array Size:");
				ArrayLog(pankey_Log_Statement, "insertLocalArrayPointer", "println", this->getSize());
				PointerArrayLog(pankey_Log_Statement, "insertLocalArrayPointer", "println", this->m_t_value);
				ArrayLog(pankey_Log_EndMethod, "insertLocalArrayPointer", "println", "");
				return *this;
			}
			this->expandIfNeeded(i_array_length);
			
			if(a_position >= this->getPosition()){
				ArrayLog(pankey_Log_Statement, "insertLocalArrayPointer", "println", "a_position >= this->getPosition()");
				this->copyPointer(a_pointer, i_array_length);
				this->copyEndValue();
				ArrayLog(pankey_Log_Statement, "insertLocalArrayPointer", "println", "Array Position:");
				ArrayLog(pankey_Log_Statement, "insertLocalArrayPointer", "println", this->getPosition());
				ArrayLog(pankey_Log_Statement, "insertLocalArrayPointer", "println", "Array Size:");
				ArrayLog(pankey_Log_Statement, "insertLocalArrayPointer", "println", this->getSize());
				ArrayLog(pankey_Log_EndMethod, "insertLocalArrayPointer", "println", "");
				return *this;
			}

			T* i_pointer = this->createArrayClone(i_array_length + this->getPosition());

			this->copyExternPointer(i_pointer, this->pointer(), a_position);
			this->copyExternPointer(i_pointer, a_pointer, a_position, 0, i_array_length);
			this->copyExternPointer(i_pointer, this->pointer(), a_position + i_array_length, a_position, this->getPosition() - a_position);
			this->copyExternEndValue(i_pointer, this->getPosition() + i_array_length);

			this->createFilledArray(i_pointer, this->getPosition() + i_array_length);
			
			ArrayLog(pankey_Log_Statement, "insertLocalArrayPointer", "println", "a_position < this->getPosition()");
			ArrayLog(pankey_Log_Statement, "insertLocalArrayPointer", "println", "Array Position:");
			ArrayLog(pankey_Log_Statement, "insertLocalArrayPointer", "println", this->getPosition());
			ArrayLog(pankey_Log_Statement, "insertLocalArrayPointer", "println", "Array Size:");
			ArrayLog(pankey_Log_Statement, "insertLocalArrayPointer", "println", this->getSize());
			
			ArrayLog(pankey_Log_EndMethod, "insertLocalArrayPointer", "println", "");
			return *this;
		}

		virtual Array<T> addLocal(){
			ArrayLog(pankey_Log_StartMethod, "addLocal", "println", "");
			if(this->hasReachedFixSize()){
				return *this;
			}
			if(this->isEmpty()){
				return *this;
			}
			int i_size = this->getPosition();
			T* i_t_value = this->clonePointer();
			if(this->m_size - this->m_pos < 1){
				expandLocal(i_size + this->m_expandSize);
			}
			this->copyPointer(i_t_value, i_size);
			this->eraseExternArrayPointer(i_t_value);
			ArrayLog(pankey_Log_EndMethod, "addLocal", "println", "");
			return *this;
		}

		virtual ArrayIterator<T> begin() const{
			return ArrayIterator<T>(this->m_t_value,0);
		}
		virtual ArrayIterator<T> end() const{
			return ArrayIterator<T>(this->m_t_value, this->m_pos);
		}

		virtual bool contain(const T& a_value){
			ArrayLog(pankey_Log_StartMethod, "contain", "println", "");
			if(this->isEmpty()){
				return false;
			}

			ArrayLog(pankey_Log_Statement, "contain", "println", "Array Position:");
			ArrayLog(pankey_Log_Statement, "contain", "println", this->getPosition());
			ArrayLog(pankey_Log_Statement, "contain", "println", "Array Size:");
			ArrayLog(pankey_Log_Statement, "contain", "println", this->getSize());

			for(int x = 0; x < this->m_pos; x++){
				if(this->m_t_value[x] == a_value){
					ArrayLog(pankey_Log_EndMethod, "contain", "println", "return true");
					return true;
				}
			}
			ArrayLog(pankey_Log_EndMethod, "contain", "println", "return false");
			return false;
		}

		virtual int getFirstIndex(const T& a_value){
			ArrayLog(pankey_Log_StartMethod, "getFirstIndex", "println", "");
			if(this->isEmpty()){
				ArrayLog(pankey_Log_EndMethod, "getFirstIndex", "println", "");
				return -1;
			}
			for(int x = 0; x < this->m_pos; x++){
				if(this->m_t_value[x] == a_value){
					return x;
				}
			}
			return -1;
			ArrayLog(pankey_Log_EndMethod, "getFirstIndex", "println", "");
		}

		virtual int getLastIndex(const T& a_value){
			ArrayLog(pankey_Log_StartMethod, "getLastIndex", "println", "");
			if(this->isEmpty()){
				ArrayLog(pankey_Log_EndMethod, "getLastIndex", "println", "");
				return -1;
			}
			for(int x = this->m_pos - 1; x >= 0; x--){
				if(this->m_t_value[x] == a_value){
					return x;
				}
			}
			return -1;
			ArrayLog(pankey_Log_EndMethod, "getLastIndex", "println", "");
		}

		virtual bool remove(int a_index){
			ArrayLog(pankey_Log_StartMethod, "remove", "println", "");
			if(a_index == -1 || a_index >= this->m_pos || this->isEmpty()){
				return false;
			}
			if(this->removeShrink){
				int i_pos = this->m_pos - 1;
				T* i_copy = this->createArrayClone(i_pos);
				int x_count = 0;
				for(int x = 0; x < this->m_pos; x++){
					if(a_index != x){
						i_copy[x_count] = this->m_t_value[x];
						x_count++;
					}
				}
				this->createFilledArray(i_copy, i_pos);
				this->copyEndValue();
			}else{

			}
			return true;
			ArrayLog(pankey_Log_EndMethod, "remove", "println", "");
		}

		virtual bool remove(int a_index, int a_size){
			ArrayLog(pankey_Log_StartMethod, "remove", "println", "");
			if(a_index == -1 || a_index >= this->m_pos || this->isEmpty()){
				return false;
			}
			if(this->removeShrink){
				int i_pos = this->m_pos - a_size;
				T* i_copy = this->createArrayClone(i_pos);
				int x_count = 0;
				for(int x = 0; x < a_index; x++){
					i_copy[x_count] = this->m_t_value[x];
					x_count++;
				}
				for(int x = a_index + a_size; x < this->getPosition(); x++){
					i_copy[x_count] = this->m_t_value[x];
					x_count++;
				}
				this->createFilledArray(i_copy, x_count);
				this->copyEndValue();
			}else{

			}
			return true;
			ArrayLog(pankey_Log_EndMethod, "remove", "println", "");
		}

		virtual void removeFirst(const T& a_value){
			ArrayLog(pankey_Log_StartMethod, "removeFirst", "println", "");
			int index = getFirstIndex(a_value);
			if(index == -1){
				return;
			}
			this->remove(index);
			ArrayLog(pankey_Log_EndMethod, "removeFirst", "println", "");
		}

		virtual void removeLast(const T& a_value){
			ArrayLog(pankey_Log_StartMethod, "removeLast", "println", "");
			int index = getLastIndex(a_value);
			if(index == -1){
				return;
			}
			this->remove(index);
			ArrayLog(pankey_Log_EndMethod, "removeLast", "println", "");
		}

		virtual Array<T> removeAllInitialValues(const T& a_value) const{
			ArrayLog(pankey_Log_StartMethod, "removeAllInitialValues", "println", "");

			Array<T> i_array;
			int i_start_cut = 0;

			ArrayLog(pankey_Log_Statement, "removeAllInitialValues", "println", "this->length()");
			ArrayLog(pankey_Log_Statement, "removeAllInitialValues", "println", this->length());

			for(int x = 0; x < this->length(); x++){
				const T f_val = this->m_t_value[x];
				if(f_val == a_value){
					i_start_cut++;
				}else{
					break;
				}
			}

			ArrayLog(pankey_Log_Statement, "removeAllInitialValues", "println", "i_start_cut");
			ArrayLog(pankey_Log_Statement, "removeAllInitialValues", "println", i_start_cut);

			for(int x = i_start_cut; x < this->length(); x++){
				const T f_val = this->m_t_value[x];
				i_array.addLocalValue(f_val);
				if(x == this->length() - 1 && this->hasEndValue()){
					ArrayLog(pankey_Log_Statement, "removeAllInitialValues", "println", "adding end value");
					i_array.addLocalValue(this->endValue());
				}
			}

			ArrayLog(pankey_Log_EndMethod, "removeAllInitialValues", "println", "");
			return i_array;
		}

		virtual Array<T> removeAllEndingValues(const T& a_value) const{
			ArrayLog(pankey_Log_StartMethod, "removeAllEndingValues", "println", "");

			Array<T> i_array;
			int i_end_cut = 0;

			for(int x = this->length() - 1; x >= 0; x--){
				const T f_val = this->m_t_value[x];
				if(f_val == a_value){
					i_end_cut++;
				}else{
					break;
				}
			}

			for(int x = 0; x < this->length() - i_end_cut; x++){
				const T f_val = this->m_t_value[x];
				i_array.addLocalValue(f_val);
				if(x == this->length() - i_end_cut - 1 && this->hasEndValue()){
					i_array.addLocalValue(this->endValue());
				}
			}

			ArrayLog(pankey_Log_EndMethod, "removeAllEndingValues", "println", "");
			return i_array;
		}

		virtual Array<T> removeAllInitialAndEndingValues(const T& a_value) const{
			ArrayLog(pankey_Log_StartMethod, "removeAllInitialAndEndingValues", "println", "");

			Array<T> i_array;
			int i_start_cut = 0;

			for(int x = 0; x < this->length(); x++){
				const T f_val = this->m_t_value[x];
				if(f_val == a_value){
					i_start_cut++;
				}else{
					break;
				}
			}

			int i_end_cut = 0;

			for(int x = this->length() - 1; x >= 0; x--){
				const T f_val = this->m_t_value[x];
				if(f_val == a_value){
					i_end_cut++;
				}else{
					break;
				}
			}

			for(int x = i_start_cut; x < this->length() - i_end_cut; x++){
				const T f_val = this->m_t_value[x];
				i_array.addLocalValue(f_val);
				if(x == this->length() - i_end_cut - 1 && this->hasEndValue()){
					i_array.addLocalValue(this->endValue());
				}
			}

			ArrayLog(pankey_Log_EndMethod, "removeAllInitialAndEndingValues", "println", "");
			return i_array;
		}

		virtual void removeFirstIndex(){
			ArrayLog(pankey_Log_StartMethod, "removeFirstIndex", "println", "");
			if(this->isEmpty()){
				return;
			}
			this->remove(0);
			ArrayLog(pankey_Log_EndMethod, "removeFirstIndex", "println", "");
		}

		virtual void removeLastIndex(){
			ArrayLog(pankey_Log_StartMethod, "removeLastIndex", "println", "");
			if(this->isEmpty()){
				return;
			}
			this->remove(this->getPosition() - 1);
			ArrayLog(pankey_Log_EndMethod, "removeLastIndex", "println", "");
		}

		Array<T> split(int a_position, T a_split) const{
			ArrayLog(pankey_Log_StartMethod, "split", "println", "");
			Array<T> i_array_cut;
			Array<T> i_array_part;
			int i_position = 0;

			i_array_cut = this->removeAllInitialAndEndingValues(a_split);

			for(int x = 0; x < i_array_cut.getPosition(); x++){
				ArrayLog(pankey_Log_Statement, "split", "println", "iteration: ");
				ArrayLog(pankey_Log_Statement, "split", "println", x);
				const T f_val = i_array_cut.m_t_value[x];
				ArrayLog(pankey_Log_Statement, "split", "println", "char: ");
				ArrayLog(pankey_Log_Statement, "split", "println", f_val);
				ArrayLog(pankey_Log_Statement, "split", "println", "i_array_part: ");
				// ArrayLog(pankey_Log_Statement, "split", "println", i_array_part.pointer());
				if(f_val == a_split){
					ArrayLog(pankey_Log_Statement, "split", "println", "f_val == a_split");
					i_position++;
					ArrayLog(pankey_Log_Statement, "split", "println", "end for loop");
					continue;
				}
				if(i_position == a_position){
					ArrayLog(pankey_Log_Statement, "split", "println", "f_val == a_split");
					i_array_part.addLocalValue(f_val);
					ArrayLog(pankey_Log_Statement, "split", "println", "i_array_part: ");
					// ArrayLog(pankey_Log_Statement, "split", "println", i_array_part.pointer());
					ArrayLog(pankey_Log_Statement, "split", "println", "end for loop");
					continue;
				}
				if(i_position > a_position){
					ArrayLog(pankey_Log_Statement, "split", "println", "i_position > a_position");
					ArrayLog(pankey_Log_Statement, "split", "println", "end for loop");
					break;
				}
				ArrayLog(pankey_Log_Statement, "split", "println", "end for loop");
			}
			ArrayLog(pankey_Log_EndMethod, "split", "println", "");
			return i_array_part;
		}

		//gets the amount of times it gets splits, ignorring extra split values at the start and the end
		int getSplitSize(T a_split) const{
			ArrayLog(pankey_Log_StartMethod, "getSplitSize", "println", "");
			if(this->isEmpty()){
				return 0;
			}
			int i_size = 0;
			Array<T> i_array_part = this->removeAllInitialAndEndingValues(a_split);

			for(int x = 0; x < i_array_part.getPosition(); x++){
				T f_val = i_array_part.get(x);
				if(f_val == a_split){
					i_size++;
				}
			}

			ArrayLog(pankey_Log_EndMethod, "getSplitSize", "println", "");
			return i_size;
		}

		//gets the amount of parts it gets splits on
		int getPartSize(T a_split) const{
			ArrayLog(pankey_Log_StartMethod, "getPartSize", "println", "");
			if(this->isEmpty()){
				return 0;
			}
			Array<T> i_array_part = this->removeAllInitialAndEndingValues(a_split);

			int i_size = 1;
			for(int x = 0; x < i_array_part.getPosition(); x++){
				T f_val = i_array_part.get(x);
				if(f_val == a_split){
					i_size++;
				}
			}

			ArrayLog(pankey_Log_EndMethod, "getPartSize", "println", "");
			return i_size;
		}
/*
		Array<Array<T>> split(const T& divide){

		}

		Array<T> split(const T& divide, int parte){

		}

		int splitLenght(const T& divide){

		}*/

		virtual void fixSize(int a_length){
			ArrayLog(pankey_Log_StartMethod, "fixSize", "println", "");
			m_fix_length = a_length;
			ArrayLog(pankey_Log_EndMethod, "fixSize", "println", "");
		}

		virtual void setFixSize(int a_length){
			ArrayLog(pankey_Log_StartMethod, "setFixSize", "println", "");
			m_fix_length = a_length;
			expandLocal(a_length);
			ArrayLog(pankey_Log_EndMethod, "setFixSize", "println", "");
		}

		virtual bool hasReachedFixSize()const{
			ArrayLog(pankey_Log_StartMethod, "hasReachedFixSize", "println", "");
			ArrayLog(pankey_Log_Statement, "hasReachedFixSize", "println", "m_fix_length:");
			ArrayLog(pankey_Log_Statement, "hasReachedFixSize", "println", m_fix_length);
			ArrayLog(pankey_Log_Statement, "hasReachedFixSize", "println", "this->length():");
			ArrayLog(pankey_Log_Statement, "hasReachedFixSize", "println", this->length());
			ArrayLog(pankey_Log_Statement, "hasReachedFixSize", "println", "this->getPosition():");
			ArrayLog(pankey_Log_Statement, "hasReachedFixSize", "println", this->getPosition());
			ArrayLog(pankey_Log_Statement, "hasReachedFixSize", "println", "this->getSize():");
			ArrayLog(pankey_Log_Statement, "hasReachedFixSize", "println", this->getSize());
			ArrayLog(pankey_Log_Statement, "hasReachedFixSize", "println", "has reached fix size:");
			ArrayLog(pankey_Log_Statement, "hasReachedFixSize", "println", this->length() >= m_fix_length);
			if(m_fix_length == -1){
				ArrayLog(pankey_Log_EndMethod, "hasReachedFixSize", "println", "m_fix_length == -1");
				return false;
			}
			ArrayLog(pankey_Log_EndMethod, "hasReachedFixSize", "println", "");
			return this->length() >= m_fix_length || this->getPosition() >= m_fix_length;
		}

		virtual int getFreeSpace(int a_position)const{
			ArrayLog(pankey_Log_StartMethod, "getFreeSpace", "println", "int a_position");
			int i_addingEndValue = 0;
			if(this->hasEndValue()){
				ArrayLog(pankey_Log_Statement, "getFreeSpace", "println", "this->hasEndValue()");
				i_addingEndValue = 1;
			}
			int i_availableSize = this->getSize() - a_position - i_addingEndValue;
			ArrayLog(pankey_Log_EndMethod, "getFreeSpace", "println", i_availableSize);
			return i_availableSize;
		}

		virtual int getFreeSpace()const{
			ArrayLog(pankey_Log_StartMethod, "getFreeSpace", "println", "");
			int i_addingEndValue = 0;
			if(this->hasEndValue()){
				ArrayLog(pankey_Log_Statement, "getFreeSpace", "println", "this->hasEndValue()");
				i_addingEndValue = 1;
			}
			int i_availableSize = this->getSize() - this->getPosition() - i_addingEndValue;
			ArrayLog(pankey_Log_EndMethod, "getFreeSpace", "println", i_availableSize);
			return i_availableSize;
		}

		virtual bool hasAvailableSize()const{
			ArrayLog(pankey_Log_StartMethod, "hasAvailableSize", "println", "");
			ArrayLog(pankey_Log_Statement, "hasAvailableSize", "println", "Array Position:");
			ArrayLog(pankey_Log_Statement, "hasAvailableSize", "println", this->getPosition());
			ArrayLog(pankey_Log_Statement, "hasAvailableSize", "println", "Array Size:");
			ArrayLog(pankey_Log_Statement, "hasAvailableSize", "println", this->getSize());
			return this->getFreeSpace() > 0;
		}

		virtual bool hasAvailableSize(int a_size)const{
			ArrayLog(pankey_Log_StartMethod, "hasAvailableSize", "println", "int a_size");
			ArrayLog(pankey_Log_Statement, "hasAvailableSize", "println", "New Size:");
			ArrayLog(pankey_Log_Statement, "hasAvailableSize", "println", a_size);
			ArrayLog(pankey_Log_Statement, "hasAvailableSize", "println", "Array Size:");
			ArrayLog(pankey_Log_Statement, "hasAvailableSize", "println", this->getSize());
			return this->getFreeSpace(a_size) > 0;
		}

		virtual void fix(){
			ArrayLog(pankey_Log_StartMethod, "fix", "println", "");
			ArrayLog(pankey_Log_EndMethod, "fix", "println", "");
		}

		virtual void erase(){
			ArrayLog(pankey_Log_StartMethod, "erase", "println", "");
			if(this->m_t_value == nullptr){
				this->m_pos = 0;
				this->m_size = 0;
				ArrayLog(pankey_Log_EndMethod, "erase", "println", "this->m_t_value == nullptr");
				return;
			}
			delete[] this->m_t_value;
			this->m_t_value = nullptr;
			this->m_pos = 0;
			this->m_size = 0;
			ArrayLog(pankey_Log_EndMethod, "erase", "println", "");
		}

		virtual void fill(T a_fill){
			ArrayLog(pankey_Log_StartMethod, "fill", "println", "");
			if(this->isEmpty()){
				return;
			}
			for(int x = 0; x < this->getPosition(); x++){
				this->m_t_value[x] = a_fill;
			}
			ArrayLog(pankey_Log_EndMethod, "fill", "println", "");
		}

		virtual void clear(){
			ArrayLog(pankey_Log_StartMethod, "clear", "println", "");
			if(this->m_t_value == nullptr){
				this->m_pos = 0;
				this->m_size = 0;
				return;
			}
			delete[] this->m_t_value;
			this->m_t_value = nullptr;
			this->m_pos = 0;
			this->m_size = 0;
			ArrayLog(pankey_Log_EndMethod, "clear", "println", "");
		}

		virtual void expandLocal(int a_size){
			ArrayLog(pankey_Log_StartMethod, "expandLocal", "println", "");
			if(this->hasReachedFixSize()){
				return;
			}
			int nsize = this->getSize() + a_size;
			T *nT = new T[nsize];
			for(int x = 0; x < this->m_pos; x++){
				nT[x] = this->m_t_value[x];
			}
			if(this->m_t_value != nullptr){
				delete[] this->m_t_value;
			}
			this->m_t_value = nT;
			this->setSize(nsize);
			ArrayLog(pankey_Log_EndMethod, "expandLocal", "println", "");
		}

		////////////////////////////operator part////////////////////////////////////////////////////////////////

	public:

		virtual Array<T>& operator=(const Array<T>& a_array){
			ArrayLog(pankey_Log_StartMethod, "operator=", "println", "operator= const Array<T>&");
			this->fix();
			this->erase();

			if(a_array.isEmpty()){
				ArrayLog(pankey_Log_EndMethod, "operator=", "println", "a_array.isEmpty()");
				return *this;
			}
			int i_array_length = a_array.getPosition();
			this->createArray(i_array_length);
			this->copyPointer(a_array.pointer(), i_array_length);
			this->copyEndValue();
			ArrayLog(pankey_Log_EndMethod, "operator=", "println", "");
			return *this;
		}

		virtual Array<T> operator=(T a_value){
			ArrayLog(pankey_Log_StartMethod, "operator=", "println", "operator= const T&");
			this->fix();
			this->erase();
			this->createArray(1);
			this->copyValue(a_value);
			this->copyEndValue();
			//ArrayLog(pankey_Log_Statement, "operator=", "println", a_value);
			ArrayLog(pankey_Log_EndMethod, "operator=", "println", "");
			return *this;
		}

		virtual Array<T> operator+=(const Array<T>& a_value){
			ArrayLog(pankey_Log_StartMethod, "operator+=", "println", "const Array<T>& a_value");
			ArrayLog(pankey_Log_EndMethod, "operator+=", "println", "");
			return this->addLocalArray(a_value);
		}

		virtual Array<T> operator+(const Array<T>& a_value){
			ArrayLog(pankey_Log_StartMethod, "operator+", "println", "const Array<T>& a_value");
			Array<T> i_array = *this;
			ArrayLog(pankey_Log_EndMethod, "operator+", "println", "");
			return i_array.addArray(a_value);
		}

		virtual Array<T> operator+=(T a_value){
			ArrayLog(pankey_Log_StartMethod, "operator+=", "println", "T a_value");
			ArrayLog(pankey_Log_EndMethod, "operator+=", "println", "");
			return this->addLocalValue(a_value);
		}

		virtual Array<T> operator+(T a_value){
			ArrayLog(pankey_Log_StartMethod, "operator+", "println", "T a_value");
			Array<T> i_array = *this;
			ArrayLog(pankey_Log_EndMethod, "operator+", "println", "");
			return i_array.addValue(a_value);
		}

		virtual bool operator==(const Array<T>& o_array)const{
			ArrayLog(pankey_Log_StartMethod, "operator==", "println", "const Array<T>& o_array");
			
			if(o_array.getPosition() != this->getPosition()){
				return false;
			}
			for(int x = 0; x < this->getPosition(); x++){
				if(o_array.get(x) != this->get(x)){
					return false;
				}
			}

			ArrayLog(pankey_Log_EndMethod, "operator==", "println", "");
			return true;
		}

		virtual bool operator!=(const Array<T>& o_array)const{
			ArrayLog(pankey_Log_StartMethod, "operator!=", "println", "const Array<T>& o_array");
			
			if(o_array.getPosition() != this->getPosition()){
				return true;
			}
			for(int x = 0; x < this->getPosition(); x++){
				if(o_array.get(x) != this->get(x)){
					return true;
				}
			}

			ArrayLog(pankey_Log_EndMethod, "operator!=", "println", "");
			return false;
		}

		virtual bool operator==(const T& a_value){
			ArrayLog(pankey_Log_StartMethod, "operator==", "println", "const T& a_value");
			
			if(this->length() != 1){
				return false;
			}

			ArrayLog(pankey_Log_EndMethod, "operator==", "println", "");
			return this->get(0) == a_value;
		}
		
		virtual bool operator!=(const T& a_value){
			ArrayLog(pankey_Log_StartMethod, "operator!=", "println", "const T& a_value");
			
			if(this->length() != 1){
				return true;
			}

			ArrayLog(pankey_Log_EndMethod, "operator!=", "println", "");
			return this->get(0) != a_value;
		}

		virtual T& operator[](int x){
			ArrayLog(pankey_Log_StartMethod, "operator[]", "println", "");
			if(x > this->m_pos && this->m_pos > 0){
				return this->m_t_value[this->m_pos - 1];
			}
			if(x < this->m_pos && x >= 0){
				return this->m_t_value[x];
			}
			if(x >= this->m_size){
				expandLocal((x - this->m_size + 1) + this->m_expandSize);
			}
			if(this->m_pos == x){
				this->m_pos++;
			}
			ArrayLog(pankey_Log_EndMethod, "operator[]", "println", "");
			return this->m_t_value[x];
		}

		virtual T operator[](int x) const{
			if(this->m_t_value == nullptr){
				return T();
			}
			if(x >= this->m_pos && this->m_pos > 0){
				return this->m_t_value[this->m_pos - 1];
			}
			if(x < this->m_pos && x >= 0){
				return this->m_t_value[x];
			}
			return T();
		}
/*
		void replace(Array a_search, Array a_change){
			ArrayLog(pankey_Log_StartMethod, "replace", "println", "");
			ArrayLog(pankey_Log_Statement, "replace", "println", "");
			Array i_Array;
			Array i_search;
			int i_search_index = 0;

			if(isEmpty()){
				return;
			}

			ArrayLog(pankey_Log_Statement, "replace", "println", "start for");
			for(int x = 0; x < this->m_pos; x++){
				ArrayLog(pankey_Log_Statement, "replace", "println", pankey_String("iteration ") + pankey_String(x));
				char cr = charAt(x);
				char schr = a_search.charAt(i_search_index);
				ArrayLog(pankey_Log_Statement, "replace", "println", pankey_String("Arrays char: ") + pankey_String((char)cr));
				ArrayLog(pankey_Log_Statement, "replace", "println", pankey_String("searche char: ") + pankey_String((char)schr));
				if(schr == cr){
					ArrayLog(pankey_Log_Statement, "replace", "println", "schr == cr");
					i_search_index++;
					i_search += schr;
				}else{
					ArrayLog(pankey_Log_Statement, "replace", "println", "schr != cr");
					if(i_search_index > 0){
						ArrayLog(pankey_Log_Statement, "replace", "println", "i_search_index > 0");
						i_search_index = 0;
						i_Array += i_search;
						i_search = "";
					}
					i_Array += cr;
				}
				if(i_search_index == a_search.getPosition()){
					ArrayLog(pankey_Log_Statement, "replace", "println", "i_search_index == a_search.getPosition() - 1");
					i_search_index = 0;
					i_search = "";
					i_Array += a_change;
				}
			}
			ArrayLog(pankey_Log_Statement, "replace", "println", "end for");

			fix(this->m_t_value, this->m_pos, this->m_size);
			erase(this->m_t_value);
			this->m_t_value = i_Array.this->m_t_value;
			this->m_pos = i_Array.this->m_pos;
			this->m_size = i_Array.this->m_size;
			i_Array.this->m_t_value = nullptr;
			i_Array.this->m_pos = 0;
			i_Array.this->m_size = 0;
			return;
		}
*/

		virtual Array<T> getArray(){
			return *this;
		}

	protected:

		virtual void incrementPosition(){this->m_pos++;}
		virtual void decrementPosition(){
			this->m_pos--;
			if(this->m_pos < 0){
				this->m_pos = 0;
			}
		}

		virtual void incrementPosition(int a_size){this->m_pos += a_size;}
		virtual void decrementPosition(int a_size){
			this->m_pos -= a_size;
			if(this->m_pos < 0){
				this->m_pos = 0;
			}
		}

		virtual void incrementSize(){this->m_size++;}
		virtual void decrementSize(){
			this->m_size--;
			if(this->m_size < 0){
				this->m_size = 0;
			}
		}

		virtual void incrementSize(int a_size){this->m_size += a_size;}
		virtual void decrementSize(int a_size){
			this->m_size -= a_size;
			if(this->m_size < 0){
				this->m_size = 0;
			}
		}

	protected:
		bool removeShrink = true;
		int m_fix_length = -1;
};

}

#endif








