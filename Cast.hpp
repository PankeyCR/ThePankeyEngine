
#include "ame_Enviroment.hpp"

#if defined(DISABLE_Cast)
	#define Cast_hpp
#endif

#ifndef Cast_hpp
#define Cast_hpp
#define Cast_AVAILABLE

#ifndef ame_Enviroment_Defined

#endif

#ifdef ame_Windows

#endif

#ifdef ame_ArduinoIDE
	#include "Arduino.h"
#endif

namespace ame{

template <class T>
struct remove_reference { typedef T type; };

template <class T>
struct remove_reference<T&> { typedef T type; };

template <class T>
struct remove_reference<T&&> { typedef T type; };

template<class T>
T&& forward(typename remove_reference<T>::type& arg){
  return static_cast<T&&>(arg);
}

template<class T>
typename remove_reference<T>::type&& move(typename remove_reference<T>::type& arg){
  return (typename remove_reference<T>::type&&)(arg);
}
template<class T>
typename remove_reference<T>::type&& move(T&& arg){
  return (typename remove_reference<T>::type&&)(arg);
}

}

#endif