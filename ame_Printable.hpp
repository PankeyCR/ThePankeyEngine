
#ifndef ame_Printable_hpp
#define ame_Printable_hpp

#include <stdlib.h>

class Print;

class Printable{
  public:
    virtual size_t printTo(Print& p) const = 0;
};

#endif

