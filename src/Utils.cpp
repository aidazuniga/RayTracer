#include "Utils.h"

bool equal(float a, float b) {
  float epsilon = 0.00001;
  if (std::abs(a - b) < epsilon) {
    return true;
  }
  return false;
}

float clamp(float f, float lower, float upper) {
  if (f > upper) {
    return upper;
  }
  else if (f < lower) {
  	return lower;
  }
  return f;
}

int getNumLen(int n) {
  if (n > 99) {
    return 3;
  }
  else if (n > 9) {
    return 2;
  }
  return 1;
}