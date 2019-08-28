#include <iostream>
#include <type_traits>

template <typename A, typename B>
struct is_related : std::conditional_t<std::is_base_of<A, B>::value ||
                                           std::is_base_of<B, A>::value,
                                       std::true_type, std::false_type> {};

class Base {};
class Derived : public Base {};

int main() {
  std::cout << std::boolalpha << is_related<Base, Derived>::value << '\n';
}