
#ifndef Average_h
#define Average_h

template<class T>
class Average{
	public:
		Average(){
			this->value = new T();
			this->size = 0;
			this->mm = true;
		}
		
		Average(T *t){
			this->value = t;
			this->size = 0;
			this->mm = true;
		}
		
		Average(T *t, bool manageMemory){
			this->value = t;
			this->size = 0;
			this->mm = manageMemory;
		}
		
		virtual ~Average(){
			if(this->value != nullptr && this->mm){
				delete this->value;
			}
		}
		
		virtual int getSize(){
			return this->size;
		}
		
		virtual T getLValue(){
			return *this->value;
		}
		
		virtual T* getPointer(){
			return this->value;
		}
		
		virtual void addRValue(T&& t){
			*this->value += t;
			this->size++;
		}
		
		virtual void addLValue(T t){
			*this->value += t;
			this->size++;
		}
		
		virtual void addPointer(T *t){
			*this->value += *t;
			this->size++;
		}
		
		virtual T getAverage(){
			return *this->value / this->size;
		}
		
		virtual void reset(){
			*this->value = 0;
			this->size = 0;
		}
		
	protected:
		T *value = nullptr;
		int size = 0;
		bool mm = true;
};

#endif 
