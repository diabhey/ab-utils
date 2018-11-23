#include "UtilFunc.h"
#include "Vector.h"
#include <iostream>

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

  algos::mods::Fill(vec, 110);

  std::cout << vec.GetVector() << std::endl;

  algos::mods::Fill(vec, 2);
  std::cout << "Testing std::fill " << vec.GetVector() << std::endl;

  algos::mods::FillWithSequentialValues(vec, 101);
  std::cout << "Testing std::iota " << vec.GetVector() << std::endl;

  // Sequential static generator
  auto SequentialGen = []() {
    static int x = 0;
    x++;
    return x;
  };
  std::function<int(void)> FuncGen = SequentialGen;

  algos::mods::FillWithRandomGeneratedValues(vec /*default generator used*/);
  std::cout << "Testing std::generate with default RGN " << vec.GetVector()
            << std::endl;

  algos::mods::FillWithRandomGeneratedValues(vec, 2 /*default generator used*/);
  std::cout << "Testing std::generate_n with default RGN " << vec.GetVector()
            << std::endl;

  algos::mods::FillWithRandomGeneratedValues(vec, FuncGen);
  std::cout << "Testing std::generate with user defined RGN " << vec.GetVector()
            << std::endl;

  algos::mods::FillWithRandomGeneratedValues(vec, 2, FuncGen);
  std::cout << " Testing std::generate_n with user defined RGN "
            << vec.GetVector() << std::endl;

  algos::mods::Fill(vec, 2);
  algos::mods::ReplaceValues(vec, 2, 5);
  std::cout << "Testing std::replace " << vec.GetVector() << std::endl;

  return EXIT_SUCCESS;
}