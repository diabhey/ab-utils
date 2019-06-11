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

namespace ab {
// Overloading the stream operator to print a key value pair.
// This will be also triggered while printing an std::map<key, value> for
// instance.
template <typename Key, typename Value>
std::ostream& operator<<(std::ostream& os,
                         const std::pair<const Key, Value>& p) {
  os << "{ " << p.first << ", " << p.second << " }";
  return os;
}

class Printer {
 public:
  /**
   * @brief print() specialization for integral types
   *
   */
  template <typename T, typename = typename std::enable_if<
                            std::is_integral<T>::value>::type>
  void print(std::ostream& stream, const T value) const {
    stream << value << '\n';
  }

  /**
   * @brief print() specialization for non-integral types (ex, std::string)
   * passing a std::string by reference is cheaper than passing by value
   */
  template <typename T, typename = typename std::enable_if<
                            !std::is_integral<T>::value>::type>
  void print(std::ostream& stream, const T& value) const {
    stream << value << '\n';
  }

  /**
   * @brief print() specialization for pointer types
   * Does not deduct smart pointers
   */
  template <typename T,
            typename = typename std::enable_if<std::is_pointer<T>::value>::type>
  void print(std::ostream& stream, const T value) {
    stream << *value << '\n';
  }

  /**
   * @brief print() specialization for smart pointers
   * Fix me: Matches the print() of containers, especially,std::vector<>
   */
  template <typename U, template <typename> class T>
  void print(std::ostream& stream, T<U> p) {
    stream << *p.get() << '\n';
  }

  /**
   * @brief print() specialization for STL containers
   * Both sequential and associative containers are taken intou
   * account
   */
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
}  // namespace ab