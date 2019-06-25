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
#include "Printer.h"

using namespace std::experimental;

/**
 * @brief Entry point into the test application
 *
 */
int main() {
  ab::print(std::cout, source_location::current(), char{'c'});
  ab::print(std::cout, source_location::current(), int{7});
  ab::print(std::cout, source_location::current(), double{3.14});
  return EXIT_SUCCESS;
}
