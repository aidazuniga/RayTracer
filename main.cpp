#include "Driver.h"
#include "ToyotaCar.h"
#include "src/Tuple.h"

#include <iostream>

int main() {
  auto car = std::make_unique<ToyotaCar>("Aida");
  Driver person(std::move(car));
  person.pressDown();

  auto pointA = Tuple(5.0, 2.0, 3.0, 1.0);
  std::cout << "pointA x: " << pointA.x << std::endl;
  pointA.isAPoint();
  std::cout << "Is pointA a point? " << pointA.isAPoint() << std::endl;
}
