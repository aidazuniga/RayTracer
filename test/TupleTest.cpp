#include <gtest/gtest.h>
#include <gmock/gmock.h>

#include "../src/Tuple.h"

class MockTuple : public Tuple {
public:
	MockTuple(float x, float y, float z, float w) : Tuple(x, y, x, w) {}
  MOCK_METHOD0(isAPoint, bool());
};

// Sample mock test
// TEST(SomeTest, DoesThis) { ... }
TEST(PointTest, MockTest) {
  MockTuple testPoint(2.0, 2.0, 3.0, 1.0);

  using ::testing::Return;
  
  EXPECT_CALL(testPoint, isAPoint())
  	.Times(1)
  	.WillOnce(Return(true));

  testPoint.isAPoint();
}

/*
Scenario: A tuple with w=1.0 is a point
  Given a ← tuple(4.3, -4.2, 3.1, 1.0)
  Then a.x = 4.3
    And a.y = -4.2
    And a.z = 3.1
    And a.w = 1.0
    And a is a point
    And a is not a vector

Scenario: point() creates tuples with w=1
  Given p ← point(4, -4, 3)
  Then p = tuple(4, -4, 3, 1)
*/
TEST(IsAPoint, TupleTest) {
  Tuple a(4.3, -4.2, 3.1, 1.0);
  Tuple p = createPoint(4, -4, 3);
  
  EXPECT_TRUE(a.isAPoint());
  EXPECT_TRUE(p.isAPoint());
  EXPECT_TRUE(equal(p.getW(), 1));
}

/*
Scenario: A tuple with w=0 is a vector
  Given a ← tuple(4.3, -4.2, 3.1, 0.0)
  Then a.x = 4.3
    And a.y = -4.2
    And a.z = 3.1
    And a.w = 0.0
    And a is not a point
    And a is a vector

Scenario: vector() creates tuples with w=0
  Given v ← vector(4, -4, 3)
  Then v = tuple(4, -4, 3, 0)
*/
TEST(IsAVector, TupleTest) {
	Tuple a(4.3, -4.2, 3.1, 0.0);
  Tuple v = createVector(4, -4, 3);
  
  EXPECT_TRUE(a.isAVector());
  EXPECT_TRUE(v.isAVector());
  EXPECT_EQ(v.getW(), 0);
}

/*
	Scenario: Adding two tuples 
	Given a1 ← tuple(3, -2, 5, 1) 
	And a2 ← tuple(-2, 3, 1, 0)
	Then a1 + a2 = tuple(1, 1, 6, 1)
*/
TEST(AddingTuples, TupleTest) {
	Tuple a1 = createPoint(3, -2, 5);
	Tuple a2 = createVector(-2, 3, 1);

	Tuple result = addTuples(a1, a2);
	EXPECT_TRUE(equalTuples(result, result));
	Tuple expected = Tuple(1, 1, 6, 1);
	EXPECT_TRUE(equalTuples(result, expected));
}

/*
Scenario: Subtracting two points
  Given p1 ← point(3, 2, 1)
    And p2 ← point(5, 6, 7)
  Then p1 - p2 = vector(-2, -4, -6)

Scenario: Subtracting a vector from a point
  Given p ← point(3, 2, 1)
    And v ← vector(5, 6, 7)
  Then p - v = point(-2, -4, -6)

Scenario: Subtracting two vectors
  Given v1 ← vector(3, 2, 1)
    And v2 ← vector(5, 6, 7)
  Then v1 - v2 = vector(-2, -4, -6)
*/
TEST(SubtractingTuples, TupleTest) {
	Tuple p1 = createPoint(3, 2, 1);
	Tuple p2 = createPoint(5, 6, 7);

	Tuple result = subtractTuples(p1, p2);
	EXPECT_TRUE(equalTuples(result, result));
	Tuple expected = createVector(-2, -4, -6);
	EXPECT_TRUE(equalTuples(result, expected));


	Tuple p = createPoint(3, 2, 1);
	Tuple v = createVector(5, 6, 7);

	result = subtractTuples(p, v);
	expected = createPoint(-2, -4, -6);
	EXPECT_TRUE(equalTuples(result, expected));


	Tuple v1 = createVector(3, 2, 1);
	Tuple v2 = createVector(5, 6, 7);

	result = subtractTuples(v1, v2);
	expected = createVector(-2, -4, -6);
	EXPECT_TRUE(equalTuples(result, expected));
}

/*
Scenario: Subtracting a vector from the zero vector
  Given zero ← vector(0, 0, 0)
    And v ← vector(1, -2, 3)
  Then zero - v = vector(-1, 2, -3)

Scenario: Negating a tuple
  Given a ← tuple(1, -2, 3, -4)
  Then -a = tuple(-1, 2, -3, 4)
*/
TEST(NegatingTuples, TupleTest) {
	Tuple v = createVector(1, -2, 3);
	Tuple result = negateTuple(v);
	Tuple expected = createVector(-1, 2, -3);
	EXPECT_TRUE(equalTuples(result, expected));


	Tuple a = Tuple(1, -2, 3, -4);
	result = negateTuple(a);
	expected = Tuple(-1, 2, -3, 4);
	EXPECT_TRUE(equalTuples(result, expected));
}

