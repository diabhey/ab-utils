/**
 * @file CustomDeque.h
 * @author bigillu
 * @brief Custom Deque implementation
 * @version 0.1
 * @date 2019-01-28
 *
 * @copyright Copyright (c) 2019
 *
 */
#include <deque>
#include <iostream>
#include <stdexcept>
#include <utility>

template <typename T, size_t SIZE = 10>
class CustomDeque {
  template <typename U>
  using if_integral_or_string = typename std::enable_if<
      std::is_integral<U>::value || std::is_same<std::string, U>::value, U>;

 private:
  using itr = typename std::deque<T>::iterator;
  using size_type = typename std::deque<T>::size_type;
  std::deque<T> mCDeq;
  size_type mCDeqMaxSize;

 public:
  CustomDeque() : mCDeq{}, mCDeqMaxSize(SIZE) {}

  void push(T const &elem) {
    if (mCDeq.size() >= mCDeqMaxSize) {
      throw std::length_error("Max size has been reached!");
    }
    mCDeq.push_back(elem);
  }

  void pop() {
    if (empty()) {
      throw std::out_of_range("CustomDeque is empty!");
    }
    mCDeq.pop_back();
  }

  void resize(const size_type size) { mCDeq.resize(size); }

  const T &front() const { return mCDeq[0]; }

  size_t size() const { return mCDeq.size(); }

  bool empty() const { return mCDeq.empty(); }

  void print(std::ostream &out) const {
    out << "\nDeque: ";
    for (auto i : mCDeq) {
      out << i << " ";
    }
    out << '\n';
  }

  // Overloaded subscript operator [] to extract the content of the deque at a
  // particular index
  const T &operator[](const size_type &value) { return mCDeq[value]; }

  // Overloaded stream to print the contents of the deque.
  template <typename U = T, typename = typename if_integral_or_string<U>::type>
  friend std::ostream &operator<<(std::ostream &out,
                                  const class CustomDeque<T, SIZE> &customDeq) {
    customDeq.print(out);
    return out;
  }
};
