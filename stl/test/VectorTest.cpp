/**
 * @file VectorTest.cpp
 * @author bigillu
 * @brief Tester class for Vector
 * @version 0.1
 * @date 2018-12-02
 *
 * @copyright Copyright (c) 2018
 *
 */
#include <gtest/gtest.h>
#include <iostream>
#include <map>
#include <vector>
#include "AnyContainer.h"
#include "UtilityFunctions.h"
#include "Vector.h"

namespace stl::vector::test {

class VectorTest : public ::testing::Test {
 public:
  void SetUp() override {}
  void TearDown() override {}
};

TEST_F(VectorTest, DefaultConstruction) {
  Vector<int> testVec;
  ASSERT_EQ(0, testVec.GetSize());
}

TEST_F(VectorTest, ParameterizedConstruction) {
  Vector<int> testVec(2);
  ASSERT_EQ(2, testVec.GetSize());
}

TEST_F(VectorTest, CopyConstruction) {
  Vector<int> testVec(5);
  algos::mods::Fill(testVec, 3, 7);
  Vector<int> testVecCopy(testVec);
  EXPECT_EQ(testVec.GetVector(), testVecCopy.GetVector());
}

TEST_F(VectorTest, PreventSelfCopyAssignment) {
  Vector<int> testVec;
  testVec = testVec;
  ASSERT_EQ(testVec.GetVector(), testVec.GetVector());
}

TEST_F(VectorTest, CopyAssignment) {
  Vector<int> testVec(5);
  algos::mods::FillWithSequentialValues(testVec, 100);
  Vector<int> testVecCopy = testVec;
  ASSERT_TRUE(testVecCopy.GetVector() == testVec.GetVector());
}

TEST_F(VectorTest, MoveConstruction) {
  Vector<int> testVec(2);

  algos::mods::Fill(testVec, 100);
  Vector<int> testVecMove(std::move_if_noexcept(testVec));
  ASSERT_FALSE(testVec.GetVector() == testVecMove.GetVector());
}

TEST_F(VectorTest, MoveAssignment) {
  Vector<int> testVec(2);
  algos::mods::FillWithRandomGeneratedValues(testVec);
  Vector<int> testVecMove = std::move_if_noexcept(testVec);
  ASSERT_FALSE(testVec.GetVector() == testVecMove.GetVector());
}

TEST_F(VectorTest, IteratorBeginEnd) {
  Vector<int> testVec(3);
  algos::mods::FillWithSequentialValues(testVec, 55);
  ASSERT_EQ(testVec.GetSize(), 3);
  EXPECT_EQ(*testVec.begin(), 55);
  EXPECT_EQ(*(testVec.end() - 1), 57);
}

TEST_F(VectorTest, Erase) {
  Vector<int> testVec(2);
  algos::mods::Fill(testVec, 100);
  testVec.erase(std::begin(testVec), std::end(testVec));
  ASSERT_TRUE(testVec.GetSize() == 0);
}

TEST_F(VectorTest, AnyTypeHolder) {
  std::vector<AnyContainer> ce;
  std::vector<double> dVec{1.0, 2.0};
  Vector<int> intVec(2);
  algos::mods::FillWithSequentialValues(intVec, 55);
  Vector<std::string> stringVec;
  std::map<int, std::string> stringMap;
  ce.push_back(intVec);
  ce.push_back(stringVec);
  ce.push_back(stringMap);
  ce.push_back(dVec);

  for (const auto& itr : ce) {
    std::cout << std::boolalpha << itr.empty() << std::endl;
  }
}
/**
 * @brief TODO
 * 1. How to determine the type
 * 2. What all can we once we know the type.
 */
}  // namespace stl::vector::test