

#ifndef PID_h
#define PID_h

class PID {
	public:
		virtual void setInput(float pidInput);
		virtual void setPoint(float pidPoint);
		virtual void setPID(float P,float I, float D);
		virtual void setP(float P);
		virtual void setI(float I);
		virtual void setD(float D);
		virtual float getOutput();
		virtual float getP();
		virtual float getI();
		virtual float getD();
		virtual float getError();
		virtual bool Compute()=0;
		virtual void operator=(const PID& b);	
	protected:
		float error = 0;
		float input = 0;
		float output = 0;
		float setpoint = 0;
		float kp = 1;
		float ki = 0;
		float kd = 0;
};

#endif 
