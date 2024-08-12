
#ifndef Average_hpp
	#define Average_hpp

	#ifdef Average_LogApp
		#include "higgs_Logger.hpp"
		#define AverageLog(location,method,type,mns) higgs_Log(nullptr,location,"Average",method,type,mns)
	#else
		#define AverageLog(location,method,type,mns)
	#endif

	namespace higgs{

		template<class T>
		class Average{
			public:
				
				Average(T a_value){
					AverageLog(higgs_Log_StartMethod, "Constructor", "println", "");
					this->value = a_value;
					this->size = 0;
					AverageLog(higgs_Log_Statement, "Constructor", "println", "Value: ");
					AverageLog(higgs_Log_Statement, "Constructor", "println", this->value);
					AverageLog(higgs_Log_Statement, "Constructor", "println", "Size: ");
					AverageLog(higgs_Log_Statement, "Constructor", "println", this->size);
					AverageLog(higgs_Log_EndMethod, "Constructor", "println", "");
				}
				
				virtual ~Average(){
					AverageLog(higgs_Log_StartMethod, "Destructor", "println", "");
					AverageLog(higgs_Log_EndMethod, "Destructor", "println", "");
				}
				
				virtual int getSize(){
					AverageLog(higgs_Log_StartMethod, "getSize", "println", "");
					AverageLog(higgs_Log_EndMethod, "getSize", "println", "");
					return this->size;
				}
				
				virtual T getValue(){
					AverageLog(higgs_Log_StartMethod, "getValue", "println", "");
					AverageLog(higgs_Log_EndMethod, "getValue", "println", "");
					return this->value;
				}
				
				virtual void add(T t){
					AverageLog(higgs_Log_StartMethod, "add", "println", "");
					this->value += t;
					this->size++;
					AverageLog(higgs_Log_Statement, "Constructor", "println", "Value: ");
					AverageLog(higgs_Log_Statement, "Constructor", "println", this->value);
					AverageLog(higgs_Log_Statement, "Constructor", "println", "Size: ");
					AverageLog(higgs_Log_Statement, "Constructor", "println", this->size);
					AverageLog(higgs_Log_EndMethod, "add", "println", "");
				}
				
				virtual T getAverage(){
					AverageLog(higgs_Log_StartMethod, "getAverage", "println", "");
					AverageLog(higgs_Log_Statement, "Constructor", "println", "Value: ");
					AverageLog(higgs_Log_Statement, "Constructor", "println", this->value);
					AverageLog(higgs_Log_Statement, "Constructor", "println", "Size: ");
					AverageLog(higgs_Log_Statement, "Constructor", "println", this->size);
					AverageLog(higgs_Log_EndMethod, "getAverage", "println", "");
					return this->value / this->size;
				}
				
				virtual void clear(T a_value){
					AverageLog(higgs_Log_StartMethod, "clear", "println", "");
					this->value = a_value;
					this->size = 0;
					AverageLog(higgs_Log_Statement, "Constructor", "println", "Value: ");
					AverageLog(higgs_Log_Statement, "Constructor", "println", this->value);
					AverageLog(higgs_Log_Statement, "Constructor", "println", "Size: ");
					AverageLog(higgs_Log_Statement, "Constructor", "println", this->size);
					AverageLog(higgs_Log_EndMethod, "clear", "println", "");
				}
				
			protected:
				T value;
				int size = 0;
		};

	}

#endif
