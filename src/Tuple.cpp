#include "Tuple.h"

#include <iostream>

void Tuple::print() {
  std::cout << "TUPLE  x: " << x;
  std::cout << ", y: " << y;
  std::cout << ", z: " << z;
  std::cout << ", w: " << w << std::endl;
}

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

float Tuple::getMagnitude() {
  // pythagoream theorem
  float magnitude;
  magnitude = x*x + y*y + z*z + w*w;
  magnitude = sqrt(magnitude);

  return magnitude;
}

float Tuple::getX() {
  return x;
}

float Tuple::getY() {
  return y;
}

float Tuple::getZ() {
  return z;
}

float Tuple::getW() {
  return w;
}

// -------------------------

bool equalTuples(Tuple a, Tuple b) {
  if (equal(a.getX(), b.getX()) && 
    equal(a.getY(), b.getY()) &&
    equal(a.getZ(), b.getZ()) &&
    equal(a.getW(), b.getW())) {
    return true;
  }
  return false;
}

Tuple createPoint(float x, float y, float z) {
  return Tuple(x, y, z, 1.0);
}

Tuple createVector(float x, float y, float z) {
  return Tuple(x, y, z, 0.0);
}

Tuple addTuples(Tuple a, Tuple b){
  float newX = a.getX() + b.getX();
  float newY = a.getY() + b.getY();
  float newZ = a.getZ() + b.getZ();
  float newW = a.getW() + b.getW();

  return Tuple(newX, newY, newZ, newW);
}

Tuple subtractTuples(Tuple a, Tuple b){
  float newX = a.getX() - b.getX();
  float newY = a.getY() - b.getY();
  float newZ = a.getZ() - b.getZ();

  if(a.isAPoint() && b.isAVector()) {
    return createPoint(newX, newY, newZ);
  }
  else {
    return createVector(newX, newY, newZ);
  }
}

Tuple scalarMultiplyTuple(Tuple a, float s){
  float newX = a.getX() * s;
  float newY = a.getY() * s;
  float newZ = a.getZ() * s;
  float newW = a.getW() * s;

  return Tuple(newX, newY, newZ, newW);
}

Tuple scalarDivideTuple(Tuple a, float s){
  float newX = a.getX() / s;
  float newY = a.getY() / s;
  float newZ = a.getZ() / s;
  float newW = a.getW() / s;

  return Tuple(newX, newY, newZ, newW);
}

Tuple negateTuple(Tuple a){
  Tuple zeroTuple(0, 0, 0, 0);
  Tuple result = subtractTuples(zeroTuple, a);
  return Tuple(result.getX(), 
    result.getY(), 
    result.getZ(), 
    0 - a.getW());
}

Tuple normalizeTuple(Tuple a){
  float magnitude = a.getMagnitude();

  float newX = a.getX() / magnitude;
  float newY = a.getY() / magnitude;
  float newZ = a.getZ() / magnitude;
  float newW = a.getW() / magnitude;

  return Tuple(newX, newY, newZ, newW);
}

float dotProduct(Tuple a, Tuple b){
  float newX = a.getX() * b.getX();
  float newY = a.getY() * b.getY();
  float newZ = a.getZ() * b.getZ();
  float newW = a.getW() * b.getW();

  return newX + newY + newZ + newW;
}

Tuple crossProduct(Tuple a, Tuple b){
  float newX = a.getY()*b.getZ() - a.getZ()*b.getY();
  float newY = a.getZ()*b.getX() - a.getX() * b.getZ();
  float newZ = a.getX()*b.getY() - a.getY() * b.getX();
  
  return createVector(newX, newY, newZ);
}