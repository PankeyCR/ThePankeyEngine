
#ifndef Annotation_hpp
#define Annotation_hpp

#if defined(ame_untilLevel_10)

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

#endif 
