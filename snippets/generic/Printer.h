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

namespace ab {
/**
 * @brief print() specialization for integral types
 *
 */
template <typename T, typename = typename std::enable_if<
                          std::is_integral<T>::value ||
                          std::is_floating_point<T>::value>::type>
void print(std::ostream& stream, const T value) {
  stream << value << '\n';
}

/**
 * @brief print() specialization for non-integral types (ex, std::string)
 * passing a std::string by reference is cheaper than passing by value
 */

template <typename T, typename = typename std::enable_if<
                          not(std::is_integral<T>::value ||
                              std::is_floating_point<T>::value)>::type>
void print(std::ostream& stream, const T& value) {
  stream << value << '\n';
}

/**
 * @brief Generic print utility
 */
template <typename... Args>
void print(std::ostream& stream,
           const std::experimental::source_location& location, Args&&... args) {
  stream << location.file_name() << "::" << location.function_name() << "("
         << location.line() << ") : ";
  print(stream, std::forward<Args>(args)...);
}
}  // namespace ab