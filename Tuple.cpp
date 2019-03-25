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
