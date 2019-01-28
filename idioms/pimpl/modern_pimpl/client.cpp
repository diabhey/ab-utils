/**
 * @file client.cpp
 * @author bigillu
 * @brief modern pimpl implementation tester
 * Code compilation:
 * g++-7 -std=c++17 -I/ModernPimpl.h ModernPimpl.cpp client.cpp
 *
 * @version 0.1
 * @date 2019-01-11
 *
 * @copyright Copyright (c) 2019
 *
 */
#include "ModernPimpl.h"

int main() {
  {
    ModernPimpl obj;
    obj.Print();
  }
  {
    const ModernPimpl cObj;
    cObj.Print();
  }
  return EXIT_SUCCESS;
}