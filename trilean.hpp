
#include "ame_Enviroment.hpp"

#if defined(DISABLE_trilean)
	#define trilean_hpp
#endif

#ifndef trilean_hpp
#define trilean_hpp
#define trilean_AVAILABLE

#ifndef ame_Enviroment_Defined

#endif

#ifdef ame_Windows

#endif

#ifdef ame_ArduinoIDE
	#include "Arduino.h"
#endif

#define unknown -1

namespace ame{
	
class trilean{
	protected:
		
    public:
		bool tbool=false;
		bool known=false;
		trilean(const bool& b){
			this->tbool=b;
			this->known=true;
		}
		trilean(const int& b){
			if(b == 1){
				this->tbool=true;
				this->known=true;
			}
			if(b == 0){
				this->tbool=false;
				this->known=true;
			}
			if(b == -1){
				this->tbool=true;
				this->known=false;
			}
		}
		trilean(){}
		virtual ~trilean(){}
		
		virtual void operator=(const bool& b){
			this->tbool=b;
			this->known=true;
		}
		virtual void operator=(const int& b){
			if(b == 1){
				this->tbool=true;
				this->known=true;
			}
			if(b == 0){
				this->tbool=false;
				this->known=true;
			}
			if(b == -1){
				this->tbool=true;
				this->known=false;
			}
		}
		virtual void operator=(const float& b){
			if(b == 1.0f){
				this->tbool=true;
				this->known=true;
			}
			if(b == 0.0f){
				this->tbool=false;
				this->known=true;
			}
			if(b == -1.0f){
				this->tbool=true;
				this->known=false;
			}
		}
		virtual void operator=(const double& b){
			if(b == 1.0d){
				this->tbool=true;
				this->known=true;
			}
			if(b == 0.0d){
				this->tbool=false;
				this->known=true;
			}
			if(b == -1.0d){
				this->tbool=true;
				this->known=false;
			}
		}
		
		virtual bool operator==(const bool& b){
			if(!this->known){
				return false;
			}
			return b == this->tbool;
		}
		virtual bool operator==(const int& b){
			if(!this->known){
				if(b == 1){
					return false;
				}
				if(b == 0){
					return false;
				}
				if(b == -1){
					return true;
				}
			}
			if(this->tbool){
				if(b == 1){
					return true;
				}
				if(b == 0){
					return false;
				}
				if(b == -1){
					return false;
				}
			}else{
				if(b == 1){
					return false;
				}
				if(b == 0){
					return true;
				}
				if(b == -1){
					return false;
				}
			}
		}
		virtual bool operator==(const float& b){
			if(!this->known){
				if(b == 1.0f){
					return false;
				}
				if(b == 0.0f){
					return false;
				}
				if(b == -1.0f){
					return true;
				}
			}
			if(this->tbool){
				if(b == 1.0f){
					return true;
				}
				if(b == 0.0f){
					return false;
				}
				if(b == -1.0f){
					return false;
				}
			}else{
				if(b == 1.0f){
					return false;
				}
				if(b == 0.0f){
					return true;
				}
				if(b == -1.0f){
					return false;
				}
			}
		}
		virtual bool operator==(const double& b){
			if(!this->known){
				if(b == 1.0d){
					return false;
				}
				if(b == 0.0d){
					return false;
				}
				if(b == -1.0d){
					return true;
				}
			}
			if(this->tbool){
				if(b == 1.0d){
					return true;
				}
				if(b == 0.0d){
					return false;
				}
				if(b == -1.0d){
					return false;
				}
			}else{
				if(b == 1.0d){
					return false;
				}
				if(b == 0.0d){
					return true;
				}
				if(b == -1.0d){
					return false;
				}
			}
		}
		
		virtual bool operator!=(const bool& b){
			if(!this->known){
				return true;
			}
			return b != this->tbool;
		}
		virtual bool operator!=(const int& b){
			if(!this->known){
				if(b == 1){
					return true;
				}
				if(b == 0){
					return true;
				}
				if(b == -1){
					return false;
				}
			}
			if(this->tbool){
				if(b == 1){
					return false;
				}
				if(b == 0){
					return true;
				}
				if(b == -1){
					return true;
				}
			}else{
				if(b == 1){
					return true;
				}
				if(b == 0){
					return false;
				}
				if(b == -1){
					return true;
				}
			}
		}
		virtual bool operator!=(const float& b){
			if(!this->known){
				if(b == 1.0f){
					return true;
				}
				if(b == 0.0f){
					return true;
				}
				if(b == -1.0f){
					return false;
				}
			}
			if(this->tbool){
				if(b == 1.0f){
					return false;
				}
				if(b == 0.0f){
					return true;
				}
				if(b == -1.0f){
					return true;
				}
			}else{
				if(b == 1.0f){
					return true;
				}
				if(b == 0.0f){
					return false;
				}
				if(b == -1.0f){
					return true;
				}
			}
		}
		virtual bool operator!=(const double& b){
			if(!this->known){
				if(b == 1.0d){
					return true;
				}
				if(b == 0.0d){
					return true;
				}
				if(b == -1.0d){
					return false;
				}
			}
			if(this->tbool){
				if(b == 1.0d){
					return false;
				}
				if(b == 0.0d){
					return true;
				}
				if(b == -1.0d){
					return true;
				}
			}else{
				if(b == 1.0d){
					return true;
				}
				if(b == 0.0d){
					return false;
				}
				if(b == -1.0d){
					return true;
				}
			}
		}
};

}

#endif 

#endif 
