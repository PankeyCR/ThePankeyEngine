

#ifndef Random_h
#define Random_h

namespace ame{

class Random{
	protected:
		float max=1;
		float min=0;
		float seed=1.0f;
	
    public:
		virtual ~Random();
		virtual void setMax(float Max);
		virtual void setMin(float Min);
		virtual float getMin();
		virtual float getMax();
		virtual float getSeed();
		virtual void setSeed(float Seed);
		virtual float getRandom();
};

}

#endif 
