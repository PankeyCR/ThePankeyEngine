
#ifndef DebounceInput_hpp
	#define DebounceInput_hpp
	
	#include "System.hpp"

	#ifdef DebounceInput_LogApp
		#include "pankey_Logger.hpp"
		#define DebounceInputLog(location,method,type,mns) pankey_Log(nullptr,location,"DebounceInput",method,type,mns)
	#else
		#define DebounceInputLog(location,method,type,mns) 
	#endif

	namespace pankey{

		class DebounceInput{
			public:
				bool inverted = false;
				int pin = -1;
				bool state = false;
				bool reading = false;
				long start = 0;
				long check = 100;

				DebounceInput(){
					DebounceInputLog(pankey_Log_StartMethod, "Constructor", "println", "");
					DebounceInputLog(pankey_Log_EndMethod, "Constructor", "println", "");
				}
				DebounceInput(int a_pin){
					DebounceInputLog(pankey_Log_StartMethod, "CopyConstructor", "println", "");
					pin = a_pin;
					DebounceInputLog(pankey_Log_EndMethod, "CopyConstructor", "println", "");
				}
				DebounceInput(const DebounceInput& a_di){
					DebounceInputLog(pankey_Log_StartMethod, "CopyConstructor", "println", "");
					inverted = a_di.inverted;
					pin = a_di.pin;
					state = a_di.state;
					DebounceInputLog(pankey_Log_EndMethod, "CopyConstructor", "println", "");
				}
				virtual ~DebounceInput(){}

				void initialize(){
					DebounceInputLog(pankey_Log_StartMethod, "initialize", "println", "");
					DebounceInputLog(pankey_Log_Statement, "initialize", "println", "initializing pin");
					DebounceInputLog(pankey_Log_Statement, "initialize", "println", pin);
					if(pin != -1){
						pinMode(pin, INPUT);
						DebounceInputLog(pankey_Log_Statement, "initialize", "println", "pin has been initialize");
					}
					DebounceInputLog(pankey_Log_EndMethod, "initialize", "println", "");
				}
					
				virtual void operator=(DebounceInput a_di){
					DebounceInputLog(pankey_Log_StartMethod, "operator=", "println", "");
					inverted = a_di.inverted;
					pin = a_di.pin;
					state = a_di.state;
					DebounceInputLog(pankey_Log_EndMethod, "operator=", "println", "");
				}
				virtual bool operator==(DebounceInput a_di){
					return inverted == a_di.inverted && pin == a_di.pin && state == a_di.state;
				}
				virtual bool operator!=(DebounceInput a_di){
					return inverted != a_di.inverted && pin != a_di.pin && state != a_di.state;
				}
		};

		bool DebounceInputAction(DebounceInput& a_input, float a_tpc){
			DebounceInputLog(pankey_Log_StartMethod, "DebounceInputAction", "println", "");
			DebounceInputLog(pankey_Log_Statement, "DebounceInputAction", "println", "Pin number:");
			DebounceInputLog(pankey_Log_Statement, "DebounceInputAction", "println", a_input.pin);
			DebounceInputLog(pankey_Log_Statement, "DebounceInputAction", "println", "Pin state:");
			DebounceInputLog(pankey_Log_Statement, "DebounceInputAction", "println", digitalRead(a_input.pin));

			bool i_input = false;
			if(a_input.inverted){
				i_input = !digitalRead(a_input.pin);
			}else{
				i_input = digitalRead(a_input.pin);
			}
			if(i_input == a_input.state){
				DebounceInputLog(pankey_Log_EndMethod, "DebounceInputAction", "println", "i_input == a_input.state");
				a_input.reading = false;
				return false;
			}
			if(!a_input.reading){
				DebounceInputLog(pankey_Log_Statement, "DebounceInputAction", "println", "!a_input.reading");
				a_input.reading = true;
				a_input.start = millis();
			}
			DebounceInputLog(pankey_Log_Statement, "DebounceInputAction", "println", "start time:");
			DebounceInputLog(pankey_Log_Statement, "DebounceInputAction", "println", a_input.start);
			DebounceInputLog(pankey_Log_Statement, "DebounceInputAction", "println", "time:");
			DebounceInputLog(pankey_Log_Statement, "DebounceInputAction", "println", millis());
			DebounceInputLog(pankey_Log_Statement, "DebounceInputAction", "println", "check time:");
			DebounceInputLog(pankey_Log_Statement, "DebounceInputAction", "println", a_input.check);
			if((millis() - a_input.start) < a_input.check){
				DebounceInputLog(pankey_Log_EndMethod, "DebounceInputAction", "println", "(millis() - a_input.start) < a_input.check");
				return false;
			}
			if(a_input.inverted){
				DebounceInputLog(pankey_Log_Statement, "DebounceInputAction", "println", "a_input.state = !i_input;");
				a_input.state = !i_input;
			}else{
				DebounceInputLog(pankey_Log_Statement, "DebounceInputAction", "println", "a_input.state = i_input;");
				a_input.state = i_input;
			}
			DebounceInputLog(pankey_Log_EndMethod, "DebounceInputAction", "println", "return true");
			return true;
		}

	}

#endif