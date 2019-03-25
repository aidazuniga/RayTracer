#pragma once

class Tuple {
public:
	Tuple(float x, float y, float z, float w) : x(x), y(y), z(z), w(w) {}

	virtual bool isAPoint();
	virtual bool isAVector();

  	virtual ~Tuple() = default;

	float x;
	float y;
	float z;
	float w;
	
private:
};

// -------------------------

Tuple createPoint(float x, float y, float z);
Tuple createVector(float x, float y, float z);
