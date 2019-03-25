#include "Tuple.h"

bool Tuple::isAPoint() {
  if (w == 1.0) {
    return true;
  }
  return false;
}

bool Tuple::isAVector() {
  if (w == 0.0) {
    return true;
  }
  return false;
}

// -------------------------

Tuple createPoint(float x, float y, float z) {
  return Tuple(x, y, z, 1.0);
}

Tuple createVector(float x, float y, float z) {
  return Tuple(x, y, z, 0.0);
}