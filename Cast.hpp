
#ifndef Cast_hpp
#define Cast_hpp
#define Cast_AVAILABLE

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



//