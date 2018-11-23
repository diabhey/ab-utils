#include <algorithm>
#include <functional>
#include <random>

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
  std::iota(std::begin(container), std::end(container), value);
}
/**
 * @brief
 *
 * @return int
 */
int RandomGenerator() {
  std::random_device device;
  auto value = device();
  return value;
}
/**
 * @brief Wrapper around std::generate with a random generator
 * std::function provided
 *
 * @param func Random function genrator object, default =
 RandomGenerator()
 */
template <typename T>
void FillWithRandomGeneratedValues(
    T &container, std::function<const typename T::value_type(void)> func =
                      std::bind(RandomGenerator)) {
  std::generate(std::begin(container), std::end(container), func);
}

/**
 * @brief Wrapper around std::generate with a random generator
 * std::function provided
 *
 * @param count The count till which the value has to be filled
 * @param func Random function genrator object, default =
 RandomGenerator()
 */
template <typename T>
void FillWithRandomGeneratedValues(
    T &container, std::size_t count,
    std::function<const typename T::value_type(void)> func = RandomGenerator) {
  std::generate_n(std::begin(container), count, func);
}

template <typename T>
void ReplaceValues(T &container, const typename T::value_type &valueOne,
                   const typename T::value_type &valueTwo) {
  std::replace(std::begin(container), std::end(container), valueOne, valueTwo);
}
}
}
