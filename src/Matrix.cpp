#include "Matrix.h"

void Matrix4::print() {
	std::cout << "Printing: " << std::endl;
	int dim = 4;
	for (int i = 0; i < dim; i++) {
		for (int j = 0; j < dim; j++) {
			std::cout << mat[i][j] << "  ";
		}
		std::cout << std::endl;
	}
}

float Matrix4::get(int row, int col) {
	return mat[row][col];
}

void Matrix4::set(int row, int col, float val) {
	mat[row][col] = val;
}

// -------------------------

void Matrix3::print() {
	std::cout << "Printing: " << std::endl;
	int dim = 3;
	for (int i = 0; i < dim; i++) {
		for (int j = 0; j < dim; j++) {
			std::cout << mat[i][j] << "  ";
		}
		std::cout << std::endl;
	}
}

float Matrix3::get(int row, int col) {
	return mat[row][col];
}

void Matrix3::set(int row, int col, float val) {
	mat[row][col] = val;
}

// -------------------------

void Matrix2::print() {
	std::cout << "Printing: " << std::endl;
	int dim = 2;
	for (int i = 0; i < dim; i++) {
		for (int j = 0; j < dim; j++) {
			std::cout << mat[i][j] << "  ";
		}
		std::cout << std::endl;
	}
}

float Matrix2::get(int row, int col) {
	return mat[row][col];
}

void Matrix2::set(int row, int col, float val) {
	mat[row][col] = val;
}