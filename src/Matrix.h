#pragma once

#include <vector>
#include <iostream>

class Matrix4 {
public:
	Matrix4(float first[4],
					float second[4],
					float third[4],
					float fourth[4]){

		mat[0][0] = first[0];
		mat[0][1] = first[1];
		mat[0][2] = first[2];
		mat[0][3] = first[3];

	  mat[1][0] = second[0];
		mat[1][1] = second[1];
		mat[1][2] = second[2];
		mat[1][3] = second[3];

		mat[2][0] = third[0];
		mat[2][1] = third[1];
		mat[2][2] = third[2];
		mat[2][3] = third[3];

		mat[3][0] = fourth[0];
		mat[3][1] = fourth[1];
		mat[3][2] = fourth[2];
		mat[3][3] = fourth[3];
	}

	virtual ~Matrix4() = default;
	void print();
	float get(int row, int col);

private:
	float mat[4][4];
};

// -------------------------

class Matrix3 {
public:
	Matrix3(float first[3],
					float second[3],
					float third[3]){

		mat[0][0] = first[0];
		mat[0][1] = first[1];
		mat[0][2] = first[2];

	  mat[1][0] = second[0];
		mat[1][1] = second[1];
		mat[1][2] = second[2];

		mat[2][0] = third[0];
		mat[2][1] = third[1];
		mat[2][2] = third[2];
	}

	virtual ~Matrix3() = default;
	void print();
	float get(int row, int col);

private:
	float mat[3][3];
};

// -------------------------

class Matrix2 {
public:
	Matrix2(float first[2],
					float second[2]) {

		mat[0][0] = first[0];
		mat[0][1] = first[1];

	  mat[1][0] = second[0];
		mat[1][1] = second[1];
	}

	virtual ~Matrix2() = default;
	void print();
	float get(int row, int col);

private:
	float mat[2][2];
};
