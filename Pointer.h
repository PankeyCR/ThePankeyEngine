#ifndef Pointer_h
#define Pointer_h

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

#endif