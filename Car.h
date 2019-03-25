#pragma once

class Car {
public:
  virtual void move() = 0;
  
  virtual ~Car() = default;
};