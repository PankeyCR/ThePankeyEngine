
#ifndef Ultrasonic_h
#define Ultrasonic_h

class Ultrasonic {
    public:
		Ultrasonic(){}
		Ultrasonic(int t, int r){
			setTriggerPin(t);
			setReadPin(r);
		}
		Ultrasonic(int triggerP, int readP, int zoneV, float max, float min, float scaleV){
			setTriggerPin(triggerP);
			setReadPin(readP);
			m_zone = zoneV;
			m_maxLimit = max;
			m_minLimit = min;
			m_scale = scaleV;
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
		
		virtual void setScale(int p){
			m_scale = p;
		}
		virtual int scale(){return m_scale;}
		
		virtual bool isTriggering(){return m_triggering;}
		virtual void startTrigger(){
			m_triggering = true;
			digitalWrite(t_pin, HIGH);
		}
		virtual void stopTrigger(){
			m_triggering = false;
			digitalWrite(t_pin, LOW);
		}
		
		//distance on centimeters
		virtual float read(){
			m_read = analogRead(r_pin) * m_scale;
			return m_read;
		}
		
		virtual void setZone(int z){m_zone = z;}
		virtual int zone(){return m_zone;}
		
		virtual void setMaxLimit(float l){m_maxLimit = l;}
		virtual void setMinLimit(float l){m_minLimit = l;}
		
		virtual float getMaxLimit(){return m_maxLimit;}
		virtual float getMinLimit(){return m_minLimit;}
		
		virtual bool online(){
			m_safeReading++;
			if(m_safeReading < 10000l && m_read >= 0){
				m_safeReading = 0;
			}
			if(m_safeReading > 10000l && m_read < 0.0f){
				return false;
			}
			return true;
		}
		
    protected: 
		long m_safeReading = 0l;
		float m_read = -1.0f;
		bool m_triggering = false;
		int r_pin = 0;
		int t_pin = 0;
		int m_zone = 0;
		float m_maxLimit = 500.0f;
		float m_minLimit = 30.0f;
		float m_scale = 0.4761f;
};
#endif