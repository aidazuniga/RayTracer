#include <gtest/gtest.h>
#include <gmock/gmock.h>

#include "../src/Tuple.h"

class MockTuple : public Tuple {
public:
	MockTuple(float x, float y, float z, float w) : Tuple(x, y, x, w) {}
  MOCK_METHOD0(isAPoint, bool());
};

// Sample mock test
TEST(PointTest, MockTest) {
  MockTuple testPoint(2.0, 2.0, 3.0, 1.0);

  using ::testing::Return;
  
  EXPECT_CALL(testPoint, isAPoint())
  	.Times(1)
  	.WillOnce(Return(true));

  testPoint.isAPoint();
}

// A tuple with w=1.0 is a point
TEST(IsAPoint, Tuple) {
  Tuple testPointA(4.3, -4.2, 3.1, 1.0);
  Tuple testPointB = createPoint(4, -4, 3);
  
  EXPECT_TRUE(testPointA.isAPoint());
  EXPECT_TRUE(testPointB.isAPoint());
  EXPECT_EQ(testPointB.w, 1);
}

// A tuple with w=0.0 is a vector
TEST(IsAVector, Tuple) {
Tuple testVectorA(4.3, -4.2, 3.1, 0.0);
  Tuple testVectorB = createVector(4, -4, 3);
  
  EXPECT_TRUE(testVectorA.isAVector());
  EXPECT_TRUE(testVectorB.isAVector());
  EXPECT_EQ(testVectorB.w, 0);
}