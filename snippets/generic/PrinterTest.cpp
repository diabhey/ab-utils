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
#include <vector>
#include "Printer.h"

using namespace std::experimental;

/**
 * @brief Entry point into the test application
 *
 */
int main() {
  auto vec = std::vector<int>{1, 2, 3, 4, 5};
  ab::printer(std::cout, source_location::current(), "vec:", vec,
              "integer:", int{7}, "map:", std::map<int, int>{{1, 2}});
  return EXIT_SUCCESS;
}
