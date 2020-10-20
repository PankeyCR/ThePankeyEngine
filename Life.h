//Life owns it lelf, life deletes it lelf, but it can be deleted by others


#ifndef Life_h
#define Life_h

#include "Function.h"
#include "GameObject.h"
#include "ByteArray.h"


class Life : public GameObject{
public:
Life(){
}
~Life(){}

virtual void update(float tpf){
	
}

protected:
ByteArray cells;
};

#endif