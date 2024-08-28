
#ifndef SafeList_hpp
	#define SafeList_hpp

	namespace pankey{

		template <class T>
		class SafeList : virtual public RawPointerList<T>{	
			public:
				virtual ~SafeList(){}

                virtual bool isEmpty()const=0;
                virtual bool replace(int i, int j)=0;
                virtual void addMove(RawPointerList<T>& a_list)=0;
                virtual void addDuplicate(const RawPointerList<T>& a_list)=0;
                virtual void clear()=0;
                virtual bool removeFirstIndex(int a_amount)=0;
                virtual bool removeLastIndex(int a_amount)=0;
                virtual bool removeFirst()=0;
                virtual bool removeLast()=0;
                virtual void expand(int a_size)=0;
				virtual void addCopy(RawPointerList<T>* a_list)=0;
				virtual T* add(T a_value)=0;
				virtual T* set(int a_position, T a_value)=0;
				virtual T* insert(int a_position, T a_value)=0;
				virtual T* get(T a_value)=0;
				virtual T& getReferenceByIndex(int x)const=0;
				virtual T getByIndex(int x)const=0;
				virtual bool contain(T a_value)=0;
				virtual int getIndex(T a_value)=0;
				virtual bool remove(T a_value)=0;
				virtual bool removeByIndex(int a_position)=0;
				virtual bool removeAll(T a_value)=0;
				virtual bool removeFirst(T a_value)=0;
				virtual bool removeLast(T a_value)=0;
				// template<class... Args>
				// void addPack(Args... x)=0;
				// template<class... Args>
				// T* addWithParameters(Args... x)=0;
				virtual T* put(T a_value)=0;
				virtual int repeated(T a_value)=0;
				virtual T* addFirst(T a_value)=0;
				virtual T* addLast(T a_value)=0;
				virtual T& operator[](int x)=0;
		
				//operators
				virtual T& operator[](int x)=0;
			private:
		};

	}

#endif