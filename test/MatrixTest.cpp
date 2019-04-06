#include <gtest/gtest.h>
#include <gmock/gmock.h>

#include "../src/Matrix.h"

TEST(MatrixTest, MatrixTest) {
	float first[4] = {1, 2, 3, 4};
  float second[4] = {5.5, 6.5, 7.5, 8.5};
  float third[4] = {9, 10, 11, 12};
  float fourth[4] = {13.5, 14.5, 15.5, 16.5};
  Matrix4 m = Matrix4(first, second, third, fourth);

  EXPECT_EQ(m.get(0,0), 1.0);
  EXPECT_EQ(m.get(0,3), 4);
  EXPECT_EQ(m.get(1,0), 5.5);
  EXPECT_EQ(m.get(1,2), 7.5);
  EXPECT_EQ(m.get(2,2), 11);
  EXPECT_EQ(m.get(3,0), 13.5);
  EXPECT_EQ(m.get(3,2), 15.5);

 //  EXPECT_TRUE(equal(c.getWidth(), 10));
}