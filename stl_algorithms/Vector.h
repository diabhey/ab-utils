#pragma once
/**
 * @brief: Super Sayyan Vector
 *
 * @author: bigillu
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
  using value_type = T;

  /**
   * @brief Default construct a new Vector obejct
   *
   */
  Vector() {}

  /**
   * @brief Parameterized Constructor of Vector
   *
   * @param size size of the vector
   */
  Vector(std::size_t size) : mSize(size) { mVector.resize(mSize); }

  /**
   * @brief Copy constructor a new Vector object
   *
   * @param rhs
   */
  Vector(Vector &rhs) {
    assert(CopyPolicy(rhs));
    std::copy(this->begin(), this->end(), std::back_inserter(rhs.GetVector()));
  }

  /**
   * @brief
   *
   * @param rhs
   * @return Vector&
   */
  Vector &operator=(Vector &rhs) {
    assert(CopyPolicy(rhs));
    return *this = Vector(rhs);
  }

  /**
   * @brief
   *
   * @param rhs
   * @return Vector&
   */
  Vector &operator=(Vector &&rhs) {
    std::swap(mVector, rhs.mVector);
    std::swap(mSize, rhs.mSize);
    return *this;
  }
  /**
   * @brief Construct a new Vector object
   *
   * @param other
   */
  Vector(Vector &&other) noexcept
      : mVector(std::exchange(other.mVector, {})),
        mSize(std::exchange(other.mSize, 0)) {}
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
   * @brief Get the Size object *
   * @return const std::size_t
   */
  const std::size_t GetSize() const { return mSize; }

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
   * @brief Wrapper around vector::erase
   *
   * @param current The iterator which points to the value to be erased
   * @param end Iterator that points to the end of the container
   */
  void erase(const iterator &current, const iterator &end) {
    mVector.erase(current, end);
  }

 private:
  /**
   * @brief
   *
   * @tparam pred
   * @param predicate
   * @return true
   * @return false
   */
  bool CopyPolicy(Vector &predicate) {
    return this->GetSize() == predicate.GetSize();
  }

  std::vector<T> mVector;
  std::size_t mSize;
};