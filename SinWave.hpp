
#ifndef SinWave_hpp
	#define SinWave_hpp
	
	#include "ClassFunction.hpp"

	#ifdef SinWave_LogApp
		#include "pankey_Logger.hpp"
		#define SinWaveLog(location,method,type,mns) pankey_Log((void*)this,location,"SinWave",method,type,mns)
	#else
		#define SinWaveLog(location,method,type,mns) 
	#endif

	namespace pankey{

		class SinWave : public ClassFunction<float,float,float>{
			public:
				float frequency = 10.0;
				float amplitude = 127.5;
				float offset = 1;
				
				SinWave(){
					SinWaveLog(pankey_Log_StartMethod, "Contructor",  "println", "");
					SinWaveLog(pankey_Log_StartMethod, "Contructor",  "println", "");
				}
 
				virtual float run(float a_time, float a_noise){  
					SinWaveLog(pankey_Log_StartMethod, "run",  "println", "");
					float i_sin_wave =  amplitude * sin(2 * PI * frequency * a_time) + a_noise;

					SinWaveLog(pankey_Log_StartMethod, "run",  "println", "");
					return i_sin_wave;
				}
		};

	}

#endif