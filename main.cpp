#include "src/Utils.h"
#include "src/Tuple.h"
#include "src/Color.h"
#include "src/Canvas.h"

#include <iostream>
#include <vector>

// -------------------------

int main() {
  std::cout << "Hello Ray Tracing World" << std::endl;

  Canvas c(5, 3);

  Color c1(1.5, 0, 0);
  Color c2(0, 0.5, 0);
  Color c3(-0.5, 0, 1);

  c.writePixel(0, 0, c1);
  c.writePixel(2, 1, c2);
  c.writePixel(4, 2, c3);

  c.toPPM();
}

// -------------------------
