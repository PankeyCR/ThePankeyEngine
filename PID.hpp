
#ifndef PID_hpp
	#define PID_hpp
	
	#include "ClassFunction.hpp"

	namespace pankey{

		class PID : public ClassFunction<float,float>{
			public:
				float m_kp = 1;
				float m_ki = 0;
				float m_kd = 0;

				float m_setpoint = 0;
				
				long m_time = 0;
				long m_prevTime = 0;
				float m_elapsedTime = 0.0f;
				float m_error = 0.0f;
				float m_lastError = 0.0f;
				float m_cumError = 0.0f;
				float m_rateError = 0.0f;

				bool m_direction = true;
				
				PID(){}
				PID(float a_kp, float a_ki, float a_kd){
					m_kp = a_kp;
					m_ki = a_ki;
					m_kd = a_kd;
				}
				PID(float a_kp, float a_ki, float a_kd, float a_setpoint){
					m_kp = a_kp;
					m_ki = a_ki;
					m_kd = a_kd;
					m_setpoint = a_setpoint;
				}
				PID(float a_kp, float a_ki, float a_kd, float a_setpoint, bool a_direction){
					m_kp = a_kp;
					m_ki = a_ki;
					m_kd = a_kd;
					m_setpoint = a_setpoint;
					m_direction = a_direction;
				}
 
				virtual void setPoint(float a_setpoint){
					m_setpoint = a_setpoint;
				}
 
				virtual void setPID(float a_kp, float a_ki, float a_kd){
					m_kp = a_kp;
					m_ki = a_ki;
					m_kd = a_kd;
				}
 
				virtual float run(float a_input){     
					m_time = millis();                          
					m_elapsedTime = (float)((m_time - m_prevTime) / 1000.0f);   
					
					m_error = m_setpoint - a_input;                             
					m_cumError += m_error * m_elapsedTime;                    
					m_rateError = (m_error - m_lastError) / m_elapsedTime;      
			
					float i_output = m_kp * m_error + m_ki * m_cumError + m_kd * m_rateError;
			
					m_lastError = m_error;                                    
					m_prevTime = m_time;                           
			
					return i_output;
				}
		};

	}

#endif