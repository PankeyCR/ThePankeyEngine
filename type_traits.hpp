
#ifndef type_traits_hpp
  #define type_traits_hpp

  namespace pankey{
    
    template<class T, T v>
    struct integral_constant{
      static constexpr T value = v;
      using value_type = T;
      using type = integral_constant; // using injected-class-name
      constexpr operator value_type() const noexcept { return value; }
      constexpr value_type operator()() const noexcept { return value; } // since c++14
    };

    using true_type = integral_constant<bool, true>;
    using false_type = integral_constant<bool, false>;

    namespace detail{
      template<typename T>
      integral_constant<bool, true> test(int T::*);
  
      template<class>
      false_type test(...);
    }

    template<typename T>
    struct is_class : decltype(detail::test<T>(nullptr)) {};

    namespace detail{
      template<typename B>
      true_type test_pre_ptr_convertible(const volatile B*);

      template<typename>
      false_type test_pre_ptr_convertible(const volatile void*);

      template<typename, typename>
      auto test_pre_is_base_of(...) -> true_type;

      template<typename B, typename D>
      auto test_pre_is_base_of(int) ->
          decltype(test_pre_ptr_convertible<B>(static_cast<D*>(nullptr)));
    }

    template<typename Base, typename Derived>
    struct is_base_of : integral_constant<bool,
    is_class<Base>::value &&
    is_class<Derived>::value &&
    decltype(detail::test_pre_is_base_of<Base, Derived>(0))::value> {};

    template<class T, class U>
    struct type_traits : integral_constant<bool, false> {};
    
    template<class T>
    struct type_traits<T, T> : integral_constant<bool, true> {};

  }

#endif



//