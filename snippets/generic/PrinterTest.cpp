/**
 * @file PrinterTest.cpp
 * @author Bigillupe
 * @brief Test application for the Printer library
 * @version 0.1
 * @date 2019-06-08
 *
 * @copyright Copyright (c) 2019
 *
 */
#include <array>
#include <deque>
#include <iostream>
#include <list>
#include <map>
#include <vector>
#include "Printer.h"

using namespace std::experimental;

/**
 * @brief Entry point into the test application
 *
 */
int main() {
  ab::printer(std::cout, source_location::current(), "\n char:", char{'a'},
              "\n int", int{7}, "\n double", double{2.2});
  ab::printer(std::cout, source_location::current(),
              "\n vector:", std::vector<int>{1, 2, 3, 4, 5},
              "\n deque:", std::deque<int>{1, 2, 3, 4, 5},
              "\n list:", std::list<int>{1, 2, 3, 4, 5},
              "\n array:", std::array<int, 5>{1, 2, 3, 4, 5});

  return EXIT_SUCCESS;
}
