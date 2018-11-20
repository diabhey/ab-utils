// #pragma once
/**
 * @brief: Super Sayyan Vector
 *
 * @author: bigillu
 */

#include <algorithm>
#include <functional>
#include <iostream>
#include <random>
#include <vector>
/**
 * @brief Overloaded << operator to print the contents of a std::vector
 *
 * @tparam U type of the vector
 * @param os ostream reference
 * @param v vector to be displayed
 * @return std::ostream&
 */
template <typename U>
std::ostream &operator<<(std::ostream &os, const std::vector<U> &v) {
  os << "[ ";
  for (const auto itr : v) {
    os << itr << " ";
  }
  os << "] " << std::endl;
  return os;
}
/**
 * @brief Wrapper around std::vector with powerdul functionalities
 *
 * @tparam T type of the vector values
 */
template <typename T>
class Vector {
 public:
  /**
   * @brief Construct a new Vector object
   *
   */
  Vector() {
    // Intialise the vector with 0 using std::fill
    std::fill(std::begin(mVector), std::end(mVector), 0);
  }

  /**
   * @brief Parameterized Constructor of Vector
   *
   * @param size size of the vector
   */
  Vector(std::size_t size) { mVector.resize(size); }

  /**
   * @brief Get the const Vector object
   *
   * @return const std::vector<T>&
   */
  const std::vector<T> &GetVector() const { return mVector; }

  /**
   * @brief Get the non const Vector object
   *
   * @return std::vector<T>&
   */
  std::vector<T> &GetVector() { return mVector; }

  /**
   * @brief Wrapper around std::fill
   *
   * @param value Value to be filled with
   */
  inline void Fill(T value) {
    std::fill(std::begin(mVector), std::end(mVector), value);
  }
  /**
   * @brief Wrapper arounf std::fill_n
   *
   * @param count The count till which the value has to be filled
   * @param value value to be filled
   */
  inline void Fill(std::size_t count, T value) {
    std::fill_n(std::begin(mVector), count, value);
  }
  /**
   * @brief Wrapper around std::iota
   *
   * @param startingValue Starting value of the sequence
   *
   */
  inline void FillwithSequentialValues(T startingValue) {
    std::iota(std::begin(mVector), std::end(mVector), startingValue);
  }
  /**
   * @brief Wrapper around std::generate with default
   * random generator
   *
   */
  inline void FillwithRandomValues() {
    std::generate(std::begin(mVector), std::end(mVector), RandomGenerator);
  }
  /**
   * @brief Wrapper around std::generate with default
   * random generator
   *
   * @param count The count till which the value has to be filled
   */
  inline void FillwithRandomValues(std::size_t count) {
    std::generate_n(std::begin(mVector), count, RandomGenerator);
  }

  /**
   * @brief Wrapper around std::generate with a random generator
   * std::function provided
   *
   * @param func Random function genrator object
   */
  inline void FillwithGeneratorFunc(std::function<T(void)> &func) {
    std::generate(std::begin(mVector), std::end(mVector), func);
  }

  /**
   * @brief Wrapper around std::generate with a random generator
   * std::function provided
   *
   * @param count The count till which the value has to be filled
   * @param func Random function genrator object
   */
  inline void FillwithGeneratorFunc(std::size_t count,
                                    std::function<T(void)> &func) {
    std::generate_n(std::begin(mVector), count, func);
  }

 private:
  static T RandomGenerator() {
    std::random_device device;
    auto value = device();
    return value;
  }
  std::vector<T> mVector;
};

int gen() {
  static int x = 1;
  x++;
  return x;
}

/**
 * @brief Tester: Sole purpose is to test the functionality of Vector class
 * TODO To be removed
 *
 * @return int Error code
 */
int main() {
  Vector<int> vec(5);

  vec.Fill(2);
  vec.GetVector().push_back(5);
  vec.FillwithSequentialValues(101);

  auto StaticGenerate = []() {
    static int x = 0;
    x++;
    return x;
  };
  std::function<int(void)> FuncGen = StaticGenerate;
  vec.FillwithGeneratorFunc(FuncGen);
  std::cout << vec.GetVector() << std::endl;

  return EXIT_SUCCESS;
}