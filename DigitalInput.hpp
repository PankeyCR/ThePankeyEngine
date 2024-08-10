
#ifndef DigitalInput_hpp
	#define DigitalInput_hpp
	
	#include "System.hpp"

	#ifdef DigitalInput_LogApp
		#include "higgs_Logger.hpp"
		#define DigitalInputLog(location,method,type,mns) higgs_Log(nullptr,location,"DigitalInput",method,type,mns)
	#else
		#define DigitalInputLog(location,method,type,mns) 
	#endif

	namespace higgs{

		class DigitalInput{
			public:
				bool inverted = false;
				int pin = -1;
				float state = false;

				DigitalInput(){
					DigitalInputLog(higgs_Log_StartMethod, "Constructor", "println", "");
					DigitalInputLog(higgs_Log_EndMethod, "Constructor", "println", "");
				}
				DigitalInput(int a_pin){
					DigitalInputLog(higgs_Log_StartMethod, "CopyConstructor", "println", "");
					pin = a_pin;
					DigitalInputLog(higgs_Log_EndMethod, "CopyConstructor", "println", "");
				}
				DigitalInput(const DigitalInput& a_di){
					DigitalInputLog(higgs_Log_StartMethod, "CopyConstructor", "println", "");
					inverted = a_di.inverted;
					pin = a_di.pin;
					state = a_di.state;
					DigitalInputLog(higgs_Log_EndMethod, "CopyConstructor", "println", "");
				}
				virtual ~DigitalInput(){}

				void initialize(){
					DigitalInputLog(higgs_Log_StartMethod, "initialize", "println", "");
					DigitalInputLog(higgs_Log_Statement, "initialize", "println", "initializing pin");
					DigitalInputLog(higgs_Log_Statement, "initialize", "println", pin);
					if(pin != -1){
						pinMode(pin, INPUT);
						DigitalInputLog(higgs_Log_Statement, "initialize", "println", "pin has been initialize");
					}
					DigitalInputLog(higgs_Log_EndMethod, "initialize", "println", "");
				}
					
				virtual void operator=(DigitalInput a_di){
					DigitalInputLog(higgs_Log_StartMethod, "operator=", "println", "");
					inverted = a_di.inverted;
					pin = a_di.pin;
					state = a_di.state;
					DigitalInputLog(higgs_Log_EndMethod, "operator=", "println", "");
				}
				virtual bool operator==(DigitalInput a_di){
					return inverted == a_di.inverted && pin == a_di.pin && state == a_di.state;
				}
				virtual bool operator!=(DigitalInput a_di){
					return inverted != a_di.inverted && pin != a_di.pin && state != a_di.state;
				}
		};

		bool DigitalInputAction(DigitalInput& a_input, float a_tpc){
			DigitalInputLog(higgs_Log_StartMethod, "DigitalInputAction", "println", "");
			DigitalInputLog(higgs_Log_StartMethod, "DigitalInputAction", "println", "Pin number:");
			DigitalInputLog(higgs_Log_StartMethod, "DigitalInputAction", "println", a_input.pin);
			DigitalInputLog(higgs_Log_StartMethod, "DigitalInputAction", "println", "Pin state:");
			DigitalInputLog(higgs_Log_StartMethod, "DigitalInputAction", "println", digitalRead(a_input.pin));

			bool i_input = digitalRead(a_input.pin);
			a_input.state = i_input;

			if(a_input.inverted){
				DigitalInputLog(higgs_Log_EndMethod, "DigitalInputAction", "println", "");
				return !i_input;
			}
			DigitalInputLog(higgs_Log_EndMethod, "DigitalInputAction", "println", "");
			return i_input;
		}

	}

#endif