#include <iostream>
#include "UtilFunc.h"
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

  std::cout << "********** Testing Value Modiers  **********\n" << std::endl;
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

  algos::mods::
      FillWithRandomGeneratedValues(vec /*default generator
used*/);
  std::cout << "Testing std::generate with default RGN " << vec.GetVector()
            << std::endl;

  algos::mods::
      FillWithRandomGeneratedValues(vec, 2 /*default generator
used*/);
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

  std::cout << "********** Testing Structural Changers  **********\n"
            << std::endl;
  Vector<double> dVec;
  dVec.GetVector().push_back(1);
  dVec.GetVector().push_back(1);
  dVec.GetVector().push_back(2);
  dVec.GetVector().push_back(1);
  dVec.GetVector().push_back(1);
  dVec.GetVector().push_back(4);

  algos::changers::MakeItUnique(dVec);
  std::cout << "Testing std::unique " << dVec.GetVector() << std::endl;
  algos::changers::Remove(dVec, 1);
  std::cout << "Testing std::remove " << dVec.GetVector() << std::endl;
  return EXIT_SUCCESS;
}