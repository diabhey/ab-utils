/**
 * @file Printer.h
 * @author Bigillu
 * @brief Generic Printer Library
 * @version 0.1
 * @date 2019-06-08
 *
 * @copyright Copyright (c) 2019
 *
 */
#include <ostream>
#include <type_traits>

template <typename Key, typename Value>
std::ostream& operator<<(std::ostream& os,
                         const std::pair<const Key, Value>& p) {
  os << "{ " << p.first << ", " << p.second << " }";
  return os;
}

class Printer {
 public:
  Printer() {}

  // For integral types
  template <typename T, typename = typename std::enable_if<
                            std::is_integral<T>::value>::type>
  void print(std::ostream& stream, const T value) const {
    stream << value << '\n';
  }
  // For non-integral types
  template <typename T, typename = typename std::enable_if<
                            !std::is_integral<T>::value>::type>
  void print(std::ostream& stream, const T& value) const {
    stream << value << '\n';
  }
  // For pointer types (does not deduce smart pointers)
  template <typename T,
            typename = typename std::enable_if<std::is_pointer<T>::value>::type>
  void print(std::ostream& stream, const T value) {
    stream << *value << '\n';
  }

  // STL containers
  template <typename T, typename = void>
  struct is_iterable : std::false_type {};
  template <typename T>
  struct is_iterable<T, std::void_t<decltype(std::declval<T>().begin()),
                                    decltype(std::declval<T>().end())>>
      : std::true_type {};

  template <typename T,
            typename = typename std::enable_if<is_iterable<T>::value>::type>
  void print(std::ostream& stream, const T& value) {
    for (typename T::const_iterator it = value.begin(); it != value.end();
         ++it) {
      stream << *it << " ";
    }
    stream << '\n';
  }
};
