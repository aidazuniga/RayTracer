#pragma once

#include "Car.h"

#include <memory>

class Driver {
public:
  Driver(std::unique_ptr<Car> car) : car_(std::move(car)) {}

  void pressDown();
private:
  std::unique_ptr<Car> car_;
};