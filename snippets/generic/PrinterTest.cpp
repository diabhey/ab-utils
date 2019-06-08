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

int main() {
  Printer p;
  p.print(std::cout, char{'c'});
  p.print(std::cout, int{7});
  p.print(std::cout, double{3.14});
  p.print(std::cout, "bigillu");
  p.print(std::cout, std::vector<int>{1, 2, 3, 4, 5});
  p.print(std::cout, std::map<int, int>{{1, 2}, {4, 5}});
  auto i = 9;
  p.print(std::cout, &i);
  return EXIT_SUCCESS;
}