

#ifndef Random_hpp
#define Random_hpp

namespace ame{

class Random{
	protected:
		float max=1;
		float min=0;
		float seed=1.0f;
	
    public:
		virtual ~Random(){}
		
		virtual void setMax(float Max){
			max = Max;
		}
		
		virtual void setMin(float Min){
			min = Min;
		}
		
		virtual float getMax() const{
			return max;
		}
		
		virtual float getMin() const{
			return min;
		}
		
		virtual void setSeed(float Seed){
			seed = Seed;
		}
		
		virtual float getSeed() const{
			return seed;
		}
		
		virtual float getRandom() const{
			return 0;
		}
};

}

#endif 
