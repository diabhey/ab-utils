#include <bits/stdc++.h>
#include <iostream>
#include <vector>

template <typename T>
class Matrix {
  using mat = std::vector<std::vector<T>>;

 public:
  Matrix(const std::size_t row, const std::size_t col)
      : cRows(row), cCols(col), mMatrix(cRows, std::vector<T>(cCols)) {}

  void ReadMatrixFromInputStream() {
    for (auto &row : mMatrix) {
      for (auto &col : row) {
        std::cin >> mMatrix[row][col];
      }
    }
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
  }
  const Matrix<T> &GetMatrix() const { return mMatrix; }

 private:
  const std::size_t cRows;
  const std::size_t cCols;
  mat mMatrix;
};

template <typename T>
std::ostream &operator<<(std::ostream &os, const Matrix<T> &matrix) {
  for (const auto &row : mMatrix) {
    for (const auto &col : row) {
      std::cout << col << ' ';
    }
    std::cout << std::endl;
  }
  return os;
}

template <typename T>
std::istream &operator>>(std::istream &input, const Matrix<T> &matrix) {
  for (auto &row : mMatrix) {
    for (auto &col : row) {
      input >> mMatrix[row][col];
    }
  }
  return input;
}

// Caller
int main() {
  const auto x = 2;
  const auto y = 2;
  Matrix<int> mat(x, y);
  return 0;
}
