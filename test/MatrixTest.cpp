#include <gtest/gtest.h>
#include <gmock/gmock.h>

#include "../src/Matrix.h"
#include "../src/Utils.h"

TEST(Matrix4Test, MatrixTest) {
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
}

TEST(Matrix2Test, MatrixTest) {
	float first[2] = {-3, 5};
  float second[2] = {1, -2};
  Matrix2 m = Matrix2(first, second);

  EXPECT_EQ(m.get(0,0), -3);
  EXPECT_EQ(m.get(0,1), 5);
  EXPECT_EQ(m.get(1,0), 1);
  EXPECT_EQ(m.get(1,1), -2);
}

TEST(Matrix3Test, MatrixTest) {
	float first[3] = {-3, 5, 0};
  float second[3] = {1, -2, -7};
  float third[3] = {0, 1, 1};
  Matrix3 m = Matrix3(first, second, third);

  EXPECT_EQ(m.get(0,0), -3);
  EXPECT_EQ(m.get(1,1), -2);
  EXPECT_EQ(m.get(2,2), 1);
}

TEST(Matrix4EqualTest, MatrixTest) {
	float first[4] = {1, 2, 3, 4};
  float second[4] = {5, 6, 7, 8};
  float third[4] = {9, 8, 7, 6};
  float fourth[4] = {5, 4, 3, 2};
  Matrix4 m1 = Matrix4(first, second, third, fourth);
  Matrix4 m2 = Matrix4(first, second, third, fourth);

  EXPECT_TRUE(equalM4(m1, m2));
}

TEST(Matrix4NotEqualTest, MatrixTest) {
	float first[4] = {1, 2, 3, 4};
  float second[4] = {5, 6, 7, 8};
  float third[4] = {9, 8, 7, 6};
  float fourth[4] = {5, 4, 3, 2};

  Matrix4 m1 = Matrix4(first, second, third, fourth);

  float third2[4] = {8, 7, 6, 5};
  float fourth2[4] = {4, 3, 2, 1};
  Matrix4 m2 = Matrix4(first, second, third2, fourth2);

  multiplyM4(m1, m2);

  EXPECT_TRUE(!equalM4(m1, m2));
}

TEST(Matrix4MultiplicationTest, MatrixTest) {
	float first1[4] = {1, 2, 3, 4};
  float second1[4] = {5, 6, 7, 8};
  float third1[4] = {9, 8, 7, 6};
  float fourth1[4] = {5, 4, 3, 2};

  Matrix4 m1 = Matrix4(first1, second1, third1, fourth1);

  float first2[4] = {-2, 1, 2, 3};
  float second2[4] = {3, 2, 1, -1};
  float third2[4] = {4, 3, 6, 5};
  float fourth2[4] = {1, 2, 7, 8};
  Matrix4 m2 = Matrix4(first2, second2, third2, fourth2);

  float first3[4] = {20, 22, 50, 48};
  float second3[4] = {44, 54, 114, 108};
  float third3[4] = {40, 58, 110, 102};
  float fourth3[4] = {16, 26, 46, 42};
  Matrix4 expected = Matrix4(first3, second3, third3, fourth3);

  Matrix4 result = multiplyM4(m1, m2);

  EXPECT_TRUE(equalM4(result, expected));
}