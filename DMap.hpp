
#ifndef DMap_hpp
#define DMap_hpp

namespace pankey{

template <class T>
class DMap {
	public:
		virtual ~DMap(){}
		
		virtual void vector(int dimention,int pos){}
		virtual void add(T t){}
		virtual void remove(){}
		virtual T get(){}
		virtual int getDPos(int dimention){}
		virtual int size(){}
	private:
};

}

#endif