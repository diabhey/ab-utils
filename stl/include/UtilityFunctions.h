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
 * @brief Random Number Generator
 *
 * @return int Integer that was generated
 */
int RandomGen() {
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
  container.erase(
      std::remove(std::begin(container), std::end(container), value),
      std::end(container));
}

}  // namespace changers


}  // namespace algos
