
#ifndef Pointer_hpp
#define Pointer_hpp

namespace ame{

template<class P>
class Pointer{
	public:
		Pointer(P* p){
			pointer = p;
		}
		Pointer(const Pointer &p){
			pointer = p.pointer;
		}
		virtual ~Pointer(){
			delete pointer;
		}
		virtual P* operator ->(){
			return pointer;
		}
	protected:
		P* pointer;
};

}

#endif