
#ifndef Memory_hpp
	#define Memory_hpp

	#include "PointerSize.hpp"

	namespace pankey{

		class Memory{
			public:
				virtual ~Memory(){}

				virtual void* create(pointer_size a_size){return malloc(a_size);}
				virtual void destroy(pointer_size a_size, void* a_destroy){free(a_destroy);}

				template<class T>
				T* newInstance(){
					void* i_instance = this->create(sizeOfPointer<T>());
					if(i_instance == nullptr){
						return nullptr;
					}
					return (T*)i_instance;
				}
		};

	}

#endif