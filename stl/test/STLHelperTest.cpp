/**
 * @file STLHelperTest.cpp
 * @author bigillu
 * @brief Tester class for STLHelper
 * @version 0.1
 * @date 2018-12-02
 *
 * @copyright Copyright (c) 2018
 *
 */

#include <gtest/gtest.h>
#include <map>
#include "UtilityFunctions.h"
#include "Vector.h"

class STLHelperTest : public ::testing::Test {
 public:
  void SetUp() override {}
  void TearDown() override {}
};

TEST_F(STLHelperTest, CopyIfTestForSequenceContainer) {
  Vector<int> srcVec(10);
  Vector<int> dstVec(10);
  algos::mods::FillWithSequentialValues(srcVec, 0);
  algos::movers::CopyIf(srcVec, dstVec, [](int i) { return !(i < 5); });
  ASSERT_NE(srcVec.GetVector(), dstVec.GetVector());
}

TEST_F(STLHelperTest, CopyBakcwardForSequenceContainer) {
  Vector<int> srcVec(10);
  Vector<int> dstVec(10);
  algos::mods::FillWithSequentialValues(srcVec, 0);
  algos::movers::CopyBackward(srcVec, dstVec);

  ASSERT_EQ(dstVec.GetVector(), srcVec.GetVector());
}
