#include "Canvas.h"

float Canvas::getWidth() {
	return width;
}

float Canvas::getHeight() {
	return height;
}

Color Canvas::readPixel(int y, int x) {
	return pixels[y][x];
}

void Canvas::writePixel(int y, int x, Color c) {
	pixels[y][x] = c;
}