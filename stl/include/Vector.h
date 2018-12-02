#pragma once

/**
 * @file Vector.h
 * @author bigillu
 * @brief Super Sayyan Vector
 * @version 0.1
 * @date 2018-12-02
 *
 * @copyright Copyright (c) 2018
 *
 */
#include <cassert>
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
template <typename T>
class Vector {
 public:
  /**
   * @brief Public Typedefs
   *
   */
  using iterator = typename std::vector<T>::iterator;
  using const_iterator = typename std::vector<T>::const_iterator;
  using value_type = T;

  /**
   * @brief Default constructor of Vector
   *
   */
  Vector() {}

  /**
   * @brief Parameterized constructor of Vector
   *
   * @param size size of the vector
   */
  Vector(const std::size_t size) { mVector.resize(size); }

  /**
   * @brief Copy constructor of Vector
   *
   * @param rhs
   */
  Vector(const Vector &rhs) { copy(rhs); }

  /**
   * @brief Copy assignment operator
   *
   * @param rhs Vector to be copied
   * @return Vector& Reference to this
   */
  Vector &operator=(const Vector &rhs) {
    if (this != &rhs) {
      copy(rhs);
    }
    return *this;
  }

  /**
   * @brief Move constructor of Vector
   *
   * @param other
   */
  Vector(Vector &&other) noexcept : mVector(std::exchange(other.mVector, {})) {}

  /**
   * @brief Move assignment operator
   *
   * @param rhs Vector to be moved
   * @return Vector& Reference to this
   */
  Vector &operator=(Vector &&rhs) {
    assert(this != &rhs);
    std::swap(mVector, rhs.mVector);
    return *this;
  }

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
   * @brief Get the Size object
   * @return const std::size_t
   */
  const std::size_t GetSize() const { return mVector.size(); }

  /**
   * @brief Returns the iterator to the beginning of the container
   *
   * @return iterator iterator(wrapped around std::vector<T>::iterator)
   */
  iterator begin() { return mVector.begin(); }

  /**
   * @brief Returns the iterator to the end of the container
   *
   * @return iterator iterator(std::vector<T>::iterator)
   */
  iterator end() { return mVector.end(); }

  /**
   * @brief Returns the const_iterator to the beginning of the container
   *
   * @return iterator const_iterator(std::vector<T>::const_iterator)
   *
   */
  const_iterator begin() const { return mVector.cbegin(); }

  /**
   * @brief Returns the const_iterator to the end of the container
   *
   * @return iterator const_iterator(std::vector<T>::const_iterator)
   */
  const_iterator end() const { return mVector.cend(); }

  /**
   * @brief Wrapper around vector::erase
   *
   * @param current The iterator which points to the value to be erased
   * @param end Iterator that points to the end of the container
   */
  void erase(const iterator &current, const iterator &end) {
    mVector.erase(current, end);
  }

  bool empty() const { return mVector.empty(); }

 private:
  /**
   * @brief Wrapper around std::copy
   *
   * @param rhs Vector to be copied
   */
  void copy(const Vector &rhs) {
    mVector.resize(rhs.GetSize());
    mVector.clear();
    std::copy(rhs.begin(), rhs.end(), std::back_inserter(mVector));
  }

  std::vector<T> mVector;
};