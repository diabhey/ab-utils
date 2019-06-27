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

// Trait to determine if it is a STL container
template <typename T, typename = void>
struct is_container : std::false_type {};

template <typename... Ts>
struct is_container_helper {
  typedef void type;
};

/**
 * @brief is_container template specialization
 * Determines if the type is a container or not,
 *
 * @tparam T the "type" that is passed
 *
 * NOTE: typename T::allocator_type check has been removed
 * in order to be able to deduce the std::array<> type because
 * the std::array does not have a allocator_type
 */
template <typename T>
struct is_container<
    T,
    typename is_container_helper<
        typename T::value_type, typename T::size_type, typename T::iterator,
        typename T::const_iterator, decltype(std::declval<T>().size()),
        decltype(std::declval<T>().begin()), decltype(std::declval<T>().end()),
        decltype(std::declval<T>().cbegin()),
        decltype(std::declval<T>().cend())>::type> : public std::true_type {};

// Typedefs that combine traits with std::enable_if.
// This is done for convinience and to avoide excessive typing.

template <typename T>
using if_integral = std::enable_if<
    std::is_integral<T>::value || std::is_floating_point<T>::value, T>;

template <typename T>
using if_container = std::enable_if<is_container<T>::value, T>;

template <typename T>
using if_non_integral = std::enable_if<not(std::is_integral<T>::value ||
                                           std::is_floating_point<T>::value ||
                                           is_container<T>::value),
                                       T>;
}  // namespace ab::typetraits