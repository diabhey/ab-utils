/**
 * @brief: Custom Matrix Wrapper
 * @copyright: Copyright (c) HeartyByte.Inc 2018, All Rights Reserved.
 */

#include <bits/stdc++.h>
#include <iostream>
#include <vector>

template <typename T>
class Matrix {
  using mat = std::vector<std::vector<T>>;

 public:
  Matrix(const std::size_t row, const std::size_t col)
      : cRows(row), cCols(col), mMatrix(cRows, std::vector<T>(cCols)) {}

  const mat &GetMatrix() const { return mMatrix; }
  const size_t GetRows() const { return cRows; }
  const size_t GetCols() const { return cCols; }

  /*
    Overloading operators with specific functonalities
  */
  friend std::ostream &operator<<(std::ostream &os, const Matrix &matrix) {
    for (const auto &row : matrix.GetMatrix()) {
      for (const auto &col : row) {
        os << col << " ";
      }
      os << std::endl;
    }
    return os;
  }

  /* TODO - Look into range based input reader
  Need to implement iterators. */
  friend std::istream &operator>>(std::istream &is, Matrix &matrix) {
    for (unsigned i = 0; i < matrix.GetRows(); ++i) {
      for (unsigned j = 0; j < matrix.GetCols(); ++j) {
        is >> matrix[i][j];
      }
    }
    return is;
  }

  std::vector<T> &operator[](size_t row) { return mMatrix[row]; }

  const std::vector<T> &operator[](size_t row) const { return mMatrix[row]; }

 private:
  const std::size_t cRows;
  const std::size_t cCols;
  mat mMatrix;
};
