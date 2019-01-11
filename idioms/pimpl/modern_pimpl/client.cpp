/**
 * @file client.cpp
 * @author bigillu
 * @brief modern pimpl implementation tester
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