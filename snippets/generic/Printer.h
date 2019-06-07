#include <deque>
#include <iostream>
#include <list>
#include <map>
#include <string>
#include <vector>

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
                            std::is_integral<T>::value ||
                            std::is_arithmetic<T>::value>::type>
  void print(const T value) const {
    std::cout << value << "\n";
  }
  // For non-integral types
  template <typename T, typename = typename std::enable_if<
                            !(std::is_integral<T>::value ||
                              std::is_arithmetic<T>::value)>::type>
  void print(const T& value) const {
    std::cout << value << "\n";
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
  void print(const T& value) {
    for (typename T::const_iterator it = value.begin(); it != value.end();
         ++it) {
      std::cout << *it << " ";
    }
    std::cout << '\n';
  }
};
