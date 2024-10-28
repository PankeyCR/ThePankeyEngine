
#ifndef PID_hpp
	#define PID_hpp
	
	#include "ClassFunction.hpp"

	namespace pankey{

		class PID : public ClassFunction<float,float>{
			public:
				float m_kp = 0;
				float m_ki = 0;
				float m_kd = 0;

				float m_input = 0;
				float m_output = 0;
				float m_setpoint = 0;
				
				long m_time;
				long m_prevTime;
				float m_elapsedTime;
				float error;
				float lastError;
				float cumError;
				float rateError;
				
				PID(){}
				PID(float a_kp, float a_ki, float a_kd){
					
				}
		};

	}

#endif