

#ifndef trilean_cpp
#define trilean_cpp

#include "trilean.h"

	ame::trilean::trilean(){
		
	}
	ame::trilean::trilean(const bool& b){
		this->tbool=b;
		this->known=true;
	}
	ame::trilean::trilean(const int& b){
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
	ame::trilean::~trilean(){
		
	}
	void ame::trilean::operator=(const bool& b){
		this->tbool=b;
		this->known=true;
	}
	void ame::trilean::operator=(const int& b){
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
	void ame::trilean::operator=(const float& b){
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
	void ame::trilean::operator=(const double& b){
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
	bool ame::trilean::operator==(const bool& b){
		if(!this->known){
			return false;
		}
		return b == this->tbool;
	}
	bool ame::trilean::operator==(const int& b){
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
	bool ame::trilean::operator==(const float& b){
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
	bool ame::trilean::operator==(const double& b){
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
	bool ame::trilean::operator!=(const bool& b){
		if(!this->known){
			return true;
		}
		return b != this->tbool;
	}
	bool ame::trilean::operator!=(const int& b){
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
	bool ame::trilean::operator!=(const float& b){
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
	bool ame::trilean::operator!=(const double& b){
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
#endif 
