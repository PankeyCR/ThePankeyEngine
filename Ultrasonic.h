
#ifndef Ultrasonic_h
#define Ultrasonic_h

class Ultrasonic {
    public:
		Ultrasonic(){}
		Ultrasonic(int t, int r){
			setTriggerPin(t);
			setReadPin(r);
		}
		virtual ~Ultrasonic(){}
		
		virtual void initialize(Application *app){}
		
		virtual void setTriggerPin(int p){
			pinMode(p, INPUT);
			t_pin = p;
		}
		virtual int triggerPin(){return t_pin;}
		
		virtual void setReadPin(int p){
			pinMode(p, INPUT);
			r_pin = p;
		}
		virtual int readPin(){return r_pin;}
		
		virtual bool isEnable(){return m_enable;}
		virtual void enable(){m_enable = true;}
		virtual void disenable(){m_enable = false;}
		
		//distance on centimeters
		virtual float read(){return -1.0f;}
		virtual int zone(){return -1;}
		
		virtual float getMaxLimit(){return 0;}
		virtual float getMinLimit(){return 0;}
		
		virtual bool online(){return false;}
		
    protected: 
		bool m_enable = false;
		int r_pin = 0;
		int t_pin = 0;
};
#endif