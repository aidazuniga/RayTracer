#include "src/Tuple.h"

#include <iostream>

int main() {
  auto pointA = Tuple(5.0, 2.0, 3.0, 1.0);
  std::cout << "Is pointA a point? " << pointA.isAPoint() << std::endl;

  auto pointB = createVector(3.0, 4.0, 5.0);
  std::cout << "Is pointB a point? " << pointB.isAPoint() << std::endl;
}
