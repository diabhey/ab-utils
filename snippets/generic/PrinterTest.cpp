/**
 * @file PrinterTest.cpp
 * @author Bigillu
 * @brief Test application for the Printer library
 * @version 0.1
 * @date 2019-06-08
 *
 * @copyright Copyright (c) 2019
 *
 */
#include <iostream>
#include <map>
#include <memory>
#include <vector>
#include "Printer.h"

/**
 * @brief Coordinate class
 * Used for test purposes only
 */
class Coord {
 public:
  Coord(int x_, int y_) : mX(x_), mY(y_) {}

  friend std::ostream& operator<<(std::ostream& s, const Coord& obj) {
    s << "Coord: { " << obj.mX << ", " << obj.mY << " }";
    return s;
  }

 private:
  int mX, mY;
};

/**
 * @brief Entry point into the test application
 *
 */
int main() {
  auto i = 9;
  Coord c{1, 2};
  std::unique_ptr<Coord> pC = std::make_unique<Coord>(c);

  ab::Printer p;
  p.print(std::cout, c);
  p.print(std::cout, std::move(pC));
  p.print(std::cout, char{'c'});
  p.print(std::cout, int{7});
  p.print(std::cout, double{3.14});
  p.print(std::cout, "bigillu");
  // p.print(std::cout, std::vector<int>{1, 2, 3, 4, 5});
  p.print(std::cout, std::map<int, int>{{1, 2}, {4, 5}});
  p.print(std::cout, &i);
  return EXIT_SUCCESS;
}

// TODO
// Smart pointer support
// More tests for other types like uple, hash_map
// Test with log file
// Dispatcher
// Pass custom messages
// Variadic Templates
