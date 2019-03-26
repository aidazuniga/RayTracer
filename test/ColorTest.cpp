#include <gtest/gtest.h>
#include <gmock/gmock.h>

#include "../src/Color.h"
#include "../src/Tuple.h"

/*
Scenario: Colors are (red, green, blue) tuples 
	Given c ← color(-0.5, 0.4, 1.7)
	Then c.red = -0.5
		And c.green = 0.4
		And c.blue = 1.7
*/
TEST(CorrectColors, ColorTest) {
  Color c(-0.5, 0.4, 1.7);
  EXPECT_TRUE(equal(c.getRed(), -0.5));
  EXPECT_TRUE(equal(c.getGreen(), 0.4));
  EXPECT_TRUE(equal(c.getBlue(), 1.7));
}

/*
Scenario: Adding colors
	Given c1 ← color(0.9, 0.6, 0.75)
		And c2 ← color(0.7, 0.1, 0.25)
	Then c1 + c2 = color(1.6, 0.7, 1.0)
*/
TEST(AddingColors, ColorTest) {
  Color c1(0.9, 0.6, 0.75);
  Color c2(0.7, 0.1, 0.25);

  Color result = addColors(c1, c2);
  EXPECT_TRUE(equal(result.getRed(), 1.6));
  EXPECT_TRUE(equal(result.getGreen(), 0.7));
  EXPECT_TRUE(equal(result.getBlue(), 1.0));
}

/*
Scenario: Subtracting colors
	Given c1 ← color(0.9, 0.6, 0.75)
		And c2 ← color(0.7, 0.1, 0.25)
	Then c1 - c2 = color(0.2, 0.5, 0.5)
*/
TEST(SubtractingColors, ColorTest) {
  Color c1(0.9, 0.6, 0.75);
  Color c2(0.7, 0.1, 0.25);

  Color result = subtractColors(c1, c2);
  EXPECT_TRUE(equal(result.getRed(), 0.2));
  EXPECT_TRUE(equal(result.getGreen(), 0.5));
  EXPECT_TRUE(equal(result.getBlue(), 0.5));
}

/*
Scenario: Multiplying a color by a scalar
	Given c ← color(0.2, 0.3, 0.4)
	Then c * 2 = color(0.4, 0.6, 0.8)
*/
TEST(ScalarMultiplyingColors, ColorTest) {
  Color c(0.2, 0.3, 0.4);

  Color result = scalarMultiplyColor(c, 2);
  EXPECT_TRUE(equal(result.getRed(), 0.4));
  EXPECT_TRUE(equal(result.getGreen(), 0.6));
  EXPECT_TRUE(equal(result.getBlue(), 0.8));
}

/*
Scenario: Multiplying colors 
	Given c1 ← color(1, 0.2, 0.4) 
		And c2 ← color(0.9, 1, 0.1)
	Then c1 * c2 = color(0.9, 0.2, 0.04)
*/
TEST(MultiplyingColors, ColorTest) {
  Color c1(1, 0.2, 0.4);
  Color c2(0.9, 1, 0.1);

  Color result = multiplyColors(c1, c2);
  EXPECT_TRUE(equal(result.getRed(), 0.9));
  EXPECT_TRUE(equal(result.getGreen(), 0.2));
  EXPECT_TRUE(equal(result.getBlue(), 0.04));
}
