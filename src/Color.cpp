#include "Color.h"

float Color::getRed() {
	return red;
}

float Color::getGreen(){
	return green;
}

float Color::getBlue() {
	return blue;
}

// -------------------------

bool equalColors(Color a, Color b) {
  if (equal(a.getRed(), b.getRed()) && 
    equal(a.getGreen(), b.getGreen()) &&
    equal(a.getBlue(), b.getBlue())) {
    return true;
  }
  return false;
}

Color addColors(Color a, Color b){
  float newRed = a.getRed() + b.getRed();
  float newGreen = a.getGreen() + b.getGreen();
  float newBlue = a.getBlue() + b.getBlue();

  return Color(newRed, newGreen, newBlue);
}

Color subtractColors(Color a, Color b){
  float newRed = a.getRed() - b.getRed();
  float newGreen = a.getGreen() - b.getGreen();
  float newBlue = a.getBlue() - b.getBlue();

  return Color(newRed, newGreen, newBlue);
}

Color scalarMultiplyColor(Color a, float s){
  float newRed = a.getRed() * s;
  float newGreen = a.getGreen() * s;
  float newBlue = a.getBlue() * s;

  return Color(newRed, newGreen, newBlue);
}

Color multiplyColors(Color a, Color b) {
	float newRed = a.getRed() * b.getRed();
	float newGreen = a.getGreen() * b.getGreen();
	float newBlue = a.getBlue() * b.getBlue();

	return Color(newRed, newGreen, newBlue);
}

