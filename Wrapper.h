
#ifndef Wrapper_h
#define Wrapper_h

template<typename T>
class Wrapper{
    private:
	
    public:
		T wrapper;

        virtual T operator &(){
			return wrapper;
		}
        virtual void operator =(const T& t){
			wrapper = t;
		}
        virtual bool operator ==(const T& t){
			return wrapper==t;
		}
        virtual bool operator !=(const T& t){
			return wrapper!=t;
		}
};

#endif 
