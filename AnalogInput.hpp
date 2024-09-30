
#ifndef AnalogInput_hpp
	#define AnalogInput_hpp

	#ifdef AnalogInput_LogApp
		#include "pankey_Logger.hpp"
		#define AnalogInputLog(location,method,type,mns) pankey_Log(nullptr,location,"AnalogInput",method,type,mns)
	#else
		#define AnalogInputLog(location,method,type,mns) 
	#endif

	namespace pankey{

		class AnalogInput{
			public:
				int pin = -1;
				float value = -1.0f;
				float resolution = 1.0f;
				float offset = 0.0f;
				bool pause = false;
				long start = 0;
				long interval = 0;

				AnalogInput(){
					AnalogInputLog(pankey_Log_StartMethod, "Constructor", "println", "");
					AnalogInputLog(pankey_Log_EndMethod, "Constructor", "println", "");
				}
				AnalogInput(int a_pin){
					AnalogInputLog(pankey_Log_StartMethod, "CopyConstructor", "println", "");
					pin = a_pin;
					AnalogInputLog(pankey_Log_EndMethod, "CopyConstructor", "println", "");
				}
				AnalogInput(int a_pin, long a_interval){
					AnalogInputLog(pankey_Log_StartMethod, "CopyConstructor", "println", "");
					pin = a_pin;
					interval = a_interval;
					AnalogInputLog(pankey_Log_EndMethod, "CopyConstructor", "println", "");
				}
				AnalogInput(int a_pin, long a_interval, float a_resolution){
					AnalogInputLog(pankey_Log_StartMethod, "CopyConstructor", "println", "");
					pin = a_pin;
					interval = a_interval;
					resolution = a_resolution;
					AnalogInputLog(pankey_Log_EndMethod, "CopyConstructor", "println", "");
				}
				AnalogInput(int a_pin, long a_interval, float a_resolution, float a_offset){
					AnalogInputLog(pankey_Log_StartMethod, "CopyConstructor", "println", "");
					pin = a_pin;
					interval = a_interval;
					resolution = a_resolution;
					offset = a_offset;
					AnalogInputLog(pankey_Log_EndMethod, "CopyConstructor", "println", "");
				}
				AnalogInput(const AnalogInput& a_di){
					AnalogInputLog(pankey_Log_StartMethod, "CopyConstructor", "println", "");
					pin = a_di.pin;
					value = a_di.value;
					resolution = a_di.resolution;
					offset = a_di.offset;
					pause = a_di.pause;
					interval = a_di.interval;
					AnalogInputLog(pankey_Log_EndMethod, "CopyConstructor", "println", "");
				}
				virtual ~AnalogInput(){}

				void initialize(){
					AnalogInputLog(pankey_Log_StartMethod, "initialize", "println", "");
					AnalogInputLog(pankey_Log_Statement, "initialize", "println", "initializing pin");
					AnalogInputLog(pankey_Log_Statement, "initialize", "println", pin);
					if(pin != -1){
						pinMode(pin, INPUT);
						AnalogInputLog(pankey_Log_Statement, "initialize", "println", "pin has been initialize");
					}
					AnalogInputLog(pankey_Log_EndMethod, "initialize", "println", "");
				}
					
				virtual void operator=(const AnalogInput& a_di){
					AnalogInputLog(pankey_Log_StartMethod, "operator=", "println", "");
					pin = a_di.pin;
					value = a_di.value;
					resolution = a_di.resolution;
					offset = a_di.offset;
					pause = a_di.pause;
					interval = a_di.interval;
					AnalogInputLog(pankey_Log_EndMethod, "operator=", "println", "");
				}
				virtual bool operator==(AnalogInput a_di){
					return resolution == a_di.resolution && offset == a_di.offset && pause == a_di.pause && interval == a_di.interval && pin == a_di.pin && value == a_di.value;
				}
				virtual bool operator!=(AnalogInput a_di){
					return resolution != a_di.resolution && offset != a_di.offset && pause != a_di.pause && interval != a_di.interval && pin != a_di.pin && value != a_di.value;
				}
		};

		bool AnalogInputAction(AnalogInput& a_input, float a_tpc){
			AnalogInputLog(pankey_Log_StartMethod, "AnalogInputAction", "println", "");

			if(a_input.pause){
				AnalogInputLog(pankey_Log_EndMethod, "AnalogInputAction", "println", "a_input.pause");
				return false;
			}
			AnalogInputLog(pankey_Log_Statement, "AnalogInputAction", "println", "Pin number:");
			AnalogInputLog(pankey_Log_Statement, "AnalogInputAction", "println", a_input.pin);

			int i_value = analogRead(a_input.pin);

			AnalogInputLog(pankey_Log_Statement, "AnalogInputAction", "println", "Pin value:");
			AnalogInputLog(pankey_Log_Statement, "AnalogInputAction", "println", i_value);

			if((millis() - a_input.start) <= a_input.interval){
				AnalogInputLog(pankey_Log_EndMethod, "AnalogInputAction", "println", "(millis() - a_input.start) < a_input.check");
				return false;
			}

			a_input.start = millis();
			a_input.value = (i_value * a_input.resolution) + a_input.offset;

			AnalogInputLog(pankey_Log_Statement, "AnalogInputAction", "println", "value:");
			AnalogInputLog(pankey_Log_Statement, "AnalogInputAction", "println", a_input.value);
			
			AnalogInputLog(pankey_Log_EndMethod, "AnalogInputAction", "println", "return true");
			return true;
		}

	}

#endif