/**
 * @file TypeTraits.h
 * @author Bigillu
 * @brief  Header that contains the custom type traits
 * @version 0.1
 * @date 2019-06-26
 *
 * @copyright Copyright (c) 2019
 *
 */
#include <utility>

namespace ab::typetraits {

template <typename T>
using if_integral = std::enable_if<
    std::is_integral<T>::value || std::is_floating_point<T>::value, T>;

// Traits to determine if it is a STL container
template <typename T, typename = void>
struct is_container : std::false_type {};

template <typename... Ts>
struct is_container_helper {
  typedef void type;
};

template <typename T>
struct is_container<
    T,
    typename is_container_helper<
        typename T::value_type, typename T::size_type,
        typename T::allocator_type, typename T::iterator,
        typename T::const_iterator, decltype(std::declval<T>().size()),
        decltype(std::declval<T>().begin()), decltype(std::declval<T>().end()),
        decltype(std::declval<T>().cbegin()),
        decltype(std::declval<T>().cend())>::type> : public std::true_type {};

template <typename T>
using if_container = std::enable_if<is_container<T>::value, T>;

template <typename T>
using if_non_integral = std::enable_if<not(
              std::is_integral<T>::value || std::is_floating_point<T>::value ||
              is_container<T>::value), T>;
}