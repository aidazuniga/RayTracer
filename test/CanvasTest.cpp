#include <gtest/gtest.h>
#include <gmock/gmock.h>

#include "../src/Canvas.h"
#include "../src/Utils.h"
#include "../src/Color.h"

/*
Scenario: Creating a canvas 
	Given c ← canvas(10, 20) 
	Then c.width = 10
		And c.height = 20
		And every pixel of c is color(0, 0, 0)
*/
TEST(CreateCanvas, CanvasTest) {
  Canvas c(10, 20);
  EXPECT_TRUE(equal(c.getWidth(), 10));
  EXPECT_TRUE(equal(c.getHeight(), 20));

  for (int y=0; y<c.getHeight(); y++) {
		for (int x=0; x<c.getWidth(); x++) {
			Color resultPixelColor = c.readPixel(x, y);
			EXPECT_TRUE(equalColors(resultPixelColor, Color()));
		}
	}
}

/*
Scenario: Writing pixels to a canvas 
	Given c ← canvas(10, 20)
		And red ← color(1, 0, 0)
	When write_pixel(c, 2, 3, red) 
	Then pixel_at(c, 2, 3) = red
*/
TEST(WriteToCanvas, CanvasTest) {
  Canvas c(10, 20);
  Color red(1, 0, 0);
  c.writePixel(2, 3, red);

  EXPECT_TRUE(equalColors(c.readPixel(2, 3), red));
}

/*
Scenario: Constructing the PPM header 
	Given c ← canvas(5, 3)
	When ppm ← canvas_to_ppm(c)
	Then lines 1-3 of ppm are
		"""
		P3
		5 3
		255
		"""
Scenario: Constructing the PPM pixel data 
	Given c ← canvas(5, 3)
		And c1 ← color(1.5, 0, 0) And c2 ← color(0, 0.5, 0) 
		And c3 ← color(-0.5, 0, 1)
	When write_pixel(c, 0, 0, c1) 
		And write_pixel(c, 2, 1, c2) 
		And write_pixel(c, 4, 2, c3) 
		And ppm ← canvas_to_ppm(c)
	Then lines 4-6 of ppm are
		"""
    255 0 0 0 0 0 0 0 0 0 0 0 0 0 0
    0 0 0 0 0 0 0 128 0 0 0 0 0 0 0
    0 0 0 0 0 0 0 0 0 0 0 0 0 0 255
    """
*/
TEST(ConsructPPMHeader, CanvasTest) {
	Canvas c(5, 3);
  Color c1(1.5, 0, 0);
  Color c2(0, 0.5, 0);
  Color c3(-0.5, 0, 1);
  c.writePixel(0, 0, c1);
  c.writePixel(2, 1, c2);
  c.writePixel(4, 2, c3);
  c.toPPM();
}

/*
Scenario: Splitting long lines in PPM files
  Given c ← canvas(10, 2)
  When every pixel of c is set to color(1, 0.8, 0.6)
    And ppm ← canvas_to_ppm(c)
  Then lines 4-7 of ppm are
    """
    255 204 153 255 204 153 255 204 153 255 204 153 255 204 153 255 204
    153 255 204 153 255 204 153 255 204 153 255 204 153
    255 204 153 255 204 153 255 204 153 255 204 153 255 204 153 255 204
    153 255 204 153 255 204 153 255 204 153 255 204 153
    """
Scenario: PPM files are terminated by a newline character
  Given c ← canvas(5, 3)
  When ppm ← canvas_to_ppm(c)
  Then ppm ends with a newline character
*/
TEST(PPMLongLines, CanvasTest) {
	Canvas c(10, 2);
  c.colorEveryPixel(Color(1, 0.8, 0.6));
  c.toPPM();
}
