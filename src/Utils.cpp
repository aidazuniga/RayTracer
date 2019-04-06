#include "Utils.h"

bool equal(float a, float b) {
  float epsilon = 0.00001;
  if (std::abs(a - b) < epsilon) {
    return true;
  }
  return false;
}

bool equalTuples(Tuple a, Tuple b) {
  if (equal(a.getX(), b.getX()) && 
    equal(a.getY(), b.getY()) &&
    equal(a.getZ(), b.getZ()) &&
    equal(a.getW(), b.getW())) {
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

// Matrices

bool equalM4(Matrix4 a, Matrix4 b) {
  int dim = 4;
  for (int row = 0; row < dim; row++) {
    for (int col = 0; col < dim; col++) {
      if (a.get(row, col) != b.get(row, col)) {
        return false;
      }
    }
  }
  return true;
}

bool equalM3(Matrix3 a, Matrix3 b){
  int dim = 3;
  for (int row = 0; row < dim; row++) {
    for (int col = 0; col < dim; col++) {
      if (a.get(row, col) != b.get(row, col)) {
        return false;
      }
    }
  }
  return true;
}

bool equalM2(Matrix2 a, Matrix2 b) {
  int dim = 2;
  for (int row = 0; row < dim; row++) {
    for (int col = 0; col < dim; col++) {
      if (a.get(row, col) != b.get(row, col)) {
        return false;
      }
    }
  }
  return true;
}

Matrix4 multiplyM4(Matrix4 a, Matrix4 b) {
  int dim = 4;
  float tmp[4] = {0, 0, 0, 0};
  Matrix4 result = Matrix4(tmp, tmp, tmp, tmp);

  for (int row = 0; row < dim; row++) {
    for (int col = 0; col < dim; col++) {
      float product = 
          (a.get(row, 0) * b.get(0, col)) +
          (a.get(row, 1) * b.get(1, col)) +
          (a.get(row, 2) * b.get(2, col)) +
          (a.get(row, 3) * b.get(3, col));
      result.set(row, col, product);
    }
  }
  return result;
}