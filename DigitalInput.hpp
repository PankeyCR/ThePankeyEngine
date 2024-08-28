
#ifndef DigitalInput_hpp
	#define DigitalInput_hpp
	
	#include "System.hpp"

	#ifdef DigitalInput_LogApp
		#include "pankey_Logger.hpp"
		#define DigitalInputLog(location,method,type,mns) pankey_Log(nullptr,location,"DigitalInput",method,type,mns)
	#else
		#define DigitalInputLog(location,method,type,mns) 
	#endif

	namespace pankey{

		class DigitalInput{
			public:
				bool inverted = false;
				int pin = -1;
				float state = false;

				DigitalInput(){
					DigitalInputLog(pankey_Log_StartMethod, "Constructor", "println", "");
					DigitalInputLog(pankey_Log_EndMethod, "Constructor", "println", "");
				}
				DigitalInput(int a_pin){
					DigitalInputLog(pankey_Log_StartMethod, "CopyConstructor", "println", "");
					pin = a_pin;
					DigitalInputLog(pankey_Log_EndMethod, "CopyConstructor", "println", "");
				}
				DigitalInput(const DigitalInput& a_di){
					DigitalInputLog(pankey_Log_StartMethod, "CopyConstructor", "println", "");
					inverted = a_di.inverted;
					pin = a_di.pin;
					state = a_di.state;
					DigitalInputLog(pankey_Log_EndMethod, "CopyConstructor", "println", "");
				}
				virtual ~DigitalInput(){}

				void initialize(){
					DigitalInputLog(pankey_Log_StartMethod, "initialize", "println", "");
					DigitalInputLog(pankey_Log_Statement, "initialize", "println", "initializing pin");
					DigitalInputLog(pankey_Log_Statement, "initialize", "println", pin);
					if(pin != -1){
						pinMode(pin, INPUT);
						DigitalInputLog(pankey_Log_Statement, "initialize", "println", "pin has been initialize");
					}
					DigitalInputLog(pankey_Log_EndMethod, "initialize", "println", "");
				}
					
				virtual void operator=(DigitalInput a_di){
					DigitalInputLog(pankey_Log_StartMethod, "operator=", "println", "");
					inverted = a_di.inverted;
					pin = a_di.pin;
					state = a_di.state;
					DigitalInputLog(pankey_Log_EndMethod, "operator=", "println", "");
				}
				virtual bool operator==(DigitalInput a_di){
					return inverted == a_di.inverted && pin == a_di.pin && state == a_di.state;
				}
				virtual bool operator!=(DigitalInput a_di){
					return inverted != a_di.inverted && pin != a_di.pin && state != a_di.state;
				}
		};

		bool DigitalInputAction(DigitalInput& a_input, float a_tpc){
			DigitalInputLog(pankey_Log_StartMethod, "DigitalInputAction", "println", "");
			DigitalInputLog(pankey_Log_StartMethod, "DigitalInputAction", "println", "Pin number:");
			DigitalInputLog(pankey_Log_StartMethod, "DigitalInputAction", "println", a_input.pin);
			DigitalInputLog(pankey_Log_StartMethod, "DigitalInputAction", "println", "Pin state:");
			DigitalInputLog(pankey_Log_StartMethod, "DigitalInputAction", "println", digitalRead(a_input.pin));

			bool i_input = digitalRead(a_input.pin);
			a_input.state = i_input;

			if(a_input.inverted){
				DigitalInputLog(pankey_Log_EndMethod, "DigitalInputAction", "println", "");
				return !i_input;
			}
			DigitalInputLog(pankey_Log_EndMethod, "DigitalInputAction", "println", "");
			return i_input;
		}

	}

#endif