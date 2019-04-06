#include "Tuple.h"
#include "Matrix.h"

#include <cstdlib>
#include <cmath>

bool equal(float a, float b);

bool equalTuples(Tuple a, Tuple b);

float clamp(float f, float upper, float lower);

int getNumLen(int n);

// Matrices

bool equalM4(Matrix4 a, Matrix4 b);
bool equalM3(Matrix3 a, Matrix3 b);
bool equalM2(Matrix2 a, Matrix2 b);

Matrix4 multiplyM4(Matrix4 a, Matrix4 b);