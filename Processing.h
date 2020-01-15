

#ifndef Processing_h
#define Processing_h

template<class V>
class Processing{
	public:
		Processing();
		virtual ~Processing(){}
		
		virtual V processing(V plantValue, V controlValue);
		
	protected:
	
};

#endif 
