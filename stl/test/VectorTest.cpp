#include <gtest/gtest.h>
#include <iostream>
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
  Vector<int> testVec;
  algos::mods::Fill(testVec, 100);
  Vector<int> testVecCopy(testVec);
  EXPECT_EQ(testVec.GetVector(), testVecCopy.GetVector());
}

TEST_F(VectorTest, PreventSelfCopyAssignment) {
  Vector<int> testVec;
  algos::mods::Fill(testVec, 100);
  testVec = testVec;
  ASSERT_EQ(testVec.GetVector(), testVec.GetVector());
}

TEST_F(VectorTest, CopyAssignment) {
  Vector<int> testVec(5);
  algos::mods::Fill(testVec, 100);
  Vector<int> testVecCopy = testVec;
  ASSERT_FALSE(testVecCopy.GetVector() == testVec.GetVector());
}

TEST_F(VectorTest, MoveConstruction) {
  Vector<int> testVec(2);
  algos::mods::Fill(testVec, 100);
  Vector<int> testVecMove(std::move_if_noexcept(testVec));
  ASSERT_FALSE(testVec.GetVector() == testVecMove.GetVector());
}

}  // namespace stl::vector::test
