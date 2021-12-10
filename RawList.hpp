
#ifndef RawList_hpp
#define RawList_hpp

namespace ame{

template <class T>
class RawList{	
	public:
	virtual ~RawList(){}
	virtual bool isEmpty()const=0;
	virtual void setPosition(int p)=0;
	virtual int getPosition()const=0;
	virtual int getSize()const=0;
	virtual bool replace(int i, int j)=0;
	virtual void addList(RawList<T> *raw)=0;
	virtual T* addPointer(T* value)=0;
	virtual T* add(T value){
		return this->addLValue(value);
	}
	virtual void put(T value){
		if(this->containByLValue(value)){
			return;
		}
		this->addLValue(value);
	}
	virtual T* addLValue(T value)=0;
	virtual T* setLValue(int position, T value)=0;
	virtual T* set(int position, T value){
		return this->setLValue(position, value);
	}
	virtual T* setPointer(int position, T* value)=0;
	virtual T* insertLValue(int position, T value)=0;
	virtual T* insertPointer(int position, T* value)=0;
	virtual T* getByPointer(T* key)=0;
	virtual T* get(T value){
		return this->getByLValue(value);
	}
	virtual T* getByLValue(T key)=0;
	virtual T* getByPosition(int x)const=0;
	virtual bool containByPointer(T* key)=0;
	virtual bool containByLValue(T key)=0;
	virtual int getIndexByPointer(T* key)=0;
	virtual int getIndexByLValue(T key)=0;
	virtual void reset()=0;
	virtual void resetDelete()=0;
	virtual T* removeByPointer(T* key)=0;
	virtual T* removeByLValue(T key)=0;
	virtual void remove(T value){
		this->removeDeleteByLValue(value);
	}
	virtual T* removeByPosition(int p)=0;
	virtual void removeDeleteByPointer(T* key)=0;
	virtual void removeDeleteByLValue(T key)=0;
	virtual void removeDeleteByPosition(int p)=0;
	virtual T& operator[](int x)=0;
	virtual bool operator<(int x) const{
		return this->getPosition() < x;
	}
	virtual bool operator>(int x) const{
		return this->getPosition() > x;
	}
	virtual bool operator<=(int x) const{
		return this->getPosition() <= x;
	}
	virtual bool operator>=(int x) const{
		return this->getPosition() >= x;
	}
	// virtual bool operator==(int x) const{
		// return this->getPosition() == x;
	// }
	// virtual bool operator!=(int x) const{
		// return this->getPosition() != x;
	// }
	private:
};

}
#endif 
