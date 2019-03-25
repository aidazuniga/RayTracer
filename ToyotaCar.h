#pragma once

#include "Car.h"

#include <string>

class ToyotaCar : public Car {
public:
  ToyotaCar(const std::string& name) : name_(name) {}
  void move() override;

private:
  std::string name_;
};