/*
Scenario: Multiplying a tuple by a scalar
  Given a ← tuple(1, -2, 3, -4)
  Then a * 3.5 = tuple(3.5, -7, 10.5, -14)

Scenario: Multiplying a tuple by a fraction
  Given a ← tuple(1, -2, 3, -4)
  Then a * 0.5 = tuple(0.5, -1, 1.5, -2)
*/
TEST(MultiplyingTuples, TupleTest) {
	Tuple a = Tuple(1, -2, 3, -4);
	Tuple result = scalarMultiply(a, 3.5);
	Tuple expected = Tuple(3.5, -7, 10.5, -14);
	EXPECT_TRUE(equalTuples(result, expected));

	a = Tuple(1, -2, 3, -4);
	result = scalarMultiply(a, 0.5);
	expected = Tuple(0.5, -1, 1.5, -2);
	EXPECT_TRUE(equalTuples(result, expected));
}

/*
Scenario: Dividing a tuple by a scalar
  Given a ← tuple(1, -2, 3, -4)
  Then a / 2 = tuple(0.5, -1, 1.5, -2)
*/
TEST(DividingTuple, TupleTest) {
	Tuple a = Tuple(1, -2, 3, -4);
	Tuple result = scalarDivide(a, 2);
	Tuple expected = Tuple(0.5, -1, 1.5, -2);
	EXPECT_TRUE(equalTuples(result, expected));
}

/*
Scenario: Computing the magnitude of vector(1, 0, 0)
  Given v ← vector(1, 0, 0)
  Then magnitude(v) = 1

Scenario: Computing the magnitude of vector(0, 1, 0)
  Given v ← vector(0, 1, 0)
  Then magnitude(v) = 1

Scenario: Computing the magnitude of vector(0, 0, 1)
  Given v ← vector(0, 0, 1)
  Then magnitude(v) = 1

Scenario: Computing the magnitude of vector(1, 2, 3)
  Given v ← vector(1, 2, 3)
  Then magnitude(v) = √14

Scenario: Computing the magnitude of vector(-1, -2, -3)
  Given v ← vector(-1, -2, -3)
  Then magnitude(v) = √14
*/
TEST(TupleMagnitude, TupleTest) {
	Tuple v = createVector(1, 0, 0);
	float result = v.getMagnitude();
	float expected = 1;
	EXPECT_TRUE(equal(result, expected));

	v = createVector(0, 1, 0);
	result = v.getMagnitude();
	expected = 1;
	EXPECT_TRUE(equal(result, expected));

	v = createVector(0, 0, 1);
	result = v.getMagnitude();
	expected = 1;
	EXPECT_TRUE(equal(result, expected));

	v = createVector(1, 2, 3);
	result = v.getMagnitude();
	expected = sqrt(14);
	EXPECT_TRUE(equal(result, expected));

	v = createVector(-1, -2, -3);
	result = v.getMagnitude();
	expected = sqrt(14);
	EXPECT_TRUE(equal(result, expected));
}

/*
Scenario: Normalizing vector(4, 0, 0) gives (1, 0, 0)
  Given v ← vector(4, 0, 0)
  Then normalize(v) = vector(1, 0, 0)

Scenario: Normalizing vector(1, 2, 3)
  Given v ← vector(1, 2, 3)  # vector(1/√14,   2/√14,   3/√14)
  Then normalize(v) = approximately vector(0.26726, 0.53452, 0.80178)

Scenario: The magnitude of a normalized vector
  Given v ← vector(1, 2, 3)
  When norm ← normalize(v)
  Then magnitude(norm) = 1
*/
TEST(NormalizingTuple, TupleTest) {
	Tuple v = createVector(4, 0, 0);
	Tuple result = normalizeTuple(v);
	Tuple expected = createVector(1, 0, 0);
	EXPECT_TRUE(equalTuples(result, expected));

	v = createVector(1, 2, 3);
	result = normalizeTuple(v);
	expected = createVector(0.26726, 0.53452, 0.80178);
	EXPECT_TRUE(equalTuples(result, expected));

	v = createVector(1, 2, 3);
	result = normalizeTuple(v);
	float resultM = result.getMagnitude();
	float expectedM = 1.0;
	EXPECT_TRUE(equal(resultM, expectedM));
}

/*
Scenario: The dot product of two tuples
  Given a ← vector(1, 2, 3)
    And b ← vector(2, 3, 4)
  Then dot(a, b) = 20
*/
TEST(TupleDotProduct, TupleTest) {
	Tuple a = createVector(1, 2, 3);
	Tuple b = createVector(2, 3, 4);

	float result = dotProduct(a, b);
	float expected = 20;
	EXPECT_TRUE(equal(result, expected));
}

/*
Scenario: The cross product of two vectors
  Given a ← vector(1, 2, 3)
    And b ← vector(2, 3, 4)
  Then cross(a, b) = vector(-1, 2, -1)
    And cross(b, a) = vector(1, -2, 1)
*/
TEST(TupleCrossProduct, TupleTest) {
	Tuple a = createVector(1, 2, 3);
	Tuple b = createVector(2, 3, 4);

	Tuple resultA = crossProduct(a, b);
	Tuple expectedA = createVector(-1, 2, -1);
	EXPECT_TRUE(equalTuples(resultA, expectedA));

	Tuple resultB = crossProduct(b, a);
	Tuple expectedB = createVector(1, -2, 1);
	EXPECT_TRUE(equalTuples(resultB, expectedB));
}