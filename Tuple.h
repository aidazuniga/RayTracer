#pragma once

class Tuple {
public:
	Tuple(float x, float y, float z, float w) : x(x), y(y), z(z), w(w) {}

	bool isAPoint();
	bool isAVector();

  ~Tuple() = default;

	float x;
	float y;
	float z;
	
private:
	float w;
};
