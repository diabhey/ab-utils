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
#include <experimental/source_location>
#include <ostream>
#include "TypeTraits.h"

namespace ab {

// Overloaded << operator to print std::pair. It will
// also be triggered while using std::map
template <typename Key, typename Value>
std::ostream &operator<<(std::ostream &os, const std::pair<Key, Value> p) {
  os << "{ " << p.first << ", " << p.second << " }";
  return os;
}

/**
 * @brief print() specialization for integral types
 *
 */
template <typename T, typename = typename typetraits::if_integral<T>::type>
void print(std::ostream &stream, const T value) {
  stream << value << " ";
}

/**
 * @brief print() specialization for non-integral types (ex, std::string)
 * passing a std::string by reference is cheaper than passing by value
 */
template <typename T, typename = typename typetraits::if_non_integral<T>::type>
void print(std::ostream &stream, const T &value) {
  stream << value << " ";
}

/**
 * @brief print() specialization for STL containers
 * Both sequential and associative containers are taken into
 * account
 */
template <typename T>
auto print(std::ostream &stream, const T &value) ->
    typename std::enable_if<typetraits::is_container<T>::value>::type {
  stream << "{ ";
  for (typename T::const_iterator it = value.begin(); it != value.end(); ++it) {
    stream << *it << " ";
  }
  stream << " } ";
}

/**
 * @brief Called when the parameter pack is empty
 *
 * @tparam Function function object to be called.
 */
template <typename Function>
void printArgs(Function f) {
  // Parameter pack is empty.
}

/**
 * @brief Generic recursive printer function
 *
 * @tparam Function function object to be called
 * @tparam First First argument of the pack
 * @tparam Rest The remaining arguments of the pack
 */
template <typename Function, typename FirstArg, typename... Rest>
void printArgs(Function f, FirstArg first, Rest... rest) {
  f(first);
  printArgs(f, rest...);
}

/**
 * @brief Generic printer function
 *
 * @tparam Args list of arguments
 * @param stream Ostream object reference
 * @param location current location of the file
 * @param args list of args of different types
 */
template <class... Args>
void printer(std::ostream &stream,
             const std::experimental::source_location &location, Args... args) {
  stream << location.file_name() << "::" << location.function_name() << "("
         << location.line() << ") - ";
  printArgs([&](auto arg) { print(stream, arg); }, args...);
  stream << '\n';
}

}  // namespace ab