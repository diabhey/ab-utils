#pragma once
/**
 * @brief: Super Sayyan Vector
 *
 * @author: bigillu
 */

#include <iostream>
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
  for (const auto &itr : v) {
    os << itr << " ";
  }
  os << "] " << std::endl;
  return os;
}

/**
 * @brief Wrapper around std::vector with powerful functionalities
 *
 * @tparam T type of the vector values
 */
template <typename T> class Vector {
public:
  /**
   * @brief Public Typedefs
   *
   */
  using iterator = typename std::vector<T>::iterator;
  using value_type = T;

  /**
   * @brief Returns the custom iterator to the beginning of the container
   *
   * @return iterator Custom Iterator(wrapped around std::vector<T>::iterator)
   */
  iterator begin() { return mVector.begin(); }

  /**
   * @brief Returns the custom iterator to the end() of the container
   *
   * @return iterator Custom Iterator(wrapped around std::vector<T>::iterator)
   */
  iterator end() { return mVector.end(); }

  /**
   * @brief Default construct a new Vector obejct
   *
   */
  Vector() { std::fill(std::begin(mVector), std::end(mVector), 0); }

  /**
   * @brief Parameterized Constructor of Vector
   *
   * @param size size of the vector
   */
  Vector(std::size_t size) : mSize(size) { mVector.resize(mSize); }

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

private:
  std::vector<T> mVector;
  std::size_t mSize;
};
