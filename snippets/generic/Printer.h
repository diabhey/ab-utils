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
#include <iostream>

namespace ab {
/**
 * @brief print() specialization for integral types
 *
 */
template <typename T, typename = typename std::enable_if<
                          std::is_integral<T>::value ||
                          std::is_floating_point<T>::value>::type>
void print(std::ostream& stream, const T value) {
  stream << value << " ";
}

/**
 * @brief print() specialization for non-integral types (ex, std::string)
 * passing a std::string by reference is cheaper than passing by value
 */

template <typename T, typename = typename std::enable_if<
                          not(std::is_integral<T>::value ||
                              std::is_floating_point<T>::value)>::type>
void print(std::ostream& stream, const T& value) {
  stream << value << " ";
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
 * @brief Called when the parameter pack is empty
 *
 * @tparam Function function object to be called.
 */
template <typename Function>
void printArgs(Function f) {
  // Parameter pack is empty.
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
void printer(std::ostream& stream,
             const std::experimental::source_location& location, Args... args) {
  stream << location.file_name() << "::" << location.function_name() << "("
         << location.line() << ") - ";
  printArgs([&](auto arg) { print(stream, arg); }, args...);
}

}  // namespace ab