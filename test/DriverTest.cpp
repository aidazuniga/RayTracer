#include <gtest/gtest.h>
#include <gmock/gmock.h>

#include "../Car.h"
#include "../Driver.h"

class MockCar : public Car {
public:
  MOCK_METHOD0(move, void());
};

TEST(DriverTest, MovesCar) {
  auto car = std::make_unique<MockCar>();
  EXPECT_CALL(*car, move()).Times(1);

  Driver person(std::move(car));
  person.pressDown();
}