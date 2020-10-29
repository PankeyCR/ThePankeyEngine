

#ifndef trilean_h
#define trilean_h
#define unknown -1

class trilean{
	protected:
		
    public:
		bool tbool=false;
		bool known=false;
		trilean(const bool& b);
		trilean(const int& b);
		trilean();
		virtual ~trilean();
		
		virtual void operator=(const bool& b);
		virtual void operator=(const int& b);
		virtual void operator=(const float& b);
		virtual void operator=(const double& b);
		
		virtual bool operator==(const bool& b);
		virtual bool operator==(const int& b);
		virtual bool operator==(const float& b);
		virtual bool operator==(const double& b);
		
		virtual bool operator!=(const bool& b);
		virtual bool operator!=(const int& b);
		virtual bool operator!=(const float& b);
		virtual bool operator!=(const double& b);
		
};

#endif 
