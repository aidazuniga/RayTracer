#pragma once

#include "Color.h"
#include "Utils.h"

#include <math.h>
#include <vector>
#include <fstream>
#include <iostream>

class Canvas {
public:
	Canvas(int w, int h) : width(w), height(h) {

		pixels.resize(h);
		for (int i = 0; i < h; ++i) {
		  pixels[i].resize(w);
		}
	}

	float getWidth();
	float getHeight();

	Color readPixel(int x, int y);
	void writePixel(int x, int y, Color c);

	void toPPM();

	virtual ~Canvas() = default;

private:
	float width;
	float height;
	std::vector<std::vector<Color>> pixels;
};

// -------------------------