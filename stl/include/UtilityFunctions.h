/**
 * @file UtilityFunctions.h
 * @author bigillu
 * @brief A collection of STL algorithms classified as per the STL world map
 * created by Jonathan Boccara of fluentcpp:
 * https://www.fluentcpp.com/getthemap/
 * @version 0.1
 * @date 2019-01-28
 *
 * @copyright Copyright (c) 2019
 *
 */
#include <algorithm>
#include <functional>
#include <random>
#include <vector>
#include "Vector.h"

namespace stl {
/**
 * @brief STL SequenceContainer type deduction
 *
 * @tparam T value type
 */
template <typename T>
struct is_seq_container : std::false_type {};
template <typename T>
struct is_seq_container<std::vector<T>> : std::true_type {};
template <typename T>
struct is_seq_container<Vector<T>> : std::true_type {};

template <typename T>
struct is_sequence_container {
  static constexpr bool const value =
      stl::is_seq_container<std::decay_t<T>>::value;
};

}  // namespace stl

namespace algos {

namespace mods {

/**
 * @brief Wrapper around std::fill
 *
 * @param value Value to be filled with
 */
template <typename T>
void Fill(T &container, const typename T::value_type &value) {
  std::fill(std::begin(container), std::end(container), value);
}

/**
 * @brief Wrapper arounf std::fill_n
 *
 * @param count The count till which the value has to be filled
 * @param value value to be filled
 */
template <typename T>
void Fill(T &container, std::size_t count,
          const typename T::value_type &value) {
  static_assert(stl::is_sequence_container<T>::value);
  std::fill_n(std::begin(container), count, value);
}

/**
 * @brief Wrapper around std::iota
 *
 * @param startingValue Starting value of the sequence
 *
 */
template <typename T>
void FillWithSequentialValues(T &container,
                              const typename T::value_type &value) {
  static_assert(stl::is_sequence_container<T>::value);
  std::iota(std::begin(container), std::end(container), value);
}

/**
 * @brief Random Number Generator
 *
 * @return int Integer that was generated
 */
inline int RandomGen() {
  std::random_device device;
  auto value = device();
  return value;
}
/**
 * @brief Wrapper around std::generate with a random generator
 * std::function provided
 *
 * @param func Random function genrator object, default = RandomGen()
 */
template <typename T>
void FillWithRandomGeneratedValues(
    T &container, std::function<const typename T::value_type(void)> func =
                      std::bind(RandomGen)) {
  static_assert(stl::is_sequence_container<T>::value);
  std::generate(std::begin(container), std::end(container), func);
}

/**
 * @brief Wrapper around std::generate with a random generator
 * std::function provided
 *
 * @param count The count till which the value has to be filled
 * @param func Random function genrator object, default = RandomGen()
 */
template <typename T>
void FillWithRandomGeneratedValues(
    T &container, std::size_t count,
    std::function<const typename T::value_type(void)> func = RandomGen) {
  static_assert(stl::is_sequence_container<T>::value);
  std::generate_n(std::begin(container), count, func);
}
/**
 * @brief Wrapper around std::replace
 *
 * @tparam T Type of the container
 * @param container Reference to the container
 * @param valueOne Value to be replaced
 * @param valueTwo Value to be replaced by
 */
template <typename T>
void ReplaceValues(T &container, const typename T::value_type &valueOne,
                   const typename T::value_type &valueTwo) {
  static_assert(stl::is_sequence_container<T>::value);
  std::replace(std::begin(container), std::end(container), valueOne, valueTwo);
}
}  // namespace mods

namespace changers {

/**
 * @brief Wrapper around std::unique where the consecutive identical values are
 * removed
 *
 * @tparam T Container type
 * @param container Reference to the container
 */
template <typename T>
void MakeItUnique(T &container) {
  static_assert(stl::is_sequence_container<T>::value);
  container.erase(std::unique(std::begin(container), std::end(container)),
                  std::end(container));
}

/**
 * @brief Wrapper around std::remove
 *
 * @tparam T Container type
 * @param container Reference to the container
 * @param value Value to be removed
 */
template <typename T>
void Remove(T &container, const typename T::value_type &value) {
  static_assert(stl::is_sequence_container<T>::value);
  container.erase(
      std::remove(std::begin(container), std::end(container), value),
      std::end(container));
}

}  // namespace changers

namespace movers {

/**
 * @brief Wrapper around std::copy_if
 *        Temporarily used for sequence containers(ex: Vector, std::Vector)
 *
 * @tparam T Container Type
 * @tparam Pred Callable Object
 * @param copyfrom Source Container
 * @param copyto Destination Container
 * @param func Unary predicate
 */
template <typename T, typename Pred>
void CopyIf(T &copyfrom, T &copyto, const Pred &func) {
  static_assert(stl::is_sequence_container<T>::value);
  auto it = std::copy_if(std::begin(copyfrom), std::end(copyfrom),
                         std::begin(copyto), func);
  copyto.resize(std::distance(std::begin(copyto), it));
}

/**
 * @brief Wrapper around std::copy_backward
 *        Temporarily used for sequence containers(ex: Vector, std::Vector)
 *
 * @tparam T Container type
 * @param copyfrom Source Container
 * @param copyto Destination Container
 */
template <typename T>
void CopyBackward(T &copyfrom, T &copyto) {
  static_assert(stl::is_sequence_container<T>::value);
  std::copy_backward(std::begin(copyfrom), std::end(copyfrom),
                     std::end(copyto));
}

}  // namespace movers

}  // namespace algos
