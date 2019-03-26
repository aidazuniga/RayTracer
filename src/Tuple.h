#pragma once

#include <cmath>
#include "Utils.h"

class Tuple {
public:
	Tuple(float x, float y, float z, float w) : x(x), y(y), z(z), w(w) {}

	virtual void print();

	virtual bool isAPoint();
	virtual bool isAVector();

	virtual float getMagnitude();

	virtual float getX();
	virtual float getY();
	virtual float getZ();
	virtual float getW();

  virtual ~Tuple() = default;
	
private:

	float x;
	float y;
	float z;
	float w;
};

// -------------------------

bool equalTuples(Tuple a, Tuple b);

Tuple createPoint(float x, float y, float z);
Tuple createVector(float x, float y, float z);

Tuple addTuples(Tuple a, Tuple b);
Tuple subtractTuples(Tuple a, Tuple b);

Tuple scalarMultiplyTuple(Tuple a, float s);
Tuple scalarDivideTuple(Tuple a, float s);

Tuple negateTuple(Tuple a);

// Take vector and convert it to a unit vector
Tuple normalizeTuple(Tuple a);

// The smaller the dotProduct, the larger the angle between vectors
	// dotProduct = 1 -> vectors are identical
	// docProdict = -1 -> vectprs point in opposite direction
// if two vectors are unit vectors, the dotProduct is 
	// the cosine angle between them
float dotProduct(Tuple a, Tuple b);

// The result of the crossProduct is the vector that is
	// perpendicular to both inputs 
	// (ex for X x Y = Z but Y x X = -Z)
Tuple crossProduct(Tuple a, Tuple b);
