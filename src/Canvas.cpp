#include "Canvas.h"

float Canvas::getWidth() {
	return width;
}

float Canvas::getHeight() {
	return height;
}

Color Canvas::readPixel(int x, int y) {
	return pixels[y][x];
}

void Canvas::writePixel(int x, int y, Color c) {
	pixels[y][x] = c;
}

void Canvas::toPPM() {
	std::ofstream ppmFile;
  ppmFile.open ("raytracer.ppm");
  
  ppmFile << "P3\n";
  ppmFile << width << " " << height << "\n";
  ppmFile << "255\n";

  for (int y = 0; y < height; y++) {
  	for (int x = 0; x < width; x++) {
	  	Color c = readPixel(x, y);
	  	float r = clamp(c.getRed() * 255, 0, 255);
	  	float g = clamp(c.getGreen() * 255, 0, 255);
	  	float b = clamp(c.getBlue() * 255, 0, 255);
	  	ppmFile << round(r) << " " << round(g) << " " << round(b) << " ";
	  }
	  ppmFile << "\n";
  }
  
  ppmFile.close();
}