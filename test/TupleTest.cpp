#include <gtest/gtest.h>
#include <gmock/gmock.h>

#include "../src/Tuple.h"

class MockTuple : public Tuple {
public:
	MockTuple() : Tuple(2.0, 2.0, 2.0, 2.0) {}
  MOCK_METHOD0(isAPoint, bool());
};

TEST(PointTest, ChecksPoint) {
  MockTuple testPoint;
  EXPECT_CALL(testPoint, isAPoint()).Times(1);

  testPoint.isAPoint();
}