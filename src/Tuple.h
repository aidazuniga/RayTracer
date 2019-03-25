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
	
private:
	float w;
};
