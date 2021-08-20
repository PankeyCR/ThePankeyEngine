
#ifndef Solution_h
#define Solution_h

namespace ame{

template<class T>
class Solution{
    public:
		Solution(){}
		Solution(T s){
			t = s;
		}
		Solution(const Solution& e){
			t = e.t;
		}
		virtual ~Solution(){
			
		}
		
		virtual int solutionType(){return -1;}
		virtual bool hasSolution(){return false;}
		virtual T getSolution(){return t;}
		virtual bool operator=(Solution e){
			t = e.t;
		}
		virtual bool operator==(Solution e){
			return t == e.t;
		}
		virtual bool operator!=(Solution e){
			return t != e.t;
		}
	protected:
		T t;
};

}

#endif 
