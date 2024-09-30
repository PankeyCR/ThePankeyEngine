
#ifndef pankey_Printable_hpp
  #define pankey_Printable_hpp

  #include <stdlib.h>

	namespace pankey{
    class Print;

    class Printable{
      public:
        virtual size_t printTo(Print& p) const = 0;
    };
  }

#endif

