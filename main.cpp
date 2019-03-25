#include "src/Tuple.h"

#include <iostream>

int main() {
  auto pointA = Tuple(5.0, 2.0, 3.0, 1.0);
  std::cout << "pointA x: " << pointA.x << std::endl;
  pointA.isAPoint();
  std::cout << "Is pointA a point? " << pointA.isAPoint() << std::endl;
}
