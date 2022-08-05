
#include "ame_Enviroment.hpp"

#if defined(DISABLE_Annotation)
	#define Annotation_hpp
#endif

#ifndef Annotation_hpp
#define Annotation_hpp
#define Annotation_AVAILABLE

namespace ame{

class cppObjectClass;

class Annotation{
public:
Annotation(){}
virtual ~Annotation(){}

virtual cppObjectClass* getClass(){return nullptr;}

virtual void operator=(Annotation b){}
virtual bool operator==(Annotation b){return true;}
virtual bool operator!=(Annotation b){return false;}
protected:
};

}

#endif
