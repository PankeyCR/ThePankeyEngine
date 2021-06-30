

#ifndef Annotation_h
#define Annotation_h

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

#endif 
