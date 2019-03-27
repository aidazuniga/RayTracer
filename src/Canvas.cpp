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

void Canvas::colorEveryPixel(Color c) {
	for (int y = 0; y < height; y++) {
  	for (int x = 0; x < width; x++) {
  		writePixel(x, y, c);
  	}
  }
}

void Canvas::toPPM() {
	std::ofstream ppmFile;
  ppmFile.open ("raytracer.ppm");
  
  ppmFile << "P3\n";
  ppmFile << width << " " << height << "\n";
  ppmFile << "255\n";

  int lineLen;
  int numLen;

  for (int y = 0; y < height; y++) {
  	lineLen = 0;
  	for (int x = 0; x < width; x++) {
	  	Color c = readPixel(x, y);
	  	float r = clamp(c.getRed() * 255, 0, 255);
	  	float g = clamp(c.getGreen() * 255, 0, 255);
	  	float b = clamp(c.getBlue() * 255, 0, 255);

	  	// red
	  	numLen = getNumLen(round(r));
	  	if ((lineLen + numLen) > 70 ) {
	  		ppmFile << "\n" << round(r) << " ";
	  		lineLen = numLen + 1;
	  	}
	  	else {
	  		ppmFile << round(r) << " ";
	  		lineLen += numLen + 1;
	  	}

	  	// green
	  	numLen = getNumLen(round(g));
	  	if ((lineLen + numLen) > 70 ) {
	  		ppmFile << "\n" << round(g) << " ";
	  		lineLen = numLen + 1;
	  	}
	  	else {
	  		ppmFile << round(g) << " ";
	  		lineLen += numLen + 1;
	  	}
	  	
	  	// blue
	  	numLen = getNumLen(round(b));
	  	if ((lineLen + numLen) > 70 ) {
	  		ppmFile << "\n" << round(b) << " ";
	  		lineLen = numLen + 1;
	  	}
	  	else {
	  		ppmFile << round(b) << " ";
	  		lineLen += numLen + 1;
	  	}
	  }
	  ppmFile << "\n";
  }
  
  ppmFile.close();
}