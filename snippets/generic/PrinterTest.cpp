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
  ab::printer(std::cout, source_location::current(), "char: ", char{'c'},
              ", integer: ", int{7}, ", double: ", double{2.2});
  return EXIT_SUCCESS;
}
