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

  for (int i=0; i<c.getHeight(); i++) {
		for (int j=0; j<c.getWidth(); j++) {
			Color resultPixelColor = c.readPixel(i, j);
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