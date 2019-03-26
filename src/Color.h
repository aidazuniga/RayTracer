#pragma once

#include <cstdlib>
#include <cmath>

#include "Tuple.h"

class Color {
public:
	Color(float r, float g, float b) : red(r), green(g), blue(b) {}

	float getRed();
	float getGreen();
	float getBlue();

	virtual ~Color() = default;

private:
	float red;
	float green;
	float blue;
};

// -------------------------

bool equalColors(Color a, Color b);

Color addColors(Color a, Color b);
Color subtractColors(Color a, Color b);
Color scalarMultiplyColor(Color a, float s);
Color multiplyColors(Color a, Color b);