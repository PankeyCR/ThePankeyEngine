

#ifndef Processing_h
#define Processing_h

namespace ame{

template<class V>
class Processing{
	public:
		Processing();
		virtual ~Processing(){}
		
		virtual V processing(V plantValue, V controlValue);
		
	protected:
};

}

#endif 
