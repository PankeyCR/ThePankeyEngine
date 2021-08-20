
#ifndef Error_h
#define Error_h

namespace ame{
	
//Error defines
#define NO_WIFI_CONEXION_ERROR 0

class NoErrorClass{
    public:
		NoErrorClass(){
			
		}
		virtual ~NoErrorClass(){
			
		}
		
		virtual void resolve(int e){}
		virtual bool operator=(Error e){
			
		}
	protected:
};

class Error{
    public:
		Error(){
			
		}
		Error(const Error& e){
		}
		virtual ~Error(){
			
		}
		
		virtual void resolve(String e){}
		virtual bool operator=(Error e){
			
		}
	protected:
};

class ErrorSolver{
    public:
		ErrorSolver(){
			
		}
		ErrorSolver(const ErrorSolver& e){
		}
		virtual ~ErrorSolver(){
			
		}
		
		virtual void resolve(String e){}
		virtual bool operator=(ErrorSolver e){
			
		}
	protected:
};

class ErrorMannager{
    public:
		ErrorMannager(){
			
		}
		ErrorMannager(const ErrorMannager& e){
			hasError = e.hasError;
		}
		virtual ~ErrorMannager(){
			
		}
		
		virtual void resolve(String e){}
		virtual bool operator(){
			return hasError;
		}
		virtual bool operator=(const ErrorMannager& e){
			hasError = e.hasError;
		}
	protected:
		bool hasError = false;
};

}

#endif 
