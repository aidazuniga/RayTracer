#pragma once

#include "Color.h"
#include <vector>

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

	Color readPixel(int y, int x);
	void writePixel(int y, int x, Color c);

	virtual ~Canvas() = default;

private:
	float width;
	float height;
	std::vector<std::vector<Color>> pixels;
};

// -------------------------