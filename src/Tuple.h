#pragma once

#include <cstdlib>
#include <cmath>

class Tuple {
public:
	Tuple(float x, float y, float z, float w) : x(x), y(y), z(z), w(w) {}

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

void printTuple(Tuple a);

bool equal(float a, float b);
bool equalTuples(Tuple a, Tuple b);

Tuple createPoint(float x, float y, float z);
Tuple createVector(float x, float y, float z);

Tuple addTuples(Tuple a, Tuple b);
Tuple subtractTuples(Tuple a, Tuple b);

Tuple scalarMultiply(Tuple a, float s);
Tuple scalarDivide(Tuple a, float s);

Tuple negateTuple(Tuple a);
Tuple normalizeTuple(Tuple a);

float dotProduct(Tuple a, Tuple b);
Tuple crossProduct(Tuple a, Tuple b);
