#include <iostream>
#include "Vector.h"

/**
 * @brief Tester: Sole purpose of this app is to test the functionality of
 * Vector
 * TODO To be removed
 *
 * @return int Error code
 */
int main() {
  // Create a Vector instance
  Vector<int> vec(5);

  vec.Fill(2);
  std::cout << "Testing std::fill " << vec.GetVector() << std::endl;

  vec.FillwithSequentialValues(101);
  std::cout << "Testing std::iota " << vec.GetVector() << std::endl;

  // Sequential static generator
  auto SequentialGen = []() {
    static int x = 0;
    x++;
    return x;
  };
  std::function<int(void)> FuncGen = SequentialGen;

  vec.FillwithRandomGeneratedValues(/*default generator used*/);
  std::cout << "Testing std::generate with default RGN " << vec.GetVector()
            << std::endl;

  vec.FillwithRandomGeneratedValues(2 /*default generator used*/);
  std::cout << "Testing std::generate_n with default RGN " << vec.GetVector()
            << std::endl;

  vec.FillwithRandomGeneratedValues(FuncGen);
  std::cout << "Testing std::generate with user defined RGN " << vec.GetVector()
            << std::endl;

  vec.FillwithRandomGeneratedValues(2, FuncGen);
  std::cout << " Testing std::generate_n with user defined RGN "
            << vec.GetVector() << std::endl;

  vec.Fill(2);
  vec.ReplaceValues(2, 5);
  std::cout << "Testing std::replace " << vec.GetVector() << std::endl;

  /**
   * TODO Continue implementation of replace and replace_if
   * try and classify the value modifiers into a separate class or
   * equivalent
   */

  return EXIT_SUCCESS;
}